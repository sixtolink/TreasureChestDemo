// Copyright Epic Games, Inc. All Rights Reserved.

#include "OSSTool.h"
#include "SCOssManage.h"
#include "Misc/MessageDialog.h"
#include "ToolMenus.h"
#include "ISettingsModule.h"
#include "Setting/MyOSSConfig.h"

#define LOCTEXT_NAMESPACE "FOSSToolModule"

void FOSSToolModule::StartupModule()
{
	//×¢²áÅäÖÃÄ¿Â¼
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>(TEXT("Settings")))
	{
		SettingsModule->RegisterSettings(
			"Editor",
			"OSSToolManager",
			"OSSToolAcountSettings",
			LOCTEXT("OSSToolAcountSettings", "OSSTool Settings Config"),
			LOCTEXT("OSSToolAcountSettingsTip", "Set OSSTool Acount"),
			GetMutableDefault<UMyOSSConfig>()
		);
	}
}

void FOSSToolModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	SCOssManage::Destroy();
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FOSSToolModule, OSSTool)