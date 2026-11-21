// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/FortWeaponComponent_Swinging.h"

void UFortWeaponComponent_Swinging::CancelForgivenessTimer()
{
}

void UFortWeaponComponent_Swinging::ForceEndForgivenessTimer()
{
}

bool UFortWeaponComponent_Swinging::IsActorPullable(const AActor* Actor) const
{
	return false;
}

bool UFortWeaponComponent_Swinging::IsForgivenessTimerActive() const
{
	return false;
}

void UFortWeaponComponent_Swinging::OnSingleFire()
{
}

void UFortWeaponComponent_Swinging::OnSpawnedProjectile()
{
}

void UFortWeaponComponent_Swinging::ServerSetTargetingResults_Implementation(const FHitResult& HitResult, const bool bHitSomething)
{
}

void UFortWeaponComponent_Swinging::SetForgivenessTimer(const float NewTimer)
{
}
