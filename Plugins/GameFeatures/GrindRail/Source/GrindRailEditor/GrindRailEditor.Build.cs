// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GrindRailEditor : ModuleRules
{
	public GrindRailEditor(ReadOnlyTargetRules Target) : base(Target)
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
