// Some copyright should be here...

using UnrealBuildTool;
using System.IO;

public class OSSTool : ModuleRules
{
	private string ThirdPartyPath
    {
        get
        {
			return Path.GetFullPath(Path.Combine(ModuleDirectory, "../ThirdParty/OSSToolThirdParty"));
        }
    }
	public OSSTool(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
            {
               
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
                "Projects",
                "InputCore",
                "EditorFramework",
                "UnrealEd",
                "ToolMenus",
                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore",
				"Settings"
				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
		string IncludePath = Path.Combine(ThirdPartyPath, "include");
		PublicIncludePaths.Add(IncludePath);
		PublicIncludePaths.Add(Path.Combine(IncludePath, "curl"));
		PublicIncludePaths.Add(Path.Combine(IncludePath, "openssl"));
        string Alibabacloudpath = Path.Combine(IncludePath, "alibabacloud/oss");
        PublicIncludePaths.Add(Path.Combine(Alibabacloudpath, "auth"));
        PublicIncludePaths.Add(Path.Combine(Alibabacloudpath, "client"));
        PublicIncludePaths.Add(Path.Combine(Alibabacloudpath, "encryption"));
        PublicIncludePaths.Add(Path.Combine(Alibabacloudpath, "http"));
        PublicIncludePaths.Add(Path.Combine(Alibabacloudpath, "model"));
        PublicIncludePaths.Add(Path.Combine(Alibabacloudpath, "utils"));

		string LibraryPath = Path.Combine(ThirdPartyPath, "lib");
		PublicAdditionalLibraries.Add(Path.Combine(LibraryPath, "x64", "libcurl.lib"));
		PublicAdditionalLibraries.Add(Path.Combine(LibraryPath, "x64", "libeay32.lib"));
		PublicAdditionalLibraries.Add(Path.Combine(LibraryPath, "x64", "ssleay32.lib"));
		PublicAdditionalLibraries.Add(Path.Combine(LibraryPath, "x64", "alibabacloud-oss-cpp-sdk.lib"));

		PublicDelayLoadDLLs.Add(Path.Combine(LibraryPath, "x64", "libcurl.dll"));
		PublicDelayLoadDLLs.Add(Path.Combine(LibraryPath, "x64", "libeay32.dll"));
		PublicDelayLoadDLLs.Add(Path.Combine(LibraryPath, "x64", "ssleay32.dll"));
		PublicDelayLoadDLLs.Add(Path.Combine(LibraryPath, "x64", "zlibwapi.dll"));
	}
}
