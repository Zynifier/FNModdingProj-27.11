// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class FortnitePatchCheck : ModuleRules
{
	public FortnitePatchCheck(ReadOnlyTargetRules Target) : base(Target)
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
