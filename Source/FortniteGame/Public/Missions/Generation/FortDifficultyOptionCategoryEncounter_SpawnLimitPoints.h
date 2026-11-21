// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Missions/FortDifficultyOptionCategoryEncounter.h"
#include "FortDifficultyOptionCategoryEncounter_SpawnLimitPoints.generated.h"

class UFortDifficultyOptionEncounter_SpawnLimitPoints;

UCLASS(HideCategories=("CategorySettings", "CategorySettings"))
class UFortDifficultyOptionCategoryEncounter_SpawnLimitPoints : public UFortDifficultyOptionCategoryEncounter
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="DifficultyOptions")
	TArray<TSubclassOf<UFortDifficultyOptionEncounter_SpawnLimitPoints>> Options;

};

