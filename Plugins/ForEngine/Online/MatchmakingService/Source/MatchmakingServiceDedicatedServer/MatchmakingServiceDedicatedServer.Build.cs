// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MatchmakingServiceDedicatedServer : ModuleRules
{
	public MatchmakingServiceDedicatedServer(ReadOnlyTargetRules Target) : base(Target)
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
