// Copyright Epic Games, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class FortniteConversationUI : ModuleRules
{
	public FortniteConversationUI(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		ShadowVariableWarningLevel = WarningLevel.Off;
		bUseUnity = true;

		PublicIncludePaths.AddRange(new string[]
		{
			ModuleDirectory,
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
			"CommonConversationRuntime",
			"CommonUI",
			"CommonUILegacy",
			"DynamicUI",
			"FieldNotification",
			"FortniteConversationRuntime",
			"FortniteGame",
			"FortniteUI",
			"GameplayTags",
			"UMG",
		});
	}
}
