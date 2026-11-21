// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Athena/FortPhysicsVehicleConfigs.h"
#include "FortHoagieVehicleConfigs.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UFortHoagieVehicleConfigs : public UFortPhysicsVehicleConfigs
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float StrafeForce;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float StrafeForceMin;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float MaxStrafeSpeedKmh;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float StrafeTooFastBrakeForce;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float LandedBrakeForce;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float LiftForce;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float MaxLiftSpeedKmh;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float LiftTooFastBrakeForce;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float LateralDragCoefficient;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float LateralDragCoefficient2;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float LiftDragCoefficient;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float LiftDragCoefficient2;

	UPROPERTY(EditAnywhere, Config, Category="CameraYaw")
	float MaxPitchForCameraYaw;

	UPROPERTY(EditAnywhere, Config, Category="CameraYaw")
	float MaxCameraYawAngle;

	UPROPERTY(EditAnywhere, Config, Category="CameraYaw")
	float CameraYawStiff;

	UPROPERTY(EditAnywhere, Config, Category="CameraYaw")
	float CameraYawDamp;

	UPROPERTY(EditAnywhere, Config, Category="CameraYaw")
	float CameraYawStrength;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float UprightStiff;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float UprightDamp;

	UPROPERTY(EditAnywhere, Config, Category="Camera")
	bool bUseVehiclePivotForCameraPitch;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float ThrustTorqueAnglePercent;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float BoostThrustTorqueAnglePercent;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float ThrustTorqueStiff;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float ThrustTorqueDamp;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float ThrustTorqueMaxAccel;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float ThrustTorque;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float YawTorque;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float YawTorqueDampingSpeed;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float BoostForce;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float BoostMaxSpeedKmh;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float BoostDuration;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float BoostCooldown;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float BoostTorqueStiff;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float BoostTorqueDamp;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float AfterBoostBrakingForce;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float AfterBoostBrakingDuration;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float AfterBoostBrakingMinSpeed;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float PitchAngleRequiredForFullThrust;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float DistanceToGroundForLanding;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float StartupDelay;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float LandingSequenceDelay;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float RotorsRadius;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float RotorsRadiusInner;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float NoDriverBrakeForce;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float TimeBetweenRotorDamageTicks;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float AutoLandingForce;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float RotorDamageBoxSweepLength;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float CriticalStateLiftForce;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float IdleRotationMultiplier;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float LiftPitchDegrees;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float MinAltitudeForIdleNoise;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float DefaultLinearDamp;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float DefaultAngularDamp;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float LandingLinearDamp;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float LandingAngularDamp;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float LandingLiftAlpha;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float CriticalStateThrustMultiplier;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float BodyUpDotThresholdForLanding;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	int32 CriticalHealthThreshold;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float DamagePerImpulseWhileCritical;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float RotorImpulseLinear;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float RotorImpulseAngular;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float RotorImpulseCooldown;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float StartupLift;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float StartupLiftTime;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float MaxAltitude;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float AltitudeForSpinning;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float RotorMaxSpeed;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float RotorAccel;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float RotorDecel;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float ExplodeRotorDecel;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float MinRotorSpeedForSkippingStartup;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float RotorSpeedForStartupLift;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float CriticalLiftForceDecay;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float CriticalYawTorqueMin;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float CriticalYawTorqueMax;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float CriticalYawTorqueRampDuration;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float RotorTraceRotationSpeed;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float RotorTraceBoxSize;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float RotorTraceBoxHeight;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float MaxCriticalFallForce;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float BoostFOV;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float GentleCrashTimeToExplode;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float CriticalTimeForGentleCrash;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float AutoLandingYawTorque;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float MinHeightForAutoLandingYawTorque;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float MinSpeedForScrapingBottom;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float FallDamageHeightBuffer;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float TimeBetweenRotorPlayerDamage;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float RotorMoveSpeedRequiredToUpdateTraceDirSqr;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float FoliageTraceRate;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float RotorWashTicksPerFrame;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float CriticalHitRadius;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float AngleNormalUpForLockMovement;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float MaxAutoLandingTime;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float SpeedThresholdForCrashed;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float CritMultiplier;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float AltitudeForSprings;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float MaxCrashingTime;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float MaxCrashingScrapingTime;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float MaxCrashingTimeSpentNotMoving;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float LandscapeRotorImpulseMag;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float HealthThresholdForLandscapeRotorImpulse;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float MaxHeightBuffer;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	bool bImpulseOnOuterRotorHitLandscape;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	bool bSkipRotorImpulses;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	FVector FoliageTraceBoxSize;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	FVector WaterBoxSize;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	FVector WaterBoxOffset;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	FVector RotorOffsetFromActorLocationOnServer;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	bool bSkipContactRotations;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	FScalableFloat MaxAutoLandHeightWhenOutOfFuel;

};

