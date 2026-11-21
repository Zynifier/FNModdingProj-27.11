// Copyright Epic Games, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class FortniteAIServer : ModuleRules
{
	public FortniteAIServer(ReadOnlyTargetRules Target) : base(Target)
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
			"ContextualAnimation",
			"DataRegistry",
			"FortniteAI",
			"FortniteGame",
			"GameFeatures",
			"GameplayAbilities",
			"GameplayInteractionsModule",
			"GameplayTags",
			"GameplayTasks",
			"ModularGameplay",
			"NavigationSystem",
			"PhysicsCore",
			"SmartObjectsModule",
			"StateTreeModule",
			"StructUtils",
			"WorldConditions",
		});
	}
}
