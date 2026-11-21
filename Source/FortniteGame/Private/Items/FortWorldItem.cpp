// Copyright Epic Games, Inc. All Rights Reserved.

#include "Items/FortWorldItem.h"

FFortItemEntry UFortWorldItem::CreateItemEntryForDrop() const
{
	return FFortItemEntry();
}

int32 UFortWorldItem::GetFuelChargeValue() const
{
	return int32();
}

float UFortWorldItem::GetMaxDurability() const
{
	return float();
}

void UFortWorldItem::GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const
{
}

void UFortWorldItem::MarkItemAsSeenInFrontend()
{
}

bool UFortWorldItem::SeenInFrontend() const
{
	return false;
}
