// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class FabricMetasound : ModuleRules
{
	public FabricMetasound(ReadOnlyTargetRules Target) : base(Target)
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
