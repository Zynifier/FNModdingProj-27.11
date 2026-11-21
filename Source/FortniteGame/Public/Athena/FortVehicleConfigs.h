// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "UObject/NoExportTypes.h"
#include "FortVehicleTypes.h"
#include "FortVehicleConfigs.generated.h"

class ULegacyCameraShake;

USTRUCT(BlueprintType)
struct FVehicleDamageablePartConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VehicleDamageablePartConfig")
	FName ShapeName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VehicleDamageablePartConfig")
	FName BoneName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VehicleDamageablePartConfig")
	FGameplayTag PartTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VehicleDamageablePartConfig")
	FScalableFloat MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VehicleDamageablePartConfig")
	bool bStartsDisabled;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VehicleDamageablePartConfig")
	bool bConsideredCriticalHit;

};

USTRUCT(BlueprintType)
struct FVehicleWeaponReticle3DConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="VehicleWeaponReticle3DConfig")
	int32 SeatIndex;

	UPROPERTY(EditDefaultsOnly, Category="VehicleWeaponReticle3DConfig")
	float ReticleTraceDistance;

	UPROPERTY(EditDefaultsOnly, Category="VehicleWeaponReticle3DConfig")
	float OffsetCloserDistance;

	UPROPERTY(EditDefaultsOnly, Category="VehicleWeaponReticle3DConfig", meta=(ClampMax="1.000000", ClampMin="0.001000", UIMax="1.000000", UIMin="0.001000"))
	float SmoothingAlpha;

};

UCLASS(Config=Game, MinimalAPI, BlueprintType, Blueprintable)
class UFortVehicleConfigs : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Movement")
	int32 NumWheelsTouchingGroundForWheelsOnGround;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Movement")
	float TimeToIdleBrake;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Movement")
	float ChangeDirBrakeDelta;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Movement")
	float VehicleSleepCounter;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Movement")
	float GasPedalDownMinSpeed;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Movement")
	float AcceleratingSpeedThresholdMin;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Movement")
	float AcceleratingSpeedThresholdMax;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Camera")
	float VehicleMinFOV;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Camera")
	float VehicleMaxFOV;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Camera")
	float VehicleMinFOVSpeed;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Camera")
	float VehicleMaxFOVSpeed;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Camera")
	float VehicleFOVInterpSpeed;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Camera")
	float VehicleFOVPassengerInterpSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Vehicle|Camera")
	float CameraSpaceForwardDistanceOverride;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Camera")
	bool bStandingPlayerMatchesVehicleOrientation;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Camera")
	bool bPreventCameraBlockedByFriendlyPassenger;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Camera")
	bool bPreventCameraBlockedByEnemyPassenger;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle|Camera|Shake")
	TSubclassOf<ULegacyCameraShake> DriverCameraShakeClass;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Camera|Shake|Offroad")
	TSubclassOf<ULegacyCameraShake> OffroadCamShakeClass;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Camera|Shake|Offroad", meta=(DisplayName="Oscillation Amplitude Y"))
	float OffroadCameraShakeOscillationYAmplitude;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Camera|Shake|Offroad", meta=(DisplayName="Oscillation Amplitude Z"))
	float OffroadCameraShakeOscillationZAmplitude;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Camera|Shake|Offroad", meta=(DisplayName="Max Vehicle Speed"))
	float OffroadCameraShakeMaxVehicleSpeed;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Camera|Shake|Offroad", meta=(DisplayName="Oscillation Rotation Amplitude"))
	float OffroadCameraShakeOscillationRotationAmplitude;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Camera|Shake|Offroad", meta=(DisplayName="Oscillation Min Frequency"))
	float OffroadCameraShakeOscillationMinFrequency;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Camera|Shake|Offroad", meta=(DisplayName="Oscillation Max Frequency"))
	float OffroadCameraShakeOscillationMaxFrequency;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle|Camera|Shake|Accelerating")
	TSubclassOf<ULegacyCameraShake> AcceleratingCamShakeClass;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle|Camera|Shake|Accelerating")
	float AcceleratingMaxSpeedForCameraShakeIntensity;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle|Camera|Shake|Accelerating")
	float AcceleratingMaxCameraShakeIntensity;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle|Camera|Shake|Accelerating")
	float AcceleratingCameraShakeIntensityFalloff;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle|Force Feedback|Accelerating")
	float AcceleratingForceFeedbackDuration;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle|Force Feedback|Accelerating")
	bool bAcceleratingAffectsLeftLarge;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle|Force Feedback|Accelerating")
	bool bAcceleratingAffectsLeftSmall;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle|Force Feedback|Accelerating")
	bool bAcceleratingAffectsRightLarge;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle|Force Feedback|Accelerating")
	bool bAcceleratingAffectsRightSmall;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle|Force Feedback|Accelerating")
	float AcceleratingMaxSpeedForForceFeedbackIntensity;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle|Force Feedback|Accelerating")
	float AcceleratingMaxForceFeedbackIntensity;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle|Force Feedback|Accelerating")
	float AcceleratingForceFeedbackIntensityFalloff;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle|Interact")
	float InteractDistanceScalar;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Damage")
	float MinFallDamageHeight;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Damage")
	float MaxFallDamageHeight;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Damage")
	float MinFallDamage;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Damage")
	float MaxFallDamage;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Damage")
	float PlayerFallDamageMultiplier;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Damage")
	bool bDamageFriendlyVehicles;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Damage")
	bool bDamageOtherVehicles;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Damage")
	bool bDamageOwnVehicle;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Damage")
	bool bDamageAllowedFromOtherVehicle;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|EnterAndExit")
	float VehicleEjectCooldown;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|EnterAndExit")
	float PlayerToSocketSweepRadius;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Movement")
	float VehicleGravity;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Movement")
	float PlayerGravityMultiplier;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Steering")
	float PassengerDamageOnDestruction;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|Steering")
	float MinFallDamageNormalScale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Vehicle")
	float DriverExitLaunchScalar;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Vehicle")
	float DriverExitLaunchUpScalar;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Vehicle")
	float DriverExitInAirLaunchScalar;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Vehicle")
	float DriverExitInAirLaunchUpScalar;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Vehicle")
	float PassengerExitLaunchScalar;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Vehicle")
	float PassengerExitLaunchUpScalar;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Vehicle")
	float PassengerExitInAirLaunchScalar;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Vehicle")
	float PassengerExitInAirLaunchUpScalar;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle")
	bool bCanDoTricks;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle")
	bool bShouldDriverHaveReticle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle")
	bool bSupportsWraps;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle")
	float ExitVehicleCoolDown;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	bool bShouldProtectFromFireDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|PawnAttach")
	bool bInheritScale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|PawnAttach")
	float HoldToExitTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle")
	float ForceExitZOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle")
	bool bBlockBuilding;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle")
	bool bPreferDriverSeatWhenEmpty;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle")
	bool bCanUseSkeletalMeshSimulationUpdatesChildTransforms;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle")
	float FireDamagePerSecond;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle")
	float FireDamageTickRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle")
	bool bCanBeOnFire;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle")
	TArray<FVehicleDamageablePartConfig> DamageableParts;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle")
	TArray<FName> ToggleablePartNames;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle|HUD")
	TArray<FVehicleWeaponReticle3DConfig> WeaponDynamicReticleData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Lifetime")
	FScalableFloat UnoccupiedAutoDestroyTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|HUD")
	float HUDTopSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|HUD")
	FText PlayerFacingLocName;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float WheelRotationRange;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float VehicleFrontLowLateralFrictionMultiplier;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float VehicleRearLowLateralFrictionMultiplier;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float VehicleFrontHighLateralFrictionMultiplier;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float VehicleRearHighLateralFrictionMultiplier;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float LowToHighFrictionDuration;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float UphillIncline;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float ReverseToForwardFrontFriction;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float ReverseToForwardRearFriction;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float ReverseToForwardMaxSpeed;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Mods|Tires")
	TMap<FGameplayTag, FTireInfo> TireModDataMapping;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Horn")
	float HonkTimeMax;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Horn")
	float HonkCooldownMax;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle|Horn")
	float HonkTimePerHonk;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Destruction")
	float ServerExtraHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Destruction")
	float MaxTimeZeroHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Destruction")
	float MaxTimeExplosion;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Destruction")
	float SelfDestructTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Destruction")
	float MaxTimeSelfDestructCleanup;

	UPROPERTY(EditDefaultsOnly, Config, Transient, Category="Vehicle|Destruction")
	FGameplayTagQuery SkipDamageWhileCriticalHealthTagQuery;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Squad Restriction")
	FScalableFloat SquadRestrictionEnabled;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Squad Restriction")
	FText SquadRestrictionText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Team Restriction")
	FScalableFloat TeamRestrictionEnabled;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle|Team Restriction")
	FText TeamRestrictionText;

};

