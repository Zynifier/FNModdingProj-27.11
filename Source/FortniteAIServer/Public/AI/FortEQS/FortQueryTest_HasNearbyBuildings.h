// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "FortQueryTest_HasNearbyBuildings.generated.h"

UCLASS()
class UFortQueryTest_HasNearbyBuildings : public UEnvQueryTest
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Building")
	uint8 bIncludeCenter : 1;

	UPROPERTY(EditDefaultsOnly, Category="Building")
	uint8 bIncludeFloors : 1;

	UPROPERTY(EditDefaultsOnly, Category="Building")
	uint8 bIncludeFloorsAbove : 1;

	UPROPERTY(EditDefaultsOnly, Category="Building")
	uint8 bIncludeWalls : 1;

	UPROPERTY(EditDefaultsOnly, Category="Building")
	int32 ExtentXY;

	UPROPERTY(EditDefaultsOnly, Category="Building")
	int32 ExtentZ;

};

