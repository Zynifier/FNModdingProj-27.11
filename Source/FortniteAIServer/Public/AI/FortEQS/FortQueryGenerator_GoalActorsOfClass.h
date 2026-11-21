// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataProviders/AIDataProvider.h"
#include "EnvironmentQuery/EnvQueryGenerator.h"
#include "FortQueryGenerator_GoalActorsOfClass.generated.h"

class AActor;
class UEnvQueryContext;

UCLASS(meta=(DisplayName="Goal: Actors Of Class"))
class UFortQueryGenerator_GoalActorsOfClass : public UEnvQueryGenerator
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortQueryGenerator_GoalActorsOfClass")
	TSubclassOf<AActor> SearchedActorClass;

	UPROPERTY(EditDefaultsOnly, Category="FortQueryGenerator_GoalActorsOfClass")
	FAIDataProviderFloatValue SearchRadius;

	UPROPERTY(EditDefaultsOnly, Category="FortQueryGenerator_GoalActorsOfClass")
	TSubclassOf<UEnvQueryContext> SearchCenter;

};

