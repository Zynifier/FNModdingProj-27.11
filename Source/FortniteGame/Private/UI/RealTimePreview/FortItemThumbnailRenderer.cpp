// Copyright Epic Games, Inc. All Rights Reserved.

#include "UI/RealTimePreview/FortItemThumbnailRenderer.h"

UMaterialInstanceDynamic* UFortItemThumbnailRenderer::GetItemPreviewMaterial()
{
	return nullptr;
}

AFortItemCaptureActor* UFortItemThumbnailRenderer::GetOrCreateCaptureActor(TSubclassOf<AFortItemCaptureActor> ThumbnailCaptureTarget)
{
	return nullptr;
}

void UFortItemThumbnailRenderer::InvalidateCapture()
{
}

void UFortItemThumbnailRenderer::SetItemDefinition(UFortItemDefinition* InItemDefinition)
{
}

void UFortItemThumbnailRenderer::UpdateItemCapture()
{
}
