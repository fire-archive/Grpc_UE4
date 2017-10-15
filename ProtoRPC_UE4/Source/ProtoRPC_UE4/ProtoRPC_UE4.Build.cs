// Copyright 2015 Paddle Creek Games Inc. All Rights Reserved.

using UnrealBuildTool;

public class ProtoRPC_UE4 : ModuleRules
{
	public ProtoRPC_UE4(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		bEnforceIWYU = true;
		bFasterWithoutUnity = true;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "GrpcPlugin" });
		PrivateDependencyModuleNames.AddRange(new string[] { "HTTP" });

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

}
