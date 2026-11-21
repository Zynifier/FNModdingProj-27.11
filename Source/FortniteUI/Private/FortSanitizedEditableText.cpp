// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortSanitizedEditableText.h"

UFortEditableFilteredCountedTextBox::UFortEditableFilteredCountedTextBox(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UFortEditableFilteredCountedTextBox::ForceSetText(const FText& Text)
{
}

FString UFortEditableFilteredCountedTextBox::GetAllowedCharactersAsString() const
{
	return FString();
}

bool UFortEditableFilteredCountedTextBox::GetAllowLineBreaks() const
{
	return false;
}

bool UFortEditableFilteredCountedTextBox::GetAllowStyleEditing() const
{
	return false;
}

int32 UFortEditableFilteredCountedTextBox::GetEntryCharLimit() const
{
	return int32();
}

bool UFortEditableFilteredCountedTextBox::GetIgnoreCharLimitValidation() const
{
	return false;
}

void UFortEditableFilteredCountedTextBox::HandleTextChanged(const FText& Text)
{
}

void UFortEditableFilteredCountedTextBox::HandleTextCommitted(const FText& Text, ETextCommit::Type CommitMethod)
{
}

void UFortEditableFilteredCountedTextBox::SetEntryCharLimit_Implementation(int32 InCharLimit)
{
}

void UFortEditableFilteredCountedTextBox::SetTextWithForcedSanitization(const FText& Text)
{
}

void UFortEditableFilteredCountedTextBox::UpdateCharacterCount()
{
}
