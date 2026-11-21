// Copyright Epic Games, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class FabricRuntime : ModuleRules
{
	public FabricRuntime(ReadOnlyTargetRules Target) : base(Target)
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
			"AIModule",
			"AudioExtensions",
			"CoreOnline",
			"FMCoreRuntime",
			"FabricMetasoundDataTypes",
			"FabricUI",
			"FortniteGame",
			"GameplayAbilities",
			"GameplayMessages",
			"GameplayTags",
			"HarmonixDsp",
			"HarmonixMetasound",
			"HarmonixMidi",
			"MetasoundEngine",
			"MetasoundFrontend",
			"ModularGameplay",
			"PlayspaceSystem",
		});
	}
}
