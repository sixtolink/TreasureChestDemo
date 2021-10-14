// Fill out your copyright notice in the Description page of Project Settings.


#include "HttpLib.h"
#include "SCHttpManage.h"

void UHttpLib::CusPutObject(FString InURL, FString InLocalPaths)
{
	SCHttpManage::Get()->PutObject(InURL, InLocalPaths);
}

void UHttpLib::CusGetObject(FString InURL, FString InSavePaths)
{
	SCHttpManage::Get()->GetObject(InURL, InSavePaths);
}
