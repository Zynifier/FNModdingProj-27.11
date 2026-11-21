// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class NGXVulkanRHIPreInit : ModuleRules
{
	public NGXVulkanRHIPreInit(ReadOnlyTargetRules Target) : base(Target)
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
