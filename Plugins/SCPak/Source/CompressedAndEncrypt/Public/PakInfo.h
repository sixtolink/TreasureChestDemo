// Saved PakInfo.

#pragma once

#include "CoreMinimal.h"
#include "PakInfo.generated.h"

#define BYTE_30M 31457280

UENUM(BlueprintType)
enum class EEncryptionMode :uint8
{
	NONE,
	AES,
	MAX
};

namespace SimplePak
{

	//FGuid::NewGuid().ToString()
	typedef FGuid FPakHash;

	struct COMPRESSEDANDENCRYPT_API FByteInfo
	{
		FByteInfo()
			:ByteBgin(0)
			,ByteEnd(BYTE_30M){}

		FByteInfo(uint32 InByteBegin, uint32 InByteEnd) 
			:ByteBgin(InByteBegin)
			,ByteEnd(InByteEnd){}

		uint32 ByteBgin;
		uint32 ByteEnd;
	};

	typedef TMap<FPakHash, FByteInfo> TSimpleHashMapPakInfo;
	struct COMPRESSEDANDENCRYPT_API FPakInfo
	{
		FPakInfo()
			:ByteTotalSize(0){}

		FPakInfo(uint32 InByteTotalSize,const FString& InRelativePath)
			:RelativePath(InRelativePath)
			,ByteTotalSize(InByteTotalSize) {}

		FString RelativePath;
		uint32 ByteTotalSize;
		TMap <FPakHash, FByteInfo> StickyBag;
	};
}