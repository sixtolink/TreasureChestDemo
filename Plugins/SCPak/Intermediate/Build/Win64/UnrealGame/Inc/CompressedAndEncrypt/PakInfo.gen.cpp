// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CompressedAndEncrypt/Public/PakInfo.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePakInfo() {}
// Cross Module References
	COMPRESSEDANDENCRYPT_API UEnum* Z_Construct_UEnum_CompressedAndEncrypt_EEncryptionMode();
	UPackage* Z_Construct_UPackage__Script_CompressedAndEncrypt();
// End Cross Module References
	static UEnum* EEncryptionMode_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_CompressedAndEncrypt_EEncryptionMode, Z_Construct_UPackage__Script_CompressedAndEncrypt(), TEXT("EEncryptionMode"));
		}
		return Singleton;
	}
	template<> COMPRESSEDANDENCRYPT_API UEnum* StaticEnum<EEncryptionMode>()
	{
		return EEncryptionMode_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EEncryptionMode(EEncryptionMode_StaticEnum, TEXT("/Script/CompressedAndEncrypt"), TEXT("EEncryptionMode"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_CompressedAndEncrypt_EEncryptionMode_Hash() { return 3776921626U; }
	UEnum* Z_Construct_UEnum_CompressedAndEncrypt_EEncryptionMode()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_CompressedAndEncrypt();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EEncryptionMode"), 0, Get_Z_Construct_UEnum_CompressedAndEncrypt_EEncryptionMode_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UECodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EEncryptionMode::NONE", (int64)EEncryptionMode::NONE },
				{ "EEncryptionMode::AES", (int64)EEncryptionMode::AES },
				{ "EEncryptionMode::MAX", (int64)EEncryptionMode::MAX },
			};
#if WITH_METADATA
			const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "AES.Name", "EEncryptionMode::AES" },
				{ "BlueprintType", "true" },
				{ "MAX.Name", "EEncryptionMode::MAX" },
				{ "ModuleRelativePath", "Public/PakInfo.h" },
				{ "NONE.Name", "EEncryptionMode::NONE" },
			};
#endif
			static const UECodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_CompressedAndEncrypt,
				nullptr,
				"EEncryptionMode",
				"EEncryptionMode",
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
