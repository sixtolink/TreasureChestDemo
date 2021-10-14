#pragma once

#include "CoreMinimal.h"
#include "Interfaces/IHttpRequest.h"
#include "Client/HTTPClient.h"

namespace SimpleHTTP
{
	namespace HTTP
	{
		struct HTTPTOOL_API IHTTPClientRequest
		{
			friend struct FHTTPClient;

			IHTTPClientRequest();

			//��д���Ʋ�����
			IHTTPClientRequest& operator<<(const FHttpRequestCompleteDelegate& CompleteDel)
			{
				HttpRequest->OnProcessRequestComplete() = CompleteDel;
				return *this;
			}
			//��д���Ʋ�����
			IHTTPClientRequest& operator<<(const FHttpRequestProgressDelegate& ProgressDel)
			{
				HttpRequest->OnRequestProgress() = ProgressDel;
				return *this;
			}
			//��д���Ʋ�����
			IHTTPClientRequest& operator<<(const FHttpRequestHeaderReceivedDelegate& CompleteDel)
			{
				HttpRequest->OnHeaderReceived() = CompleteDel;
				return *this;
			}
			
		protected:
			//ִ������
			bool ProcessRequest();
			//ȡ������
			void CancelRequest();

		protected:
			TSharedRef<IHttpRequest, ESPMode::ThreadSafe> HttpRequest;
		};
	}
}