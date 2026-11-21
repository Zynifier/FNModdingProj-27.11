// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Curves/CurveFloat.h"
#include "GameplayTagContainer.h"
#include "Athena/FortPhysicsVehicleConfigs.h"
#include "RockScalableFloat.h"
#include "RockVehicleConfigs.generated.h"

USTRUCT(BlueprintType)
struct ROCKVEHICLERUNTIME_API FRockRuntimeConfigOverrides
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Transient, Category="RockRuntimeConfigOverrides")
	bool bDamageFriendlyVehicles;

	UPROPERTY(BlueprintReadWrite, Transient, Category="RockRuntimeConfigOverrides")
	bool bDamageOtherVehicles;

	UPROPERTY(BlueprintReadWrite, Transient, Category="RockRuntimeConfigOverrides")
	bool bDamageOwnVehicle;

	UPROPERTY(BlueprintReadWrite, Transient, Category="RockRuntimeConfigOverrides")
	bool bDamageAllowedFromOtherVehicle;

};

USTRUCT(BlueprintType)
struct FRockThrottledValue
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RockThrottledValue")
	float RiseRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RockThrottledValue")
	float FallRate;

};

USTRUCT(BlueprintType)
struct FRockVehicleSuspensionConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VehicleSuspensionSetup")
	float MaxRaise;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VehicleSuspensionSetup")
	float MaxDrop;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VehicleSuspensionSetup")
	float Stiffness;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VehicleSuspensionSetup")
	float DampingCompression;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VehicleSuspensionSetup")
	float DampingRelaxation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VehicleSuspensionSetup")
	float Strength;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VehicleSuspensionSetup")
	float RockDampingCompression;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VehicleSuspensionSetup")
	float RockDampingRelaxation;

};

USTRUCT(BlueprintType)
struct FRockVehicleAxleConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VehicleAxleSetup")
	float TranslateX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VehicleAxleSetup")
	float TranslateY;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VehicleAxleSetup")
	float TranslateZ;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VehicleAxleSetup")
	float WheelRadius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VehicleAxleSetup")
	float RestDistanceZ;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VehicleBoxSetup")
	FRockVehicleSuspensionConfig Suspension;

};

USTRUCT(BlueprintType)
struct FRockVehicleDemoConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RockVehicle")
	FGameplayTagContainer VehiclesThatCanBeDemolished;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RockVehicle")
	float DemolishAngleYaw;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RockVehicle")
	float DemolishAnglePitch;

};

USTRUCT(BlueprintType)
struct FRockVehicleDriveConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Drive")
	FRockScalableFloat DriveAccel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Drive")
	FRockScalableFloat DriveTopSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Drive")
	FRockScalableFloat BrakeAccel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Drive")
	FRockScalableFloat StopSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Drive")
	float IdleBrakeFactor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Drive")
	FRuntimeFloatCurve DriveAccelCurve;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Steer")
	FRuntimeFloatCurve SteerAngleCurve;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Friction")
	FRuntimeFloatCurve LatFrictionCurve;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Friction")
	FRuntimeFloatCurve LongFrictionCurve;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Friction")
	FRuntimeFloatCurve WallFrictionCurve;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Handbrake")
	FRuntimeFloatCurve HandbrakeSteerAngleCurve;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Handbrake")
	FRuntimeFloatCurve HandbrakeLatFrictionCurve;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Handbrake")
	FRuntimeFloatCurve HandbrakeLongFrictionCurve;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Handbrake")
	FRockThrottledValue HandbrakeRate;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class URockVehicleConfigs : public UFortPhysicsVehicleConfigs
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="RockVehicle")
	FRockVehicleAxleConfig FrontAxle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="RockVehicle")
	FRockVehicleAxleConfig BackAxle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="RockVehicle")
	FRockVehicleDriveConfig Drive;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="RockVehicle")
	FRockVehicleDemoConfig DemolitionConfiguration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RockVehicle")
	FRockScalableFloat MaxLinearSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RockVehicle")
	FRockScalableFloat SupersonicSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RockVehicle")
	float MaxAngularSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Rock")
	float SafeBuildingLandingDegrees;

};

