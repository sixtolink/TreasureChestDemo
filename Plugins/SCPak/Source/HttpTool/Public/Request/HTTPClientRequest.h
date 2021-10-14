#pragma once

#include "CoreMinimal.h"
#include "RequestInterface.h"

namespace SimpleHTTP
{
	namespace HTTP
	{
		struct HTTPTOOL_API FPutObjectRequest:IHTTPClientRequest
		{
			FPutObjectRequest(const FString& URL, const FString& ContentString);
			FPutObjectRequest(const FString& URL, TArray<uint8>& ContentPayload);
			FPutObjectRequest(const FString& URL, TSharedRef<FArchive, ESPMode::ThreadSafe> Stream);
		};

		struct HTTPTOOL_API FGetObjectRequest:IHTTPClientRequest 
		{
			FGetObjectRequest(const FString& URL);
		};
		
		struct HTTPTOOL_API FDeleteObjectRequest:IHTTPClientRequest 
		{
			FDeleteObjectRequest(const FString& URL);
		};
	}
}