// Copyright Epic Games, Inc. All Rights Reserved.

#include "Environment/FortWaterBodyCubeVolumeComponent.h"

AFortWaterBodyCubeVolume* UFortWaterBodyCubeVolumeComponent::GetFortWaterBodyCubeVolume() const
{
	return nullptr;
}

void UFortWaterBodyCubeVolumeComponent::GetVolumeBounds(FVector& Min, FVector& Max) const
{
}

FVector UFortWaterBodyCubeVolumeComponent::GetVolumeCenter() const
{
	return FVector();
}

FVector UFortWaterBodyCubeVolumeComponent::GetVolumeExtent() const
{
	return FVector();
}

FVector UFortWaterBodyCubeVolumeComponent::GetVolumeExtentFortCell() const
{
	return FVector();
}

FVector UFortWaterBodyCubeVolumeComponent::GetVolumeExtentScaled() const
{
	return FVector();
}

FVector UFortWaterBodyCubeVolumeComponent::GetVolumeExtentScaledFortCell() const
{
	return FVector();
}

FVector UFortWaterBodyCubeVolumeComponent::GetVolumeMax() const
{
	return FVector();
}

FVector UFortWaterBodyCubeVolumeComponent::GetVolumeMin() const
{
	return FVector();
}

FVector UFortWaterBodyCubeVolumeComponent::GetVolumeSize() const
{
	return FVector();
}

FVector UFortWaterBodyCubeVolumeComponent::GetVolumeSizeFortCell() const
{
	return FVector();
}

FVector UFortWaterBodyCubeVolumeComponent::GetVolumeSizeScaled() const
{
	return FVector();
}

FVector UFortWaterBodyCubeVolumeComponent::GetVolumeSizeScaledFortCell() const
{
	return FVector();
}

void UFortWaterBodyCubeVolumeComponent::GetWaterCubeBounds(FVector& Min, FVector& Max) const
{
}

FVector UFortWaterBodyCubeVolumeComponent::GetWaterCubeCenter() const
{
	return FVector();
}

FVector UFortWaterBodyCubeVolumeComponent::GetWaterCubeExtent() const
{
	return FVector();
}

FVector UFortWaterBodyCubeVolumeComponent::GetWaterCubeExtentFortCell() const
{
	return FVector();
}

FVector UFortWaterBodyCubeVolumeComponent::GetWaterCubeExtentScaled() const
{
	return FVector();
}

FVector UFortWaterBodyCubeVolumeComponent::GetWaterCubeExtentScaledFortCell() const
{
	return FVector();
}

FVector UFortWaterBodyCubeVolumeComponent::GetWaterCubeMax() const
{
	return FVector();
}

UStaticMeshComponent* UFortWaterBodyCubeVolumeComponent::GetWaterCubeMesh() const
{
	return nullptr;
}

FVector UFortWaterBodyCubeVolumeComponent::GetWaterCubeMin() const
{
	return FVector();
}

FVector UFortWaterBodyCubeVolumeComponent::GetWaterCubeSize() const
{
	return FVector();
}

FVector UFortWaterBodyCubeVolumeComponent::GetWaterCubeSizeFortCell() const
{
	return FVector();
}

FVector UFortWaterBodyCubeVolumeComponent::GetWaterCubeSizeScaled() const
{
	return FVector();
}

FVector UFortWaterBodyCubeVolumeComponent::GetWaterCubeSizeScaledFortCell() const
{
	return FVector();
}

FVector UFortWaterBodyCubeVolumeComponent::GetWaterMeshCubeRescaleToUnitCube() const
{
	return FVector();
}

FVector UFortWaterBodyCubeVolumeComponent::GetWaterRatio() const
{
	return FVector();
}

bool UFortWaterBodyCubeVolumeComponent::IsNullExtent() const
{
	return false;
}

bool UFortWaterBodyCubeVolumeComponent::IsVolumeEmptied() const
{
	return false;
}

bool UFortWaterBodyCubeVolumeComponent::IsVolumeFilled() const
{
	return false;
}

bool UFortWaterBodyCubeVolumeComponent::IsWaterCollisionEnabled() const
{
	return false;
}

bool UFortWaterBodyCubeVolumeComponent::IsWaterVisibilityEnabled() const
{
	return false;
}

bool UFortWaterBodyCubeVolumeComponent::IsWaterVisible() const
{
	return false;
}

void UFortWaterBodyCubeVolumeComponent::OnVolumeExtentChanged_Implementation(const FVector& LastVolumeExtent)
{
}

void UFortWaterBodyCubeVolumeComponent::OnWaterRatioChanged_Implementation(const FVector& LastWaterRatio)
{
}

void UFortWaterBodyCubeVolumeComponent::SetVolumeExtent(const FVector& NewExtent)
{
}

void UFortWaterBodyCubeVolumeComponent::SetVolumeExtentByFortCell(const FVector& NewFortCellExtent)
{
}

void UFortWaterBodyCubeVolumeComponent::SetVolumeSize(const FVector& NewSize)
{
}

void UFortWaterBodyCubeVolumeComponent::SetVolumeSizeByFortCell(const FVector& NewFortCellSize)
{
}

void UFortWaterBodyCubeVolumeComponent::SetWaterCollisionEnabled(bool bNewIsCollisionEnabled)
{
}

void UFortWaterBodyCubeVolumeComponent::SetWaterRatio(const FVector& NewWaterRatio)
{
}

void UFortWaterBodyCubeVolumeComponent::SetWaterVisibiltyEnabled(bool bNewIsWaterVisibilityEnabled)
{
}

bool UFortWaterBodyCubeVolumeComponent::ShouldWaterBeVisible() const
{
	return false;
}

bool UFortWaterBodyCubeVolumeComponent::ShouldWaterCollide() const
{
	return false;
}

void UFortWaterBodyCubeVolumeComponent::UpdateParametersOnUnderwaterPostProcess()
{
}

void UFortWaterBodyCubeVolumeComponent::UpdateWaterMeshCube()
{
}

void UFortWaterBodyCubeVolumeComponent::UpdateWaterSpline()
{
}
