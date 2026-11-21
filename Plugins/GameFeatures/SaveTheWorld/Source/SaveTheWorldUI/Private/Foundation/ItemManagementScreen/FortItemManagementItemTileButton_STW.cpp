// Copyright Epic Games, Inc. All Rights Reserved.

#include "Foundation/ItemManagementScreen/FortItemManagementItemTileButton_STW.h"

FHomebaseSquadSlotId UFortItemManagementItemTileButton_STW::GetHomebaseSquadSlotForItem() const
{
	return FHomebaseSquadSlotId();
}

EFortItemManagementMode UFortItemManagementItemTileButton_STW::GetItemManagementMode() const
{
	return EFortItemManagementMode();
}

UUserWidget* UFortItemManagementItemTileButton_STW::GetPopupMenu()
{
	return nullptr;
}

bool UFortItemManagementItemTileButton_STW::IsValidEquipSlotOverlayIndex(const int32 SlotIndex) const
{
	return false;
}

void UFortItemManagementItemTileButton_STW::OnSlotItemComplete(const UFortAccountItem* SlottedItem, FName SlotId)
{
}

void UFortItemManagementItemTileButton_STW::PopulateEquipSlotOverlay()
{
}

void UFortItemManagementItemTileButton_STW::UpdateEquipSlotOverlay(const int32 CurrentSlotIndex)
{
}
