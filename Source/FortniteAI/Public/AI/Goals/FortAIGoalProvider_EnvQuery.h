// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AI/FortAIRootAssignmentProviderInterface.h"
#include "AI/FortAITypes.h"
#include "AI/Goals/FortAIGoalProvider.h"
#include "FortAIGoalProvider_EnvQuery.generated.h"

class AFortAIPawn;
class UEnvQuery;

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UFortAIGoalProvider_EnvQuery : public UFortAIGoalProvider, public IFortAIRootAssignmentProviderInterface
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="AIGoalProvider")
	TObjectPtr<UEnvQuery> GoalQuery;

	UPROPERTY(EditAnywhere, Category="AIGoalProvider")
	float AutomaticUpdatePeriodInSeconds;

	UPROPERTY(EditAnywhere, Category="Assignment")
	FFortAIAssignmentIdentifier SpecificAssignmentContext;

	UPROPERTY(EditAnywhere, Category="Assignment")
	TSoftClassPtr<AFortAIPawn> AIPawnContext;

};

