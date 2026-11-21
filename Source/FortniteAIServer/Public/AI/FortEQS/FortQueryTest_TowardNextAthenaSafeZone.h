// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataProviders/AIDataProvider.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "FortQueryTest_TowardNextAthenaSafeZone.generated.h"

UCLASS()
class UFortQueryTest_TowardNextAthenaSafeZone : public UEnvQueryTest
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="SafeZone")
	FAIDataProviderIntValue SafeZoneIndex;

	UPROPERTY(EditDefaultsOnly, Category="SafeZone")
	bool bCheckAcceptanceAngleTowardNextCenter;

	UPROPERTY(EditDefaultsOnly, Category="SafeZone", meta=(ClampMax="180.000000", ClampMin="0.000000", EditCondition="bCheckAcceptanceAngleTowardNextCenter", UIMax="180.000000", UIMin="0.000000"))
	float AcceptanceAngleTowardNextCenter;

	UPROPERTY(EditDefaultsOnly, Category="SafeZone")
	TArray<int32> ExclusionSafeZoneIndex;

};

