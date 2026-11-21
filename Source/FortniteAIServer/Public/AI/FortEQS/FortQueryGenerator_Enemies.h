// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataProviders/AIDataProvider.h"
#include "EnvironmentQuery/EnvQueryGenerator.h"
#include "GameplayTagContainer.h"
#include "FortQueryGenerator_Enemies.generated.h"

UCLASS(MinimalAPI, meta=(DisplayName="Goal: Enemies"))
class UFortQueryGenerator_Enemies : public UEnvQueryGenerator
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Generator")
	bool bPerceivedEnemiesOnly;

	UPROPERTY(EditAnywhere, Category="Generator")
	bool bSleepCapableAIUsePerceivedEnemiesOnly;

	UPROPERTY(EditAnywhere, Category="Generator")
	bool bIgnoreDBNOPawns;

	UPROPERTY(EditAnywhere, Category="Generator")
	bool bIgnoreSleepingAIs;

	UPROPERTY(EditAnywhere, Category="Generator", meta=(EditCondition="bPerceivedEnemiesOnly"))
	bool bAddEnemiesFromAbilityRange;

	UPROPERTY(EditAnywhere, Category="Generator", meta=(EditCondition="bAddEnemiesFromAbilityRange"))
	FGameplayTagContainer AbilityTags;

	UPROPERTY(EditAnywhere, Category="Generator", meta=(EditCondition="bAddEnemiesFromAbilityRange"))
	FGameplayTagContainer DistanceTags;

	UPROPERTY(EditAnywhere, Category="Generator")
	FAIDataProviderFloatValue MaxTimeSincePerceived;

};

