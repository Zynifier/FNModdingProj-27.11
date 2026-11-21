// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "Athena/FortDoghouseVehicleConfigs.h"
#include "FortFerretVehicleConfigs.generated.h"

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FFerretVehicleBoostLevel
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FerretVehicleBoostLevel")
	float AccumulationPercent;

	UPROPERTY(EditAnywhere, Category="FerretVehicleBoostLevel")
	float BoostTime;

};

UCLASS(BlueprintType, Blueprintable)
class UFortFerretVehicleConfigs : public UFortDoghouseVehicleConfigs
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
	float MinSpeedForWingTrails;

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
	float BoostingCameraShakeAmount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="CameraShake")
	float BoostCameraShakeFrequency;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="CameraShake")
	float SmoothedSpringCompressionMin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="CameraShake")
	float SmoothedSpringCompressionMax;

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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Weapon")
	FName LeftMuzzleSocketName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Weapon")
	FName RightMuzzleSocketName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle")
	float MaxHealthToDestroyPropWithDirectHit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle")
	float ImpactScaleWhenBoosting;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle")
	float MaxAltitudeForWaterTest;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle")
	bool bUseBiplaneComponentsForProjectileOrigins;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle")
	bool bUseLTMBiplaneForReplayWeaponFX;

};

