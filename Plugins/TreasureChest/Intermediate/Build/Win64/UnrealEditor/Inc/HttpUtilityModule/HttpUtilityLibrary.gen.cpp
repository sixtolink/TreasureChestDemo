// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HttpUtilityModule/Public/BlueprintLibrary/HttpUtilityLibrary.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHttpUtilityLibrary() {}
// Cross Module References
	HTTPUTILITYMODULE_API UFunction* Z_Construct_UDelegateFunction_HttpUtilityModule_HttpRequestSuccessDelegate__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_HttpUtilityModule();
	HTTPUTILITYMODULE_API UClass* Z_Construct_UClass_UHttpUtilityLibrary_NoRegister();
	HTTPUTILITYMODULE_API UClass* Z_Construct_UClass_UHttpUtilityLibrary();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintAsyncActionBase();
	HTTPUTILITYMODULE_API UEnum* Z_Construct_UEnum_HttpUtilityModule_ERequestVerb();
	HTTPUTILITYMODULE_API UEnum* Z_Construct_UEnum_HttpUtilityModule_ERequestContentType();
	HTTPUTILITYMODULE_API UFunction* Z_Construct_UDelegateFunction_HttpUtilityModule_CompleteDelegate__DelegateSignature();
	HTTPUTILITYMODULE_API UFunction* Z_Construct_UDelegateFunction_HttpUtilityModule_ProgressDelegate__DelegateSignature();
	HTTPUTILITYMODULE_API UFunction* Z_Construct_UDelegateFunction_HttpUtilityModule_ReceivedDelegate__DelegateSignature();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_HttpUtilityModule_HttpRequestSuccessDelegate__DelegateSignature_Statics
	{
		struct _Script_HttpUtilityModule_eventHttpRequestSuccessDelegate_Parms
		{
			FString Msg;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Msg_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Msg;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_HttpUtilityModule_HttpRequestSuccessDelegate__DelegateSignature_Statics::NewProp_Msg_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_HttpUtilityModule_HttpRequestSuccessDelegate__DelegateSignature_Statics::NewProp_Msg = { "Msg", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_HttpUtilityModule_eventHttpRequestSuccessDelegate_Parms, Msg), METADATA_PARAMS(Z_Construct_UDelegateFunction_HttpUtilityModule_HttpRequestSuccessDelegate__DelegateSignature_Statics::NewProp_Msg_MetaData, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_HttpUtilityModule_HttpRequestSuccessDelegate__DelegateSignature_Statics::NewProp_Msg_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_HttpUtilityModule_HttpRequestSuccessDelegate__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_HttpUtilityModule_HttpRequestSuccessDelegate__DelegateSignature_Statics::NewProp_Msg,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_HttpUtilityModule_HttpRequestSuccessDelegate__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/BlueprintLibrary/HttpUtilityLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_HttpUtilityModule_HttpRequestSuccessDelegate__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_HttpUtilityModule, nullptr, "HttpRequestSuccessDelegate__DelegateSignature", nullptr, nullptr, sizeof(_Script_HttpUtilityModule_eventHttpRequestSuccessDelegate_Parms), Z_Construct_UDelegateFunction_HttpUtilityModule_HttpRequestSuccessDelegate__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_HttpUtilityModule_HttpRequestSuccessDelegate__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_HttpUtilityModule_HttpRequestSuccessDelegate__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_HttpUtilityModule_HttpRequestSuccessDelegate__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_HttpUtilityModule_HttpRequestSuccessDelegate__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UDelegateFunction_HttpUtilityModule_HttpRequestSuccessDelegate__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	DEFINE_FUNCTION(UHttpUtilityLibrary::execMyHttpProgress)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_InUrl);
		P_GET_ENUM(ERequestVerb,Z_Param_InVerb);
		P_GET_ENUM(ERequestContentType,Z_Param_InContentType);
		P_GET_TMAP_REF(FString,FString,Z_Param_Out_InHeadParam);
		P_GET_PROPERTY_REF(FDelegateProperty,Z_Param_Out_InCompleteDel);
		P_GET_PROPERTY_REF(FDelegateProperty,Z_Param_Out_InProgressDel);
		P_GET_PROPERTY_REF(FDelegateProperty,Z_Param_Out_InHeadReceDel);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UHttpUtilityLibrary**)Z_Param__Result=UHttpUtilityLibrary::MyHttpProgress(Z_Param_InUrl,ERequestVerb(Z_Param_InVerb),ERequestContentType(Z_Param_InContentType),Z_Param_Out_InHeadParam,FCompleteDelegate(Z_Param_Out_InCompleteDel),FProgressDelegate(Z_Param_Out_InProgressDel),FReceivedDelegate(Z_Param_Out_InHeadReceDel));
		P_NATIVE_END;
	}
	void UHttpUtilityLibrary::StaticRegisterNativesUHttpUtilityLibrary()
	{
		UClass* Class = UHttpUtilityLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "MyHttpProgress", &UHttpUtilityLibrary::execMyHttpProgress },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UHttpUtilityLibrary_MyHttpProgress_Statics
	{
		struct HttpUtilityLibrary_eventMyHttpProgress_Parms
		{
			FString InUrl;
			ERequestVerb InVerb;
			ERequestContentType InContentType;
			TMap<FString,FString> InHeadParam;
			FScriptDelegate InCompleteDel;
			FScriptDelegate InProgressDel;
			FScriptDelegate InHeadReceDel;
			UHttpUtilityLibrary* ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InUrl_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_InUrl;
		static const UECodeGen_Private::FBytePropertyParams NewProp_InVerb_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_InVerb;
		static const UECodeGen_Private::FBytePropertyParams NewProp_InContentType_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_InContentType;
		static const UECodeGen_Private::FStrPropertyParams NewProp_InHeadParam_ValueProp;
		static const UECodeGen_Private::FStrPropertyParams NewProp_InHeadParam_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InHeadParam_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_InHeadParam;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InCompleteDel_MetaData[];
#endif
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_InCompleteDel;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InProgressDel_MetaData[];
#endif
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_InProgressDel;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InHeadReceDel_MetaData[];
#endif
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_InHeadReceDel;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UHttpUtilityLibrary_MyHttpProgress_Statics::NewProp_InUrl_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UHttpUtilityLibrary_MyHttpProgress_Statics::NewProp_InUrl = { "InUrl", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(HttpUtilityLibrary_eventMyHttpProgress_Parms, InUrl), METADATA_PARAMS(Z_Construct_UFunction_UHttpUtilityLibrary_MyHttpProgress_Statics::NewProp_InUrl_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UHttpUtilityLibrary_MyHttpProgress_Statics::NewProp_InUrl_MetaData)) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UHttpUtilityLibrary_MyHttpProgress_Statics::NewProp_InVerb_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UHttpUtilityLibrary_MyHttpProgress_Statics::NewProp_InVerb = { "InVerb", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(HttpUtilityLibrary_eventMyHttpProgress_Parms, InVerb), Z_Construct_UEnum_HttpUtilityModule_ERequestVerb, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UHttpUtilityLibrary_MyHttpProgress_Statics::NewProp_InContentType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UHttpUtilityLibrary_MyHttpProgress_Statics::NewProp_InContentType = { "InContentType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(HttpUtilityLibrary_eventMyHttpProgress_Parms, InContentType), Z_Construct_UEnum_HttpUtilityModule_ERequestContentType, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UHttpUtilityLibrary_MyHttpProgress_Statics::NewProp_InHeadParam_ValueProp = { "InHeadParam", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 1, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UHttpUtilityLibrary_MyHttpProgress_Statics::NewProp_InHeadParam_Key_KeyProp = { "InHeadParam_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UHttpUtilityLibrary_MyHttpProgress_Statics::NewProp_InHeadParam_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UFunction_UHttpUtilityLibrary_MyHttpProgress_Statics::NewProp_InHeadParam = { "InHeadParam", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(HttpUtilityLibrary_eventMyHttpProgress_Parms, InHeadParam), EMapPropertyFlags::None, METADATA_PARAMS(Z_Construct_UFunction_UHttpUtilityLibrary_MyHttpProgress_Statics::NewProp_InHeadParam_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UHttpUtilityLibrary_MyHttpProgress_Statics::NewProp_InHeadParam_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UHttpUtilityLibrary_MyHttpProgress_Statics::NewProp_InCompleteDel_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UHttpUtilityLibrary_MyHttpProgress_Statics::NewProp_InCompleteDel = { "InCompleteDel", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(HttpUtilityLibrary_eventMyHttpProgress_Parms, InCompleteDel), Z_Construct_UDelegateFunction_HttpUtilityModule_CompleteDelegate__DelegateSignature, METADATA_PARAMS(Z_Construct_UFunction_UHttpUtilityLibrary_MyHttpProgress_Statics::NewProp_InCompleteDel_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UHttpUtilityLibrary_MyHttpProgress_Statics::NewProp_InCompleteDel_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UHttpUtilityLibrary_MyHttpProgress_Statics::NewProp_InProgressDel_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UHttpUtilityLibrary_MyHttpProgress_Statics::NewProp_InProgressDel = { "InProgressDel", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(HttpUtilityLibrary_eventMyHttpProgress_Parms, InProgressDel), Z_Construct_UDelegateFunction_HttpUtilityModule_ProgressDelegate__DelegateSignature, METADATA_PARAMS(Z_Construct_UFunction_UHttpUtilityLibrary_MyHttpProgress_Statics::NewProp_InProgressDel_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UHttpUtilityLibrary_MyHttpProgress_Statics::NewProp_InProgressDel_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UHttpUtilityLibrary_MyHttpProgress_Statics::NewProp_InHeadReceDel_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UHttpUtilityLibrary_MyHttpProgress_Statics::NewProp_InHeadReceDel = { "InHeadReceDel", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(HttpUtilityLibrary_eventMyHttpProgress_Parms, InHeadReceDel), Z_Construct_UDelegateFunction_HttpUtilityModule_ReceivedDelegate__DelegateSignature, METADATA_PARAMS(Z_Construct_UFunction_UHttpUtilityLibrary_MyHttpProgress_Statics::NewProp_InHeadReceDel_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UHttpUtilityLibrary_MyHttpProgress_Statics::NewProp_InHeadReceDel_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UHttpUtilityLibrary_MyHttpProgress_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(HttpUtilityLibrary_eventMyHttpProgress_Parms, ReturnValue), Z_Construct_UClass_UHttpUtilityLibrary_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UHttpUtilityLibrary_MyHttpProgress_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHttpUtilityLibrary_MyHttpProgress_Statics::NewProp_InUrl,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHttpUtilityLibrary_MyHttpProgress_Statics::NewProp_InVerb_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHttpUtilityLibrary_MyHttpProgress_Statics::NewProp_InVerb,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHttpUtilityLibrary_MyHttpProgress_Statics::NewProp_InContentType_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHttpUtilityLibrary_MyHttpProgress_Statics::NewProp_InContentType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHttpUtilityLibrary_MyHttpProgress_Statics::NewProp_InHeadParam_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHttpUtilityLibrary_MyHttpProgress_Statics::NewProp_InHeadParam_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHttpUtilityLibrary_MyHttpProgress_Statics::NewProp_InHeadParam,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHttpUtilityLibrary_MyHttpProgress_Statics::NewProp_InCompleteDel,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHttpUtilityLibrary_MyHttpProgress_Statics::NewProp_InProgressDel,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHttpUtilityLibrary_MyHttpProgress_Statics::NewProp_InHeadReceDel,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHttpUtilityLibrary_MyHttpProgress_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UHttpUtilityLibrary_MyHttpProgress_Statics::Function_MetaDataParams[] = {
		{ "Category", "HttpUtilities" },
		{ "DisplayName", "HttpProgress" },
		{ "Keywords", "HttpProgress" },
		{ "ModuleRelativePath", "Public/BlueprintLibrary/HttpUtilityLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UHttpUtilityLibrary_MyHttpProgress_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UHttpUtilityLibrary, nullptr, "MyHttpProgress", nullptr, nullptr, sizeof(HttpUtilityLibrary_eventMyHttpProgress_Parms), Z_Construct_UFunction_UHttpUtilityLibrary_MyHttpProgress_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UHttpUtilityLibrary_MyHttpProgress_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UHttpUtilityLibrary_MyHttpProgress_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UHttpUtilityLibrary_MyHttpProgress_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UHttpUtilityLibrary_MyHttpProgress()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UHttpUtilityLibrary_MyHttpProgress_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UHttpUtilityLibrary_NoRegister()
	{
		return UHttpUtilityLibrary::StaticClass();
	}
	struct Z_Construct_UClass_UHttpUtilityLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnSuccess_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnSuccess;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnFail_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnFail;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UHttpUtilityLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintAsyncActionBase,
		(UObject* (*)())Z_Construct_UPackage__Script_HttpUtilityModule,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UHttpUtilityLibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UHttpUtilityLibrary_MyHttpProgress, "MyHttpProgress" }, // 2301221453
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHttpUtilityLibrary_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "BlueprintLibrary/HttpUtilityLibrary.h" },
		{ "ModuleRelativePath", "Public/BlueprintLibrary/HttpUtilityLibrary.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHttpUtilityLibrary_Statics::NewProp_OnSuccess_MetaData[] = {
		{ "Category", "HttpUtilities" },
		{ "ModuleRelativePath", "Public/BlueprintLibrary/HttpUtilityLibrary.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UHttpUtilityLibrary_Statics::NewProp_OnSuccess = { "OnSuccess", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UHttpUtilityLibrary, OnSuccess), Z_Construct_UDelegateFunction_HttpUtilityModule_HttpRequestSuccessDelegate__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UHttpUtilityLibrary_Statics::NewProp_OnSuccess_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UHttpUtilityLibrary_Statics::NewProp_OnSuccess_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHttpUtilityLibrary_Statics::NewProp_OnFail_MetaData[] = {
		{ "Category", "HttpUtilities" },
		{ "ModuleRelativePath", "Public/BlueprintLibrary/HttpUtilityLibrary.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UHttpUtilityLibrary_Statics::NewProp_OnFail = { "OnFail", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UHttpUtilityLibrary, OnFail), Z_Construct_UDelegateFunction_HttpUtilityModule_HttpRequestSuccessDelegate__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UHttpUtilityLibrary_Statics::NewProp_OnFail_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UHttpUtilityLibrary_Statics::NewProp_OnFail_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UHttpUtilityLibrary_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHttpUtilityLibrary_Statics::NewProp_OnSuccess,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHttpUtilityLibrary_Statics::NewProp_OnFail,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UHttpUtilityLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UHttpUtilityLibrary>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UHttpUtilityLibrary_Statics::ClassParams = {
		&UHttpUtilityLibrary::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UHttpUtilityLibrary_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UHttpUtilityLibrary_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UHttpUtilityLibrary_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UHttpUtilityLibrary_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UHttpUtilityLibrary()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UECodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UHttpUtilityLibrary_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UHttpUtilityLibrary, 2060550625);
	template<> HTTPUTILITYMODULE_API UClass* StaticClass<UHttpUtilityLibrary>()
	{
		return UHttpUtilityLibrary::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UHttpUtilityLibrary(Z_Construct_UClass_UHttpUtilityLibrary, &UHttpUtilityLibrary::StaticClass, TEXT("/Script/HttpUtilityModule"), TEXT("UHttpUtilityLibrary"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UHttpUtilityLibrary);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
