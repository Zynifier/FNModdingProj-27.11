// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortCreativePropertyWidget.h"

FText UCreativePropertyEditWidgetBase::GetEntryDescriptionText() const
{
	return FText();
}

FText UCreativePropertyEditWidgetBase::GetEntryDisplayName() const
{
	return FText();
}

FText UCreativePropertyEditWidgetBase::GetEntryDisplayValue() const
{
	return FText();
}

bool UCreativePropertyEditWidgetBase::GetIsModified() const
{
	return false;
}

FText UCreativePropertyEditWidgetBase::GetStepperLabelForIndex(const int32 Index) const
{
	return FText();
}

bool UCreativePropertyEditWidgetBase::IsDialogOpen() const
{
	return false;
}

bool UCreativePropertyEditWidgetBase::RefreshGrantedContextTags_Implementation()
{
	return false;
}

void UCreativePropertyEditWidgetBase::RequestCloseDialog(const bool bSetFocusToOptionsList)
{
}

const FText& UCreativePropertyEditWidgetBase::RequestDeviceName() const
{
	static FText Dummy;
	return Dummy;
}

void UCreativePropertyEditWidgetBase::RequestSelected(UObject* ObjectToSelect, const bool bNavigateToItem)
{
}

void UCreativePropertyEditWidgetBase::SetCurrentIndexInStepperValue(int32 InStepperValue)
{
}

void UCreativePropertyEditWidgetBase::SetIsModified(bool bModified)
{
}

FText UCreativePropertyEditWidgetDeviceButtonComponentBase::GetButtonLabel() const
{
	return FText();
}

UFortCreativeDeviceButtonComponent* UCreativePropertyEditWidgetDeviceButtonComponentBase::GetDeviceButtonComponent() const
{
	return nullptr;
}

UObject* UCreativePropertyEditWidgetUserOptionBase::GetInitializingObject() const
{
	return nullptr;
}

void UCreativePropertyEditWidgetDirectNumericInputBase::CheckIsNumeircValueModified()
{
}

void UCreativePropertyEditWidgetDirectNumericInputBase::HandleNumericEntryChanged_Implementation(float InValue)
{
}

void UCreativePropertyEditWidgetDirectNumericInputBase::HandleNumericEntryCommited_Implementation(float InValue, ETextCommit::Type CommitInfo)
{
}

void UCreativePropertyEditWidgetDirectNumericInputBase::OnRotated()
{
}

FString UCreativePropertyEditWidgetDirectNumericInputBase::ParseTeamOrClassOptionsAsString(const FString& OriginalString)
{
	return FString();
}

void UCreativePropertyEditWidgetDirectNumericInputBase::SetNumericEntryEditable(bool bIsEditable)
{
}

void UCreativePropertyEditWidgetDirectNumericInputBase::TryGetCurrentOptionValue(FString& Data) const
{
}

void UCreativePropertyEditWidgetLevelListBase::UpdateCurrentLevelOptionName(const FText& UpdatedLevelName)
{
}

void UCreativePropertyEditWidgetInstancedLevelList::ClientLevelListUpdated()
{
}

void UCreativePropertyEditWidgetInstancedLevelList::HandleNewLevelButtonClicked()
{
}

void UCreativePropertyEditWidgetMessageComponentBase::HandleChannelNumericEntryChanged_Implementation(const FText& Text)
{
}

void UCreativePropertyEditWidgetMessageComponentBase::HandleChannelNumericEntryCommitted_Implementation(const FText& InText, ETextCommit::Type CommitInfo)
{
}

const int32 UCreativePropertyEditWidgetStringBase::GetEntryCharacterLimit() const
{
	return int32();
}

bool UCreativePropertyEditWidgetStringBase::HandlesCharLimitValidation_Implementation() const
{
	return false;
}

FPlaylistOptionTintedIconIntValue UCreativePropertyEditWidgetTintedIconIntBase::GetCustomValueOption() const
{
	return FPlaylistOptionTintedIconIntValue();
}
