// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryGenerator.h"
#include "AI/FortAITypes.h"
#include "FortQueryGenerator_SpecificAssignmentGoals.generated.h"

class UFortAIAssignmentSettings;
class UFortAIGoalProvider;

UCLASS(meta=(DisplayName="Goals: Specific Assignment"))
class UFortQueryGenerator_SpecificAssignmentGoals : public UEnvQueryGenerator
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Assignment")
	FFortAIAssignmentIdentifier AssignmentIdentifier;

	UPROPERTY(EditAnywhere, Category="Assignment")
	TObjectPtr<UFortAIAssignmentSettings> AssignmentSettings;

	UPROPERTY(EditAnywhere, Category="Assignment")
	TSubclassOf<UFortAIGoalProvider> GoalProvider;

};

