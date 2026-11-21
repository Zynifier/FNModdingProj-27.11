// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/FortAthenaVehicleSpawner.h"

bool AFortAthenaVehicleSpawner::GetForceSpawnAlways() const
{
	return false;
}

UClass* AFortAthenaVehicleSpawner::GetVehicleClass() const
{
	return nullptr;
}

void AFortAthenaVehicleSpawner::OnConstructVehicle_Implementation(AFortAthenaVehicle* Vehicle)
{
}

void AFortAthenaVehicleSpawner::SpawnVehicle_Implementation()
{
}

AFortAthenaVehicle* AFortAthenaVehicleSpawner::SpawnVehicleWithConstruction(UClass* Class, const FTransform& Transform)
{
	return nullptr;
}

void AFortAthenaVehicleSpawner::GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const
{
}
