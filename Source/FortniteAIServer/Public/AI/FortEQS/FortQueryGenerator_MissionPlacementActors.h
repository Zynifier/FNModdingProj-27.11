// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryGenerator.h"
#include "GameplayTagContainer.h"
#include "FortQueryGenerator_MissionPlacementActors.generated.h"

UCLASS(meta=(DisplayName="Actors: Mission Placement Actors"))
class UFortQueryGenerator_MissionPlacementActors : public UEnvQueryGenerator
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="FortQueryGenerator_MissionPlacementActors")
	FGameplayTagQuery MissionPlacementActorTagQuery;

};

