// Copyright Epic Games, Inc. All Rights Reserved.

#include "TurntableItemPreviewRotator.h"

USceneComponent* ATurntableItemPreviewRotator::GetRotatingComponent() const
{
	return nullptr;
}

const FRotator& ATurntableItemPreviewRotator::GetTurntablePedestalRotationOffset() const
{
	static FRotator Dummy;
	return Dummy;
}

void ATurntableItemPreviewRotator::InitializePreview(EFrontEndCamera Camera)
{
}

void ATurntableItemPreviewRotator::LoadItemDefinition(UAthenaCosmeticItemDefinition* ItemDefinition)
{
}

void ATurntableItemPreviewRotator::LoadLoadout(FFortAthenaLoadout Loadout)
{
}

void ATurntableItemPreviewRotator::RestoreTurntableZoomLevel()
{
}

void ATurntableItemPreviewRotator::SetTurntablePedestalRotationOffset(const FRotator& InRotationOffset, bool bSnap)
{
}

void ATurntableItemPreviewRotator::SetTurntableZoomLevel(float InZoomLevel, bool bSnap)
{
}

void ATurntableItemPreviewRotator::ViewCosmeticDeveloperItemOverride()
{
}

void ATurntableItemPreviewRotator::ViewCosmeticDeveloperLoadout()
{
}
