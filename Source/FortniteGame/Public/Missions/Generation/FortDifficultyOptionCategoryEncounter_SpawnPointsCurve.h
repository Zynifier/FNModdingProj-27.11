// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Missions/FortDifficultyOptionCategoryEncounter.h"
#include "FortDifficultyOptionCategoryEncounter_SpawnPointsCurve.generated.h"

class UFortDifficultyOptionEncounter_SpawnPointsCurve;

UCLASS(HideCategories=("CategorySettings", "CategorySettings"))
class UFortDifficultyOptionCategoryEncounter_SpawnPointsCurve : public UFortDifficultyOptionCategoryEncounter
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="DifficultyOptions")
	TArray<TSubclassOf<UFortDifficultyOptionEncounter_SpawnPointsCurve>> Options;

};

