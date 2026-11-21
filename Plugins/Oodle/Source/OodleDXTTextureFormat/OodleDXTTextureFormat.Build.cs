// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class OodleDXTTextureFormat : ModuleRules
{
	public OodleDXTTextureFormat(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"CoreUObject",
			"Engine",
		});

		PrivateIncludePathModuleNames.Add("TextureFormat");
	}
}
