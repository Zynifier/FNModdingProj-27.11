// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class EOSGameStreaming : ModuleRules
{
	public EOSGameStreaming(ReadOnlyTargetRules Target) : base(Target)
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
