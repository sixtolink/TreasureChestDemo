// Copyright Epic Games, Inc. All Rights Reserved.

#include "CompressedLibrary.h"
#include "Compressed/CompressedByte.h"
#include "Compressed/DecompressedByte.h"

UCompressedLibrary::UCompressedLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

bool UCompressedLibrary::CompressedData(FString ReadPaths, FString SavePaths, FString BaseURL, int64 FragmentSize, EEncryptionMode EncryptionMode, FString Keys)
{
	return SimplePak::FCompressedByte::CompressedData(ReadPaths, SavePaths, BaseURL, FragmentSize, EncryptionMode, Keys);
}

bool UCompressedLibrary::DecompressedData(FString Paths, FString SavePaths, EEncryptionMode EncryptionMode, FString Keys)
{
	return SimplePak::FDecompressedByte::DecompressedData(Paths, SavePaths, EncryptionMode, Keys);
}

