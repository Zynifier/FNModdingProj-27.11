// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SpatialMetric.h"
#include "TestMetric.generated.h"

UCLASS()
class UTestMetric : public USpatialMetric
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 SamplingDistance;

	UPROPERTY()
	float WorldSamplingFactor;

};

