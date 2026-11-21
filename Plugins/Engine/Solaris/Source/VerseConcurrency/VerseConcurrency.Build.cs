// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class VerseConcurrency : ModuleRules
{
	public VerseConcurrency(ReadOnlyTargetRules Target) : base(Target)
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
