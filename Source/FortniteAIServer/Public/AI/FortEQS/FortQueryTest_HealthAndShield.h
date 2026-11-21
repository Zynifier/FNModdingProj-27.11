// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataProviders/AIDataProvider.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "FortQueryTest_HealthAndShield.generated.h"

UCLASS()
class UFortQueryTest_HealthAndShield : public UEnvQueryTest
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Health and Shield")
	bool bConsiderHealth;

	UPROPERTY(EditDefaultsOnly, Category="Health and Shield")
	FAIDataProviderFloatValue HealthMin;

	UPROPERTY(EditDefaultsOnly, Category="Health and Shield")
	FAIDataProviderFloatValue HealthMax;

	UPROPERTY(EditDefaultsOnly, Category="Health and Shield")
	bool bHealthAsPercent;

	UPROPERTY(EditDefaultsOnly, Category="Health and Shield")
	bool bConsiderShield;

	UPROPERTY(EditDefaultsOnly, Category="Health and Shield")
	FAIDataProviderFloatValue ShieldMin;

	UPROPERTY(EditDefaultsOnly, Category="Health and Shield")
	FAIDataProviderFloatValue ShieldMax;

	UPROPERTY(EditDefaultsOnly, Category="Health and Shield")
	bool bShieldAsPercent;

};

