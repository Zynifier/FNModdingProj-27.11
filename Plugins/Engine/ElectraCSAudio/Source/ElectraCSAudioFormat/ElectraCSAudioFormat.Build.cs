// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ElectraCSAudioFormat : ModuleRules
{
	public ElectraCSAudioFormat(ReadOnlyTargetRules Target) : base(Target)
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
