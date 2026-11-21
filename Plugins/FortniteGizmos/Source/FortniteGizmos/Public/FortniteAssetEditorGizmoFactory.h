// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AssetEditorGizmoFactory.h"
#include "UObject/NoExportTypes.h"
#include "FortniteAssetEditorGizmoFactory.generated.h"

UCLASS()
class FORTNITEGIZMOS_API UFortniteAssetEditorGizmoFactory : public UObject, public IAssetEditorGizmoFactory
{
	GENERATED_BODY()

public:
	virtual bool CanBuildGizmoForSelection(FEditorModeTools* ModeTools) const override;

	virtual TArray<UInteractiveGizmo*> BuildGizmoForSelection(FEditorModeTools* ModeTools, UInteractiveGizmoManager* GizmoManager) const override;

	virtual void ConfigureGridSnapping(bool bGridEnabled, bool bRotGridEnabled, const TArray<UInteractiveGizmo*>& Gizmos) const override;

};

