#pragma once

#include "CoreMinimal.h"

namespace SimpleXML
{
	void Write(const FString& XmlHead, const FString& Attribute, const FString& XmlValue, FString& Content, bool bArray = false);

	FString Write(const FString& XmlHead, const FString& Attribute, const FString& XmlValue, bool bArray = false);

	FString ANSI(int32 I, int32 J);

	FString AorB(const FString& Value, const FString& A, const FString& B, const FString& Condition = "-1");
}