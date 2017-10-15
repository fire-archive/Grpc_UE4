// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

using System.IO;
using System;
using UnrealBuildTool;

public class GrpcPlugin : ModuleRules
{
	public GrpcPlugin(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		bEnforceIWYU = false;
		bFasterWithoutUnity = true;

		string LibrariesPath = Path.Combine(ModulePath, "RelWithDebInfo");

		//PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "gpr.lib"));
		//PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "grpc.lib"));
		//PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "grpc++.lib"));

		//PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "grpc_dll.lib"));
		//PublicAdditionalLibraries.Add("ThirdParty/zlib/zlib-1.2.5/Lib/Win64/zlib_64.lib");
		//PublicAdditionalLibraries.Add("ThirdParty/OpenSSL/1_0_2h/lib/Win64/VS2015/libeay64_static.lib");
		//PublicAdditionalLibraries.Add("ThirdParty/OpenSSL/1_0_2h/lib/Win64/VS2015/ssleay64_static.lib");
		//PublicDelayLoadDLLs.Add(Path.Combine(LibrariesPath, "grpc_dll.dll"));
		//RuntimeDependencies.Add(new RuntimeDependency(Path.Combine(LibrariesPath, "grpc_dll.dll")));

		PublicIncludePaths.AddRange(
			new string[] {
				"GrpcPlugin/Public",
				"GrpcPlugin/Public/google",
				"GrpcPlugin/Public/grpc",
				"GrpcPlugin/Public/grpc++"
				// ... add public include paths required here ...
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				"GrpcPlugin/Private",
				// ... add other private include paths required here ...
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"zlib",
				"OpenSSL"
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}

	private string ModulePath
	{
		get
		{
			return ModuleDirectory;
		}
	}

	private string ThirdPartyPath
	{
		get
		{
			return Path.GetFullPath(Path.Combine(ModulePath, "../../ThirdParty/"));
		}
	}
}
