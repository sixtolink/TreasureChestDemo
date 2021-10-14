#pragma once

#include "CoreMinimal.h"
#include "PakInfo.h"

namespace SimplePak
{
	struct COMPRESSEDANDENCRYPT_API FCompressedByte
	{
		/*
		* 压缩数据
		* param01 待压缩文件路径
		* param02 压缩后文件路径
		* param03 分片大小
		* param04 加密
		*/
		static bool CompressedData(const FString& ReadPaths, const FString& SavePaths, const FString& BaseURL = "", uint64 FragmentSize = BYTE_30M, EEncryptionMode EncryptionMode = EEncryptionMode::NONE, const FString& Keys = "");
		
		/*
		* AES加密数据
		* param01 待加密数据
		* param02 Key
		*/
		static void AESEncrtptData(TArray<uint8> &RawData, const FString& Keys);
	};
}