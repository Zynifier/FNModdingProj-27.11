// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CRContentServiceProvider : ModuleRules
{
	public CRContentServiceProvider(ReadOnlyTargetRules Target) : base(Target)
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
