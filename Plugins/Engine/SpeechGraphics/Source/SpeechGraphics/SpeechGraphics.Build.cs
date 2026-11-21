// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SpeechGraphics : ModuleRules
{
	public SpeechGraphics(ReadOnlyTargetRules Target) : base(Target)
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
