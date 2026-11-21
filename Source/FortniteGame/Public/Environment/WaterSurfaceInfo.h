// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "WaterSurfaceInfo.generated.h"

USTRUCT(BlueprintType)
struct FWaterSurfaceInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WaterBody")
	FVector WaterPlaneLocation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WaterBody")
	FVector WaterPlaneNormal;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WaterBody")
	FVector WaterSurfaceLocation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WaterBody")
	float WaterDepth;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WaterBody")
	int32 WaterBodyIdx;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WaterBody")
	FVector WaterVelocity;

};

