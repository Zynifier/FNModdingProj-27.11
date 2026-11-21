// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/FortControllerComponent_Collections.h"

UFortControllerComponent_Collections* UFortControllerComponent_Collections::GetCollectionsComponent(const APawn* Pawn, ECollectionsComponentValidityResult& OutIsValid)
{
	return nullptr;
}

void UFortControllerComponent_Collections::OnFishCollected(const FFortItemEntry& ItemEntry, const FFortMcpCollectedFishProperties& FishProperties, FGameplayTag& OutFishCollectionTag, FGameplayTag& OutAnalyticsTag, EFortCollectedState& OutNewSeenState)
{
}
