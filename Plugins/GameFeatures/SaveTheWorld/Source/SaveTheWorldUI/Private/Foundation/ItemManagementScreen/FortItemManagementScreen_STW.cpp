// Copyright Epic Games, Inc. All Rights Reserved.

#include "Foundation/ItemManagementScreen/FortItemManagementScreen_STW.h"

void UFortItemManagementScreen_STW::CancelInventoryPanelTileViewRefresh()
{
}

bool UFortItemManagementScreen_STW::CanEquipItem(UFortItem* Item) const
{
	return false;
}

bool UFortItemManagementScreen_STW::CanRequestPopupMenuForSelectedItem()
{
	return false;
}

void UFortItemManagementScreen_STW::ConsumeItem(UFortConsumableAccountItem* ConsumableItem)
{
}

void UFortItemManagementScreen_STW::CraftAndSlotItem(UFortSchematicItem* SchematicItem, EFortItemTier RequestedTier, int32 CraftCount)
{
}

void UFortItemManagementScreen_STW::CraftItem(UFortSchematicItem* SchematicItem, EFortItemTier RequestedTier, int32 CraftCount)
{
}

void UFortItemManagementScreen_STW::CycleSortType()
{
}

void UFortItemManagementScreen_STW::DropItem(UFortItem* Item)
{
}

void UFortItemManagementScreen_STW::EnterComparisonMode(UFortItem* ItemToCompareDetailsWith)
{
}

void UFortItemManagementScreen_STW::EnterDetailsMode(UFortItem* ItemToDetail)
{
}

void UFortItemManagementScreen_STW::EnterMulchMode(UFortItem* ItemToMulch)
{
}

void UFortItemManagementScreen_STW::EnterMulchModeForAutoMulch()
{
}

void UFortItemManagementScreen_STW::EquipItem(UFortItem* Item)
{
}

UFortItem* UFortItemManagementScreen_STW::GetItemToCompareDetailsWith() const
{
	return nullptr;
}

UFortItem* UFortItemManagementScreen_STW::GetItemToDetail() const
{
	return nullptr;
}

bool UFortItemManagementScreen_STW::GetShouldShowCollectionBookIndicator() const
{
	return false;
}

bool UFortItemManagementScreen_STW::GetShouldShowRefundIndicator() const
{
	return false;
}

bool UFortItemManagementScreen_STW::GuardActionForReadOnlyWIFE()
{
	return false;
}

void UFortItemManagementScreen_STW::HandleItemToCompareWithChanged(bool bItemChanged, bool bAmmoChanged, bool bIngredientsChanged)
{
}

void UFortItemManagementScreen_STW::HandleItemToDetailChanged(bool bItemChanged, bool bAmmoChanged, bool bIngredientsChanged)
{
}

bool UFortItemManagementScreen_STW::HasDefaultItemsToMulch() const
{
	return false;
}

bool UFortItemManagementScreen_STW::HasItemBeenSeen(UFortAccountItem* AccountItem) const
{
	return false;
}

void UFortItemManagementScreen_STW::HideCustomFilterModal()
{
}

void UFortItemManagementScreen_STW::HideMulchConfirmationModal()
{
}

void UFortItemManagementScreen_STW::InspectItem(UFortItem* Item)
{
}

bool UFortItemManagementScreen_STW::IsScreenWIFE() const
{
	return false;
}

void UFortItemManagementScreen_STW::MarkAllItemsAsSeen()
{
}

void UFortItemManagementScreen_STW::NotifyPanelActivated()
{
}

void UFortItemManagementScreen_STW::NotifyPanelDeactivated()
{
}

void UFortItemManagementScreen_STW::OpenAutoMulchOptions()
{
}

void UFortItemManagementScreen_STW::OpenCraftingOptions(UFortSchematicItem* SchematicItem)
{
}

void UFortItemManagementScreen_STW::RequestPopupMenuForSelectedItem()
{
}

void UFortItemManagementScreen_STW::SetConsumeItemRequestInProgress(bool InProgress)
{
}

void UFortItemManagementScreen_STW::SetFrontendInventoryFilter(EFortFrontendInventoryFilter FrontendInventoryFilter)
{
}

void UFortItemManagementScreen_STW::ShowCustomFilterModal()
{
}

void UFortItemManagementScreen_STW::ShowMulchConfirmationModal()
{
}

void UFortItemManagementScreen_STW::ToggleShowCollectionBookIndicator()
{
}

void UFortItemManagementScreen_STW::ToggleShowRefundIndicator()
{
}

void UFortItemManagementScreen_STW::ToggleSortAndMoreBlade()
{
}

void UFortItemManagementScreen_STW::TransferItem(UFortItem* Item)
{
}

void UFortItemManagementScreen_STW::UpdateSorts()
{
}
