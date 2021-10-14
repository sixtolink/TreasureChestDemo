#pragma once

#include "CoreMinimal.h"
#include "Request/HttpRequestObject.h"

namespace HttpUtilityTool
{
	struct HTTPUTILITYMODULE_API FHttpClient
	{
		FHttpClient();
		bool HttpRequestProgress(FHttpClientRequest& Request);
		void HttpRequestCancel(FHttpClientRequest& Request);
	};
}