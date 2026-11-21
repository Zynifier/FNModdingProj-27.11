// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Math/UnitConversion.h"
#include "Misc/DateTime.h"
#include "UObject/NoExportTypes.h"
#include "SpatialMetric.generated.h"

USTRUCT()
struct FSpatialMetricProperties
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FName IdName;

	UPROPERTY()
	int32 MinValue;

	UPROPERTY()
	int32 MaxValue;

	UPROPERTY()
	int32 ThresholdValue;

	UPROPERTY()
	int32 SpatialPrecision;

	UPROPERTY()
	EUnit Unit;

};

USTRUCT()
struct FSpatialValue
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FIntVector Location;

	UPROPERTY()
	int32 Value;

};

USTRUCT()
struct FSpatialMetricSample
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FSpatialMetricProperties Properties;

	UPROPERTY()
	TArray<FSpatialValue> Values;

	UPROPERTY()
	FIntVector BoundsMin;

	UPROPERTY()
	FIntVector BoundsMax;

	UPROPERTY()
	FDateTime TimeStamp;

};

UCLASS()
class SPATIALMETRICSCORE_API USpatialMetric : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FSpatialMetricProperties Properties;

};

