// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Animation/FortAnimInputs.h"
#include "Animation/PlayerAnimInstances/FortPlayerAnimInstanceProxy.h"
#include "FortPlayerAnimInstance_ATVDriver.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortPlayerAnimInstance_ATVDriver : public UFortPlayerAnimInstanceProxy
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void AnimNotify_JumpEntered();

	UPROPERTY(BlueprintReadOnly, Category="ATVDriver")
	FFortAnimInput_Quad QuadBikeInput;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ATVDriver")
	FFortAnimInput_VelocityImpact VelocityImpact;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ATVDriver")
	FVector ImpactDisplacement;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ATVDriver")
	float AbsSteerAngle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ATVDriver")
	bool bInAir;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ATVDriver")
	bool bIsInRollAngleThreshold;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ATVDriver")
	bool bIsDriveStarting;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ATVDriver")
	FVector LocalLeftOffset;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ATVDriver")
	FVector WorldPosLeft;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ATVDriver")
	FRotator LocalRotLeftOffset;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ATVDriver")
	FRotator WorldRotLeft;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ATVDriver")
	FVector LocalRightOffset;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ATVDriver")
	FVector WorldPosRight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ATVDriver")
	FRotator LocalRotRightOffset;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ATVDriver")
	FRotator WorldRotRight;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ATVDriver")
	bool bIsSteeringRotating;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ATVDriver")
	bool bIsStopped;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ATVDriver")
	bool bIsSlowingDown;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ATVDriver")
	bool bIsDrivingFast;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ATVDriver")
	bool bIsTurningRightHard;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ATVDriver")
	bool bIsTurningLeftHard;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ATVDriver")
	bool bIsBraking;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ATVDriver")
	bool bIsBoosting;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ATVDriver")
	bool bIsJumpTrick;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ATVDriver")
	float JumpPlayRate;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ATVDriver")
	bool bIsJumpFlipping;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ATVDriver")
	bool bShouldEnableAO;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ATVDriver")
	bool bIsBodyDragging;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ATVDriver")
	float FallDistanceJumpingThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ATVDriver")
	float FallDistanceJumpTrickThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ATVDriver")
	float RollAngleThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ATVDriver")
	float StartSpeedThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ATVDriver")
	float SlowingSpeedThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ATVDriver")
	float FastSpeedThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ATVDriver")
	float BrakingDeltaThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ATVDriver")
	float SteerHardAngleThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ATVDriver")
	float GroundTraceUpOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ATVDriver")
	float GroundTraceLength;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ATVDriver")
	FVector2D JumpPlayRateInRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ATVDriver")
	FVector2D JumpPlayRateOutRange;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ATVDriver")
	bool bIsJumpingAndNotRolling;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ATVDriver")
	bool bIsOnGroundAndNotRolling;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ATVDriver")
	bool bIsOnGroundAndBoosting;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ATVDriver")
	bool bPlayPivotOnGroundAndNotBoosting;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ATVDriver")
	FVector2D LandStartPosInRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ATVDriver")
	FVector2D LandStartPosOutRange;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ATVDriver")
	float LandStartPosition;

	UPROPERTY(Transient)
	uint8 bPivotTransitionDoOnceTriggered : 1;

};

