// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class FortniteGameTarget : TargetRules
{
	public FortniteGameTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_4;
		bUseAdaptiveUnityBuild = false;
		ExtraModuleNames.AddRange(new string[]
		{
			"AudioModulationFortnite",
			"FabricMetasoundDataTypes",
			"FortniteDeveloperTools",
			"FortniteEngineLoadingScreen",
			"FortniteGameFramework",
			"FortniteVersion",
			"GameFeaturesFortnite",
			"IrisCoreFortnite",
			"LauncherSocialDefaults",
		});
	}
}
