// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class FortniteTargetPlatform : ModuleRules
{
	public FortniteTargetPlatform(ReadOnlyTargetRules Target) : base(Target)
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
