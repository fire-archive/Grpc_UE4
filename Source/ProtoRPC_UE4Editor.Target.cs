// Copyright 2015 Paddle Creek Games Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class ProtoRPC_UE4EditorTarget : TargetRules
{
	public ProtoRPC_UE4EditorTarget(TargetInfo Target)
	{
		Type = TargetType.Editor;
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
		OutExtraModuleNames.AddRange( new string[] { "ProtoRPC_UE4" } );
	}
}
