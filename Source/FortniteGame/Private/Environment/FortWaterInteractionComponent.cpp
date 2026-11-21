// Copyright Epic Games, Inc. All Rights Reserved.

#include "Environment/FortWaterInteractionComponent.h"

AFortWaterBodyActor* UFortWaterInteractionComponent::GetCurrentWaterBody() const
{
	return nullptr;
}

void UFortWaterInteractionComponent::GetLastWaterSurfaceInfo(FVector& WaterPlaneLocation, FVector& WaterPlaneNormal, FVector& WaterSurfacePosition, float& WaterDepth, int32& WaterBodyIdx, FVector& WaterVelocity)
{
}

bool UFortWaterInteractionComponent::IsEnabled() const
{
	return false;
}

bool UFortWaterInteractionComponent::IsInWater() const
{
	return false;
}
