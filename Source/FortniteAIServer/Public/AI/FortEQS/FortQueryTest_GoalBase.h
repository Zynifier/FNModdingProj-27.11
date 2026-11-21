// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "GameplayTagContainer.h"
#include "AI/FortAITypes.h"
#include "FortQueryTest_GoalBase.generated.h"

UCLASS(Abstract, MinimalAPI)
class UFortQueryTest_GoalBase : public UEnvQueryTest
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Condition")
	uint8 bScoreEnemies : 1;

	UPROPERTY(EditDefaultsOnly, Category="Condition")
	uint8 bScoreEncounterGoals : 1;

	UPROPERTY(EditDefaultsOnly, Category="Condition")
	uint8 bScoreWorldGoals : 1;

	UPROPERTY(EditDefaultsOnly, Category="Condition")
	uint8 bScoreSpecificAssignments : 1;

	UPROPERTY(EditDefaultsOnly, Category="Condition")
	TArray<FFortAIAssignmentIdentifier> AssignmentIDs;

	UPROPERTY(EditDefaultsOnly, Category="Condition")
	TArray<FFortAIAssignmentIdentifier> ProhibitedAssignmentIDs;

	UPROPERTY(EditDefaultsOnly, Category="Condition")
	FGameplayTagQuery GoalActorTagQuery;

};

