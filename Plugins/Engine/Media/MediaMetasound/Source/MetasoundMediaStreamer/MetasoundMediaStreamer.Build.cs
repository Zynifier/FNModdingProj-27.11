// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MetasoundMediaStreamer : ModuleRules
{
	public MetasoundMediaStreamer(ReadOnlyTargetRules Target) : base(Target)
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
