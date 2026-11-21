// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SolarisDebugAdapter : ModuleRules
{
	public SolarisDebugAdapter(ReadOnlyTargetRules Target) : base(Target)
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
