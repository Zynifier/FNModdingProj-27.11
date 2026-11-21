// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class VerseColorsEditor : ModuleRules
{
	public VerseColorsEditor(ReadOnlyTargetRules Target) : base(Target)
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
