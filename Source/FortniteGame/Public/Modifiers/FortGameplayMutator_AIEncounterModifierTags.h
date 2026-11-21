// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Missions/MissionTypes.h"
#include "Modifiers/FortGameplayMutator.h"
#include "FortGameplayMutator_AIEncounterModifierTags.generated.h"

USTRUCT()
struct FFortEncounterMutatorReplacedTag
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortEncounterMutatorReplacedTag")
	FGameplayTagContainer TagsToRemove;

	UPROPERTY(EditDefaultsOnly, Category="FortEncounterMutatorReplacedTag")
	FGameplayTagContainer TagsToAdd;

};

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortGameplayMutator_AIEncounterModifierTags : public AFortGameplayMutator
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Mutator")
	FGameplayTagContainer GameplayTags;

	UPROPERTY(EditDefaultsOnly, Category="Mutator")
	TArray<FFortEncounterMutatorReplacedTag> TagsToReplace;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Mutator")
	TEnumAsByte<EFortMissionType::Type> RequiredEncounterAssociatedMissionType;

};

