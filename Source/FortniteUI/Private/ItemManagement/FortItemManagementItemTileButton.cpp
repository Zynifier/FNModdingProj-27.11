// Copyright Epic Games, Inc. All Rights Reserved.

#include "ItemManagement/FortItemManagementItemTileButton.h"

FHomebaseSquadSlotId UFortItemManagementItemTileButton::GetHomebaseSquadSlotForItem() const
{
	return FHomebaseSquadSlotId();
}

EFortItemManagementMode UFortItemManagementItemTileButton::GetItemManagementMode() const
{
	return EFortItemManagementMode();
}

UUserWidget* UFortItemManagementItemTileButton::GetPopupMenu()
{
	return nullptr;
}

bool UFortItemManagementItemTileButton::IsValidEquipSlotOverlayIndex(const int32 SlotIndex) const
{
	return false;
}

void UFortItemManagementItemTileButton::OnSlotItemComplete(const UFortAccountItem* SlottedItem, FName SlotId)
{
}

void UFortItemManagementItemTileButton::PopulateEquipSlotOverlay()
{
}

void UFortItemManagementItemTileButton::UpdateEquipSlotOverlay(const int32 CurrentSlotIndex)
{
}
