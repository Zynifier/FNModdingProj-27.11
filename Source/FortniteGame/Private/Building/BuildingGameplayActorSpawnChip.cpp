// Copyright Epic Games, Inc. All Rights Reserved.

#include "Building/BuildingGameplayActorSpawnChip.h"
#include "Net/UnrealNetwork.h"

bool ABuildingGameplayActorSpawnChip::CanHandleCleanupEvents_Implementation() const
{
	return false;
}

void ABuildingGameplayActorSpawnChip::OnDestroyPickup_Implementation()
{
}

void ABuildingGameplayActorSpawnChip::OnRep_RebootCardReplicatedState()
{
}

void ABuildingGameplayActorSpawnChip::PickUp(AFortPlayerControllerAthena* PickingUpController)
{
}

void ABuildingGameplayActorSpawnChip::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ABuildingGameplayActorSpawnChip, RebootCardReplicatedState);
	DOREPLIFETIME(ABuildingGameplayActorSpawnChip, SquadId);
}
