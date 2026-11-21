// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Missions/FortDifficultyOptionCategoryEncounter.h"
#include "FortDifficultyOptionCategoryEncounter_Breathers.generated.h"

class UFortDifficultyOptionEncounter_Breathers;

UCLASS(HideCategories=("CategorySettings"))
class UFortDifficultyOptionCategoryEncounter_Breathers : public UFortDifficultyOptionCategoryEncounter
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="DifficultyOptions")
	TArray<TSubclassOf<UFortDifficultyOptionEncounter_Breathers>> Options;

};

