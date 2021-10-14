#include "BlueprintLibrary/MathUtilityLibrary.h"
#include "Core/CoreUtility.h"

void UMathUtilityLibrary::MathMapd_(const FString& Value, const FString& Omin, const FString& Omax, const FString& Nmin, const FString& Nmax, FString& ReturnValue)
{
	MathUtilityTool::MappingTransformation_FString(Value, Omin, Omax, Nmin, Nmax, ReturnValue);
	return;
}

void UMathUtilityLibrary::MathMapd(const double& Value, const double& Omin, const double& Omax, const double& Nmin, const double& Nmax, double& ReturnValue)
{
	MathUtilityTool::MappingTransformation_T<double>(Value, Omin, Omax, Nmin, Nmax, ReturnValue);
	return;
}

void UMathUtilityLibrary::MathMapi(const int32& Value, const int32& Omin, const int32& Omax, const int32& Nmin, const int32& Nmax, int32& ReturnValue)
{
	MathUtilityTool::MappingTransformation_T<int32>(Value, Omin, Omax, Nmin, Nmax, ReturnValue);
	return;
}

void UMathUtilityLibrary::MathMapf(const float& Value, const float& Omin, const float& Omax, const float& Nmin, const float& Nmax, float& ReturnValue)
{
	MathUtilityTool::MappingTransformation_T<float>(Value, Omin, Omax, Nmin, Nmax, ReturnValue);
	return;
}