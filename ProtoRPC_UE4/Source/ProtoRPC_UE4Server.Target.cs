// Copyright 2015 Paddle Creek ProtoRPC_UE4s Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;
 
public class ProtoRPC_UE4ServerTarget : TargetRules
{
    public ProtoRPC_UE4ServerTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Server;

		LaunchModuleName = "ProtoRPC_UE4";
	}
}