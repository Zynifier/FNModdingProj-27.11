// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class VkArchivePlatformFile : ModuleRules
{
	public VkArchivePlatformFile(ReadOnlyTargetRules Target) : base(Target)
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
