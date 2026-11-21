// Copyright Epic Games, Inc. All Rights Reserved.

#include "Building/BuildingCustomizableSpawnContainer.h"
#include "Net/UnrealNetwork.h"

void ABuildingCustomizableSpawnContainer::ValidateSpawnItems()
{
}

void ABuildingCustomizableSpawnContainer::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ABuildingCustomizableSpawnContainer, SpawnItems);
}
