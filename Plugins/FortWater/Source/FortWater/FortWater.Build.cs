// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class FortWater : ModuleRules
{
	public FortWater(ReadOnlyTargetRules Target) : base(Target)
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
