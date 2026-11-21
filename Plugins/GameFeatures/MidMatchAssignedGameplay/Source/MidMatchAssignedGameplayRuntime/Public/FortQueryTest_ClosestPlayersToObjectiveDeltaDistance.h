// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "FortQueryTest_ClosestPlayersToObjectiveDeltaDistance.generated.h"

UCLASS()
class UFortQueryTest_ClosestPlayersToObjectiveDeltaDistance : public UEnvQueryTest
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortQueryTest_ClosestPlayersToObjectiveDeltaDistance")
	bool bUseDistance2D;

};

