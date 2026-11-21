// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AI/FortAthenaAIBotEvaluator_Attack.h"
#include "FortAthenaAIBotEvaluator_MeleeAttack.generated.h"

class UFortAthenaAIBotAttackingDigestedSkillSet;

UENUM(BlueprintType)
enum class ECannotMeleeAttackReason : uint8
{
	None = 0,
	CooldownActive = 1,
	Other = 2,
	AttackDestinationNotValid = 3,
	TargetOutsideLeash = 4,
};

UCLASS(BlueprintType, Blueprintable)
class FORTNITEAISERVER_API UFortAthenaAIBotEvaluator_MeleeAttack : public UFortAthenaAIBotEvaluator_Attack
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName WeaponTriggerMeleeName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName ThrowableAttacksAllowedName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName TraversalBlockMeleeAttackName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName CannotMeleeAttackReasonName;

	UPROPERTY(Transient)
	UFortAthenaAIBotAttackingDigestedSkillSet* AttackingSkillSet;

};

