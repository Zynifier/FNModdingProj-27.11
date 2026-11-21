// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataProviders/AIDataProvider.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "FortQueryTest_InsideAthenaSafeZone.generated.h"

UCLASS()
class UFortQueryTest_InsideAthenaSafeZone : public UEnvQueryTest
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="SafeZone")
	bool bUseCurrentSafeZoneIndicatorRadius;

	UPROPERTY(EditDefaultsOnly, Category="SafeZone", meta=(EditCondition="!bUseCurrentSafeZoneIndicatorRadius"))
	FAIDataProviderIntValue SafeZoneIndex;

	UPROPERTY(EditDefaultsOnly, Category="SafeZone", meta=(EditCondition="!bUseCurrentSafeZoneIndicatorRadius"))
	bool bNextSafeZone;

};

