// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CosmeticsEarlyQRPTests : ModuleRules
{
	public CosmeticsEarlyQRPTests(ReadOnlyTargetRules Target) : base(Target)
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
