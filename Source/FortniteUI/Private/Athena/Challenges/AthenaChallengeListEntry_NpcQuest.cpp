// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Challenges/AthenaChallengeListEntry_NpcQuest.h"

bool UAthenaChallengeListEntry_NpcQuest::GetIsCompleted() const
{
	return false;
}

void UAthenaChallengeListEntry_NpcQuest::HandleObjectiveUpdate(const UFortQuestItem* QuestItem, const FName Objective, const int32 AchievedCount, const int32 GoalCount)
{
}

void UAthenaChallengeListEntry_NpcQuest::HandleQuestSeen(const UFortAccountItem* AccountItem)
{
}

void UAthenaChallengeListEntry_NpcQuest::HandleViewPlaylistButtonClicked()
{
}

bool UAthenaChallengeListEntry_NpcQuest::HasVisibleRewards() const
{
	return false;
}

bool UAthenaChallengeListEntry_NpcQuest::IsChallengeRefreshingDaily() const
{
	return false;
}

bool UAthenaChallengeListEntry_NpcQuest::IsSelected() const
{
	return false;
}

void UAthenaChallengeListEntry_NpcQuest::UpdateIconUL(const FAthenaPinnedQuestData& PinnedQuestData)
{
}
