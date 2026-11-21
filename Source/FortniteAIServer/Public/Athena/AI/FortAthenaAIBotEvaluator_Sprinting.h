// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AI/FortAthenaAIBotEvaluator.h"
#include "FortAthenaAIBotEvaluator_Sprinting.generated.h"

class UFortAthenaAIBotAimingDigestedSkillSet;
class UFortAthenaAIBotMovementDigestedSkillSet;

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAIBotEvaluator_Sprinting : public UFortAthenaAIBotEvaluator
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName AllowSprintKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName AllowSlideKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName JumpExecutionStatusName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName TacticalSprintExecutionStatusName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName SlideExecutionStatusName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName UrgentMovementKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName RangeAttackExecutionStatusName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName MeleeAttackExecutionStatusName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName ThrowableAttackExecutionStatusName;

	UPROPERTY(EditDefaultsOnly, Category="Params")
	bool bSprintOnlyInWater;

	UPROPERTY(EditDefaultsOnly, Category="Params")
	bool bSprintOnlyInUrgentMode;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIBotMovementDigestedSkillSet> MovementSkillSet;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIBotAimingDigestedSkillSet> AimingSkillSet;

	UPROPERTY(Transient)
	float TacticalSprintTriggerChance;

	UPROPERTY(Transient)
	float TacticalSprintTriggerChanceInUrgentMovement;

	UPROPERTY(Transient)
	float TacticalSprintJumpTriggerChance;

};

