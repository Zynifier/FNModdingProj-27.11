// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/FortPhysicsVehicleConfigs.h"
#include "FortTreadVehicleConfigs.generated.h"

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FRollerSetup
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="RollerSetup")
	FName TopSocket;

	UPROPERTY(EditDefaultsOnly, Category="RollerSetup")
	FName BottomSocket;

	UPROPERTY(EditDefaultsOnly, Category="RollerSetup")
	float Radius;

	UPROPERTY(EditDefaultsOnly, Category="RollerSetup")
	float Width;

	UPROPERTY(EditDefaultsOnly, Category="RollerSetup")
	uint8 Tread;

};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FRollerSetups
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="RollerSetups")
	FRollerSetup FrontRightRoller;

	UPROPERTY(EditDefaultsOnly, Category="RollerSetups")
	FRollerSetup BackRightRoller;

	UPROPERTY(EditDefaultsOnly, Category="RollerSetups")
	FRollerSetup FrontLeftRoller;

	UPROPERTY(EditDefaultsOnly, Category="RollerSetups")
	FRollerSetup BackLeftRoller;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UFortTreadVehicleConfigs : public UFortPhysicsVehicleConfigs
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Tread Vehicle|Speed")
	float TopSpeedKmh;

	UPROPERTY(EditDefaultsOnly, Category="Tread Vehicle|Speed")
	float TopReverseSpeedKmh;

	UPROPERTY(EditDefaultsOnly, Category="Tread Vehicle|Speed|Boost")
	float BoostTopSpeedScale;

	UPROPERTY(EditDefaultsOnly, Category="Tread Vehicle|Steering|Boost")
	float BoostTurnScale;

	UPROPERTY(EditDefaultsOnly, Category="Tread Vehicle|Speed|Ramp", meta=(ClampMin="0"))
	float RampUpTime;

	UPROPERTY(EditDefaultsOnly, Category="Tread Vehicle|Speed|Ramp", meta=(ClampMin="0"))
	float RampDownTime;

	UPROPERTY(EditDefaultsOnly, Category="Tread Vehicle|Speed")
	float TrackFrictionCoefficient;

	UPROPERTY(EditDefaultsOnly, Category="Tread Vehicle|Speed")
	float TrackStiffness;

	UPROPERTY(EditDefaultsOnly, Category="Tread Vehicle|Speed")
	float TrackLateralStiffness;

	UPROPERTY(EditDefaultsOnly, Category="Tread Vehicle|Speed", meta=(ClampMax="1", ClampMin="0"))
	float DisabledTreadPowerScale;

	UPROPERTY(EditDefaultsOnly, Category="Tread Vehicle|Speed", meta=(ClampMax="1", ClampMin="0"))
	float DisabledTreadTopSpeedScale;

	UPROPERTY(EditDefaultsOnly, Category="Tread Vehicle|Speed", meta=(ClampMax="1", ClampMin="0"))
	float DisabledTreadFloorFriction;

	UPROPERTY(EditDefaultsOnly, Category="Tread Vehicle|Tread")
	FRollerSetups RollerSetups;

	UPROPERTY(EditDefaultsOnly, Category="Tread Vehicle|Steering", meta=(ClampMax="1", ClampMin="0"))
	float PowerSpread;

	UPROPERTY(EditDefaultsOnly, Category="Tread Vehicle|Steering", meta=(ClampMin="1"))
	float TurnPower;

	UPROPERTY(EditDefaultsOnly, Category="Tread Vehicle|Steering", meta=(ClampMax="1", ClampMin="-1"))
	float ForwardBias;

	UPROPERTY(EditDefaultsOnly, Category="Tread Vehicle|Steering", meta=(ClampMax="1", ClampMin="0"))
	float ReverseThreshold;

	UPROPERTY(EditDefaultsOnly, Category="Tread Vehicle|Steering", meta=(ClampMax="1", ClampMin="0"))
	bool bCanAlwaysSwitchFromReverseToForward;

	UPROPERTY(EditDefaultsOnly, Category="Tread Vehicle|Tread", meta=(ClampMin="1"))
	float SuspensionPadding;

	UPROPERTY(EditDefaultsOnly, Category="Tread Vehicle|Tread", meta=(ClampMax="1", ClampMin="0"))
	float DisabledTreadSuspensionScale;

	UPROPERTY(EditDefaultsOnly, Category="Tread Vehicle|Tread", meta=(ClampMin="0"))
	float RollerDamping;

	UPROPERTY(EditDefaultsOnly, Category="Tread Vehicle|Tread", meta=(ClampMax="1", ClampMin="0"))
	float TractionScaleInWater;

	UPROPERTY(EditDefaultsOnly, Category="Tread Vehicle|Tread|Compression")
	float CompressionEventVelocity;

	UPROPERTY(EditDefaultsOnly, Category="Tread Vehicle|Tread|Compression")
	float CompressionEventFrequency;

};

