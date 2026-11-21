// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class DXTCompressor : ModuleRules
{
	public DXTCompressor(ReadOnlyTargetRules Target) : base(Target)
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
