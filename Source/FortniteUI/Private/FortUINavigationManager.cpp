// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortUINavigationManager.h"

void UUINavigationManager::ClearStack()
{
}

FText UUINavigationManager::GetDisplayName(int32 Index)
{
	return FText();
}

int32 UUINavigationManager::GetStackSize()
{
	return int32();
}

void UUINavigationManager::NavigationToIndex(int32 Index)
{
}

void UUINavigationManager::PopNavigation()
{
}

void UUINavigationManager::PushNavigation(FText DisplayName, UObject* ObjectData, FName IdData, int32 IntData, const FUINavigateDelegate& OnNavigateTo, const FUINavigateDelegate& OnNavigateFrom)
{
}

bool UFortUINavigationManager::AttemptMatchmakeForQuest(UFortQuestItem* Quest, bool& OutContentNotDownloaded)
{
	return false;
}

bool UFortUINavigationManager::AttemptPlayQuest(UFortQuestItem* Quest)
{
	return false;
}

bool UFortUINavigationManager::CanNavigateToQuestObjective(UFortQuestItem* QuestItem)
{
	return false;
}

void UFortUINavigationManager::CenterWidget(UWidget* Widget)
{
}

void UFortUINavigationManager::CompletePendingNavigationOp(EFortUINavigationOp NavigationOp)
{
}

bool UFortUINavigationManager::HasPendingNavigationOp(EFortUINavigationOp NavigationOp)
{
	return false;
}

void UFortUINavigationManager::NavigateToFeature(EFortUIFeature Feature)
{
}

void UFortUINavigationManager::NavigateToItemManagementScreen(EFortFrontendInventoryFilter Filter)
{
}

void UFortUINavigationManager::PushHeroLoadoutScreen(UFortCampaignHeroLoadoutItem* HeroLoadout)
{
}

void UFortUINavigationManager::PushItemInspectionScreen(UFortItem* ItemToInspect, EFortItemInspectionMode Mode, UFortItemTileView* CycleTileView, bool bReadOnly, bool bAllowFavoriting, bool bIsTemporaryItem, bool bAllowRarityUpgrading)
{
}

void UFortUINavigationManager::PushItemManagementScreen(EFortFrontendInventoryFilter ItemManagementFilter, UFortItem* ItemToSelect, bool bShowAutoMulch)
{
}

void UFortUINavigationManager::SetScrollWidget(UWidget* Widget)
{
}

bool UFortUINavigationManager::TryGetPendingNavigationOp(FFortUINavigationOperation& NavigationOp)
{
	return false;
}
