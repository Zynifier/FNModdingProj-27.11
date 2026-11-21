// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class VerseMessageServer : ModuleRules
{
	public VerseMessageServer(ReadOnlyTargetRules Target) : base(Target)
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
