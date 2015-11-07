// Copyright 2015 Paddle Creek Games Inc. All Rights Reserved.
using UnrealBuildTool;

public class ProtoRpcPlugin : ModuleRules
{
    public ProtoRpcPlugin( TargetInfo Target )
    {
        PublicDependencyModuleNames.AddRange( new string[] { "Core", "Engine", "CoreUObject", "Sockets", "Networking" } );
        PrivateDependencyModuleNames.AddRange( new string[] {  } );
    }
}