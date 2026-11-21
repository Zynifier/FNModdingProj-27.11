// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataProviders/AIDataProvider.h"
#include "AI/EnvironmentQuery/Generators/FortEnvQueryGenerator_ProjectedPoints.h"
#include "FortEnvQueryGenerator_SimpleGrid.generated.h"

class UEnvQueryContext;

UCLASS(meta=(DisplayName="(Fort) Points: Grid"))
class UFortEnvQueryGenerator_SimpleGrid : public UFortEnvQueryGenerator_ProjectedPoints
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Generator", meta=(DisplayName="GridHalfSize"))
	FAIDataProviderFloatValue GridSize;

	UPROPERTY(EditDefaultsOnly, Category="Generator")
	FAIDataProviderFloatValue SpaceBetween;

	UPROPERTY(EditDefaultsOnly, Category="Generator")
	TSubclassOf<UEnvQueryContext> GenerateAround;

};

