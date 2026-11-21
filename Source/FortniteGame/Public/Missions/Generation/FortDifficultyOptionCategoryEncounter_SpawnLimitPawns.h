// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Missions/FortDifficultyOptionCategoryEncounter.h"
#include "FortDifficultyOptionCategoryEncounter_SpawnLimitPawns.generated.h"

class UFortDifficultyOptionEncounter_SpawnLimitPawns;

UCLASS(HideCategories=("CategorySettings", "CategorySettings"))
class UFortDifficultyOptionCategoryEncounter_SpawnLimitPawns : public UFortDifficultyOptionCategoryEncounter
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="DifficultyOptions")
	TArray<TSubclassOf<UFortDifficultyOptionEncounter_SpawnLimitPawns>> Options;

};

