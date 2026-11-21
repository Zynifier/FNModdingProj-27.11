// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "FortQueryTest_DeltaDistance.generated.h"

class UEnvQueryContext;

UCLASS()
class UFortQueryTest_DeltaDistance : public UEnvQueryTest
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortQueryTest_DeltaDistance")
	TSubclassOf<UEnvQueryContext> LocationProviderContext;

	UPROPERTY(EditDefaultsOnly, Category="FortQueryTest_DeltaDistance")
	bool bUseDistance2D;

};

