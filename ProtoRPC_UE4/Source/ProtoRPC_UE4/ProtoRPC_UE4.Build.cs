// Copyright 2015 Paddle Creek Games Inc. All Rights Reserved.

using UnrealBuildTool;

public class ProtoRPC_UE4 : ModuleRules
{
	public ProtoRPC_UE4(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		bEnforceIWYU = true;
		bFasterWithoutUnity = true;

		Definitions.Add(string.Format("WITH_GOOGLE_PROTOBUF_BINDING={0}", 1));
		Definitions.Add(string.Format("PROTOBUF_USE_EXCEPTIONS={0}", 0));

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });
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

		PrivateIncludePaths.AddRange(
		new string[] {
				"GrpcPlugin/Public",
				"GrpcPlugin/Public/google",
				"GrpcPlugin/Public/grpc",
				"GrpcPlugin/Public/grpc++"
		}
	);
	}
}
