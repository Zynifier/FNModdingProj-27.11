// Copyright Epic Games, Inc. All Rights Reserved.

#include "Frontend/HeroLoadout/FortHeroLoadoutScreenBase.h"

bool UFortHeroLoadoutScreenBase::GetIsReadOnly() const
{
	return false;
}

void UFortHeroLoadoutScreenBase::HideItemDetails()
{
}

bool UFortHeroLoadoutScreenBase::IsLoadoutSwitchingAllowed() const
{
	return false;
}

void UFortHeroLoadoutScreenBase::OnItemPreviewChanged(AActor* NewPrefab, UFortItem* NewItem)
{
}

void UFortHeroLoadoutScreenBase::OnVaultItemsViewed(const TArray<UFortItem*>& Items)
{
}

void UFortHeroLoadoutScreenBase::PushItemInspectionScreen(UFortItem* ItemToInspect, EFortItemInspectionMode Mode, UFortItemTileView* CycleTileView, bool bReadOnly, bool bAllowFavoriting, bool bIsTemporaryItem, bool bAllowRarityUpgrading)
{
}

void UFortHeroLoadoutScreenBase::SetInputBindings(const bool ActivePickerBox, const bool CommanderSlot, const bool NoneSlot, const bool CanClearAll)
{
}

void UFortHeroLoadoutScreenBase::ShowItemDetails()
{
}
