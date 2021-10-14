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

			//重写左移操作符
			IHTTPClientRequest& operator<<(const FHttpRequestCompleteDelegate& CompleteDel)
			{
				HttpRequest->OnProcessRequestComplete() = CompleteDel;
				return *this;
			}
			//重写左移操作符
			IHTTPClientRequest& operator<<(const FHttpRequestProgressDelegate& ProgressDel)
			{
				HttpRequest->OnRequestProgress() = ProgressDel;
				return *this;
			}
			//重写左移操作符
			IHTTPClientRequest& operator<<(const FHttpRequestHeaderReceivedDelegate& CompleteDel)
			{
				HttpRequest->OnHeaderReceived() = CompleteDel;
				return *this;
			}
			
		protected:
			//执行请求
			bool ProcessRequest();
			//取消请求
			void CancelRequest();

		protected:
			TSharedRef<IHttpRequest, ESPMode::ThreadSafe> HttpRequest;
		};
	}
}