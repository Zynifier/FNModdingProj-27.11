// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CosmeticsFrameworkUtilities : ModuleRules
{
	public CosmeticsFrameworkUtilities(ReadOnlyTargetRules Target) : base(Target)
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
