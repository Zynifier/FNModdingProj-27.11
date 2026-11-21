// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "FortQueryTest_OnFlatSurface.generated.h"

UCLASS()
class UFortQueryTest_OnFlatSurface : public UEnvQueryTest
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="GroundTrace")
	float Radius;

	UPROPERTY(EditDefaultsOnly, Category="GroundTrace")
	float ToleranceZ;

	UPROPERTY(EditDefaultsOnly, Category="GroundTrace")
	float TraceOffsetUp;

	UPROPERTY(EditDefaultsOnly, Category="GroundTrace")
	float TraceOffsetDown;

	UPROPERTY(EditDefaultsOnly, Category="GroundTrace")
	uint32 NumberOfIteration;

};

