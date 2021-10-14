// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MediaUtilityModule/Public/MediaCommon/MediaUtilityType.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMediaUtilityType() {}
// Cross Module References
	MEDIAUTILITYMODULE_API UEnum* Z_Construct_UEnum_MediaUtilityModule_ESynchronizationType();
	UPackage* Z_Construct_UPackage__Script_MediaUtilityModule();
	MEDIAUTILITYMODULE_API UEnum* Z_Construct_UEnum_MediaUtilityModule_ETransport();
// End Cross Module References
	static UEnum* ESynchronizationType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_MediaUtilityModule_ESynchronizationType, Z_Construct_UPackage__Script_MediaUtilityModule(), TEXT("ESynchronizationType"));
		}
		return Singleton;
	}
	template<> MEDIAUTILITYMODULE_API UEnum* StaticEnum<ESynchronizationType>()
	{
		return ESynchronizationType_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_ESynchronizationType(ESynchronizationType_StaticEnum, TEXT("/Script/MediaUtilityModule"), TEXT("ESynchronizationType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_MediaUtilityModule_ESynchronizationType_Hash() { return 2801174027U; }
	UEnum* Z_Construct_UEnum_MediaUtilityModule_ESynchronizationType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_MediaUtilityModule();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("ESynchronizationType"), 0, Get_Z_Construct_UEnum_MediaUtilityModule_ESynchronizationType_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UECodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "ESynchronizationType::AudioMaster", (int64)ESynchronizationType::AudioMaster },
				{ "ESynchronizationType::VideoMaster", (int64)ESynchronizationType::VideoMaster },
				{ "ESynchronizationType::ExternalClock", (int64)ESynchronizationType::ExternalClock },
			};
#if WITH_METADATA
			const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "AudioMaster.Name", "ESynchronizationType::AudioMaster" },
				{ "BlueprintType", "true" },
				{ "ExternalClock.Comment", "//\xcd\xac??????\xc6\xb5\n" },
				{ "ExternalClock.Name", "ESynchronizationType::ExternalClock" },
				{ "ExternalClock.ToolTip", "\xcd\xac??????\xc6\xb5" },
				{ "ModuleRelativePath", "Public/MediaCommon/MediaUtilityType.h" },
				{ "VideoMaster.Comment", "//\xcd\xac??????\xc6\xb5\n" },
				{ "VideoMaster.Name", "ESynchronizationType::VideoMaster" },
				{ "VideoMaster.ToolTip", "\xcd\xac??????\xc6\xb5" },
			};
#endif
			static const UECodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_MediaUtilityModule,
				nullptr,
				"ESynchronizationType",
				"ESynchronizationType",
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
	static UEnum* ETransport_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_MediaUtilityModule_ETransport, Z_Construct_UPackage__Script_MediaUtilityModule(), TEXT("ETransport"));
		}
		return Singleton;
	}
	template<> MEDIAUTILITYMODULE_API UEnum* StaticEnum<ETransport>()
	{
		return ETransport_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_ETransport(ETransport_StaticEnum, TEXT("/Script/MediaUtilityModule"), TEXT("ETransport"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_MediaUtilityModule_ETransport_Hash() { return 3501371095U; }
	UEnum* Z_Construct_UEnum_MediaUtilityModule_ETransport()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_MediaUtilityModule();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("ETransport"), 0, Get_Z_Construct_UEnum_MediaUtilityModule_ETransport_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UECodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "ETransport::Default", (int64)ETransport::Default },
				{ "ETransport::UDP", (int64)ETransport::UDP },
				{ "ETransport::UDPMULTICAST", (int64)ETransport::UDPMULTICAST },
				{ "ETransport::TCP", (int64)ETransport::TCP },
				{ "ETransport::HTTP", (int64)ETransport::HTTP },
				{ "ETransport::HTTPS", (int64)ETransport::HTTPS },
			};
#if WITH_METADATA
			const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "Default.Name", "ETransport::Default" },
				{ "HTTP.Name", "ETransport::HTTP" },
				{ "HTTPS.Name", "ETransport::HTTPS" },
				{ "ModuleRelativePath", "Public/MediaCommon/MediaUtilityType.h" },
				{ "TCP.Name", "ETransport::TCP" },
				{ "UDP.Name", "ETransport::UDP" },
				{ "UDPMULTICAST.Name", "ETransport::UDPMULTICAST" },
			};
#endif
			static const UECodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_MediaUtilityModule,
				nullptr,
				"ETransport",
				"ETransport",
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
