// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDialogueBridge_init() {}
	DIALOGUEBRIDGE_API UFunction* Z_Construct_UDelegateFunction_DialogueBridge_DialogueErrorDelegate__DelegateSignature();
	DIALOGUEBRIDGE_API UFunction* Z_Construct_UDelegateFunction_DialogueBridge_DialogueEventDelegate__DelegateSignature();
	DIALOGUEBRIDGE_API UFunction* Z_Construct_UDelegateFunction_DialogueBridge_DialogueNodeChangedDelegate__DelegateSignature();
	DIALOGUEBRIDGE_API UFunction* Z_Construct_UDelegateFunction_DialogueBridge_DialogueReadyDelegate__DelegateSignature();
	DIALOGUEBRIDGE_API UFunction* Z_Construct_UDelegateFunction_DialogueBridge_DialogueSaveReadyDelegate__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_DialogueBridge;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_DialogueBridge()
	{
		if (!Z_Registration_Info_UPackage__Script_DialogueBridge.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_DialogueBridge_DialogueErrorDelegate__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_DialogueBridge_DialogueEventDelegate__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_DialogueBridge_DialogueNodeChangedDelegate__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_DialogueBridge_DialogueReadyDelegate__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_DialogueBridge_DialogueSaveReadyDelegate__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/DialogueBridge",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0xC0534A7A,
				0x822075D1,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_DialogueBridge.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_DialogueBridge.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_DialogueBridge(Z_Construct_UPackage__Script_DialogueBridge, TEXT("/Script/DialogueBridge"), Z_Registration_Info_UPackage__Script_DialogueBridge, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xC0534A7A, 0x822075D1));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
