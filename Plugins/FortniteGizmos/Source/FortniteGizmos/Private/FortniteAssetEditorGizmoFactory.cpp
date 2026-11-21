// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortniteAssetEditorGizmoFactory.h"

bool UFortniteAssetEditorGizmoFactory::CanBuildGizmoForSelection(FEditorModeTools* ModeTools) const
{
	return false;
}

TArray<UInteractiveGizmo*> UFortniteAssetEditorGizmoFactory::BuildGizmoForSelection(FEditorModeTools* ModeTools, UInteractiveGizmoManager* GizmoManager) const
{
	return TArray<UInteractiveGizmo*>();
}

void UFortniteAssetEditorGizmoFactory::ConfigureGridSnapping(bool bGridEnabled, bool bRotGridEnabled, const TArray<UInteractiveGizmo*>& Gizmos) const
{
}
