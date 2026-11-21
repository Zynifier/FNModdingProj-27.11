// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataProviders/AIDataProvider.h"
#include "EnvironmentQuery/Generators/EnvQueryGenerator_ProjectedPoints.h"
#include "Missions/FortTaggedActorsManager.h"
#include "FortQueryGenerator_PointsOnBuildingActors.generated.h"

class UEnvQueryContext;

UCLASS(meta=(DisplayName="Points: On Building Actors"))
class UFortQueryGenerator_PointsOnBuildingActors : public UEnvQueryGenerator_ProjectedPoints
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Generator")
	FAIDataProviderFloatValue BoundingBoxExtentXY;

	UPROPERTY(EditDefaultsOnly, Category="Generator")
	FAIDataProviderFloatValue BoundingBoxExtentZ;

	UPROPERTY(EditDefaultsOnly, Category="Generator")
	FAIDataProviderFloatValue PointDensity;

	UPROPERTY(EditDefaultsOnly, Category="Generator")
	FAIDataProviderIntValue MaxGeneratedPoints;

	UPROPERTY(EditDefaultsOnly, Category="Generator")
	FFortTaggedActorOctreeFilter ActorLookupFilter;

	UPROPERTY(EditAnywhere, Category="Generator")
	FAIDataProviderFloatValue RandomChanceToSkip;

protected:
	UPROPERTY(EditDefaultsOnly, Category="Generator")
	TSubclassOf<UEnvQueryContext> GenerateAround;

};

