// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class LauncherSocial : ModuleRules
{
	public LauncherSocial(ReadOnlyTargetRules Target) : base(Target)
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
