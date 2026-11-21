// Copyright Epic Games, Inc. All Rights Reserved.

#include "Item/FortItemInspect.h"

void UFortItemInspectionScreen::DoAlterationModification()
{
}

bool UFortItemInspectionScreen::DoesItemHaveLegacyAlterations() const
{
	return false;
}

UFortItemInspectCycleWidget* UFortItemInspectionScreen::GetCycleWidget()
{
	return nullptr;
}

int32 UFortItemInspectionScreen::GetItemQuantityOverride() const
{
	return int32();
}

FText UFortItemInspectionScreen::GetRefundDescriptionText() const
{
	return FText();
}

UFortAccountItem* UFortItemInspectionScreen::GetRefundResultItem() const
{
	return nullptr;
}

void UFortItemInspectionScreen::HandleItemToInspectChanged(bool bItemChanged, bool bAmmoChanged, bool bIngredientsChanged)
{
}

void UFortItemInspectionScreen::HandleItemToInspectDestroyed()
{
}

bool UFortItemInspectionScreen::IsItemSlottedInCollectionBook(const UFortItem* Item) const
{
	return false;
}

void UFortItemInspectionScreen::OpenItemInspect(UFortItem* ItemToInspect, EFortItemInspectionMode Mode, bool ShouldAllowUpgrading, bool ShouldAllowEvolution, bool ShouldAllowFavorite, bool IsTemporaryItem, bool bAllowRarityUpgrading, int32 QuantityOverride, UFortItemTileView* TileViewWidget)
{
}

void UFortItemInspectionScreen::SetAttemptingConversion(bool bIsAttemptingConversion)
{
}

void UFortItemInspectionScreen::SetInspectionMode(EFortItemInspectionMode NewInspectMode)
{
}

void UFortItemInspectionScreen::SetItemToRepresent(UFortItem* Item)
{
}
