// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataProviders/AIDataProvider.h"
#include "EnvironmentQuery/EnvQueryGenerator.h"
#include "GameplayTagContainer.h"
#include "AI/FortAITypes.h"
#include "FortQueryGenerator_LootGoalsAthena.generated.h"

class UEnvQueryContext;
class UFortAIAssignmentSettings;

UCLASS(meta=(DisplayName="Goal: Loot (Athena)"))
class UFortQueryGenerator_LootGoalsAthena : public UEnvQueryGenerator
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Assignment")
	FFortAIAssignmentIdentifier AssignmentIdentifier;

	UPROPERTY(EditAnywhere, Category="Assignment")
	TObjectPtr<UFortAIAssignmentSettings> AssignmentSettings;

	UPROPERTY(EditDefaultsOnly, Category="FortQueryGenerator_LootGoalsAthena")
	FAIDataProviderFloatValue HorizontalHalfExtents;

	UPROPERTY(EditDefaultsOnly, Category="FortQueryGenerator_LootGoalsAthena")
	FAIDataProviderFloatValue VerticalHalfExtents;

	UPROPERTY(EditDefaultsOnly, Category="FortQueryGenerator_LootGoalsAthena")
	TSubclassOf<UEnvQueryContext> SearchCenter;

	UPROPERTY(EditDefaultsOnly, Category="FortQueryGenerator_LootGoalsAthena")
	uint8 bAvailableLootOnly : 1;

	UPROPERTY(EditDefaultsOnly, Category="FortQueryGenerator_LootGoalsAthena")
	FGameplayTagContainer ExcludedAILootGameplayTags;

};

