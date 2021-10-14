// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef MEDIAUTILITYMODULE_MediaUtilityType_generated_h
#error "MediaUtilityType.generated.h already included, missing '#pragma once' in MediaUtilityType.h"
#endif
#define MEDIAUTILITYMODULE_MediaUtilityType_generated_h

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID UE5Quickstart_Plugins_TreasureChest_Source_MediaUtilityModule_Public_MediaCommon_MediaUtilityType_h


#define FOREACH_ENUM_ESYNCHRONIZATIONTYPE(op) \
	op(ESynchronizationType::AudioMaster) \
	op(ESynchronizationType::VideoMaster) \
	op(ESynchronizationType::ExternalClock) 

enum class ESynchronizationType : uint8;
template<> MEDIAUTILITYMODULE_API UEnum* StaticEnum<ESynchronizationType>();

#define FOREACH_ENUM_ETRANSPORT(op) \
	op(ETransport::Default) \
	op(ETransport::UDP) \
	op(ETransport::UDPMULTICAST) \
	op(ETransport::TCP) \
	op(ETransport::HTTP) \
	op(ETransport::HTTPS) 

enum class ETransport : uint8;
template<> MEDIAUTILITYMODULE_API UEnum* StaticEnum<ETransport>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
