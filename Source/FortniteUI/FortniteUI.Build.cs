// Copyright Epic Games, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class FortniteUI : ModuleRules
{
	public FortniteUI(ReadOnlyTargetRules Target) : base(Target)
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
			"AudioMixer",
			"BlueprintContext",
			"CommonInput",
			"CommonUI",
			"CommonUILegacy",
			"CoreOnline",
			"Curie",
			"DataRegistry",
			"DynamicUI",
			"EnhancedInput",
			"EpicCMSUIFramework",
			"EpicMediaBasePlayer",
			"FieldNotification",
			"FortniteAI",
			"FortniteGame",
			"FortniteVersion",
			"GameFeatures",
			"GameSubCatalog",
			"GameplayAbilities",
			"GameplayMessages",
			"GameplayTags",
			"Hotfix",
			"InputCore",
			"JsonUtilities",
			"LauncherSocialDefaults",
			"LauncherSocialTypes",
			"LevelSequence",
			"LinkEntry",
			"LinkId",
			"McpProfileSys",
			"MediaAssets",
			"MediaUtils",
			"ModelViewViewModel",
			"MotdOverride",
			"Niagara",
			"OnlineSubsystemMcp",
			"Overlay",
			"Paper2D",
			"Party",
			"SocialUMG",
			"SubtitlesWidgets",
			"UEKittTexture",
			"UMG",
		});
	}
}
