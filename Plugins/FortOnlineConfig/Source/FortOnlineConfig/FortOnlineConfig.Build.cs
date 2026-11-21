// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class FortOnlineConfig : ModuleRules
{
	public FortOnlineConfig(ReadOnlyTargetRules Target) : base(Target)
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
