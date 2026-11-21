// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AI/FortAthenaAIBotEvaluator_Movement.h"
#include "FortAthenaAIBotEvaluator_ChoosePosition.generated.h"

class UAthenaAIServiceZoneManager;
class UFortAthenaAIBotAimingDigestedSkillSet;
class UFortAthenaAIBotAttackingDigestedSkillSet;

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAIBotEvaluator_ChoosePosition : public UFortAthenaAIBotEvaluator_Movement
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName TargetActorName;

	UPROPERTY(Transient)
	UAthenaAIServiceZoneManager* CachedZoneManager;

	UPROPERTY(Transient)
	UFortAthenaAIBotAttackingDigestedSkillSet* AttackingSkillSet;

	UPROPERTY(Transient)
	UFortAthenaAIBotAimingDigestedSkillSet* AimingSkillSet;

};

