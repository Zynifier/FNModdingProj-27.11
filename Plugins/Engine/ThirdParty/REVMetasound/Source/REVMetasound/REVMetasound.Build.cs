// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class REVMetasound : ModuleRules
{
	public REVMetasound(ReadOnlyTargetRules Target) : base(Target)
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
