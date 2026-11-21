// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "FortSpline.generated.h"

USTRUCT()
struct FFortSplineBase
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	float StartTime;

	UPROPERTY()
	float Duration;

};

USTRUCT()
struct FFortCatmullRomSpline : public FFortSplineBase
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TArray<FVector> ControlPoints;

};

