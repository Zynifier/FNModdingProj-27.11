// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CosmeticTurntableUI : ModuleRules
{
	public CosmeticTurntableUI(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"CoreUObject",
			"Engine",
		});
	}
}
