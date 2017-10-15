// Copyright 2015 Paddle Creek ProtoRPC_UE4s Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;
 
public class ProtoRPC_UE4ServerTarget : TargetRules
{
    public ProtoRPC_UE4ServerTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Server;
    }
 
    //
    // TargetRules interface.
    //
    public override void SetupBinaries(
        TargetInfo Target,
        ref List<UEBuildBinaryConfiguration> OutBuildBinaryConfigurations,
        ref List<string> OutExtraModuleNames
        )
    {
        base.SetupBinaries(Target, ref OutBuildBinaryConfigurations, ref OutExtraModuleNames);
        OutExtraModuleNames.Add("ProtoRPC_UE4");
    }
}