// Copyright Epic Games, Inc. All Rights Reserved.

#include "DiscoveryShared/FortActivityDetailsDisplay.h"

void UFortActivityDetailsDisplay::AcceptActivity()
{
}

TArray<FString> UFortActivityDetailsDisplay::GetContentWarningStrings() const
{
	return TArray<FString>();
}

FText UFortActivityDetailsDisplay::GetCreatorTextFormat_Implementation(const FText& CreatorName)
{
	return FText();
}

EFortInvalidActivityReason UFortActivityDetailsDisplay::GetInvalidActivityReason() const
{
	return EFortInvalidActivityReason();
}

const UFortGameActivity* UFortActivityDetailsDisplay::GetSelectedGameActivity() const
{
	return nullptr;
}

bool UFortActivityDetailsDisplay::IsActivityEpicCreated() const
{
	return false;
}

bool UFortActivityDetailsDisplay::IsActivityEpicOriginal() const
{
	return false;
}

bool UFortActivityDetailsDisplay::IsDisplayingCategory() const
{
	return false;
}

bool UFortActivityDetailsDisplay::IsDownloadRequired() const
{
	return false;
}

void UFortActivityDetailsDisplay::OnOutroAnimationFinished()
{
}

void UFortActivityDetailsDisplay::ToggleFavorite()
{
}
