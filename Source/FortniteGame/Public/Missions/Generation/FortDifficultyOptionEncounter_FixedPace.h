// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Missions/FortDifficultyOptionEncounter.h"
#include "FortDifficultyOptionEncounter_FixedPace.generated.h"

UCLASS(EditInlineNew, BlueprintType, Blueprintable)
class UFortDifficultyOptionEncounter_FixedPace : public UFortDifficultyOptionEncounter
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Rift Spawn Settings")
	FScalableFloat RiftSpawnInterval;

	UPROPERTY(EditDefaultsOnly, Category="Rift Spawn Settings")
	FScalableFloat RiftSpawnCount;

	UPROPERTY(EditDefaultsOnly, Category="AI Max Count")
	FScalableFloat AIMaxCount;

	UPROPERTY(EditDefaultsOnly, Category="AI Max Count")
	FScalableFloat SpawnAIMaxCountPlayerMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="AI Max Count")
	FScalableFloat SpawnAIMaxCountDifficultyMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="Spawn Interval Time")
	FScalableFloat SpawnAIIntervalTime;

	UPROPERTY(EditDefaultsOnly, Category="Spawn Interval Time")
	FScalableFloat SpawnAIIntervalTimePlayerMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="Spawn Interval Time")
	FScalableFloat SpawnAIIntervalTimeDifficultyMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="Spawn Interval Count")
	FScalableFloat SpawnAIIntervalCount;

	UPROPERTY(EditDefaultsOnly, Category="Spawn Interval Count")
	FScalableFloat SpawnAIIntervalCountPlayerMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="Spawn Interval Count")
	FScalableFloat SpawnAIIntervalCountDifficultyMultiplier;

};

