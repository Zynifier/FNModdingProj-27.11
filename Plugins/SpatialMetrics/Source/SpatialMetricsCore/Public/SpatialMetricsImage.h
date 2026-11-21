// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SpatialMetricsImage.generated.h"

USTRUCT()
struct FSpatialMetricSampleImageProperties
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 ImageSize;

	UPROPERTY()
	int32 MinWorldUnitsPerPixel;

	UPROPERTY()
	float WorldColorSaturation;

	UPROPERTY()
	float SpatialValueAlpha;

};

