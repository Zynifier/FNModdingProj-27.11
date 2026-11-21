// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class NGXD3D11RHI : ModuleRules
{
	public NGXD3D11RHI(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"CoreUObject",
			"Engine",
		});
	}
}
