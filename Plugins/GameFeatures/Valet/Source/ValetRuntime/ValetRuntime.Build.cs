// Copyright Epic Games, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class ValetRuntime : ModuleRules
{
	public ValetRuntime(ReadOnlyTargetRules Target) : base(Target)
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
			"Curie",
			"DataRegistry",
			"FortniteGame",
			"GameFeatures",
			"GameplayAbilities",
			"GameplayCameras",
			"GameplayTags",
			"IrisCore",
			"ModularGameplay",
			"MotoSynth",
			"Niagara",
			"PhysicsCore",
		});
	}
}
