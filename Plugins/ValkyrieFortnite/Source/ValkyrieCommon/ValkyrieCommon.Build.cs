// Copyright Epic Games, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class ValkyrieCommon : ModuleRules
{
	public ValkyrieCommon(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		ShadowVariableWarningLevel = WarningLevel.Off;
		bUseUnity = true;

		PublicIncludePaths.AddRange(new string[]
		{
			ModuleDirectory,
			Path.Combine(ModuleDirectory, "Public"),
			Path.Combine(ModuleDirectory, "Private"),
		});

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"NetCore",
			"Slate",
			"SlateCore",
			"ConcertSyncCore",
			"ConcertTransport",
			"CoreOnline",
			"FortniteGame",
			"LinkId",
			"OnlineSubsystemUtils",
			"ReplicationGraph",
			"UnrealEngineExperimental",
			"VerseGameplayDebug",
			"VerseInterface",
			"VkEngineTypes",
		});
	}
}
