#pragma once

#include "CoreMinimal.h"

namespace MathUtilityTool
{
	template<typename T>
	void MappingTransformation_T(const T& Value, const T& Omin, const T& Omax, const T& Nmin, const T& Nmax, T& ReturnValue);
	
	void MappingTransformation_FString(const FString& Value, const FString& Omin, const FString& Omax, const FString& Nmin, const FString& Nmax, FString& ReturnValue);
}