// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class OnlineServicesMcp : ModuleRules
{
	public OnlineServicesMcp(ReadOnlyTargetRules Target) : base(Target)
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
