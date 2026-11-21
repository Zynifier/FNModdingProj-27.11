// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Missions/FortDifficultyOptionEncounter.h"
#include "FortDifficultyOptionEncounter_SpawnLimitPoints.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UFortDifficultyOptionEncounter_SpawnLimitPoints : public UFortDifficultyOptionEncounter
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortDifficultyOptionEncounter_SpawnLimitPoints", meta=(ClampMin="0.000000", UIMin="0.000000"))
	float SpawnPointsPercentageLimit;

};

