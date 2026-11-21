// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class EOSGameClips : ModuleRules
{
	public EOSGameClips(ReadOnlyTargetRules Target) : base(Target)
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
