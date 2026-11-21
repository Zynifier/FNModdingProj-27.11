// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataProviders/AIDataProvider.h"
#include "EnvironmentQuery/Generators/EnvQueryGenerator_ProjectedPoints.h"
#include "FortQueryGenerator_GridInVolume.generated.h"

class UEnvQueryContext;

UCLASS(meta=(DisplayName="Points: Grid In Volume"))
class UFortQueryGenerator_GridInVolume : public UEnvQueryGenerator_ProjectedPoints
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Generator")
	FAIDataProviderFloatValue SpaceBetween;

	UPROPERTY(EditDefaultsOnly, Category="Generator")
	TSubclassOf<UEnvQueryContext> GenerateInVolume;

};

