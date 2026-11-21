// Copyright Epic Games, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class PictureInPictureUI : ModuleRules
{
	public PictureInPictureUI(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		ShadowVariableWarningLevel = WarningLevel.Off;
		bUseUnity = true;

		PublicIncludePaths.AddRange(new string[]
		{
			ModuleDirectory,
			Path.Combine(ModuleDirectory, "Private"),
		});

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"NetCore",
			"Slate",
			"SlateCore",
			"CommonUI",
			"CommonUILegacy",
			"FieldNotification",
			"FortniteGame",
			"FortniteUI",
			"GameFeatures",
			"PictureInPictureCore",
			"PictureInPictureDescriptors",
			"SubtitlesWidgets",
			"UMG",
		});
	}
}
