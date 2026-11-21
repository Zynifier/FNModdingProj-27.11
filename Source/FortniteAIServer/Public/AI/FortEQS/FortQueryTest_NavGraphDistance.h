// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "FortQueryTest_NavGraphDistance.generated.h"

class UEnvQueryContext;

UCLASS()
class UFortQueryTest_NavGraphDistance : public UEnvQueryTest
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Distance")
	TSubclassOf<UEnvQueryContext> DistanceTo;

};

