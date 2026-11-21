// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ContentResolver : ModuleRules
{
	public ContentResolver(ReadOnlyTargetRules Target) : base(Target)
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
