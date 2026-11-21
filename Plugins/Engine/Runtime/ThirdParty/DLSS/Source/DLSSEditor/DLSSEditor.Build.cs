// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class DLSSEditor : ModuleRules
{
	public DLSSEditor(ReadOnlyTargetRules Target) : base(Target)
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
