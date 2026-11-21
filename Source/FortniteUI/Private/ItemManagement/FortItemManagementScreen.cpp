// Copyright Epic Games, Inc. All Rights Reserved.

#include "ItemManagement/FortItemManagementScreen.h"

void UFortItemManagementScreen::CancelInventoryPanelTileViewRefresh()
{
}

bool UFortItemManagementScreen::CanEquipItem(UFortItem* Item) const
{
	return false;
}

bool UFortItemManagementScreen::CanRequestPopupMenuForSelectedItem()
{
	return false;
}

void UFortItemManagementScreen::ConsumeItem(UFortConsumableAccountItem* ConsumableItem)
{
}

void UFortItemManagementScreen::CraftAndSlotItem(UFortSchematicItem* SchematicItem, EFortItemTier RequestedTier, int32 CraftCount)
{
}

void UFortItemManagementScreen::CraftItem(UFortSchematicItem* SchematicItem, EFortItemTier RequestedTier, int32 CraftCount)
{
}

void UFortItemManagementScreen::CycleSortType()
{
}

void UFortItemManagementScreen::DropItem(UFortItem* Item)
{
}

void UFortItemManagementScreen::EnterComparisonMode(UFortItem* ItemToCompareDetailsWith)
{
}

void UFortItemManagementScreen::EnterDetailsMode(UFortItem* ItemToDetail)
{
}

void UFortItemManagementScreen::EnterMulchMode(UFortItem* ItemToMulch)
{
}

void UFortItemManagementScreen::EnterMulchModeForAutoMulch()
{
}

void UFortItemManagementScreen::EquipItem(UFortItem* Item)
{
}

UFortItem* UFortItemManagementScreen::GetItemToCompareDetailsWith() const
{
	return nullptr;
}

UFortItem* UFortItemManagementScreen::GetItemToDetail() const
{
	return nullptr;
}

bool UFortItemManagementScreen::GetShouldShowCollectionBookIndicator() const
{
	return false;
}

bool UFortItemManagementScreen::GetShouldShowRefundIndicator() const
{
	return false;
}

bool UFortItemManagementScreen::GuardActionForReadOnlyWIFE()
{
	return false;
}

void UFortItemManagementScreen::HandleItemToCompareWithChanged(bool bItemChanged, bool bAmmoChanged, bool bIngredientsChanged)
{
}

void UFortItemManagementScreen::HandleItemToDetailChanged(bool bItemChanged, bool bAmmoChanged, bool bIngredientsChanged)
{
}

bool UFortItemManagementScreen::HasDefaultItemsToMulch() const
{
	return false;
}

bool UFortItemManagementScreen::HasItemBeenSeen(UFortAccountItem* AccountItem) const
{
	return false;
}

void UFortItemManagementScreen::HideCustomFilterModal()
{
}

void UFortItemManagementScreen::HideMulchConfirmationModal()
{
}

void UFortItemManagementScreen::HideRecycleProgressModal()
{
}

void UFortItemManagementScreen::InspectItem(UFortItem* Item)
{
}

bool UFortItemManagementScreen::IsScreenWIFE() const
{
	return false;
}

void UFortItemManagementScreen::MarkAllItemsAsSeen()
{
}

void UFortItemManagementScreen::NotifyPanelActivated()
{
}

void UFortItemManagementScreen::NotifyPanelDeactivated()
{
}

void UFortItemManagementScreen::OpenAutoMulchOptions()
{
}

void UFortItemManagementScreen::OpenCraftingOptions(UFortSchematicItem* SchematicItem)
{
}

void UFortItemManagementScreen::RequestPopupMenuForSelectedItem()
{
}

void UFortItemManagementScreen::SetConsumeItemRequestInProgress(bool InProgress)
{
}

void UFortItemManagementScreen::SetFrontendInventoryFilter(EFortFrontendInventoryFilter FrontendInventoryFilter)
{
}

void UFortItemManagementScreen::ShowCustomFilterModal()
{
}

void UFortItemManagementScreen::ShowMulchConfirmationModal()
{
}

void UFortItemManagementScreen::ShowRecycleProgressModal()
{
}

void UFortItemManagementScreen::ToggleShowCollectionBookIndicator()
{
}

void UFortItemManagementScreen::ToggleShowRefundIndicator()
{
}

void UFortItemManagementScreen::TransferItem(UFortItem* Item)
{
}
