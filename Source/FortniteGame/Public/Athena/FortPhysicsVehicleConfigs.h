// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Athena/FortVehicleConfigs.h"
#include "FortVehicleTypes.h"
#include "FortPhysicsVehicleConfigs.generated.h"

class AActor;

UENUM()
enum class EPawnLaunchMinVelocityApply : uint8
{
	Add = 0,
	// Add min velocities for forward and vertical to the existing calculated velocities for launching a pawn

	Min = 1,
};

USTRUCT()
struct FFortPhysicsVehicleDamageOverrideConfigs
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Damage")
	FGameplayTag Tag;

	UPROPERTY(EditDefaultsOnly, Category="Damage")
	FScalableFloat MaxDamageOverride;

	UPROPERTY(EditDefaultsOnly, Category="Damage")
	FScalableFloat MinDamageOverride;

	UPROPERTY(EditDefaultsOnly, Category="Damage")
	FScalableFloat MinimumSpeed;

	UPROPERTY(EditDefaultsOnly, Category="Damage")
	FScalableFloat SpeedForMaximumDamage;

	UPROPERTY(EditDefaultsOnly, Category="Damage")
	FScalableFloat SpeedForMinimumDamage;

};

UCLASS(PerObjectConfig, MinimalAPI, BlueprintType, Blueprintable)
class UFortPhysicsVehicleConfigs : public UFortVehicleConfigs
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Movement")
	float WaterTestFrequency;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Movement")
	float TimeBetweenShallowWaterLevelUpdates;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Movement")
	float ShallowWaterVolumeSurfaceTraceLength;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Movement")
	float MinLinearSpeedRunningVarianceSq;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Movement")
	float MinAngularSpeedRunningVarianceSq;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Movement")
	float VehicleErrorPerDistanceCentimeters;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Movement")
	float VehicleErrorPerDistanceCentimetersPerSecond;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Movement")
	float VehicleErrorPerAngleDegrees;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Movement")
	float VehicleErrorPerAngleDegreesPerSecond;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Movement")
	float VehicleErrorPerUpdate;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Movement")
	float VehicleInvalidErrorPerSecondTolerance;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Movement")
	float VehicleInvalidErrorMaxSeconds;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Movement")
	float VehicleInvalidErrorMinSeconds;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics")
	float InPlaceRotationStrength;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Physics")
	float IdleBrakeForce;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Physics")
	float TooFastBrakeForce;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics")
	float BrakeForce;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics")
	float AutoBrakeSpeed;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Movement")
	float WaterDragCoefficient;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Movement")
	float WaterDragCoefficient2;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics")
	float LateralFriction;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Steering")
	float VehicleCameraMaxSteerAlpha;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Physics|Movement")
	float MaxForwardSpeedToSwapReverseControls;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Steering")
	float MinSpeedSteeringAngle;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Steering")
	float MaxSpeedSteeringAngle;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Steering")
	bool bSteerWithFrontWheels;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Steering")
	bool bInvertSteeringWhenReversing;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Steering")
	float InvertSteeringMinSpeedKmh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Config, Category="Vehicle|Physics|Steering")
	float SteerBrakeMultiplier;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Tires")
	float PoppedTireTractionMultiplier_StageOne;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Tires")
	float PoppedTireTractionMultiplier_StageTwo;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Tires")
	float PoppedTireTractionMultiplier_Min;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics")
	float MaxRestSpeed;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics")
	float ImpactDamageSafeDegrees;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Damage")
	bool bAlwaysDestroyPhysicsFellables;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Damage")
	float MinSpeedToDamage;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Damage")
	float MaxSpeedToDamage;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Damage")
	float MinSpeedDamage;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Damage")
	float MaxSpeedDamage;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Damage")
	float MinSpeedDamageNoPlayer;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Damage")
	float MaxSpeedDamageNoPlayer;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Damage")
	float MinSpeedAIDamage;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Damage")
	float MaxSpeedAIDamage;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Damage")
	float MinSpeedAIDamageNoPlayer;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Damage")
	float MaxSpeedAIDamageNoPlayer;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Damage")
	float MinSpeedBuildingDamage;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Damage")
	float MaxSpeedBuildingDamage;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Damage")
	float MinSpeedBuildingDamageNoPlayer;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Damage")
	float MaxSpeedBuildingDamageNoPlayer;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Damage")
	float VehicleOnVehicle_ImpactVelocityMultiplier;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Damage")
	float MinImpactMagnitudeToDealDamageKmH;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Damage")
	float MaxImpactDamage;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Damage")
	float ImpactDamagePerImpulse;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Damage")
	float ImpactReductionPerTransverseVelocity;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Damage")
	float MaxImpactDamageReduction;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Damage")
	float PlayerImpactDamageMultiplier;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Damage")
	float IgnorePawnForDamageTimeout;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Damage")
	TArray<FFortPhysicsVehicleDamageOverrideConfigs> DamageOverrideList;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Damage")
	float MinSpeedForRimScrapeDamage;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Damage")
	float RimScrapeDamageRate;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Physics|EnterAndExit")
	float VehicleFlipCooldown;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Movement")
	float MinSpringHitNormal;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Camera")
	float VehicleCameraGraceZone;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Steering")
	float VehicleLeftAnalogSteeringDeadZone;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Steering")
	float VehicleCameraLeftAnalogMultiplier;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Movement")
	float WaterTopSpeedMultiplier;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Movement")
	bool bUseWaterVolumeFluidFrictionForTopSpeedMultiplier;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Push Vehicle")
	float VehicleInPlaceThreshold;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Push Vehicle")
	float VehicleWeightShiftPitchStrength;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Push Vehicle")
	float VehicleWeightShiftRollStrength;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Push Vehicle")
	float VehicleWeightShiftYawStrength;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Push Vehicle")
	float JumpRateMultiplier;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Push Vehicle")
	float VehicleDebugStrafeMultiplier;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Push Vehicle")
	float GravityVelocitySteerForwardThreshold;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Push Vehicle")
	float GravityVelocitySteerErrorThreshold;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Push Vehicle")
	float GravitySteerMultiplier;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Push Vehicle")
	float InWaterPushMultiplier;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Push Vehicle")
	float MinWheelRotationSpeed;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Push Vehicle")
	float WheelRotationAcceleration;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Push Vehicle")
	float WheelRotationDampingPerSecond;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|LookAhead")
	float VehicleLookAheadLength;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|LookAhead")
	float VehicleLookAheadInAirLength;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|LookAhead")
	float VehicleLookAheadMinSpeed;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|LookAhead")
	bool bEnableLookahead;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|LookAhead")
	float VehicleLookAheadMinNormal;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|LookAhead")
	float VehicleLookAheadStiff;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|LookAhead")
	float VehicleLookAheadDamp;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|LookAhead")
	float VehicleLookAheadInAirStiff;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|LookAhead")
	float VehicleLookAheadInAirDamp;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|LookAhead")
	float VehicleLookAheadMaxAccel;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|LookAhead")
	float VehicleLookAheadMaxAccelInAir;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|AirControl")
	float VehicleAirControlStiff;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|AirControl")
	float VehicleAirControlDamp;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|AirControl")
	float VehicleAirYawStrength;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|AirControl")
	float VehicleAirPitchStrength;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics")
	float DragCoefficient;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics")
	float DragCoefficient2;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics")
	float MaxDragSpeed;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics")
	float MinLinearSpeedToWake;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics")
	float MinAngularSpeedToWake;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics")
	float MaxDriveInclineAngle;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics")
	float MaxAntigravityInclineAngle;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics")
	bool bAlwaysApplyAntiGravityInRightDir;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics")
	float MaxDriveTiltAngle;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Movement")
	float SpringStiffMultiplier;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Movement")
	float SpringDampMultiplier;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Movement")
	float SpringStiffMultiplierWater;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Movement")
	float SpringDampMultiplierWater;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Movement")
	float SpringMaxAccelMultiplier;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Movement")
	float SpringLengthMultiplier;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Movement")
	float HasGroundSweepLengthMultiplier;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Movement")
	float AngularDragCoefficient;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Movement")
	float PitchAngularDrag;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Movement")
	float RollAngularDrag;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Movement")
	float AngularDragCoefficientWater;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Movement")
	float PitchAngularDragWater;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Movement")
	float RollAngularDragWater;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Movement")
	float YawAngularDragWater;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Steering")
	float VehicleAnalogReverse;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|LookAhead")
	float VehicleLookAheadMinSpeedInAir;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|AirControl")
	float VehicleAutoAirPitchStrength;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|AirControl")
	float VehicleAutoAirYawStrength;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|AirControl")
	float VehicleAutoAirRollStrength;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|AirControl")
	float VehicleMinVelAlongContactNormal;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|AirControl")
	float VehicleMaxVelAlongContactNormal;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|AirControl")
	float MinSameDirCollision;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|AirControl")
	float MinCollisionSpeedToCorrect;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|AirControl")
	float MinCollisionBoostNormal;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|AirControl")
	float CollisionSpeedBoostAlpha;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|AirControl")
	float CancelIgnoreForwardThreshold;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Physics|Ramped Up Air Control")
	float AngularDragCoefficientRampedUp;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Physics|Ramped Up Air Control")
	float PitchAngularDragRampedUp;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Physics|Ramped Up Air Control")
	float VehicleAirYawStrengthRampedUp;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Physics|Ramped Up Air Control")
	float VehicleAirPitchStrengthRampedUp;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Physics")
	float WheelRadiusF;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Physics")
	float WheelRadiusB;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Vehicle|Physics")
	float PitchLeanStrength;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Vehicle|Physics")
	float MaxForwardVelAccelLean;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Vehicle|Physics")
	float MaxReverseVelAccelLean;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Vehicle|Physics")
	float MaxSteerForAccelLean;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Vehicle|Physics")
	float MinYawSpeedForLean;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Vehicle|Physics")
	float YawLeanStrength;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Vehicle|Physics")
	float AccelerationPitchCooldown;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Vehicle|Physics")
	float YawLeanCooldown;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Vehicle|Physics")
	float MaxAccelPitch;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Vehicle|Physics")
	float MaxYawLean;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Vehicle|Physics")
	float ContactModificationOffset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Vehicle|Physics")
	float VehicleFloorFriction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Vehicle|Physics")
	float VehicleSideScrapeFriction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Vehicle|Physics")
	float VehicleSideScrapeMaxCosAngle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Vehicle|Physics")
	float GroundCheckSweepRadius;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics")
	float GroundTraceLength;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Vehicle|Physics")
	float SMSleepCounter;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Vehicle|Physics")
	float CorrectOrientationTimeout;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Vehicle|Physics")
	float NudgeOrientationTimeout;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Vehicle|Physics")
	float NudgeDistance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Vehicle|Physics")
	FVector CorrectOrientationCenterOfMassOffset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Vehicle|Physics")
	float CorrectOrientationLinearCoefficient;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Vehicle|Physics")
	float CorrectOrientationAngularCoefficient;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Vehicle|Physics")
	TEnumAsByte<ECollisionChannel> SpringCollisionChannel;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Vehicle|Physics")
	FName SpringCollisionProfile;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics")
	bool bShouldLandscapeCheckUseCapsuleOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Vehicle|Physics")
	bool bShouldUseTerrainHandlingInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics")
	int32 NumWheelsOnSurfaceRequired;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Vehicle|Physics", meta=(EditCondition="bShouldUseTerrainHandlingInfo"))
	FRuntimeTerrainHandlingInfo RoadBehavior;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Vehicle|Physics", meta=(EditCondition="bShouldUseTerrainHandlingInfo"))
	FRuntimeTerrainHandlingInfo DirtBehavior;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Vehicle|Physics", meta=(EditCondition="bShouldUseTerrainHandlingInfo"))
	FRuntimeTerrainHandlingInfo GrassBehavior;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Vehicle|Physics", meta=(EditCondition="bShouldUseTerrainHandlingInfo"))
	FRuntimeTerrainHandlingInfo SnowBehavior;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Vehicle|Physics", meta=(EditCondition="bShouldUseTerrainHandlingInfo"))
	FRuntimeTerrainHandlingInfo IceBehavior;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Vehicle|Physics", meta=(EditCondition="bShouldUseTerrainHandlingInfo"))
	FRuntimeTerrainHandlingInfo MudBehavior;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle|Physics")
	bool bVehicleScreenSpaceSteering;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle|Physics")
	bool bVehicleCameraLeftAnalogSteering;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle|Physics")
	bool bUseKinematicReplicationWhenNotRendered;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle|Physics")
	bool bIsVehicleKinematic;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics|PawnCollision")
	float PawnLaunchVerticalVelocityScale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics|PawnCollision")
	float PawnLaunchForwardVelocityScale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics|PawnCollision")
	EPawnLaunchMinVelocityApply PawnLaunchMinVelocityApply;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics|PawnCollision")
	float PawnLaunchMinVerticalVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics|PawnCollision")
	float PawnLaunchMinForwardVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics|PawnCollision")
	float PawnLaunchMaxSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics|PawnCollision", meta=(ClampMax="10.0", ClampMin="0.0"))
	float PawnLaunchAngleAdjustment;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics|PawnCollision")
	float PawnLaunchMinDirection;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics|PawnCollision|Pushout")
	bool bPushoutPlayers;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics|PawnCollision|Pushout")
	bool bProbeShapeSetup;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics|PawnCollision|Pushout")
	float PushoutPlayersUsingMovementMaxDepth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics|PawnCollision|Pushout", meta=(ClampMax="1.0", ClampMin="0.0"))
	float PushoutPlayersUsingMovementMinStrength;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics|PawnCollision|Pushout", meta=(ClampMax="1.0", ClampMin="0.0"))
	float PushoutPlayersUsingMovementMaxStrength;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics|PawnCollision|Pushout", meta=(ClampMin="0.0"))
	float PushoutPlayersUsingUsingHardSnapMaxDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics|PawnCollision|Pushout", meta=(ClampMin="0.0"))
	float PushoutPlayersUsingUsingHardSnapMinDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics|DestructionCollision")
	float HitRequiredMinSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics|DestructionCollision")
	float MaxHealthToDestroyProp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics|DestructionCollision")
	float MaxHealthToDestroyPropFast;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics|DestructionCollision")
	float MaxHealthToDestroyPropSpeedThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics|DestructionCollision")
	float PropImpactImpulseMagnitude;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics|DestructionCollision")
	float RadiusForPropOverlapCheck;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics|DestructionCollision")
	float MaxMultiplierForVelocityOverlap;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics|DestructionCollision")
	float MinMultiplierForVelocityOverlap;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics|DestructionCollision")
	float PropOverlapMinMoveDistSquared;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics|DestructionCollision|ForceUseImminentCollision")
	bool bForceUseImminentCollision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics|DestructionCollision|ForceUseImminentCollision", meta=(EditCondition="bForceUseImminentCollision"))
	float DestructionTraceAheadMinSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics|DestructionCollision|ForceUseImminentCollision", meta=(EditCondition="bForceUseImminentCollision"))
	float DestructionTraceAheadAmount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics|DestructionCollision|ForceUseImminentCollision", meta=(EditCondition="bForceUseImminentCollision"))
	float PropDestructionImpulseAmount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics|DestructionCollision|ForceUseImminentCollision", meta=(EditCondition="bForceUseImminentCollision"))
	FVector DestructionTraceHalfSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics|DestructionCollision|ForceUseImminentCollision", meta=(EditCondition="bForceUseImminentCollision"))
	bool bCanDestroyProps;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics|DestructionCollision|ForceUseImminentCollision", meta=(EditCondition="bForceUseImminentCollision"))
	float ImminentHitRequiredMinSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics|DestructionCollision|ForceUseImminentCollision", meta=(EditCondition="bForceUseImminentCollision"))
	float MaxHealthToDestroyPropBoosting;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics|DestructionCollision|ForceUseImminentCollision", meta=(EditCondition="bForceUseImminentCollision"))
	bool bShouldUseLocalIgnoreListForDestroyedBuildings;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics")
	int32 MaxBudgetForActorTick;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics")
	int32 MinBudgetForReducedSpring;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics")
	bool bShouldServerRunReducedSprings;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics")
	int32 MaxReducedSpringsPerTick;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics|PawnAttach")
	bool bDontApplyDragInAir;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics")
	bool bDriverCanDamageVehicle;

	UPROPERTY(EditDefaultsOnly, Config, Transient, Category="Vehicle|Physics", meta=(EditCondition="bDriverCanDamageVehicle == false"))
	FGameplayTagQuery DriverCannotDamageVehicleExceptionQuery;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics")
	float MaxWheelSpinWound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics|Fuel")
	bool bUseRechargeableFuel;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Config, Category="Vehicle|Physics|Fuel")
	bool bCanReverseOnEmpty;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics|WaterInteraction")
	float BuoyancyCoefficient;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics|WaterInteraction")
	float BuoyancyDamp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics|WaterInteraction")
	float BuoyancyDamp2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics|WaterInteraction")
	float BuoyancyRampMinVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics|WaterInteraction")
	float BuoyancyRampMaxVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics|WaterInteraction")
	float BuoyancyRampMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics|WaterInteraction")
	float MaxBuoyantForce;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics|WaterInteraction")
	float UprightSpringWaterPitchStiff;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics|WaterInteraction")
	float UprightSpringWaterPitchDamp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics|WaterInteraction")
	float UprightSpringWaterRollStiff;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics|WaterInteraction")
	float UprightSpringWaterRollDamp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics|WaterInteraction")
	bool bModifyShocksInWater;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics|Movement")
	bool bApplyPushForceAtSocket;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics|WaterInteraction")
	float WaterVelocityStrength;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics|WaterInteraction")
	float MaxWaterForce;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics|WaterInteraction")
	int32 NumPontoonsForFullyInWater;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|WaterInteraction")
	float WaterIdleTimeForRiverPush;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|WaterInteraction")
	float WaterIdleTimeForSleep;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|WaterInteraction")
	int32 VelocityPontoonIndex;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|WaterInteraction")
	float WaterShorePushFactor;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|WaterInteraction")
	float YawAngularDragIdleMultiplier;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|WaterInteraction")
	float YawAngularDragWaterEmpty;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|WaterInteraction")
	float WaterBodyTraceTimer;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|WaterInteraction")
	float WaterBodyOverlapSphereRadius;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|WaterInteraction")
	float WaterBodyOverlapSphereCenterZOffset;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|WaterInteraction")
	bool bUseBoxBasedWaterOverlapChecks;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Physics|WaterInteraction")
	FVector WaterBoxSizeForOverlaps;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Physics|WaterInteraction")
	FVector WaterBoxOffsetForOverlaps;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|WaterInteraction")
	float WaterSubmergedDelay;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|WaterInteraction")
	float MaxWaterDepth;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|WaterInteraction")
	float WaterDestructionDelay;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|DestructionCollision")
	float ImminentCollisDestructionAngle;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|DestructionCollision")
	float ImminentCollisUpForwardMinProtected;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|DestructionCollision")
	float ImminentCollisUpNormalMinProtected;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|DestructionCollision")
	float DebasePlayerLaunchSpeed;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|DestructionCollision")
	bool bExplodeOnImpactAtCriticalHealth;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics")
	FScalableFloat MetalOnHit;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics")
	bool bOverrideErrorCorrection;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics")
	FRigidBodyErrorCorrection ErrorCorrectionOverride;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle|Physics")
	TSubclassOf<AActor> BoundsXYSplineClass;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics")
	FScalableFloat bEnableDormantOnSleep;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics|Collision")
	float MinVehicleDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics|Collision")
	float MaxVehicleDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics|Collision")
	float MinVehicleDamageSpeedKmh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics|Collision")
	float MaxVehicleDamageSpeedKmh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics|Collision")
	float MinVehicleDamageWhileBoosting;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics|Collision")
	float MaxVehicleDamageWhileBoosting;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics|Collision")
	float MinVehicleDamageSpeedWhileBoostingKmh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics|Collision")
	float MaxVehicleDamageSpeedWhileBoostingKmh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics")
	float MinBumpinessSpringHitTimeMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics")
	float MaxBumpinessSpringHitTimeMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics")
	float BumpinessExponentForShocks;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics")
	float DirtRoadFakeBumpinessMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Physics")
	bool bApplyGameplayImpulseAtCOM;

protected:
	UPROPERTY(EditDefaultsOnly, Category="Vehicle|Physics")
	bool bVehicleCameraSteering;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle|Physics", meta=(EditCondition="bVehicleCameraSteering"))
	bool bVehicleCameraSteeringForKBM;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle|Physics", meta=(EditCondition="bVehicleCameraSteering"))
	bool bVehicleCameraSteeringForGamepad;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle|Physics", meta=(EditCondition="bVehicleCameraSteering"))
	bool bVehicleCameraSteeringForTouch;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle|Physics", meta=(EditCondition="bVehicleCameraSteeringForGamepad"))
	bool bVehicleCameraBoostForGamepad;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Spawned Vehicle|Movement")
	bool bApplyPawnSpeedOnEntry;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Physics|Spawned Vehicle|Movement", meta=(EditCondition="bApplyPawnSpeedOnEntry"))
	float MaxAppliedPawnSpeedOnEntry;

};

