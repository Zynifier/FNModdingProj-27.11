// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class VerseGameplay : ModuleRules
{
	public VerseGameplay(ReadOnlyTargetRules Target) : base(Target)
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
