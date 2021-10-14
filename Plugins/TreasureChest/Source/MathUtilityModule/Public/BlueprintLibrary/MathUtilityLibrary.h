#pragma once

#include "CoreMinimal.h"

#include "Kismet/BlueprintFunctionLibrary.h"
#include "MathUtilityLibrary.generated.h"

UCLASS(meta = (BlueprintThreadSafe, ScriptName = "MathUtilityLibrary"))
class MATHUTILITYMODULE_API UMathUtilityLibrary :public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintPure, meta = (DisplayName = "double_ Mapping", Keywords = "Mapping"), Category = "MathUtilities")
		static void MathMapd_(const FString& Value, const FString& Omin, const FString& Omax, const FString& Nmin, const FString& Nmax, FString& ReturnValue); 
		
	UFUNCTION(BlueprintPure, meta = (DisplayName = "double Mapping", Keywords = "Mapping"), Category = "MathUtilities")
		static void MathMapd(const double& Value, const double& Omin, const double& Omax, const double& Nmin, const double& Nmax, double& ReturnValue);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "int Mapping", Keywords = "Mapping"), Category = "MathUtilities")
		static void MathMapi(const int32& Value, const int32& Omin, const int32& Omax, const int32& Nmin, const int32& Nmax, int32& ReturnValue);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "float Mapping", Keywords = "Mapping"), Category = "MathUtilities")
		static void MathMapf(const float& Value, const float& Omin, const float& Omax, const float& Nmin, const float& Nmax, float& ReturnValue);
};