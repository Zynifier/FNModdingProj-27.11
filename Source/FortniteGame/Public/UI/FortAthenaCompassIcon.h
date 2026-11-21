// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateBrush.h"
#include "FortAthenaCompassIcon.generated.h"

USTRUCT(BlueprintType)
struct FFortAthenaCompassIcon
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortAthenaCompassIcon")
	FSlateBrush Brush;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortAthenaCompassIcon")
	float Scale;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortAthenaCompassIcon")
	float MaxPawnDistanceForScaling;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortAthenaCompassIcon", meta=(EditCondition="MaxPawnDistanceForScaling>0"))
	float DistanceForScalingMultiplier_Min;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortAthenaCompassIcon", meta=(EditCondition="MaxPawnDistanceForScaling>0"))
	float DistanceForScalingMultiplier_Max;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortAthenaCompassIcon")
	float YOffset;

};

