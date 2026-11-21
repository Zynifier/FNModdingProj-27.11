// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class VkEditorContentService : ModuleRules
{
	public VkEditorContentService(ReadOnlyTargetRules Target) : base(Target)
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
