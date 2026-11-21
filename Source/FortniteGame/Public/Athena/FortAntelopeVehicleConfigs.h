// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "Athena/FortPhysicsVehicleConfigs.h"
#include "FortAntelopeVehicleConfigs.generated.h"

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FAntelopeVehicleBoostLevel
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="AntelopeVehicleBoostLevel")
	float AccumulationPercent;

	UPROPERTY(EditAnywhere, Category="AntelopeVehicleBoostLevel")
	float BoostTime;

};

UCLASS(BlueprintType, Blueprintable)
class UFortAntelopeVehicleConfigs : public UFortPhysicsVehicleConfigs
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Settings|Antelope")
	float BounceCrouchTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Settings|Antelope")
	float BounceCrouchTimeDeadzone;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Settings|Antelope")
	float BounceRecoilTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Settings|Antelope")
	float BounceForcePerMass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Settings|Antelope")
	float PassengerLeanMagnitude;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Settings|Antelope")
	float PassengerLeanMinMagnitude;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Settings|Antelope")
	float PassengerLeanLeftRightInterpolationPerSecond;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Settings|Antelope")
	float PassengerLeanUpInterpolationPerSecond;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Settings|Antelope")
	float PassengerLeanDownInterpolationPerSecond;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Settings|Antelope")
	float PassengerLeanResetInterpolationPerSecond;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Settings|Antelope")
	float PassengerLeanDeadzone;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Settings|Antelope")
	float NaturalSlideMinAngle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Settings|Antelope")
	float TractionVelocityDelta;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Settings|Antelope")
	float MinSpeedForWheelRotation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Settings|Antelope")
	float MinSpeedForSkidFX;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Settings|Antelope|Boost")
	float BoostAccumulationRate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Settings|Antelope|Boost")
	float BoostExpenseRate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Settings|Antelope|Boost")
	float BoostPassiveExpenseRate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Settings|Antelope|Boost")
	float BoostTopSpeedMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Settings|Antelope|Boost")
	float BoostTopSpeedInAirMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Settings|Antelope|Boost")
	float BoostAirMaxSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Settings|Antelope|Boost")
	float BoostForceInAir;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Settings|Antelope|Boost")
	float BoostSteeringMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Settings|Antelope|Boost")
	float BoostCooldown;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Settings|Antelope|Boost")
	float BoostSteeringMultiplierRampTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Settings|Antelope|Boost")
	float BoostSlowExtraStrength;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Settings|Antelope|Boost")
	float BoostTopSpeedForceMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Settings|Antelope|Boost")
	float VehicleBoostFrontFrictionMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Settings|Antelope|Boost")
	float VehicleBoostRearFrictionMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Settings|Antelope|Boost")
	float BoostMinPushForce;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Settings|Antelope|Boost")
	float BoostSmashForgivenessDuration;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Settings|Antelope|Boost")
	float MinBoostTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Settings|Antelope|CameraShake")
	float CameraShakeAmplitudeMin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Settings|Antelope|CameraShake")
	float CameraShakeAmplitudeMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Settings|Antelope|CameraShake")
	float SpringFudgeFactor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Settings|Antelope|CameraShake")
	float CameraShakeNormalizedSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Settings|Antelope|CameraShake")
	float CameraShakeSpeedCurvePow;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Settings|Antelope|CameraShake")
	float BoostingCameraShakeAmount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Settings|Antelope|CameraShake")
	float BoostCameraShakeFrequency;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Settings|Antelope|CameraShake")
	float SmoothedSpringCompressionMin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Settings|Antelope|CameraShake")
	float SmoothedSpringCompressionMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Settings|Antelope|CameraShake")
	float ScreenShakeFrequencyMin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Settings|Antelope|CameraShake")
	float ScreenShakeFrequencyMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Settings|Antelope|CameraShake")
	float PassengerCameraShakeMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Settings|Antelope|CameraShake")
	float ScreenShakeYawFrequencyMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Settings|Antelope|WheelFX")
	FLinearColor WheelSlideBoostColorWhenNotPowerSliding;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Settings|Antelope|WheelFX")
	float TreadWidth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Settings|Antelope|Rumble")
	float RumbleMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Settings|Antelope|Rumble")
	float SparksRumbleMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Settings|Antelope|CameraOffset")
	float BoostCameraOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Settings|Antelope|CameraOffset")
	float ADSCameraDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Settings|Antelope|CameraOffset")
	float PassengerCameraOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Settings|Antelope|CameraOffset")
	float ADSInterpSpeed;

};

