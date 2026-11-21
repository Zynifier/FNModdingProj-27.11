// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Missions/FortDifficultyOptionEncounter.h"
#include "FortDifficultyOptionEncounter_Distance.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UFortDifficultyOptionEncounter_Distance : public UFortDifficultyOptionEncounter
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortDifficultyOptionEncounter_Distance")
	float MinSpawnDistance;

	UPROPERTY(EditDefaultsOnly, Category="FortDifficultyOptionEncounter_Distance", meta=(DisplayName="Max Navigation Distance"))
	float MaxSpawnDistance;

};

