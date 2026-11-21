// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataProviders/AIDataProvider.h"
#include "EnvironmentQuery/EnvQueryGenerator.h"
#include "FortQueryGenerator_TerrainDonut.generated.h"

class UEnvQueryContext;

UCLASS(meta=(DisplayName="Points: Terrain Donut"))
class UFortQueryGenerator_TerrainDonut : public UEnvQueryGenerator
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Generator")
	TSubclassOf<UEnvQueryContext> Center;

	UPROPERTY(EditDefaultsOnly, Category="Generator")
	FAIDataProviderFloatValue Radius;

	UPROPERTY(EditDefaultsOnly, Category="Generator")
	FAIDataProviderFloatValue RadiusWidth;

	UPROPERTY(EditDefaultsOnly, Category="Generator")
	FAIDataProviderFloatValue SpacingArc;

	UPROPERTY(EditDefaultsOnly, Category="Generator")
	FAIDataProviderIntValue NumRings;

	UPROPERTY(EditDefaultsOnly, Category="Generator")
	uint8 bFilterAllowTerrain : 1;

	UPROPERTY(EditDefaultsOnly, Category="Generator")
	uint8 bFilterAllowBuildings : 1;

};

