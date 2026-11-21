// Copyright Epic Games, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class RockVehicleRuntime : ModuleRules
{
	public RockVehicleRuntime(ReadOnlyTargetRules Target) : base(Target)
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
			"AnimGraphRuntime",
			"AudioMotorSim",
			"Curie",
			"DataRegistry",
			"FortniteGame",
			"GameplayAbilities",
			"GameplayTags",
			"ModularGameplay",
			"Niagara",
			"PhysicsCore",
			"SrirachaRanch",
			"VehicleAudioRuntime",
		});
	}
}
