// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Athena/FortPhysicsVehicleConfigs.h"
#include "FortMotorcycleVehicleConfigs.generated.h"

UENUM(BlueprintType)
enum class EFortMotorcycleWheelTraceMode : uint8
{
	None = 0,
	BoxSweep = 1,
	LineTrace = 2,
};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FMotorcycleWheel
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="MotorcycleWheel")
	FName WheelSocket;

	UPROPERTY(EditDefaultsOnly, Category="MotorcycleWheel")
	float Radius;

	UPROPERTY(EditDefaultsOnly, Category="MotorcycleWheel")
	float TireWidth;

	UPROPERTY(EditDefaultsOnly, Category="MotorcycleWheel")
	float SpringLength;

	UPROPERTY(EditDefaultsOnly, Category="MotorcycleWheel")
	float WheelieMinSpringLength;

	UPROPERTY(EditDefaultsOnly, Category="MotorcycleWheel")
	float SpringStiff;

	UPROPERTY(EditDefaultsOnly, Category="MotorcycleWheel")
	float SpringDamp;

	UPROPERTY(EditDefaultsOnly, Category="MotorcycleWheel")
	float PoppedTireSpringLength;

	UPROPERTY(EditDefaultsOnly, Category="MotorcycleWheel")
	float PoppedTireSpringStiff;

	UPROPERTY(EditDefaultsOnly, Category="MotorcycleWheel")
	float PoppedTireSpringDamp;

	UPROPERTY(EditDefaultsOnly, Category="MotorcycleWheel")
	float PowerslideSpringStiff;

	UPROPERTY(EditDefaultsOnly, Category="MotorcycleWheel")
	float PowerslideSpringDamp;

	UPROPERTY(EditDefaultsOnly, Category="MotorcycleWheel")
	float WheelieSpringStiff;

	UPROPERTY(EditDefaultsOnly, Category="MotorcycleWheel")
	float WheelieSpringDamp;

	UPROPERTY(EditDefaultsOnly, Category="MotorcycleWheel")
	EFortMotorcycleWheelTraceMode WheelTraceMode;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UFortMotorcycleVehicleConfigs : public UFortPhysicsVehicleConfigs
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|Wheels")
	TArray<FMotorcycleWheel> Wheels;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|Wheels")
	float SpringInterpDamp;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|Wheels")
	float WheelieSpringInterpDamp;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|WallPush", meta=(EditCondition="bUseWallPushTracesForWalls == true"))
	float WallPushStiff;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|WallPush", meta=(EditCondition="bUseWallPushTracesForWalls == true"))
	float WallPushDamp;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|WallPush", meta=(EditCondition="bUseWallPushTracesForWalls == true"))
	FVector WallPushXTraceOffset;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|WallPush", meta=(EditCondition="bUseWallPushTracesForWalls == true"))
	float WallPushForwardTraceLengthScale;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|WallPush", meta=(EditCondition="bUseWallPushTracesForWalls == true"))
	float WallPushBackTraceLengthScale;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|WallPush", meta=(EditCondition="bUseWallPushTracesForWalls == true"))
	float WallPushRightTraceLength;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|WallPush", meta=(EditCondition="bUseWallPushTracesForWalls == true"))
	FVector WallPushRightTraceOffset;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|WallPush", meta=(EditCondition="bUseWallPushTracesForWalls == true && bUseWallPushRearSideTracesForWalls == true"))
	FVector WallPushRearRightTraceOffset;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|WallPush", meta=(EditCondition="bUseWallPushTracesForWalls == true"))
	float WallPushAngle;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|WallPush")
	bool bUseWallPushTracesForWalls;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|WallPush", meta=(EditCondition="bUseWallPushTracesForWalls == true"))
	bool bUseWallPushRearSideTracesForWalls;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|Jump")
	float MaxJumpChargeTime;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|Jump")
	float MinChargeJumpForce;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|Jump")
	float MaxChargeJumpForce;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|Jump")
	float MinJumpForwardAngle;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|Jump")
	float MaxJumpForwardAngle;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|Jump")
	FVector JumpForceMinCOMOffset;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|Jump")
	FVector JumpForceMaxCOMOffset;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|Jump")
	float JumpChargeGraceTimeSeconds;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|Jump")
	float JumpGraceTimeSeconds;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation")
	float LeanAngleScale;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation")
	float LeanStiff;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation")
	float LeanDamp;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation")
	float LeanStrength;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation")
	float SlideCatchupForceTime;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation")
	float SlideCatchupSpeed;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation")
	float SlideCatchupPushForce;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation")
	float AutoAirPitchAngle;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation")
	float MinSteeringAngleForModifiedFriction;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation")
	float MinSpeedForModifiedFriction;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation")
	float MinSteeringAngleToConsiderTractionLost;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation")
	float FrictionRatioToConsiderTractionLost;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|Wheelie")
	float WheeliePitchStiffMin;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|Wheelie")
	float WheeliePitchStiffMax;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|Wheelie")
	float WheeliePitchDampMin;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|Wheelie")
	float WheeliePitchDampMax;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|Wheelie")
	float WheeliePitchAngleMin;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|Wheelie")
	float WheeliePitchAngleMax;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|Wheelie")
	float StoppiePitchAngle;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|Wheelie")
	float StoppiePitchStiff;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|Wheelie")
	float StoppiePitchDamp;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|Wheelie", meta=(ClampMin="0.1"))
	float WheelieRampSeconds;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|Wheelie", meta=(ClampMin="0.1"))
	float WheelieFailPitchAngle;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|Wheelie")
	float WheelieRecoveryRate;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|Wheelie")
	float WheelieFailRecoveryRate;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|Wheelie")
	float WheelieMinStartSpeed;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|Wheelie")
	float StoppieMinStopSpeed;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|Wheelie")
	float WheelieSteerFactor;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|Wheelie")
	float StoppieSteerFactor;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|Wheelie")
	float WheelieSteerAlphaThreshold;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|Wheelie")
	float WheelieStoppieMaxLeanAllowedToInitiate;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|Wheelie")
	float WheelieGroundBufferTime;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|Wheelie")
	float StoppieGroundBufferTime;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|Wheelie")
	float WheelieSpringLengthExponent;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|Wheelie")
	float WheelieWheelOffsetLerpMultiplier;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|Wheelie")
	float WheelieBrakeFactor;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|Wheelie")
	float StoppieTurnInPlaceSpeed;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|Wheelie")
	float StoppieTurnInPlaceSpeedIce;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|Wheelie")
	float StoppieTurnInPlaceSpeedMud;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|Wheelie", meta=(ClampMin="0.100000"))
	float MinSpeedKmhForMaxStoppie;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|Wheelie")
	float StoppieTurnAngleExponent;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|Wheelie")
	float StoppieMaxTurnAngle;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|Wheelie")
	float WheelieTireTractionMultiplier_Min;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|Wheelie")
	float WheelieCameraMinStraightFactor;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation")
	float MaxLeanAccel;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|CruiseControl", meta=(ClampMax="1.000000", ClampMin="0.000000"))
	float CruiseControlForwardAlpha;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|CruiseControl")
	float InventoryModeSpeedKmh;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|CruiseControl")
	float CruiseControlDisengageSpeedKmh;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|PowerSlide")
	bool bPowerSlideIsSuperSlide;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|PowerSlide")
	float PowerSlideFrontFrictionMultiplier;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|PowerSlide")
	float PowerSlideRearFrictionMultiplier;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|PowerSlide")
	float PowerSlideRoadFrontFrictionMultiplier;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|PowerSlide")
	float PowerSlideRoadRearFrictionMultiplier;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|PowerSlide")
	float PowerSlideDirtFrontFrictionMultiplier;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|PowerSlide")
	float PowerSlideDirtRearFrictionMultiplier;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|PowerSlide")
	float PowerSlideGrassFrontFrictionMultiplier;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|PowerSlide")
	float PowerSlideGrassRearFrictionMultiplier;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|PowerSlide")
	float PowerSlideSnowFrontFrictionMultiplier;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|PowerSlide")
	float PowerSlideSnowRearFrictionMultiplier;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|PowerSlide")
	float PowerSlideIceFrontFrictionMultiplier;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|PowerSlide")
	float PowerSlideIceRearFrictionMultiplier;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|PowerSlide")
	float PowerSlideMudFrontFrictionMultiplier;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|PowerSlide")
	float PowerSlideMudRearFrictionMultiplier;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|PowerSlide", meta=(EditCondition="bPowerSlideIsSuperSlide == false"))
	float PowerSlideFactor;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|PowerSlide")
	float PowerSlideDampFactor;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|PowerSlide")
	float FrictionDampFactor;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|PowerSlide", meta=(EditCondition="bPowerSlideIsSuperSlide == false"))
	float PowerSlideLeanAngleScale;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|PowerSlide", meta=(EditCondition="bPowerSlideIsSuperSlide == true"))
	float SuperSlideLeanAngle;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|PowerSlide", meta=(EditCondition="bPowerSlideIsSuperSlide == true"))
	float SuperSlideMinStartYawSpeedDegrees;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|PowerSlide", meta=(EditCondition="bPowerSlideIsSuperSlide == true"))
	float SuperSlideMinStartSpeedKmh;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|PowerSlide", meta=(EditCondition="bPowerSlideIsSuperSlide == true"))
	float SuperSlideMaxEndSpeedKmh;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|PowerSlide")
	float PowerslideInputWindow;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|Steering")
	float ShootingMinSpeedSteeringAngle;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|Steering")
	float ShootingMaxSpeedSteeringAngle;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Camera")
	float InventoryModeCameraYawConstraint;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|Boost")
	float BoostTopSpeedMultiplier;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|Boost")
	float BoostPushForceMultiplier;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|Boost")
	float BoostMinPushForce;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation|Boost")
	float BoostSteeringMultiplier;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Animation")
	bool bPlayHolsterAnimsOnClient;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Animation")
	float FrontWheelSteeringFactor;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Animation")
	float FrontWheelRotationAcceleration;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Animation")
	float PassengerInventoryCooldown;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Animation")
	float DriverInventoryCooldown;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Simulation")
	TSet<FName> BoostAttackShapes;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Camera")
	float CameraAssistStrengthMax;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Camera")
	float CameraAssistStrengthMin;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Camera")
	float CameraAssistStrengthRecovery;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Camera")
	float CameraAssistInterpSpeed;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Tricks")
	float AirTrickIncrementInterval;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Tricks")
	float AirTrickFeedStartTime;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Tricks")
	float AirTrickPitchMultiplier;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Tricks")
	float AirTrickYawMultiplier;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Tricks")
	bool bAllowAirTrickNeutral;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Tricks")
	bool bAllowAirTrickRight;

	UPROPERTY(EditDefaultsOnly, Config, Category="Motorcycle|Tricks")
	bool bAllowAirTrickLeft;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Tires|Motorcycle")
	float PoppedTireTractionScalar_Front;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Tires|Motorcycle")
	float PoppedTireTractionScalar_Rear;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Tires|Motorcycle")
	float PoppedTireTractionScalar_Both;

protected:
	UPROPERTY(EditDefaultsOnly, Category="Motorcycle")
	FScalableFloat TopSpeedKmh;

};

