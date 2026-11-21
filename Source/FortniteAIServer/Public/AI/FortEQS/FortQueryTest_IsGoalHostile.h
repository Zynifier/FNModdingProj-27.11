// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "AI/FortEQS/FortQueryTest_GoalBase.h"
#include "FortQueryTest_IsGoalHostile.generated.h"

UCLASS(meta=(DisplayName="Goal is Hostile"))
class UFortQueryTest_IsGoalHostile : public UFortQueryTest_GoalBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortQueryTest_IsGoalHostile")
	FGameplayTagQuery OwnerTagQuery;

	UPROPERTY(EditDefaultsOnly, Category="FortQueryTest_IsGoalHostile")
	FGameplayTagQuery EnemyPawnTagsToConsider;

	UPROPERTY(EditDefaultsOnly, Category="FortQueryTest_IsGoalHostile", meta=(Categories="Building.Resource, Building.Player"))
	FGameplayTagContainer BuildingTagsToConsider;

	UPROPERTY(EditDefaultsOnly, Category="FortQueryTest_IsGoalHostile")
	bool bConsiderDefenders;

};

