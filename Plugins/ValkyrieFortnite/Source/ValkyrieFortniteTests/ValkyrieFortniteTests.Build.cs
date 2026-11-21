// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ValkyrieFortniteTests : ModuleRules
{
	public ValkyrieFortniteTests(ReadOnlyTargetRules Target) : base(Target)
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
