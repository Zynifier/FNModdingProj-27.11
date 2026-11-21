// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/FortPhysicsVehicleConfigs.h"
#include "Athena/Vehicle/FortFlightModel.h"
#include "Athena/Vehicle/FortRechargingActionTimer.h"
#include "FortDoghouseVehicleConfigs.generated.h"

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UFortDoghouseVehicleConfigs : public UFortPhysicsVehicleConfigs
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Doghouse")
	float PropSpeedPerLinearSpeed;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Doghouse")
	float PropSpeedPerLinearSpeedPassive;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Doghouse")
	float PropSpeedAccelLerpPerSecond;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Doghouse")
	float PropSpeedDecelLerpPerSecond;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Doghouse")
	float TaxiPitchProjTarget;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Doghouse|Altitude")
	float MaxAltitudeZ;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Doghouse|Altitude")
	float StallAltitudeZ;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Doghouse|Altitude")
	float StallTime;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Doghouse")
	float StuckTimeBeforeStall;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Doghouse|Altitude")
	float MinSkipShocksAltitudeZ;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Doghouse|Altitude")
	float AltitudeUpdateFrequency;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Doghouse|Altitude")
	float ControlStateNetUpdateFrequency;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Doghouse|Altitude")
	float ForceHeadingUpdateFrequency;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Doghouse")
	FFlightParams BaseFlightParams;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Doghouse")
	float AileronRollMatchRate;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Doghouse")
	float AileronRollRotationalDampingCoefficient;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Doghouse")
	float AileronRollMaxRotationalDampingTorque;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Doghouse")
	float DivebombSpeedMinKmh;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Doghouse")
	float DivebombSpeedMaxKmh;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Doghouse")
	float DivebombSteerPitchRate;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Doghouse")
	float DivebombHeadingMatchRate;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Doghouse")
	float HardRollHeadingMatchRate;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Doghouse")
	float HardRollHeadingSteerRate;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Doghouse")
	float HardRollOffsetPercent;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Doghouse")
	float TimeBeforeStallWithNoPassengersInAir;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Doghouse")
	float TimeBeforeStallWithNoPassengersOnGround;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Doghouse")
	float BoostTopSpeedKmh;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Doghouse")
	float BoostThrust;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Doghouse")
	float AileronRollDoubleClickSpeed;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Doghouse")
	FFortRechargingActionTimerConfig BoostConfig;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Doghouse")
	FFortRechargingActionTimerConfig AileronRollConfig;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Doghouse")
	float PitchBiasOnGround;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Doghouse")
	float HeadingAutoCenterRate;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Doghouse")
	float RollAutoCenterRate;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Doghouse")
	float AirbrakeDragCoefficient;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Doghouse|Destruction")
	bool bEngineStallAtCriticalHealth;

};

