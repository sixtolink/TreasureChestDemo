#pragma once

#include "CoreMinimal.h"
#include "Client/HttpClient.h"

#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"

#include "HttpCommon/HttpUtilityType.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "HttpUtilityLibrary.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FHttpRequestSuccessDelegate, const FString&, Msg);

UCLASS(BlueprintType)
class HTTPUTILITYMODULE_API UHttpUtilityLibrary :public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "HttpProgress", Keywords = "HttpProgress"), Category = "HttpUtilities")
		static UHttpUtilityLibrary* MyHttpProgress(
			const FString& InUrl,
			ERequestVerb InVerb,
			ERequestContentType InContentType,
			const TMap<FString, FString>& InHeadParam,
			const FCompleteDelegate& InCompleteDel,
			const FProgressDelegate& InProgressDel,
			const FReceivedDelegate& InHeadReceDel);

	UPROPERTY(BlueprintAssignable, Category = "HttpUtilities")
		FHttpRequestSuccessDelegate OnSuccess;
	UPROPERTY(BlueprintAssignable, Category = "HttpUtilities")
		FHttpRequestSuccessDelegate OnFail;

protected:

	void DelSuccess();
	void DelFailed();
};