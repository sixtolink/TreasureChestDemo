// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HttpTool/Public/HttpLib.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHttpLib() {}
// Cross Module References
	HTTPTOOL_API UClass* Z_Construct_UClass_UHttpLib_NoRegister();
	HTTPTOOL_API UClass* Z_Construct_UClass_UHttpLib();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_HttpTool();
// End Cross Module References
	DEFINE_FUNCTION(UHttpLib::execCusGetObject)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_InURL);
		P_GET_PROPERTY(FStrProperty,Z_Param_InSavePaths);
		P_FINISH;
		P_NATIVE_BEGIN;
		UHttpLib::CusGetObject(Z_Param_InURL,Z_Param_InSavePaths);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UHttpLib::execCusPutObject)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_InURL);
		P_GET_PROPERTY(FStrProperty,Z_Param_InLocalPaths);
		P_FINISH;
		P_NATIVE_BEGIN;
		UHttpLib::CusPutObject(Z_Param_InURL,Z_Param_InLocalPaths);
		P_NATIVE_END;
	}
	void UHttpLib::StaticRegisterNativesUHttpLib()
	{
		UClass* Class = UHttpLib::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CusGetObject", &UHttpLib::execCusGetObject },
			{ "CusPutObject", &UHttpLib::execCusPutObject },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UHttpLib_CusGetObject_Statics
	{
		struct HttpLib_eventCusGetObject_Parms
		{
			FString InURL;
			FString InSavePaths;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_InURL;
		static const UECodeGen_Private::FStrPropertyParams NewProp_InSavePaths;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UHttpLib_CusGetObject_Statics::NewProp_InURL = { "InURL", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(HttpLib_eventCusGetObject_Parms, InURL), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UHttpLib_CusGetObject_Statics::NewProp_InSavePaths = { "InSavePaths", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(HttpLib_eventCusGetObject_Parms, InSavePaths), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UHttpLib_CusGetObject_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHttpLib_CusGetObject_Statics::NewProp_InURL,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHttpLib_CusGetObject_Statics::NewProp_InSavePaths,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UHttpLib_CusGetObject_Statics::Function_MetaDataParams[] = {
		{ "Category", "CusHttp" },
		{ "ModuleRelativePath", "Public/HttpLib.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UHttpLib_CusGetObject_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UHttpLib, nullptr, "CusGetObject", nullptr, nullptr, sizeof(HttpLib_eventCusGetObject_Parms), Z_Construct_UFunction_UHttpLib_CusGetObject_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UHttpLib_CusGetObject_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UHttpLib_CusGetObject_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UHttpLib_CusGetObject_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UHttpLib_CusGetObject()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UHttpLib_CusGetObject_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UHttpLib_CusPutObject_Statics
	{
		struct HttpLib_eventCusPutObject_Parms
		{
			FString InURL;
			FString InLocalPaths;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_InURL;
		static const UECodeGen_Private::FStrPropertyParams NewProp_InLocalPaths;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UHttpLib_CusPutObject_Statics::NewProp_InURL = { "InURL", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(HttpLib_eventCusPutObject_Parms, InURL), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UHttpLib_CusPutObject_Statics::NewProp_InLocalPaths = { "InLocalPaths", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(HttpLib_eventCusPutObject_Parms, InLocalPaths), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UHttpLib_CusPutObject_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHttpLib_CusPutObject_Statics::NewProp_InURL,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHttpLib_CusPutObject_Statics::NewProp_InLocalPaths,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UHttpLib_CusPutObject_Statics::Function_MetaDataParams[] = {
		{ "Category", "CusHttp" },
		{ "ModuleRelativePath", "Public/HttpLib.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UHttpLib_CusPutObject_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UHttpLib, nullptr, "CusPutObject", nullptr, nullptr, sizeof(HttpLib_eventCusPutObject_Parms), Z_Construct_UFunction_UHttpLib_CusPutObject_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UHttpLib_CusPutObject_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UHttpLib_CusPutObject_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UHttpLib_CusPutObject_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UHttpLib_CusPutObject()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UHttpLib_CusPutObject_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UHttpLib_NoRegister()
	{
		return UHttpLib::StaticClass();
	}
	struct Z_Construct_UClass_UHttpLib_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UHttpLib_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_HttpTool,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UHttpLib_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UHttpLib_CusGetObject, "CusGetObject" }, // 327232371
		{ &Z_Construct_UFunction_UHttpLib_CusPutObject, "CusPutObject" }, // 2597620029
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHttpLib_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "HttpLib.h" },
		{ "ModuleRelativePath", "Public/HttpLib.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UHttpLib_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UHttpLib>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UHttpLib_Statics::ClassParams = {
		&UHttpLib::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UHttpLib_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UHttpLib_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UHttpLib()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UECodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UHttpLib_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UHttpLib, 2395391048);
	template<> HTTPTOOL_API UClass* StaticClass<UHttpLib>()
	{
		return UHttpLib::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UHttpLib(Z_Construct_UClass_UHttpLib, &UHttpLib::StaticClass, TEXT("/Script/HttpTool"), TEXT("UHttpLib"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UHttpLib);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
