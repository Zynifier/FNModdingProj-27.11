// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MotdUI : ModuleRules
{
	public MotdUI(ReadOnlyTargetRules Target) : base(Target)
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
