// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Missions/FortDifficultyOptionEncounter.h"
#include "FortDifficultyOptionEncounter_TimedModifierTags.generated.h"

USTRUCT()
struct FFortAIEncounterTimedModifierTags
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortAIEncounterTimedModifierTags")
	float TimeSeconds;

	UPROPERTY(EditDefaultsOnly, Category="FortAIEncounterTimedModifierTags")
	FGameplayTagContainer GameplayTags;

};

UCLASS(BlueprintType, Blueprintable)
class UFortDifficultyOptionEncounter_TimedModifierTags : public UFortDifficultyOptionEncounter
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortDifficultyOptionEncounter_TimedModifierTags")
	TArray<FFortAIEncounterTimedModifierTags> TimedModifierTags;

};

