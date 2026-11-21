// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataProviders/AIDataProvider.h"
#include "EnvironmentQuery/EnvQueryGenerator.h"
#include "FortQueryGenerator_ValidSpawnRiftActors.generated.h"

UCLASS(meta=(DisplayName="Actors: Valid Spawn Rifts"))
class UFortQueryGenerator_ValidSpawnRiftActors : public UEnvQueryGenerator
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Generator")
	FAIDataProviderIntValue NumAIForGroup;

};

