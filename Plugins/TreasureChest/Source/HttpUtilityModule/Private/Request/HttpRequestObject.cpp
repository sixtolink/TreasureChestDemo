#include "Request/HttpRequestObject.h"
#include "Interfaces/IHttpResponse.h"

FCompleteDelegate DDMD_InCompleteDel;
FProgressDelegate DDMD_InProgressDel;
FReceivedDelegate DDMD_InHeadReceDel;

HttpUtilityTool::FHttpClientRequest::FHttpClientRequest(
	const FString& InURL,
	const ERequestVerb& InVerb,
	const ERequestContentType& InContentType,
	const TMap<FString, FString>& InHeadParam,
	const FCompleteDelegate& InCompleteDel,
	const FProgressDelegate& InProgressDel,
	const FReceivedDelegate& InHeadReceDel)
{
	*this << FHttpRequestCompleteDelegate::CreateRaw(this, &HttpUtilityTool::FHttpClientRequest::HttpRequestComplete)
		<< FHttpRequestProgressDelegate::CreateRaw(this, &HttpUtilityTool::FHttpClientRequest::HttpRequestProgress)
		<< FHttpRequestHeaderReceivedDelegate::CreateRaw(this, &HttpUtilityTool::FHttpClientRequest::HttpRequestHeaderReceived);

	DDMD_InCompleteDel = InCompleteDel;
	DDMD_InProgressDel = InProgressDel;
	DDMD_InHeadReceDel = InHeadReceDel;

	HttpRequest->SetURL(InURL);

	switch (InVerb)
	{
	case ERequestVerb::GET:
		HttpRequest->SetVerb(TEXT("GET"));
		break;
	case ERequestVerb::PUT:
		HttpRequest->SetVerb(TEXT("PUT"));
		break;
	case ERequestVerb::POST:
		HttpRequest->SetVerb(TEXT("POST"));
		break;
	}

	switch (InContentType)
	{
	case ERequestContentType::NORMAL:
		HttpRequest->SetHeader(TEXT("Content-Type"), TEXT("application/x-www-form-urlencoded"));
		break;
	case ERequestContentType::JSON:
		HttpRequest->SetHeader(TEXT("Content-Type"), TEXT("application/json;charset=utf-8"));
		break;
	}

	if (InHeadParam.Num() > 1)
	{
		for (const auto& Tmp : InHeadParam)
		{
			if (Tmp.Key != "")
			{
				HttpRequest->SetHeader(Tmp.Key, Tmp.Value);
			}
		}
	}
}

void HttpUtilityTool::FHttpClientRequest::HttpRequestComplete(FHttpRequestPtr InRequest, FHttpResponsePtr InResponse, bool bConnectedSuccess)
{
	int32 Code = InResponse->GetResponseCode();
	if (EHttpResponseCodes::IsOk(Code))
	{
		FString OutputString = InResponse->GetContentAsString();
		DDMD_InCompleteDel.ExecuteIfBound(OutputString);
	}
}

void HttpUtilityTool::FHttpClientRequest::HttpRequestProgress(FHttpRequestPtr InRequest, int32 ByteSent, int32 ByteReceived)
{
	if (DDMD_InProgressDel.ExecuteIfBound(ByteSent, ByteReceived))
	{
		UE_LOG(LogTemp, Error, TEXT("HttpRequestProgress_Success"));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("HttpRequestProgress_Fail"));
	}
}

void HttpUtilityTool::FHttpClientRequest::HttpRequestHeaderReceived(FHttpRequestPtr InRequesr, const FString& HeaderName, const FString& NewHeaderValue)
{
	if (DDMD_InHeadReceDel.ExecuteIfBound())
	{
		UE_LOG(LogTemp, Error, TEXT("HttpRequestHeaderReceived_Success"));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("HttpRequestHeaderReceived_Fail"));
	}
}