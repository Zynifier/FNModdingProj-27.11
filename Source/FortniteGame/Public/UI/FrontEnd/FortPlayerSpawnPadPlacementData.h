// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "FortPlayerSpawnPadPlacementData.generated.h"

class ABuildingSMActor;
class UEnvQuery;

USTRUCT()
struct FFortPlayerSpawnPadPlacementData
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortPlayerSpawnPadPlacementData", meta=(ShowOnlyInnerProperties))
	TObjectPtr<UEnvQuery> PlacementQuery;

	UPROPERTY(EditDefaultsOnly, Category="FortPlayerSpawnPadPlacementData", meta=(ShowOnlyInnerProperties))
	TSoftClassPtr<ABuildingSMActor> ActorToPlace;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="FortPlayerSpawnPadPlacementData", meta=(ShowOnlyInnerProperties))
	bool bSnapToGrid;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="FortPlayerSpawnPadPlacementData", meta=(ShowOnlyInnerProperties))
	bool bAdjustPlacementForFloors;

	UPROPERTY(EditDefaultsOnly, Category="FortPlayerSpawnPadPlacementData", meta=(ShowOnlyInnerProperties))
	FGameplayTagContainer TagsToAddToChosenPlacementActor;

};

