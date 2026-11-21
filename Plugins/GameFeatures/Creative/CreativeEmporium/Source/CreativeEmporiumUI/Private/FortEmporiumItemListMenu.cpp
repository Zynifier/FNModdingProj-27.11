// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortEmporiumItemListMenu.h"

bool UFortEmporiumItemListMenu::AddSelectionToQuickBar()
{
	return false;
}

bool UFortEmporiumItemListMenu::CanAddToChest(const FFortItemEntry& SelectedItem) const
{
	return false;
}

bool UFortEmporiumItemListMenu::CanDropItem(const FFortItemEntry& SelectedItem) const
{
	return false;
}

bool UFortEmporiumItemListMenu::CanEquip(const FFortItemEntry& SelectedItem) const
{
	return false;
}

bool UFortEmporiumItemListMenu::DropItem(const FFortItemEntry& SelectedItem)
{
	return false;
}

bool UFortEmporiumItemListMenu::EquipItem(const FFortItemEntry& ItemEntry)
{
	return false;
}

bool UFortEmporiumItemListMenu::EquipSelection()
{
	return false;
}

FFortItemEntry UFortEmporiumItemListMenu::GetCurrentSelection() const
{
	return FFortItemEntry();
}

UFortCreativeContentBrowserTabPanelBase* UFortEmporiumItemListMenu::GetCurrentTab() const
{
	return nullptr;
}

FName UFortEmporiumItemListMenu::GetLastSelectedTabName() const
{
	return FName();
}

UFortItemDefinition* UFortEmporiumItemListMenu::GetSubTabSelectedItemDefinition() const
{
	return nullptr;
}

void UFortEmporiumItemListMenu::HandleAddSelectionToMoveToolComplete()
{
}

void UFortEmporiumItemListMenu::HandleCategoryActivated(FName CategoryID)
{
}

void UFortEmporiumItemListMenu::HandleCategoryFocused(FName CategoryID)
{
}

void UFortEmporiumItemListMenu::HandleChestItemCountChanged(int32 Count)
{
}

void UFortEmporiumItemListMenu::HandleEquipItem(const FFortItemEntry& ItemEntry)
{
}

void UFortEmporiumItemListMenu::HandleFilterButtonClicked(FName FilterNameId, UCommonButtonBase* NewButton)
{
}

void UFortEmporiumItemListMenu::HandleFilterChanged()
{
}

void UFortEmporiumItemListMenu::HandleFilterPanelIsFocused(bool bIsFocused)
{
}

void UFortEmporiumItemListMenu::HandleGlobalSortPanelToggle()
{
}

void UFortEmporiumItemListMenu::HandleItemClicked(const FFortItemEntry& ItemEntry)
{
}

void UFortEmporiumItemListMenu::HandleItemDoubleClicked(const FFortItemEntry& ItemEntry)
{
}

void UFortEmporiumItemListMenu::HandleItemTagSelected(const FName& TagID, bool bSelected)
{
}

void UFortEmporiumItemListMenu::HandleItemThumbnailDownloaded(UFortEmporiumItemDefinition* ItemDefinition)
{
}

void UFortEmporiumItemListMenu::HandleModalHitBlockerClicked()
{
}

void UFortEmporiumItemListMenu::HandleQuickbarPanelIsFocused(bool bIsFocused)
{
}

void UFortEmporiumItemListMenu::HandleQuickbarStateChanged(const EFortContentBrowserQuickbarState State)
{
}

void UFortEmporiumItemListMenu::HandleSelectionChanged(UFortCreativeContentBrowserTabPanelBase* Tab)
{
}

void UFortEmporiumItemListMenu::HandleSortButtonClicked(FName SortNameId, UCommonButtonBase* NewButton)
{
}

void UFortEmporiumItemListMenu::HandleSortChanged()
{
}

void UFortEmporiumItemListMenu::HandleTabItemDetailClicked(const FName& TagID)
{
}

void UFortEmporiumItemListMenu::HandleTabSelected(FName TabId, bool bCaptureFocus)
{
}

void UFortEmporiumItemListMenu::HandleTabSortButtonClicked()
{
}

void UFortEmporiumItemListMenu::InitializeFabTab()
{
}

void UFortEmporiumItemListMenu::InitializeTabs()
{
}

bool UFortEmporiumItemListMenu::IsSubTabOpened() const
{
	return false;
}

void UFortEmporiumItemListMenu::LoadFabItems()
{
}

void UFortEmporiumItemListMenu::NativeOnBuiltInItemsLoaded()
{
}

void UFortEmporiumItemListMenu::NativeOnItemsLoaded()
{
}

void UFortEmporiumItemListMenu::NativeOnItemsRefreshed()
{
}

void UFortEmporiumItemListMenu::OnContentRatingFilterChanged()
{
}

void UFortEmporiumItemListMenu::OnCreativeQuickbarComponentLoaded()
{
}

void UFortEmporiumItemListMenu::OnCursorModeChanged(bool bCursorModeEnabled, FName ActionName, UUserWidget* CursorModeContentWidget)
{
}

void UFortEmporiumItemListMenu::OnFabCategoryListLoaded(bool bSuccess, const FString& JSONString)
{
}

void UFortEmporiumItemListMenu::OnFabItemQueryComplete(bool bSuccess, const FString& JSONString)
{
}

bool UFortEmporiumItemListMenu::OpenSelection()
{
	return false;
}

bool UFortEmporiumItemListMenu::PlaceSelectionInMoveTool()
{
	return false;
}

void UFortEmporiumItemListMenu::RefreshTabWarningState()
{
}

void UFortEmporiumItemListMenu::SetIsItemCommandsEnabled(bool bInIsItemCommandEnabled)
{
}

void UFortEmporiumItemListMenu::SetSubTabOpened(UFortItemDefinition* ItemDefinition)
{
}

void UFortEmporiumItemListMenu::SpawnContainer(TSubclassOf<AActor> SupplyDropClass)
{
}

void UFortEmporiumItemListMenu::SwitchItemDetailsPanel(bool bUseLegacy)
{
}

void UFortEmporiumItemListMenu::UpdateDetailsPanel()
{
}

void UFortEmporiumItemListMenu::UpdatePermissionsDisplay()
{
}
