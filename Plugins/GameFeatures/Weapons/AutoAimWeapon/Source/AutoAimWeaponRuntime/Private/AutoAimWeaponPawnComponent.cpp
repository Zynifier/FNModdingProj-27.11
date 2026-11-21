// Copyright Epic Games, Inc. All Rights Reserved.

#include "AutoAimWeaponPawnComponent.h"

int32 UAutoAimWeaponPawnComponent::GetCurrentLockOnCount() const
{
	return int32();
}

float UAutoAimWeaponPawnComponent::GetLockOnProgress() const
{
	return float();
}

bool UAutoAimWeaponPawnComponent::GetLockOnTargetLocation(FVector& OutLockTargetLocation) const
{
	return false;
}

float UAutoAimWeaponPawnComponent::GetTargetToReticleDistanceNormalized() const
{
	return float();
}
