// Copyright Epic Games, Inc. All Rights Reserved.

#include "STW/FortTieredCollectionLayout.h"

bool UFortTieredCollectionLayout::GetAllValidTiers(TArray<FFortTierCollectionLayoutOutput>& OutTiers, TArray<FFortTierCollectionLayoutOutput>& OutLockedTiers, const TArray<UFortQuestManager*>& QuestManagers) const
{
	return false;
}

FText UFortTieredCollectionLayout::GetCollectionLayoutDisplayName() const
{
	return FText();
}

int32 UFortTieredCollectionLayout::GetMaxTierUnlocked(const TArray<UFortQuestManager*>& QuestManagers) const
{
	return int32();
}

int32 UFortTieredCollectionLayout::GetMissionPointsForTier(int32 Tier) const
{
	return int32();
}

bool UFortTieredCollectionLayout::GetTierOutput(int32 Tier, FFortTierCollectionLayoutOutput& Output) const
{
	return false;
}

bool UFortTieredCollectionLayout::ShouldUseTierAsRandomSeed() const
{
	return false;
}

void UFortTieredCollectionLayout::UpdatePlayerTierCompletions(int32 CompletedTier, const TArray<UFortQuestManager*>& QuestManagers) const
{
}
