// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class DLSSUtility : ModuleRules
{
	public DLSSUtility(ReadOnlyTargetRules Target) : base(Target)
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
