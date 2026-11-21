// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortCreativeMessageKnobsDialog.h"

bool UFortCreativeMessageKnobsDialog::CheckDestructiveSettings()
{
	return false;
}

void UFortCreativeMessageKnobsDialog::CloseDialog(const bool bSetFocusToOptionsList)
{
}

bool UFortCreativeMessageKnobsDialog::ContainsItem() const
{
	return false;
}

void UFortCreativeMessageKnobsDialog::DisableFilters()
{
}

void UFortCreativeMessageKnobsDialog::FilterEntriesByIsModified(bool bShowUnmodifiedEntries, bool UpdateSelection)
{
}

void UFortCreativeMessageKnobsDialog::FilterEntriesByString(const FString& FilterString, bool UpdateSelection)
{
}

void UFortCreativeMessageKnobsDialog::FilterEntriesByTag(FGameplayTagContainer Tags, bool UpdateSelection)
{
}

void UFortCreativeMessageKnobsDialog::GenerateFilteredEntries(bool bUpdateSelectionForGamepad, bool bUpdateSelectionForMouse)
{
}

FText UFortCreativeMessageKnobsDialog::GetClearItemsConfirmationText() const
{
	return FText();
}

UAthenaConfirmationWindow* UFortCreativeMessageKnobsDialog::GetConfirmationDialogWidget()
{
	return nullptr;
}

ESlateVisibility UFortCreativeMessageKnobsDialog::GetDesiredAdditionalActionButtonsVisiblity(const ESlateVisibility RequestedVisibility) const
{
	return ESlateVisibility();
}

int32 UFortCreativeMessageKnobsDialog::GetItemCount() const
{
	return int32();
}

void UFortCreativeMessageKnobsDialog::HandleClearItemsClicked()
{
}

void UFortCreativeMessageKnobsDialog::HandleDeviceBrowserButtonPressed()
{
}

bool UFortCreativeMessageKnobsDialog::HasClearItemsConfirmation() const
{
	return false;
}

bool UFortCreativeMessageKnobsDialog::IsAnyFilterActive()
{
	return false;
}

void UFortCreativeMessageKnobsDialog::NativeHandleOnRenameInput() const
{
}

void UFortCreativeMessageKnobsDialog::RefreshTagFilterForGrantedContextTags(bool bRefreshOnlyWhenChanged, bool bUpdateSelectionForGamepad, bool bUpdateSelectForMouse)
{
}

void UFortCreativeMessageKnobsDialog::RefreshUIOnDeviceButtonClicked()
{
}

void UFortCreativeMessageKnobsDialog::RemoveIsModifiedFilter(bool UpdateSelection)
{
}

void UFortCreativeMessageKnobsDialog::RemoveStringFilter(bool UpdateSelection)
{
}

void UFortCreativeMessageKnobsDialog::RemoveTagFilter(bool UpdateSelection)
{
}

void UFortCreativeMessageKnobsDialog::SetFocusToItem(UObject* Item)
{
}

bool UFortCreativeMessageKnobsDialog::ShouldShowAdditonalActionButtons() const
{
	return false;
}
