// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/Generators/EnvQueryGenerator_OnCircle.h"
#include "AI/FortAITypes.h"
#include "FortQueryGenerator_GoalOnCircle.generated.h"

class UFortAIAssignmentSettings;

UCLASS(meta=(DisplayName="Goal: Points On Circle"))
class UFortQueryGenerator_GoalOnCircle : public UEnvQueryGenerator_OnCircle
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Generator")
	bool bIncludeCenterActorInGeneratedGoals;

	UPROPERTY(EditAnywhere, Category="Assignment")
	TObjectPtr<UFortAIAssignmentSettings> OptionalAssignmentSettings;

	UPROPERTY(EditAnywhere, Category="Assignment")
	FFortAIAssignmentIdentifier OptionalAssignmentIdentifier;

};

