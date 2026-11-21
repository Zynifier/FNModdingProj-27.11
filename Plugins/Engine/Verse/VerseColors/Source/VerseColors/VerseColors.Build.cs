// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class VerseColors : ModuleRules
{
	public VerseColors(ReadOnlyTargetRules Target) : base(Target)
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
