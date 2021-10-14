#pragma once

#include "CoreMinimal.h"
#include "DependInfo.h"

class DEPENDXMLTOOL_API FDependXmlManage
{
public:
	FDependXmlManage();
	~FDependXmlManage();

	static FDependXmlManage* Get();

	static void Destroy();

	void WriteToFile(const FString& InSavePath, const TArray<FUploadFileMeta>& InFileInfo, bool& bSuccess);

	void ReadFromFile(const FString& InSavePath, TArray<FUploadFileMeta>& OutFileInfo, bool& bSuccess);

private:
	static FDependXmlManage* DependXmlManage;
};