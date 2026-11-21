// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Weapons/Data/FortWeaponItemDefinition.h"
#include "FortWeaponRangedItemDefinition.generated.h"

class AActor;
class AFortProjectileBase;
class UCurveFloat;
class UParticleSystem;
class USoundLibrary;

USTRUCT(BlueprintType)
struct FFortBulletPatternEntryData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortBulletPatternEntryData")
	FName SocketName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortBulletPatternEntryData")
	FRotator RelativeRotation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortBulletPatternEntryData")
	FRotator MinRotationVariance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortBulletPatternEntryData")
	FRotator MaxRotationVariance;

};

USTRUCT(BlueprintType)
struct FFortRangedWeaponRecoil
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	int32 BulletNum;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	float MinVertical;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	float MaxVertical;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	float MinHorizontal;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	float MaxHorizontal;

};

USTRUCT(BlueprintType)
struct FFortRangedWeaponSpread
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	float BulletNum;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	float Spread;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	float RecoveryTime;

};

USTRUCT(BlueprintType)
struct FFortRangedWeaponStats : public FFortBaseWeaponStats
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	TArray<FFortRangedWeaponRecoil> PerBulletRecoil;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	TArray<FFortRangedWeaponRecoil> ScopedPerBulletRecoilOverride;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	TArray<FFortRangedWeaponSpread> PerBulletSpread;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	TArray<FFortBulletPatternEntryData> OverrideBulletPattern;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float Spread;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float OverrideBaseSpread;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float SpreadDownsights;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float OverrideSpreadDownsights;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float StandingStillSpreadMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float AthenaCrouchingSpreadMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float AthenaSlidingSpreadMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float AthenaJumpingFallingSpreadMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float AthenaSprintingSpreadMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float MinSpeedForSpreadMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float MaxSpeedForSpreadMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float SpreadDownsightsAdditionalCooldownTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float SpreadExponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float HeatX1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float HeatY1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float HeatX2;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float HeatY2;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float HeatX3;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float HeatY3;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float HeatXScale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float HeatYScale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float CoolX1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float CoolY1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float CoolX2;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float CoolY2;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float CoolX3;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float CoolY3;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float CoolXScale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float CoolYScale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float PerfectAimCooldown;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	int32 BulletsPerCartridge;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	int32 MinHitsPerCartridge;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float FiringRate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float ROFScale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float BurstFiringRate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float FiringRateDownsightsMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float AutofireRange;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float AutofireAcquisitionDelay;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float AutofireDBNOAcquisitionDelay;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float AutofireAcquisitionRechargeTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float AutofireReleaseTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float AutofireCooldown;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float RecoilVert;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float RecoilVertScale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float RecoilVertScaleGamepad;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float VertRecoilDownChance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float RecoilHoriz;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float RecoilHorizScale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float RecoilHorizScaleGamepad;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float RecoilInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float RecoilRecoveryInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float RecoilRecoveryDelay;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float RecoilRecoveryFraction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float RecoilDownsightsMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float AthenaRecoilMagnitudeMin;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float AthenaRecoilMagnitudeMax;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float AthenaRecoilMagnitudeScale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float AthenaRecoilAngleMin;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float AthenaRecoilAngleMax;

	UPROPERTY(EditAnywhere, Category="FortWeaponRangedStats")
	float AthenaRecoilRollMagnitudeMin;

	UPROPERTY(EditAnywhere, Category="FortWeaponRangedStats")
	float AthenaRecoilRollMagnitudeMax;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float AthenaRecoilInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float AthenaRecoilRecoveryInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float AthenaRecoilDownsightsMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float AthenaRecoilHipFireMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float PitchLimitForPerBulletRecoil;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	bool bPerBulletRecoilRecoveryWhileFiring;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float AthenaAimAssistRange;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float ADSTransitionInTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float ADSTransitionOutTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	int32 MaxSpareAmmo;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	int32 BulletsPerTracer;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float AIDelayBeforeFiringMin;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float AIDelayBeforeFiringMax;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float AIFireDurationMin;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float AIFireDurationMax;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float AIMinSpreadDuration;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float AIMaxSpreadDuration;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float AIDurationSpreadMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float AIAdditionalSpreadForTargetMovingLaterally;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float AIAthenaHearFiringNoiseRange;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float EQSDensity;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float MinApproachRange;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float MinActualRange;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float MinPreferredRange;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float MinPreferredRangeEQS;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float MaxPreferredRangeEQS;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float MaxPreferredRange;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float MaxActualRange;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float MaxApproachRange;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float RangeToAutomaticallyAddEnemyPawnGoals;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float SweepRadius;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float AutoReloadDelayOverride;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float OverheatingMaxValue;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float OverheatHeatingValue;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float FullChargeOverheatHeatingValue;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float OverheatingCoolingValue;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float FullyOverheatedCoolingValue;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float HeatingCooldownDelay;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float OverheatedCooldownDelay;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	bool bCoolOverheatWhileCharging;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float FortHomingTurnSpeedMin;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float FortHomingTurnSpeedMax;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float FortHomingTimeUntilMaxTurnSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float ProjectileVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	int32 BulletsPerBulletFireFX;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponRangedStats")
	float MaxDamagePerCartridge;

};

UCLASS(MinimalAPI, BlueprintType)
class UFortWeaponRangedItemDefinition : public UFortWeaponItemDefinition
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="RangedItemDefinition")
	bool DoNotAllowDoublePump() const;

	UFUNCTION(BlueprintPure, Category="RangedItemDefinition")
	bool ForceProjectileTooltip() const;

	UFUNCTION(BlueprintPure, Category="RangedItemDefinition")
	UParticleSystem* GetBulletShellFXTemplate() const;

	UFUNCTION(BlueprintPure, Category="RangedItemDefinition")
	TSubclassOf<AFortProjectileBase> GetProjectileTemplate() const;

	UFUNCTION(BlueprintPure, Category="RangedItemDefinition")
	bool HasLightweightProjectile() const;

	UFUNCTION(BlueprintPure, Category="RangedItemDefinition")
	bool HasPhysicsObjectProjectile() const;

	UFUNCTION(BlueprintPure, Category="RangedItemDefinition")
	bool IsProjectileWeapon() const;

	UFUNCTION(BlueprintPure, Category="RangedItemDefinition")
	bool ShouldShowReticleHitNotifyAtImpactLocation() const;

	UFUNCTION(BlueprintPure, Category="RangedItemDefinition")
	bool ShouldSpawnBulletShellFX() const;

	UFUNCTION(BlueprintPure, Category="RangedItemDefinition")
	bool ShouldTraceThroughPawns() const;

	UFUNCTION(BlueprintPure, Category="RangedItemDefintion")
	bool ShouldTraceThroughWorld() const;

	UFUNCTION(BlueprintPure, Category="RangedItemDefinition")
	bool ShouldUseNativeWeaponTrace() const;

	UFUNCTION(BlueprintPure, Category="RangedItemDefinition")
	bool ShouldUsePerfectAimWhenTargetingMinSpread() const;

	UFUNCTION(BlueprintPure, Category="RangedItemDefinition")
	bool UseOnTouch() const;

	UPROPERTY(EditDefaultsOnly, Category="SoundLibrary")
	TArray<TObjectPtr<USoundLibrary>> ProjectileSoundLibraries;

private:
	UPROPERTY(EditAnywhere, Category="Ammo", meta=(AssetBundles="Equipped,ItemsInInventoryInZone,ClientAthenaPreload"))
	TSoftClassPtr<AActor> ProjectileTemplate;

	UPROPERTY(EditDefaultsOnly, Category="WeaponData", meta=(AssetBundles="Equipped,ItemsInInventoryInZone"))
	TSoftObjectPtr<UParticleSystem> BulletShellFXTemplate;

	UPROPERTY(EditAnywhere, Category="Firing")
	uint8 bUseNativeWeaponTrace : 1;

	UPROPERTY(EditAnywhere, Category="Firing")
	uint8 bTraceThroughPawns : 1;

	UPROPERTY(EditAnywhere, Category="Firing")
	uint8 bTraceThroughWorld : 1;

	UPROPERTY(EditDefaultsOnly, Category="WeaponData")
	uint8 bShouldSpawnBulletShellFX : 1;

	UPROPERTY(EditDefaultsOnly, Category="WeaponData")
	uint8 bShouldUsePerfectAimWhenTargetingMinSpread : 1;

	UPROPERTY(EditDefaultsOnly, Category="WeaponData")
	uint8 bDoNotAllowDoublePump : 1;

	UPROPERTY(EditDefaultsOnly, Category="WeaponData")
	uint8 bUseOnTouch : 1;

	UPROPERTY(EditDefaultsOnly, Category="WeaponData")
	uint8 bCanAutofireWithMinimalCharge : 1;

	UPROPERTY(EditDefaultsOnly, Category="WeaponData")
	uint8 bAllowADSInAir : 1;

	UPROPERTY(EditDefaultsOnly, Category="Reticle")
	uint8 bShowReticleHitNotifyAtImpactLocation : 1;

	UPROPERTY(EditDefaultsOnly, Category="Tooltip")
	uint8 bForceProjectileTooltip : 1;

	UPROPERTY(EditDefaultsOnly, Category="WeaponData")
	uint8 bPrimaryFireRequiresAmmo : 1;

	UPROPERTY(EditDefaultsOnly, Category="WeaponData")
	uint8 bSecondaryFireRequiresAmmo : 1;

	UPROPERTY(EditDefaultsOnly, Category="TouchFireModeOverrides")
	uint8 bAllowCombinedAimAndFire : 1;

	UPROPERTY(EditDefaultsOnly, Category="TouchFireModeOverrides")
	uint8 bAllowReleaseToFire : 1;

	UPROPERTY(EditDefaultsOnly, Category="TouchFireModeOverrides")
	uint8 bAllowContinuousFire : 1;

	UPROPERTY(EditDefaultsOnly, Category="Charge")
	TObjectPtr<UCurveFloat> ChargeToBurstRoundsCurve;

	UPROPERTY(EditDefaultsOnly, Category="Charge")
	TObjectPtr<UCurveFloat> ChargeToBurstFireRateCurve;

};

