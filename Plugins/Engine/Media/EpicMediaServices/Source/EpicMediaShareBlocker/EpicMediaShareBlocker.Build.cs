// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class EpicMediaShareBlocker : ModuleRules
{
	public EpicMediaShareBlocker(ReadOnlyTargetRules Target) : base(Target)
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
