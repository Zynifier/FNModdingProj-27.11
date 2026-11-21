// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Missions/FortDifficultyOptionEncounter.h"
#include "FortDifficultyOptionEncounter_SpawnPointsMultiplier.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UFortDifficultyOptionEncounter_SpawnPointsMultiplier : public UFortDifficultyOptionEncounter
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortDifficultyOptionEncounter_SpawnPointsMultiplier")
	FScalableFloat Multiplier;

};

