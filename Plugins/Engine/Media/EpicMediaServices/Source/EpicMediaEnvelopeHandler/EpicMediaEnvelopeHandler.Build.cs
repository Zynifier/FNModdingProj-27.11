// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class EpicMediaEnvelopeHandler : ModuleRules
{
	public EpicMediaEnvelopeHandler(ReadOnlyTargetRules Target) : base(Target)
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
