// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Animation/FortBaseAnimInstance.h"
#include "FortScoutDroneAnimInstance.generated.h"

class AFortScoutDrone;
class UFortScoutDroneMovementComponent;

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortScoutDroneAnimInstance : public UFortBaseAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Transient, Category="ScoutDrone|Nativized")
	double YawDeltaLastTick;

	UPROPERTY(BlueprintReadWrite, Transient, Category="ScoutDrone|Nativized")
	FRotator ActorCurrentRotationTick;

	UPROPERTY(BlueprintReadWrite, Transient, Category="ScoutDrone|Nativized")
	double YawDeltaCurrentTick;

	UPROPERTY(BlueprintReadWrite, Transient, Category="ScoutDrone|Nativized")
	FRotator ActorRotationLastTick;

	UPROPERTY(BlueprintReadWrite, Transient, Category="ScoutDrone|Nativized")
	bool IsFlying;

	UPROPERTY(BlueprintReadWrite, Transient, Category="ScoutDrone|Nativized")
	double CurrentVelocity;

	UPROPERTY(BlueprintReadWrite, Transient, Category="ScoutDrone|Nativized")
	double LastVelocity;

	UPROPERTY(BlueprintReadWrite, Transient, Category="ScoutDrone|Nativized")
	double Velocity;

	UPROPERTY(BlueprintReadWrite, Transient, Category="ScoutDrone|Nativized")
	double ForwardInputAlpha;

	UPROPERTY(BlueprintReadWrite, Transient, Category="ScoutDrone|Nativized")
	double StrafeInputAlpha;

	UPROPERTY(BlueprintReadWrite, Transient, Category="ScoutDrone|Nativized")
	FRotator DroneRotation;

	UPROPERTY(BlueprintReadWrite, Transient, Category="ScoutDrone|Nativized")
	double Acceleration;

	UPROPERTY(BlueprintReadWrite, Transient, Category="ScoutDrone|Nativized")
	TObjectPtr<AFortScoutDrone> ScoutDrone;

	UPROPERTY(BlueprintReadWrite, Transient, Category="ScoutDrone|Nativized")
	bool IsBoosting;

	UPROPERTY(BlueprintReadWrite, Transient, Category="ScoutDrone|Nativized")
	bool IsDiving;

	UPROPERTY(BlueprintReadWrite, Transient, Category="ScoutDrone|Nativized")
	double AimPitch;

	UPROPERTY(BlueprintReadWrite, Transient, Category="ScoutDrone|Nativized")
	double NegativeAimPitch;

	UPROPERTY(BlueprintReadWrite, Transient, Category="ScoutDrone|Nativized")
	FRotator FinalFanRotationL;

	UPROPERTY(BlueprintReadWrite, Transient, Category="ScoutDrone|Nativized")
	FRotator FinalFanRotationR;

	UPROPERTY(BlueprintReadWrite, Transient, Category="ScoutDrone|Nativized")
	double FanIdleSpeed;

	UPROPERTY(BlueprintReadWrite, Transient, Category="ScoutDrone|Nativized")
	double FanAuthoredSpeed;

	UPROPERTY(BlueprintReadWrite, Transient, Category="ScoutDrone|Nativized")
	double FanIdleAuthoredSpeed;

	UPROPERTY(BlueprintReadWrite, Transient, Category="ScoutDrone|Nativized")
	double FanBwdSpeed;

	UPROPERTY(BlueprintReadWrite, Transient, Category="ScoutDrone|Nativized")
	double FanFwdSpeed;

	UPROPERTY(BlueprintReadWrite, Transient, Category="ScoutDrone|Nativized")
	double TurnNoiseAlpha;

	UPROPERTY(BlueprintReadWrite, Transient, Category="ScoutDrone|Nativized")
	double LeanAlpha;

	UPROPERTY(BlueprintReadWrite, Transient, Category="ScoutDrone|Nativized")
	double TurnAlpha;

	UPROPERTY(BlueprintReadWrite, Transient, Category="ScoutDrone|Nativized")
	bool IsColliding;

	UPROPERTY(BlueprintReadWrite, Transient, Category="ScoutDrone|Nativized")
	bool IsFlyingBwd;

	UPROPERTY(BlueprintReadWrite, Transient, Category="ScoutDrone|Nativized")
	bool ShouldExitFromFlying;

	UPROPERTY(BlueprintReadWrite, Transient, Category="ScoutDrone|Nativized")
	bool ShouldExitFromDiving;

	UPROPERTY(BlueprintReadWrite, Transient, Category="ScoutDrone|Nativized")
	bool EarlyIntoLoop;

	UPROPERTY(BlueprintReadWrite, Transient, Category="ScoutDrone|Nativized")
	double AccelerationZ;

	UPROPERTY(BlueprintReadWrite, Transient, Category="ScoutDrone|Nativized")
	bool IsLeftStrafe;

	UPROPERTY(BlueprintReadWrite, Transient, Category="ScoutDrone|Nativized")
	bool WasStrafing;

	UPROPERTY(BlueprintReadWrite, Transient, Category="ScoutDrone|Nativized")
	double GroundDistance;

	UPROPERTY(BlueprintReadWrite, Transient, Category="ScoutDrone|Nativized")
	bool HasDivingConditionBeenMet;

	UPROPERTY(BlueprintReadWrite, Transient, Category="ScoutDrone|Nativized")
	bool IsItemAttached;

	UPROPERTY(BlueprintReadWrite, Transient, Category="ScoutDrone|Nativized")
	bool IsPlayerAttached;

	UPROPERTY(BlueprintReadWrite, Transient, Category="ScoutDrone|Nativized")
	double FlapTime;

	UPROPERTY(BlueprintReadWrite, Transient, Category="ScoutDrone|Nativized")
	int32 FlapRandomPick;

	UPROPERTY(BlueprintReadWrite, Transient, Category="ScoutDrone|Nativized")
	bool IsFlapSmall;

	UPROPERTY(BlueprintReadWrite, Transient, Category="ScoutDrone|Nativized")
	int32 FlapRandomMaxRange;

	UPROPERTY(BlueprintReadWrite, Transient, Category="ScoutDrone|Nativized")
	double FlapSmallTimeThreshold;

	UPROPERTY(BlueprintReadWrite, Transient, Category="ScoutDrone|Nativized")
	double FlapBigTimeThreshold;

	UPROPERTY(BlueprintReadWrite, Transient, Category="ScoutDrone|Nativized")
	double FlapSmallResetDelayDuration;

	UPROPERTY(BlueprintReadWrite, Transient, Category="ScoutDrone|Nativized")
	double FlapBigResetDelayDuration;

	UPROPERTY(BlueprintReadWrite, Transient, Category="ScoutDrone|Nativized")
	bool IsFlapBig;

	UPROPERTY(BlueprintReadWrite, Transient, Category="ScoutDrone|Nativized")
	double VerticalInputAlpha;

	UPROPERTY(BlueprintReadWrite, Transient, Category="ScoutDrone|Nativized")
	bool WasVerticalUp;

	UPROPERTY(BlueprintReadWrite, Transient, Category="ScoutDrone|Nativized")
	bool IsFlyingVerticalUp;

	UPROPERTY(BlueprintReadWrite, Transient, Category="ScoutDrone|Nativized")
	bool ShouldExitFromBoostOutro;

	UPROPERTY(BlueprintReadWrite, Transient, Category="ScoutDrone|Nativized")
	bool HasSpawned;

	UPROPERTY(BlueprintReadWrite, Transient, Category="ScoutDrone|Nativized")
	bool ShouldExitFromSpawning;

	UPROPERTY(BlueprintReadWrite, Transient, Category="ScoutDrone|Nativized")
	bool ShouldAllowTransition;

	UPROPERTY(BlueprintReadWrite, Transient, Category="ScoutDrone|Nativized")
	bool StateRuleFromBoostOutroToFlying;

	UPROPERTY(BlueprintReadWrite, Transient, Category="ScoutDrone|Nativized")
	bool WasBoosting;

	UPROPERTY(BlueprintReadWrite, Transient, Category="ScoutDrone|Nativized")
	FScalableFloat SpeedBoostForceBoostVelocity;

	UPROPERTY(BlueprintReadWrite, Transient, Category="ScoutDrone|Nativized")
	FScalableFloat SpeedBoostMaxSpeedIncrease;

	UPROPERTY(BlueprintReadWrite, Transient, Category="ScoutDrone|Nativized")
	bool IsFlappingTime;

protected:
	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="FortPlayerPawn", meta=(EditInline="true"))
	TObjectPtr<UFortScoutDroneMovementComponent> FortScoutDroneMovementComponent;

};

