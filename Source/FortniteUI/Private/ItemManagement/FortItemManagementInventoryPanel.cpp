// Copyright Epic Games, Inc. All Rights Reserved.

#include "ItemManagement/FortItemManagementInventoryPanel.h"

void UFortItemManagementInventoryPanel::AddItemStackToMulch(UFortItem* Item, int32 Count)
{
}

void UFortItemManagementInventoryPanel::AdvanceSelection()
{
}

bool UFortItemManagementInventoryPanel::CanDragItems() const
{
	return false;
}

void UFortItemManagementInventoryPanel::CycleSortType()
{
}

FText UFortItemManagementInventoryPanel::GetQualifiedFilterDisplayName() const
{
	return FText();
}

bool UFortItemManagementInventoryPanel::GetShouldPrioritizeFavorites()
{
	return false;
}

TArray<EInventoryContentSortType> UFortItemManagementInventoryPanel::GetSupportedSortTypesForCurrentInventory() const
{
	return TArray<EInventoryContentSortType>();
}

TArray<UFortItemDefinition*> UFortItemManagementInventoryPanel::GetUpgradeItemDefinitionsForCurrentInventory() const
{
	return TArray<UFortItemDefinition*>();
}

void UFortItemManagementInventoryPanel::HandleCraftItemStarted()
{
}

void UFortItemManagementInventoryPanel::HandleCursorModeChanged(bool bCursorModeEnabled, FName ActionName, UUserWidget* CursorModeContentWidget)
{
}

void UFortItemManagementInventoryPanel::HandleCustomInventoryFilterChanged()
{
}

void UFortItemManagementInventoryPanel::HandleFilterTabButtonCreated(FName TabNameId, UCommonButtonBase* TabButton)
{
}

void UFortItemManagementInventoryPanel::HandleFilterTabSelected(FName TabNameId)
{
}

void UFortItemManagementInventoryPanel::HandleInventoryUpdatedEvent()
{
}

void UFortItemManagementInventoryPanel::HandleItemBeginDrag(UObject* Item)
{
}

bool UFortItemManagementInventoryPanel::HasUnlockedStorageSlots() const
{
	return false;
}

bool UFortItemManagementInventoryPanel::IsSelectedItem(const UFortItem* Item) const
{
	return false;
}

bool UFortItemManagementInventoryPanel::IsSwitchPanelAvailable() const
{
	return false;
}

void UFortItemManagementInventoryPanel::MarkAllItemsAsSeen()
{
}

void UFortItemManagementInventoryPanel::RefreshCraftingSort()
{
}

void UFortItemManagementInventoryPanel::RequestFocusEquipSlots()
{
}

void UFortItemManagementInventoryPanel::SetFilter(const FName FilterName)
{
}

void UFortItemManagementInventoryPanel::SetSortType(EInventoryContentSortType SortType)
{
}

void UFortItemManagementInventoryPanel::SwitchPanelFocus()
{
}

void UFortItemManagementInventoryPanel::TogglePrioritizeFavorites()
{
}

void UFortItemManagementInventoryPanel::ToggleTileSize()
{
}

void UFortItemManagementInventoryPanel::UpdateSchematicTiles()
{
}
