// Copyright Epic Games, Inc. All Rights Reserved.

#include "SquadManagement/FortSquadSlotsView.h"

void UFortSquadSlotSelectorButton::GetIdOfSquadSlotToManageBP(FName& OutSquadId, int32& OutSquadSlotIndex) const
{
}

bool UFortSquadSlotSelectorButton::GetInPreviewMode() const
{
	return false;
}

UUserWidget* UFortSquadSlotSelectorButton::GetPopupMenu()
{
	return nullptr;
}

bool UFortSquadSlotSelectorButton::IsSquadSlotLockedBP() const
{
	return false;
}

void UFortSquadSlotSelectorButton::OpenSquadSlot()
{
}

void UFortSquadSlotSelectorButton::SetIdOfSquadSlotToManageBP(const FName& SquadId, const int32 SquadSlotIndex)
{
}

void UFortSquadSlotSelectorButton::SquadSlotWidgetUpdated_Implementation()
{
}

void UFortSquadSlotSelectorButton::ViewInAll()
{
}

FName UFortSquadSlotsView::GetIdOfSquadToManageBP() const
{
	return FName();
}

int32 UFortSquadSlotsView::GetIndexOfSelectedSquadSlot() const
{
	return int32();
}

void UFortSquadSlotsView::HandleButtonClicked(UCommonButtonLegacy* CommittedButton, int32 ButtonIndex)
{
}

void UFortSquadSlotsView::HandleButtonDoubleClicked(UCommonButtonLegacy* CommittedButton, int32 ButtonIndex)
{
}

void UFortSquadSlotsView::HandleHoveredButtonChanged(UCommonButtonLegacy* HoveredButton, int32 ButtonIndex)
{
}

void UFortSquadSlotsView::HandleRequestOpenSquadSlot(int32 SquadSlotIndex)
{
}

void UFortSquadSlotsView::HandleRequestViewInAll(int32 SquadSlotIndex)
{
}

void UFortSquadSlotsView::HandleSelectedButtonChanged(UCommonButtonLegacy* SelectedButton, int32 ButtonIndex)
{
}

void UFortSquadSlotsView::SelectSlot(int32 SquadSlotIndex)
{
}

void UFortSquadSlotsView::SetIdOfSquadToManageBP(const FName& SquadId)
{
}

void UFortSquadSlotsView::SetInPreviewMode(const bool bPreview)
{
}

void UFortSquadSlotsView::SetIsSelectionLocked(const bool ShouldSelectionBeLocked)
{
}

bool UFortSquadSlotsView::TryGetSelectedSquadSlotSortTypes(FSquadSlotSortTypes& OutSlotSortTypes)
{
	return false;
}

bool UFortSquadSlotsView::TryGetStaticSquadDataBP(FHomebaseSquad& OutSquadData) const
{
	return false;
}
