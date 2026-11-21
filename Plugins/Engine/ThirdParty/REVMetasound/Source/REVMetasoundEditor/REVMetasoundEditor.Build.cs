// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class REVMetasoundEditor : ModuleRules
{
	public REVMetasoundEditor(ReadOnlyTargetRules Target) : base(Target)
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
