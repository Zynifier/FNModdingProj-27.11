// Copyright Epic Games, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class FortniteAI : ModuleRules
{
	public FortniteAI(ReadOnlyTargetRules Target) : base(Target)
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
			"AssembledMeshSystem",
			"CoreOnline",
			"Curie",
			"DataRegistry",
			"FortniteGame",
			"FortniteVersion",
			"GameplayAbilities",
			"GameplayBehaviorsModule",
			"GameplayInteractionsModule",
			"GameplayTags",
			"GameplayTasks",
			"ModularGameplay",
			"NavigationSystem",
			"Niagara",
			"PlayspaceSystem",
			"SmartObjectsModule",
			"StructUtils",
			"WorldConditions",
		});

		CircularlyReferencedDependentModules.AddRange(new string[]
		{
			"FortniteGame",
		});
	}
}
