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

	//从url获取objet到本地
	bool GetObject(const FString& URL, const FString& SavePaths);
	//将本地读取之后的数据上传到url
	bool PutObject(const FString& URL, TArray<uint8>& Data);
	//从本地路径上传url
	bool PutObject(const FString& URL, const FString& LocalPaths);
	//从stream上传
	bool PutObject(const FString& URL, TSharedRef<FArchive,ESPMode::ThreadSafe> Stream);
	//删除服务器上资源
	bool DeleteObject(const FString& URL);

private: 
	//绑定请求成功回调函数
	void HttpRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully);
	//绑定请求进行时回调函数
	void HttpRequestProgress(FHttpRequestPtr Request, int32 BytesSent, int32 BytesReceived);
	//绑定请求头部信息回调函数
	void HttpRequestHeaderReceived(FHttpRequestPtr Request, const FString& HeaderName, const FString& NewHeaderValue);

	void Print(const FString& Msg, float Time = 10.f, FColor Color = FColor::Red);

private:
	static SCHttpManage* SCHttp;

	//异步锁
	FCriticalSection Mutex;
	FString TmpSavePaths;
};