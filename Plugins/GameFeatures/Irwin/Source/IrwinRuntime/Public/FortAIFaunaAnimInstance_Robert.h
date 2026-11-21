// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortAIFaunaAnimInstance.h"
#include "FortAIFaunaAnimInstance_Robert.generated.h"

class AFortAIPawn;

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortAIFaunaAnimInstance_Robert : public UFortAIFaunaAnimInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	float CalculateLocomotionPoseAdditiveAlpha();

	UFUNCTION(BlueprintPure)
	bool DetermineEnableHeadTiltDownAdditive();

	UFUNCTION(BlueprintPure)
	bool DetermineIdleStartTurn();

	UFUNCTION(BlueprintPure)
	bool DetermineIsFullBodyInPlace();

	UFUNCTION(BlueprintCallable)
	void UpdateEnableHeadTiltDownAdditive();

	UFUNCTION(BlueprintCallable)
	void UpdateIdleStartTurn();

	UFUNCTION(BlueprintCallable)
	void UpdateIsFullBodyInPlace();

	UFUNCTION(BlueprintCallable)
	void UpdateLocomotionPoseAdditiveAlpha();

	UFUNCTION(BlueprintCallable)
	void UpdateStateVariables();

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|Properties")
	TObjectPtr<AFortAIPawn> AIPawn;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|Properties")
	bool bIdleStartTurn;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|Properties")
	bool bEnableHeadTiltDownAdditive;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|Properties")
	bool bIsFullBodyInPlace;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|Properties")
	float LocomotionPoseAdditiveAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|Properties")
	bool bIsIdleShuffleTurn;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|Properties")
	float IdleShuffleBodyBend;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|Properties")
	float IdleShufflePlayRate;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|Properties")
	bool bIdleShuffleTurnDirection;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|Properties")
	bool bLookAtAdditiveTurnAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|Properties")
	bool bTurnDirection;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|Magic Numbers")
	int32 PawnIDScale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|Magic Numbers")
	int32 HeadTiltDownAdditiveFrequenceySeconds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|Magic Numbers")
	float ForceFullBodyTransition;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|Magic Numbers")
	float LocomotionPoseAdditiveAlphaInterpRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|Magic Numbers")
	float IdleStartTurnInterruptibleThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|Magic Numbers")
	float LookAtAlphaThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|Magic Numbers")
	float SpeedMovingThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|Magic Numbers")
	float TurnDirectionThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|Magic Numbers")
	float SprintStopThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|Magic Numbers")
	float WalkStopThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|Magic Numbers")
	float BackwardStopThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|Magic Numbers")
	float AdditiveInterruptibleThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|Magic Numbers")
	float InterruptibleThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|Magic Numbers")
	float TurningRightThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|Magic Numbers")
	float LeftFootStopThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|Magic Numbers")
	float HipInterpSpeed_Fast;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|Magic Numbers")
	float HipInterpSpeed_Slow;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|Magic Numbers")
	float AdditiveHipAlphaTargeting_Constant;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|Magic Numbers")
	float BackwardLocomotionThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|Magic Numbers")
	float LocomotionThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|Magic Numbers")
	float PawnSpeedThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|Magic Numbers")
	float LocomotionPlayRate_Fixed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|Magic Numbers")
	float BoostJumpingThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|Magic Numbers")
	float BoostStartPosition_Jumping;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|Magic Numbers")
	float BoostStartPosition_NotJumping;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|Magic Numbers")
	float AdditiveBodyTurnSwimInRangeA;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|Magic Numbers")
	float AdditiveBodyTurnSwimInRangeB;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|Magic Numbers")
	float AdditiveBodyTurnSwimOutRangeA;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|Magic Numbers")
	float AdditiveBodyTurnSwimOutRangeB;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|Magic Numbers")
	float AdditiveBodyTurnNotSwimInRangeA;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|Magic Numbers")
	float AdditiveBodyTurnNotSwimInRangeB;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|Magic Numbers")
	float AdditiveBodyTurnNotSwimOutRangeA;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|Magic Numbers")
	float AdditiveBodyTurnNotSwimOutRangeB;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|Magic Numbers")
	float BodyTurnInterpSpeed_Accel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|Magic Numbers")
	float BodyTurnInterpSpeed_NotAccel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|Magic Numbers")
	float IdleAdditiveBodyTurnTarget_NotAccel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|Magic Numbers")
	float AdditiveLeanAlphaTargeting_Targeting;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|Magic Numbers")
	float AdditiveLeanAlphaTargeting_NonTargeting;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|Magic Numbers")
	float AdditiveLeanAlphaInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|Magic Numbers")
	float AdditiveHipStopAlphaTargeting_PlayerTargeting;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|Magic Numbers")
	float HipInterpSpeed_PlayerTargeting;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|Magic Numbers")
	float AdditiveHipStopAlphaTargeting_NotPlayerTargeting;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|Magic Numbers")
	float HipInterpSpeed_NotPlayerTargeting;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|Magic Numbers")
	float LocomotionSecondaryInRangeA;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|Magic Numbers")
	float LocomotionSecondaryInRangeB;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|Magic Numbers")
	float LocomotionSecondaryOutRangeA;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|Magic Numbers")
	float LocomotionSecondaryOutRangeB;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|Magic Numbers")
	float SwimCameraRotationSecondaryInRangeA;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|Magic Numbers")
	float SwimCameraRotationSecondaryInRangeB;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|Magic Numbers")
	float SwimCameraRotationSecondaryOutRangeA;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|Magic Numbers")
	float SwimCameraRotationSecondaryOutRangeB;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|Magic Numbers")
	float SwimRaptorRotationSecondaryInRangeA;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|Magic Numbers")
	float SwimRaptorRotationSecondaryInRangeB;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|Magic Numbers")
	float SwimRaptorRotationSecondaryOutRangeA;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|Magic Numbers")
	float SwimRaptorRotationSecondaryOutRangeB;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|Magic Numbers|Idle Shuffle")
	float IdleShuffleBodyBendMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|Magic Numbers|Idle Shuffle")
	float IdleShuffleTurnThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|Magic Numbers|Idle Shuffle")
	float IdleShuffleTurnDirectionThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|Magic Numbers|Idle Shuffle|Map Range")
	float IdleShufflePlayRateInRangeA;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|Magic Numbers|Idle Shuffle|Map Range")
	float IdleShufflePlayRateInRangeB;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|Magic Numbers|Idle Shuffle|Map Range")
	float IdleShufflePlayRateOutRangeA;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|Magic Numbers|Idle Shuffle|Map Range")
	float IdleShufflePlayRateOutRangeB;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|State|Properties")
	bool bStateRule_Idle_Moving;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|State|Properties")
	bool bStateRule_Moving_Idle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|State|Properties")
	bool bStateRule_Swimming_Fall;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|State|Properties")
	bool bStateRule_Land_Idle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|State|Properties")
	bool bStateRule_Fall_Idle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|State|Properties")
	bool bStateRule_Fall_Moving;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|State|Properties")
	bool bStateRule_SwimIdle_SwimLoco;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|State|Properties")
	bool bStateRule_IsTurnInPlace;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|State|Properties")
	bool bStateRule_IsSprintStop;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|State|Properties")
	bool bStateRule_IsStopBackwards;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|State|Properties")
	bool bStateRule_IsLocomotion;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|State|Properties")
	bool bStateRule_IsFinishedTurnInPlace;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|State|Properties")
	bool bStateRule_IsInterruptible;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|State|Properties")
	bool bStateRule_IsIdleTurnRight;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|State|Properties")
	bool bStateRule_IsLeftFootStop;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|State|Properties")
	bool bStateRule_IsTurningRight;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|State|Properties")
	bool bStateRule_IsAdditiveInterruptible;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|State|Properties")
	bool bStateRule_IsBackwardLocomotion;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|State|Properties")
	bool bStateRule_IsJumpIdleLand;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|State|Properties")
	bool bStateRule_IsIdleTurnToIdleTurn;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|State|Properties")
	bool bStateRule_BoostJumpToBoostLand;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|State|Properties")
	bool bStateRule_IsJumpToBoostJump;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|State|Properties")
	bool bStateRule_IsJumpToJumpLand;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|State|Properties")
	bool bStateRule_BoostFallLoopToBoostLand;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|State|Properties")
	bool bStateRule_IsLocomotionToIdle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|State|Properties")
	bool bStateRule_IsExitLocomotionToIdle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|State|Properties")
	bool bStateRule_IsLocomotionHoldToSecondary;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|State|Properties")
	bool bStateRule_IsLocomotionSecondaryToHold;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|State|Properties")
	bool bStateRule_IsJumpAdditive;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|State|Properties")
	bool bStateRule_IsLandAdditiveToJump;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|State|Properties")
	bool bStateRule_IsAllowSlopeSlide;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|State|Properties")
	bool bStateRule_IsToJumpState;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|State|Properties")
	bool bIsRidden;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|State|Properties")
	bool bIsStop;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|State|Properties")
	bool bIsWalkStop;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|State|Properties")
	float AdditiveHipAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|State|Properties")
	float AdditiveBodyAlpha;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Robert|State|Properties")
	float RiderAimYaw;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Robert|State|Properties")
	float PlayerSlopePitch;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Robert|State|Properties")
	bool bIsPlayerTargeting;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|State|Properties")
	float AdditiveHipAlphaTargeting;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|State|Properties")
	float HipInterpSpeed;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|State|Properties")
	float IdleAdditiveBodyTurnTarget;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|State|Properties")
	float BodyTurnAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|State|Properties")
	float BodyTurnInterpSpeed;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|State|Properties")
	float LocomotionPlayRate;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|State|Properties")
	float AdditiveLeanAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|State|Properties")
	float AdditiveLeanAlphaTargeting;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|State|Properties")
	float BoostStartPosition;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|State|Properties")
	float AdditiveHipStopAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|State|Properties")
	float AdditiveHipStopAlphaTargeting;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|State|Properties")
	bool bIsAllowBoost;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|State|Properties")
	bool bIsSlopeWarpHack;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|State|Properties")
	float LocomotionHeadSecondary;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|State|Properties")
	float LocomotionTailSecondary;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|State|Properties")
	float SwimCameraRotationSecondary;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|State|Properties")
	float SwimRaptorRotationSecondary;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|State|Properties")
	float SwimTurnYaw;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|State|Properties")
	float SwimHeadYaw;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|State|Properties")
	bool bAnimRule_NegativeTurnAngle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Robert|Locomotion")
	bool bIsAccelerating2D;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|State|Magic Numbers")
	float InterruptibleMaxCheck;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|State|Magic Numbers")
	float SpeedStopTransition;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|State|Magic Numbers")
	float SpeedIdleMoveTransition;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|State|Magic Numbers")
	float SpeedToMoveMin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robert|State|Magic Numbers")
	float StateTimeFromEndThreshold;

};

