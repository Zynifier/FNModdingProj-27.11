// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Athena/FortPhysicsVehicleConfigs.h"
#include "Athena/Vehicle/FortVehicleAsync.h"
#include "FortNevadaVehicleConfigs.generated.h"

class UFortNevadaVehicleConfigs;

UENUM(BlueprintType)
enum class ENevadaFlightStates : uint8
{
	FLIGHT = 0,
	CRASHING = 1,
	CRASHED = 2,
	REBOOTING = 3,
	LANDING = 4,
	LANDED = 5,
	IDLE = 6,
	NONE = 7,
};

USTRUCT(BlueprintType)
struct FDampedSpringConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DampedSpringConfig")
	float Stiffness;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DampedSpringConfig")
	float Damping;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DampedSpringConfig")
	float MaxAccel;

};

USTRUCT()
struct FNevadaInPersistent : public FFortVehicleInPersistent
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UFortNevadaVehicleConfigs> FortNevadaVehicleConfigs;

	UPROPERTY()
	bool bBoostThrust;

	UPROPERTY()
	bool bBoostDrag;

	UPROPERTY()
	float TractorBeamExtraLengthForExtents;

	UPROPERTY()
	bool bUseTractorBeamUprightForce;

	UPROPERTY()
	FVector CrashingDesiredUp;

	UPROPERTY()
	ENevadaFlightStates CurrentVehicleState;

};

USTRUCT(BlueprintType)
struct FNevadaMoveModeConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="NevadaMoveModeConfig")
	float ThrustForce;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="NevadaMoveModeConfig")
	float LiftForce;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="NevadaMoveModeConfig")
	float MaxHorizontalSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="NevadaMoveModeConfig")
	float MaxVerticalSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="NevadaMoveModeConfig")
	float DragForceMultiplier;

};

USTRUCT()
struct FNevadaOutContinuous : public FFortVehicleOutContinuous
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	float AltimeterTraceHitDistance;

	UPROPERTY(Transient)
	float TractorBeamAppliedForceMagnitude;

};

USTRUCT()
struct FNevadaOutPersistent : public FFortVehicleOutPersistent
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct NEVADARUNTIME_API FNevadaState
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Transient, Category="NevadaState")
	ENevadaFlightStates CurrentStatus;

	UPROPERTY(BlueprintReadWrite, Transient, Category="NevadaState")
	int32 LivesRemaining;

	UPROPERTY(BlueprintReadWrite, Transient, Category="NevadaState")
	bool bHijackingActive;

	UPROPERTY(BlueprintReadWrite, Transient, Category="NevadaState")
	bool bPilotBubbleCollisionEnabled;

	UPROPERTY(BlueprintReadWrite, Transient, Category="NevadaState")
	float CurrentBatteryCharge;

	UPROPERTY(BlueprintReadOnly, Transient, Category="NevadaState")
	bool bCannonEnabled;

	UPROPERTY(BlueprintReadOnly, Transient, Category="NevadaState")
	bool bTractorBeamEnabled;

};

UCLASS()
class NEVADARUNTIME_API UFortNevadaVehicleConfigs : public UFortPhysicsVehicleConfigs
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="NevadaMovement")
	FNevadaMoveModeConfig BaseMovement;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Boost")
	FNevadaMoveModeConfig BoostMovement;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="TractorBeam")
	FNevadaMoveModeConfig ChargingMovement;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Rotation")
	FDampedSpringConfig UprightSpringForce;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="NevadaMovement")
	float DebaseLaunchspeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="NevadaMovement")
	float MaxHeight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="NevadaMovement")
	float MinHeight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="NevadaMovement")
	float OnEnterPitchAlpha;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Falling")
	float FallDamageHeightBuffer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Rotation")
	float TurningForce;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Rotation")
	float ThrustRotationAlpha;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Rotation")
	float PitchDrag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Rotation")
	float YawDrag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Rotation")
	float RollDrag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Boost")
	float BoostThrustDuration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Boost")
	float BoostDragDuration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Boost")
	int32 NumBoostCharges;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Boost")
	float BoostChargeDuration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Boost")
	float BoostChargeDelay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Boost")
	float BoostDragFinishSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="TractorBeam")
	float TractorBeamRadius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="TractorBeam")
	float TractorBeamWithTargetRadius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="TractorBeam")
	FScalableFloat TractorBeamSweepLength;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="TractorBeam")
	FScalableFloat TractorBeamChargeTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="TractorBeam")
	FScalableFloat TractorBeamDurationTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="TractorBeam")
	FScalableFloat TractorBeamTossImpulseStrengthForward;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="TractorBeam")
	FScalableFloat TractorBeamTossImpulseStrengthUpward;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="TractorBeam")
	float TractorBeamShutdownTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="TractorBeam")
	FScalableFloat TractorBeamTurnOffDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="TractorBeam")
	FScalableFloat AllowTractorBeamAIPawns;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="TractorBeam")
	float TractorBeamBreakForceMagnitude;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="TractorBeam")
	FScalableFloat TractorBeamActive;

	UPROPERTY(EditAnywhere, Config, Category="TractorBeam")
	FScalableFloat TractorBeamCooldown;

	UPROPERTY(EditAnywhere, Config, Category="TractorBeam")
	FScalableFloat TractorBeamDisruptionCooldown;

	UPROPERTY(EditAnywhere, Config, Category="TractorBeam")
	FName TractorBeamSocket;

	UPROPERTY(EditAnywhere, Config, Category="TractorBeam")
	FVector TractorBeamAttachPositionOffset;

	UPROPERTY(EditAnywhere, Config, Category="TractorBeam")
	FRigidBodyErrorCorrection TractorBeamTargetOverridenErrorCorrection;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Rotation")
	float VictimPitchDrag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Rotation")
	float VictimYawDrag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Rotation")
	float VictimRollDrag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="TractorBeam")
	FDampedSpringConfig TractorBeamVictimUprightForce;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="CrashReboot")
	int32 NumReboots;

	UPROPERTY(Config)
	int32 NumRebootsDefault;

	UPROPERTY(EditAnywhere, Config, Category="CrashReboot")
	float MaxCrashingTime;

	UPROPERTY(EditAnywhere, Config, Category="CrashReboot")
	float MaxCrashingScrapingTime;

	UPROPERTY(EditAnywhere, Config, Category="CrashReboot")
	float MaxCrashingTimeSpentNotMoving;

	UPROPERTY(EditAnywhere, Config, Category="CrashReboot")
	float SpeedThresholdForCrashed;

	UPROPERTY(EditAnywhere, Config, Category="CrashReboot")
	FScalableFloat RebootDuration;

	UPROPERTY(EditAnywhere, Config, Category="CrashReboot")
	FScalableFloat RebootDelay;

	UPROPERTY(EditAnywhere, Config, Category="Landing")
	float LandingTraceRange;

	UPROPERTY(EditAnywhere, Config, Category="Landing")
	float DesiredLandingDistance;

	UPROPERTY(EditAnywhere, Config, Category="Landing")
	float LandingDelay_Max;

	UPROPERTY(EditAnywhere, Config, Category="Landing")
	float LandingDelay_Min;

	UPROPERTY(EditAnywhere, Config, Category="Landing")
	float HeightForMinLandingDelay;

	UPROPERTY(EditAnywhere, Config, Category="Landing")
	float HeightForMaxLandingDelay;

	UPROPERTY(EditAnywhere, Config, Category="Landing")
	float LandingPitchAlphaMax;

	UPROPERTY(EditAnywhere, Config, Category="Landing")
	float LandingPitchAlphaMin;

	UPROPERTY(EditAnywhere, Config, Category="Animation")
	float DriverSeatRotationAnimBlendSpeed;

	UPROPERTY(EditAnywhere, Config, Category="Animation")
	float CrashingDesiredUpLerpFactor;

	UPROPERTY(EditAnywhere, Config, Category="CrashReboot")
	float CrashedLinearDrag;

	UPROPERTY(EditAnywhere, Config, Category="Landing")
	float LandedDragCoef;

	UPROPERTY(EditAnywhere, Config, Category="Landing")
	float LandedDragCoef2;

	UPROPERTY(EditAnywhere, Config, Category="Landing")
	float LandedMaxDragSpeed;

	UPROPERTY(EditAnywhere, Config, Category="CrashReboot")
	float CrashedAngularDragMultiplier;

	UPROPERTY(EditAnywhere, Config, Category="Boost")
	float BoostFOV;

	UPROPERTY(EditAnywhere, Config, Category="Boost")
	float ExtraTraceInteractRange;

	UPROPERTY(EditAnywhere, Config, Category="Gravity")
	float AntiGravityMult;

	UPROPERTY(EditAnywhere, Config, Category="InitialLift")
	float InitialLiftDuration;

	UPROPERTY(EditAnywhere, Config, Category="Battery")
	FScalableFloat BatteryCostDuringFlight;

	UPROPERTY(EditAnywhere, Config, Category="Battery")
	FScalableFloat BatteryRegenDelay;

	UPROPERTY(EditAnywhere, Config, Category="Battery")
	FScalableFloat BatteryRegenTickRate;

	UPROPERTY(EditAnywhere, Config, Category="Battery")
	FScalableFloat BatteryRegenAmount;

	UPROPERTY(EditAnywhere, Config, Category="Battery")
	FScalableFloat MaxBattery;

	UPROPERTY(EditAnywhere, Config, Category="Battery")
	FScalableFloat MinBatteryForFlight;

	UPROPERTY(EditAnywhere, Config, Category="NevadaMisc")
	TArray<FName> CockpitShapeNames;

	UPROPERTY(EditAnywhere, Config, Category="Battery")
	FScalableFloat CockpitDamageMult;

	UPROPERTY(EditAnywhere, Config, Category="Battery")
	FScalableFloat CockpitHealth;

};

