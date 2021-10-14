// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"

/**
 * 
 */
class HTTPTOOL_API SCHttpManage
{
public:
	SCHttpManage();
	~SCHttpManage();

	static SCHttpManage* Get();

	static void Destroy();

	//��url��ȡobjet������
	bool GetObject(const FString& URL, const FString& SavePaths);
	//�����ض�ȡ֮��������ϴ���url
	bool PutObject(const FString& URL, TArray<uint8>& Data);
	//�ӱ���·���ϴ�url
	bool PutObject(const FString& URL, const FString& LocalPaths);
	//��stream�ϴ�
	bool PutObject(const FString& URL, TSharedRef<FArchive,ESPMode::ThreadSafe> Stream);
	//ɾ������������Դ
	bool DeleteObject(const FString& URL);

private: 
	//������ɹ��ص�����
	void HttpRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully);
	//���������ʱ�ص�����
	void HttpRequestProgress(FHttpRequestPtr Request, int32 BytesSent, int32 BytesReceived);
	//������ͷ����Ϣ�ص�����
	void HttpRequestHeaderReceived(FHttpRequestPtr Request, const FString& HeaderName, const FString& NewHeaderValue);

	void Print(const FString& Msg, float Time = 10.f, FColor Color = FColor::Red);

private:
	static SCHttpManage* SCHttp;

	//�첽��
	FCriticalSection Mutex;
	FString TmpSavePaths;
};