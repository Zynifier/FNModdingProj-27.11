// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Missions/FortDifficultyOptionEncounter.h"
#include "FortDifficultyOptionEncounter_SpawnTiming.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UFortDifficultyOptionEncounter_SpawnTiming : public UFortDifficultyOptionEncounter
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortDifficultyOptionEncounter_SpawnTiming")
	FScalableFloat SpawnIntervalSeconds;

};

