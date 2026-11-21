// Copyright Epic Games, Inc. All Rights Reserved.

#include "Items/FortInventorySubSystem.h"

FGameplayTag UFortInventorySubsystem::GetActionTagForItem(const UFortItem* Item) const
{
	return FGameplayTag();
}

UFortWorldItem* UFortInventorySubsystem::GetItemForActionTag(const AFortPlayerController* OwningPlayerController, const FGameplayTag ActionTag) const
{
	return nullptr;
}

UFortWorldItem* UFortInventorySubsystem::GetViewTargetItemForActionTag(const AFortPlayerController* OwningPlayerController, const FGameplayTag ActionTag) const
{
	return nullptr;
}
