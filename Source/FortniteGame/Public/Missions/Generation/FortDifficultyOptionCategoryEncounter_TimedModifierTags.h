// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Missions/FortDifficultyOptionCategoryEncounter.h"
#include "FortDifficultyOptionCategoryEncounter_TimedModifierTags.generated.h"

class UFortDifficultyOptionEncounter_TimedModifierTags;

UCLASS(HideCategories=("CategorySettings"))
class UFortDifficultyOptionCategoryEncounter_TimedModifierTags : public UFortDifficultyOptionCategoryEncounter
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="DifficultyOptions")
	TArray<TSubclassOf<UFortDifficultyOptionEncounter_TimedModifierTags>> Options;

};

