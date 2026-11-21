// Copyright Epic Games, Inc. All Rights Reserved.

#include "AthenaPlayerMatchReport.h"

void UAthenaPlayerMatchReport::GetLootRewards(TArray<FAthenaMatchLootReward>& LootRewards)
{
}

int32 UAthenaPlayerMatchReport::GetTotalBookXpEarned() const
{
	return int32();
}

int32 UAthenaPlayerMatchReport::GetTotalScoreEarned() const
{
	return int32();
}

int32 UAthenaPlayerMatchReport::GetTotalSeasonalXpEarned() const
{
	return int32();
}

void UAthenaPlayerMatchReport::GetXpRewards(TArray<FAthenaMatchXpReward>& XpRewards)
{
}

UAthenaSeasonItemDefinition* UAthenaSeasonStats::GetSeasonDefintion()
{
	return nullptr;
}
