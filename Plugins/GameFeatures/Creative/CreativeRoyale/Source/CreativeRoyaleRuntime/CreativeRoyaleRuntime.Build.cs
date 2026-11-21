// Copyright Epic Games, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class CreativeRoyaleRuntime : ModuleRules
{
	public CreativeRoyaleRuntime(ReadOnlyTargetRules Target) : base(Target)
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
			"CoreOnline",
			"DataRegistry",
			"FortniteAI",
			"FortniteGame",
			"GameFeatures",
			"GameplayAbilities",
			"GameplayEventRouter",
			"GameplayTags",
			"LinkId",
			"ModularGameplay",
			"PlayspaceSystem",
		});
	}
}
