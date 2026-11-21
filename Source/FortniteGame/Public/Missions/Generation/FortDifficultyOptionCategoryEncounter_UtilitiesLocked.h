// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Missions/FortDifficultyOptionCategoryEncounter.h"
#include "FortDifficultyOptionCategoryEncounter_UtilitiesLocked.generated.h"

class UFortDifficultyOptionEncounter_UtilitiesLocked;

UCLASS(HideCategories=("CategorySettings"))
class UFortDifficultyOptionCategoryEncounter_UtilitiesLocked : public UFortDifficultyOptionCategoryEncounter
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="DifficultyOptions")
	TArray<TSubclassOf<UFortDifficultyOptionEncounter_UtilitiesLocked>> Options;

};

