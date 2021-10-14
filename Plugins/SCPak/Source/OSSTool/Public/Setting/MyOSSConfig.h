// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MyOSSConfig.generated.h"

/**
 *
 */
UCLASS(config = OSSConfig)
class OSSTOOL_API UMyOSSConfig : public UObject
{
	GENERATED_BODY()

public:

	UMyOSSConfig();

public:

	UPROPERTY(Config, EditAnywhere, Category = "OSSConfig")
		FString AccessKeyID;

	UPROPERTY(Config, EditAnywhere, Category = "OSSConfig")
		FString AccessSecret;

	UPROPERTY(Config, EditAnywhere, Category = "OSSConfig")
		FString Endpoint;

	UPROPERTY(Config, EditAnywhere, Category = "OSSConfig")
		FString BucketName;

};