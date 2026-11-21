// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AI/FortAthenaAIBotEvaluator_Attack.h"
#include "FortAthenaAIBotEvaluator_ThrowableAttack.generated.h"

class AFortPawn;
class UFortAthenaAIBotAimingDigestedSkillSet;
class UFortAthenaAIBotAttackingDigestedSkillSet;
class UFortAthenaAIBotRangeAttackDigestedSkillSet;
class UFortWorldItem;

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAIBotEvaluator_ThrowableAttack : public UFortAthenaAIBotEvaluator_Attack
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName WeaponTriggerThrowableName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName ThrowableAttackIsReadyToThrowName;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIBotAttackingDigestedSkillSet> AttackingSkillSet;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIBotRangeAttackDigestedSkillSet> RangeAttackSkillSet;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIBotAimingDigestedSkillSet> AimingSkillSet;

	UPROPERTY(Transient)
	TObjectPtr<UFortWorldItem> ChosenWeapon;

	UPROPERTY(Transient)
	TObjectPtr<AFortPawn> CachedFortPawn;

};

