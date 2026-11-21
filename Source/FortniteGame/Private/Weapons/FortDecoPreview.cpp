// Copyright Epic Games, Inc. All Rights Reserved.

#include "Weapons/FortDecoPreview.h"

UMaterialInstanceDynamic* AFortDecoPreview::CreatePreviewMID(UMaterialInterface* OverrideParentMaterial)
{
	return nullptr;
}

UTexture* AFortDecoPreview::GetTextureParameterValueFromMeshComponent(UMeshComponent* MeshComp, int32 ElementIdx, FName ParamName)
{
	return nullptr;
}

void AFortDecoPreview::OnBounceMotionUpdate_Implementation(float VectorScale)
{
}

void AFortDecoPreview::OnInitializeDecoPreview_Implementation(const ABuildingActor* NewBuildingActor, const UFortDecoItemDefinition* NewDecoItemDefinition)
{
}

void AFortDecoPreview::OnUpdateScale_Implementation(float Scale, const FVector& InWorldSpacePivot)
{
}

void AFortDecoPreview::OnUpdateVisuals_Implementation(float DeltaSeconds, bool bSafeToPlace)
{
}

void AFortDecoPreview::SetScalarParameterValueOnAllPreviewMIDs_Implementation(FName ParamName, float ParamValue)
{
}

void AFortDecoPreview::SetVectorParameterValueOnAllPreviewMIDs_Implementation(FName ParamName, const FLinearColor& ParamValue)
{
}
