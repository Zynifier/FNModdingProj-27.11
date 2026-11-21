// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CRLocalProvider : ModuleRules
{
	public CRLocalProvider(ReadOnlyTargetRules Target) : base(Target)
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
