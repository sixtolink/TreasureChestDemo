#include "BlueprintLibrary/HttpUtilityLibrary.h"

UHttpUtilityLibrary* UHttpUtilityLibrary::MyHttpProgress(
	const FString& InUrl,
	ERequestVerb InVerb,
	ERequestContentType InContentType,
	const TMap<FString, FString>& InHeadParam,
	const FCompleteDelegate& InCompleteDel,
	const FProgressDelegate& InProgressDel,
	const FReceivedDelegate& InHeadReceDel)
{
	UHttpUtilityLibrary* ThisObject = NewObject<UHttpUtilityLibrary>();

	HttpUtilityTool::FHttpClient DoHttpClient;
	HttpUtilityTool::FHttpClientRequest DoHttpRequest(InUrl, InVerb, InContentType, InHeadParam, InCompleteDel, InProgressDel, InHeadReceDel);

	if (DoHttpClient.HttpRequestProgress(DoHttpRequest))
	{
		ThisObject->DelSuccess();
	}
	else
	{
		ThisObject->DelFailed();
	}

	return ThisObject;
}

void UHttpUtilityLibrary::DelSuccess()
{
	OnSuccess.Broadcast(FString("Successed"));
	return;
}

void UHttpUtilityLibrary::DelFailed()
{
	OnFail.Broadcast(FString("Failed"));
	return;
}