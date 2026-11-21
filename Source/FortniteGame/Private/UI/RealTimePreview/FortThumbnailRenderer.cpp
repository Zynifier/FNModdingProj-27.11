// Copyright Epic Games, Inc. All Rights Reserved.

#include "UI/RealTimePreview/FortThumbnailRenderer.h"

void UFortThumbnailRenderer::CaptureAlphaMask()
{
}

void UFortThumbnailRenderer::CaptureDiffuse()
{
}

void UFortThumbnailRenderer::CaptureEffects()
{
}

UTextureRenderTarget2D* UFortThumbnailRenderer::GetOrCreateAlphaMaskRenderTarget()
{
	return nullptr;
}

UTextureRenderTarget2D* UFortThumbnailRenderer::GetOrCreateDiffuseRenderTarget()
{
	return nullptr;
}

UTextureRenderTarget2D* UFortThumbnailRenderer::GetOrCreateEffectsRenderTarget()
{
	return nullptr;
}

int32 UFortThumbnailRenderer::GetRendererIndex() const
{
	return int32();
}

void UFortThumbnailRenderer::ReclaimResources()
{
}

void UFortThumbnailRenderer::ReleaseResources()
{
}

void UFortThumbnailRenderer::SetAlphaMaskedActors(const TArray<AActor*>& InCaptureTarget)
{
}

void UFortThumbnailRenderer::SetCaptureTarget(AActor* InCaptureTarget)
{
}

void UFortThumbnailRenderer::SetRenderTargetSize(int32 Width, int32 Height)
{
}
