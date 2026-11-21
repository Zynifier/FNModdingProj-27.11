// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/FortPhysicsVehicleConfigs.h"
#include "FortMeatballVehicleConfigs.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UFortMeatballVehicleConfigs : public UFortPhysicsVehicleConfigs
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="WaterControl")
	float WaterSteerRollFactor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="WaterControl")
	float InnerTurnPontoonOffsetMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="WaterControl")
	float OuterTurnPontoonOffsetMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="WaterControl")
	float MinForwardSpeedToBankOnTurn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle")
	float BoostMinPushForce;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle")
	float BoostTopSpeedForceMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle")
	float BoostTopSpeedMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle")
	float MaxPontoonOffsetPerSecond;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle")
	float LandTopSpeedMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle")
	float LandPushForceMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle")
	int32 MinPushPontoonsForWaterDriving;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle")
	float MaxWaterPitchAngle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle")
	float MinForwardSpeedToPitch;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle")
	float MinForwardSpeedForMaxPitch;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle")
	float MaxForwardSpeedForMaxPitch;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle")
	float MaxFowrardSpeedPitchFactor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle")
	float BoostMaxForwardSpeedPitchFactor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle")
	float FrontLateralFrictionFactor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle")
	float RearLateralFrictionFactor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle")
	float LandFrontLateralFrictionFactor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle")
	float LandRearLateralFrictionFactor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle")
	float LateralFrictionModStartSpeedKmh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle")
	float RearLateralFrictionModPerSpeedKmh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle")
	float FrontLateralFrictionModPerSpeedKmh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle")
	float SeatOffsetScaleX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle")
	float SeatOffsetScaleY;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle")
	float SeatYawAngleMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle")
	float SeatPitchAngleMax;

	UPROPERTY(EditAnywhere, Config, Category="VehicleBoost")
	float BoostSteeringMultiplier;

	UPROPERTY(EditAnywhere, Config, Category="VehicleBoost")
	float BoostSteeringMultiplierRampTime;

	UPROPERTY(EditAnywhere, Config, Category="VehicleBoost")
	float LandSteeringMultiplier;

	UPROPERTY(EditAnywhere, Config, Category="VehicleBoost")
	float LandMinSpeedSteeringAngle;

	UPROPERTY(EditAnywhere, Config, Category="VehicleBoost")
	float LandMaxSpeedSteeringAngle;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle")
	float DragCoefficientNoAccel;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle")
	float DragCoefficient2NoAccel;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle")
	float DragCoefficientMultiplierRoad;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle")
	float DragCoefficientMultiplierGrass;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle")
	float DragCoefficientMultiplierDirt;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle")
	float DragCoefficientMultiplierSnow;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle")
	float DragCoefficientMultiplierIce;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle")
	float DragCoefficientMultiplierMud;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle")
	float MinSteerAlphaForWaterFriction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle")
	float TurnInPlaceYawStiff;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle")
	float TurnInPlaceYawDamp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="WaterControl")
	float MaxSteerRollAngle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle")
	float MaxTurnInPlaceYawAngle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="WaterControl")
	float UprightSpringSteerStrength;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle")
	float TurnInPlaceYawStrength;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float MaxSpeedForTurnInPlaceKmH;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float BlendOutExtraSpeedTurnInPlaceKmH;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float MaxPitchForCameraInPlaceSteer;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float SpringLengthMutliplierWater;

};

