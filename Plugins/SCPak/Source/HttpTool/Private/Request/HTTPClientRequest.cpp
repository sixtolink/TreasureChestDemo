#include "Request/HTTPClientRequest.h"
#include "Core/HttpMacro.h"

SimpleHTTP::HTTP::FPutObjectRequest::FPutObjectRequest(const FString& URL, const FString& ContentString)
{
	DEFINITION_HTTP_TYPE("PUT", "application/x-www-form-urlencoded")
	HttpRequest->SetContentAsString(ContentString);
}

SimpleHTTP::HTTP::FPutObjectRequest::FPutObjectRequest(const FString& URL, TArray<uint8>& ContentPayload)
{
	DEFINITION_HTTP_TYPE("PUT", "application/x-www-form-urlencoded")
	HttpRequest->SetContent(ContentPayload);
}

SimpleHTTP::HTTP::FPutObjectRequest::FPutObjectRequest(const FString& URL, TSharedRef<FArchive, ESPMode::ThreadSafe> Stream)
{
	DEFINITION_HTTP_TYPE("PUT", "application/x-www-form-urlencoded")
	HttpRequest->SetContentFromStream(Stream);
}

//HTTP��������
//GET:�ӷ�������ȡ��Դ
//POST:�ڷ������½�һ����Դ
//PUT:�ڷ�����������Դ �ͻ����ṩ�ı���������Դ
//PATCH:�ڷ��������Դ �ͻ����ṩ�ı������
//DELETE:�ڷ�����ɾ����Դ
//HEAD:��ȡ��Դ��Ԫ����
//OPTIONS:��ȡ��Ϣ��������Դ����Щ�����ǿͻ��˿��Ըı��
SimpleHTTP::HTTP::FGetObjectRequest::FGetObjectRequest(const FString& URL)
{
	DEFINITION_HTTP_TYPE("GET", "application/x-www-form-urlencoded")
}

SimpleHTTP::HTTP::FDeleteObjectRequest::FDeleteObjectRequest(const FString& URL)
{
	DEFINITION_HTTP_TYPE("DELETE", "application/x-www-form-urlencoded")
}
