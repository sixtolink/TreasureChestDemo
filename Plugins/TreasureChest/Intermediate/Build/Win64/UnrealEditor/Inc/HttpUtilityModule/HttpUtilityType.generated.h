// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef HTTPUTILITYMODULE_HttpUtilityType_generated_h
#error "HttpUtilityType.generated.h already included, missing '#pragma once' in HttpUtilityType.h"
#endif
#define HTTPUTILITYMODULE_HttpUtilityType_generated_h

#define TreasureChestDemo_Plugins_TreasureChest_Source_HttpUtilityModule_Public_HttpCommon_HttpUtilityType_h_24_DELEGATE \
static inline void FReceivedDelegate_DelegateWrapper(const FScriptDelegate& ReceivedDelegate) \
{ \
	ReceivedDelegate.ProcessDelegate<UObject>(NULL); \
}


#define TreasureChestDemo_Plugins_TreasureChest_Source_HttpUtilityModule_Public_HttpCommon_HttpUtilityType_h_23_DELEGATE \
struct _Script_HttpUtilityModule_eventProgressDelegate_Parms \
{ \
	int32 InSent; \
	int32 InRece; \
}; \
static inline void FProgressDelegate_DelegateWrapper(const FScriptDelegate& ProgressDelegate, int32 InSent, int32 InRece) \
{ \
	_Script_HttpUtilityModule_eventProgressDelegate_Parms Parms; \
	Parms.InSent=InSent; \
	Parms.InRece=InRece; \
	ProgressDelegate.ProcessDelegate<UObject>(&Parms); \
}


#define TreasureChestDemo_Plugins_TreasureChest_Source_HttpUtilityModule_Public_HttpCommon_HttpUtilityType_h_22_DELEGATE \
struct _Script_HttpUtilityModule_eventCompleteDelegate_Parms \
{ \
	FString Content; \
}; \
static inline void FCompleteDelegate_DelegateWrapper(const FScriptDelegate& CompleteDelegate, const FString& Content) \
{ \
	_Script_HttpUtilityModule_eventCompleteDelegate_Parms Parms; \
	Parms.Content=Content; \
	CompleteDelegate.ProcessDelegate<UObject>(&Parms); \
}


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TreasureChestDemo_Plugins_TreasureChest_Source_HttpUtilityModule_Public_HttpCommon_HttpUtilityType_h


#define FOREACH_ENUM_EREQUESTCONTENTTYPE(op) \
	op(ERequestContentType::NORMAL) \
	op(ERequestContentType::JSON) 

enum class ERequestContentType : uint8;
template<> HTTPUTILITYMODULE_API UEnum* StaticEnum<ERequestContentType>();

#define FOREACH_ENUM_EREQUESTVERB(op) \
	op(ERequestVerb::GET) \
	op(ERequestVerb::PUT) \
	op(ERequestVerb::POST) \
	op(ERequestVerb::DELETE) 

enum class ERequestVerb : uint8;
template<> HTTPUTILITYMODULE_API UEnum* StaticEnum<ERequestVerb>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
