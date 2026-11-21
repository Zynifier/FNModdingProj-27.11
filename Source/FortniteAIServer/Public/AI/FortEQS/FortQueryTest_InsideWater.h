// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "FortQueryTest_InsideWater.generated.h"

UCLASS()
class UFortQueryTest_InsideWater : public UEnvQueryTest
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortQueryTest_InsideWater")
	float TestRadius;

};

