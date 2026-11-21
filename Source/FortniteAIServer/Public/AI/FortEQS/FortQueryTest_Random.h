// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "FortQueryTest_Random.generated.h"

UCLASS()
class UFortQueryTest_Random : public UEnvQueryTest
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Test")
	uint8 bUseRandomSeedForAI : 1;

	UPROPERTY(EditDefaultsOnly, Category="Test")
	uint8 bUseRandomSeedForOthers : 1;

};

