// Copyright Epic Games, Inc. All Rights Reserved.

#include "Events/FortCompetitiveLeaderboardTypes.h"

void UFortEventLeaderboardEntry::DisplayTeamUsernames(const UFortEventLeaderboardEntryData* LeaderboardEntryData)
{
}

void UFortEventLeaderboardEntry::SetPlayerFlag(TSoftObjectPtr<UTexture2D> PlayerFlag)
{
}

bool UFortEventLeaderboardEntryData::DoesLeaderboardHaveQualifiedIcons() const
{
	return false;
}

float UFortEventLeaderboardEntryData::GetAverageMatchScore() const
{
	return float();
}

float UFortEventLeaderboardEntryData::GetAveragePlacement() const
{
	return float();
}

float UFortEventLeaderboardEntryData::GetAverageTrackedStat(const FString& TrackedStatName) const
{
	return float();
}

FString UFortEventLeaderboardEntryData::GetEventId() const
{
	return FString();
}

FString UFortEventLeaderboardEntryData::GetEventWindowId() const
{
	return FString();
}

bool UFortEventLeaderboardEntryData::GetIsMatchPointWinner() const
{
	return false;
}

FString UFortEventLeaderboardEntryData::GetLiveSessionId() const
{
	return FString();
}

int32 UFortEventLeaderboardEntryData::GetNumTeammates() const
{
	return int32();
}

int32 UFortEventLeaderboardEntryData::GetPageIndex() const
{
	return int32();
}

int32 UFortEventLeaderboardEntryData::GetRank() const
{
	return int32();
}

int32 UFortEventLeaderboardEntryData::GetScore() const
{
	return int32();
}

const FString UFortEventLeaderboardEntryData::GetTeamAccountId(int32 Index) const
{
	return FString();
}

FText UFortEventLeaderboardEntryData::GetTeamDisplayNameText() const
{
	return FText();
}

void UFortEventLeaderboardEntryData::GetTeammateDisplayNames(TArray<FString>& DisplayNames) const
{
}

int32 UFortEventLeaderboardEntryData::GetTotalEliminations() const
{
	return int32();
}

int32 UFortEventLeaderboardEntryData::GetTotalMatchesPlayed() const
{
	return int32();
}

int32 UFortEventLeaderboardEntryData::GetTotalPointsForCategory(FName ScoreCategoryId) const
{
	return int32();
}

int32 UFortEventLeaderboardEntryData::GetTotalTrackedStat(const FString& TrackedStatName) const
{
	return int32();
}

int32 UFortEventLeaderboardEntryData::GetTotalVictoryRoyales() const
{
	return int32();
}

bool UFortEventLeaderboardEntryData::ShouldShowQualifiedIcon() const
{
	return false;
}

void UFortEventLeaderboardTeammateEntry::SetPlayerFlag(TSoftObjectPtr<UTexture2D> PlayerFlag)
{
}

void UFortEventLeaderboardTeammateEntry::SetPlayerName(const FString& PlayerName)
{
}
