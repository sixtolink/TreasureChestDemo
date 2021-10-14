// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CompressedAndEncrypt/Public/CompressedLibrary.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCompressedLibrary() {}
// Cross Module References
	COMPRESSEDANDENCRYPT_API UClass* Z_Construct_UClass_UCompressedLibrary_NoRegister();
	COMPRESSEDANDENCRYPT_API UClass* Z_Construct_UClass_UCompressedLibrary();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_CompressedAndEncrypt();
	COMPRESSEDANDENCRYPT_API UEnum* Z_Construct_UEnum_CompressedAndEncrypt_EEncryptionMode();
// End Cross Module References
	DEFINE_FUNCTION(UCompressedLibrary::execDecompressedData)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_Paths);
		P_GET_PROPERTY(FStrProperty,Z_Param_SavePaths);
		P_GET_ENUM(EEncryptionMode,Z_Param_EncryptionMode);
		P_GET_PROPERTY(FStrProperty,Z_Param_Keys);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UCompressedLibrary::DecompressedData(Z_Param_Paths,Z_Param_SavePaths,EEncryptionMode(Z_Param_EncryptionMode),Z_Param_Keys);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCompressedLibrary::execCompressedData)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_ReadPaths);
		P_GET_PROPERTY(FStrProperty,Z_Param_SavePaths);
		P_GET_PROPERTY(FStrProperty,Z_Param_BaseURL);
		P_GET_PROPERTY(FInt64Property,Z_Param_FragmentSize);
		P_GET_ENUM(EEncryptionMode,Z_Param_EncryptionMode);
		P_GET_PROPERTY(FStrProperty,Z_Param_Keys);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UCompressedLibrary::CompressedData(Z_Param_ReadPaths,Z_Param_SavePaths,Z_Param_BaseURL,Z_Param_FragmentSize,EEncryptionMode(Z_Param_EncryptionMode),Z_Param_Keys);
		P_NATIVE_END;
	}
	void UCompressedLibrary::StaticRegisterNativesUCompressedLibrary()
	{
		UClass* Class = UCompressedLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CompressedData", &UCompressedLibrary::execCompressedData },
			{ "DecompressedData", &UCompressedLibrary::execDecompressedData },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UCompressedLibrary_CompressedData_Statics
	{
		struct CompressedLibrary_eventCompressedData_Parms
		{
			FString ReadPaths;
			FString SavePaths;
			FString BaseURL;
			int64 FragmentSize;
			EEncryptionMode EncryptionMode;
			FString Keys;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReadPaths;
		static const UECodeGen_Private::FStrPropertyParams NewProp_SavePaths;
		static const UECodeGen_Private::FStrPropertyParams NewProp_BaseURL;
		static const UECodeGen_Private::FInt64PropertyParams NewProp_FragmentSize;
		static const UECodeGen_Private::FBytePropertyParams NewProp_EncryptionMode_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_EncryptionMode;
		static const UECodeGen_Private::FStrPropertyParams NewProp_Keys;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UCompressedLibrary_CompressedData_Statics::NewProp_ReadPaths = { "ReadPaths", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CompressedLibrary_eventCompressedData_Parms, ReadPaths), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UCompressedLibrary_CompressedData_Statics::NewProp_SavePaths = { "SavePaths", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CompressedLibrary_eventCompressedData_Parms, SavePaths), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UCompressedLibrary_CompressedData_Statics::NewProp_BaseURL = { "BaseURL", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CompressedLibrary_eventCompressedData_Parms, BaseURL), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FInt64PropertyParams Z_Construct_UFunction_UCompressedLibrary_CompressedData_Statics::NewProp_FragmentSize = { "FragmentSize", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CompressedLibrary_eventCompressedData_Parms, FragmentSize), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UCompressedLibrary_CompressedData_Statics::NewProp_EncryptionMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UCompressedLibrary_CompressedData_Statics::NewProp_EncryptionMode = { "EncryptionMode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CompressedLibrary_eventCompressedData_Parms, EncryptionMode), Z_Construct_UEnum_CompressedAndEncrypt_EEncryptionMode, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UCompressedLibrary_CompressedData_Statics::NewProp_Keys = { "Keys", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CompressedLibrary_eventCompressedData_Parms, Keys), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UCompressedLibrary_CompressedData_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((CompressedLibrary_eventCompressedData_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCompressedLibrary_CompressedData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(CompressedLibrary_eventCompressedData_Parms), &Z_Construct_UFunction_UCompressedLibrary_CompressedData_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCompressedLibrary_CompressedData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCompressedLibrary_CompressedData_Statics::NewProp_ReadPaths,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCompressedLibrary_CompressedData_Statics::NewProp_SavePaths,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCompressedLibrary_CompressedData_Statics::NewProp_BaseURL,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCompressedLibrary_CompressedData_Statics::NewProp_FragmentSize,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCompressedLibrary_CompressedData_Statics::NewProp_EncryptionMode_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCompressedLibrary_CompressedData_Statics::NewProp_EncryptionMode,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCompressedLibrary_CompressedData_Statics::NewProp_Keys,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCompressedLibrary_CompressedData_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCompressedLibrary_CompressedData_Statics::Function_MetaDataParams[] = {
		{ "Category", "CompressedAndEncrypt" },
		{ "CPP_Default_BaseURL", "" },
		{ "CPP_Default_EncryptionMode", "NONE" },
		{ "CPP_Default_FragmentSize", "31457280" },
		{ "CPP_Default_Keys", "" },
		{ "DisplayName", "Compressed Data" },
		{ "ModuleRelativePath", "Public/CompressedLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCompressedLibrary_CompressedData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCompressedLibrary, nullptr, "CompressedData", nullptr, nullptr, sizeof(CompressedLibrary_eventCompressedData_Parms), Z_Construct_UFunction_UCompressedLibrary_CompressedData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCompressedLibrary_CompressedData_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCompressedLibrary_CompressedData_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCompressedLibrary_CompressedData_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCompressedLibrary_CompressedData()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UCompressedLibrary_CompressedData_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCompressedLibrary_DecompressedData_Statics
	{
		struct CompressedLibrary_eventDecompressedData_Parms
		{
			FString Paths;
			FString SavePaths;
			EEncryptionMode EncryptionMode;
			FString Keys;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_Paths;
		static const UECodeGen_Private::FStrPropertyParams NewProp_SavePaths;
		static const UECodeGen_Private::FBytePropertyParams NewProp_EncryptionMode_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_EncryptionMode;
		static const UECodeGen_Private::FStrPropertyParams NewProp_Keys;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UCompressedLibrary_DecompressedData_Statics::NewProp_Paths = { "Paths", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CompressedLibrary_eventDecompressedData_Parms, Paths), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UCompressedLibrary_DecompressedData_Statics::NewProp_SavePaths = { "SavePaths", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CompressedLibrary_eventDecompressedData_Parms, SavePaths), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UCompressedLibrary_DecompressedData_Statics::NewProp_EncryptionMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UCompressedLibrary_DecompressedData_Statics::NewProp_EncryptionMode = { "EncryptionMode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CompressedLibrary_eventDecompressedData_Parms, EncryptionMode), Z_Construct_UEnum_CompressedAndEncrypt_EEncryptionMode, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UCompressedLibrary_DecompressedData_Statics::NewProp_Keys = { "Keys", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CompressedLibrary_eventDecompressedData_Parms, Keys), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UCompressedLibrary_DecompressedData_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((CompressedLibrary_eventDecompressedData_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCompressedLibrary_DecompressedData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(CompressedLibrary_eventDecompressedData_Parms), &Z_Construct_UFunction_UCompressedLibrary_DecompressedData_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCompressedLibrary_DecompressedData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCompressedLibrary_DecompressedData_Statics::NewProp_Paths,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCompressedLibrary_DecompressedData_Statics::NewProp_SavePaths,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCompressedLibrary_DecompressedData_Statics::NewProp_EncryptionMode_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCompressedLibrary_DecompressedData_Statics::NewProp_EncryptionMode,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCompressedLibrary_DecompressedData_Statics::NewProp_Keys,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCompressedLibrary_DecompressedData_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCompressedLibrary_DecompressedData_Statics::Function_MetaDataParams[] = {
		{ "Category", "CompressedAndEncrypt" },
		{ "CPP_Default_EncryptionMode", "NONE" },
		{ "CPP_Default_Keys", "" },
		{ "DisplayName", "Decompressed Data" },
		{ "ModuleRelativePath", "Public/CompressedLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCompressedLibrary_DecompressedData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCompressedLibrary, nullptr, "DecompressedData", nullptr, nullptr, sizeof(CompressedLibrary_eventDecompressedData_Parms), Z_Construct_UFunction_UCompressedLibrary_DecompressedData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCompressedLibrary_DecompressedData_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCompressedLibrary_DecompressedData_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCompressedLibrary_DecompressedData_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCompressedLibrary_DecompressedData()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UCompressedLibrary_DecompressedData_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UCompressedLibrary_NoRegister()
	{
		return UCompressedLibrary::StaticClass();
	}
	struct Z_Construct_UClass_UCompressedLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCompressedLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_CompressedAndEncrypt,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UCompressedLibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UCompressedLibrary_CompressedData, "CompressedData" }, // 2238086271
		{ &Z_Construct_UFunction_UCompressedLibrary_DecompressedData, "DecompressedData" }, // 1502815145
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCompressedLibrary_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/* \n*\x09""Function library class.\n*\x09""Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.\n*\n*\x09When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.\n*\x09""BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.\n*\x09""BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.\n*\x09""DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.\n*\x09\x09\x09\x09Its lets you name the node using characters not allowed in C++ function names.\n*\x09""CompactNodeTitle - the word(s) that appear on the node.\n*\x09Keywords -\x09the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu. \n*\x09\x09\x09\x09Good example is \"Print String\" node which you can find also by using keyword \"log\".\n*\x09""Category -\x09the category your node will be under in the Blueprint drop-down menu.\n*\n*\x09""For more info on custom blueprint nodes visit documentation:\n*\x09https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation\n*/" },
		{ "IncludePath", "CompressedLibrary.h" },
		{ "ModuleRelativePath", "Public/CompressedLibrary.h" },
		{ "ToolTip", "*      Function library class.\n*      Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.\n*\n*      When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.\n*      BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.\n*      BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.\n*      DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.\n*                              Its lets you name the node using characters not allowed in C++ function names.\n*      CompactNodeTitle - the word(s) that appear on the node.\n*      Keywords -      the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu.\n*                              Good example is \"Print String\" node which you can find also by using keyword \"log\".\n*      Category -      the category your node will be under in the Blueprint drop-down menu.\n*\n*      For more info on custom blueprint nodes visit documentation:\n*      https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UCompressedLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCompressedLibrary>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UCompressedLibrary_Statics::ClassParams = {
		&UCompressedLibrary::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UCompressedLibrary_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UCompressedLibrary_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UCompressedLibrary()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UECodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UCompressedLibrary_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UCompressedLibrary, 257394670);
	template<> COMPRESSEDANDENCRYPT_API UClass* StaticClass<UCompressedLibrary>()
	{
		return UCompressedLibrary::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UCompressedLibrary(Z_Construct_UClass_UCompressedLibrary, &UCompressedLibrary::StaticClass, TEXT("/Script/CompressedAndEncrypt"), TEXT("UCompressedLibrary"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCompressedLibrary);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
