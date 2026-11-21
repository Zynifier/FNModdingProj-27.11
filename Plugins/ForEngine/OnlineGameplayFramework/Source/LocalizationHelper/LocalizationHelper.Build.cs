// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class LocalizationHelper : ModuleRules
{
	public LocalizationHelper(ReadOnlyTargetRules Target) : base(Target)
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
