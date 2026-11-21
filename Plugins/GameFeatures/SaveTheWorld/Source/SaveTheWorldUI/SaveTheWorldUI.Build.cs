// Copyright Epic Games, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class SaveTheWorldUI : ModuleRules
{
	public SaveTheWorldUI(ReadOnlyTargetRules Target) : base(Target)
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
			"BlueprintContext",
			"CommonInput",
			"CommonUI",
			"CommonUILegacy",
			"CoreOnline",
			"FieldNotification",
			"FortniteGame",
			"FortniteUI",
			"GameFeatures",
			"GameplayAbilities",
			"GameplayTags",
			"MediaAssets",
			"SaveTheWorldRuntime",
			"UMG",
		});
	}
}
