// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataProviders/AIDataProvider.h"
#include "EnvironmentQuery/Generators/EnvQueryGenerator_ProjectedPoints.h"
#include "FortQueryGenerator_PointsOutsideBox.generated.h"

class UEnvQueryContext;

UCLASS(meta=(DisplayName="Points: Outside Box"))
class UFortQueryGenerator_PointsOutsideBox : public UEnvQueryGenerator_ProjectedPoints
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Generator")
	FAIDataProviderFloatValue SpaceBetween;

	UPROPERTY(EditDefaultsOnly, Category="Generator")
	FAIDataProviderFloatValue NumberOfRingsAroundVolume;

	UPROPERTY(EditDefaultsOnly, Category="Generator")
	FAIDataProviderFloatValue ExtraXExtent;

	UPROPERTY(EditDefaultsOnly, Category="Generator")
	FAIDataProviderFloatValue ExtraYExtent;

	UPROPERTY(EditDefaultsOnly, Category="Generator")
	FAIDataProviderFloatValue ExtraZExtent;

	UPROPERTY(EditDefaultsOnly, Category="Generator")
	TSubclassOf<UEnvQueryContext> GenerateInBoxCenter;

	UPROPERTY(EditDefaultsOnly, Category="Generator")
	TSubclassOf<UEnvQueryContext> GenerateInBoxExtent;

};

