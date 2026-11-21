// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Missions/FortDifficultyOptionCategoryEncounter.h"
#include "FortDifficultyOptionCategoryEncounter_SpawnPointsBurst.generated.h"

class UFortDifficultyOptionEncounter_SpawnPointsBurst;

UCLASS(HideCategories=("CategorySettings", "CategorySettings"))
class UFortDifficultyOptionCategoryEncounter_SpawnPointsBurst : public UFortDifficultyOptionCategoryEncounter
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="DifficultyOptions")
	TArray<TSubclassOf<UFortDifficultyOptionEncounter_SpawnPointsBurst>> Options;

};

