// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AI/FortAthenaAIBotEvaluator.h"
#include "FortAthenaAIBotEvaluator_CanMove.generated.h"

UENUM()
enum class EFortAthenaAICanMoveState : uint8
{
	None = 0,
	Failed_AgentOffNavmesh = 1,
	Failed_GoalOffNavmesh = 2,
	Failed_Falling = 3,
	Success = 4,
	Success_Partial = 5,
};

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAIBotEvaluator_CanMove : public UFortAthenaAIBotEvaluator
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName CanMoveKeyName;

};

