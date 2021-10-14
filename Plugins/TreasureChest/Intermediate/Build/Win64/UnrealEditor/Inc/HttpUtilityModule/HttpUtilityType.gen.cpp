// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HttpUtilityModule/Public/HttpCommon/HttpUtilityType.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHttpUtilityType() {}
// Cross Module References
	HTTPUTILITYMODULE_API UFunction* Z_Construct_UDelegateFunction_HttpUtilityModule_ReceivedDelegate__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_HttpUtilityModule();
	HTTPUTILITYMODULE_API UFunction* Z_Construct_UDelegateFunction_HttpUtilityModule_ProgressDelegate__DelegateSignature();
	HTTPUTILITYMODULE_API UFunction* Z_Construct_UDelegateFunction_HttpUtilityModule_CompleteDelegate__DelegateSignature();
	HTTPUTILITYMODULE_API UEnum* Z_Construct_UEnum_HttpUtilityModule_ERequestContentType();
	HTTPUTILITYMODULE_API UEnum* Z_Construct_UEnum_HttpUtilityModule_ERequestVerb();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_HttpUtilityModule_ReceivedDelegate__DelegateSignature_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_HttpUtilityModule_ReceivedDelegate__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/HttpCommon/HttpUtilityType.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_HttpUtilityModule_ReceivedDelegate__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_HttpUtilityModule, nullptr, "ReceivedDelegate__DelegateSignature", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_HttpUtilityModule_ReceivedDelegate__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_HttpUtilityModule_ReceivedDelegate__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_HttpUtilityModule_ReceivedDelegate__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UDelegateFunction_HttpUtilityModule_ReceivedDelegate__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_HttpUtilityModule_ProgressDelegate__DelegateSignature_Statics
	{
		struct _Script_HttpUtilityModule_eventProgressDelegate_Parms
		{
			int32 InSent;
			int32 InRece;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_InSent;
		static const UECodeGen_Private::FIntPropertyParams NewProp_InRece;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_HttpUtilityModule_ProgressDelegate__DelegateSignature_Statics::NewProp_InSent = { "InSent", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_HttpUtilityModule_eventProgressDelegate_Parms, InSent), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_HttpUtilityModule_ProgressDelegate__DelegateSignature_Statics::NewProp_InRece = { "InRece", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_HttpUtilityModule_eventProgressDelegate_Parms, InRece), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_HttpUtilityModule_ProgressDelegate__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_HttpUtilityModule_ProgressDelegate__DelegateSignature_Statics::NewProp_InSent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_HttpUtilityModule_ProgressDelegate__DelegateSignature_Statics::NewProp_InRece,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_HttpUtilityModule_ProgressDelegate__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/HttpCommon/HttpUtilityType.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_HttpUtilityModule_ProgressDelegate__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_HttpUtilityModule, nullptr, "ProgressDelegate__DelegateSignature", nullptr, nullptr, sizeof(_Script_HttpUtilityModule_eventProgressDelegate_Parms), Z_Construct_UDelegateFunction_HttpUtilityModule_ProgressDelegate__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_HttpUtilityModule_ProgressDelegate__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_HttpUtilityModule_ProgressDelegate__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_HttpUtilityModule_ProgressDelegate__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_HttpUtilityModule_ProgressDelegate__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UDelegateFunction_HttpUtilityModule_ProgressDelegate__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_HttpUtilityModule_CompleteDelegate__DelegateSignature_Statics
	{
		struct _Script_HttpUtilityModule_eventCompleteDelegate_Parms
		{
			FString Content;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Content_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Content;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_HttpUtilityModule_CompleteDelegate__DelegateSignature_Statics::NewProp_Content_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_HttpUtilityModule_CompleteDelegate__DelegateSignature_Statics::NewProp_Content = { "Content", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_HttpUtilityModule_eventCompleteDelegate_Parms, Content), METADATA_PARAMS(Z_Construct_UDelegateFunction_HttpUtilityModule_CompleteDelegate__DelegateSignature_Statics::NewProp_Content_MetaData, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_HttpUtilityModule_CompleteDelegate__DelegateSignature_Statics::NewProp_Content_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_HttpUtilityModule_CompleteDelegate__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_HttpUtilityModule_CompleteDelegate__DelegateSignature_Statics::NewProp_Content,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_HttpUtilityModule_CompleteDelegate__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/HttpCommon/HttpUtilityType.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_HttpUtilityModule_CompleteDelegate__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_HttpUtilityModule, nullptr, "CompleteDelegate__DelegateSignature", nullptr, nullptr, sizeof(_Script_HttpUtilityModule_eventCompleteDelegate_Parms), Z_Construct_UDelegateFunction_HttpUtilityModule_CompleteDelegate__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_HttpUtilityModule_CompleteDelegate__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_HttpUtilityModule_CompleteDelegate__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_HttpUtilityModule_CompleteDelegate__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_HttpUtilityModule_CompleteDelegate__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UDelegateFunction_HttpUtilityModule_CompleteDelegate__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	static UEnum* ERequestContentType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_HttpUtilityModule_ERequestContentType, Z_Construct_UPackage__Script_HttpUtilityModule(), TEXT("ERequestContentType"));
		}
		return Singleton;
	}
	template<> HTTPUTILITYMODULE_API UEnum* StaticEnum<ERequestContentType>()
	{
		return ERequestContentType_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_ERequestContentType(ERequestContentType_StaticEnum, TEXT("/Script/HttpUtilityModule"), TEXT("ERequestContentType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_HttpUtilityModule_ERequestContentType_Hash() { return 2016766967U; }
	UEnum* Z_Construct_UEnum_HttpUtilityModule_ERequestContentType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_HttpUtilityModule();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("ERequestContentType"), 0, Get_Z_Construct_UEnum_HttpUtilityModule_ERequestContentType_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UECodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "ERequestContentType::NORMAL", (int64)ERequestContentType::NORMAL },
				{ "ERequestContentType::JSON", (int64)ERequestContentType::JSON },
			};
#if WITH_METADATA
			const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "JSON.Name", "ERequestContentType::JSON" },
				{ "ModuleRelativePath", "Public/HttpCommon/HttpUtilityType.h" },
				{ "NORMAL.Name", "ERequestContentType::NORMAL" },
			};
#endif
			static const UECodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_HttpUtilityModule,
				nullptr,
				"ERequestContentType",
				"ERequestContentType",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UECodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UECodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static UEnum* ERequestVerb_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_HttpUtilityModule_ERequestVerb, Z_Construct_UPackage__Script_HttpUtilityModule(), TEXT("ERequestVerb"));
		}
		return Singleton;
	}
	template<> HTTPUTILITYMODULE_API UEnum* StaticEnum<ERequestVerb>()
	{
		return ERequestVerb_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_ERequestVerb(ERequestVerb_StaticEnum, TEXT("/Script/HttpUtilityModule"), TEXT("ERequestVerb"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_HttpUtilityModule_ERequestVerb_Hash() { return 1850537772U; }
	UEnum* Z_Construct_UEnum_HttpUtilityModule_ERequestVerb()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_HttpUtilityModule();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("ERequestVerb"), 0, Get_Z_Construct_UEnum_HttpUtilityModule_ERequestVerb_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UECodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "ERequestVerb::GET", (int64)ERequestVerb::GET },
				{ "ERequestVerb::PUT", (int64)ERequestVerb::PUT },
				{ "ERequestVerb::POST", (int64)ERequestVerb::POST },
				{ "ERequestVerb::DELETE", (int64)ERequestVerb::DELETE },
			};
#if WITH_METADATA
			const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "DELETE.Name", "ERequestVerb::DELETE" },
				{ "GET.Name", "ERequestVerb::GET" },
				{ "ModuleRelativePath", "Public/HttpCommon/HttpUtilityType.h" },
				{ "POST.Name", "ERequestVerb::POST" },
				{ "PUT.Name", "ERequestVerb::PUT" },
			};
#endif
			static const UECodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_HttpUtilityModule,
				nullptr,
				"ERequestVerb",
				"ERequestVerb",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UECodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UECodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
