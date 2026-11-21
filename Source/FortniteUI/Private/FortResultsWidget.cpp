// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortResultsWidget.h"

void UFortResultsWidget::GetRewardsByType(EFortRewardItemType Type, TArray<UFortItem*>& OutRewards)
{
}

int32 UFortResultsWidget::GetTotalMissionPointsEarned()
{
	return int32();
}

EFortCompletionResult UFortResultsWidget::GetZoneCompletionResult() const
{
	return EFortCompletionResult();
}

FText UFortResultsWidget::GetZoneCompletionResultText() const
{
	return FText();
}

void UFortResultsWidget::HandleEmoteClicked(bool& bPassThrough)
{
}

void UFortResultsWidget::HandlePickerCancel(bool& bPassThrough)
{
}

bool UFortResultsWidget::IsDataFinalized() const
{
	return false;
}

void UFortResultsWidget::LogXPData()
{
}

void UFortResultsWidget::RequestExitZone()
{
}

void UFortResultsWidget::SendEndOfRoundFriendInviteAnalytic(const FUniqueNetIdRepl& TargetId, const FString& TargetPlayerName)
{
}

void UFortResultsWidget::SendEndOfRoundScreenAnalytic(const FString& ScreenName, bool Skipped, float TimeSpent)
{
}

void UFortResultsWidget::SendEndOfRoundUpVoteAnalytic(const FUniqueNetIdRepl& TargetId, const FString& TargetPlayerName)
{
}

void UFortResultsWidget::ToggleChat(bool bShow)
{
}

void UFortResultsWidget::TriggerSetupTeleportCameraEvent()
{
}
