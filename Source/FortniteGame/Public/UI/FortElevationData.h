// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "FortElevationData.generated.h"

USTRUCT(BlueprintType)
struct FElevationArrowData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ElevationArrowData")
	bool bShowElevationArrow;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ElevationArrowData")
	bool bOverrideDefaultBehavior;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ElevationArrowData", meta=(EditCondition="bOverrideDefaultBehavior"))
	float ElevationDifferenceZ;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ElevationArrowData", meta=(EditCondition="bOverrideDefaultBehavior"))
	float MaxDistanceToDisplay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ElevationArrowData", meta=(EditCondition="bOverrideDefaultBehavior"))
	FLinearColor IndicatorColor;

};

