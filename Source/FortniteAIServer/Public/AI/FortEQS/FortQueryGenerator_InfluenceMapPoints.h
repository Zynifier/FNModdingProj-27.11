// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataProviders/AIDataProvider.h"
#include "EnvironmentQuery/Generators/EnvQueryGenerator_ProjectedPoints.h"
#include "FortQueryGenerator_InfluenceMapPoints.generated.h"

class UEnvQueryContext;

UCLASS(HideCategories=("Generator"), meta=(DisplayName="Points: Using Influence Map"))
class UFortQueryGenerator_InfluenceMapPoints : public UEnvQueryGenerator_ProjectedPoints
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="GraphGenerator", meta=(ClampMax="16", ClampMin="1"))
	FAIDataProviderIntValue Density;

	UPROPERTY(EditDefaultsOnly, Category="GraphGenerator")
	uint8 bOnlyFlatSurface : 1;

	UPROPERTY(EditDefaultsOnly, Category="GraphGenerator")
	TSubclassOf<UEnvQueryContext> GenerateAround;

};

