#include "DependXmlManage.h"
#include "Core/WriteXML.h"

FDependXmlManage* FDependXmlManage::DependXmlManage = nullptr;

FDependXmlManage::FDependXmlManage()
{

}

FDependXmlManage::~FDependXmlManage()
{

}

FDependXmlManage* FDependXmlManage::Get()
{
	if (!DependXmlManage)
	{
		DependXmlManage = new FDependXmlManage();
	}

	return DependXmlManage;
}

void FDependXmlManage::Destroy()
{
	if (DependXmlManage)
	{
		delete DependXmlManage;
	}

	DependXmlManage = nullptr;
}

void FDependXmlManage::WriteToFile(const FString& InSavePath, const TArray<FUploadFileMeta>& InFileInfo, bool& bSuccess)
{
	bSuccess = WriteXML::AllWrite(InSavePath, InFileInfo);
	return;
}

void FDependXmlManage::ReadFromFile(const FString& InSavePath, TArray<FUploadFileMeta>& OutFileInfo, bool& bSuccess)
{
	bSuccess = WriteXML::AllRead(InSavePath, OutFileInfo);
	return;
}
