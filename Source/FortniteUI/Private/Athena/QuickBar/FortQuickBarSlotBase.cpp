// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/QuickBar/FortQuickBarSlotBase.h"

FName UFortQuickBarSlotBase::GetKeyBindingAction()
{
	return FName();
}

FName UFortQuickBarSlotBase::GetKeyBindingActionGamepad()
{
	return FName();
}

FName UFortQuickBarSlotBase::GetKeyBindingActionKeyboard()
{
	return FName();
}

const FVector2D UFortQuickBarSlotBase::GetSlotSizeForItem(const UFortItem* InItem) const
{
	return FVector2D();
}

void UFortQuickBarSlotBase::OnMinigameEnded()
{
}

void UFortQuickBarSlotBase::OnMinigameStarted()
{
}

void UFortQuickBarSlotBase::RefreshInventoryCapacity()
{
}

void UFortQuickBarSlotBase::RefreshItem()
{
}

void UFortQuickBarSlotBase::RefreshItemIfSlotChanged(EFortQuickBars InQuickBar, const TArray<int32>& InSlot)
{
}

void UFortQuickBarSlotBase::Resize(EFortItemCardSize CardSize)
{
}

void UFortQuickBarSlotBase::SetBottomComboSwitcherVisibility(ESlateVisibility InVisibility)
{
}

void UFortQuickBarSlotBase::SetQuickbarIndexRuntime(int32 Index, bool bRefresh)
{
}

void UFortQuickBarSlotBase::SetQuickbarTypeRuntime(EFortQuickBars NewQuickBarType, bool bRefresh)
{
}

void UFortQuickBarSlotBase::SetTopComboSwitcherVisibility(ESlateVisibility InVisibility)
{
}

void UFortQuickBarSlotBase::UpdateItemCardsVisibility()
{
}

void UFortQuickBarSlotBase::UpdateKeyBindingText()
{
}

void UFortQuickBarSlotBase::UpdateKeyBindingVisibility()
{
}
