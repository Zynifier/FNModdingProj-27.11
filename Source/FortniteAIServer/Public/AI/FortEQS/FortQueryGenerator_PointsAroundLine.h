// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataProviders/AIDataProvider.h"
#include "EnvironmentQuery/Generators/EnvQueryGenerator_ProjectedPoints.h"
#include "FortQueryGenerator_PointsAroundLine.generated.h"

class UEnvQueryContext;
class UFortQueryData_CurvesAroundLine;

UCLASS(meta=(DisplayName="Points: Clusters Around Line"))
class UFortQueryGenerator_PointsAroundLine : public UEnvQueryGenerator_ProjectedPoints
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Generator")
	TSubclassOf<UEnvQueryContext> GenerateAround;

	UPROPERTY(EditAnywhere, Category="Generator")
	FAIDataProviderIntValue MaxPointsPerClusterLocation;

	UPROPERTY(EditAnywhere, Category="Generator")
	FAIDataProviderFloatValue ClusterRadius;

	UPROPERTY(EditDefaultsOnly, Category="Generator")
	TSoftObjectPtr<UFortQueryData_CurvesAroundLine> CurvesAroundLineAsset;

};

