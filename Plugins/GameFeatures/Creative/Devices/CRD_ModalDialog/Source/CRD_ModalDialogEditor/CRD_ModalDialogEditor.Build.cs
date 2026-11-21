// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CRD_ModalDialogEditor : ModuleRules
{
	public CRD_ModalDialogEditor(ReadOnlyTargetRules Target) : base(Target)
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
