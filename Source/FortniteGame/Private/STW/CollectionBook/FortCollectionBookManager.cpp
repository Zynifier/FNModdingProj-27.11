// Copyright Epic Games, Inc. All Rights Reserved.

#include "STW/CollectionBook/FortCollectionBookManager.h"

int32 UFortCollectionBookManager::CalculateBookXp() const
{
	return int32();
}

int32 UFortCollectionBookManager::CalculatePageXp(FName PageId) const
{
	return int32();
}

bool UFortCollectionBookManager::CanSlotItem(const UFortAccountItem* AccountItem, bool bOnlyAllowIfSlotEmpty, FName& OutSlotId) const
{
	return false;
}

void UFortCollectionBookManager::ClaimReward(const FFortCollectionBookRewards& RewardToClaim, int32 RewardIndex)
{
}

bool UFortCollectionBookManager::DoesItemSlotExistInCollectionBook(const UFortItemDefinition* ItemDefinition) const
{
	return false;
}

int32 UFortCollectionBookManager::GetBookTotalXPToNextLevel(int32 CurrentLevel) const
{
	return int32();
}

float UFortCollectionBookManager::GetBookXPPercentToNextLevel(int32 CurrentLevel, int32 NewXP) const
{
	return float();
}

UFortItem* UFortCollectionBookManager::GetItemInSlot(FName SlotId) const
{
	return nullptr;
}

bool UFortCollectionBookManager::IsItemMissingFromCollectionBook(const UFortItemDefinition* ItemDefinition) const
{
	return false;
}

void UFortCollectionBookManager::PopulateCollectionBookRewards(TArray<FFortCollectionBookRewards>& OutAvailableRewards)
{
}

bool UFortCollectionBookManager::PurchaseItem(const UFortAccountItem* Item)
{
	return false;
}

bool UFortCollectionBookManager::SlotItem(const UFortAccountItem* Item, FName SlotId)
{
	return false;
}

bool UFortCollectionBookManager::UnSlotItem(const UFortAccountItem* Item)
{
	return false;
}
