// Copyright 2015 Paddle Creek Games Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class ProtoRPC_UE4Target : TargetRules
{
	public ProtoRPC_UE4Target(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		LaunchModuleName = "ProtoRPC_UE4";
	}
}
