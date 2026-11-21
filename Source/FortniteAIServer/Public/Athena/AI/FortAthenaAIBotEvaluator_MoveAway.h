// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTypes.h"
#include "ScalableFloat.h"
#include "Athena/AI/FortAthenaAIBotEvaluator_Movement.h"
#include "FortAthenaAIBotEvaluator_MoveAway.generated.h"

class UEnvQuery;

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAIBotEvaluator_MoveAway : public UFortAthenaAIBotEvaluator_Movement
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortAthenaAIBotEvaluator_MoveAway", meta=(AllowPrivateAccess="true"))
	FScalableFloat MaxSecondsToReactToBump;

	UPROPERTY(EditAnywhere, Category="FortAthenaAIBotEvaluator_MoveAway", meta=(AllowPrivateAccess="true"))
	FScalableFloat MaxSecondsToReactToBox;

	UPROPERTY(EditAnywhere, Category="FortAthenaAIBotEvaluator_MoveAway", meta=(AllowPrivateAccess="true"))
	FScalableFloat MinSecondsBetweenInstantReactions;

	UPROPERTY(EditAnywhere, Category="Convert", meta=(AllowPrivateAccess="true"))
	TObjectPtr<UEnvQuery> FindAwayLocationFromPawnQueryTemplate;

	UPROPERTY(EditAnywhere, Category="Convert", meta=(AllowPrivateAccess="true"))
	TEnumAsByte<EEnvQueryRunMode::Type> FindAwayLocationFromPawnRunMode;

	UPROPERTY(EditAnywhere, Category="Convert", meta=(AllowPrivateAccess="true"))
	TObjectPtr<UEnvQuery> FindAwayLocationFromBoxQueryTemplate;

	UPROPERTY(EditAnywhere, Category="Convert", meta=(AllowPrivateAccess="true"))
	TEnumAsByte<EEnvQueryRunMode::Type> FindAwayLocationFromBoxRunMode;

};

