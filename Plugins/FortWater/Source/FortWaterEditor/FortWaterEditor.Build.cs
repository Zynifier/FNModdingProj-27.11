// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class FortWaterEditor : ModuleRules
{
	public FortWaterEditor(ReadOnlyTargetRules Target) : base(Target)
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
