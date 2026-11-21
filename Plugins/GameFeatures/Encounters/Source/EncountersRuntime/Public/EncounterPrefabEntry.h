// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "WorldConditionQuery.h"
#include "EncounterPrefabEntry.generated.h"

class UEncounterItemDefinition;

USTRUCT()
struct FEncounterPrefabEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Encounter")
	TObjectPtr<UEncounterItemDefinition> EncounterDefinition;

	UPROPERTY(EditAnywhere, Category="Encounter")
	FGameplayTag EncounterIdentifierTag;

	UPROPERTY(EditAnywhere, Category="Encounter")
	FScalableFloat Weight;

	UPROPERTY(EditAnywhere, Category="Encounter")
	FWorldConditionQueryDefinition CanSpawnCondition;

};

