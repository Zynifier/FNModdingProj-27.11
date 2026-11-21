// Copyright Epic Games, Inc. All Rights Reserved.

#include "Building/BuildingGameplayActorLockOnConsumable.h"
#include "Net/UnrealNetwork.h"

void ABuildingGameplayActorLockOnConsumable::OnRep_InteractingPawn()
{
}

void ABuildingGameplayActorLockOnConsumable::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ABuildingGameplayActorLockOnConsumable, InteractingPawn);
}
