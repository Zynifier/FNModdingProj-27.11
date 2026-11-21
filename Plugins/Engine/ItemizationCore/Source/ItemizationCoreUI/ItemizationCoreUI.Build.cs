// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ItemizationCoreUI : ModuleRules
{
	public ItemizationCoreUI(ReadOnlyTargetRules Target) : base(Target)
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
