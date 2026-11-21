// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AI/FortAthenaAIBotEvaluator.h"
#include "FortAthenaAIBotEvaluator_AimDownSight.generated.h"

class UFortAthenaAIBotAimingDigestedSkillSet;

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAIBotEvaluator_AimDownSight : public UFortAthenaAIBotEvaluator
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName WeaponKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName ThrowableAttacksName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName TargetActorName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName UrgentMovementName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="RangeAttack", meta=(AllowPrivateAccess="true"))
	bool bSkipTargetChecks;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIBotAimingDigestedSkillSet> CacheAimingDigestedSkillSet;

};

