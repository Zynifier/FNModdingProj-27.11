// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class VerseAssetsEditor : ModuleRules
{
	public VerseAssetsEditor(ReadOnlyTargetRules Target) : base(Target)
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
