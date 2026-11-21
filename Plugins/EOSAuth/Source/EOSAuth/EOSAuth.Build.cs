// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class EOSAuth : ModuleRules
{
	public EOSAuth(ReadOnlyTargetRules Target) : base(Target)
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
