// Copyright Epic Games, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class ValkyrieEditor : ModuleRules
{
	public ValkyrieEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		ShadowVariableWarningLevel = WarningLevel.Off;
		bUseUnity = true;

		PublicIncludePaths.AddRange(new string[]
		{
			ModuleDirectory,
			Path.Combine(ModuleDirectory, "Public"),
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
			"DataValidation",
			"DeveloperSettings",
			"EditorConfig",
			"EditorFramework",
			"EditorSubsystem",
			"EpicCMSUIFramework",
			"FieldNotification",
			"GameFeatures",
			"JsonUtilities",
			"LinkId",
			"Localization",
			"UMG",
			"UnrealEd",
			"VkEngineTypes",
		});
	}
}
