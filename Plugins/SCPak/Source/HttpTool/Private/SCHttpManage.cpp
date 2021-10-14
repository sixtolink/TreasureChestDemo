// Fill out your copyright notice in the Description page of Project Settings.


#include "SCHttpManage.h"
#include "Client/HTTPClient.h"
#include "Core/HttpMacro.h"

SCHttpManage* SCHttpManage::SCHttp = nullptr;

SCHttpManage::SCHttpManage()
{
}

SCHttpManage::~SCHttpManage()
{
}

SCHttpManage* SCHttpManage::Get()
{
	if (!SCHttp)
	{
		SCHttp = new SCHttpManage();
	}

	return SCHttp;
}

void SCHttpManage::Destroy()
{
	if (SCHttp)
	{
		delete SCHttp;
	}

	SCHttp = nullptr;
}

bool SCHttpManage::GetObject(const FString& URL, const FString& SavePaths)
{
	TmpSavePaths = SavePaths;
	//�����ͻ���--������Ӧ��������--ִ������
	FHTTPClient Client;

	FGetObjectRequest Request(URL);
	REQUEST_BIND_FUN

	return Client.GetObject(Request);
}

bool SCHttpManage::PutObject(const FString& URL, TArray<uint8>& Data)
{
	FHTTPClient Client;

	FPutObjectRequest Request(URL, Data);
	REQUEST_BIND_FUN

	return Client.PutObject(Request);
}

bool SCHttpManage::PutObject(const FString& URL, const FString& LocalPaths)
{
	//�������ļ���ȡ��������
	TArray<uint8> Data;
	if (FFileHelper::LoadFileToArray(Data, *LocalPaths))
	{
		FHTTPClient Client;

		FPutObjectRequest Request(URL, Data);
		REQUEST_BIND_FUN

		return Client.PutObject(Request);
	}

	return false;
}

bool SCHttpManage::PutObject(const FString& URL, TSharedRef<FArchive, ESPMode::ThreadSafe> Stream)
{
	FHTTPClient Client;

	FPutObjectRequest Request(URL, Stream);
	REQUEST_BIND_FUN

	return Client.PutObject(Request);
}

bool SCHttpManage::DeleteObject(const FString& URL)
{
	FHTTPClient Client;
	FDeleteObjectRequest Request(URL);
	REQUEST_BIND_FUN

	return Client.DeleteObject(Request);
}

void SCHttpManage::HttpRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully)
{
	if (Request.IsValid() && Response.IsValid() && bConnectedSuccessfully && EHttpResponseCodes::IsOk(Response->GetResponseCode()))
	{
		//�ж�����ִ�е�������ʲô
		if (Request->GetVerb() == "GET")
		{
			//GetCleanFilename:��ȡ���Ĵ���׺���ļ��������ǰ������·��
			FString Filename = FPaths::GetCleanFilename(Request->GetURL());
			//�����ļ�������
			FFileHelper::SaveArrayToFile(Response->GetContent(), *(Get()->TmpSavePaths / Filename));
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, FString::Printf(TEXT("Download Complete")));
			}
		}else if (Request->GetVerb() == "PUT")
		{
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, FString::Printf(TEXT("Upload Complete")));
			}
		}else if (Request->GetVerb() == "DELETE")
		{

		}
	}
}

void SCHttpManage::HttpRequestProgress(FHttpRequestPtr Request, int32 BytesSent, int32 BytesReceived)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Green, FString::Printf(TEXT("Working......")));
	}
}

void SCHttpManage::HttpRequestHeaderReceived(FHttpRequestPtr Request, const FString& HeaderName, const FString& NewHeaderValue)
{
}

void SCHttpManage::Print(const FString& Msg, float Time, FColor Color)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, Time, Color, Msg);
	}
}
