#pragma once

#include "CoreMinimal.h"
#include "DependInfo.h"

namespace WriteXML
{
	//InfoItemд��
	void Write(const FString& XmlHead, const FString& Attribute, const FString& XmlValue, FString& Content, bool bArray = false);

	//Info����д��
	bool AllWrite(const FString& InSavePath, const TArray<FUploadFileMeta>& InFileInfo);

	//Info�����ȡ
	bool AllRead(const FString& InSavePath, TArray<FUploadFileMeta>& OutFileInfo);
}