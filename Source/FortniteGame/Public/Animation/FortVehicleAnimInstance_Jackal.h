// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/FortAnimTypes.h"
#include "Animation/FortVehicleAnimInstance.h"
#include "FortVehicleAnimInstance_Jackal.generated.h"

class AFortAthenaJackalVehicle;

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortVehicleAnimInstance_Jackal : public UFortVehicleAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="Jackal")
	TObjectPtr<AFortAthenaJackalVehicle> JackalVehicle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Jackal")
	bool bIsSprinting;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Jackal")
	EFortCardinalDirection LocomotionCardinalDirection;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Jackal")
	float RunForwardAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Jackal")
	float LeanYaw;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Jackal")
	float CombatLeanYaw;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Jackal")
	bool bPlayJumpTrickVertical;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Jackal")
	bool bPlayJumpTrick;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Jackal")
	bool bIsMoving;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Jackal")
	bool bInAir;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Jackal")
	bool bIsVehicleJumping;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Jackal")
	bool bIsBoosting;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Jackal")
	bool bIsOnSlope;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Jackal")
	bool bPlayMovingFast;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Jackal")
	bool bPlayDriveSouth;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Jackal")
	bool bPlayAdditiveLeans;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Jackal")
	bool bIdleToMovementStartTransition;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Jackal")
	bool bMovementLoopToMovementStopTransition;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Jackal")
	bool bLocomotionPoseToJumpTransition;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Jackal")
	bool bJumpToLocomotionPoseTransition;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Jackal")
	bool bIdleToMovementLoopTransition;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Jackal")
	bool bMovementLoopToPivotTransition;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Jackal")
	bool bMovementLoopToIdleTransition;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Jackal")
	bool bDefaultToJumpCombatStartTransition;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Jackal")
	bool bJumpApexToJumpFallTransition;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Jackal")
	bool bDefaultToJumpStartTransition;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Jackal")
	bool bCombatModeToSprintModeTransition;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Jackal")
	bool bSprintModeToCombatModeTransition;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Jackal")
	bool bIsPlayingEmoteOnHoverboard;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Jackal")
	bool bShouldApplyAdditive;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Jackal")
	bool bIsBothLegFK;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JackalTunables")
	float InPlaceLeansBlendSpaceAlpha;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JackalTunables")
	float CombatLeanYawMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JackalTunables")
	float SlopeCheckPitchThresholdDegrees;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JackalTunables")
	float SlopeCheckYawThresholdDegrees;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JackalTunables")
	float AdditiveLeansSpeedThreshold;

};

