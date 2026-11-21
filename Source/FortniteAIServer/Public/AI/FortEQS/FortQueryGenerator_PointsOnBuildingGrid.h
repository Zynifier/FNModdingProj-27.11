// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataProviders/AIDataProvider.h"
#include "EnvironmentQuery/Generators/EnvQueryGenerator_ProjectedPoints.h"
#include "FortQueryGenerator_PointsOnBuildingGrid.generated.h"

class UEnvQueryContext;

UCLASS(meta=(DisplayName="Points: Using Building Grid"))
class UFortQueryGenerator_PointsOnBuildingGrid : public UEnvQueryGenerator_ProjectedPoints
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Generator")
	FAIDataProviderIntValue HorizontalGridSize;

	UPROPERTY(EditAnywhere, Category="Generator")
	FAIDataProviderIntValue VerticalGridSize;

	UPROPERTY(EditDefaultsOnly, Category="Generator")
	bool bStartGridFromBottom;

	UPROPERTY(EditDefaultsOnly, Category="Generator")
	bool bUsePointInVerticalCenterOfCell;

	UPROPERTY(EditDefaultsOnly, Category="Generator")
	TSubclassOf<UEnvQueryContext> GenerateAround;

};

