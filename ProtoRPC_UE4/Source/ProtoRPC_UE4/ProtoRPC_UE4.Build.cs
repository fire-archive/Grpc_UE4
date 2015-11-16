// Copyright 2015 Paddle Creek Games Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class ProtoRPC_UE4 : ModuleRules
{
	public ProtoRPC_UE4(TargetInfo Target)
	{
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "ProtoRpcPlugin" });
		//PrivateIncludePathModulesNames.AddRange(new string[] { "HTTP" });
		PrivateDependencyModuleNames.AddRange(new string[] { "HTTP" });

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");
		// if ((Target.Platform == UnrealTargetPlatform.Win32) || (Target.Platform == UnrealTargetPlatform.Win64))
		// {
		//		if (UEBuildConfiguration.bCompileSteamOSS == true)
		//		{
		//			DynamicallyLoadedModuleNames.Add("OnlineSubsystemSteam");
		//		}
		// }
        LoadThirdParty(Target);
	}

    private bool LoadThirdParty(TargetInfo Target) {
        bool isLibrarySupported = false;

        if ((Target.Platform == UnrealTargetPlatform.Win64) || (Target.Platform == UnrealTargetPlatform.Win32)) {
            isLibrarySupported = true;

            string PlatformString = (Target.Platform == UnrealTargetPlatform.Win64) ? "x64" : "x86";
            string LibrariesPath = Path.Combine(ThirdPartyPath, "GoogleProtoBuf", "Libraries");

            PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "libprotobuf.lib"));
            PublicDelayLoadDLLs.Add(Path.Combine(LibrariesPath, "libprotobuf.dll"));
        }

        if (isLibrarySupported) {
            // Include path
            PublicIncludePaths.Add(Path.Combine(ThirdPartyPath, "GoogleProtoBuf", "Includes"));
        }

        Definitions.Add(string.Format("WITH_GOOGLE_PROTOBUF_BINDING={0}", isLibrarySupported ? 1 : 0));

        return isLibrarySupported;
    }
 

    private string ModulePath {
        get {
            return Path.GetDirectoryName(RulesCompiler.GetModuleFilename(this.GetType().Name)); 
        }
    }

    private string ThirdPartyPath {
        get {
            return Path.GetFullPath(Path.Combine(ModulePath, "../../ThirdParty/")); 
        }
    }
}
