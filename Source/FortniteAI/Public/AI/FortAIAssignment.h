// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AI/FortAITypes.h"
#include "AI/Goals/FortAIGoal.h"
#include "FortAIAssignment.generated.h"

class UAIGoalComponent;
class UFortAIAssignmentSettings;
class UFortAIGoalProvider;

UCLASS(BlueprintType)
class UFortAIAssignment : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	FFortAIAssignmentIdentifier AssignmentIdentifier;

	UPROPERTY()
	TObjectPtr<UFortAIAssignmentSettings> AssignmentSettings;

	UPROPERTY()
	TObjectPtr<UFortAIGoalProvider> GoalProvider;

	UPROPERTY(Transient, Export)
	TArray<TWeakObjectPtr<UAIGoalComponent>> GoalComponentsOnAssignment;

private:
	UPROPERTY()
	TArray<FFortAIGoal> Goals;

};

