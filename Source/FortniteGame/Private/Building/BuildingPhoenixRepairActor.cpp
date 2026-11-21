// Copyright Epic Games, Inc. All Rights Reserved.

#include "Building/BuildingPhoenixRepairActor.h"

bool ABuildingPhoenixRepairActor::CanWeaponBeRepaired(UFortWorldItem* WeaponItem) const
{
	return false;
}

UFortWorldItem* ABuildingPhoenixRepairActor::GetCurrentWeapon(AFortPlayerController* FPC) const
{
	return nullptr;
}

bool ABuildingPhoenixRepairActor::GetWeaponHasDurability(UFortWorldItem* WeaponItem) const
{
	return false;
}

void ABuildingPhoenixRepairActor::GetWeaponRepairRecipe(AFortPlayerController* FPC, FRecipe& OutRecipe) const
{
}
