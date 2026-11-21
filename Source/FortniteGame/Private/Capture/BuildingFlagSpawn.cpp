// Copyright Epic Games, Inc. All Rights Reserved.

#include "Capture/BuildingFlagSpawn.h"

bool ABuildingFlagSpawn::IsSpawnedObjectAwayFromBase() const
{
	return false;
}

void ABuildingFlagSpawn::OnCarriedObjectAttachedEvent_Implementation()
{
}

void ABuildingFlagSpawn::OnCarriedObjectDetachedEvent_Implementation()
{
}

void ABuildingFlagSpawn::SpawnCarriedObject()
{
}
