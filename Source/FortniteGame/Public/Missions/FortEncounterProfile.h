// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Missions/MissionSaving/MissionSavingTypes.h"
#include "FortEncounterProfile.generated.h"

class UFortDifficultyOptionCategoryEncounter;
class UFortDifficultyOptionSetEncounter;

USTRUCT()
struct FFortEncounterProfile
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortEncounterProfile")
	TSoftObjectPtr<UFortDifficultyOptionSetEncounter> EncounterOptions;

	UPROPERTY(EditDefaultsOnly, Instanced, Category="FortEncounterProfile")
	TArray<TObjectPtr<UFortDifficultyOptionCategoryEncounter>> OverrideCategories;

	UPROPERTY(EditAnywhere, Category="FortEncounterProfile")
	bool bShouldReselectOptionsPerInstance;

	UPROPERTY(EditAnywhere, Category="FortEncounterProfile")
	FGameplayTagContainer EncounterTypeTags;

};

USTRUCT()
struct FFortEncounterSequenceSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortEncounterSequenceSettings")
	FFortEncounterTransitionSettings TransitionSettings;

	UPROPERTY(EditDefaultsOnly, Category="FortEncounterSequenceSettings")
	TArray<FFortEncounterProfile> EncounterSequence;

	UPROPERTY(EditDefaultsOnly, Category="FortEncounterSequenceSettings")
	FGameplayTagContainer SequenceTags;

};

