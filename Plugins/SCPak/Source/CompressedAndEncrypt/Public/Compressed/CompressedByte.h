#pragma once

#include "CoreMinimal.h"
#include "PakInfo.h"

namespace SimplePak
{
	struct COMPRESSEDANDENCRYPT_API FCompressedByte
	{
		/*
		* ѹ������
		* param01 ��ѹ���ļ�·��
		* param02 ѹ�����ļ�·��
		* param03 ��Ƭ��С
		* param04 ����
		*/
		static bool CompressedData(const FString& ReadPaths, const FString& SavePaths, const FString& BaseURL = "", uint64 FragmentSize = BYTE_30M, EEncryptionMode EncryptionMode = EEncryptionMode::NONE, const FString& Keys = "");
		
		/*
		* AES��������
		* param01 ����������
		* param02 Key
		*/
		static void AESEncrtptData(TArray<uint8> &RawData, const FString& Keys);
	};
}