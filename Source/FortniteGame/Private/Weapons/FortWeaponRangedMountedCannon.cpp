// Copyright Epic Games, Inc. All Rights Reserved.

#include "Weapons/FortWeaponRangedMountedCannon.h"

USkeletalMeshComponent* AFortWeaponRangedMountedCannon::GetVehicleSkeletalMesh() const
{
	return nullptr;
}

void AFortWeaponRangedMountedCannon::ServerFireActorInCannon_Implementation(const FVector LaunchDir)
{
}
bool AFortWeaponRangedMountedCannon::ServerFireActorInCannon_Validate(const FVector LaunchDir)
{
	return true;
}
