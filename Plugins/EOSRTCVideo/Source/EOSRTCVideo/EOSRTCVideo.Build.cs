// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class EOSRTCVideo : ModuleRules
{
	public EOSRTCVideo(ReadOnlyTargetRules Target) : base(Target)
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
