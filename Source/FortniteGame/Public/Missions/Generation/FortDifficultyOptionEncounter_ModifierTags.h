// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Missions/FortDifficultyOptionEncounter.h"
#include "FortDifficultyOptionEncounter_ModifierTags.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UFortDifficultyOptionEncounter_ModifierTags : public UFortDifficultyOptionEncounter
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortDifficultyOptionEncounter_ModifierTags")
	FGameplayTagContainer ModifierTags;

};

