// Copyright 2015 Paddle Creek Games Inc. All Rights Reserved.

using System.IO;
using System;
using UnrealBuildTool;

public class ProtoRPC_UE4 : ModuleRules
{       
  public ProtoRPC_UE4(ReadOnlyTargetRules Target) : base(Target)
  {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
        bEnforceIWYU = false;
        bFasterWithoutUnity = true;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });
        PrivateDependencyModuleNames.AddRange(new string[] { "HTTP", "zlib" });


        string LibrariesPath = Path.Combine(ModulePath, "RelWithDebInfo");

        PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "gpr.lib"));
        PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "grpc.lib"));
        PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "grpc_dll.lib"));
        PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "grpc++.lib"));
        PublicAdditionalLibraries.Add("ThirdParty/zlib/zlib-1.2.5/Lib/Win64/zlib_64.lib");
        PublicAdditionalLibraries.Add("ThirdParty/OpenSSL/1_0_2h/lib/Win64/VS2015/libeay64_static.lib");
        PublicAdditionalLibraries.Add("ThirdParty/OpenSSL/1_0_2h/lib/Win64/VS2015/ssleay64_static.lib");
        PublicDelayLoadDLLs.Add(Path.Combine(LibrariesPath, "grpc_dll.dll"));
        RuntimeDependencies.Add(new RuntimeDependency(Path.Combine(LibrariesPath, "grpc_dll.dll")));
        
        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        PrivateDependencyModuleNames.Add("OnlineSubsystem");
        PrivateDependencyModuleNames.Add("OnlineSubsystemNull");
    // if ((Target.Platform == UnrealTargetPlatform.Win32) || (Target.Platform == UnrealTargetPlatform.Win64))
    // {
    //    if (UEBuildConfiguration.bCompileSteamOSS == true)
    //    {
    //      DynamicallyLoadedModuleNames.Add("OnlineSubsystemSteam");
    //    }
    // }

    //   LoadThirdParty(Target);
  }

/*     private bool LoadThirdParty(TargetInfo Target) {
        bool isLibrarySupported = false;

        if ((Target.Platform == UnrealTargetPlatform.Win64) || (Target.Platform == UnrealTargetPlatform.Win32)) {
            isLibrarySupported = true;

            string PlatformString = (Target.Platform == UnrealTargetPlatform.Win64) ? "x64" : "x86";
            string LibrariesPath = Path.Combine(ThirdPartyPath, "GoogleProtoBuf", "Libraries");

            //PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "libprotobuf.lib"));
            //PublicDelayLoadDLLs.Add(Path.Combine(LibrariesPath, "libprotobuf.dll"));
        }

        if (isLibrarySupported) {
            // Include path
            PublicIncludePaths.Add(Path.Combine(ThirdPartyPath, "GoogleProtoBuf", "Includes"));
        }

        Definitions.Add(string.Format("WITH_GOOGLE_PROTOBUF_BINDING={0}", isLibrarySupported ? 1 : 0));
        Definitions.Add(string.Format("PROTOBUF_USE_EXCEPTIONS={0}", 0));

        return isLibrarySupported;
    }*/
 

    private string ModulePath {
        get {
            return ModuleDirectory;
        }
    }

    private string ThirdPartyPath {
        get {
            return Path.GetFullPath(Path.Combine(ModulePath, "../../ThirdParty/")); 
        }
    } 
}
