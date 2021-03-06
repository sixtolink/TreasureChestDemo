// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef HTTPTOOL_HttpLib_generated_h
#error "HttpLib.generated.h already included, missing '#pragma once' in HttpLib.h"
#endif
#define HTTPTOOL_HttpLib_generated_h

#define UE5Quickstart_Plugins_SCPak_Source_HttpTool_Public_HttpLib_h_15_SPARSE_DATA
#define UE5Quickstart_Plugins_SCPak_Source_HttpTool_Public_HttpLib_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execCusGetObject); \
	DECLARE_FUNCTION(execCusPutObject);


#define UE5Quickstart_Plugins_SCPak_Source_HttpTool_Public_HttpLib_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execCusGetObject); \
	DECLARE_FUNCTION(execCusPutObject);


#define UE5Quickstart_Plugins_SCPak_Source_HttpTool_Public_HttpLib_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUHttpLib(); \
	friend struct Z_Construct_UClass_UHttpLib_Statics; \
public: \
	DECLARE_CLASS(UHttpLib, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/HttpTool"), NO_API) \
	DECLARE_SERIALIZER(UHttpLib)


#define UE5Quickstart_Plugins_SCPak_Source_HttpTool_Public_HttpLib_h_15_INCLASS \
private: \
	static void StaticRegisterNativesUHttpLib(); \
	friend struct Z_Construct_UClass_UHttpLib_Statics; \
public: \
	DECLARE_CLASS(UHttpLib, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/HttpTool"), NO_API) \
	DECLARE_SERIALIZER(UHttpLib)


#define UE5Quickstart_Plugins_SCPak_Source_HttpTool_Public_HttpLib_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UHttpLib(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UHttpLib) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UHttpLib); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UHttpLib); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UHttpLib(UHttpLib&&); \
	NO_API UHttpLib(const UHttpLib&); \
public:


#define UE5Quickstart_Plugins_SCPak_Source_HttpTool_Public_HttpLib_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UHttpLib(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UHttpLib(UHttpLib&&); \
	NO_API UHttpLib(const UHttpLib&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UHttpLib); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UHttpLib); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UHttpLib)


#define UE5Quickstart_Plugins_SCPak_Source_HttpTool_Public_HttpLib_h_15_PRIVATE_PROPERTY_OFFSET
#define UE5Quickstart_Plugins_SCPak_Source_HttpTool_Public_HttpLib_h_12_PROLOG
#define UE5Quickstart_Plugins_SCPak_Source_HttpTool_Public_HttpLib_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UE5Quickstart_Plugins_SCPak_Source_HttpTool_Public_HttpLib_h_15_PRIVATE_PROPERTY_OFFSET \
	UE5Quickstart_Plugins_SCPak_Source_HttpTool_Public_HttpLib_h_15_SPARSE_DATA \
	UE5Quickstart_Plugins_SCPak_Source_HttpTool_Public_HttpLib_h_15_RPC_WRAPPERS \
	UE5Quickstart_Plugins_SCPak_Source_HttpTool_Public_HttpLib_h_15_INCLASS \
	UE5Quickstart_Plugins_SCPak_Source_HttpTool_Public_HttpLib_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define UE5Quickstart_Plugins_SCPak_Source_HttpTool_Public_HttpLib_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UE5Quickstart_Plugins_SCPak_Source_HttpTool_Public_HttpLib_h_15_PRIVATE_PROPERTY_OFFSET \
	UE5Quickstart_Plugins_SCPak_Source_HttpTool_Public_HttpLib_h_15_SPARSE_DATA \
	UE5Quickstart_Plugins_SCPak_Source_HttpTool_Public_HttpLib_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	UE5Quickstart_Plugins_SCPak_Source_HttpTool_Public_HttpLib_h_15_INCLASS_NO_PURE_DECLS \
	UE5Quickstart_Plugins_SCPak_Source_HttpTool_Public_HttpLib_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> HTTPTOOL_API UClass* StaticClass<class UHttpLib>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID UE5Quickstart_Plugins_SCPak_Source_HttpTool_Public_HttpLib_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
