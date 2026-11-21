// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/CachedAnimData.h"
#include "Math/MathFwd.h"
#include "Animation/AnimInputs/FortAnimInput_AdjustedAim.h"
#include "Animation/AnimSets/FortLocomotionAnimSet.h"
#include "Animation/FortAnimInputs.h"
#include "Animation/FortAnimTypes.h"
#include "Animation/PlayerAnimInstances/FortLocomotionAnimInstance.h"
#include "FortWalkAnimInstance.generated.h"

UCLASS(MinimalAPI, HideCategories=("AnimInstance"))
class UFortWalkAnimInstance : public UFortLocomotionAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="TurnInPlace")
	FCachedAnimStateArray TurnInitiatingStates;

	UPROPERTY(EditDefaultsOnly, Category="TurnInPlace")
	FCachedAnimStateArray TurnTransitionStates;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="Default")
	float MeleeTwistCurveValue;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Aiming")
	FFortAnimInput_AdjustedAim AdjustedAim;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	FFortLocomotionAnimSet CurrentLocomotionAnimSet;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="Locomotion")
	FFortAnimInput_SpeedWarping StartSpeedWarping;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="Locomotion")
	FFortAnimInput_SpeedWarping SpeedWarping;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="Locomotion")
	FVector ActorSpaceVelocityDirPreTurn;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="Locomotion")
	float LeanAdditiveAlpha;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="Locomotion")
	float LeanAngle;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="Locomotion")
	float Speed2D;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="Locomotion")
	float LocalVelocityYawAngle;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="Locomotion")
	float LocalVelocityYawAngleMinusMeleeTwist;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="Locomotion")
	float StopAnimDeltaAngle;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="Locomotion")
	float TransitionPlayRate;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="Locomotion")
	float StartAnimDeltaAngleNorth;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="Locomotion")
	float StartAnimDeltaAngleEast;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="Locomotion")
	float StartAnimDeltaAngleSouth;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="Locomotion")
	float StartAnimDeltaAngleWest;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	float StartSpeedWarpingAlpha;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="Locomotion")
	float PostPivotAnimDeltaAngle;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="Locomotion")
	float PrePivotTimer;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="Locomotion")
	float PrePivotAnimDeltaAngle;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="Locomotion")
	EFortCardinalDirection StopCardinalDirection;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="Locomotion")
	EFortCardinalDirection PrePivotCardinalDirection;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="Locomotion")
	EFortCardinalDirection LocomotionCardinalDirection;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="Locomotion")
	EFortCardinalDirection PostPivotCardinalDirection;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="Idle")
	FVector StandardIdlePelvisOffset;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="Idle")
	FVector IdlePelvisOffset;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="Idle")
	float IdlePelvisOffsetAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Turning")
	FFortAnimInput_TurnInPlace TurnInPlaceInput;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="Turning")
	float YawDeltaSmoothed;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="Turning")
	float AbsYawDeltaSmoothed;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="Default")
	uint8 bIsPlayingMeleeAnim : 1;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="Default")
	uint8 bDisableUpperBodySlotOnLowerBodyInIdle : 1;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="Default")
	uint8 bIsTargeting : 1;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="Default")
	uint8 bIsSurfaceSwimming : 1;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="Locomotion")
	uint8 bShouldPlayStopTransition : 1;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="Locomotion")
	uint8 bShouldEarlyOutStopState : 1;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="Locomotion")
	uint8 bShouldPlayPivotTransition : 1;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="Locomotion")
	uint8 bShouldEarlyOutPivotState : 1;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="Locomotion")
	uint8 bShouldWalkRightFootFwd : 1;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="Locomotion")
	uint8 bShouldPlayPostPivotTransition : 1;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="Locomotion")
	uint8 bShouldPlayStartTransition : 1;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="Locomotion")
	uint8 bShouldEarlyOutStartState : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transitions")
	uint8 bLocomotion_Idles_to_Turns : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transitions")
	uint8 bEarlyOut_Lowerbody_Turns : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transitions")
	uint8 bTransition_LowerBody_Movement : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transitions")
	uint8 bTransition_LowerBody_Shuffle : 1;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="Jump")
	uint8 bIsWaterJump : 1;

};

