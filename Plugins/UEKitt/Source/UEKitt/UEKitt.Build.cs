// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UEKitt : ModuleRules
{
	public UEKitt(ReadOnlyTargetRules Target) : base(Target)
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
