// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class EOSVoiceChatFN : ModuleRules
{
	public EOSVoiceChatFN(ReadOnlyTargetRules Target) : base(Target)
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
