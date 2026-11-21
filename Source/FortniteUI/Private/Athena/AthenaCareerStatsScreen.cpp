// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/AthenaCareerStatsScreen.h"

void UAthenaCareerStatsScreen::DisplayRankBadge(const FString& HabaneroType, const int32 Habanero)
{
}

void UAthenaCareerStatsScreen::GetLoadedScreenData(const FString& SeasonName, const bool bRanked, const FString& GameMode, const FString& SubMode, FStatPageData& StatPageData, bool& bSuccess)
{
}

FFortHabaneroTier UAthenaCareerStatsScreen::GetRankDisplayData(const FString& HabaneroType, const int32 Habanero)
{
	return FFortHabaneroTier();
}

void UAthenaCareerStatsScreen::GetReplaysButtonDesiredState(bool& bVisible, bool& bEnabled)
{
}

TArray<FString> UAthenaCareerStatsScreen::GetSeasonNames()
{
	return TArray<FString>();
}

void UAthenaCareerStatsScreen::OpenReplaysScreen()
{
}

void UAthenaCareerStatsScreen::RequestToUpdateSeasonStatsIfNeeded(const FString& SeasonName)
{
}
