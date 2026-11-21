// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataProviders/AIDataProvider.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "FortQueryTest_HasNearbyEncounterGoals.generated.h"

UCLASS()
class UFortQueryTest_HasNearbyEncounterGoals : public UEnvQueryTest
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Encounters")
	uint8 bOnlyActiveEncounters : 1;

	UPROPERTY(EditDefaultsOnly, Category="Encounters")
	FAIDataProviderFloatValue TestDistance;

};

