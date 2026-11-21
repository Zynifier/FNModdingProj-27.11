// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class FortExternalRpcFramework : ModuleRules
{
	public FortExternalRpcFramework(ReadOnlyTargetRules Target) : base(Target)
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
