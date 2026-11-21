// Copyright Epic Games, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class AnimationLayeringEditor : ModuleRules
{
	public AnimationLayeringEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		ShadowVariableWarningLevel = WarningLevel.Off;
		bUseUnity = true;

		PublicIncludePaths.AddRange(new string[]
		{
			ModuleDirectory,
			Path.Combine(ModuleDirectory, "Public"),
		});

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"NetCore",
			"Slate",
			"SlateCore",
			"AnimGraph",
			"AnimGraphRuntime",
			"AnimationBlueprintLibrary",
			"AnimationLayeringRuntime",
			"AnimationModifierLibrary",
			"AnimationModifiers",
			"BlueprintGraph",
		});
	}
}
