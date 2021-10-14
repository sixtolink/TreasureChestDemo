#include "Compressed/DecompressedByte.h"
#include "XmlFile.h"
#include "PakInfo.h"


bool SimplePak::FDecompressedByte::DecompressedData(
	const FString& Paths,
	const FString& SavePaths,
	EEncryptionMode EncryptionMode,
	const FString& Keys)
{
	//Hash����Ӧ�����ַ���
	TMap<FString, FString> PakFileData;
	//�ҵ�������Pak·��
	TArray<FString> AllPakPaths;

	IFileManager::Get().FindFilesRecursive(AllPakPaths, *Paths, TEXT("*"), true, true);

	for (const auto& PakPath : AllPakPaths)
	{
		//�õ�������.��hash������.�����������ļ�
		if (!PakPath.Contains("."))
		{
			FString HashName = FPaths::GetCleanFilename(PakPath);
			PakFileData.Add(HashName, PakPath);
		}
	}

	//��������
	FXmlFile* XmlFile = new FXmlFile(Paths / TEXT("DependencyPakFile.xml"));

	FXmlNode* RootNode = XmlFile->GetRootNode();
	if (RootNode)
	{
		const TArray<FXmlNode*> NodeFiles = RootNode->GetChildrenNodes();
		for (const FXmlNode *NodeFile : NodeFiles)
		{
			FString PakPaths = NodeFile->GetAttribute(TEXT("Name"));
			int32 ByteTotalSize = FCString::Atoi(*(NodeFile->GetAttribute(TEXT("ByteTotalSize"))));

			const TArray<FXmlNode*> Blobs = NodeFile->GetChildrenNodes();

			TMap<FString, SimplePak::FByteInfo> ByteMap;
			for (const FXmlNode* Blob : Blobs)
			{
				FString Hash = Blob->GetAttribute(TEXT("Hash"));
				int32 ByteBegin = FCString::Atoi(*(Blob->GetAttribute(TEXT("ByteBegin"))));
				int32 ByteEnd = FCString::Atoi(*(Blob->GetAttribute(TEXT("ByteEnd"))));

				ByteMap.Add(Hash, SimplePak::FByteInfo(ByteBegin, ByteEnd));
			}

			//����ByteMap�����Ϣ���ļ���ȡ�ַ��뱣��
			TArray<uint8> ByteData;
			for (const auto& Tmp : ByteMap)
			{
				TArray<uint8> TmpData;
				FFileHelper::LoadFileToArray(TmpData, *(Paths / Tmp.Key));

				if (EncryptionMode == EEncryptionMode::AES)
				{
					if (Keys != "")
					{
						AESDecryptData(TmpData, Keys);
					}
					AESDecryptData(TmpData, Tmp.Key);
				}
				

				for (uint32 i = Tmp.Value.ByteBgin; i <= Tmp.Value.ByteEnd; ++i)
				{
					if (TmpData.IsValidIndex(i))
					{
						ByteData.Add(TmpData[i]);
					}
				}
			}

			FFileHelper::SaveArrayToFile(ByteData, *(SavePaths / PakPaths));
		}
	}

	delete XmlFile;
	return true;
}

bool SimplePak::FDecompressedByte::AESDecryptData(TArray<uint8>& RawData, const FString& Keys)
{
	if (RawData.Num() % FAES::AESBlockSize == 0)
	{
		FAES::DecryptData(RawData.GetData(), RawData.Num(), TCHAR_TO_ANSI(*Keys));
		return true;
	}
	return false;
}