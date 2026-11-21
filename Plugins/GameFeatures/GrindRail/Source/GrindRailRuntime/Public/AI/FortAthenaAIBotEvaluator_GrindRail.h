// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "Athena/AI/FortAthenaAIBotEvaluator.h"
#include "FortAthenaAIBotEvaluator_GrindRail.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAIBotEvaluator_GrindRail : public UFortAthenaAIBotEvaluator
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortAthenaAIBotEvaluator_GrindRail")
	FGameplayTag GrindRailTag;

	UPROPERTY(EditAnywhere, Category="FortAthenaAIBotEvaluator_GrindRail")
	FScalableFloat GrindDuration;

	UPROPERTY(EditAnywhere, Category="FortAthenaAIBotEvaluator_GrindRail")
	FScalableFloat GrindDurationRandomDeviation;

};

