// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortAthenaMutator_CR_LootChoice.h"

FGameplayTagContainer AFortAthenaMutator_CR_LootChoice::GetContextTagsToAdd_Implementation() const
{
	return FGameplayTagContainer();
}

FGameplayTagContainer AFortAthenaMutator_CR_LootChoice::GetContextTagsToRemove_Implementation() const
{
	return FGameplayTagContainer();
}

UDataTable* AFortAthenaMutator_CR_LootChoice::GetLootPackageTable_Implementation() const
{
	return nullptr;
}

FString AFortAthenaMutator_CR_LootChoice::GetLootSelectionString_Implementation() const
{
	return FString();
}

UDataTable* AFortAthenaMutator_CR_LootChoice::GetLootTierDataTable_Implementation() const
{
	return nullptr;
}
