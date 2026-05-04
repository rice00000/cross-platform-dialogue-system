#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DialogueBridgeComponent.generated.h"

class UWebBrowser;

USTRUCT(BlueprintType)
struct DIALOGUEBRIDGE_API FDialogueSaveData
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Dialogue")
    FString NodeId;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Dialogue")
    FString Language;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Dialogue")
    TMap<FString, FString> Vars;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDialogueReadyDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDialogueSaveReadyDelegate, const FDialogueSaveData&, SaveData);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDialogueErrorDelegate, const FString&, Message);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FDialogueNodeChangedDelegate, const FString&, NodeId, const FString&, SpeakerKey, const FString&, NodeJson);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDialogueEventDelegate, const FString&, EventName, const FString&, PayloadJson);

UCLASS(ClassGroup=(Dialogue), meta=(BlueprintSpawnableComponent))
class DIALOGUEBRIDGE_API UDialogueBridgeComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    // Paths are relative to project Content/. Init also navigates the browser to the HUD.
    // InitialState: pass default-constructed struct for a fresh run, or a previously captured save.
    UFUNCTION(BlueprintCallable, Category="Dialogue")
    bool Init(UWebBrowser* InBrowser,
              const FString& HudHtmlRelPath,
              const FString& NodesCsvRelPath,
              const FString& ChoicesCsvRelPath,
              const FString& LocCsvRelPath,
              const FDialogueSaveData& InitialState);

    UFUNCTION(BlueprintCallable, Category="Dialogue")
    void JumpToNode(const FString& NodeId);

    UFUNCTION(BlueprintCallable, Category="Dialogue")
    void SetLanguage(const FString& Lang);

    UFUNCTION(BlueprintCallable, Category="Dialogue")
    void SetFlag(const FString& Key, bool bValue);

    UFUNCTION(BlueprintCallable, Category="Dialogue")
    void SetVarString(const FString& Key, const FString& Value);

    // Ask engine for a save snapshot. Result arrives via OnSaveReady (async, one frame).
    UFUNCTION(BlueprintCallable, Category="Dialogue")
    void RequestSave();

    // Push a save back into the engine; re-enters the stored node with restored vars + lang.
    UFUNCTION(BlueprintCallable, Category="Dialogue")
    void ApplySave(const FDialogueSaveData& Data);

    UPROPERTY(BlueprintAssignable, Category="Dialogue")
    FDialogueReadyDelegate OnReady;

    UPROPERTY(BlueprintAssignable, Category="Dialogue")
    FDialogueSaveReadyDelegate OnSaveReady;

    UPROPERTY(BlueprintAssignable, Category="Dialogue")
    FDialogueNodeChangedDelegate OnNodeChanged;

    UPROPERTY(BlueprintAssignable, Category="Dialogue")
    FDialogueEventDelegate OnDialogueEvent;

    UPROPERTY(BlueprintAssignable, Category="Dialogue")
    FDialogueErrorDelegate OnError;

    UFUNCTION()
    void HandleConsoleMessage(const FString& Message, const FString& Source, int32 Line);

private:
    UPROPERTY()
    UWebBrowser* Browser = nullptr;

    FString NodesCsv;
    FString ChoicesCsv;
    FString LocCsv;
    FDialogueSaveData PendingInitial;
    bool bInjected = false;

    void NotifyReady();
    void NotifySave(const FString& StateJson);
    void NotifyNodeChanged(const FString& NodeJson);
    void NotifyDialogueEvent(const FString& PayloadJson);
    void InjectInitialData();

    static FString ResolveContentPath(const FString& RelPath);
    static bool LoadContentCsv(const FString& RelPath, FString& Out);
    static bool BuildContentFileUrl(const FString& RelPath, FString& OutUrl);
    static FString PercentEncodeUrlPath(const FString& In);
    static FString EscapeJsString(const FString& In);
    static FString SerializeSave(const FDialogueSaveData& Data);
    static bool DeserializeSave(const FString& Json, FDialogueSaveData& Out);
};
