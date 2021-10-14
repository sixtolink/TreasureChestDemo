// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MediaUtilityModule/Public/MediaSetting/FFMPEGMediaSetting.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFFMPEGMediaSetting() {}
// Cross Module References
	MEDIAUTILITYMODULE_API UClass* Z_Construct_UClass_UFFMPEGMediaSetting_NoRegister();
	MEDIAUTILITYMODULE_API UClass* Z_Construct_UClass_UFFMPEGMediaSetting();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_MediaUtilityModule();
	MEDIAUTILITYMODULE_API UEnum* Z_Construct_UEnum_MediaUtilityModule_ETransport();
	MEDIAUTILITYMODULE_API UEnum* Z_Construct_UEnum_MediaUtilityModule_ESynchronizationType();
// End Cross Module References
	void UFFMPEGMediaSetting::StaticRegisterNativesUFFMPEGMediaSetting()
	{
	}
	UClass* Z_Construct_UClass_UFFMPEGMediaSetting_NoRegister()
	{
		return UFFMPEGMediaSetting::StaticClass();
	}
	struct Z_Construct_UClass_UFFMPEGMediaSetting_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bUseInfiniteBuffer_MetaData[];
#endif
		static void NewProp_bUseInfiniteBuffer_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseInfiniteBuffer;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bAllowFrameDrop_MetaData[];
#endif
		static void NewProp_bAllowFrameDrop_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bAllowFrameDrop;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bUseHardwareAcceleratedCodecs_MetaData[];
#endif
		static void NewProp_bUseHardwareAcceleratedCodecs_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseHardwareAcceleratedCodecs;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bDisableAudio_MetaData[];
#endif
		static void NewProp_bDisableAudio_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bDisableAudio;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bZeroLatencyStreaming_MetaData[];
#endif
		static void NewProp_bZeroLatencyStreaming_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bZeroLatencyStreaming;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bSpeedUpTricks_MetaData[];
#endif
		static void NewProp_bSpeedUpTricks_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bSpeedUpTricks;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AudioThreads_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_AudioThreads;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_VideoThreads_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_VideoThreads;
		static const UECodeGen_Private::FBytePropertyParams NewProp_RTSPTransport_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RTSPTransport_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_RTSPTransport;
		static const UECodeGen_Private::FBytePropertyParams NewProp_SyncType_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SyncType_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_SyncType;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UFFMPEGMediaSetting_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_MediaUtilityModule,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFFMPEGMediaSetting_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "MediaSetting/FFMPEGMediaSetting.h" },
		{ "ModuleRelativePath", "Public/MediaSetting/FFMPEGMediaSetting.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFFMPEGMediaSetting_Statics::NewProp_bUseInfiniteBuffer_MetaData[] = {
		{ "Category", "FFMPEGMedia" },
		{ "Comment", "//?\xc7\xb7?\xca\xb9?????\xde\xbb???\n" },
		{ "ModuleRelativePath", "Public/MediaSetting/FFMPEGMediaSetting.h" },
		{ "ToolTip", "?\xc7\xb7?\xca\xb9?????\xde\xbb???" },
	};
#endif
	void Z_Construct_UClass_UFFMPEGMediaSetting_Statics::NewProp_bUseInfiniteBuffer_SetBit(void* Obj)
	{
		((UFFMPEGMediaSetting*)Obj)->bUseInfiniteBuffer = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UFFMPEGMediaSetting_Statics::NewProp_bUseInfiniteBuffer = { "bUseInfiniteBuffer", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UFFMPEGMediaSetting), &Z_Construct_UClass_UFFMPEGMediaSetting_Statics::NewProp_bUseInfiniteBuffer_SetBit, METADATA_PARAMS(Z_Construct_UClass_UFFMPEGMediaSetting_Statics::NewProp_bUseInfiniteBuffer_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UFFMPEGMediaSetting_Statics::NewProp_bUseInfiniteBuffer_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFFMPEGMediaSetting_Statics::NewProp_bAllowFrameDrop_MetaData[] = {
		{ "Category", "FFMPEGMedia" },
		{ "Comment", "//?\xc7\xb7?????\xd6\xa1?\xc2\xbd?\n" },
		{ "ModuleRelativePath", "Public/MediaSetting/FFMPEGMediaSetting.h" },
		{ "ToolTip", "?\xc7\xb7?????\xd6\xa1?\xc2\xbd?" },
	};
#endif
	void Z_Construct_UClass_UFFMPEGMediaSetting_Statics::NewProp_bAllowFrameDrop_SetBit(void* Obj)
	{
		((UFFMPEGMediaSetting*)Obj)->bAllowFrameDrop = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UFFMPEGMediaSetting_Statics::NewProp_bAllowFrameDrop = { "bAllowFrameDrop", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UFFMPEGMediaSetting), &Z_Construct_UClass_UFFMPEGMediaSetting_Statics::NewProp_bAllowFrameDrop_SetBit, METADATA_PARAMS(Z_Construct_UClass_UFFMPEGMediaSetting_Statics::NewProp_bAllowFrameDrop_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UFFMPEGMediaSetting_Statics::NewProp_bAllowFrameDrop_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFFMPEGMediaSetting_Statics::NewProp_bUseHardwareAcceleratedCodecs_MetaData[] = {
		{ "Category", "FFMPEGMedia" },
		{ "Comment", "//?\xc7\xb7?\xca\xb9??\xd3\xb2?????\xeb\xa3\xa8GPU\n" },
		{ "ModuleRelativePath", "Public/MediaSetting/FFMPEGMediaSetting.h" },
		{ "ToolTip", "?\xc7\xb7?\xca\xb9??\xd3\xb2?????\xeb\xa3\xa8GPU" },
	};
#endif
	void Z_Construct_UClass_UFFMPEGMediaSetting_Statics::NewProp_bUseHardwareAcceleratedCodecs_SetBit(void* Obj)
	{
		((UFFMPEGMediaSetting*)Obj)->bUseHardwareAcceleratedCodecs = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UFFMPEGMediaSetting_Statics::NewProp_bUseHardwareAcceleratedCodecs = { "bUseHardwareAcceleratedCodecs", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UFFMPEGMediaSetting), &Z_Construct_UClass_UFFMPEGMediaSetting_Statics::NewProp_bUseHardwareAcceleratedCodecs_SetBit, METADATA_PARAMS(Z_Construct_UClass_UFFMPEGMediaSetting_Statics::NewProp_bUseHardwareAcceleratedCodecs_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UFFMPEGMediaSetting_Statics::NewProp_bUseHardwareAcceleratedCodecs_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFFMPEGMediaSetting_Statics::NewProp_bDisableAudio_MetaData[] = {
		{ "Category", "FFMPEGMedia" },
		{ "Comment", "//?\xc7\xb7???????\xc6\xb5\n" },
		{ "ModuleRelativePath", "Public/MediaSetting/FFMPEGMediaSetting.h" },
		{ "ToolTip", "?\xc7\xb7???????\xc6\xb5" },
	};
#endif
	void Z_Construct_UClass_UFFMPEGMediaSetting_Statics::NewProp_bDisableAudio_SetBit(void* Obj)
	{
		((UFFMPEGMediaSetting*)Obj)->bDisableAudio = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UFFMPEGMediaSetting_Statics::NewProp_bDisableAudio = { "bDisableAudio", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UFFMPEGMediaSetting), &Z_Construct_UClass_UFFMPEGMediaSetting_Statics::NewProp_bDisableAudio_SetBit, METADATA_PARAMS(Z_Construct_UClass_UFFMPEGMediaSetting_Statics::NewProp_bDisableAudio_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UFFMPEGMediaSetting_Statics::NewProp_bDisableAudio_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFFMPEGMediaSetting_Statics::NewProp_bZeroLatencyStreaming_MetaData[] = {
		{ "Category", "FFMPEGMedia" },
		{ "Comment", "//?\xc7\xb7????\xd3\xb3?\n" },
		{ "ModuleRelativePath", "Public/MediaSetting/FFMPEGMediaSetting.h" },
		{ "ToolTip", "?\xc7\xb7????\xd3\xb3?" },
	};
#endif
	void Z_Construct_UClass_UFFMPEGMediaSetting_Statics::NewProp_bZeroLatencyStreaming_SetBit(void* Obj)
	{
		((UFFMPEGMediaSetting*)Obj)->bZeroLatencyStreaming = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UFFMPEGMediaSetting_Statics::NewProp_bZeroLatencyStreaming = { "bZeroLatencyStreaming", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UFFMPEGMediaSetting), &Z_Construct_UClass_UFFMPEGMediaSetting_Statics::NewProp_bZeroLatencyStreaming_SetBit, METADATA_PARAMS(Z_Construct_UClass_UFFMPEGMediaSetting_Statics::NewProp_bZeroLatencyStreaming_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UFFMPEGMediaSetting_Statics::NewProp_bZeroLatencyStreaming_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFFMPEGMediaSetting_Statics::NewProp_bSpeedUpTricks_MetaData[] = {
		{ "Category", "FFMPEGMedia" },
		{ "Comment", "//?\xc7\xb7??????\xc7\xb9\xe6\xb7\xb6????\n" },
		{ "ModuleRelativePath", "Public/MediaSetting/FFMPEGMediaSetting.h" },
		{ "ToolTip", "?\xc7\xb7??????\xc7\xb9\xe6\xb7\xb6????" },
	};
#endif
	void Z_Construct_UClass_UFFMPEGMediaSetting_Statics::NewProp_bSpeedUpTricks_SetBit(void* Obj)
	{
		((UFFMPEGMediaSetting*)Obj)->bSpeedUpTricks = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UFFMPEGMediaSetting_Statics::NewProp_bSpeedUpTricks = { "bSpeedUpTricks", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UFFMPEGMediaSetting), &Z_Construct_UClass_UFFMPEGMediaSetting_Statics::NewProp_bSpeedUpTricks_SetBit, METADATA_PARAMS(Z_Construct_UClass_UFFMPEGMediaSetting_Statics::NewProp_bSpeedUpTricks_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UFFMPEGMediaSetting_Statics::NewProp_bSpeedUpTricks_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFFMPEGMediaSetting_Statics::NewProp_AudioThreads_MetaData[] = {
		{ "Category", "FFMPEGMedia" },
		{ "Comment", "//??\xc6\xb5?????\xdf\xb3?\n" },
		{ "ModuleRelativePath", "Public/MediaSetting/FFMPEGMediaSetting.h" },
		{ "ToolTip", "??\xc6\xb5?????\xdf\xb3?" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UFFMPEGMediaSetting_Statics::NewProp_AudioThreads = { "AudioThreads", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UFFMPEGMediaSetting, AudioThreads), METADATA_PARAMS(Z_Construct_UClass_UFFMPEGMediaSetting_Statics::NewProp_AudioThreads_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UFFMPEGMediaSetting_Statics::NewProp_AudioThreads_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFFMPEGMediaSetting_Statics::NewProp_VideoThreads_MetaData[] = {
		{ "Category", "FFMPEGMedia" },
		{ "Comment", "//??\xc6\xb5?????\xdf\xb3?\n" },
		{ "ModuleRelativePath", "Public/MediaSetting/FFMPEGMediaSetting.h" },
		{ "ToolTip", "??\xc6\xb5?????\xdf\xb3?" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UFFMPEGMediaSetting_Statics::NewProp_VideoThreads = { "VideoThreads", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UFFMPEGMediaSetting, VideoThreads), METADATA_PARAMS(Z_Construct_UClass_UFFMPEGMediaSetting_Statics::NewProp_VideoThreads_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UFFMPEGMediaSetting_Statics::NewProp_VideoThreads_MetaData)) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UFFMPEGMediaSetting_Statics::NewProp_RTSPTransport_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFFMPEGMediaSetting_Statics::NewProp_RTSPTransport_MetaData[] = {
		{ "Category", "FFMPEGMedia" },
		{ "Comment", "//\xc3\xbd????\xd0\xad??????\n" },
		{ "ModuleRelativePath", "Public/MediaSetting/FFMPEGMediaSetting.h" },
		{ "ToolTip", "\xc3\xbd????\xd0\xad??????" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UFFMPEGMediaSetting_Statics::NewProp_RTSPTransport = { "RTSPTransport", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UFFMPEGMediaSetting, RTSPTransport), Z_Construct_UEnum_MediaUtilityModule_ETransport, METADATA_PARAMS(Z_Construct_UClass_UFFMPEGMediaSetting_Statics::NewProp_RTSPTransport_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UFFMPEGMediaSetting_Statics::NewProp_RTSPTransport_MetaData)) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UFFMPEGMediaSetting_Statics::NewProp_SyncType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFFMPEGMediaSetting_Statics::NewProp_SyncType_MetaData[] = {
		{ "Category", "FFMPEGMedia" },
		{ "Comment", "//\xcd\xac??????\n" },
		{ "ModuleRelativePath", "Public/MediaSetting/FFMPEGMediaSetting.h" },
		{ "ToolTip", "\xcd\xac??????" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UFFMPEGMediaSetting_Statics::NewProp_SyncType = { "SyncType", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UFFMPEGMediaSetting, SyncType), Z_Construct_UEnum_MediaUtilityModule_ESynchronizationType, METADATA_PARAMS(Z_Construct_UClass_UFFMPEGMediaSetting_Statics::NewProp_SyncType_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UFFMPEGMediaSetting_Statics::NewProp_SyncType_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UFFMPEGMediaSetting_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFFMPEGMediaSetting_Statics::NewProp_bUseInfiniteBuffer,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFFMPEGMediaSetting_Statics::NewProp_bAllowFrameDrop,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFFMPEGMediaSetting_Statics::NewProp_bUseHardwareAcceleratedCodecs,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFFMPEGMediaSetting_Statics::NewProp_bDisableAudio,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFFMPEGMediaSetting_Statics::NewProp_bZeroLatencyStreaming,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFFMPEGMediaSetting_Statics::NewProp_bSpeedUpTricks,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFFMPEGMediaSetting_Statics::NewProp_AudioThreads,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFFMPEGMediaSetting_Statics::NewProp_VideoThreads,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFFMPEGMediaSetting_Statics::NewProp_RTSPTransport_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFFMPEGMediaSetting_Statics::NewProp_RTSPTransport,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFFMPEGMediaSetting_Statics::NewProp_SyncType_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFFMPEGMediaSetting_Statics::NewProp_SyncType,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UFFMPEGMediaSetting_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UFFMPEGMediaSetting>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UFFMPEGMediaSetting_Statics::ClassParams = {
		&UFFMPEGMediaSetting::StaticClass,
		"FFMPEGMedia",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UFFMPEGMediaSetting_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UFFMPEGMediaSetting_Statics::PropPointers),
		0,
		0x001000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UFFMPEGMediaSetting_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UFFMPEGMediaSetting_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UFFMPEGMediaSetting()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UECodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UFFMPEGMediaSetting_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UFFMPEGMediaSetting, 1373441341);
	template<> MEDIAUTILITYMODULE_API UClass* StaticClass<UFFMPEGMediaSetting>()
	{
		return UFFMPEGMediaSetting::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UFFMPEGMediaSetting(Z_Construct_UClass_UFFMPEGMediaSetting, &UFFMPEGMediaSetting::StaticClass, TEXT("/Script/MediaUtilityModule"), TEXT("UFFMPEGMediaSetting"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UFFMPEGMediaSetting);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
