#include "Compressed/CompressedByte.h"
#include "PakInfo.h"
#include "Core/SimpleXML.h"
#include "XmlFile.h"
#include "Math/UnrealMathUtility.h"
#include "Misc/FileHelper.h"

typedef TMap<SimplePak::FPakHash, TArray<uint8>> TSimpleHashMapPakData;

//递归添加PakInfo
void RecursionAddPakInfo(TArray<uint8>& ByteData,
	TSimpleHashMapPakData& PakData,
	SimplePak::TSimpleHashMapPakInfo& PakInfo,
	uint64 FragmentSize)
{
	SimplePak::FPakHash* HashPoint = nullptr;
	SimplePak::FByteInfo ByteInfo;
	
	//判断当前数据长度是否小于分片标准大小
	if (ByteData.Num() <= FragmentSize)
	{
		//遍历PakData寻找可用空间
		for (auto& Tmp : PakData)
		{
			uint64 SurplusNum = FragmentSize - Tmp.Value.Num();
			if (ByteData.Num() <= SurplusNum)
			{
				//设定数据起点为当前内存已存在数据的末尾
				ByteInfo.ByteBgin = Tmp.Value.Num();
				Tmp.Value.Append(ByteData);
				ByteInfo.ByteEnd = Tmp.Value.Num() - 1;
				HashPoint = &Tmp.Key;
				break;
			}
		}

		if (HashPoint == nullptr)
		{
			//开辟新的空间
			//PakData还没有任何添加，则直接添加数据
			ByteInfo.ByteEnd = ByteData.Num() - 1;
			SimplePak::FPakHash HashObject = FGuid::NewGuid();
			PakData.Add(HashObject, ByteData);
			HashPoint = const_cast<SimplePak::FPakHash*>(PakData.FindKey(ByteData));
		}

		PakInfo.Add(*HashPoint, ByteInfo);
	}
	else
	{
		//单个文件数据大于分片最大容量
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

		//开辟新的空间
		//PakData还没有任何添加，则直接添加数据
		ByteInfo.ByteEnd = HalfData.Num() - 1;
		SimplePak::FPakHash HashObject = FGuid::NewGuid();
		PakData.Add(HashObject, HalfData);
		HashPoint = const_cast<SimplePak::FPakHash*>(PakData.FindKey(HalfData));
		PakInfo.Add(*HashPoint, ByteInfo);

		//释放临时的数据
		ByteData.Empty();

		RecursionAddPakInfo(SurplusData, PakData, PakInfo, FragmentSize);
	}
}

//储存xml文件
bool SavePakInfoToXmlFile(const FString& Paths, const TArray<SimplePak::FPakInfo>& PakInfo, const FString& BaseURL = "")
{
	FString XMLArray;
	for (auto& Tmp : PakInfo)
	{
		FString BagMap;
		for (const auto& BagTmp : Tmp.StickyBag)
		{
			FString BagElement;

			//拿到属性
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
	//获取目录下所有文件
	IFileManager::Get().FindFilesRecursive(AllPaths, *ReadPaths, TEXT("*"), true, true);

	//保存切割处理完毕的真正有用数据
	TSimpleHashMapPakData PakData;

	//保存着Pak的Hash和字节信息
	TArray<SimplePak::FPakInfo> PakInfo;
	for (auto& Tmp : AllPaths)
	{
		//读取的字节数据
		TArray<uint8> ByteData;
		FFileHelper::LoadFileToArray(ByteData, *Tmp);

		if (ByteData.Num())
		{
			//将得到的文件的相对路径保存到PakInfo数组中
			//ReadPaths F:/Project/HotUpdate/TaskPak
			//Tmp F:/Project/HotUpdate/TaskPak/aaa.jepg
			//RemoveFromStart移除F:/Project/HotUpdate/TaskPak/
			PakInfo.Add(SimplePak::FPakInfo());
			Tmp.RemoveFromStart(ReadPaths / TEXT(""));
			PakInfo[PakInfo.Num() - 1].RelativePath = Tmp;
			PakInfo[PakInfo.Num() - 1].ByteTotalSize = ByteData.Num();

			RecursionAddPakInfo(ByteData, PakData, PakInfo[PakInfo.Num() - 1].StickyBag, FragmentSize);

			TArray<SimplePak::FPakHash*> RemovePakHash;
			//动态释放内存
			for (auto& TmpPak : PakData)
			{
				if (FMath::Abs<int32>(TmpPak.Value.Num() - FragmentSize <= 4))
				{
					RemovePakHash.Add(&TmpPak.Key);
				}
			}

			//移除需要移除的pakdata
			for (auto& PakID : RemovePakHash)
			{
				PakData.Remove(*PakID);
			}
		}
	}

	//储存Hash对应的文件数据
	for (auto& Tmp : PakData)
	{
		//判断加密模式
		if (EncryptionMode == EEncryptionMode::AES)
		{
			if (Keys != "")
			{
				AESEncrtptData(Tmp.Value, Keys);
			}
			//加密Pak包里面一整块的数据
			AESEncrtptData(Tmp.Value, Tmp.Key.ToString());
		}

		FFileHelper::SaveArrayToFile(Tmp.Value, *(SavePaths / Tmp.Key.ToString()));
	}

	//储存到XML
	return SavePakInfoToXmlFile(SavePaths, PakInfo, BaseURL);
}

//递归补充数组字节至16便于参与加密运算
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