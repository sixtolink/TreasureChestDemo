#include "Compressed/CompressedByte.h"
#include "PakInfo.h"
#include "Core/SimpleXML.h"
#include "XmlFile.h"
#include "Math/UnrealMathUtility.h"
#include "Misc/FileHelper.h"

typedef TMap<SimplePak::FPakHash, TArray<uint8>> TSimpleHashMapPakData;

//�ݹ����PakInfo
void RecursionAddPakInfo(TArray<uint8>& ByteData,
	TSimpleHashMapPakData& PakData,
	SimplePak::TSimpleHashMapPakInfo& PakInfo,
	uint64 FragmentSize)
{
	SimplePak::FPakHash* HashPoint = nullptr;
	SimplePak::FByteInfo ByteInfo;
	
	//�жϵ�ǰ���ݳ����Ƿ�С�ڷ�Ƭ��׼��С
	if (ByteData.Num() <= FragmentSize)
	{
		//����PakDataѰ�ҿ��ÿռ�
		for (auto& Tmp : PakData)
		{
			uint64 SurplusNum = FragmentSize - Tmp.Value.Num();
			if (ByteData.Num() <= SurplusNum)
			{
				//�趨�������Ϊ��ǰ�ڴ��Ѵ������ݵ�ĩβ
				ByteInfo.ByteBgin = Tmp.Value.Num();
				Tmp.Value.Append(ByteData);
				ByteInfo.ByteEnd = Tmp.Value.Num() - 1;
				HashPoint = &Tmp.Key;
				break;
			}
		}

		if (HashPoint == nullptr)
		{
			//�����µĿռ�
			//PakData��û���κ���ӣ���ֱ���������
			ByteInfo.ByteEnd = ByteData.Num() - 1;
			SimplePak::FPakHash HashObject = FGuid::NewGuid();
			PakData.Add(HashObject, ByteData);
			HashPoint = const_cast<SimplePak::FPakHash*>(PakData.FindKey(ByteData));
		}

		PakInfo.Add(*HashPoint, ByteInfo);
	}
	else
	{
		//�����ļ����ݴ��ڷ�Ƭ�������
		TArray<uint8> HalfData;
		TArray<uint8> SurplusData;
		for (int32 i = 0; i < ByteData.Num(); ++i)
		{
			if (i <= FragmentSize)
			{
				HalfData.Add(ByteData[i]);
			}
			else
			{
				SurplusData.Add(ByteData[i]);
			}
		}

		//�����µĿռ�
		//PakData��û���κ���ӣ���ֱ���������
		ByteInfo.ByteEnd = HalfData.Num() - 1;
		SimplePak::FPakHash HashObject = FGuid::NewGuid();
		PakData.Add(HashObject, HalfData);
		HashPoint = const_cast<SimplePak::FPakHash*>(PakData.FindKey(HalfData));
		PakInfo.Add(*HashPoint, ByteInfo);

		//�ͷ���ʱ������
		ByteData.Empty();

		RecursionAddPakInfo(SurplusData, PakData, PakInfo, FragmentSize);
	}
}

//����xml�ļ�
bool SavePakInfoToXmlFile(const FString& Paths, const TArray<SimplePak::FPakInfo>& PakInfo, const FString& BaseURL = "")
{
	FString XMLArray;
	for (auto& Tmp : PakInfo)
	{
		FString BagMap;
		for (const auto& BagTmp : Tmp.StickyBag)
		{
			FString BagElement;

			//�õ�����
			FString BagAttribute;
			BagAttribute.Append(
				TEXT("Hash=\"" + BagTmp.Key.ToString() + TEXT("\" "))
				TEXT("ByteBegin=\"" + FString::FromInt(BagTmp.Value.ByteBgin) + TEXT("\" "))
				TEXT("ByteEnd=\"" + FString::FromInt(BagTmp.Value.ByteEnd) + TEXT("\"")));

			SimpleXML::Write(TEXT("Blob"), BagAttribute, "", BagElement);

			BagMap.Append(BagElement);
		}

		FString XMLElement;

		FString Attribute;
		Attribute.Append(
			TEXT("Name=\"" + Tmp.RelativePath + TEXT("\" "))
			TEXT("ByteTotalSize=\"" + FString::FromInt(Tmp.ByteTotalSize) + TEXT("\"")));

		SimpleXML::Write(TEXT("File"), Attribute, BagMap, XMLElement,true);

		XMLArray.Append(XMLElement);
	}

	FString DependencyXML;
	SimpleXML::Write(
		TEXT("DependencyPak"),
		FString::Printf(TEXT("BaseURL=\"%s\""),*BaseURL),
		XMLArray,
		DependencyXML,
		true);
	FXmlFile* DependencyXMLFile = new FXmlFile(DependencyXML, EConstructMethod::ConstructFromBuffer);
	bool bSaveSuccess = DependencyXMLFile->Save(Paths / TEXT("DependencyPakFile.xml"));
	delete DependencyXMLFile;
	return bSaveSuccess;
}

bool SimplePak::FCompressedByte::CompressedData(const FString& ReadPaths, const FString& SavePaths, const FString& BaseURL, uint64 FragmentSize, EEncryptionMode EncryptionMode, const FString& Keys)
{
	TArray<FString> AllPaths;
	//��ȡĿ¼�������ļ�
	IFileManager::Get().FindFilesRecursive(AllPaths, *ReadPaths, TEXT("*"), true, true);

	//�����и����ϵ�������������
	TSimpleHashMapPakData PakData;

	//������Pak��Hash���ֽ���Ϣ
	TArray<SimplePak::FPakInfo> PakInfo;
	for (auto& Tmp : AllPaths)
	{
		//��ȡ���ֽ�����
		TArray<uint8> ByteData;
		FFileHelper::LoadFileToArray(ByteData, *Tmp);

		if (ByteData.Num())
		{
			//���õ����ļ������·�����浽PakInfo������
			//ReadPaths F:/Project/HotUpdate/TaskPak
			//Tmp F:/Project/HotUpdate/TaskPak/aaa.jepg
			//RemoveFromStart�Ƴ�F:/Project/HotUpdate/TaskPak/
			PakInfo.Add(SimplePak::FPakInfo());
			Tmp.RemoveFromStart(ReadPaths / TEXT(""));
			PakInfo[PakInfo.Num() - 1].RelativePath = Tmp;
			PakInfo[PakInfo.Num() - 1].ByteTotalSize = ByteData.Num();

			RecursionAddPakInfo(ByteData, PakData, PakInfo[PakInfo.Num() - 1].StickyBag, FragmentSize);

			TArray<SimplePak::FPakHash*> RemovePakHash;
			//��̬�ͷ��ڴ�
			for (auto& TmpPak : PakData)
			{
				if (FMath::Abs<int32>(TmpPak.Value.Num() - FragmentSize <= 4))
				{
					RemovePakHash.Add(&TmpPak.Key);
				}
			}

			//�Ƴ���Ҫ�Ƴ���pakdata
			for (auto& PakID : RemovePakHash)
			{
				PakData.Remove(*PakID);
			}
		}
	}

	//����Hash��Ӧ���ļ�����
	for (auto& Tmp : PakData)
	{
		//�жϼ���ģʽ
		if (EncryptionMode == EEncryptionMode::AES)
		{
			if (Keys != "")
			{
				AESEncrtptData(Tmp.Value, Keys);
			}
			//����Pak������һ���������
			AESEncrtptData(Tmp.Value, Tmp.Key.ToString());
		}

		FFileHelper::SaveArrayToFile(Tmp.Value, *(SavePaths / Tmp.Key.ToString()));
	}

	//���浽XML
	return SavePakInfoToXmlFile(SavePaths, PakInfo, BaseURL);
}

//�ݹ鲹�������ֽ���16���ڲ����������
void RecursionSupplementByte(TArray<uint8>& RawData)
{
	if (RawData.Num() % FAES::AESBlockSize)
	{
		uint8 NewChar = 0;
		RawData.Add(NewChar);
		RecursionSupplementByte(RawData);
	}
	return;
}

void SimplePak::FCompressedByte::AESEncrtptData(TArray<uint8>& RawData, const FString& Keys)
{
	RecursionSupplementByte(RawData);
	FAES::EncryptData(RawData.GetData(), RawData.Num(), TCHAR_TO_ANSI(*Keys));
}