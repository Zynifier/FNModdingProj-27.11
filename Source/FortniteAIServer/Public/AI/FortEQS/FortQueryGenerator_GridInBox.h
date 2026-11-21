// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataProviders/AIDataProvider.h"
#include "EnvironmentQuery/Generators/EnvQueryGenerator_ProjectedPoints.h"
#include "FortQueryGenerator_GridInBox.generated.h"

class UEnvQueryContext;

UCLASS(meta=(DisplayName="Points: Grid In Box"))
class UFortQueryGenerator_GridInBox : public UEnvQueryGenerator_ProjectedPoints
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Generator")
	FAIDataProviderFloatValue BoxWidth;

	UPROPERTY(EditDefaultsOnly, Category="Generator")
	FAIDataProviderFloatValue BoxLength;

	UPROPERTY(EditDefaultsOnly, Category="Generator")
	FAIDataProviderFloatValue SpaceBetween;

	UPROPERTY(EditDefaultsOnly, Category="Generator")
	TSubclassOf<UEnvQueryContext> GenerateAround;

	UPROPERTY(EditDefaultsOnly, Category="Generator")
	TSubclassOf<UEnvQueryContext> BoxExtentsContext;

};

