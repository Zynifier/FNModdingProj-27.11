// Copyright Epic Games, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class ValkyrieFortniteEditor : ModuleRules
{
	public ValkyrieFortniteEditor(ReadOnlyTargetRules Target) : base(Target)
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
			"DataValidation",
			"DeveloperSettings",
			"Documentation",
			"EditorConfig",
			"EditorFramework",
			"EditorSubsystem",
			"FortniteGame",
			"UnrealEd",
			"ValkyrieEditor",
		});
	}
}
