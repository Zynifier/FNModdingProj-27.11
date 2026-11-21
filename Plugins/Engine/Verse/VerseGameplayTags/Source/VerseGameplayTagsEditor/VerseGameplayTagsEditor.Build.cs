// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class VerseGameplayTagsEditor : ModuleRules
{
	public VerseGameplayTagsEditor(ReadOnlyTargetRules Target) : base(Target)
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
