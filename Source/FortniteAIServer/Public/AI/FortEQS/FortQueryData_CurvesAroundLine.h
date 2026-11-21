// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FortQueryData_CurvesAroundLine.generated.h"

class UCurveFloat;

USTRUCT()
struct FFortPointOnCurveRange
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortPointOnCurveRange")
	float MinPercentage;

	UPROPERTY(EditDefaultsOnly, Category="FortPointOnCurveRange")
	float MaxPercentage;

};

USTRUCT()
struct FFortPointsOnCurve
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortPointsOnCurve")
	TSoftObjectPtr<UCurveFloat> Curve;

	UPROPERTY(EditDefaultsOnly, Category="FortPointsOnCurve")
	TArray<FFortPointOnCurveRange> RangesForPointsOnCurve;

};

UCLASS(meta=(DisplayName="Points on Curves around Line"))
class UFortQueryData_CurvesAroundLine : public UDataAsset
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="FortQueryData_CurvesAroundLine")
	FFortPointsOnCurve PointsOnSideA;

	UPROPERTY(EditDefaultsOnly, Category="FortQueryData_CurvesAroundLine")
	FFortPointsOnCurve PointsOnSideB;

};

