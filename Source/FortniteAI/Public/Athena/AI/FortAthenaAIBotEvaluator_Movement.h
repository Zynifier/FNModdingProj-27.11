// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AI/FortAthenaAIBotEvaluator.h"
#include "FortAthenaAIBotEvaluator_Movement.generated.h"

class UAthenaAIServicePlayerBots;
class UFortAthenaAIBotMovementDigestedSkillSet;
class UFortAthenaAIBotUnstuckDigestedSkillSet;
enum class EBotUnstuckSteeringReason : uint8;

UENUM()
enum class EBotMovementState : uint8
{
	None = 0,
	InProgress = 1,
	Failed_NoPathFound = 2,
	Failed_Aborted = 3,
	Failed_AgentOffNavmesh = 4,
	Failed_GoalOffNavmesh = 5,
	Failed_Blocked = 6,
	Failed_OffPath = 7,
	Failed_Falling = 8,
	Success = 9,
	Success_Partial = 10,
	Success_AlreadyAtGoal = 11,
};

UENUM()
enum class EBotUnstuckSteeringReason : uint8
{
	Unknown = 0,
	OffNavMesh = 1,
	IsolatedIsland = 2,
};

UCLASS(Abstract)
class FORTNITEAI_API UFortAthenaAIBotEvaluator_Movement : public UFortAthenaAIBotEvaluator
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName MovementStateKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName MovementDestinationKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName LastPartialPathTimeKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName LastPartialPathCountKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName LastBlockedPathCountKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName UnstuckInWaterExecutionStatusName;

	UPROPERTY(EditAnywhere, Category="Unstuck", meta=(AllowPrivateAccess="true"))
	FName UnstuckLastBlockedByActorKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Teleport", meta=(AllowPrivateAccess="true"))
	FName UnstuckExecutionStatusKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Teleport", meta=(AllowPrivateAccess="true"))
	FName TeleportExecutionStatusKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Undermine", meta=(AllowPrivateAccess="true"))
	FName UndermineExecutionStatusKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Undermine", meta=(AllowPrivateAccess="true"))
	FName UndermineTargetKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Undermine", meta=(AllowPrivateAccess="true"))
	FName UndermineLocationImpactName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Steer", meta=(AllowPrivateAccess="true"))
	FName UnstuckSteerExecutionStatusKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Steer", meta=(AllowPrivateAccess="true"))
	FName UnstuckSteerDirectionKeyName;

	UPROPERTY(Transient)
	TObjectPtr<UAthenaAIServicePlayerBots> CachedAIServicePlayerBots;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIBotMovementDigestedSkillSet> CachedMovementDigestedSkillSet;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIBotUnstuckDigestedSkillSet> UnstuckSkillSet;

private:
	UFUNCTION()
	void EvaluateIsolatedIslandSteering();

	UFUNCTION()
	void OnCurrentUnstuckSteeringAttemptFinished(const EBotUnstuckSteeringReason UnstuckSteeringReason);

};

