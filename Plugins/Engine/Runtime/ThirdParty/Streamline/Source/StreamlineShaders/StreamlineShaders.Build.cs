// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class StreamlineShaders : ModuleRules
{
	public StreamlineShaders(ReadOnlyTargetRules Target) : base(Target)
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
