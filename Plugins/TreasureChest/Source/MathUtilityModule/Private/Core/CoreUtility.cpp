#include "CoreUtility.h"

void MathUtilityTool::MappingTransformation_FString(const FString& Value, const FString& Omin, const FString& Omax, const FString& Nmin, const FString& Nmax, FString& ReturnValue)
{
	double _Value = FCString::Atod(*Value);
	double _OMin = FCString::Atod(*Omin);
	double _OMax = FCString::Atod(*Omax);
	double _NMin = FCString::Atod(*Nmin);
	double _NMax = FCString::Atod(*Nmax);
	double _ReturnValue;
	_ReturnValue = ((_NMax - _NMin) / (_OMax - _OMin)) * (_Value - _OMin) + _NMin;

	ReturnValue = FString::SanitizeFloat(_ReturnValue);
	return;
}

template<typename T>
void MathUtilityTool::MappingTransformation_T(const T& Value, const T& Omin, const T& Omax, const T& Nmin, const T& Nmax, T& ReturnValue)
{
	ReturnValue = ((Nmax - Nmin) / (Omax - Omin)) * (Value - Omin) + Nmin;
	return;
}