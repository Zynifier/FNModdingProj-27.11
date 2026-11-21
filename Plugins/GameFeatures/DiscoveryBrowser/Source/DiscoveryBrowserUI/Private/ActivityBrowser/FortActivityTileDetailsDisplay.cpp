// Copyright Epic Games, Inc. All Rights Reserved.

#include "ActivityBrowser/FortActivityTileDetailsDisplay.h"

void UFortActivityTileDetailsDisplay::BroadcastOnActivityConfirmed() const
{
}

bool UFortActivityTileDetailsDisplay::DoesActivityRequirePurchase() const
{
	return false;
}

FString UFortActivityTileDetailsDisplay::GetActivityCreatorDisplayText() const
{
	return FString();
}

EFortInvalidActivityReason UFortActivityTileDetailsDisplay::GetInvalidActivityReason() const
{
	return EFortInvalidActivityReason();
}

EFortActivityIsLockedReason UFortActivityTileDetailsDisplay::GetIsActivityLockedReason() const
{
	return EFortActivityIsLockedReason();
}

void UFortActivityTileDetailsDisplay::HandleActivitySelected()
{
}

void UFortActivityTileDetailsDisplay::HandleShowActivityDetails()
{
}

bool UFortActivityTileDetailsDisplay::IsActivityFavorited() const
{
	return false;
}

bool UFortActivityTileDetailsDisplay::IsActivityLocked() const
{
	return false;
}

bool UFortActivityTileDetailsDisplay::IsModeSetActivity() const
{
	return false;
}

void UFortActivityTileDetailsDisplay::StartTileVideo()
{
}

void UFortActivityTileDetailsDisplay::StopTileVideo()
{
}

void UFortActivityTileDetailsDisplay::UpdateActivitySelector()
{
}

void UFortActivityTileDetailsDisplay::UpdateFromFortActivityViewModel()
{
}
