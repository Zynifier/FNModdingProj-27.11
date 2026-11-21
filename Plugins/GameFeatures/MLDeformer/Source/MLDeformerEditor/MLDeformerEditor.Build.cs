// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MLDeformerEditor : ModuleRules
{
	public MLDeformerEditor(ReadOnlyTargetRules Target) : base(Target)
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
