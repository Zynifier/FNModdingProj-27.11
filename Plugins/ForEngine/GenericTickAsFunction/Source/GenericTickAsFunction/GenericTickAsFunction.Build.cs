// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GenericTickAsFunction : ModuleRules
{
	public GenericTickAsFunction(ReadOnlyTargetRules Target) : base(Target)
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
