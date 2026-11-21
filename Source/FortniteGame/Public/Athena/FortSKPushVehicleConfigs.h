// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/FortPhysicsVehicleConfigs.h"
#include "FortSKPushVehicleConfigs.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UFortSKPushVehicleConfigs : public UFortPhysicsVehicleConfigs
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Push Vehicle")
	float PedalForceMultiplier;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Push Vehicle")
	float PedalTopSpeedMultiplier;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Push Vehicle")
	float PedalForceDuration;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Push Vehicle")
	float CoastBrakingMinDelta;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Push Vehicle")
	float CoastBrakingMaxDelta;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Push Vehicle")
	float PedalMinDuration;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Push Vehicle")
	float MountDuration;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Push Vehicle")
	float DismountDuration;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Push Vehicle")
	float MinPreDismountCooldown;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Push Vehicle")
	float PreDismountCooldown;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Push Vehicle")
	float PedalCooldown;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Push Vehicle")
	float CoastBrakingStrength;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Push Vehicle")
	float ShoppingMinPedalCoastSpeed;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Push Vehicle")
	float VehicleDebugStrafeCoastMultiplier;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Push Vehicle")
	float CanCoastCooldown;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Push Vehicle")
	float MaxAutoDismountForwardSpeed;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Push Vehicle")
	float PedalMinForwardVelocity;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Push Vehicle")
	float FastDismountDuration;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Push Vehicle")
	float CanCoastAfterFastDismountCooldown;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Push Vehicle")
	float PassengerVehicleWeightShiftYawStrength;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Push Vehicle")
	float MinPushForceMagnitude;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Push Vehicle")
	float MinGearRampTime;

};

