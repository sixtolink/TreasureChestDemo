#pragma once

#include "CoreMinimal.h"

namespace SimplePak
{
	struct COMPRESSEDANDENCRYPT_API FDecompressedByte
	{
		static bool DecompressedData(const FString& Paths, const FString& SavePaths, EEncryptionMode EncryptionMode = EEncryptionMode::NONE, const FString& Keys = "");

		static bool AESDecryptData(TArray<uint8>& RawData, const FString& Keys);
	};
}