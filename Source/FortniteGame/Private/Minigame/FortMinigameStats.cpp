// Copyright Epic Games, Inc. All Rights Reserved.

#include "Minigame/FortMinigameStats.h"

int32 UFortMinigameStatFilter::Accumulate_Implementation(int32 A, int32 B) const
{
	return int32();
}

int32 UFortMinigameStatFilter::Compare_Implementation(int32 FirstScore, int32 SecondScore) const
{
	return int32();
}

FText UFortMinigameStatFilter::FormatStat_Implementation(int32 InCount) const
{
	return FText();
}

bool UFortMinigameStatFilter::Matches_Implementation(EFortQuestObjectiveStatEvent InStatEvent, UObject* InTargetObject, AController* InPlayerController, const FGameplayTagContainer& InTargetTags, const FGameplayTagContainer& InSourceTags, const FGameplayTagContainer& InContextTags) const
{
	return false;
}
