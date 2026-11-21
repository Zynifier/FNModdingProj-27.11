// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "Athena/AI/FortAthenaAIBotSkillSet.h"
#include "FortAthenaAIBotAimingSkillSet.generated.h"

class AFortWeapon;

USTRUCT()
struct FAimingCircleSettings
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="AimingCircleSettings", meta=(AllowPrivateAccess="true"))
	FScalableFloat UseAimingCircle;

	UPROPERTY(EditDefaultsOnly, Category="Circles", meta=(AllowPrivateAccess="true"))
	FScalableFloat CircleCenterOffsetZ;

	UPROPERTY(EditDefaultsOnly, Category="Circles", meta=(AllowPrivateAccess="true"))
	FScalableFloat MinCircleOpeningAngleVerticalCurve;

	UPROPERTY(EditDefaultsOnly, Category="Circles", meta=(AllowPrivateAccess="true"))
	FScalableFloat MaxCircleOpeningAngleVerticalCurve;

	UPROPERTY(EditDefaultsOnly, Category="Circles", meta=(AllowPrivateAccess="true"))
	FScalableFloat MinCircleOpeningAngleHorizontalCurve;

	UPROPERTY(EditDefaultsOnly, Category="Circles", meta=(AllowPrivateAccess="true"))
	FScalableFloat MaxCircleOpeningAngleHorizontalCurve;

	UPROPERTY(EditDefaultsOnly, Category="Circles", meta=(AllowPrivateAccess="true"))
	FScalableFloat MinCursorRotationSpeed;

	UPROPERTY(EditDefaultsOnly, Category="Circles", meta=(AllowPrivateAccess="true"))
	FScalableFloat MaxCursorRotationSpeed;

	UPROPERTY(EditDefaultsOnly, Category="Circles", meta=(AllowPrivateAccess="true"))
	FScalableFloat MinCursorUpdateInterval;

	UPROPERTY(EditDefaultsOnly, Category="Circles", meta=(AllowPrivateAccess="true"))
	FScalableFloat MaxCursorUpdateInterval;

	UPROPERTY(EditDefaultsOnly, Category="Circles", meta=(AllowPrivateAccess="true"))
	FScalableFloat MinCursorTrackingFrequency;

	UPROPERTY(EditDefaultsOnly, Category="Circles", meta=(AllowPrivateAccess="true"))
	FScalableFloat MaxCursorTrackingFrequency;

	UPROPERTY(EditDefaultsOnly, Category="Circles", meta=(AllowPrivateAccess="true"))
	FScalableFloat CircleShrinkCurve;

	UPROPERTY(EditDefaultsOnly, Category="Time Between Hits", meta=(AllowPrivateAccess="true"))
	FScalableFloat MinDistanceForTimeBetweenHits;

	UPROPERTY(EditDefaultsOnly, Category="Time Between Hits", meta=(AllowPrivateAccess="true"))
	FScalableFloat MaxDistanceForTimeBetweenHits;

	UPROPERTY(EditDefaultsOnly, Category="Time Between Hits", meta=(AllowPrivateAccess="true"))
	FScalableFloat MinTimeBetweenHitsAtMinRange;

	UPROPERTY(EditDefaultsOnly, Category="Time Between Hits", meta=(AllowPrivateAccess="true"))
	FScalableFloat MaxTimeBetweenHitsAtMinRange;

	UPROPERTY(EditDefaultsOnly, Category="Time Between Hits", meta=(AllowPrivateAccess="true"))
	FScalableFloat MinTimeBetweenHitsAtMaxRange;

	UPROPERTY(EditDefaultsOnly, Category="Time Between Hits", meta=(AllowPrivateAccess="true"))
	FScalableFloat MaxTimeBetweenHitsAtMaxRange;

	UPROPERTY(EditDefaultsOnly, Category="Clamping", meta=(AllowPrivateAccess="true"))
	FScalableFloat ForceMissEnabled;

	UPROPERTY(EditDefaultsOnly, Category="Clamping", meta=(AllowPrivateAccess="true"))
	FScalableFloat ExtraClampingDistance;

	UPROPERTY(EditDefaultsOnly, Category="Clamping", meta=(AllowPrivateAccess="true"))
	FScalableFloat PreventHeadshots;

	UPROPERTY(EditDefaultsOnly, Category="Clamping", meta=(AllowPrivateAccess="true"))
	FScalableFloat WeaponSpreadContributionToClampCurve;

	UPROPERTY(EditDefaultsOnly, Category="Time Between Hits", meta=(AllowPrivateAccess="true"))
	FScalableFloat KillingBlowGracePeriodAtMinRange;

	UPROPERTY(EditDefaultsOnly, Category="Time Between Hits", meta=(AllowPrivateAccess="true"))
	FScalableFloat KillingBlowGracePeriodAtMaxRange;

	UPROPERTY(EditDefaultsOnly, Category="Time Between Hits", meta=(AllowPrivateAccess="true"))
	FScalableFloat ExtraHitOddsCurve;

};

USTRUCT()
struct FDigestedAimingCircleSettings
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	bool bUseAimingCircle;

	UPROPERTY(Transient)
	float CircleCenterOffsetZ;

	UPROPERTY(Transient)
	FScalableFloat MinCircleOpeningAngleVerticalCurve;

	UPROPERTY(Transient)
	FScalableFloat MaxCircleOpeningAngleVerticalCurve;

	UPROPERTY(Transient)
	FScalableFloat MinCircleOpeningAngleHorizontalCurve;

	UPROPERTY(Transient)
	FScalableFloat MaxCircleOpeningAngleHorizontalCurve;

	UPROPERTY(Transient)
	float MinCursorRotationSpeed;

	UPROPERTY(Transient)
	float MaxCursorRotationSpeed;

	UPROPERTY(Transient)
	float MinCursorUpdateInterval;

	UPROPERTY(Transient)
	float MaxCursorUpdateInterval;

	UPROPERTY(Transient)
	float MinCursorTrackingFrequency;

	UPROPERTY(Transient)
	float MaxCursorTrackingFrequency;

	UPROPERTY(Transient)
	FScalableFloat CircleShrinkCurve;

	UPROPERTY(Transient)
	float MinDistanceForTimeBetweenHits;

	UPROPERTY(Transient)
	float MaxDistanceForTimeBetweenHits;

	UPROPERTY(Transient)
	float MinTimeBetweenHitsAtMinRange;

	UPROPERTY(Transient)
	float MaxTimeBetweenHitsAtMinRange;

	UPROPERTY(Transient)
	float MinTimeBetweenHitsAtMaxRange;

	UPROPERTY(Transient)
	float MaxTimeBetweenHitsAtMaxRange;

	UPROPERTY(Transient)
	bool bForceMissEnabled;

	UPROPERTY(Transient)
	float ExtraClampingDistance;

	UPROPERTY(Transient)
	bool bPreventHeadshots;

	UPROPERTY(Transient)
	FScalableFloat WeaponSpreadContributionToClampCurve;

	UPROPERTY(Transient)
	float KillingBlowGracePeriodAtMinRange;

	UPROPERTY(Transient)
	float KillingBlowGracePeriodAtMaxRange;

	UPROPERTY(Transient)
	FScalableFloat ExtraHitOddsCurve;

};

USTRUCT()
struct FDigestedFocusSetting
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	FGameplayTagQuery WeaponTagQuery;

	UPROPERTY(Transient)
	bool bRequireAmmoToMatch;

	UPROPERTY(Transient)
	float IgnoreThreatTimeWhenNotAttacking;

	UPROPERTY(Transient)
	float IgnoreThreatDeviationWhenNotAttacking;

	UPROPERTY(Transient)
	float IgnoreThreatDuration;

	UPROPERTY(Transient)
	float IgnoreThreatDurationDeviation;

	UPROPERTY(Transient)
	float IgnoreThreatDistanceWhenFleeing;

	UPROPERTY(Transient)
	float IgnoreThreatDirectionCosAngleWhenFleeing;

};

USTRUCT()
struct FDigestedTargetBasedAccuracy
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	float AimTrackingOffsetErrorMultiplier;

	UPROPERTY(Transient)
	float AimTrackingHeightOffsetErrorMultiplier;

	UPROPERTY(Transient)
	float AimTrackingDistanceErrorMultiplier;

	UPROPERTY(Transient)
	float AimTrackingReactionTimeMultiplier;

	UPROPERTY(Transient)
	float AimTrackingInterpTimeMultiplier;

	UPROPERTY(Transient)
	float AimTrackingInAirVelocityThresholdMultiplier;

	UPROPERTY(Transient)
	float AimTrackinginAirHeightDataThresholdMultiplier;

};

USTRUCT()
struct FDigestedTargetBasedAccuracyCategory
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	FGameplayTagContainer Tags;

	UPROPERTY(Transient)
	FDigestedTargetBasedAccuracy TargetBasedAccuracy;

};

USTRUCT()
struct FDigestedTrackingOffsetModifierCurves
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	int32 Values[10];

};

USTRUCT()
struct FDigestedTrackingOffsetModifiers
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	float CombatStartDuration;

	UPROPERTY(Transient)
	float TargetLowHealthThreshold;

	UPROPERTY(Transient, meta=(ArraySizeEnum="/Script/FortniteAI.ETrackingOffsetModifierCurve"))
	FDigestedTrackingOffsetModifierCurves Curves[3];

	UPROPERTY(Transient, meta=(ArraySizeEnum="/Script/FortniteAI.ETrackingOffsetModifierCurve"))
	FDigestedTrackingOffsetModifierCurves DistanceCurves[3];

	UPROPERTY(Transient)
	FDigestedTrackingOffsetModifierCurves InAirHeightCurve;

};

USTRUCT()
struct FDigestedWeaponAccuracy
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	FScalableFloat TrackingOffsetError;

	UPROPERTY(Transient)
	FScalableFloat TargetingTrackingOffsetError;

	UPROPERTY(Transient)
	FScalableFloat TrackingDistanceFarError;

	UPROPERTY(Transient)
	FScalableFloat TargetingTrackingDistanceFarError;

	UPROPERTY(Transient)
	FScalableFloat TrackingDistanceNearError;

	UPROPERTY(Transient)
	FScalableFloat TargetingTrackingDistanceNearError;

	UPROPERTY(Transient)
	FScalableFloat TrackingDistanceNearErrorProbability;

	UPROPERTY(Transient)
	FScalableFloat TargetingActivationProbability;

	UPROPERTY(Transient)
	FScalableFloat FiringRestrictedToTargetingActive;

	UPROPERTY(Transient)
	float MinimumDistanceForAiming;

	UPROPERTY(Transient)
	float MinimumDistanceForPawnAiming;

	UPROPERTY(Transient)
	float IdealAttackRange;

	UPROPERTY(Transient)
	float TargetingIdealAttackRange;

	UPROPERTY(Transient)
	float MaxAttackRange;

	UPROPERTY(Transient)
	float ChanceToAimAtTargetsFeet;

	UPROPERTY(Transient)
	FScalableFloat ShouldUseProjectileArcForAiming;

	UPROPERTY(Transient)
	bool bKeepAimingOnSameSideWhileFiring;

	UPROPERTY(Transient)
	float MaxTrackingHeightOffsetError;

	UPROPERTY(Transient)
	float MinRotationInterpSpeed;

	UPROPERTY(Transient)
	float MaxRotationInterpSpeed;

	UPROPERTY(Transient)
	bool bOverrideAimingCircleSettings;

	UPROPERTY(Transient)
	bool bConsiderProjectileTravelTime;

	UPROPERTY(Transient)
	FDigestedAimingCircleSettings AimingCircleSettingsOverride;

};

USTRUCT()
struct FDigestedWeaponAccuracyCategorySpecialization
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	FGameplayTagContainer Tags;

	UPROPERTY(Transient)
	FDigestedWeaponAccuracy WeaponAccuracy;

};

USTRUCT()
struct FDigestedWeaponAccuracyCategory
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	FGameplayTagContainer Tags;

	UPROPERTY(Transient)
	FDigestedWeaponAccuracy WeaponAccuracy;

	UPROPERTY(Transient)
	TArray<FDigestedWeaponAccuracyCategorySpecialization> Specializations;

};

USTRUCT()
struct FFocusSetting
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FocusSetting", meta=(AllowPrivateAccess="true"))
	FGameplayTagQuery WeaponTagQuery;

	UPROPERTY(EditDefaultsOnly, Category="FocusSetting", meta=(AllowPrivateAccess="true"))
	bool bRequireAmmoToMatch;

	UPROPERTY(EditDefaultsOnly, Category="FocusSetting", meta=(AllowPrivateAccess="true"))
	FScalableFloat IgnoreThreatTimeWhenNotAttacking;

	UPROPERTY(EditDefaultsOnly, Category="FocusSetting", meta=(AllowPrivateAccess="true"))
	FScalableFloat IgnoreThreatDeviationWhenNotAttacking;

	UPROPERTY(EditDefaultsOnly, Category="FocusSetting", meta=(AllowPrivateAccess="true"))
	FScalableFloat IgnoreThreatDuration;

	UPROPERTY(EditDefaultsOnly, Category="FocusSetting", meta=(AllowPrivateAccess="true"))
	FScalableFloat IgnoreThreatDurationDeviation;

	UPROPERTY(EditDefaultsOnly, Category="FocusSetting", meta=(AllowPrivateAccess="true"))
	FScalableFloat IgnoreThreatDistanceWhenFleeing;

	UPROPERTY(EditDefaultsOnly, Category="FocusSetting", meta=(AllowPrivateAccess="true"))
	FScalableFloat IgnoreThreatDirectionAngleWhenFleeing;

};

USTRUCT()
struct FLookAtDigestedSetting
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	float LookAtDuration;

	UPROPERTY(Transient)
	float LookAtDurationDeviation;

	UPROPERTY(Transient)
	float LookAtDelay;

	UPROPERTY(Transient)
	float LookAtDelayDeviation;

};

USTRUCT()
struct FLookAtSetting
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Focusing", meta=(AllowPrivateAccess="true"))
	FScalableFloat LookAtDuration;

	UPROPERTY(EditDefaultsOnly, Category="Focusing", meta=(AllowPrivateAccess="true"))
	FScalableFloat LookAtDurationDeviation;

	UPROPERTY(EditDefaultsOnly, Category="Focusing", meta=(AllowPrivateAccess="true"))
	FScalableFloat LookAtDelay;

	UPROPERTY(EditDefaultsOnly, Category="Focusing", meta=(AllowPrivateAccess="true"))
	FScalableFloat LookAtDelayDeviation;

};

USTRUCT()
struct FTargetBasedAccuracy
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Target Based Accuracy Multiplier", meta=(AllowPrivateAccess="true"))
	FScalableFloat AimTrackingOffsetErrorMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="Target Based Accuracy Multiplier", meta=(AllowPrivateAccess="true"))
	FScalableFloat AimTrackingHeightOffsetErrorMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="Target Based Accuracy Multiplier", meta=(AllowPrivateAccess="true"))
	FScalableFloat AimTrackingDistanceErrorMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="Target Based Accuracy Multiplier", meta=(AllowPrivateAccess="true"))
	FScalableFloat AimTrackingReactionTimeMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="Target Based Accuracy Multiplier", meta=(AllowPrivateAccess="true"))
	FScalableFloat AimTrackingInterpTimeMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="Target Based Accuracy Multiplier", meta=(AllowPrivateAccess="true"))
	FScalableFloat AimTrackingInAirVelocityThresholdMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="Target Based Accuracy Multiplier", meta=(AllowPrivateAccess="true"))
	FScalableFloat AimTrackinginAirHeightDataThresholdMultiplier;

};

USTRUCT()
struct FTargetBasedAccuracyCategory
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="TargetBasedAccuracyCategory", meta=(AllowPrivateAccess="true", DisplayName="Category Tags"))
	FGameplayTagContainer Tags;

	UPROPERTY(EditDefaultsOnly, Category="TargetBasedAccuracyCategory", meta=(AllowPrivateAccess="true", DisplayName="Category Target Based Accuracy Multipliers"))
	FTargetBasedAccuracy TargetBasedAccuracy;

};

USTRUCT()
struct FTrackingOffsetModifiers
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="TrackingOffsetModifiers", meta=(AllowPrivateAccess="true"))
	FScalableFloat CombatStartDuration;

	UPROPERTY(EditDefaultsOnly, Category="TrackingOffsetModifiers", meta=(AllowPrivateAccess="true"))
	FScalableFloat TargetLowHealthThreshold;

	UPROPERTY(EditDefaultsOnly, Category="TrackingOffsetModifiers", meta=(AllowPrivateAccess="true", ArraySizeEnum="/Script/FortniteAI.ETrackingOffsetModifierCurve"))
	FScalableFloat Curves[3];

	UPROPERTY(EditDefaultsOnly, Category="TrackingOffsetModifiers", meta=(AllowPrivateAccess="true", ArraySizeEnum="/Script/FortniteAI.ETrackingOffsetModifierCurve"))
	FScalableFloat DistanceCurves[3];

	UPROPERTY(EditDefaultsOnly, Category="TrackingOffsetModifiers", meta=(AllowPrivateAccess="true"))
	FScalableFloat InAirHeightCurve;

};

USTRUCT()
struct FTrackingOffsetModifierInfo
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="TrackingOffsetModifierInfo", meta=(AllowPrivateAccess="true"))
	FScalableFloat MinSkill;

	UPROPERTY(EditDefaultsOnly, Category="TrackingOffsetModifierInfo", meta=(AllowPrivateAccess="true"))
	FScalableFloat MaxSkill;

	UPROPERTY(EditDefaultsOnly, Category="TrackingOffsetModifierInfo", meta=(AllowPrivateAccess="true"))
	FTrackingOffsetModifiers Modifiers;

};

USTRUCT()
struct FWeaponAccuracy
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="WeaponAccuracy", meta=(AllowPrivateAccess="true"))
	FScalableFloat MaxTrackingOffsetError;

	UPROPERTY(EditDefaultsOnly, Category="WeaponAccuracy", meta=(AllowPrivateAccess="true"))
	FScalableFloat TargetingMaxTrackingOffsetError;

	UPROPERTY(EditDefaultsOnly, Category="WeaponAccuracy", meta=(AllowPrivateAccess="true"))
	FScalableFloat MaxTrackingDistanceFarError;

	UPROPERTY(EditDefaultsOnly, Category="WeaponAccuracy", meta=(AllowPrivateAccess="true"))
	FScalableFloat TargetingMaxTrackingDistanceFarError;

	UPROPERTY(EditDefaultsOnly, Category="WeaponAccuracy", meta=(AllowPrivateAccess="true"))
	FScalableFloat MaxTrackingDistanceNearError;

	UPROPERTY(EditDefaultsOnly, Category="WeaponAccuracy", meta=(AllowPrivateAccess="true"))
	FScalableFloat TargetingMaxTrackingDistanceNearError;

	UPROPERTY(EditDefaultsOnly, Category="WeaponAccuracy", meta=(AllowPrivateAccess="true"))
	FScalableFloat TrackingDistanceNearErrorProbability;

	UPROPERTY(EditDefaultsOnly, Category="WeaponAccuracy", meta=(AllowPrivateAccess="true"))
	FScalableFloat TargetingActivationProbability;

	UPROPERTY(EditDefaultsOnly, Category="WeaponAccuracy", meta=(AllowPrivateAccess="true"))
	FScalableFloat FiringRestrictedToTargetingActive;

	UPROPERTY(EditDefaultsOnly, Category="WeaponAccuracy", meta=(AllowPrivateAccess="true"))
	FScalableFloat MinimumDistanceForAiming;

	UPROPERTY(EditDefaultsOnly, Category="WeaponAccuracy", meta=(AllowPrivateAccess="true"))
	FScalableFloat MinimumDistanceForPawnAiming;

	UPROPERTY(EditDefaultsOnly, Category="WeaponAccuracy", meta=(AllowPrivateAccess="true"))
	FScalableFloat IdealAttackRange;

	UPROPERTY(EditDefaultsOnly, Category="WeaponAccuracy", meta=(AllowPrivateAccess="true"))
	FScalableFloat TargetingIdealAttackRange;

	UPROPERTY(EditDefaultsOnly, Category="WeaponAccuracy", meta=(AllowPrivateAccess="true"))
	FScalableFloat MaxAttackRangeFactor;

	UPROPERTY(EditDefaultsOnly, Category="WeaponAccuracy", meta=(AllowPrivateAccess="true", DisplayName="Chance To Aim At Targets Feet"))
	FScalableFloat ShouldAimAtTargetsFeet;

	UPROPERTY(EditDefaultsOnly, Category="WeaponAccuracy", meta=(AllowPrivateAccess="true"))
	FScalableFloat ShouldUseProjectileArcForAiming;

	UPROPERTY(EditDefaultsOnly, Category="WeaponAccuracy", meta=(AllowPrivateAccess="true"))
	FScalableFloat KeepAimingOnSameSideWhileFiring;

	UPROPERTY(EditDefaultsOnly, Category="WeaponAccuracy", meta=(AllowPrivateAccess="true"))
	FScalableFloat MaxTrackingHeightOffsetError;

	UPROPERTY(EditDefaultsOnly, Category="WeaponAccuracy", meta=(AllowPrivateAccess="true"))
	FScalableFloat MinRotationInterpSpeed;

	UPROPERTY(EditDefaultsOnly, Category="WeaponAccuracy", meta=(AllowPrivateAccess="true"))
	FScalableFloat MaxRotationInterpSpeed;

	UPROPERTY(EditDefaultsOnly, Category="WeaponAccuracy", meta=(AllowPrivateAccess="true"))
	FScalableFloat ConsiderProjectileTravelTime;

	UPROPERTY(EditDefaultsOnly, Category="WeaponAccuracy", meta=(AllowPrivateAccess="true", DisplayName="Override Aiming Circle Settings"))
	bool bOverrideAimingCircleSettings;

	UPROPERTY(EditDefaultsOnly, Category="WeaponAccuracy", meta=(AllowPrivateAccess="true", EditCondition="bOverrideAimingCircleSettings"))
	FAimingCircleSettings AimingCircleSettingsOverride;

};

USTRUCT()
struct FWeaponAccuracyCategorySpecialization
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="WeaponAccuracyCategorySpecialization", meta=(AllowPrivateAccess="true", DisplayName="Traits"))
	FGameplayTagContainer Tags;

	UPROPERTY(EditDefaultsOnly, Category="WeaponAccuracyCategorySpecialization", meta=(AllowPrivateAccess="true", DisplayName="Specialization Accuracy"))
	FWeaponAccuracy WeaponAccuracy;

};

USTRUCT()
struct FWeaponAccuracyCategory
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="WeaponAccuracyCategory", meta=(AllowPrivateAccess="true", DisplayName="Category Tags"))
	FGameplayTagContainer Tags;

	UPROPERTY(EditDefaultsOnly, Category="WeaponAccuracyCategory", meta=(AllowPrivateAccess="true", DisplayName="Category Accuracy"))
	FWeaponAccuracy WeaponAccuracy;

	UPROPERTY(EditDefaultsOnly, Category="WeaponAccuracyCategory", meta=(AllowPrivateAccess="true", DisplayName="Category Specializations"))
	TArray<FWeaponAccuracyCategorySpecialization> Specializations;

};

UCLASS(MinimalAPI)
class UFortAthenaAIBotAimingDigestedSkillSet : public UFortAthenaAIBotDigestedSkillSet
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	FDigestedFocusSetting DefaultFocusSetting;

	UPROPERTY(Transient)
	TArray<FDigestedFocusSetting> FocusSettings;

	UPROPERTY(Transient, meta=(ArraySizeEnum="/Script/FortniteAI.ELookAtType"))
	FLookAtDigestedSetting LookAtSettings[4];

	UPROPERTY(Transient)
	bool bAllowScanAroundWhileSwimming;

	UPROPERTY(Transient)
	float TrackingReactionTime;

	UPROPERTY(Transient)
	float InAirTrackingReactionTimeMultiplier;

	UPROPERTY(Transient)
	float TrackingInterpTime;

	UPROPERTY(Transient)
	float TrackingInterpTimeMultForGroundVehicles;

	UPROPERTY(Transient)
	float TrackingInterpTimeMultForFlyingVehicles;

	UPROPERTY(Transient)
	float MaxTrackingPredictionError;

	UPROPERTY(Transient)
	float MaxTrackingOffsetErrorMultiplier;

	UPROPERTY(Transient)
	float AdjustedTrackingOffsetErrorMultiplierAgainstAIs;

	UPROPERTY(Transient)
	float TrackingErrorUpdateInterval;

	UPROPERTY(Transient)
	float TrackingInAirVelocityThreshold;

	UPROPERTY(Transient)
	float TrackingInAirHeightDeltaThreshold;

	UPROPERTY(Transient)
	float TargetAcquisitionRate;

	UPROPERTY(Transient)
	float TimeToHitMultiplier;

	UPROPERTY(Transient)
	float MaxTimeToHitAddedCausedByTargetSpeed;

	UPROPERTY(Transient)
	float MaxTimeToHitAddedCausedByTargetInAir;

	UPROPERTY(Transient)
	float TimeToHitDelayMultiplierWhenTargetInAir;

	UPROPERTY(Transient)
	FScalableFloat TimeToHitDelayMultiplierCurveBasedOnSpeed;

	UPROPERTY(Transient)
	bool bAimingCircleEnabled;

	UPROPERTY(Transient)
	bool bTargetIdleDetectionEnabled;

	UPROPERTY(Transient)
	bool bTargetIdleUseAgainstNPC;

	UPROPERTY(Transient)
	float TargetIdleLookBackTime;

	UPROPERTY(Transient)
	float TargetIdleUnsuspectingCosAngle;

	UPROPERTY(Transient)
	float TargetIdleUnsuspectingDistance;

	UPROPERTY(Transient)
	float TargetIdleUnsuspectingDamageDuration;

	UPROPERTY(Transient)
	float TargetIdleUnsuspectingTimeMultiplier;

	UPROPERTY(Transient)
	float TargetIdleVerticalSpeedThreshold;

	UPROPERTY(Transient)
	float TargetIdleLateralSpeedThreshold;

	UPROPERTY(Transient)
	float TargetIdleFrontalSpeedThreshold;

	UPROPERTY(Transient)
	float TargetIdleRevivedGracePeriodDuration;

	UPROPERTY(Transient)
	float MaxDistanceEvaluationErrorRatio;

	UPROPERTY(Transient)
	float TargetingUpdateInterval;

	UPROPERTY(Transient)
	float TargetingUpdateIntervalMaxDeviation;

	UPROPERTY(Transient)
	float ReachLeashLimitToleranceDistance;

	UPROPERTY(Transient)
	bool bShootFloorTrapOnlyWhenHigherThanTrap;

	UPROPERTY(Transient)
	float TargetingRotationSpeedLimit;

	UPROPERTY(Transient)
	float TargetingRotationSnapThreshold;

	UPROPERTY(Transient)
	float BaseClampingDistance;

	UPROPERTY(Transient)
	FDigestedWeaponAccuracy NoWeaponAccuracy;

	UPROPERTY(Transient)
	TArray<FDigestedWeaponAccuracyCategory> WeaponAccuracies;

	UPROPERTY(Transient)
	TArray<FDigestedTargetBasedAccuracyCategory> DigestedTargetBasedAccuracies;

	UPROPERTY(Transient)
	FDigestedTrackingOffsetModifiers TrackingOffsetModifiers;

	UPROPERTY(Transient)
	FDigestedAimingCircleSettings DefaultAimingCircleSettings;

	UPROPERTY(Transient)
	TWeakObjectPtr<AFortWeapon> CachedWeaponUsedToCalculateAccuracy;

	UPROPERTY(Transient)
	FGameplayTagQuery WeaponModTagQuery;

	UPROPERTY(Transient)
	float WeaponModAccuracyModifier;

};

UCLASS()
class FORTNITEAI_API UFortAthenaAIBotAimingSkillSet : public UFortAthenaAIBotSkillSet
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Focusing", meta=(AllowPrivateAccess="true"))
	FFocusSetting DefaultFocusSetting;

	UPROPERTY(EditDefaultsOnly, Category="Focusing", meta=(AllowPrivateAccess="true"))
	TArray<FFocusSetting> FocusSettings;

	UPROPERTY(EditDefaultsOnly, Category="Focusing", meta=(AllowPrivateAccess="true", ArraySizeEnum="/Script/FortniteAI.ELookAtType"))
	FLookAtSetting LookAtSettings[4];

	UPROPERTY(EditDefaultsOnly, Category="Focusing", meta=(AllowPrivateAccess="true"))
	FScalableFloat AllowScanAroundWhileSwimming;

	UPROPERTY(EditDefaultsOnly, Category="Aiming", meta=(AllowPrivateAccess="true"))
	FScalableFloat TrackingReactionTime;

	UPROPERTY(EditDefaultsOnly, Category="Aiming", meta=(AllowPrivateAccess="true"))
	FScalableFloat InAirTrackingReactionTimeMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="Aiming", meta=(AllowPrivateAccess="true"))
	FScalableFloat TrackingInterpTime;

	UPROPERTY(EditDefaultsOnly, Category="Aiming", meta=(AllowPrivateAccess="true"))
	FScalableFloat TrackingInterpTimeMultForGroundVehicles;

	UPROPERTY(EditDefaultsOnly, Category="Aiming", meta=(AllowPrivateAccess="true"))
	FScalableFloat TrackingInterpTimeMultForFlyingVehicles;

	UPROPERTY(EditDefaultsOnly, Category="Aiming", meta=(AllowPrivateAccess="true"))
	FScalableFloat MaxTrackingPredictionError;

	UPROPERTY(EditDefaultsOnly, Category="Aiming", meta=(AllowPrivateAccess="true"))
	FScalableFloat MaxTrackingOffsetErrorMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="Aiming", meta=(AllowPrivateAccess="true"))
	FScalableFloat AdjustedTrackingOffsetErrorMultiplierAgainstAIs;

	UPROPERTY(EditDefaultsOnly, Category="Aiming", meta=(AllowPrivateAccess="true"))
	FScalableFloat TrackingErrorUpdateInterval;

	UPROPERTY(EditDefaultsOnly, Category="Aiming", meta=(AllowPrivateAccess="true"))
	FScalableFloat TrackingInAirVelocityThreshold;

	UPROPERTY(EditDefaultsOnly, Category="Aiming", meta=(AllowPrivateAccess="true"))
	FScalableFloat TrackingInAirHeightDeltaThreshold;

	UPROPERTY(EditDefaultsOnly, Category="Aiming", meta=(AllowPrivateAccess="true"))
	FScalableFloat TargetAcquisitionRate;

	UPROPERTY(EditDefaultsOnly, Category="Time Between Hits", meta=(AllowPrivateAccess="true"))
	FScalableFloat TimeToHitMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="Time Between Hits", meta=(AllowPrivateAccess="true"))
	FScalableFloat MaxTimeToHitAddedCausedByTargetSpeed;

	UPROPERTY(EditDefaultsOnly, Category="Time Between Hits", meta=(AllowPrivateAccess="true"))
	FScalableFloat MaxTimeToHitAddedCausedByTargetInAir;

	UPROPERTY(EditDefaultsOnly, Category="Time Between Hits", meta=(AllowPrivateAccess="true"))
	FScalableFloat TimeToHitDelayMultiplierWhenTargetInAir;

	UPROPERTY(EditDefaultsOnly, Category="Time Between Hits", meta=(AllowPrivateAccess="true"))
	FScalableFloat TimeToHitDelayMultiplierCurveBasedOnSpeed;

	UPROPERTY(EditDefaultsOnly, Category="Aiming", meta=(AllowPrivateAccess="true"))
	FScalableFloat AimingCircleEnabled;

	UPROPERTY(EditDefaultsOnly, Category="Idle Detection", meta=(AllowPrivateAccess="true"))
	FScalableFloat TargetIdleDetectionEnabled;

	UPROPERTY(EditDefaultsOnly, Category="Idle Detection", meta=(AllowPrivateAccess="true"))
	FScalableFloat TargetIdleUseAgainstNPC;

	UPROPERTY(EditDefaultsOnly, Category="Idle Detection", meta=(AllowPrivateAccess="true"))
	FScalableFloat TargetIdleLookBackTime;

	UPROPERTY(EditDefaultsOnly, Category="Idle Detection", meta=(AllowPrivateAccess="true"))
	FScalableFloat TargetIdleUnsuspectingAngle;

	UPROPERTY(EditDefaultsOnly, Category="Idle Detection", meta=(AllowPrivateAccess="true"))
	FScalableFloat TargetIdleUnsuspectingDistance;

	UPROPERTY(EditDefaultsOnly, Category="Idle Detection", meta=(AllowPrivateAccess="true"))
	FScalableFloat TargetIdleUnsuspectingDamageDuration;

	UPROPERTY(EditDefaultsOnly, Category="Idle Detection", meta=(AllowPrivateAccess="true"))
	FScalableFloat TargetIdleUnsuspectingTimeMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="Idle Detection", meta=(AllowPrivateAccess="true"))
	FScalableFloat TargetIdleVerticalSpeedThreshold;

	UPROPERTY(EditDefaultsOnly, Category="Idle Detection", meta=(AllowPrivateAccess="true"))
	FScalableFloat TargetIdleLateralSpeedThreshold;

	UPROPERTY(EditDefaultsOnly, Category="Idle Detection", meta=(AllowPrivateAccess="true"))
	FScalableFloat TargetIdleFrontalSpeedThreshold;

	UPROPERTY(EditDefaultsOnly, Category="Idle Detection", meta=(AllowPrivateAccess="true"))
	FScalableFloat TargetIdleRevivedGracePeriodDuration;

	UPROPERTY(EditDefaultsOnly, Category="Aiming", meta=(AllowPrivateAccess="true"))
	FScalableFloat MaxDistanceEvaluationErrorRatio;

	UPROPERTY(EditDefaultsOnly, Category="Aiming", meta=(AllowPrivateAccess="true"))
	FScalableFloat TargetingUpdateInterval;

	UPROPERTY(EditDefaultsOnly, Category="Aiming", meta=(AllowPrivateAccess="true"))
	FScalableFloat TargetingUpdateIntervalMaxDeviation;

	UPROPERTY(EditDefaultsOnly, Category="Aiming", meta=(AllowPrivateAccess="true"))
	FScalableFloat ReachLeashLimitToleranceDistance;

	UPROPERTY(EditDefaultsOnly, Category="Aiming", meta=(AllowPrivateAccess="true"))
	FScalableFloat ShootFloorTrapOnlyWhenHigherThanTrap;

	UPROPERTY(EditDefaultsOnly, Category="Aiming", meta=(AllowPrivateAccess="true"))
	FScalableFloat TargetingRotationSpeedLimit;

	UPROPERTY(EditDefaultsOnly, Category="Aiming", meta=(AllowPrivateAccess="true"))
	FScalableFloat TargetingRotationSnapThreshold;

	UPROPERTY(EditDefaultsOnly, Category="Aiming", meta=(AllowPrivateAccess="true"))
	FScalableFloat BaseClampingDistance;

	UPROPERTY(EditDefaultsOnly, Category="Weapon", meta=(AllowPrivateAccess="true"))
	FWeaponAccuracy NoWeaponAccuracy;

	UPROPERTY(EditDefaultsOnly, Category="Weapon", meta=(AllowPrivateAccess="true", TitleProperty="Tags"))
	TArray<FWeaponAccuracyCategory> WeaponAccuracies;

	UPROPERTY(EditDefaultsOnly, Category="Weapon", meta=(AllowPrivateAccess="true"))
	TArray<FTargetBasedAccuracyCategory> TargetBasedAccuracies;

	UPROPERTY(EditDefaultsOnly, Category="Modifiers", meta=(AllowPrivateAccess="true"))
	uint8 bDigestTrackingOffsetModifiersWithAvgMatchMMR : 1;

	UPROPERTY(EditDefaultsOnly, Category="Modifiers", meta=(AllowPrivateAccess="true"))
	TArray<FTrackingOffsetModifierInfo> TrackingOffsetModifiers;

	UPROPERTY(EditDefaultsOnly, Category="Aiming Circle", meta=(AllowPrivateAccess="true"))
	FAimingCircleSettings DefaultAimingCircleSettings;

	UPROPERTY(EditDefaultsOnly, Category="Weapon Mods", meta=(AllowPrivateAccess="true"))
	FGameplayTagQuery WeaponModTagQuery;

	UPROPERTY(EditDefaultsOnly, Category="Weapon Mods", meta=(AllowPrivateAccess="true", UIMax="1.0", UIMin="0.0"))
	FScalableFloat WeaponModAccuracyModifier;

};

