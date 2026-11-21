// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Missions/FortDifficultyOptionCategoryEncounter.h"
#include "FortDifficultyOptionCategoryEncounter_SpawnGroupProgression.generated.h"

class UFortDifficultyOptionEncounter_SpawnGroupProgression;

UCLASS(HideCategories=("CategorySettings"))
class UFortDifficultyOptionCategoryEncounter_SpawnGroupProgression : public UFortDifficultyOptionCategoryEncounter
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TSubclassOf<UFortDifficultyOptionEncounter_SpawnGroupProgression> SpawnGroupProgression;

	UPROPERTY(EditDefaultsOnly, Category="DifficultyOptions")
	TArray<TSubclassOf<UFortDifficultyOptionEncounter_SpawnGroupProgression>> Options;

};

