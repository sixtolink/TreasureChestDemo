#pragma once

#include "CoreMinimal.h"
#include "Request/HTTPClientRequest.h"

using namespace SimpleHTTP::HTTP;

namespace SimpleHTTP
{
	namespace HTTP
	{
		struct HTTPTOOL_API FHTTPClient
		{
			FHTTPClient();

			bool GetObject(FGetObjectRequest& Request) const;
			bool DeleteObject(FDeleteObjectRequest& Request) const;
			bool PutObject(FPutObjectRequest& Request) const;
			void AbortObject(FPutObjectRequest& Request);
		};
	}
}