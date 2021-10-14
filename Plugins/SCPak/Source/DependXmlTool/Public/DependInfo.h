#pragma once

#include "CoreMinimal.h"

namespace DependXmlTool
{

	struct DEPENDXMLTOOL_API FUploadFileMeta
	{
	public:
		FUploadFileMeta(const FString& InFileName, const FString& InImageUrl, const FString& InLocalPath)
			:FileName(InFileName)
			, ImageUrl(InImageUrl)
			, LocalPath(InLocalPath)
		{
		}
		FString FileName;
		FString ImageUrl;
		FString LocalPath;

		FORCEINLINE friend bool operator==(const FUploadFileMeta& A, const FUploadFileMeta& B)
		{
			return A.FileName == B.FileName;
		}
	};
}

using namespace DependXmlTool;