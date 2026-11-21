// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ValkyrieFortniteRpc : ModuleRules
{
	public ValkyrieFortniteRpc(ReadOnlyTargetRules Target) : base(Target)
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
