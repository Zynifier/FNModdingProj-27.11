// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class VersePrint : ModuleRules
{
	public VersePrint(ReadOnlyTargetRules Target) : base(Target)
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
