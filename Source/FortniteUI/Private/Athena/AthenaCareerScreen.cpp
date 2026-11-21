// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/AthenaCareerScreen.h"

TArray<FString> UAthenaCareerScreen::GetSeasonNames()
{
	return TArray<FString>();
}

void UAthenaCareerScreen::OpenReplaysScreen()
{
}

FStatPageData UAthenaCareerScreen::RequestScreenData(const FString& SeasonName, const bool bRanked, const FString& GameMode, const FString& SubMode)
{
	return FStatPageData();
}

void UAthenaCareerScreen::RequestToUpdateSeasonStatsIfNeeded(const FString& SeasonName)
{
}
