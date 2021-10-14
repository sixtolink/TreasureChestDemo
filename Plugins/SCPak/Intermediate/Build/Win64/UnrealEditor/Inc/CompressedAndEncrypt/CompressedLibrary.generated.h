// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class EEncryptionMode : uint8;
#ifdef COMPRESSEDANDENCRYPT_CompressedLibrary_generated_h
#error "CompressedLibrary.generated.h already included, missing '#pragma once' in CompressedLibrary.h"
#endif
#define COMPRESSEDANDENCRYPT_CompressedLibrary_generated_h

#define TreasureChestDemo_Plugins_SCPak_Source_CompressedAndEncrypt_Public_CompressedLibrary_h_29_SPARSE_DATA
#define TreasureChestDemo_Plugins_SCPak_Source_CompressedAndEncrypt_Public_CompressedLibrary_h_29_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execDecompressedData); \
	DECLARE_FUNCTION(execCompressedData);


#define TreasureChestDemo_Plugins_SCPak_Source_CompressedAndEncrypt_Public_CompressedLibrary_h_29_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execDecompressedData); \
	DECLARE_FUNCTION(execCompressedData);


#define TreasureChestDemo_Plugins_SCPak_Source_CompressedAndEncrypt_Public_CompressedLibrary_h_29_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCompressedLibrary(); \
	friend struct Z_Construct_UClass_UCompressedLibrary_Statics; \
public: \
	DECLARE_CLASS(UCompressedLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CompressedAndEncrypt"), NO_API) \
	DECLARE_SERIALIZER(UCompressedLibrary)


#define TreasureChestDemo_Plugins_SCPak_Source_CompressedAndEncrypt_Public_CompressedLibrary_h_29_INCLASS \
private: \
	static void StaticRegisterNativesUCompressedLibrary(); \
	friend struct Z_Construct_UClass_UCompressedLibrary_Statics; \
public: \
	DECLARE_CLASS(UCompressedLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CompressedAndEncrypt"), NO_API) \
	DECLARE_SERIALIZER(UCompressedLibrary)


#define TreasureChestDemo_Plugins_SCPak_Source_CompressedAndEncrypt_Public_CompressedLibrary_h_29_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCompressedLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCompressedLibrary) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCompressedLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCompressedLibrary); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCompressedLibrary(UCompressedLibrary&&); \
	NO_API UCompressedLibrary(const UCompressedLibrary&); \
public:


#define TreasureChestDemo_Plugins_SCPak_Source_CompressedAndEncrypt_Public_CompressedLibrary_h_29_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCompressedLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCompressedLibrary(UCompressedLibrary&&); \
	NO_API UCompressedLibrary(const UCompressedLibrary&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCompressedLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCompressedLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCompressedLibrary)


#define TreasureChestDemo_Plugins_SCPak_Source_CompressedAndEncrypt_Public_CompressedLibrary_h_29_PRIVATE_PROPERTY_OFFSET
#define TreasureChestDemo_Plugins_SCPak_Source_CompressedAndEncrypt_Public_CompressedLibrary_h_26_PROLOG
#define TreasureChestDemo_Plugins_SCPak_Source_CompressedAndEncrypt_Public_CompressedLibrary_h_29_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TreasureChestDemo_Plugins_SCPak_Source_CompressedAndEncrypt_Public_CompressedLibrary_h_29_PRIVATE_PROPERTY_OFFSET \
	TreasureChestDemo_Plugins_SCPak_Source_CompressedAndEncrypt_Public_CompressedLibrary_h_29_SPARSE_DATA \
	TreasureChestDemo_Plugins_SCPak_Source_CompressedAndEncrypt_Public_CompressedLibrary_h_29_RPC_WRAPPERS \
	TreasureChestDemo_Plugins_SCPak_Source_CompressedAndEncrypt_Public_CompressedLibrary_h_29_INCLASS \
	TreasureChestDemo_Plugins_SCPak_Source_CompressedAndEncrypt_Public_CompressedLibrary_h_29_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TreasureChestDemo_Plugins_SCPak_Source_CompressedAndEncrypt_Public_CompressedLibrary_h_29_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TreasureChestDemo_Plugins_SCPak_Source_CompressedAndEncrypt_Public_CompressedLibrary_h_29_PRIVATE_PROPERTY_OFFSET \
	TreasureChestDemo_Plugins_SCPak_Source_CompressedAndEncrypt_Public_CompressedLibrary_h_29_SPARSE_DATA \
	TreasureChestDemo_Plugins_SCPak_Source_CompressedAndEncrypt_Public_CompressedLibrary_h_29_RPC_WRAPPERS_NO_PURE_DECLS \
	TreasureChestDemo_Plugins_SCPak_Source_CompressedAndEncrypt_Public_CompressedLibrary_h_29_INCLASS_NO_PURE_DECLS \
	TreasureChestDemo_Plugins_SCPak_Source_CompressedAndEncrypt_Public_CompressedLibrary_h_29_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class CompressedLibrary."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> COMPRESSEDANDENCRYPT_API UClass* StaticClass<class UCompressedLibrary>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TreasureChestDemo_Plugins_SCPak_Source_CompressedAndEncrypt_Public_CompressedLibrary_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
