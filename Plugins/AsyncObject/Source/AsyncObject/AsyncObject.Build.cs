// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class AsyncObject : ModuleRules
{
	public AsyncObject(ReadOnlyTargetRules Target) : base(Target)
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
