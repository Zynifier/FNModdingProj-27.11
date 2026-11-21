// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "GameplayTagContainer.h"
#include "FortAthenaBTService_AIEvaluator.generated.h"

class UFortAthenaAIEvaluator;

UCLASS()
class UFortAthenaBTService_AIEvaluator : public UBTService
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortAthenaBTService_AIEvaluator", meta=(AllowPrivateAccess="true"))
	FGameplayTag InjectionTag;

	UPROPERTY(EditAnywhere, Category="FortAthenaBTService_AIEvaluator", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UFortAthenaAIEvaluator> AIEvaluatorClass;

};

