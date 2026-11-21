// Copyright Epic Games, Inc. All Rights Reserved.

#include "Creative/FortCoreGamerScoreTracker.h"

int32 UFortCoreGamerScoreTracker::GetGoalScore() const
{
	return int32();
}

int32 UFortCoreGamerScoreTracker::GetHighestOpposingTeamIndex() const
{
	return int32();
}

int32 UFortCoreGamerScoreTracker::GetLocalTeamIndex() const
{
	return int32();
}

TArray<FCoreGamerRankingInfo> UFortCoreGamerScoreTracker::GetRankings(int32& OutLocalRankingArrayIndex) const
{
	return TArray<FCoreGamerRankingInfo>();
}

int32 UFortCoreGamerScoreTracker::GetScoreForPlayer(const APlayerState* InPlayerState) const
{
	return int32();
}

int32 UFortCoreGamerScoreTracker::GetScoreForTeam(const int32 InTeamIndex) const
{
	return int32();
}

void UFortCoreGamerScoreTracker::GetTeamData(int32 DesiredTeamIndex, FMinigameTeam& OutTeam, bool& bFoundTeam) const
{
}

FText UFortCoreGamerScoreTracker::GetTeamName(const int32 InTeamIndex) const
{
	return FText();
}

FText UFortCoreGamerScoreTracker::GetTeamNameForPlayerState(const AFortPlayerState* PlayerState) const
{
	return FText();
}

FText UFortCoreGamerScoreTracker::GetTimeRemainingText(bool& bHasTimeLimit) const
{
	return FText();
}

void UFortCoreGamerScoreTracker::PopulateTeamRows(TArray<UFortCoreGamerScoreTrackerRow*> ScoreTrackerRows)
{
}
