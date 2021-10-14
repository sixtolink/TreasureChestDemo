#include "WriteXML.h"
#include "XmlFile.h"

void WriteXML::Write(const FString& XmlHead, const FString& Attribute, const FString& XmlValue, FString& Content, bool bArray /*= false*/)
{
	Content += TEXT("<") + XmlHead + TEXT(" ") + Attribute + TEXT(">") +
		FString(bArray ? TEXT("\n") : TEXT("")) + XmlValue +
		TEXT("</") + XmlHead + TEXT(">\n");
	return;
}

bool WriteXML::AllWrite(const FString& InSavePath, const TArray<FUploadFileMeta>& InFileInfo)
{
	FString XmlContent;
	FString FileItemContent;
	for (const auto& Tmp : InFileInfo)
	{
		FString FileItemContentTemp;
		FString FileItemAttribute;
		FileItemAttribute.Append(
			TEXT("Name=\"" + Tmp.FileName + TEXT("\" "))
			TEXT("ImageUrl=\"" + Tmp.ImageUrl + TEXT("\" "))
			TEXT("LocalPath=\"" + Tmp.LocalPath + TEXT("\"")));

		Write(TEXT("FileItem"), FileItemAttribute, "", FileItemContentTemp, false);
		FileItemContent.Append(FileItemContentTemp);
	}
	
	Write(TEXT("FileInfo"), "", FileItemContent, XmlContent, true);

	FXmlFile* XmlFile = new FXmlFile(XmlContent, EConstructMethod::ConstructFromBuffer);
	bool bSavedSuccess = XmlFile->Save(InSavePath / TEXT("DependencyFile.xml"));
	delete XmlFile;
	return bSavedSuccess;
}

bool WriteXML::AllRead(const FString& InSavePath, TArray<FUploadFileMeta>& OutFileInfo)
{
	//½âÎöxml
	FXmlFile* XmlFile = new FXmlFile(InSavePath);
	FXmlNode* RootNode = XmlFile->GetRootNode();
	if (RootNode)
	{
		const TArray<FXmlNode*> ChildNode = RootNode->GetChildrenNodes();
		for (int32 i = 0; i < ChildNode.Num(); ++i)
		{
			if (!OutFileInfo.IsEmpty())
			{
				TArray<FString> TempNameArray;
				for (const auto& Tmp : OutFileInfo)
				{
					TempNameArray.Add(Tmp.FileName);
				}
				if (!TempNameArray.Contains(ChildNode[i]->GetAttribute(TEXT("Name"))))
				{
					OutFileInfo.Add(FUploadFileMeta(ChildNode[i]->GetAttribute(TEXT("Name")), ChildNode[i]->GetAttribute(TEXT("ImageUrl")), ChildNode[i]->GetAttribute(TEXT("LocalPath"))));
				}
			}
			else
			{
				OutFileInfo.Add(FUploadFileMeta(ChildNode[i]->GetAttribute(TEXT("Name")), ChildNode[i]->GetAttribute(TEXT("ImageUrl")), ChildNode[i]->GetAttribute(TEXT("LocalPath"))));
			}
		}
	}
	delete XmlFile;
	return true;
}