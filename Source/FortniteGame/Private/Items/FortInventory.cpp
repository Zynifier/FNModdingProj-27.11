// Copyright Epic Games, Inc. All Rights Reserved.

#include "Items/FortInventory.h"
#include "Net/UnrealNetwork.h"

void AFortInventory::HandleInventoryLocalUpdate()
{
}

void AFortInventory::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortInventory, InventoryType);
	DOREPLIFETIME(AFortInventory, Inventory);
	DOREPLIFETIME(AFortInventory, ReplayPawn);
}
