// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/Generators/EnvQueryGenerator_ProjectedPoints.h"
#include "FortEnvQueryGenerator_ProjectedPoints.generated.h"

UCLASS(Abstract)
class UFortEnvQueryGenerator_ProjectedPoints : public UEnvQueryGenerator_ProjectedPoints
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Vehicle")
	FName OverridenAgentNameForNavmesh;

};

