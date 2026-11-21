// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class VkArchive : ModuleRules
{
	public VkArchive(ReadOnlyTargetRules Target) : base(Target)
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
