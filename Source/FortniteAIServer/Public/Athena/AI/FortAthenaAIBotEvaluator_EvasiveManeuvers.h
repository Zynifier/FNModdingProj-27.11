// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AITypes.h"
#include "GameplayTagContainer.h"
#include "Navigation/PathFollowingComponent.h"
#include "Athena/AI/FortAthenaAIBotEvaluator.h"
#include "FortAthenaAIBotEvaluator_EvasiveManeuvers.generated.h"

class UFortAthenaAIBotEvasiveManeuversDigestedSkillSet;
class UFortAthenaAIPerk_EvasiveManeuvers;

UENUM()
enum class EEvasiveManeuverType : uint8
{
	Crouch = 0,
	Dodge = 1,
	Jump = 2,
	JetpackStrafe = 3,
	None = 4,
};

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UFortAthenaAIBotEvaluator_EvasiveManeuvers : public UFortAthenaAIBotEvaluator
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type MovementResult);

private:
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName CrouchExecutionStatusName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName JumpExecutionStatusName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName JetpackStrafeExecutionStatusName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName DodgeName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName DestinationKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName UrgentMoveKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="EvasiveGameplay", meta=(AllowPrivateAccess="true"))
	bool bDoCrouching;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="EvasiveGameplay", meta=(AllowPrivateAccess="true"))
	bool bDoDodging;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="EvasiveGameplay", meta=(AllowPrivateAccess="true"))
	bool bDoJumping;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="EvasiveGameplay", meta=(AllowPrivateAccess="true"))
	bool bDoJumpingDistanceCheck;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="EvasiveGameplay", meta=(AllowPrivateAccess="true"))
	bool bDoJetpackStrafing;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="EvasiveGameplay", meta=(AllowPrivateAccess="true"))
	bool bDoJetpackStrafingDistanceCheck;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="EvasiveGameplay", meta=(AllowPrivateAccess="true"))
	float JetpackStrafingRequiredFuelPercent;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="EvasiveGameplay", meta=(AllowPrivateAccess="true"))
	float JetpackStrafeNavPadding;

	UPROPERTY(EditAnywhere, Category="Tag Query", meta=(AllowPrivateAccess="true"))
	FGameplayTagQuery RequiredTagQuery;

	UPROPERTY(EditAnywhere, Category="Tag Query", meta=(AllowPrivateAccess="true"))
	FGameplayTagQuery JetpackRequiredTagQuery;

	UPROPERTY(EditAnywhere, Category="Tag Query", meta=(AllowPrivateAccess="true"))
	FGameplayTagQuery JumpRequiredTagQuery;

	UPROPERTY(EditAnywhere, Category="FortAthenaAIBotEvaluator_EvasiveManeuvers", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UFortAthenaAIPerk_EvasiveManeuvers> ForcedPerkClass;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIBotEvasiveManeuversDigestedSkillSet> CacheEMDigestedSkillSet;

};

