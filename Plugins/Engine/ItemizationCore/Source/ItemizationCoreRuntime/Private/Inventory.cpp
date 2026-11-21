// Copyright Epic Games, Inc. All Rights Reserved.

#include "Inventory.h"
#include "Net/UnrealNetwork.h"

void UInventory::OnRep_InventoryID()
{
}

void UInventory::OnRep_InventoryMaxStackSizeOverride()
{
}

void UInventory::OnRep_InventoryTotalSlotsOverride()
{
}

void UInventory::OnRep_ItemData()
{
}

void UInventory::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UInventory, InventoryDefinition);
	DOREPLIFETIME(UInventory, InventoryID);
	DOREPLIFETIME(UInventory, ItemEntryData);
	DOREPLIFETIME(UInventory, AttributeData);
	DOREPLIFETIME(UInventory, InventoryTotalSlotsOverride);
	DOREPLIFETIME(UInventory, InventoryMaxStackSizeOverride);
}
