// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataProviders/AIDataProvider.h"
#include "EnvironmentQuery/EnvQueryGenerator.h"
#include "GameplayTagContainer.h"
#include "AI/FortAITypes.h"
#include "FortQueryGenerator_GoalTrackableAIObjects.generated.h"

class AActor;
class UEnvQueryContext;

UCLASS(meta=(DisplayName="Goal: Trackable AI Objects"))
class UFortQueryGenerator_GoalTrackableAIObjects : public UEnvQueryGenerator
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Assignment")
	FFortAIAssignmentIdentifier AssignmentIdentifier;

	UPROPERTY(EditDefaultsOnly, Category="FortQueryGenerator_GoalTrackableAIObjects")
	TSubclassOf<AActor> SearchedActorClass;

	UPROPERTY(EditDefaultsOnly, Category="FortQueryGenerator_GoalTrackableAIObjects")
	FGameplayTag RequiredTag;

	UPROPERTY(EditDefaultsOnly, Category="FortQueryGenerator_GoalTrackableAIObjects")
	FAIDataProviderFloatValue SearchRadius;

	UPROPERTY(EditDefaultsOnly, Category="FortQueryGenerator_GoalTrackableAIObjects")
	TSubclassOf<UEnvQueryContext> SearchCenter;

};

