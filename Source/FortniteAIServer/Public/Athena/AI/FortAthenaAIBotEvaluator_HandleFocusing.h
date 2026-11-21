// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AI/FortAthenaAIBotEvaluator.h"
#include "FortAthenaAIBotEvaluator_HandleFocusing.generated.h"

class AActor;
class UFortAthenaAIBotAimingDigestedSkillSet;
class UFortAthenaAIBotMovementDigestedSkillSet;

UENUM()
enum class EFocusingBehavior : uint8
{
	FocusCurrentTarget = 0,
	IgnoreThreatAfterTimer = 1,
	IgnoreThreatAlways = 2,
	IgnoreThreatToFlee = 3,
	LookAtInvestigate = 4,
	LookAtAmbush = 5,
	LookAtHeardSound = 6,
	LookAtScanAround = 7,
	LookAtScanAroundOnly = 8,
	Invalid = 9,
};

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAIBotEvaluator_HandleFocusing : public UFortAthenaAIBotEvaluator
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName TargetActorName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName InteractActorName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true", EditCondition="bFocusOnTargetLocation"))
	FName TargetLocationName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName FocusActorName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName FocalPointName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName WeaponFireName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName RangeAttackIsReadyToFireName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName WeaponTriggerMeleeName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName LastKnownPositionName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName TacticalSprintExecutionStatusName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Behavior", meta=(AllowPrivateAccess="true"))
	EFocusingBehavior FocusingBehavior;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Behavior", meta=(AllowPrivateAccess="true"))
	EFocusingBehavior NoRangedWeaponFocusBehavior;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Behavior", meta=(AllowPrivateAccess="true"))
	bool bPrioritizeThreatOverCurrentTarget;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Behavior", meta=(AllowPrivateAccess="true"))
	bool bUseTargetActorKeyAsFocusTarget;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Behavior", meta=(AllowPrivateAccess="true"))
	bool bFocusOnTargetLocation;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Behavior", meta=(AllowPrivateAccess="true", ClampMax="180", ClampMin="0"))
	float AmbushMaxLKPLookAtAngleDegree;

	UPROPERTY(EditAnywhere, Category="Movement", meta=(AllowPrivateAccess="true"))
	bool bStopFocusingWhenMoving;

	UPROPERTY(EditAnywhere, Category="Movement", meta=(AllowPrivateAccess="true", EditCondition="bStopFocusingWhenMoving"))
	float ResumeFocusingWhenMovingDist;

	UPROPERTY(EditAnywhere, Category="Movement", meta=(AllowPrivateAccess="true", EditCondition="bStopFocusingWhenMoving"))
	float StopFocusingWhenMovingDist;

	UPROPERTY(EditAnywhere, Category="Movement", meta=(AllowPrivateAccess="true", EditCondition="bStopFocusingWhenMoving"))
	bool bResumeFocusWhileSliding;

	UPROPERTY(Transient)
	UFortAthenaAIBotAimingDigestedSkillSet* CacheAimingDigestedSkillSet;

	UPROPERTY(Transient)
	UFortAthenaAIBotMovementDigestedSkillSet* CacheMovementDigestedSkillSet;

	UPROPERTY(Transient)
	TObjectPtr<AActor> LastTargetedThreat;

	UPROPERTY(Transient)
	TObjectPtr<AActor> FocusActor;

};

