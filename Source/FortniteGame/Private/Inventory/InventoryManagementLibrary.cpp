// Copyright Epic Games, Inc. All Rights Reserved.

#include "Inventory/InventoryManagementLibrary.h"

UFortWorldItem* UInventoryManagementLibrary::AddItem(TScriptInterface<IFortInventoryOwnerInterface> InventoryOwner, const UFortItemDefinition* ItemDefinition, int32 Count, const bool bShouldFireCollectStatEvent)
{
	return nullptr;
}

TArray<UFortWorldItem*> UInventoryManagementLibrary::AddItems(TScriptInterface<IFortInventoryOwnerInterface> InventoryOwner, TArray<FItemAndCount> Items)
{
	return TArray<UFortWorldItem*>();
}

UFortItem* UInventoryManagementLibrary::FindExistingItemForDefinition(TScriptInterface<IFortInventoryOwnerInterface> InventoryOwner, const UFortItemDefinition* ItemDefinition, bool bInStorageVault)
{
	return nullptr;
}

UFortControllerComponent_InventoryNetworkManagement* UInventoryManagementLibrary::GetInventoryNetworkComponent(AFortPlayerController* Owner)
{
	return nullptr;
}

int32 UInventoryManagementLibrary::GetItemCountForItemDefinition(TScriptInterface<IFortInventoryOwnerInterface> InventoryOwner, const UFortItemDefinition* ItemDefinition)
{
	return int32();
}

void UInventoryManagementLibrary::GetItemsFromInventoryOwner(TScriptInterface<IFortInventoryOwnerInterface> InventoryOwner, TArray<UFortWorldItem*>& Items)
{
}

void UInventoryManagementLibrary::GetItemsFromInventoryOwnerForRarity(TScriptInterface<IFortInventoryOwnerInterface> InventoryOwner, TArray<UFortWorldItem*>& Items, const EFortRarity RarityType)
{
}

bool UInventoryManagementLibrary::GiveItemEntryToInventoryOwner(TScriptInterface<IFortInventoryOwnerInterface> InventoryOwner, const FFortItemEntry& ItemInstance)
{
	return false;
}

bool UInventoryManagementLibrary::RemoveItem(TScriptInterface<IFortInventoryOwnerInterface> InventoryOwner, FGuid ItemGuid, int32 Count)
{
	return false;
}

void UInventoryManagementLibrary::RemoveItems(TScriptInterface<IFortInventoryOwnerInterface> InventoryOwner, TArray<FItemGuidAndCount> Items)
{
}

bool UInventoryManagementLibrary::SwapItem(TScriptInterface<IFortInventoryOwnerInterface> SourceOwner, TScriptInterface<IFortInventoryOwnerInterface> TargetOwner, FGuid ItemGuid, int32 Count)
{
	return false;
}

void UInventoryManagementLibrary::SwapItems(TScriptInterface<IFortInventoryOwnerInterface> SourceOwner, TScriptInterface<IFortInventoryOwnerInterface> TargetOwner, TArray<FItemGuidAndCount> ItemGuids)
{
}
