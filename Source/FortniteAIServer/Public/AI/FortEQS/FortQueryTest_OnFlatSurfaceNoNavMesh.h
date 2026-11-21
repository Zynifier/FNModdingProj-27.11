// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "FortQueryTest_OnFlatSurfaceNoNavMesh.generated.h"

class AActor;

UCLASS()
class UFortQueryTest_OnFlatSurfaceNoNavMesh : public UEnvQueryTest
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Trace Details", meta=(ClampMin="0.0", UIMin="0.0"))
	float Radius;

	UPROPERTY(EditDefaultsOnly, Category="Trace Details", meta=(ClampMin="0.0", UIMin="0.0"))
	float ZTolerance;

	UPROPERTY(EditDefaultsOnly, Category="Trace Details", meta=(ClampMax="90.0", ClampMin="0.0", UIMax="90.0", UIMin="0.0"))
	float NormalTolerance;

	UPROPERTY(EditDefaultsOnly, Category="Trace Details", meta=(ClampMin="0.0", UIMin="0.0"))
	float TraceOffset;

	UPROPERTY(EditDefaultsOnly, Category="FortQueryTest_OnFlatSurfaceNoNavMesh")
	TArray<TSubclassOf<AActor>> ActorClassesToIgnoreInTrace;

};

