// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryManager.h"
#include "FortEnvQueryManager.generated.h"

UCLASS(MinimalAPI)
class UFortEnvQueryManager : public UEnvQueryManager
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, GlobalConfig, Category="AIProfiling")
	TArray<FEnvQueryManagerConfig> EnvManagerConfigPerGamePhase;

	UPROPERTY(EditAnywhere, GlobalConfig, Category="AIProfiling")
	FEnvQueryManagerConfig EnvManagerConfigSTW;

};

