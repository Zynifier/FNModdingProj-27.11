// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FortAthenaAIEvaluatorComponent.generated.h"

class UFortAthenaAIBotEvaluator_Movement;
class UFortAthenaAIEvaluator;

USTRUCT()
struct FMovementEvaluatorInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIBotEvaluator_Movement> MovementEval;

};

UCLASS(MinimalAPI, ClassGroup=("AI"), meta=(BlueprintSpawnableComponent))
class UFortAthenaAIEvaluatorComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TArray<FMovementEvaluatorInfo> MovementEvaluatorInfo;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortAthenaAIEvaluator>> AIEvaluators;

};

