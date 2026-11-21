// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/Generators/EnvQueryGenerator_ProjectedPoints.h"
#include "FortQueryGenerator_PointsOnWaterShoreLine.generated.h"

class UEnvQueryContext;
class UFortQueryData_CurvesAroundLine;

UCLASS(meta=(DisplayName="Points: Around Water Shore Line"))
class UFortQueryGenerator_PointsOnWaterShoreLine : public UEnvQueryGenerator_ProjectedPoints
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Generator")
	TSubclassOf<UEnvQueryContext> GenerateAround;

	UPROPERTY(EditDefaultsOnly, Category="Generator")
	TSoftObjectPtr<UFortQueryData_CurvesAroundLine> CurvesAroundLineAsset;

};

