#pragma once

#include "CoreMinimal.h"
#include "HttpUtilityType.generated.h"

UENUM(BlueprintType)
enum class ERequestVerb :uint8
{
	GET,
	PUT,
	POST,
	DELETE
};

UENUM(BlueprintType)
enum class ERequestContentType :uint8
{
	NORMAL,
	JSON
};

DECLARE_DYNAMIC_DELEGATE_OneParam(FCompleteDelegate, const FString&, Content);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FProgressDelegate, int32, InSent, int32, InRece);
DECLARE_DYNAMIC_DELEGATE(FReceivedDelegate);