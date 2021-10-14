#pragma once

#include "CoreMinimal.h"
#include "Interfaces/IHttpRequest.h"
#include "Client/HttpClient.h"

namespace HttpUtilityTool
{
	struct HTTPUTILITYMODULE_API IHttpClientRequest
	{
		friend struct FHttpClient;
		IHttpClientRequest();

		//重写左移操作符
		IHttpClientRequest& operator<<(const FHttpRequestCompleteDelegate& CompleteDel)
		{
			HttpRequest->OnProcessRequestComplete() = CompleteDel;
			return *this;
		}

		IHttpClientRequest& operator<<(const FHttpRequestProgressDelegate& ProgressDel)
		{
			HttpRequest->OnRequestProgress() = ProgressDel;
			return *this;
		}

		IHttpClientRequest& operator<<(const FHttpRequestHeaderReceivedDelegate& ReceDel)
		{
			HttpRequest->OnHeaderReceived() = ReceDel;
			return *this;
		}

	protected:

		//执行请求
		bool ProgressRequest();

		//取消请求
		void CancelRequest();

	protected:
		TSharedRef<IHttpRequest, ESPMode::ThreadSafe> HttpRequest;
	};
}