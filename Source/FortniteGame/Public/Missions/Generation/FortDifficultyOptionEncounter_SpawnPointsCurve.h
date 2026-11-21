// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Missions/FortDifficultyOptionEncounter.h"
#include "FortDifficultyOptionEncounter_SpawnPointsCurve.generated.h"

class UFortSpawnPointsPercentageCurveSequence;

UCLASS(BlueprintType, Blueprintable)
class UFortDifficultyOptionEncounter_SpawnPointsCurve : public UFortDifficultyOptionEncounter
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortDifficultyOptionEncounter_SpawnPointsCurve")
	TObjectPtr<UFortSpawnPointsPercentageCurveSequence> CurveSequence;

};

