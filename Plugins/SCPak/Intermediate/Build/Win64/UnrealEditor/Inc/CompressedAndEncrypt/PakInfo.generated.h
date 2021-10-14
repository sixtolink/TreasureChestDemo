// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef COMPRESSEDANDENCRYPT_PakInfo_generated_h
#error "PakInfo.generated.h already included, missing '#pragma once' in PakInfo.h"
#endif
#define COMPRESSEDANDENCRYPT_PakInfo_generated_h

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TreasureChestDemo_Plugins_SCPak_Source_CompressedAndEncrypt_Public_PakInfo_h


#define FOREACH_ENUM_EENCRYPTIONMODE(op) \
	op(EEncryptionMode::NONE) \
	op(EEncryptionMode::AES) 

enum class EEncryptionMode : uint8;
template<> COMPRESSEDANDENCRYPT_API UEnum* StaticEnum<EEncryptionMode>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
