// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class EOSGameClipsPlugin : ModuleRules
{
	public EOSGameClipsPlugin(ReadOnlyTargetRules Target) : base(Target)
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
