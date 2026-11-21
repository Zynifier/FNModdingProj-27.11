// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Animation/FortAnimInputs.h"
#include "Animation/FortAnimTypes.h"
#include "Animation/PlayerAnimInstances/FortPlayerAnimInstanceProxy.h"
#include "FortPlayerAnimInstance_FerretDriver.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortPlayerAnimInstance_FerretDriver : public UFortPlayerAnimInstanceProxy
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void AnimNotify_JumpEntered();

	UPROPERTY(BlueprintReadOnly, Transient, Category="FerretDriver")
	FFortAnimInput_FerretVehicle FerretVehicleInput;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ATVDriver")
	FFortAnimInput_VelocityImpact VelocityImpact;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FerretDriver")
	FVector ImpactDisplacement;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ATVDriver")
	float AbsSteerAngle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FerretDriver")
	uint8 bInAir : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FerretDriver")
	uint8 bOnGround : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ATVDriver")
	uint8 bIsInRollAngleThreshold : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ATVDriver")
	uint8 bIsDriveStarting : 1;

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
	uint8 bIsSteeringRotating : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ATVDriver")
	uint8 bIsStopped : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ATVDriver")
	uint8 bIsSlowingDown : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ATVDriver")
	uint8 bIsDrivingFast : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ATVDriver")
	uint8 bIsTurningRightHard : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ATVDriver")
	uint8 bIsTurningLeftHard : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ATVDriver")
	uint8 bIsBraking : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ATVDriver")
	uint8 bIsBoosting : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ATVDriver")
	uint8 bIsJumpTrick : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ATVDriver")
	float JumpPlayRate;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ATVDriver")
	uint8 bIsJumpFlipping : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ATVDriver")
	uint8 bShouldEnableAO : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ATVDriver")
	uint8 bIsBodyDragging : 1;

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
	uint8 bIsJumpingAndNotRolling : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ATVDriver")
	uint8 bIsOnGroundAndNotRolling : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ATVDriver")
	uint8 bIsOnGroundAndBoosting : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ATVDriver")
	uint8 bPlayPivotOnGroundAndNotBoosting : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ATVDriver")
	FVector2D LandStartPosInRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ATVDriver")
	FVector2D LandStartPosOutRange;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ATVDriver")
	float LandStartPosition;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Weapon")
	float DriverAimPitch;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Weapon")
	float DriverAimYaw;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FerretDriver")
	EPlaneDirection FerretCardinalDirection;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FerretDriver")
	float ElevatorDeadZone;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FerretDriver")
	float RudderDeadZone;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FerretDriver")
	uint8 bFerretShouldPlayStartTransition : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FerretDriver")
	uint8 bFerretShouldPlayStopTransition : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FerretDriver")
	EPlaneDirection FerretStopCardinalDirection;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FerretDriver")
	EPlaneDirection FerretPrePivotCardinalDirection;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FerretDriver")
	uint8 bFerretShouldPlayPivotTransition : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FerretDriver")
	uint8 bIsFerretRotating : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FerretDriver")
	uint8 bIsFerretShooting : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FerretDriver")
	float ElevatorRotation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FerretDriver")
	uint8 bIsRollingRight : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FerretDriver")
	uint8 bIsRollingLeft : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FerretDriver")
	FVector LeftHandLocalTranslateOffset;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FerretDriver")
	FVector RightHandLocalTranslateOffset;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FerretDriver")
	FRotator LeftHandLocalRotateOffset;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FerretDriver")
	FRotator RightHandLocalRotateOffset;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FerretDriver")
	FVector LeftHandComponentTranslateOffset;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FerretDriver")
	FVector RightHandComponentTranslateOffset;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FerretDriver")
	FRotator LeftHandComponentRotateOffset;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FerretDriver")
	FRotator RightHandComponentRotateOffset;

private:
	UPROPERTY(Transient)
	FRotator AimRotation;

	UPROPERTY(Transient)
	FTransform OwnerTransform;

};

