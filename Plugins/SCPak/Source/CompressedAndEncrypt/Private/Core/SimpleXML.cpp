#include "SimpleXML.h"

void SimpleXML::Write(const FString& XmlHead, const FString& Attribute, const FString& XmlValue, FString& Content, bool bArray)
{
	Content += TEXT("<") + XmlHead + TEXT(" ") + Attribute + TEXT(">")
		+ FString(bArray ? TEXT("\n") : TEXT("")) + XmlValue
		+ TEXT("</") + XmlHead + TEXT(">\n");
	return;
}

FString SimpleXML::Write(const FString& XmlHead, const FString& Attribute, const FString& XmlValue, bool bArray)
{
	return TEXT("<") + XmlHead + TEXT(" ") + Attribute + TEXT(">")
		+ FString(bArray ? TEXT("\n") : TEXT("")) + XmlValue
		+ TEXT("</") + XmlHead + TEXT(">\n");
}

FString SimpleXML::ANSI(int32 I, int32 J)
{
	ANSICHAR IndexA = I + 65;
	TCHAR ANSIChar = FString(&IndexA).GetCharArray()[0];

	return FString(&ANSIChar) + FString::FromInt(J + 1);
}

FString SimpleXML::AorB(const FString& Value, const FString& A, const FString& B, const FString& Condition)
{
	return Value == Condition ? B : A;
}
