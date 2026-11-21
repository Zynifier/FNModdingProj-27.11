// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "WorldConditionQuery.h"
#include "FortAthenaLivingWorldDespawnCondition.generated.h"

USTRUCT()
struct FFortAthenaLivingWorldDespawnCondition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortAthenaLivingWorldDespawnCondition")
	FWorldConditionQueryDefinition DespawnWorldCondition;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaLivingWorldDespawnCondition")
	float TimeAsCandidateBeforeDespawn;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaLivingWorldDespawnCondition", meta=(ClampMin="0.0"))
	float TimeAsCandidateBeforeDespawnDeviation;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaLivingWorldDespawnCondition")
	bool bUseCustomDeathTag;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaLivingWorldDespawnCondition", meta=(EditCondition="bUseCustomDeathTag"))
	FGameplayTagContainer DeathTagContainer;

};

