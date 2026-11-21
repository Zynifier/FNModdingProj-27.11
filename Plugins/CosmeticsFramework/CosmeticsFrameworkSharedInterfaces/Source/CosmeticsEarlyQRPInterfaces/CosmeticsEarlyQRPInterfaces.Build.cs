// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CosmeticsEarlyQRPInterfaces : ModuleRules
{
	public CosmeticsEarlyQRPInterfaces(ReadOnlyTargetRules Target) : base(Target)
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
