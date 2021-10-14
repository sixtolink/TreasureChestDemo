// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "HttpLib.generated.h"

/**
 * 
 */
UCLASS()
class HTTPTOOL_API UHttpLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "CusHttp")
	static void CusPutObject(FString InURL,FString InLocalPaths);

	UFUNCTION(BlueprintCallable, Category = "CusHttp")
	static void CusGetObject(FString InURL, FString InSavePaths);
	
};
