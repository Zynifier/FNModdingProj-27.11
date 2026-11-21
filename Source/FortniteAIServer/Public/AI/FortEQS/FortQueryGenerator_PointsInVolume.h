// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataProviders/AIDataProvider.h"
#include "EnvironmentQuery/EnvQueryGenerator.h"
#include "AI/FortNavSystem.h"
#include "FortQueryGenerator_PointsInVolume.generated.h"

class UEnvQueryContext;

UCLASS(meta=(DisplayName="Points: In Volume"))
class UFortQueryGenerator_PointsInVolume : public UEnvQueryGenerator
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Generator")
	FAIDataProviderIntValue NumberOfPoints;

	UPROPERTY(EditDefaultsOnly, Category="Generator")
	TEnumAsByte<EFortNamedNavmesh::Type> NavMeshToUse;

	UPROPERTY(EditAnywhere, Category="Generator")
	TSubclassOf<UEnvQueryContext> GenerateIn;

};

