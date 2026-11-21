// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class StreamlineD3D11RHI : ModuleRules
{
	public StreamlineD3D11RHI(ReadOnlyTargetRules Target) : base(Target)
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
