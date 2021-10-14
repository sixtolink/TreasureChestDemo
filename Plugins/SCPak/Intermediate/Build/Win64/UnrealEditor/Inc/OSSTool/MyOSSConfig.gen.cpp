// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OSSTool/Public/Setting/MyOSSConfig.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyOSSConfig() {}
// Cross Module References
	OSSTOOL_API UClass* Z_Construct_UClass_UMyOSSConfig_NoRegister();
	OSSTOOL_API UClass* Z_Construct_UClass_UMyOSSConfig();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_OSSTool();
// End Cross Module References
	void UMyOSSConfig::StaticRegisterNativesUMyOSSConfig()
	{
	}
	UClass* Z_Construct_UClass_UMyOSSConfig_NoRegister()
	{
		return UMyOSSConfig::StaticClass();
	}
	struct Z_Construct_UClass_UMyOSSConfig_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AccessKeyID_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_AccessKeyID;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AccessSecret_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_AccessSecret;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Endpoint_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Endpoint;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_BucketName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_BucketName;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMyOSSConfig_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_OSSTool,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyOSSConfig_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n *\n */" },
		{ "IncludePath", "Setting/MyOSSConfig.h" },
		{ "ModuleRelativePath", "Public/Setting/MyOSSConfig.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyOSSConfig_Statics::NewProp_AccessKeyID_MetaData[] = {
		{ "Category", "OSSConfig" },
		{ "ModuleRelativePath", "Public/Setting/MyOSSConfig.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UMyOSSConfig_Statics::NewProp_AccessKeyID = { "AccessKeyID", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMyOSSConfig, AccessKeyID), METADATA_PARAMS(Z_Construct_UClass_UMyOSSConfig_Statics::NewProp_AccessKeyID_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMyOSSConfig_Statics::NewProp_AccessKeyID_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyOSSConfig_Statics::NewProp_AccessSecret_MetaData[] = {
		{ "Category", "OSSConfig" },
		{ "ModuleRelativePath", "Public/Setting/MyOSSConfig.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UMyOSSConfig_Statics::NewProp_AccessSecret = { "AccessSecret", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMyOSSConfig, AccessSecret), METADATA_PARAMS(Z_Construct_UClass_UMyOSSConfig_Statics::NewProp_AccessSecret_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMyOSSConfig_Statics::NewProp_AccessSecret_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyOSSConfig_Statics::NewProp_Endpoint_MetaData[] = {
		{ "Category", "OSSConfig" },
		{ "ModuleRelativePath", "Public/Setting/MyOSSConfig.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UMyOSSConfig_Statics::NewProp_Endpoint = { "Endpoint", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMyOSSConfig, Endpoint), METADATA_PARAMS(Z_Construct_UClass_UMyOSSConfig_Statics::NewProp_Endpoint_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMyOSSConfig_Statics::NewProp_Endpoint_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyOSSConfig_Statics::NewProp_BucketName_MetaData[] = {
		{ "Category", "OSSConfig" },
		{ "ModuleRelativePath", "Public/Setting/MyOSSConfig.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UMyOSSConfig_Statics::NewProp_BucketName = { "BucketName", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMyOSSConfig, BucketName), METADATA_PARAMS(Z_Construct_UClass_UMyOSSConfig_Statics::NewProp_BucketName_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMyOSSConfig_Statics::NewProp_BucketName_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UMyOSSConfig_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyOSSConfig_Statics::NewProp_AccessKeyID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyOSSConfig_Statics::NewProp_AccessSecret,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyOSSConfig_Statics::NewProp_Endpoint,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyOSSConfig_Statics::NewProp_BucketName,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMyOSSConfig_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMyOSSConfig>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UMyOSSConfig_Statics::ClassParams = {
		&UMyOSSConfig::StaticClass,
		"OSSConfig",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UMyOSSConfig_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UMyOSSConfig_Statics::PropPointers),
		0,
		0x001000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UMyOSSConfig_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UMyOSSConfig_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UMyOSSConfig()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UECodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UMyOSSConfig_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UMyOSSConfig, 2727556918);
	template<> OSSTOOL_API UClass* StaticClass<UMyOSSConfig>()
	{
		return UMyOSSConfig::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UMyOSSConfig(Z_Construct_UClass_UMyOSSConfig, &UMyOSSConfig::StaticClass, TEXT("/Script/OSSTool"), TEXT("UMyOSSConfig"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMyOSSConfig);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
