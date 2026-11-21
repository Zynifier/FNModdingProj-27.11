// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class StreamlineD3D12RHI : ModuleRules
{
	public StreamlineD3D12RHI(ReadOnlyTargetRules Target) : base(Target)
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
