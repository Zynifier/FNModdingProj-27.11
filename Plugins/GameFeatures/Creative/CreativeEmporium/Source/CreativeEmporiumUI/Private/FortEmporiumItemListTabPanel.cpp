// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortEmporiumItemListTabPanel.h"

void UFortEmporiumItemListTabPanel::AddItem(FFortItemEntry& ItemToAdd)
{
}

void UFortEmporiumItemListTabPanel::AddItemToSource(FFortItemEntry& ItemToAdd)
{
}

bool UFortEmporiumItemListTabPanel::CanPlayerCreateInVolume() const
{
	return false;
}

void UFortEmporiumItemListTabPanel::ClearAllItems()
{
}

void UFortEmporiumItemListTabPanel::ClearFilteredItems()
{
}

EFortItemCardSize UFortEmporiumItemListTabPanel::GetCardSizeForCategory() const
{
	return EFortItemCardSize();
}

bool UFortEmporiumItemListTabPanel::GetCollapseBorderPadFlagForCategory() const
{
	return false;
}

UFortItemDefinition* UFortEmporiumItemListTabPanel::GetSubTabSelectedItemDefinition() const
{
	return nullptr;
}

void UFortEmporiumItemListTabPanel::HandleItemDetailTagSelected(const FName& TagID)
{
}

bool UFortEmporiumItemListTabPanel::IsEmpty()
{
	return false;
}

bool UFortEmporiumItemListTabPanel::IsSubTabOpened() const
{
	return false;
}

void UFortEmporiumItemListTabPanel::RemoveSelectedItem()
{
}

void UFortEmporiumItemListTabPanel::RestoreLastSelection()
{
}

bool UFortEmporiumItemListTabPanel::ShowLegacyItemDetailsPanel() const
{
	return false;
}
