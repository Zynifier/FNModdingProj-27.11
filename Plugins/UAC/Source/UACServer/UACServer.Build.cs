// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UACServer : ModuleRules
{
	public UACServer(ReadOnlyTargetRules Target) : base(Target)
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
