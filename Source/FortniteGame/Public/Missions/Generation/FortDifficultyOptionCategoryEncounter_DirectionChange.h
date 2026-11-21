// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Missions/FortDifficultyOptionCategoryEncounter.h"
#include "FortDifficultyOptionCategoryEncounter_DirectionChange.generated.h"

class UFortDifficultyOptionEncounter_DirectionChange;

UCLASS(HideCategories=("CategorySettings"))
class UFortDifficultyOptionCategoryEncounter_DirectionChange : public UFortDifficultyOptionCategoryEncounter
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="DifficultyOptions")
	TArray<TSubclassOf<UFortDifficultyOptionEncounter_DirectionChange>> Options;

};

