// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataProviders/AIDataProvider.h"
#include "EnvironmentQuery/EnvQueryGenerator.h"
#include "FortQueryGenerator_BuildingsOnCachedPath.generated.h"

class UEnvQueryContext;

UCLASS(meta=(DisplayName="Goals: Structural Buildings"))
class UFortQueryGenerator_BuildingsOnCachedPath : public UEnvQueryGenerator
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Generator")
	TSubclassOf<UEnvQueryContext> CachedPathSource;

	UPROPERTY(EditDefaultsOnly, Category="Generator")
	FAIDataProviderBoolValue bIncludeWalls;

	UPROPERTY(EditDefaultsOnly, Category="Generator")
	FAIDataProviderBoolValue bIncludeFloors;

	UPROPERTY(EditDefaultsOnly, Category="Generator")
	FAIDataProviderBoolValue bIncludeCenterCell;

};

