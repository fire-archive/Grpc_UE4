// Copyright 2015 Paddle Creek Games Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class ProtoRPC_UE4EditorTarget : TargetRules
{
	public ProtoRPC_UE4EditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		LaunchModuleName = "ProtoRPC_UE4";
	}
}
