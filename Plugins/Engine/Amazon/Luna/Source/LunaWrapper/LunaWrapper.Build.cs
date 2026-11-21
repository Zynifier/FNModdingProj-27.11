// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class LunaWrapper : ModuleRules
{
	public LunaWrapper(ReadOnlyTargetRules Target) : base(Target)
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
