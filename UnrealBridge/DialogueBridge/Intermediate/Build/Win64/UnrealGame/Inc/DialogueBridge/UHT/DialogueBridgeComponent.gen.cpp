// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DialogueBridgeComponent.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeDialogueBridgeComponent() {}

// ********** Begin Cross Module References ********************************************************
DIALOGUEBRIDGE_API UClass* Z_Construct_UClass_UDialogueBridgeComponent();
DIALOGUEBRIDGE_API UClass* Z_Construct_UClass_UDialogueBridgeComponent_NoRegister();
DIALOGUEBRIDGE_API UFunction* Z_Construct_UDelegateFunction_DialogueBridge_DialogueErrorDelegate__DelegateSignature();
DIALOGUEBRIDGE_API UFunction* Z_Construct_UDelegateFunction_DialogueBridge_DialogueEventDelegate__DelegateSignature();
DIALOGUEBRIDGE_API UFunction* Z_Construct_UDelegateFunction_DialogueBridge_DialogueNodeChangedDelegate__DelegateSignature();
DIALOGUEBRIDGE_API UFunction* Z_Construct_UDelegateFunction_DialogueBridge_DialogueReadyDelegate__DelegateSignature();
DIALOGUEBRIDGE_API UFunction* Z_Construct_UDelegateFunction_DialogueBridge_DialogueSaveReadyDelegate__DelegateSignature();
DIALOGUEBRIDGE_API UScriptStruct* Z_Construct_UScriptStruct_FDialogueSaveData();
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
UPackage* Z_Construct_UPackage__Script_DialogueBridge();
WEBBROWSERWIDGET_API UClass* Z_Construct_UClass_UWebBrowser_NoRegister();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FDialogueSaveData *************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDialogueSaveData;
class UScriptStruct* FDialogueSaveData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FDialogueSaveData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FDialogueSaveData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDialogueSaveData, (UObject*)Z_Construct_UPackage__Script_DialogueBridge(), TEXT("DialogueSaveData"));
	}
	return Z_Registration_Info_UScriptStruct_FDialogueSaveData.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FDialogueSaveData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/DialogueBridgeComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NodeId_MetaData[] = {
		{ "Category", "Dialogue" },
		{ "ModuleRelativePath", "Public/DialogueBridgeComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Language_MetaData[] = {
		{ "Category", "Dialogue" },
		{ "ModuleRelativePath", "Public/DialogueBridgeComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Vars_MetaData[] = {
		{ "Category", "Dialogue" },
		{ "ModuleRelativePath", "Public/DialogueBridgeComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_NodeId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Language;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Vars_ValueProp;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Vars_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_Vars;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDialogueSaveData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDialogueSaveData_Statics::NewProp_NodeId = { "NodeId", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDialogueSaveData, NodeId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NodeId_MetaData), NewProp_NodeId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDialogueSaveData_Statics::NewProp_Language = { "Language", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDialogueSaveData, Language), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Language_MetaData), NewProp_Language_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDialogueSaveData_Statics::NewProp_Vars_ValueProp = { "Vars", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDialogueSaveData_Statics::NewProp_Vars_Key_KeyProp = { "Vars_Key", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UScriptStruct_FDialogueSaveData_Statics::NewProp_Vars = { "Vars", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDialogueSaveData, Vars), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Vars_MetaData), NewProp_Vars_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FDialogueSaveData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueSaveData_Statics::NewProp_NodeId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueSaveData_Statics::NewProp_Language,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueSaveData_Statics::NewProp_Vars_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueSaveData_Statics::NewProp_Vars_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueSaveData_Statics::NewProp_Vars,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDialogueSaveData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FDialogueSaveData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_DialogueBridge,
	nullptr,
	&NewStructOps,
	"DialogueSaveData",
	Z_Construct_UScriptStruct_FDialogueSaveData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDialogueSaveData_Statics::PropPointers),
	sizeof(FDialogueSaveData),
	alignof(FDialogueSaveData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDialogueSaveData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FDialogueSaveData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FDialogueSaveData()
{
	if (!Z_Registration_Info_UScriptStruct_FDialogueSaveData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDialogueSaveData.InnerSingleton, Z_Construct_UScriptStruct_FDialogueSaveData_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FDialogueSaveData.InnerSingleton;
}
// ********** End ScriptStruct FDialogueSaveData ***************************************************

// ********** Begin Delegate FDialogueReadyDelegate ************************************************
struct Z_Construct_UDelegateFunction_DialogueBridge_DialogueReadyDelegate__DelegateSignature_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DialogueBridgeComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_DialogueBridge_DialogueReadyDelegate__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_DialogueBridge, nullptr, "DialogueReadyDelegate__DelegateSignature", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_DialogueBridge_DialogueReadyDelegate__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_DialogueBridge_DialogueReadyDelegate__DelegateSignature_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UDelegateFunction_DialogueBridge_DialogueReadyDelegate__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_DialogueBridge_DialogueReadyDelegate__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FDialogueReadyDelegate_DelegateWrapper(const FMulticastScriptDelegate& DialogueReadyDelegate)
{
	DialogueReadyDelegate.ProcessMulticastDelegate<UObject>(NULL);
}
// ********** End Delegate FDialogueReadyDelegate **************************************************

// ********** Begin Delegate FDialogueSaveReadyDelegate ********************************************
struct Z_Construct_UDelegateFunction_DialogueBridge_DialogueSaveReadyDelegate__DelegateSignature_Statics
{
	struct _Script_DialogueBridge_eventDialogueSaveReadyDelegate_Parms
	{
		FDialogueSaveData SaveData;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DialogueBridgeComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SaveData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_SaveData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_DialogueBridge_DialogueSaveReadyDelegate__DelegateSignature_Statics::NewProp_SaveData = { "SaveData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DialogueBridge_eventDialogueSaveReadyDelegate_Parms, SaveData), Z_Construct_UScriptStruct_FDialogueSaveData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SaveData_MetaData), NewProp_SaveData_MetaData) }; // 105436896
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_DialogueBridge_DialogueSaveReadyDelegate__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_DialogueBridge_DialogueSaveReadyDelegate__DelegateSignature_Statics::NewProp_SaveData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_DialogueBridge_DialogueSaveReadyDelegate__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_DialogueBridge_DialogueSaveReadyDelegate__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_DialogueBridge, nullptr, "DialogueSaveReadyDelegate__DelegateSignature", Z_Construct_UDelegateFunction_DialogueBridge_DialogueSaveReadyDelegate__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_DialogueBridge_DialogueSaveReadyDelegate__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_DialogueBridge_DialogueSaveReadyDelegate__DelegateSignature_Statics::_Script_DialogueBridge_eventDialogueSaveReadyDelegate_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00530000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_DialogueBridge_DialogueSaveReadyDelegate__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_DialogueBridge_DialogueSaveReadyDelegate__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_DialogueBridge_DialogueSaveReadyDelegate__DelegateSignature_Statics::_Script_DialogueBridge_eventDialogueSaveReadyDelegate_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_DialogueBridge_DialogueSaveReadyDelegate__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_DialogueBridge_DialogueSaveReadyDelegate__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FDialogueSaveReadyDelegate_DelegateWrapper(const FMulticastScriptDelegate& DialogueSaveReadyDelegate, FDialogueSaveData const& SaveData)
{
	struct _Script_DialogueBridge_eventDialogueSaveReadyDelegate_Parms
	{
		FDialogueSaveData SaveData;
	};
	_Script_DialogueBridge_eventDialogueSaveReadyDelegate_Parms Parms;
	Parms.SaveData=SaveData;
	DialogueSaveReadyDelegate.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FDialogueSaveReadyDelegate **********************************************

// ********** Begin Delegate FDialogueErrorDelegate ************************************************
struct Z_Construct_UDelegateFunction_DialogueBridge_DialogueErrorDelegate__DelegateSignature_Statics
{
	struct _Script_DialogueBridge_eventDialogueErrorDelegate_Parms
	{
		FString Message;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DialogueBridgeComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Message_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_Message;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_DialogueBridge_DialogueErrorDelegate__DelegateSignature_Statics::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DialogueBridge_eventDialogueErrorDelegate_Parms, Message), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Message_MetaData), NewProp_Message_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_DialogueBridge_DialogueErrorDelegate__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_DialogueBridge_DialogueErrorDelegate__DelegateSignature_Statics::NewProp_Message,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_DialogueBridge_DialogueErrorDelegate__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_DialogueBridge_DialogueErrorDelegate__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_DialogueBridge, nullptr, "DialogueErrorDelegate__DelegateSignature", Z_Construct_UDelegateFunction_DialogueBridge_DialogueErrorDelegate__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_DialogueBridge_DialogueErrorDelegate__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_DialogueBridge_DialogueErrorDelegate__DelegateSignature_Statics::_Script_DialogueBridge_eventDialogueErrorDelegate_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_DialogueBridge_DialogueErrorDelegate__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_DialogueBridge_DialogueErrorDelegate__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_DialogueBridge_DialogueErrorDelegate__DelegateSignature_Statics::_Script_DialogueBridge_eventDialogueErrorDelegate_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_DialogueBridge_DialogueErrorDelegate__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_DialogueBridge_DialogueErrorDelegate__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FDialogueErrorDelegate_DelegateWrapper(const FMulticastScriptDelegate& DialogueErrorDelegate, const FString& Message)
{
	struct _Script_DialogueBridge_eventDialogueErrorDelegate_Parms
	{
		FString Message;
	};
	_Script_DialogueBridge_eventDialogueErrorDelegate_Parms Parms;
	Parms.Message=Message;
	DialogueErrorDelegate.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FDialogueErrorDelegate **************************************************

// ********** Begin Delegate FDialogueNodeChangedDelegate ******************************************
struct Z_Construct_UDelegateFunction_DialogueBridge_DialogueNodeChangedDelegate__DelegateSignature_Statics
{
	struct _Script_DialogueBridge_eventDialogueNodeChangedDelegate_Parms
	{
		FString NodeId;
		FString NodeJson;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DialogueBridgeComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NodeId_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NodeJson_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_NodeId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_NodeJson;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_DialogueBridge_DialogueNodeChangedDelegate__DelegateSignature_Statics::NewProp_NodeId = { "NodeId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DialogueBridge_eventDialogueNodeChangedDelegate_Parms, NodeId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NodeId_MetaData), NewProp_NodeId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_DialogueBridge_DialogueNodeChangedDelegate__DelegateSignature_Statics::NewProp_NodeJson = { "NodeJson", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DialogueBridge_eventDialogueNodeChangedDelegate_Parms, NodeJson), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NodeJson_MetaData), NewProp_NodeJson_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_DialogueBridge_DialogueNodeChangedDelegate__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_DialogueBridge_DialogueNodeChangedDelegate__DelegateSignature_Statics::NewProp_NodeId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_DialogueBridge_DialogueNodeChangedDelegate__DelegateSignature_Statics::NewProp_NodeJson,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_DialogueBridge_DialogueNodeChangedDelegate__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_DialogueBridge_DialogueNodeChangedDelegate__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_DialogueBridge, nullptr, "DialogueNodeChangedDelegate__DelegateSignature", Z_Construct_UDelegateFunction_DialogueBridge_DialogueNodeChangedDelegate__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_DialogueBridge_DialogueNodeChangedDelegate__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_DialogueBridge_DialogueNodeChangedDelegate__DelegateSignature_Statics::_Script_DialogueBridge_eventDialogueNodeChangedDelegate_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_DialogueBridge_DialogueNodeChangedDelegate__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_DialogueBridge_DialogueNodeChangedDelegate__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_DialogueBridge_DialogueNodeChangedDelegate__DelegateSignature_Statics::_Script_DialogueBridge_eventDialogueNodeChangedDelegate_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_DialogueBridge_DialogueNodeChangedDelegate__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_DialogueBridge_DialogueNodeChangedDelegate__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FDialogueNodeChangedDelegate_DelegateWrapper(const FMulticastScriptDelegate& DialogueNodeChangedDelegate, const FString& NodeId, const FString& NodeJson)
{
	struct _Script_DialogueBridge_eventDialogueNodeChangedDelegate_Parms
	{
		FString NodeId;
		FString NodeJson;
	};
	_Script_DialogueBridge_eventDialogueNodeChangedDelegate_Parms Parms;
	Parms.NodeId=NodeId;
	Parms.NodeJson=NodeJson;
	DialogueNodeChangedDelegate.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FDialogueNodeChangedDelegate ********************************************

// ********** Begin Delegate FDialogueEventDelegate ************************************************
struct Z_Construct_UDelegateFunction_DialogueBridge_DialogueEventDelegate__DelegateSignature_Statics
{
	struct _Script_DialogueBridge_eventDialogueEventDelegate_Parms
	{
		FString EventName;
		FString PayloadJson;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DialogueBridgeComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EventName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PayloadJson_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_EventName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_PayloadJson;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_DialogueBridge_DialogueEventDelegate__DelegateSignature_Statics::NewProp_EventName = { "EventName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DialogueBridge_eventDialogueEventDelegate_Parms, EventName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EventName_MetaData), NewProp_EventName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_DialogueBridge_DialogueEventDelegate__DelegateSignature_Statics::NewProp_PayloadJson = { "PayloadJson", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DialogueBridge_eventDialogueEventDelegate_Parms, PayloadJson), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PayloadJson_MetaData), NewProp_PayloadJson_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_DialogueBridge_DialogueEventDelegate__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_DialogueBridge_DialogueEventDelegate__DelegateSignature_Statics::NewProp_EventName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_DialogueBridge_DialogueEventDelegate__DelegateSignature_Statics::NewProp_PayloadJson,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_DialogueBridge_DialogueEventDelegate__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_DialogueBridge_DialogueEventDelegate__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_DialogueBridge, nullptr, "DialogueEventDelegate__DelegateSignature", Z_Construct_UDelegateFunction_DialogueBridge_DialogueEventDelegate__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_DialogueBridge_DialogueEventDelegate__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_DialogueBridge_DialogueEventDelegate__DelegateSignature_Statics::_Script_DialogueBridge_eventDialogueEventDelegate_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_DialogueBridge_DialogueEventDelegate__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_DialogueBridge_DialogueEventDelegate__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_DialogueBridge_DialogueEventDelegate__DelegateSignature_Statics::_Script_DialogueBridge_eventDialogueEventDelegate_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_DialogueBridge_DialogueEventDelegate__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_DialogueBridge_DialogueEventDelegate__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FDialogueEventDelegate_DelegateWrapper(const FMulticastScriptDelegate& DialogueEventDelegate, const FString& EventName, const FString& PayloadJson)
{
	struct _Script_DialogueBridge_eventDialogueEventDelegate_Parms
	{
		FString EventName;
		FString PayloadJson;
	};
	_Script_DialogueBridge_eventDialogueEventDelegate_Parms Parms;
	Parms.EventName=EventName;
	Parms.PayloadJson=PayloadJson;
	DialogueEventDelegate.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FDialogueEventDelegate **************************************************

// ********** Begin Class UDialogueBridgeComponent Function ApplySave ******************************
struct Z_Construct_UFunction_UDialogueBridgeComponent_ApplySave_Statics
{
	struct DialogueBridgeComponent_eventApplySave_Parms
	{
		FDialogueSaveData Data;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dialogue" },
		{ "Comment", "// Push a save back into the engine; re-enters the stored node with restored vars + lang.\n" },
		{ "ModuleRelativePath", "Public/DialogueBridgeComponent.h" },
		{ "ToolTip", "Push a save back into the engine; re-enters the stored node with restored vars + lang." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Data_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Data;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDialogueBridgeComponent_ApplySave_Statics::NewProp_Data = { "Data", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DialogueBridgeComponent_eventApplySave_Parms, Data), Z_Construct_UScriptStruct_FDialogueSaveData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Data_MetaData), NewProp_Data_MetaData) }; // 105436896
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDialogueBridgeComponent_ApplySave_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDialogueBridgeComponent_ApplySave_Statics::NewProp_Data,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueBridgeComponent_ApplySave_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDialogueBridgeComponent_ApplySave_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDialogueBridgeComponent, nullptr, "ApplySave", Z_Construct_UFunction_UDialogueBridgeComponent_ApplySave_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueBridgeComponent_ApplySave_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDialogueBridgeComponent_ApplySave_Statics::DialogueBridgeComponent_eventApplySave_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueBridgeComponent_ApplySave_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDialogueBridgeComponent_ApplySave_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDialogueBridgeComponent_ApplySave_Statics::DialogueBridgeComponent_eventApplySave_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDialogueBridgeComponent_ApplySave()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDialogueBridgeComponent_ApplySave_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDialogueBridgeComponent::execApplySave)
{
	P_GET_STRUCT_REF(FDialogueSaveData,Z_Param_Out_Data);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ApplySave(Z_Param_Out_Data);
	P_NATIVE_END;
}
// ********** End Class UDialogueBridgeComponent Function ApplySave ********************************

// ********** Begin Class UDialogueBridgeComponent Function HandleConsoleMessage *******************
struct Z_Construct_UFunction_UDialogueBridgeComponent_HandleConsoleMessage_Statics
{
	struct DialogueBridgeComponent_eventHandleConsoleMessage_Parms
	{
		FString Message;
		FString Source;
		int32 Line;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DialogueBridgeComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Message_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Source_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_Message;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Source;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Line;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDialogueBridgeComponent_HandleConsoleMessage_Statics::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DialogueBridgeComponent_eventHandleConsoleMessage_Parms, Message), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Message_MetaData), NewProp_Message_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDialogueBridgeComponent_HandleConsoleMessage_Statics::NewProp_Source = { "Source", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DialogueBridgeComponent_eventHandleConsoleMessage_Parms, Source), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Source_MetaData), NewProp_Source_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDialogueBridgeComponent_HandleConsoleMessage_Statics::NewProp_Line = { "Line", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DialogueBridgeComponent_eventHandleConsoleMessage_Parms, Line), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDialogueBridgeComponent_HandleConsoleMessage_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDialogueBridgeComponent_HandleConsoleMessage_Statics::NewProp_Message,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDialogueBridgeComponent_HandleConsoleMessage_Statics::NewProp_Source,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDialogueBridgeComponent_HandleConsoleMessage_Statics::NewProp_Line,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueBridgeComponent_HandleConsoleMessage_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDialogueBridgeComponent_HandleConsoleMessage_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDialogueBridgeComponent, nullptr, "HandleConsoleMessage", Z_Construct_UFunction_UDialogueBridgeComponent_HandleConsoleMessage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueBridgeComponent_HandleConsoleMessage_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDialogueBridgeComponent_HandleConsoleMessage_Statics::DialogueBridgeComponent_eventHandleConsoleMessage_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueBridgeComponent_HandleConsoleMessage_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDialogueBridgeComponent_HandleConsoleMessage_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDialogueBridgeComponent_HandleConsoleMessage_Statics::DialogueBridgeComponent_eventHandleConsoleMessage_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDialogueBridgeComponent_HandleConsoleMessage()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDialogueBridgeComponent_HandleConsoleMessage_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDialogueBridgeComponent::execHandleConsoleMessage)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Message);
	P_GET_PROPERTY(FStrProperty,Z_Param_Source);
	P_GET_PROPERTY(FIntProperty,Z_Param_Line);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleConsoleMessage(Z_Param_Message,Z_Param_Source,Z_Param_Line);
	P_NATIVE_END;
}
// ********** End Class UDialogueBridgeComponent Function HandleConsoleMessage *********************

// ********** Begin Class UDialogueBridgeComponent Function Init ***********************************
struct Z_Construct_UFunction_UDialogueBridgeComponent_Init_Statics
{
	struct DialogueBridgeComponent_eventInit_Parms
	{
		UWebBrowser* InBrowser;
		FString HudHtmlRelPath;
		FString NodesCsvRelPath;
		FString ChoicesCsvRelPath;
		FString LocCsvRelPath;
		FDialogueSaveData InitialState;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dialogue" },
		{ "Comment", "// Paths are relative to project Content/. Init also navigates the browser to the HUD.\n// InitialState: pass default-constructed struct for a fresh run, or a previously captured save.\n" },
		{ "ModuleRelativePath", "Public/DialogueBridgeComponent.h" },
		{ "ToolTip", "Paths are relative to project Content/. Init also navigates the browser to the HUD.\nInitialState: pass default-constructed struct for a fresh run, or a previously captured save." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InBrowser_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HudHtmlRelPath_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NodesCsvRelPath_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ChoicesCsvRelPath_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LocCsvRelPath_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InitialState_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InBrowser;
	static const UECodeGen_Private::FStrPropertyParams NewProp_HudHtmlRelPath;
	static const UECodeGen_Private::FStrPropertyParams NewProp_NodesCsvRelPath;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ChoicesCsvRelPath;
	static const UECodeGen_Private::FStrPropertyParams NewProp_LocCsvRelPath;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InitialState;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDialogueBridgeComponent_Init_Statics::NewProp_InBrowser = { "InBrowser", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DialogueBridgeComponent_eventInit_Parms, InBrowser), Z_Construct_UClass_UWebBrowser_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InBrowser_MetaData), NewProp_InBrowser_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDialogueBridgeComponent_Init_Statics::NewProp_HudHtmlRelPath = { "HudHtmlRelPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DialogueBridgeComponent_eventInit_Parms, HudHtmlRelPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HudHtmlRelPath_MetaData), NewProp_HudHtmlRelPath_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDialogueBridgeComponent_Init_Statics::NewProp_NodesCsvRelPath = { "NodesCsvRelPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DialogueBridgeComponent_eventInit_Parms, NodesCsvRelPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NodesCsvRelPath_MetaData), NewProp_NodesCsvRelPath_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDialogueBridgeComponent_Init_Statics::NewProp_ChoicesCsvRelPath = { "ChoicesCsvRelPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DialogueBridgeComponent_eventInit_Parms, ChoicesCsvRelPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ChoicesCsvRelPath_MetaData), NewProp_ChoicesCsvRelPath_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDialogueBridgeComponent_Init_Statics::NewProp_LocCsvRelPath = { "LocCsvRelPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DialogueBridgeComponent_eventInit_Parms, LocCsvRelPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LocCsvRelPath_MetaData), NewProp_LocCsvRelPath_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDialogueBridgeComponent_Init_Statics::NewProp_InitialState = { "InitialState", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DialogueBridgeComponent_eventInit_Parms, InitialState), Z_Construct_UScriptStruct_FDialogueSaveData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InitialState_MetaData), NewProp_InitialState_MetaData) }; // 105436896
void Z_Construct_UFunction_UDialogueBridgeComponent_Init_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((DialogueBridgeComponent_eventInit_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDialogueBridgeComponent_Init_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DialogueBridgeComponent_eventInit_Parms), &Z_Construct_UFunction_UDialogueBridgeComponent_Init_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDialogueBridgeComponent_Init_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDialogueBridgeComponent_Init_Statics::NewProp_InBrowser,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDialogueBridgeComponent_Init_Statics::NewProp_HudHtmlRelPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDialogueBridgeComponent_Init_Statics::NewProp_NodesCsvRelPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDialogueBridgeComponent_Init_Statics::NewProp_ChoicesCsvRelPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDialogueBridgeComponent_Init_Statics::NewProp_LocCsvRelPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDialogueBridgeComponent_Init_Statics::NewProp_InitialState,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDialogueBridgeComponent_Init_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueBridgeComponent_Init_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDialogueBridgeComponent_Init_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDialogueBridgeComponent, nullptr, "Init", Z_Construct_UFunction_UDialogueBridgeComponent_Init_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueBridgeComponent_Init_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDialogueBridgeComponent_Init_Statics::DialogueBridgeComponent_eventInit_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueBridgeComponent_Init_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDialogueBridgeComponent_Init_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDialogueBridgeComponent_Init_Statics::DialogueBridgeComponent_eventInit_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDialogueBridgeComponent_Init()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDialogueBridgeComponent_Init_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDialogueBridgeComponent::execInit)
{
	P_GET_OBJECT(UWebBrowser,Z_Param_InBrowser);
	P_GET_PROPERTY(FStrProperty,Z_Param_HudHtmlRelPath);
	P_GET_PROPERTY(FStrProperty,Z_Param_NodesCsvRelPath);
	P_GET_PROPERTY(FStrProperty,Z_Param_ChoicesCsvRelPath);
	P_GET_PROPERTY(FStrProperty,Z_Param_LocCsvRelPath);
	P_GET_STRUCT_REF(FDialogueSaveData,Z_Param_Out_InitialState);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->Init(Z_Param_InBrowser,Z_Param_HudHtmlRelPath,Z_Param_NodesCsvRelPath,Z_Param_ChoicesCsvRelPath,Z_Param_LocCsvRelPath,Z_Param_Out_InitialState);
	P_NATIVE_END;
}
// ********** End Class UDialogueBridgeComponent Function Init *************************************

// ********** Begin Class UDialogueBridgeComponent Function JumpToNode *****************************
struct Z_Construct_UFunction_UDialogueBridgeComponent_JumpToNode_Statics
{
	struct DialogueBridgeComponent_eventJumpToNode_Parms
	{
		FString NodeId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dialogue" },
		{ "ModuleRelativePath", "Public/DialogueBridgeComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NodeId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_NodeId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDialogueBridgeComponent_JumpToNode_Statics::NewProp_NodeId = { "NodeId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DialogueBridgeComponent_eventJumpToNode_Parms, NodeId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NodeId_MetaData), NewProp_NodeId_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDialogueBridgeComponent_JumpToNode_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDialogueBridgeComponent_JumpToNode_Statics::NewProp_NodeId,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueBridgeComponent_JumpToNode_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDialogueBridgeComponent_JumpToNode_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDialogueBridgeComponent, nullptr, "JumpToNode", Z_Construct_UFunction_UDialogueBridgeComponent_JumpToNode_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueBridgeComponent_JumpToNode_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDialogueBridgeComponent_JumpToNode_Statics::DialogueBridgeComponent_eventJumpToNode_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueBridgeComponent_JumpToNode_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDialogueBridgeComponent_JumpToNode_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDialogueBridgeComponent_JumpToNode_Statics::DialogueBridgeComponent_eventJumpToNode_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDialogueBridgeComponent_JumpToNode()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDialogueBridgeComponent_JumpToNode_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDialogueBridgeComponent::execJumpToNode)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_NodeId);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->JumpToNode(Z_Param_NodeId);
	P_NATIVE_END;
}
// ********** End Class UDialogueBridgeComponent Function JumpToNode *******************************

// ********** Begin Class UDialogueBridgeComponent Function RequestSave ****************************
struct Z_Construct_UFunction_UDialogueBridgeComponent_RequestSave_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dialogue" },
		{ "Comment", "// Ask engine for a save snapshot. Result arrives via OnSaveReady (async, one frame).\n" },
		{ "ModuleRelativePath", "Public/DialogueBridgeComponent.h" },
		{ "ToolTip", "Ask engine for a save snapshot. Result arrives via OnSaveReady (async, one frame)." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDialogueBridgeComponent_RequestSave_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDialogueBridgeComponent, nullptr, "RequestSave", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueBridgeComponent_RequestSave_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDialogueBridgeComponent_RequestSave_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UDialogueBridgeComponent_RequestSave()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDialogueBridgeComponent_RequestSave_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDialogueBridgeComponent::execRequestSave)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RequestSave();
	P_NATIVE_END;
}
// ********** End Class UDialogueBridgeComponent Function RequestSave ******************************

// ********** Begin Class UDialogueBridgeComponent Function SetFlag ********************************
struct Z_Construct_UFunction_UDialogueBridgeComponent_SetFlag_Statics
{
	struct DialogueBridgeComponent_eventSetFlag_Parms
	{
		FString Key;
		bool bValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dialogue" },
		{ "ModuleRelativePath", "Public/DialogueBridgeComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Key_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_Key;
	static void NewProp_bValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDialogueBridgeComponent_SetFlag_Statics::NewProp_Key = { "Key", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DialogueBridgeComponent_eventSetFlag_Parms, Key), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Key_MetaData), NewProp_Key_MetaData) };
void Z_Construct_UFunction_UDialogueBridgeComponent_SetFlag_Statics::NewProp_bValue_SetBit(void* Obj)
{
	((DialogueBridgeComponent_eventSetFlag_Parms*)Obj)->bValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDialogueBridgeComponent_SetFlag_Statics::NewProp_bValue = { "bValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DialogueBridgeComponent_eventSetFlag_Parms), &Z_Construct_UFunction_UDialogueBridgeComponent_SetFlag_Statics::NewProp_bValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDialogueBridgeComponent_SetFlag_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDialogueBridgeComponent_SetFlag_Statics::NewProp_Key,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDialogueBridgeComponent_SetFlag_Statics::NewProp_bValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueBridgeComponent_SetFlag_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDialogueBridgeComponent_SetFlag_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDialogueBridgeComponent, nullptr, "SetFlag", Z_Construct_UFunction_UDialogueBridgeComponent_SetFlag_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueBridgeComponent_SetFlag_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDialogueBridgeComponent_SetFlag_Statics::DialogueBridgeComponent_eventSetFlag_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueBridgeComponent_SetFlag_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDialogueBridgeComponent_SetFlag_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDialogueBridgeComponent_SetFlag_Statics::DialogueBridgeComponent_eventSetFlag_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDialogueBridgeComponent_SetFlag()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDialogueBridgeComponent_SetFlag_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDialogueBridgeComponent::execSetFlag)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Key);
	P_GET_UBOOL(Z_Param_bValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetFlag(Z_Param_Key,Z_Param_bValue);
	P_NATIVE_END;
}
// ********** End Class UDialogueBridgeComponent Function SetFlag **********************************

// ********** Begin Class UDialogueBridgeComponent Function SetLanguage ****************************
struct Z_Construct_UFunction_UDialogueBridgeComponent_SetLanguage_Statics
{
	struct DialogueBridgeComponent_eventSetLanguage_Parms
	{
		FString Lang;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dialogue" },
		{ "ModuleRelativePath", "Public/DialogueBridgeComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Lang_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_Lang;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDialogueBridgeComponent_SetLanguage_Statics::NewProp_Lang = { "Lang", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DialogueBridgeComponent_eventSetLanguage_Parms, Lang), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Lang_MetaData), NewProp_Lang_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDialogueBridgeComponent_SetLanguage_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDialogueBridgeComponent_SetLanguage_Statics::NewProp_Lang,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueBridgeComponent_SetLanguage_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDialogueBridgeComponent_SetLanguage_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDialogueBridgeComponent, nullptr, "SetLanguage", Z_Construct_UFunction_UDialogueBridgeComponent_SetLanguage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueBridgeComponent_SetLanguage_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDialogueBridgeComponent_SetLanguage_Statics::DialogueBridgeComponent_eventSetLanguage_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueBridgeComponent_SetLanguage_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDialogueBridgeComponent_SetLanguage_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDialogueBridgeComponent_SetLanguage_Statics::DialogueBridgeComponent_eventSetLanguage_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDialogueBridgeComponent_SetLanguage()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDialogueBridgeComponent_SetLanguage_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDialogueBridgeComponent::execSetLanguage)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Lang);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetLanguage(Z_Param_Lang);
	P_NATIVE_END;
}
// ********** End Class UDialogueBridgeComponent Function SetLanguage ******************************

// ********** Begin Class UDialogueBridgeComponent Function SetVarString ***************************
struct Z_Construct_UFunction_UDialogueBridgeComponent_SetVarString_Statics
{
	struct DialogueBridgeComponent_eventSetVarString_Parms
	{
		FString Key;
		FString Value;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dialogue" },
		{ "ModuleRelativePath", "Public/DialogueBridgeComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Key_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_Key;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Value;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDialogueBridgeComponent_SetVarString_Statics::NewProp_Key = { "Key", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DialogueBridgeComponent_eventSetVarString_Parms, Key), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Key_MetaData), NewProp_Key_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDialogueBridgeComponent_SetVarString_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DialogueBridgeComponent_eventSetVarString_Parms, Value), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Value_MetaData), NewProp_Value_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDialogueBridgeComponent_SetVarString_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDialogueBridgeComponent_SetVarString_Statics::NewProp_Key,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDialogueBridgeComponent_SetVarString_Statics::NewProp_Value,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueBridgeComponent_SetVarString_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDialogueBridgeComponent_SetVarString_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDialogueBridgeComponent, nullptr, "SetVarString", Z_Construct_UFunction_UDialogueBridgeComponent_SetVarString_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueBridgeComponent_SetVarString_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDialogueBridgeComponent_SetVarString_Statics::DialogueBridgeComponent_eventSetVarString_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueBridgeComponent_SetVarString_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDialogueBridgeComponent_SetVarString_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDialogueBridgeComponent_SetVarString_Statics::DialogueBridgeComponent_eventSetVarString_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDialogueBridgeComponent_SetVarString()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDialogueBridgeComponent_SetVarString_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDialogueBridgeComponent::execSetVarString)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Key);
	P_GET_PROPERTY(FStrProperty,Z_Param_Value);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetVarString(Z_Param_Key,Z_Param_Value);
	P_NATIVE_END;
}
// ********** End Class UDialogueBridgeComponent Function SetVarString *****************************

// ********** Begin Class UDialogueBridgeComponent *************************************************
void UDialogueBridgeComponent::StaticRegisterNativesUDialogueBridgeComponent()
{
	UClass* Class = UDialogueBridgeComponent::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ApplySave", &UDialogueBridgeComponent::execApplySave },
		{ "HandleConsoleMessage", &UDialogueBridgeComponent::execHandleConsoleMessage },
		{ "Init", &UDialogueBridgeComponent::execInit },
		{ "JumpToNode", &UDialogueBridgeComponent::execJumpToNode },
		{ "RequestSave", &UDialogueBridgeComponent::execRequestSave },
		{ "SetFlag", &UDialogueBridgeComponent::execSetFlag },
		{ "SetLanguage", &UDialogueBridgeComponent::execSetLanguage },
		{ "SetVarString", &UDialogueBridgeComponent::execSetVarString },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UDialogueBridgeComponent;
UClass* UDialogueBridgeComponent::GetPrivateStaticClass()
{
	using TClass = UDialogueBridgeComponent;
	if (!Z_Registration_Info_UClass_UDialogueBridgeComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("DialogueBridgeComponent"),
			Z_Registration_Info_UClass_UDialogueBridgeComponent.InnerSingleton,
			StaticRegisterNativesUDialogueBridgeComponent,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_UDialogueBridgeComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UDialogueBridgeComponent_NoRegister()
{
	return UDialogueBridgeComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UDialogueBridgeComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Dialogue" },
		{ "IncludePath", "DialogueBridgeComponent.h" },
		{ "ModuleRelativePath", "Public/DialogueBridgeComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnReady_MetaData[] = {
		{ "Category", "Dialogue" },
		{ "ModuleRelativePath", "Public/DialogueBridgeComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnSaveReady_MetaData[] = {
		{ "Category", "Dialogue" },
		{ "ModuleRelativePath", "Public/DialogueBridgeComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnNodeChanged_MetaData[] = {
		{ "Category", "Dialogue" },
		{ "ModuleRelativePath", "Public/DialogueBridgeComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnDialogueEvent_MetaData[] = {
		{ "Category", "Dialogue" },
		{ "ModuleRelativePath", "Public/DialogueBridgeComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnError_MetaData[] = {
		{ "Category", "Dialogue" },
		{ "ModuleRelativePath", "Public/DialogueBridgeComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Browser_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DialogueBridgeComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnReady;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnSaveReady;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnNodeChanged;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnDialogueEvent;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnError;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Browser;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UDialogueBridgeComponent_ApplySave, "ApplySave" }, // 3913522422
		{ &Z_Construct_UFunction_UDialogueBridgeComponent_HandleConsoleMessage, "HandleConsoleMessage" }, // 3627687082
		{ &Z_Construct_UFunction_UDialogueBridgeComponent_Init, "Init" }, // 3594325473
		{ &Z_Construct_UFunction_UDialogueBridgeComponent_JumpToNode, "JumpToNode" }, // 2371408647
		{ &Z_Construct_UFunction_UDialogueBridgeComponent_RequestSave, "RequestSave" }, // 3546038172
		{ &Z_Construct_UFunction_UDialogueBridgeComponent_SetFlag, "SetFlag" }, // 3507117872
		{ &Z_Construct_UFunction_UDialogueBridgeComponent_SetLanguage, "SetLanguage" }, // 2449583710
		{ &Z_Construct_UFunction_UDialogueBridgeComponent_SetVarString, "SetVarString" }, // 3857993672
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDialogueBridgeComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UDialogueBridgeComponent_Statics::NewProp_OnReady = { "OnReady", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueBridgeComponent, OnReady), Z_Construct_UDelegateFunction_DialogueBridge_DialogueReadyDelegate__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnReady_MetaData), NewProp_OnReady_MetaData) }; // 936704296
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UDialogueBridgeComponent_Statics::NewProp_OnSaveReady = { "OnSaveReady", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueBridgeComponent, OnSaveReady), Z_Construct_UDelegateFunction_DialogueBridge_DialogueSaveReadyDelegate__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnSaveReady_MetaData), NewProp_OnSaveReady_MetaData) }; // 1136822335
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UDialogueBridgeComponent_Statics::NewProp_OnNodeChanged = { "OnNodeChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueBridgeComponent, OnNodeChanged), Z_Construct_UDelegateFunction_DialogueBridge_DialogueNodeChangedDelegate__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnNodeChanged_MetaData), NewProp_OnNodeChanged_MetaData) }; // 2020676478
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UDialogueBridgeComponent_Statics::NewProp_OnDialogueEvent = { "OnDialogueEvent", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueBridgeComponent, OnDialogueEvent), Z_Construct_UDelegateFunction_DialogueBridge_DialogueEventDelegate__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnDialogueEvent_MetaData), NewProp_OnDialogueEvent_MetaData) }; // 1971207637
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UDialogueBridgeComponent_Statics::NewProp_OnError = { "OnError", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueBridgeComponent, OnError), Z_Construct_UDelegateFunction_DialogueBridge_DialogueErrorDelegate__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnError_MetaData), NewProp_OnError_MetaData) }; // 1376965033
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDialogueBridgeComponent_Statics::NewProp_Browser = { "Browser", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueBridgeComponent, Browser), Z_Construct_UClass_UWebBrowser_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Browser_MetaData), NewProp_Browser_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDialogueBridgeComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueBridgeComponent_Statics::NewProp_OnReady,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueBridgeComponent_Statics::NewProp_OnSaveReady,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueBridgeComponent_Statics::NewProp_OnNodeChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueBridgeComponent_Statics::NewProp_OnDialogueEvent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueBridgeComponent_Statics::NewProp_OnError,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueBridgeComponent_Statics::NewProp_Browser,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueBridgeComponent_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UDialogueBridgeComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_DialogueBridge,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueBridgeComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDialogueBridgeComponent_Statics::ClassParams = {
	&UDialogueBridgeComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UDialogueBridgeComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueBridgeComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueBridgeComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UDialogueBridgeComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UDialogueBridgeComponent()
{
	if (!Z_Registration_Info_UClass_UDialogueBridgeComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDialogueBridgeComponent.OuterSingleton, Z_Construct_UClass_UDialogueBridgeComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDialogueBridgeComponent.OuterSingleton;
}
UDialogueBridgeComponent::UDialogueBridgeComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UDialogueBridgeComponent);
UDialogueBridgeComponent::~UDialogueBridgeComponent() {}
// ********** End Class UDialogueBridgeComponent ***************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_PluginBuild_DialogueBridge_HostProject_Plugins_DialogueBridge_Source_DialogueBridge_Public_DialogueBridgeComponent_h__Script_DialogueBridge_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FDialogueSaveData::StaticStruct, Z_Construct_UScriptStruct_FDialogueSaveData_Statics::NewStructOps, TEXT("DialogueSaveData"), &Z_Registration_Info_UScriptStruct_FDialogueSaveData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDialogueSaveData), 105436896U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDialogueBridgeComponent, UDialogueBridgeComponent::StaticClass, TEXT("UDialogueBridgeComponent"), &Z_Registration_Info_UClass_UDialogueBridgeComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDialogueBridgeComponent), 1565087947U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_PluginBuild_DialogueBridge_HostProject_Plugins_DialogueBridge_Source_DialogueBridge_Public_DialogueBridgeComponent_h__Script_DialogueBridge_2886621800(TEXT("/Script/DialogueBridge"),
	Z_CompiledInDeferFile_FID_PluginBuild_DialogueBridge_HostProject_Plugins_DialogueBridge_Source_DialogueBridge_Public_DialogueBridgeComponent_h__Script_DialogueBridge_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_PluginBuild_DialogueBridge_HostProject_Plugins_DialogueBridge_Source_DialogueBridge_Public_DialogueBridgeComponent_h__Script_DialogueBridge_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_PluginBuild_DialogueBridge_HostProject_Plugins_DialogueBridge_Source_DialogueBridge_Public_DialogueBridgeComponent_h__Script_DialogueBridge_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_PluginBuild_DialogueBridge_HostProject_Plugins_DialogueBridge_Source_DialogueBridge_Public_DialogueBridgeComponent_h__Script_DialogueBridge_Statics::ScriptStructInfo),
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
