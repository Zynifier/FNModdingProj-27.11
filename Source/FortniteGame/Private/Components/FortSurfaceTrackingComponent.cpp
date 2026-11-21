// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/FortSurfaceTrackingComponent.h"

EPhysicalSurface UFortSurfaceTrackingComponent::GetCurrentSurfaceType() const
{
	return EPhysicalSurface();
}

void UFortSurfaceTrackingComponent::HandleMovementModeChanged(ACharacter* Character, EMovementMode PrevMovementMode, uint8 PreviousCustomMode)
{
}

void UFortSurfaceTrackingComponent::UpdateSurfaceType(bool bAlwaysNotify, bool bLookForGround)
{
}
