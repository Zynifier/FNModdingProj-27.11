// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class EOSMediaPlayer : ModuleRules
{
	public EOSMediaPlayer(ReadOnlyTargetRules Target) : base(Target)
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
