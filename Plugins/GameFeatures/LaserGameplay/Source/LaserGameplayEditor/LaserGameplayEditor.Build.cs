// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class LaserGameplayEditor : ModuleRules
{
	public LaserGameplayEditor(ReadOnlyTargetRules Target) : base(Target)
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
