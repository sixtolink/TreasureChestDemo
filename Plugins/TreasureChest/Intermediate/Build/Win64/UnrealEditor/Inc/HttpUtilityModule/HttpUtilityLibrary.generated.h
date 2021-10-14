// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class ERequestVerb : uint8;
enum class ERequestContentType : uint8;
 
class UHttpUtilityLibrary;
#ifdef HTTPUTILITYMODULE_HttpUtilityLibrary_generated_h
#error "HttpUtilityLibrary.generated.h already included, missing '#pragma once' in HttpUtilityLibrary.h"
#endif
#define HTTPUTILITYMODULE_HttpUtilityLibrary_generated_h

#define TreasureChestDemo_Plugins_TreasureChest_Source_HttpUtilityModule_Public_BlueprintLibrary_HttpUtilityLibrary_h_13_DELEGATE \
struct _Script_HttpUtilityModule_eventHttpRequestSuccessDelegate_Parms \
{ \
	FString Msg; \
}; \
static inline void FHttpRequestSuccessDelegate_DelegateWrapper(const FMulticastScriptDelegate& HttpRequestSuccessDelegate, const FString& Msg) \
{ \
	_Script_HttpUtilityModule_eventHttpRequestSuccessDelegate_Parms Parms; \
	Parms.Msg=Msg; \
	HttpRequestSuccessDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define TreasureChestDemo_Plugins_TreasureChest_Source_HttpUtilityModule_Public_BlueprintLibrary_HttpUtilityLibrary_h_18_SPARSE_DATA
#define TreasureChestDemo_Plugins_TreasureChest_Source_HttpUtilityModule_Public_BlueprintLibrary_HttpUtilityLibrary_h_18_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execMyHttpProgress);


#define TreasureChestDemo_Plugins_TreasureChest_Source_HttpUtilityModule_Public_BlueprintLibrary_HttpUtilityLibrary_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execMyHttpProgress);


#define TreasureChestDemo_Plugins_TreasureChest_Source_HttpUtilityModule_Public_BlueprintLibrary_HttpUtilityLibrary_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUHttpUtilityLibrary(); \
	friend struct Z_Construct_UClass_UHttpUtilityLibrary_Statics; \
public: \
	DECLARE_CLASS(UHttpUtilityLibrary, UBlueprintAsyncActionBase, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/HttpUtilityModule"), NO_API) \
	DECLARE_SERIALIZER(UHttpUtilityLibrary)


#define TreasureChestDemo_Plugins_TreasureChest_Source_HttpUtilityModule_Public_BlueprintLibrary_HttpUtilityLibrary_h_18_INCLASS \
private: \
	static void StaticRegisterNativesUHttpUtilityLibrary(); \
	friend struct Z_Construct_UClass_UHttpUtilityLibrary_Statics; \
public: \
	DECLARE_CLASS(UHttpUtilityLibrary, UBlueprintAsyncActionBase, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/HttpUtilityModule"), NO_API) \
	DECLARE_SERIALIZER(UHttpUtilityLibrary)


#define TreasureChestDemo_Plugins_TreasureChest_Source_HttpUtilityModule_Public_BlueprintLibrary_HttpUtilityLibrary_h_18_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UHttpUtilityLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UHttpUtilityLibrary) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UHttpUtilityLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UHttpUtilityLibrary); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UHttpUtilityLibrary(UHttpUtilityLibrary&&); \
	NO_API UHttpUtilityLibrary(const UHttpUtilityLibrary&); \
public:


#define TreasureChestDemo_Plugins_TreasureChest_Source_HttpUtilityModule_Public_BlueprintLibrary_HttpUtilityLibrary_h_18_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UHttpUtilityLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UHttpUtilityLibrary(UHttpUtilityLibrary&&); \
	NO_API UHttpUtilityLibrary(const UHttpUtilityLibrary&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UHttpUtilityLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UHttpUtilityLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UHttpUtilityLibrary)


#define TreasureChestDemo_Plugins_TreasureChest_Source_HttpUtilityModule_Public_BlueprintLibrary_HttpUtilityLibrary_h_18_PRIVATE_PROPERTY_OFFSET
#define TreasureChestDemo_Plugins_TreasureChest_Source_HttpUtilityModule_Public_BlueprintLibrary_HttpUtilityLibrary_h_15_PROLOG
#define TreasureChestDemo_Plugins_TreasureChest_Source_HttpUtilityModule_Public_BlueprintLibrary_HttpUtilityLibrary_h_18_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TreasureChestDemo_Plugins_TreasureChest_Source_HttpUtilityModule_Public_BlueprintLibrary_HttpUtilityLibrary_h_18_PRIVATE_PROPERTY_OFFSET \
	TreasureChestDemo_Plugins_TreasureChest_Source_HttpUtilityModule_Public_BlueprintLibrary_HttpUtilityLibrary_h_18_SPARSE_DATA \
	TreasureChestDemo_Plugins_TreasureChest_Source_HttpUtilityModule_Public_BlueprintLibrary_HttpUtilityLibrary_h_18_RPC_WRAPPERS \
	TreasureChestDemo_Plugins_TreasureChest_Source_HttpUtilityModule_Public_BlueprintLibrary_HttpUtilityLibrary_h_18_INCLASS \
	TreasureChestDemo_Plugins_TreasureChest_Source_HttpUtilityModule_Public_BlueprintLibrary_HttpUtilityLibrary_h_18_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TreasureChestDemo_Plugins_TreasureChest_Source_HttpUtilityModule_Public_BlueprintLibrary_HttpUtilityLibrary_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TreasureChestDemo_Plugins_TreasureChest_Source_HttpUtilityModule_Public_BlueprintLibrary_HttpUtilityLibrary_h_18_PRIVATE_PROPERTY_OFFSET \
	TreasureChestDemo_Plugins_TreasureChest_Source_HttpUtilityModule_Public_BlueprintLibrary_HttpUtilityLibrary_h_18_SPARSE_DATA \
	TreasureChestDemo_Plugins_TreasureChest_Source_HttpUtilityModule_Public_BlueprintLibrary_HttpUtilityLibrary_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	TreasureChestDemo_Plugins_TreasureChest_Source_HttpUtilityModule_Public_BlueprintLibrary_HttpUtilityLibrary_h_18_INCLASS_NO_PURE_DECLS \
	TreasureChestDemo_Plugins_TreasureChest_Source_HttpUtilityModule_Public_BlueprintLibrary_HttpUtilityLibrary_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> HTTPUTILITYMODULE_API UClass* StaticClass<class UHttpUtilityLibrary>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TreasureChestDemo_Plugins_TreasureChest_Source_HttpUtilityModule_Public_BlueprintLibrary_HttpUtilityLibrary_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
