// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Missions/FortDifficultyOptionEncounter.h"
#include "FortDifficultyOptionEncounter_SpawnGroups.generated.h"

class UFortAISpawnGroupProgressionInfo;

UCLASS(EditInlineNew, BlueprintType, Blueprintable)
class UFortDifficultyOptionEncounter_SpawnGroups : public UFortDifficultyOptionEncounter
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortDifficultyOptionEncounter_SpawnGroups")
	TObjectPtr<UFortAISpawnGroupProgressionInfo> SpawnGroupProgression;

};

