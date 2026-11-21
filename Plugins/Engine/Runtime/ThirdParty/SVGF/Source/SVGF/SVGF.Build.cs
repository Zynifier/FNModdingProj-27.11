// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SVGF : ModuleRules
{
	public SVGF(ReadOnlyTargetRules Target) : base(Target)
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
