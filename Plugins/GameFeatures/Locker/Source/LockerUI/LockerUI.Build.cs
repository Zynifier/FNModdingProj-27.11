// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class LockerUI : ModuleRules
{
	public LockerUI(ReadOnlyTargetRules Target) : base(Target)
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
