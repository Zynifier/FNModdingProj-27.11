// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/FortItemEntryComponent.h"

bool UFortItemEntryComponent::AddItemToInventoryOwner(TScriptInterface<IFortInventoryOwnerInterface> InventoryOwner, bool bUseItemPickupAnalyticEvent)
{
	return false;
}

void UFortItemEntryComponent::Empty()
{
}

int32 UFortItemEntryComponent::GetClipSize() const
{
	return int32();
}

int32 UFortItemEntryComponent::GetLoadedAmmo() const
{
	return int32();
}

const FFortItemEntry& UFortItemEntryComponent::GetOwnedItem() const
{
	static FFortItemEntry Dummy;
	return Dummy;
}

bool UFortItemEntryComponent::HasItem() const
{
	return false;
}

void UFortItemEntryComponent::SetOwnedItem(const FFortItemEntry& Item)
{
}

bool UFortItemEntryComponent::TakeItemFromInventoryOwner(const FGuid& ItemGuid, const int32 Count, TScriptInterface<IFortInventoryOwnerInterface> InventoryOwner, const bool bTreatAsPickup)
{
	return false;
}

int32 UFortItemEntryComponent::TrySetLoadedAmmo(int32 NewAmmoAmount)
{
	return int32();
}
