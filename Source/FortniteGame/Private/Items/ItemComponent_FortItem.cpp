// Copyright Epic Games, Inc. All Rights Reserved.

#include "Items/ItemComponent_FortItem.h"

const FGameplayTagContainer& UItemComponent_FortItem::GetAutomationTags() const
{
	static FGameplayTagContainer Dummy;
	return Dummy;
}

const FGameplayTagContainer& UItemComponent_FortItem::GetGameplayTags() const
{
	static FGameplayTagContainer Dummy;
	return Dummy;
}
