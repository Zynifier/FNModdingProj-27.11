// Copyright Epic Games, Inc. All Rights Reserved.

#include "Foundation/ItemManagementScreen/FortItemManagementInventoryPanel_STW.h"

void UFortItemManagementInventoryPanel_STW::AddItemStackToMulch(UFortItem* Item, int32 Count)
{
}

void UFortItemManagementInventoryPanel_STW::AdvanceSelection()
{
}

bool UFortItemManagementInventoryPanel_STW::CanDragItems() const
{
	return false;
}

void UFortItemManagementInventoryPanel_STW::CycleSortType()
{
}

FText UFortItemManagementInventoryPanel_STW::GetQualifiedFilterDisplayName() const
{
	return FText();
}

bool UFortItemManagementInventoryPanel_STW::GetShouldPrioritizeFavorites()
{
	return false;
}

TArray<EInventoryContentSortType> UFortItemManagementInventoryPanel_STW::GetSupportedSortTypesForCurrentInventory() const
{
	return TArray<EInventoryContentSortType>();
}

TArray<UFortItemDefinition*> UFortItemManagementInventoryPanel_STW::GetUpgradeItemDefinitionsForCurrentInventory() const
{
	return TArray<UFortItemDefinition*>();
}

void UFortItemManagementInventoryPanel_STW::HandleCraftItemStarted()
{
}

void UFortItemManagementInventoryPanel_STW::HandleCursorModeChanged(bool bCursorModeEnabled, FName ActionName, UUserWidget* CursorModeContentWidget)
{
}

void UFortItemManagementInventoryPanel_STW::HandleCustomInventoryFilterChanged()
{
}

void UFortItemManagementInventoryPanel_STW::HandleFilterTabButtonCreated(FName TabNameId, UCommonButtonBase* TabButton)
{
}

void UFortItemManagementInventoryPanel_STW::HandleFilterTabSelected(FName TabNameId)
{
}

void UFortItemManagementInventoryPanel_STW::HandleInventoryUpdatedEvent()
{
}

void UFortItemManagementInventoryPanel_STW::HandleItemBeginDrag(UObject* Item)
{
}

bool UFortItemManagementInventoryPanel_STW::HasUnlockedStorageSlots() const
{
	return false;
}

bool UFortItemManagementInventoryPanel_STW::IsSelectedItem(const UFortItem* Item) const
{
	return false;
}

bool UFortItemManagementInventoryPanel_STW::IsSwitchPanelAvailable() const
{
	return false;
}

void UFortItemManagementInventoryPanel_STW::MarkAllItemsAsSeen()
{
}

void UFortItemManagementInventoryPanel_STW::RefreshCraftingSort()
{
}

void UFortItemManagementInventoryPanel_STW::RequestFocusEquipSlots()
{
}

void UFortItemManagementInventoryPanel_STW::SetFilter(const FName FilterName)
{
}

void UFortItemManagementInventoryPanel_STW::SetSortType(EInventoryContentSortType SortType)
{
}

void UFortItemManagementInventoryPanel_STW::SwitchPanelFocus()
{
}

void UFortItemManagementInventoryPanel_STW::TogglePrioritizeFavorites()
{
}

void UFortItemManagementInventoryPanel_STW::ToggleTileSize()
{
}

void UFortItemManagementInventoryPanel_STW::UpdateSchematicTiles()
{
}
