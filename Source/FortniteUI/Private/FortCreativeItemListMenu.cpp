// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortCreativeItemListMenu.h"

bool UFortCreativeItemListMenu::AddSelectionToQuickBar()
{
	return false;
}

void UFortCreativeItemListMenu::BroadcastOnCloseFromContentBrowser()
{
}

void UFortCreativeItemListMenu::BroadcastOnItemEquipped(FFortItemEntry ItemToSpawn)
{
}

bool UFortCreativeItemListMenu::CanAddToChest(const FFortItemEntry& SelectedItem) const
{
	return false;
}

bool UFortCreativeItemListMenu::CanDropItem(const FFortItemEntry& SelectedItem) const
{
	return false;
}

bool UFortCreativeItemListMenu::CanEquip(const FFortItemEntry& SelectedItem) const
{
	return false;
}

bool UFortCreativeItemListMenu::DropItem(const FFortItemEntry& SelectedItem)
{
	return false;
}

bool UFortCreativeItemListMenu::EquipItem(const FFortItemEntry& ItemEntry)
{
	return false;
}

bool UFortCreativeItemListMenu::EquipSelection()
{
	return false;
}

FFortItemEntry UFortCreativeItemListMenu::GetCurrentSelection() const
{
	return FFortItemEntry();
}

UFortCreativeContentBrowserTabPanelBase* UFortCreativeItemListMenu::GetCurrentTab() const
{
	return nullptr;
}

FName UFortCreativeItemListMenu::GetLastSelectedTabName()
{
	return FName();
}

void UFortCreativeItemListMenu::HandleAddSelectionToMoveToolComplete()
{
}

void UFortCreativeItemListMenu::HandleChestItemCountChanged(int32 Count)
{
}

void UFortCreativeItemListMenu::HandleEquipItem(const FFortItemEntry& ItemEntry)
{
}

void UFortCreativeItemListMenu::HandleFilterChanged()
{
}

void UFortCreativeItemListMenu::HandleFilterPanelIsFocused(bool bIsFocused)
{
}

void UFortCreativeItemListMenu::HandleItemDetailsInputAction()
{
}

void UFortCreativeItemListMenu::HandleQuickbarPanelIsFocused(bool bIsFocused)
{
}

void UFortCreativeItemListMenu::HandleSelectionChanged(UFortCreativeContentBrowserTabPanelBase* Tab)
{
}

void UFortCreativeItemListMenu::HandleTabSelected(FName TabId)
{
}

void UFortCreativeItemListMenu::InitializeTabs()
{
}

bool UFortCreativeItemListMenu::IsSubTabOpened() const
{
	return false;
}

void UFortCreativeItemListMenu::LoadItems()
{
}

void UFortCreativeItemListMenu::NativeOnItemsLoaded()
{
}

void UFortCreativeItemListMenu::NativeOnItemsRefreshed()
{
}

void UFortCreativeItemListMenu::OnContentRatingFilterChanged()
{
}

void UFortCreativeItemListMenu::OnCreativeQuickbarComponentLoaded()
{
}

void UFortCreativeItemListMenu::OnCursorModeChanged(bool bCursorModeEnabled, FName ActionName, UUserWidget* CursorModeContentWidget)
{
}

bool UFortCreativeItemListMenu::OpenSelection()
{
	return false;
}

bool UFortCreativeItemListMenu::PlaceSelectionInMoveTool()
{
	return false;
}

void UFortCreativeItemListMenu::RefreshChestWidgetState()
{
}

void UFortCreativeItemListMenu::SetIsItemCommandsEnabled(bool bInIsItemCommandEnabled)
{
}

void UFortCreativeItemListMenu::SetSubTabOpened(bool bIsOpened)
{
}

void UFortCreativeItemListMenu::SpawnContainer(TSubclassOf<AActor> SupplyDropClass)
{
}

void UFortCreativeItemListMenu::SwitchItemDetailsPanel(bool bUseLegacy)
{
}

void UFortCreativeItemListMenu::UpdateDetailsPanel()
{
}

void UFortCreativeItemListMenu::VerifyPermissionsToCreativeInventory()
{
}
