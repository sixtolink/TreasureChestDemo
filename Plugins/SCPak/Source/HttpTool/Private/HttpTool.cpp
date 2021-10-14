// Copyright Epic Games, Inc. All Rights Reserved.

#include "HttpTool.h"
#include "SCHttpManage.h"

#define LOCTEXT_NAMESPACE "FHttpToolModule"

void FHttpToolModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FHttpToolModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	SCHttpManage::Destroy();
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FHttpToolModule, HttpTool)