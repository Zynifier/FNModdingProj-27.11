// Copyright Epic Games, Inc. All Rights Reserved.

#include "STW/FortUIScoreReport.h"

int32 UFortUIScoreReport::GetBadgeScore(UFortItem* BadgeItem) const
{
	return int32();
}

AFortPlayerPawn* UFortUIScoreReport::GetCurrentPlayerPawn(int32 ScoreReportIndex) const
{
	return nullptr;
}

AFortPlayerState* UFortUIScoreReport::GetCurrentPlayerState(int32 ScoreReportIndex) const
{
	return nullptr;
}

float UFortUIScoreReport::GetDifficultBonusMultiplier() const
{
	return float();
}

int32 UFortUIScoreReport::GetDifficultBonusScore() const
{
	return int32();
}

float UFortUIScoreReport::GetLevelProgress(int32 Level, int32 DisplayXp) const
{
	return float();
}

int32 UFortUIScoreReport::GetPlayerCount() const
{
	return int32();
}

void UFortUIScoreReport::GetPlayerIDFromScoreReportIndex(int32 ScoreReportIndex, FUniqueNetIdRepl& OutUniqueNetIdRepl) const
{
}

FText UFortUIScoreReport::GetPlayerName(int32 ScoreReportIndex) const
{
	return FText();
}

FString UFortUIScoreReport::GetPlayerPlatform(int32 ScoreReportIndex) const
{
	return FString();
}

int32 UFortUIScoreReport::GetPlayerScore(int32 ScoreReportIndex, EFortUIScoreType::Type ScoreType) const
{
	return int32();
}

int32 UFortUIScoreReport::GetScoreReportIndex(const FUniqueNetIdRepl& PlayerId) const
{
	return int32();
}

void UFortUIScoreReport::GetScoreReportIndicesByPlayerID(TArray<int32>& SortedScoreReportIndices) const
{
}

int32 UFortUIScoreReport::GetTeamScore(EFortUIScoreType::Type ScoreType) const
{
	return int32();
}

bool UFortUIScoreReport::GetXpInfo(int32 ScoreReportIndex, FFortUIXpInfo& OutXpInfo) const
{
	return false;
}

int32 UFortUIScoreReport::GetXpToCompleteLevel(int32 Level) const
{
	return int32();
}

bool UFortUIScoreReport::IsLocalPlayer(int32 ScoreReportIndex) const
{
	return false;
}
