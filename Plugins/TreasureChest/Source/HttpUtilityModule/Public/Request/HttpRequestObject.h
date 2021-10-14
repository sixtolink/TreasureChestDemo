#pragma once

#include "CoreMinimal.h"
#include "Interface/HttpRequestInterface.h"
#include "HttpCommon/HttpUtilityType.h"

namespace HttpUtilityTool
{
	struct HTTPUTILITYMODULE_API FHttpClientRequest :IHttpClientRequest
	{
	public:
		FHttpClientRequest(
			const FString& InURL,
			const ERequestVerb& InVerb,
			const ERequestContentType& InContentType,
			const TMap<FString, FString>& InHeadParam,
			const FCompleteDelegate& InCompleteDel,
			const FProgressDelegate& InProgressDel,
			const FReceivedDelegate& InHeadReceDel);

	protected:
		void HttpRequestComplete(FHttpRequestPtr InRequest, FHttpResponsePtr InResponse, bool bConnectedSuccess);
		void HttpRequestProgress(FHttpRequestPtr InRequest, int32 ByteSent, int32 ByteReceived);
		void HttpRequestHeaderReceived(FHttpRequestPtr InRequesr, const FString& HeaderName, const FString& NewHeaderValue);
	};
}