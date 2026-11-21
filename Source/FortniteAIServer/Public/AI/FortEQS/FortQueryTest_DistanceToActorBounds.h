// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "FortQueryTest_DistanceToActorBounds.generated.h"

class UEnvQueryContext;

UCLASS()
class UFortQueryTest_DistanceToActorBound : public UEnvQueryTest
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Distance")
	TSubclassOf<UEnvQueryContext> DistanceTo;

	UPROPERTY(EditDefaultsOnly, Category="Distance")
	bool bUse2DDistance;

};

