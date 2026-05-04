#include "DialogueBridgeComponent.h"
#include "WebBrowser.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "Dom/JsonObject.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

bool UDialogueBridgeComponent::Init(UWebBrowser* InBrowser,
                                    const FString& HudHtmlRelPath,
                                    const FString& NodesCsvRelPath,
                                    const FString& ChoicesCsvRelPath,
                                    const FString& LocCsvRelPath,
                                    const FDialogueSaveData& InitialState)
{
    if (!InBrowser)
    {
        OnError.Broadcast(TEXT("DialogueBridge: Browser is null"));
        return false;
    }

    FString HudUrl;
    if (!BuildContentFileUrl(HudHtmlRelPath, HudUrl))
    {
        OnError.Broadcast(TEXT("DialogueBridge: failed to find HUD HTML under Content/"));
        return false;
    }

    if (!LoadContentCsv(NodesCsvRelPath,   NodesCsv)   ||
        !LoadContentCsv(ChoicesCsvRelPath, ChoicesCsv) ||
        !LoadContentCsv(LocCsvRelPath,     LocCsv))
    {
        OnError.Broadcast(TEXT("DialogueBridge: failed to load one or more CSV files under Content/"));
        return false;
    }

    Browser = InBrowser;
    PendingInitial = InitialState;
    bInjected = false;

    Browser->OnConsoleMessage.RemoveDynamic(this, &UDialogueBridgeComponent::HandleConsoleMessage);
    Browser->OnConsoleMessage.AddDynamic(this, &UDialogueBridgeComponent::HandleConsoleMessage);

    Browser->LoadURL(HudUrl);
    return true;
}

void UDialogueBridgeComponent::NotifyReady()
{
    if (!bInjected)
    {
        InjectInitialData();
        bInjected = true;
    }
    OnReady.Broadcast();
}

void UDialogueBridgeComponent::NotifySave(const FString& StateJson)
{
    FDialogueSaveData Data;
    if (!DeserializeSave(StateJson, Data))
    {
        OnError.Broadcast(TEXT("DialogueBridge: could not parse save JSON from engine"));
        return;
    }
    OnSaveReady.Broadcast(Data);
}

void UDialogueBridgeComponent::NotifyNodeChanged(const FString& NodeJson)
{
    FString NodeId;
    FString SpeakerKey;
    TSharedPtr<FJsonObject> Obj;
    const TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(NodeJson);
    if (FJsonSerializer::Deserialize(Reader, Obj) && Obj.IsValid())
    {
        Obj->TryGetStringField(TEXT("id"), NodeId);
        Obj->TryGetStringField(TEXT("speakerKey"), SpeakerKey);
    }
    OnNodeChanged.Broadcast(NodeId, SpeakerKey, NodeJson);
}

void UDialogueBridgeComponent::NotifyDialogueEvent(const FString& PayloadJson)
{
    TSharedPtr<FJsonObject> Obj;
    const TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(PayloadJson);
    if (!FJsonSerializer::Deserialize(Reader, Obj) || !Obj.IsValid())
    {
        OnError.Broadcast(TEXT("DialogueBridge: could not parse event JSON from engine"));
        return;
    }

    FString Name;
    Obj->TryGetStringField(TEXT("name"), Name);
    OnDialogueEvent.Broadcast(Name, PayloadJson);
}

void UDialogueBridgeComponent::HandleConsoleMessage(const FString& Message, const FString& Source, int32 Line)
{
    static const FString PageReady(TEXT("DIALOGUE_READY"));
    static const FString SavePrefix(TEXT("__DIALOGUE_SAVE__"));
    static const FString NodePrefix(TEXT("__DIALOGUE_NODE__"));
    static const FString EventPrefix(TEXT("__DIALOGUE_EVENT__"));

    if (Message == PageReady)
    {
        NotifyReady();
        return;
    }

    if (Message.StartsWith(SavePrefix))
    {
        NotifySave(Message.Mid(SavePrefix.Len()));
        return;
    }

    if (Message.StartsWith(NodePrefix))
    {
        NotifyNodeChanged(Message.Mid(NodePrefix.Len()));
        return;
    }

    if (Message.StartsWith(EventPrefix))
    {
        NotifyDialogueEvent(Message.Mid(EventPrefix.Len()));
    }
}

void UDialogueBridgeComponent::JumpToNode(const FString& NodeId)
{
    if (!Browser) return;
    Browser->ExecuteJavascript(FString::Printf(
        TEXT("DialogueEngine.jumpToNode(\"%s\")"), *EscapeJsString(NodeId)));
}

void UDialogueBridgeComponent::SetLanguage(const FString& Lang)
{
    if (!Browser) return;
    Browser->ExecuteJavascript(FString::Printf(
        TEXT("DialogueEngine.setLanguage(\"%s\")"), *EscapeJsString(Lang)));
}

void UDialogueBridgeComponent::SetFlag(const FString& Key, bool bValue)
{
    if (!Browser) return;
    Browser->ExecuteJavascript(FString::Printf(
        TEXT("DialogueEngine.setFlag(\"%s\", %s)"),
        *EscapeJsString(Key), bValue ? TEXT("true") : TEXT("false")));
}

void UDialogueBridgeComponent::SetVarString(const FString& Key, const FString& Value)
{
    if (!Browser) return;
    Browser->ExecuteJavascript(FString::Printf(
        TEXT("DialogueEngine.setVar(\"%s\", \"%s\")"),
        *EscapeJsString(Key), *EscapeJsString(Value)));
}

void UDialogueBridgeComponent::RequestSave()
{
    if (!Browser) return;
    Browser->ExecuteJavascript(TEXT("console.log('__DIALOGUE_SAVE__' + DialogueEngine.exportState())"));
}

void UDialogueBridgeComponent::ApplySave(const FDialogueSaveData& Data)
{
    if (!Browser) return;
    const FString Json = SerializeSave(Data);
    Browser->ExecuteJavascript(FString::Printf(
        TEXT("DialogueEngine.importState(\"%s\")"), *EscapeJsString(Json)));
}

void UDialogueBridgeComponent::InjectInitialData()
{
    if (!Browser) return;
    const FString InitJson = SerializeSave(PendingInitial);
    const FString Js = FString::Printf(
        TEXT("DialogueEngine.loadData(\"%s\",\"%s\",\"%s\",JSON.parse(\"%s\"))"),
        *EscapeJsString(NodesCsv),
        *EscapeJsString(ChoicesCsv),
        *EscapeJsString(LocCsv),
        *EscapeJsString(InitJson));
    Browser->ExecuteJavascript(Js);
    NodesCsv.Empty();
    ChoicesCsv.Empty();
    LocCsv.Empty();
}

FString UDialogueBridgeComponent::ResolveContentPath(const FString& RelPath)
{
    FString Full = FPaths::Combine(FPaths::ProjectContentDir(), RelPath);
    FPaths::NormalizeFilename(Full);
    return Full;
}

bool UDialogueBridgeComponent::LoadContentCsv(const FString& RelPath, FString& Out)
{
    return FFileHelper::LoadFileToString(Out, *ResolveContentPath(RelPath));
}

bool UDialogueBridgeComponent::BuildContentFileUrl(const FString& RelPath, FString& OutUrl)
{
    const FString Full = FPaths::ConvertRelativePathToFull(ResolveContentPath(RelPath));
    if (!FPaths::FileExists(Full))
    {
        return false;
    }
    OutUrl = TEXT("file:///") + PercentEncodeUrlPath(Full);
    return true;
}

FString UDialogueBridgeComponent::PercentEncodeUrlPath(const FString& In)
{
    // Preserve structural chars: '/' (path sep) and ':' (drive letter on Windows).
    // Everything else outside RFC 3986 unreserved set gets percent-encoded.
    FString Out;
    Out.Reserve(In.Len() + 16);
    for (TCHAR C : In)
    {
        if ((C >= 'A' && C <= 'Z') || (C >= 'a' && C <= 'z') || (C >= '0' && C <= '9') ||
            C == '-' || C == '.' || C == '_' || C == '~' || C == '/' || C == ':')
        {
            Out.AppendChar(C);
        }
        else
        {
            Out.Appendf(TEXT("%%%02X"), static_cast<uint32>(C));
        }
    }
    return Out;
}

FString UDialogueBridgeComponent::EscapeJsString(const FString& In)
{
    FString Out;
    Out.Reserve(In.Len() * 2);
    for (TCHAR C : In)
    {
        switch (C)
        {
            case '\\': Out.Append(TEXT("\\\\")); break;
            case '"':  Out.Append(TEXT("\\\"")); break;
            case '\n': Out.Append(TEXT("\\n"));  break;
            case '\r': Out.Append(TEXT("\\r"));  break;
            case '\t': Out.Append(TEXT("\\t"));  break;
            case '\b': Out.Append(TEXT("\\b"));  break;
            case '\f': Out.Append(TEXT("\\f"));  break;
            default:
                if (C < 0x20) // Control chars get escaped as \uXXXX to avoid breaking JS string literals.
                    Out.Appendf(TEXT("\\u%04X"), static_cast<uint32>(C)); // u%04x escapes control chars to avoid breaking JS string literals.
                else
                    Out.AppendChar(C);
                break;
        }
    }
    return Out;
}

FString UDialogueBridgeComponent::SerializeSave(const FDialogueSaveData& Data)
{
    TSharedRef<FJsonObject> Obj = MakeShared<FJsonObject>();
    Obj->SetStringField(TEXT("nodeId"), Data.NodeId);
    Obj->SetStringField(TEXT("lang"),   Data.Language);

    TSharedRef<FJsonObject> VarsObj = MakeShared<FJsonObject>();
    for (const TPair<FString, FString>& Pair : Data.Vars)
    {
        VarsObj->SetStringField(Pair.Key, Pair.Value);
    }
    Obj->SetObjectField(TEXT("vars"), VarsObj);

    FString Out;
    TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&Out);
    FJsonSerializer::Serialize(Obj, Writer);
    return Out;
}

bool UDialogueBridgeComponent::DeserializeSave(const FString& Json, FDialogueSaveData& Out)
{
    TSharedPtr<FJsonObject> Obj;
    const TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Json);
    if (!FJsonSerializer::Deserialize(Reader, Obj) || !Obj.IsValid())
    {
        return false;
    }

    Obj->TryGetStringField(TEXT("nodeId"), Out.NodeId);
    Obj->TryGetStringField(TEXT("lang"),   Out.Language);

    const TSharedPtr<FJsonObject>* VarsObj = nullptr;
    if (Obj->TryGetObjectField(TEXT("vars"), VarsObj) && VarsObj && VarsObj->IsValid())
    {
        for (const auto& Pair : (*VarsObj)->Values)
        {
            if (!Pair.Value.IsValid()) continue;
            // Booleans and numbers get stringified so the UE-side map stays flat.
            switch (Pair.Value->Type)
            {
                case EJson::String:  Out.Vars.Add(Pair.Key, Pair.Value->AsString()); break;
                case EJson::Boolean: Out.Vars.Add(Pair.Key, Pair.Value->AsBool() ? TEXT("true") : TEXT("false")); break;
                case EJson::Number:  Out.Vars.Add(Pair.Key, FString::SanitizeFloat(Pair.Value->AsNumber())); break;
                default: break;
            }
        }
    }
    return true;
}
