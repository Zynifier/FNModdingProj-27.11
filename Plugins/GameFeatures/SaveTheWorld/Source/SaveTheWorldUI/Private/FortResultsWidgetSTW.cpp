// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortResultsWidgetSTW.h"

void UFortResultsWidgetSTW::GetRewardsByType(EFortRewardItemTypeSTW Type, TArray<UFortItem*>& OutRewards)
{
}

int32 UFortResultsWidgetSTW::GetTotalMissionPointsEarned()
{
	return int32();
}

EFortCompletionResult UFortResultsWidgetSTW::GetZoneCompletionResult() const
{
	return EFortCompletionResult();
}

FText UFortResultsWidgetSTW::GetZoneCompletionResultText() const
{
	return FText();
}

void UFortResultsWidgetSTW::HandleEmoteClicked(bool& bPassThrough)
{
}

void UFortResultsWidgetSTW::HandlePickerCancel(bool& bPassThrough)
{
}

bool UFortResultsWidgetSTW::IsDataFinalized() const
{
	return false;
}

void UFortResultsWidgetSTW::LogXPData()
{
}

void UFortResultsWidgetSTW::RequestExitZone()
{
}

void UFortResultsWidgetSTW::SendEndOfRoundFriendInviteAnalytic(const FUniqueNetIdRepl& TargetId, const FString& TargetPlayerName)
{
}

void UFortResultsWidgetSTW::SendEndOfRoundScreenAnalytic(const FString& ScreenName, bool Skipped, float TimeSpent)
{
}

void UFortResultsWidgetSTW::SendEndOfRoundUpVoteAnalytic(const FUniqueNetIdRepl& TargetId, const FString& TargetPlayerName)
{
}

void UFortResultsWidgetSTW::ToggleChat(bool bShow)
{
}

void UFortResultsWidgetSTW::TriggerSetupTeleportCameraEvent()
{
}
