// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/FortPhysicsVehicleConfigs.h"
#include "FortVehicleTypes.h"
#include "FortDagwoodVehicleConfigs.generated.h"

USTRUCT(BlueprintType)
struct VALETRUNTIME_API FRuntimeBoostInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RuntimeBoostInfo")
	uint8 bCanBoost : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RuntimeBoostInfo")
	uint8 bUsesRechargeableBoost : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RuntimeBoostInfo")
	float BoostPushForce;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RuntimeBoostInfo")
	float BoostTopSpeedForceMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RuntimeBoostInfo")
	float BoostTopSpeedMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RuntimeBoostInfo")
	float RechargeableBoostRateOfRegen;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RuntimeBoostInfo")
	float RechargeableBoostRateOfUse;

};

USTRUCT(BlueprintType)
struct VALETRUNTIME_API FRuntimeFuelInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RuntimeFuelInfo")
	float MaxFuel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RuntimeFuelInfo")
	float FuelPerSecondDriving;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RuntimeFuelInfo")
	float FuelPerSecondBoosting;

};

USTRUCT(BlueprintType)
struct VALETRUNTIME_API FRuntimeGearInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RuntimeGearInfo")
	int32 GearIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RuntimeGearInfo")
	float TopSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RuntimeGearInfo")
	float MinSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RuntimeGearInfo")
	float PushForce;

};

USTRUCT(BlueprintType)
struct VALETRUNTIME_API FDagwoodRuntimeModifiers
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Transient, Category="DagwoodRuntimeModifiers")
	FRuntimeBoostInfo BoostInfo;

	UPROPERTY(BlueprintReadWrite, Transient, Category="DagwoodRuntimeModifiers")
	FRuntimeFuelInfo FuelInfo;

	UPROPERTY(BlueprintReadWrite, Transient, Category="DagwoodRuntimeModifiers")
	FRuntimeSpringsInfo SpringsInfo;

	UPROPERTY(BlueprintReadWrite, Transient, Category="DagwoodRuntimeModifiers")
	bool bDamageFriendlyVehicles;

	UPROPERTY(BlueprintReadWrite, Transient, Category="DagwoodRuntimeModifiers")
	bool bDamageOtherVehicles;

	UPROPERTY(BlueprintReadWrite, Transient, Category="DagwoodRuntimeModifiers")
	bool bDamageOwnVehicle;

	UPROPERTY(BlueprintReadWrite, Transient, Category="DagwoodRuntimeModifiers")
	bool bDamageAllowedFromOtherVehicle;

	UPROPERTY(BlueprintReadWrite, Transient, Category="DagwoodRuntimeModifiers")
	float GravityMultiplier;

	UPROPERTY(BlueprintReadWrite, Transient, Category="DagwoodRuntimeModifiers")
	float MaxInclineAngle;

	UPROPERTY(BlueprintReadWrite, Transient, Category="DagwoodRuntimeModifiers")
	float MaxTiltAngle;

	UPROPERTY(BlueprintReadWrite, Transient, Category="DagwoodRuntimeModifiers")
	TArray<FRuntimeGearInfo> GearInfos;

	UPROPERTY(BlueprintReadWrite, Transient, Category="DagwoodRuntimeModifiers")
	FGameplayTag TireModTag;

	UPROPERTY(BlueprintReadOnly, Transient, Category="DagwoodRuntimeModifiers")
	uint8 TireModVersion;

	UPROPERTY(BlueprintReadOnly, Transient, Category="DagwoodRuntimeModifiers")
	bool bTireModAdjustsPosition;

	UPROPERTY(Transient)
	uint8 DataVersion;

};

USTRUCT(BlueprintType)
struct VALETRUNTIME_API FTireSimulationRuntimeData
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	FRuntimeTerrainHandlingInfo HandlingInfo;

	UPROPERTY(BlueprintReadWrite, Transient, Category="TireSimulationRuntimeData")
	float PoppedTireSpringLength;

	UPROPERTY(BlueprintReadWrite, Transient, Category="TireSimulationRuntimeData")
	float PoppedTireSpringStiff;

	UPROPERTY(BlueprintReadWrite, Transient, Category="TireSimulationRuntimeData")
	float PoppedTireSpringDamp;

};

UCLASS(BlueprintType, Blueprintable)
class UFortDagwoodVehicleConfigs : public UFortPhysicsVehicleConfigs
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Dagwood")
	float BoostMinPushForce;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Dagwood")
	float BoostTopSpeedForceMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Dagwood")
	float BoostTopSpeedMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Dagwood")
	float BoostWaterMultiplier;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Dagwood")
	float VehiclePowerSlideFrontMultiplier;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Dagwood")
	float VehiclePowerSlideRearMultiplier;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Dagwood")
	float IceVehiclePowerSlideFrontMultiplier;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Dagwood")
	float IceVehiclePowerSlideRearMultiplier;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Dagwood")
	float MudVehiclePowerSlideFrontMultiplier;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Dagwood")
	float MudVehiclePowerSlideRearMultiplier;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Dagwood")
	bool bUseAccelerationLean;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Dagwood")
	float HandbrakeGripAngle;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Dagwood")
	float HandbrakeGripAngleRecovery;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Dagwood")
	float HandbrakeSpeedForGripLoss;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Dagwood")
	float MinSlipDuration;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Dagwood")
	float HandbrakeLateralFriction;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Dagwood")
	float HandbrakeSteeringMultiplier;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Dagwood")
	float HandbrakeFrictionDampFactor;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Dagwood")
	float RestoreTractionDampFactor;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Dagwood")
	float HandbrakeForce;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Dagwood")
	float HandbrakeForceNoAccel;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Dagwood")
	bool bUseHandbrakeToDrift;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Dagwood", meta=(EditCondition="bUseHandbrakeToDrift"))
	float DriftMinSpeedSteeringAngle;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Dagwood", meta=(EditCondition="bUseHandbrakeToDrift"))
	float DriftMaxSpeedSteeringAngle;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Dagwood", meta=(EditCondition="bUseHandbrakeToDrift"))
	float DriftFrontLateralFrictionMultiplier;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Dagwood", meta=(EditCondition="bUseHandbrakeToDrift"))
	float DriftRearLateralFrictionMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Dagwood")
	float BoostSteeringMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Dagwood")
	float DirtRoadTopSpeedMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Dagwood")
	float DirtRoadFrontLateralFriction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Dagwood")
	float DirtRoadRearLateralFriction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Dagwood")
	float DirtRoadAccelForceMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Dagwood")
	float OffRoadTopSpeedMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Dagwood")
	float OffRoadFrontLateralFriction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Dagwood")
	float OffRoadRearLateralFriction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Dagwood")
	float OffRoadPushForceMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Dagwood")
	float OffroadDamageImpactForceMin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Dagwood")
	float OffroadDamageImpactForceMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Dagwood")
	float OffroadImpactDamageMin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Dagwood")
	float OffroadImpactDamageMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Dagwood")
	float MinSpeedForOffroadHandling;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Dagwood")
	float SnowFrontLateralFriction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Dagwood")
	float SnowRearLateralFriction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Dagwood")
	float IceFrontLateralFriction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Dagwood")
	float IceRearLateralFriction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Dagwood")
	float MudFrontLateralFriction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Dagwood")
	float MudRearLateralFriction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Dagwood")
	float IcePushForceMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Dagwood")
	float IceBrakeForceMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Dagwood|Damage")
	float FireHealthPercentThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Dagwood")
	float OffroadRumbleIntensity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Dagwood")
	float DirtRoadRumbleIntensity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Dagwood")
	float OffroadDamageScaleExponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Dagwood")
	float HardLandingThresholdMin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Dagwood")
	float HardLandingThresholdMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Dagwood")
	float HardLandingShakeZAmplitudeMin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Dagwood")
	float HardLandingShakeZAmplitudeMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Dagwood")
	float SpeedLinesThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Dagwood")
	float PropDestructionImpulse;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Dagwood|Collision|Destruction")
	float DestructionAngle;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Dagwood|Collision|Destruction")
	float UpNormalMinProtected;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Dagwood|Collision|Destruction")
	float UpForwardMinProtected;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Dagwood")
	float NonCameraSteeringAngleMultiplier;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Dagwood")
	float CameraAssistStrengthMax;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Dagwood")
	float CameraAssistStrengthMin;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Dagwood")
	float CameraAssistStrengthRecovery;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Dagwood")
	float CameraAssistInterpSpeed;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Dagwood")
	float ReverseChangeDirectionBrakeForceMultiplier;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Dagwood")
	float ReverseChangeDirectionSpeedThreshold;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Dagwood")
	float DriftExitPushForce;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Dagwood")
	float DriftExitCatchupSpeed;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Dagwood")
	float HandbrakeDurationRequiredForCatchup;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Dagwood")
	float ImpactMagnitudeToEndCatchup;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Dagwood")
	float PoppedTireSpringLength;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Dagwood")
	float PoppedTireSpringStiff;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Dagwood")
	float PoppedTireSpringDamp;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Dagwood")
	float PoppedTireScrapeFrictionMultiplier;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Dagwood")
	float RimScrapeFlipRollMagnitude;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Dagwood")
	float RimScrapeFlipPitchMagnitude;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Dagwood")
	float SpeedForRimFlip;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Dagwood")
	float HealthPercentForFlip;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Dagwood")
	float FlipYawDuration;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Dagwood")
	float FlipRollDuration;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Dagwood")
	float FlipPitchDuration;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Dagwood")
	float FlipExplodeDuration_Yaw;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Dagwood")
	float FlipExplodeDuration_Pitch;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Dagwood")
	float FlipPushForceDuration_Yaw;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Dagwood")
	float FlipPushForceDuration_Pitch;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Dagwood")
	float FlipPushForcMultiplier;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Dagwood")
	float FlipPushForce_UpComponentPitch;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Dagwood")
	float FlipPushForce_UpComponentRoll;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Dagwood")
	float MinTimeInAirRequiredForExplodeLanding;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Dagwood")
	float FlipYawSpringStiff;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Dagwood")
	float FlipYawSpringDamp;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Dagwood")
	float FlipYawSpringMaxAccel;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Dagwood")
	float HealthPercentForExplode;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Dagwood")
	float FlipRecoveryTime;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Dagwood")
	float FlipMaxDuration;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Dagwood")
	float FlipWiggleDuration;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Dagwood")
	float PoppedTireVeerDuration;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Dagwood")
	float PoppedTireVeerSteeringAngle;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Dagwood")
	float FlipWiggleFrequency;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Dagwood")
	float FlipWiggleSteeringAngle;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Dagwood")
	float FlipYawAngleThreshold;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Dagwood")
	bool bUsesBoost;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Dagwood", meta=(EditCondition="bUsesBoost"))
	float RechargeableBoostRateOfUse;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Dagwood", meta=(EditCondition="bUsesBoost"))
	float RechargeableBoostRateOfRegen;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Dagwood", meta=(EditCondition="bUsesBoost"))
	float BoostRateOfRegenMinMultiplier;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Dagwood", meta=(EditCondition="bUsesBoost"))
	float BoostRateOfRegenMaxMultiplier;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Dagwood", meta=(EditCondition="bUsesBoost"))
	float BoostRegenMaxMultiplyTime;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Dagwood", meta=(EditCondition="bUsesBoost"))
	float RechargeableBoostRequiredPercentToActivate;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Dagwood", meta=(EditCondition="bUsesBoost"))
	float RechargeableBoostMaxPercent;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Dagwood", meta=(EditCondition="bUsesBoost"))
	float RechargeableBoostMinPercent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Dagwood|Damage")
	float AnalogDriftStickThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Dagwood|Inoperable")
	FName TireBootRightSocketName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Dagwood|Inoperable")
	FName TireBootLeftSocketName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Dagwood|Inoperable")
	float TireBootRelativeDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Dagwood|Boost")
	float BoostForceInAir;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Dagwood|Boost")
	float BoostAirMaxSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Dagwood|Tires")
	TArray<FName> TireSocketNames;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Dagwood|Tires")
	TArray<FName> TireBoneNames;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Dagwood|Tires")
	TArray<int32> RearTireIndices;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Dagwood|Tires")
	TArray<int32> RightSideTires;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Dagwood|Tires")
	TArray<int32> FakeTireIndices;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Dagwood|Boost")
	bool bNoWheels;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Dagwood|Boost")
	float NoWheelsSpringLenMult;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Dagwood|Tires")
	TArray<FName> NoWheelsBonesToHide;

};

