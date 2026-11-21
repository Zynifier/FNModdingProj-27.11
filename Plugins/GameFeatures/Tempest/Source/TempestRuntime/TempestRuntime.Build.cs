// Copyright Epic Games, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class TempestRuntime : ModuleRules
{
	public TempestRuntime(ReadOnlyTargetRules Target) : base(Target)
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
			"AIModule",
			"DataRegistry",
			"FortniteAI",
			"FortniteGame",
			"GameplayAbilities",
			"ModularGameplay",
		});
	}
}
