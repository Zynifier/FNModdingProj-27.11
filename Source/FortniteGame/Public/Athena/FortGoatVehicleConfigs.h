// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "Athena/FortPhysicsVehicleConfigs.h"
#include "FortGoatVehicleConfigs.generated.h"

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FGoatVehicleBoostLevel
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="GoatVehicleBoostLevel")
	float AccumulationPercent;

	UPROPERTY(EditAnywhere, Category="GoatVehicleBoostLevel")
	float BoostTime;

};

UCLASS(BlueprintType, Blueprintable)
class UFortGoatVehicleConfigs : public UFortPhysicsVehicleConfigs
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float BounceCrouchTime;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float BounceCrouchTimeDeadzone;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float BounceRecoilTime;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float BounceForcePerMass;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float PassengerLeanMagnitude;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float PassengerLeanMinMagnitude;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float PassengerLeanLeftRightInterpolationPerSecond;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float PassengerLeanUpInterpolationPerSecond;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float PassengerLeanDownInterpolationPerSecond;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float PassengerLeanResetInterpolationPerSecond;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float PassengerLeanDeadzone;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float HandBrakeForce;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float PowerSlideMinAngle;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float MinLateralSpeedForPowerSlideBoost;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Vehicle")
	float MaxAccumulatedPowerSlideBoost;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Vehicle")
	TArray<FGoatVehicleBoostLevel> PowerSlideBoostAccumulationSteps;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float PowerSlideAccumulationMultiplier;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float PowerSlideTopSpeedMultiplier;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float PowerSlideTopSpeedInAirMultiplier;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float PowerSlideStrength;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float PowerSlideMinAngularSpeed;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float PowerSlideMaxAngularSpeed;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float BoostSteeringMultiplier;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float BoostCooldown;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float BoostSteeringMultiplierRampTime;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float BoostSlowExtraStrength;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float MinForwardSpeedBoostExtraStrength;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float BoostTopSpeedForceMultiplier;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float VehiclePowerSlideFrontMultiplier;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float VehiclePowerSlideRearMultiplier;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float PowerSlideMinPushForce;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="CameraShake")
	float CameraShakeAmplitudeMin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="CameraShake")
	float CameraShakeAmplitudeMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="CameraShake")
	float SpringFudgeFactor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="CameraShake")
	float CameraShakeNormalizedSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="CameraShake")
	float CameraShakeSpeedCurvePow;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="CameraShake")
	float PowerSlideShakeMultiplierMin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="CameraShake")
	float PowerSlideShakeMultiplierMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="CameraShake")
	float BoostingCameraShakeAmount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="CameraShake")
	float BoostCameraShakeFrequency;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="CameraShake")
	float SmoothedSpringCompressionMin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="CameraShake")
	float SmoothedSpringCompressionMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="CameraShake")
	float PowerSlideMinSpringCompression;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="CameraShake")
	float ScreenShakeFrequencyMin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="CameraShake")
	float ScreenShakeFrequencyMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="CameraShake")
	float PassengerCameraShakeMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="CameraShake")
	float ScreenShakeYawFrequencyMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="WheelFX")
	FLinearColor WheelSlideBoostColorWhenNotPowerSliding;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="WheelFX")
	float TreadWidth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Rumble")
	float RumbleMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Rumble")
	float SparksRumbleMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="CameraOffset")
	float BoostCameraOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="CameraOffset")
	float ADSCameraDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="CameraOffset")
	float PassengerCameraOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="CameraOffset")
	float ADSInterpSpeed;

};

