// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortAIFaunaAnimInstance.h"
#include "FortAIFaunaAnimInstance_Grandma.generated.h"

class AFortAIPawn;

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortAIFaunaAnimInstance_Grandma : public UFortAIFaunaAnimInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	float CalculateBlinkAlpha();

	UFUNCTION(BlueprintPure)
	float CalculateLocomotionPoseAlpha();

	UFUNCTION(BlueprintPure)
	float CalculateMeshScale();

	UFUNCTION(BlueprintPure)
	float CalculateWalkRunPlayRate();

	UFUNCTION(BlueprintPure)
	bool DetermineEnableAlertAdditive();

	UFUNCTION(BlueprintPure)
	bool DetermineEnableSniffAdditive();

	UFUNCTION(BlueprintPure)
	bool DetermineIdleStartTurn();

	UFUNCTION(BlueprintPure)
	bool DetermineShouldPlayFullBodyInPlace();

	UFUNCTION(BlueprintCallable)
	void UpdateBlinkAlpha();

	UFUNCTION(BlueprintCallable)
	void UpdateEnableAlertAdditive();

	UFUNCTION(BlueprintCallable)
	void UpdateEnableSniffAdditive();

	UFUNCTION(BlueprintCallable)
	void UpdateIdleStartTurn();

	UFUNCTION(BlueprintCallable)
	void UpdateLocomotionPoseAlpha();

	UFUNCTION(BlueprintCallable)
	void UpdateMeshScale();

	UFUNCTION(BlueprintCallable)
	void UpdateMovingRates();

	UFUNCTION(BlueprintCallable)
	void UpdateShouldPlayFullBodyInPlace();

	UFUNCTION(BlueprintCallable)
	void UpdateStateVariables(const bool bAccelerating = false);

	UPROPERTY(BlueprintReadOnly, Transient, Category="Grandma|Properties")
	TObjectPtr<AFortAIPawn> AIPawn;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Grandma|Properties")
	float MeshScale;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Grandma|Properties")
	bool bShouldPlayFullBodyInPlace;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Grandma|Properties")
	float BlinkAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Grandma|Properties")
	float WalkRunPlayRate;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Grandma|Properties")
	float LocomotionPoseAdditiveAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Grandma|Properties")
	bool bEnableSniffAdditive;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Grandma|Properties")
	bool bEnableAlertAdditive;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Grandma|Properties")
	bool bIdleStartTurn;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Grandma|Properties")
	bool bLookAtAdditiveTurnAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Grandma|Properties|Idle Shuffle")
	bool bIsIdleShuffleTurn;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Grandma|Properties|Idle Shuffle")
	float IdleShuffleBodyBend;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Grandma|Properties|Idle Shuffle")
	float IdleShufflePlayRate;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Grandma|Properties|Idle Shuffle")
	bool bIdleShuffleTurnDirection;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Grandma|Properties|Riding")
	float TurnInPlaceModulatedSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Grandma|Magic Numbers")
	float MaxSpeedFullBodyInPlace;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Grandma|Magic Numbers")
	float MinCurveValueFullBodyInPlace;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Grandma|Magic Numbers")
	float LocomotionPoseAdditiveAlphaInterpRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Grandma|Magic Numbers")
	int32 SniffAdditiveFrequenceySeconds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Grandma|Magic Numbers")
	int32 AlertAdditiveFrequenceySeconds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Grandma|Magic Numbers")
	int32 PawnIDScale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Grandma|Magic Numbers")
	FName ShouldPlayFullBodyInPlaceCurveName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Grandma|Magic Numbers")
	FName BlinkAlphaCurveName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Grandma|Magic Numbers")
	float IdleStartTurnInterruptibleThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Grandma|Magic Numbers")
	float IdleShuffleBodyBendMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Grandma|Magic Numbers")
	float IdleShuffleTurnThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Grandma|Magic Numbers")
	float IdleShuffleTurnDirectionThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Grandma|Magic Numbers")
	float LookAtAdditiveTurnAlphaThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Grandma|Magic Numbers|Idle Shuffle Play Rate Map")
	float IdleShufflePlayRateInRangeA;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Grandma|Magic Numbers|Idle Shuffle Play Rate Map")
	float IdleShufflePlayRateInRangeB;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Grandma|Magic Numbers|Idle Shuffle Play Rate Map")
	float IdleShufflePlayRateOutRangeA;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Grandma|Magic Numbers|Idle Shuffle Play Rate Map")
	float IdleShufflePlayRateOutRangeB;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Grandma|Magic Numbers|Riding")
	float TurnInPlaceModulatedSpeedFactor;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Grandma|State|Properties")
	bool bIsMovingOnGroundORIsSurfaceSwimming;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Grandma|State|Properties")
	bool bStateRule_DefaultJump_ToJumpApex;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Grandma|State|Properties")
	bool bStateRule_TurnIdle_Idle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Grandma|State|Properties")
	bool bStateRule_TurnIdle_Moving;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Grandma|State|Properties")
	bool bStateRule_Moving_TurnIdle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Grandma|State|Properties")
	bool bStateRule_TurnMoving_Moving;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Grandma|State|Properties")
	bool bStateRule_Moving_TurnMoving;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Grandma|State|Properties")
	bool bStateRule_Idle_Moving;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Grandma|State|Properties")
	bool bStateRule_Moving_Idle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Grandma|State|Properties")
	bool bStateRule_JumpLand_Idle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Grandma|State|Properties")
	bool bStateRule_JumpLand_Moving;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Grandma|State|Properties")
	bool bStateRule_JumpStart_JumpApex;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Grandma|State|Properties")
	bool bStateRule_Fall_Moving;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Grandma|State|Properties")
	bool bStateRule_Fall_Idle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Grandma|State|Properties")
	bool bStateRule_SwimIdle_SwimLoco;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Grandma|State|Properties")
	bool bStateRule_SwimLoco_SwimIdle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Grandma|State|Properties")
	bool bStateRule_SwimTurn_SwimIdle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Grandma|State|Properties")
	bool bStateRule_SwimTurn_SwimLoco;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Grandma|State|Properties")
	bool bAnimRule_NegativeTurnAngle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Grandma|State|Magic Numbers")
	float InterruptibleMaxCheck;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Grandma|State|Magic Numbers")
	float SpeedStopTransition;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Grandma|State|Magic Numbers")
	float SpeedIdleMoveTransition;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Grandma|State|Magic Numbers")
	float SpeedMovingTurnIdleTransition;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Grandma|State|Magic Numbers")
	float SpeedToMoveMin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Grandma|State|Magic Numbers")
	float SpeedToMoveMinWhileRiding;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Grandma|State|Magic Numbers")
	float SpeedToMoveMinWhileAcceleratingAndRiding;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Grandma|State|Magic Numbers")
	float StateTimeFromEndThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Grandma|State|Magic Numbers")
	float SpeedIdleStartTurnThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Grandma|State|Magic Numbers")
	float SpeedFallMovingThreshold;

};

