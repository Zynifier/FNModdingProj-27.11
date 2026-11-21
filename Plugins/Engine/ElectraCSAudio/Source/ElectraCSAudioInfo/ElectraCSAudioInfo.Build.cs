// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ElectraCSAudioInfo : ModuleRules
{
	public ElectraCSAudioInfo(ReadOnlyTargetRules Target) : base(Target)
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
