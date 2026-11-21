// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Missions/FortDifficultyOptionCategoryEncounter.h"
#include "FortDifficultyOptionCategoryEncounter_IntensityCurveSequence.generated.h"

class UFortDifficultyOptionEncounter_IntensityCurveSequence;

UCLASS(HideCategories=("CategorySettings", "CategorySettings"))
class UFortDifficultyOptionCategoryEncounter_IntensityCurveSequence : public UFortDifficultyOptionCategoryEncounter
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="DifficultyOptions")
	TArray<TSubclassOf<UFortDifficultyOptionEncounter_IntensityCurveSequence>> Options;

};

