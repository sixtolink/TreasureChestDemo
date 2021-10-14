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

		//��д���Ʋ�����
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

		//ִ������
		bool ProgressRequest();

		//ȡ������
		void CancelRequest();

	protected:
		TSharedRef<IHttpRequest, ESPMode::ThreadSafe> HttpRequest;
	};
}