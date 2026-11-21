// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/AI/FortAthenaAIBotEvaluator_Movement.h"
#include "FortAthenaAIBotEvaluator_HitAndRun.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAIBotEvaluator_HitAndRun : public UFortAthenaAIBotEvaluator_Movement
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Parameters", meta=(AllowPrivateAccess="true"))
	FScalableFloat AttackDurationBeforeEvade;

	UPROPERTY(EditAnywhere, Category="Parameters", meta=(AllowPrivateAccess="true"))
	FScalableFloat MeleeAttackMaxDistToEvade;

	UPROPERTY(EditAnywhere, Category="Parameters", meta=(AllowPrivateAccess="true"))
	FScalableFloat ClampEvadeDistanceEnable;

	UPROPERTY(EditAnywhere, Category="Parameters", meta=(AllowPrivateAccess="true"))
	FScalableFloat MinDistanceToEvade;

	UPROPERTY(EditAnywhere, Category="Parameters", meta=(AllowPrivateAccess="true"))
	FScalableFloat MaxDistanceToEvade;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName EvadeKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName EvadeMovementStateKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName EvadeDestinationKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName WeaponTriggerMeleeName;

	UPROPERTY(Transient)
	float MeleeAttackMaxDistToEvadeSqr;

	UPROPERTY(Transient)
	float MaxDistanceToEvadeSqr;

};

