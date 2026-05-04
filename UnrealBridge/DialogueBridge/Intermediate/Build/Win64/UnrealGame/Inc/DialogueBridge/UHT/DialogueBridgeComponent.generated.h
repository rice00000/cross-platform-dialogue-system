// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "DialogueBridgeComponent.h"

#ifdef DIALOGUEBRIDGE_DialogueBridgeComponent_generated_h
#error "DialogueBridgeComponent.generated.h already included, missing '#pragma once' in DialogueBridgeComponent.h"
#endif
#define DIALOGUEBRIDGE_DialogueBridgeComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class UWebBrowser;
struct FDialogueSaveData;

// ********** Begin ScriptStruct FDialogueSaveData *************************************************
#define FID_PluginBuild_DialogueBridge_HostProject_Plugins_DialogueBridge_Source_DialogueBridge_Public_DialogueBridgeComponent_h_12_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FDialogueSaveData_Statics; \
	static class UScriptStruct* StaticStruct();


struct FDialogueSaveData;
// ********** End ScriptStruct FDialogueSaveData ***************************************************

// ********** Begin Delegate FDialogueReadyDelegate ************************************************
#define FID_PluginBuild_DialogueBridge_HostProject_Plugins_DialogueBridge_Source_DialogueBridge_Public_DialogueBridgeComponent_h_24_DELEGATE \
DIALOGUEBRIDGE_API void FDialogueReadyDelegate_DelegateWrapper(const FMulticastScriptDelegate& DialogueReadyDelegate);


// ********** End Delegate FDialogueReadyDelegate **************************************************

// ********** Begin Delegate FDialogueSaveReadyDelegate ********************************************
#define FID_PluginBuild_DialogueBridge_HostProject_Plugins_DialogueBridge_Source_DialogueBridge_Public_DialogueBridgeComponent_h_25_DELEGATE \
DIALOGUEBRIDGE_API void FDialogueSaveReadyDelegate_DelegateWrapper(const FMulticastScriptDelegate& DialogueSaveReadyDelegate, FDialogueSaveData const& SaveData);


// ********** End Delegate FDialogueSaveReadyDelegate **********************************************

// ********** Begin Delegate FDialogueErrorDelegate ************************************************
#define FID_PluginBuild_DialogueBridge_HostProject_Plugins_DialogueBridge_Source_DialogueBridge_Public_DialogueBridgeComponent_h_26_DELEGATE \
DIALOGUEBRIDGE_API void FDialogueErrorDelegate_DelegateWrapper(const FMulticastScriptDelegate& DialogueErrorDelegate, const FString& Message);


// ********** End Delegate FDialogueErrorDelegate **************************************************

// ********** Begin Delegate FDialogueNodeChangedDelegate ******************************************
#define FID_PluginBuild_DialogueBridge_HostProject_Plugins_DialogueBridge_Source_DialogueBridge_Public_DialogueBridgeComponent_h_27_DELEGATE \
DIALOGUEBRIDGE_API void FDialogueNodeChangedDelegate_DelegateWrapper(const FMulticastScriptDelegate& DialogueNodeChangedDelegate, const FString& NodeId, const FString& NodeJson);


// ********** End Delegate FDialogueNodeChangedDelegate ********************************************

// ********** Begin Delegate FDialogueEventDelegate ************************************************
#define FID_PluginBuild_DialogueBridge_HostProject_Plugins_DialogueBridge_Source_DialogueBridge_Public_DialogueBridgeComponent_h_28_DELEGATE \
DIALOGUEBRIDGE_API void FDialogueEventDelegate_DelegateWrapper(const FMulticastScriptDelegate& DialogueEventDelegate, const FString& EventName, const FString& PayloadJson);


// ********** End Delegate FDialogueEventDelegate **************************************************

// ********** Begin Class UDialogueBridgeComponent *************************************************
#define FID_PluginBuild_DialogueBridge_HostProject_Plugins_DialogueBridge_Source_DialogueBridge_Public_DialogueBridgeComponent_h_33_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execHandleConsoleMessage); \
	DECLARE_FUNCTION(execApplySave); \
	DECLARE_FUNCTION(execRequestSave); \
	DECLARE_FUNCTION(execSetVarString); \
	DECLARE_FUNCTION(execSetFlag); \
	DECLARE_FUNCTION(execSetLanguage); \
	DECLARE_FUNCTION(execJumpToNode); \
	DECLARE_FUNCTION(execInit);


DIALOGUEBRIDGE_API UClass* Z_Construct_UClass_UDialogueBridgeComponent_NoRegister();

#define FID_PluginBuild_DialogueBridge_HostProject_Plugins_DialogueBridge_Source_DialogueBridge_Public_DialogueBridgeComponent_h_33_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDialogueBridgeComponent(); \
	friend struct Z_Construct_UClass_UDialogueBridgeComponent_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend DIALOGUEBRIDGE_API UClass* Z_Construct_UClass_UDialogueBridgeComponent_NoRegister(); \
public: \
	DECLARE_CLASS2(UDialogueBridgeComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/DialogueBridge"), Z_Construct_UClass_UDialogueBridgeComponent_NoRegister) \
	DECLARE_SERIALIZER(UDialogueBridgeComponent)


#define FID_PluginBuild_DialogueBridge_HostProject_Plugins_DialogueBridge_Source_DialogueBridge_Public_DialogueBridgeComponent_h_33_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDialogueBridgeComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UDialogueBridgeComponent(UDialogueBridgeComponent&&) = delete; \
	UDialogueBridgeComponent(const UDialogueBridgeComponent&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDialogueBridgeComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDialogueBridgeComponent); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDialogueBridgeComponent) \
	NO_API virtual ~UDialogueBridgeComponent();


#define FID_PluginBuild_DialogueBridge_HostProject_Plugins_DialogueBridge_Source_DialogueBridge_Public_DialogueBridgeComponent_h_30_PROLOG
#define FID_PluginBuild_DialogueBridge_HostProject_Plugins_DialogueBridge_Source_DialogueBridge_Public_DialogueBridgeComponent_h_33_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_PluginBuild_DialogueBridge_HostProject_Plugins_DialogueBridge_Source_DialogueBridge_Public_DialogueBridgeComponent_h_33_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_PluginBuild_DialogueBridge_HostProject_Plugins_DialogueBridge_Source_DialogueBridge_Public_DialogueBridgeComponent_h_33_INCLASS_NO_PURE_DECLS \
	FID_PluginBuild_DialogueBridge_HostProject_Plugins_DialogueBridge_Source_DialogueBridge_Public_DialogueBridgeComponent_h_33_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UDialogueBridgeComponent;

// ********** End Class UDialogueBridgeComponent ***************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_PluginBuild_DialogueBridge_HostProject_Plugins_DialogueBridge_Source_DialogueBridge_Public_DialogueBridgeComponent_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
