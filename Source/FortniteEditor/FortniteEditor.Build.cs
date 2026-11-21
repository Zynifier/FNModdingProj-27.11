// Copyright Epic Games, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class FortniteEditor : ModuleRules
{
	public FortniteEditor(ReadOnlyTargetRules Target) : base(Target)
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
			"AssetDefinition",
			"AssetTools",
			"Blutility",
			"CommonUI",
			"CosmeticsFrameworkEvents",
			"DataAssetDirectoryEditor",
			"DataValidation",
			"DeveloperSettings",
			"EditorSubsystem",
			"FieldNotification",
			"FortniteGame",
			"FortniteUI",
			"FortniteVersion",
			"GameFeatures",
			"GameSubCatalogEditor",
			"GameplayAbilities",
			"GameplayTags",
			"Kismet",
			"LiveLinkAnimationCore",
			"LiveLinkInterface",
			"ScriptableEditorWidgets",
			"StructUtils",
			"UMG",
			"UMGEditor",
			"UnrealEd",
		});
	}
}
