// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ValkyrieRuntimeServer : ModuleRules
{
	public ValkyrieRuntimeServer(ReadOnlyTargetRules Target) : base(Target)
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
