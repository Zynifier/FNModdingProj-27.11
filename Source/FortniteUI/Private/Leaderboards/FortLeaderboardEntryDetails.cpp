// Copyright Epic Games, Inc. All Rights Reserved.

#include "Leaderboards/FortLeaderboardEntryDetails.h"

const FText UFortLeaderboardEntryDetails::GetAlternativeLeaderboardTrackedStatLabel(const FString& TrackedStatName) const
{
	return FText();
}

const TArray<FString> UFortLeaderboardEntryDetails::GetAlternativeLeaderboardTrackedStats(const FString& TournamentId, const FString& EventWindowId, const FString& LeaderboardGroupingKey, const FString& LeaderboardInstanceId) const
{
	return TArray<FString>();
}

void UFortLeaderboardEntryDetails::WatchLiveMatch(const FString& SessionId)
{
}
