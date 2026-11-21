// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataProviders/AIDataProvider.h"
#include "EnvironmentQuery/Generators/EnvQueryGenerator_ProjectedPoints.h"
#include "FortQueryGenerator_RandomPointsInBoundingVolume.generated.h"

class UEnvQueryContext;

UCLASS(meta=(DisplayName="Points: Random Points Inside Bounding Volumes"))
class UFortQueryGenerator_RandomPointsInBoundingVolume : public UEnvQueryGenerator_ProjectedPoints
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Generator")
	TSubclassOf<UEnvQueryContext> GenerateIn;

	UPROPERTY(EditDefaultsOnly, Category="Generator", meta=(DisplayName="RandomPointsCount"))
	FAIDataProviderFloatValue RandomPointsCount;

};

