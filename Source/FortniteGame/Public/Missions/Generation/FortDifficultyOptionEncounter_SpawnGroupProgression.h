// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Missions/FortDifficultyOptionEncounter.h"
#include "FortDifficultyOptionEncounter_SpawnGroupProgression.generated.h"

class UFortAISpawnGroupProgressionInfo;

UCLASS(BlueprintType, Blueprintable)
class UFortDifficultyOptionEncounter_SpawnGroupProgression : public UFortDifficultyOptionEncounter
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortDifficultyOptionEncounter_SpawnGroupProgression")
	TObjectPtr<UFortAISpawnGroupProgressionInfo> SpawnGroupProgression;

};

