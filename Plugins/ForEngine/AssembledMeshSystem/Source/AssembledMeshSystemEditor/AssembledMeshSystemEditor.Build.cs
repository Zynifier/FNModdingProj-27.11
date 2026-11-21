// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class AssembledMeshSystemEditor : ModuleRules
{
	public AssembledMeshSystemEditor(ReadOnlyTargetRules Target) : base(Target)
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
