// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class AudioShapesEditor : ModuleRules
{
	public AudioShapesEditor(ReadOnlyTargetRules Target) : base(Target)
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
