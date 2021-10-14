#pragma once

#include "CoreMinimal.h"
#include "DependInfo.h"

namespace WriteXML
{
	//InfoItem写入
	void Write(const FString& XmlHead, const FString& Attribute, const FString& XmlValue, FString& Content, bool bArray = false);

	//Info整体写入
	bool AllWrite(const FString& InSavePath, const TArray<FUploadFileMeta>& InFileInfo);

	//Info整体读取
	bool AllRead(const FString& InSavePath, TArray<FUploadFileMeta>& OutFileInfo);
}