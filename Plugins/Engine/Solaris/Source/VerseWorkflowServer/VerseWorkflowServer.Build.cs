// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class VerseWorkflowServer : ModuleRules
{
	public VerseWorkflowServer(ReadOnlyTargetRules Target) : base(Target)
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
