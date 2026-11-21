// Copyright Epic Games, Inc. All Rights Reserved.

#include "InventoryCollection.h"

bool AInventoryCollection::EquipItem(const FGuid& ItemEntryID)
{
	return false;
}

bool AInventoryCollection::GetAllInventoriesInCollection(TArray<FGuid>& OutInventoryIDList) const
{
	return false;
}

bool AInventoryCollection::GetAllItemsInInventory(const FGuid& TargetInventoryID, TArray<FGuid>& OutItemEntryIDList) const
{
	return false;
}

TArray<FGuid> AInventoryCollection::GetInventoriesWithInventoryDefinition(const UInventoryDefinition* InventoryDefinition) const
{
	return TArray<FGuid>();
}

const UInventoryDefinition* AInventoryCollection::GetInventoryDefinition(const FGuid& TargetInventoryID) const
{
	return nullptr;
}

const FText& AInventoryCollection::GetInventoryName(const FGuid& TargetInventoryID) const
{
	static FText Dummy;
	return Dummy;
}

int64 AInventoryCollection::GetItemAmount(const UItemDefinitionBase* ItemDefinition) const
{
	return int64();
}

int64 AInventoryCollection::GetItemAmountFromInventory(const UItemDefinitionBase* ItemDefinition, const FGuid& TargetInventoryID) const
{
	return int64();
}

const UItemDefinitionBase* AInventoryCollection::GetItemDefinition(const FGuid& TargetInventoryID, const FGuid& ItemEntryID) const
{
	return nullptr;
}

int64 AInventoryCollection::GetItemIntAttribute(const FGuid& TargetInventoryID, const FGuid& ItemEntryID, const TSubclassOf<UItemAttribute_Int>& Attribute) const
{
	return int64();
}

int32 AInventoryCollection::GetItemSlotNumber(const FGuid& TargetInventoryID, const FGuid& ItemEntryID) const
{
	return int32();
}

bool AInventoryCollection::IsItemEquipped(const FGuid& ItemEntryID) const
{
	return false;
}

bool AInventoryCollection::UnequipItem(const FGuid& ItemEntryID)
{
	return false;
}
