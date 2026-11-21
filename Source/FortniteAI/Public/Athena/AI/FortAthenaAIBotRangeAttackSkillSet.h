// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "Athena/AI/FortAthenaAIBotSkillSet.h"
#include "FortAthenaAIBotRangeAttackSkillSet.generated.h"

class AFortWeapon;
class UCurveFloat;

USTRUCT()
struct FDigestedFiringPattern
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	float MinRange;

	UPROPERTY(Transient)
	float MaxRange;

	UPROPERTY(Transient)
	float HoldTimeDeviation;

	UPROPERTY(Transient)
	float PreventFireTimeDeviation;

	UPROPERTY(Transient)
	float FiringPatternHysteresis;

	UPROPERTY(Transient)
	TObjectPtr<UCurveFloat> FiringPatternCurve;

};

USTRUCT()
struct FDigestedRangedWeaponSkill
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	float DelayBetweenShots;

	UPROPERTY(Transient)
	float DelayDeviationTimeBetweenShots;

	UPROPERTY(Transient)
	float TriggerHoldDuration;

	UPROPERTY(Transient)
	float TriggerHoldDeviationTime;

	UPROPERTY(Transient)
	float DelayBeforeFirstShot;

	UPROPERTY(Transient)
	float ShotDelayAfterTargeting;

	UPROPERTY(Transient)
	float ShotDelayAfterIncomingLethality;

	UPROPERTY(Transient)
	float InterruptReloadToShootOdds;

	UPROPERTY(Transient)
	TArray<FDigestedFiringPattern> TargetInAirFiringPatterns;

	UPROPERTY(Transient)
	TArray<FDigestedFiringPattern> FiringPatterns;

};

USTRUCT()
struct FDigestedRangedWeaponSkillCategorySpecialization
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	FGameplayTagContainer Tags;

	UPROPERTY(Transient)
	FDigestedRangedWeaponSkill WeaponSkill;

};

USTRUCT()
struct FDigestedRangedWeaponSkillCategory
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	FGameplayTagContainer Tags;

	UPROPERTY(Transient)
	FDigestedRangedWeaponSkill WeaponSkill;

	UPROPERTY(Transient)
	TArray<FDigestedRangedWeaponSkillCategorySpecialization> Specializations;

};

USTRUCT()
struct FFiringPattern
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FiringPattern", meta=(AllowPrivateAccess="true"))
	FScalableFloat MinRange;

	UPROPERTY(EditDefaultsOnly, Category="FiringPattern", meta=(AllowPrivateAccess="true"))
	FScalableFloat MaxRange;

	UPROPERTY(EditDefaultsOnly, Category="FiringPattern", meta=(AllowPrivateAccess="true"))
	FScalableFloat HoldTimeDeviation;

	UPROPERTY(EditDefaultsOnly, Category="FiringPattern", meta=(AllowPrivateAccess="true"))
	FScalableFloat PreventFireTimeDeviation;

	UPROPERTY(EditDefaultsOnly, Category="FiringPattern", meta=(AllowPrivateAccess="true"))
	FScalableFloat FiringPatternHysteresis;

	UPROPERTY(EditDefaultsOnly, Category="FiringPattern", meta=(AllowPrivateAccess="true"))
	TObjectPtr<UCurveFloat> FiringPatternCurve;

};

USTRUCT()
struct FRangedWeaponSkill
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="RangedWeaponSkill", meta=(AllowPrivateAccess="true"))
	FScalableFloat DelayBetweenShots;

	UPROPERTY(EditDefaultsOnly, Category="RangedWeaponSkill", meta=(AllowPrivateAccess="true"))
	FScalableFloat DelayDeviationTimeBetweenShots;

	UPROPERTY(EditDefaultsOnly, Category="RangedWeaponSkill", meta=(AllowPrivateAccess="true"))
	FScalableFloat TriggerHoldDuration;

	UPROPERTY(EditDefaultsOnly, Category="RangedWeaponSkill", meta=(AllowPrivateAccess="true"))
	FScalableFloat TriggerHoldDeviationTime;

	UPROPERTY(EditDefaultsOnly, Category="RangedWeaponSkill", meta=(AllowPrivateAccess="true"))
	FScalableFloat DelayBeforeFirstShot;

	UPROPERTY(EditDefaultsOnly, Category="RangedWeaponSkill", meta=(AllowPrivateAccess="true"))
	FScalableFloat ShotDelayAfterTargeting;

	UPROPERTY(EditDefaultsOnly, Category="RangedWeaponSkill", meta=(AllowPrivateAccess="true"))
	FScalableFloat ShotDelayAfterIncomingLethality;

	UPROPERTY(EditDefaultsOnly, Category="RangedWeaponSkill", meta=(AllowPrivateAccess="true"))
	TArray<FFiringPattern> TargetInAirFiringPatterns;

	UPROPERTY(EditDefaultsOnly, Category="RangedWeaponSkill", meta=(AllowPrivateAccess="true"))
	TArray<FFiringPattern> FiringPatterns;

	UPROPERTY(EditDefaultsOnly, Category="RangedWeaponSkill", meta=(AllowPrivateAccess="true"))
	FScalableFloat InterruptReloadToShootOdds;

};

USTRUCT()
struct FRangedWeaponSkillCategorySpecialization
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="RangedWeaponSkillCategorySpecialization", meta=(AllowPrivateAccess="true", DisplayName="Traits"))
	FGameplayTagContainer Tags;

	UPROPERTY(EditDefaultsOnly, Category="RangedWeaponSkillCategorySpecialization", meta=(AllowPrivateAccess="true", DisplayName="Specialization Skill Set"))
	FRangedWeaponSkill WeaponSkill;

};

USTRUCT()
struct FRangedWeaponSkillCategory
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="RangedWeaponSkillCategory", meta=(AllowPrivateAccess="true", DisplayName="Category Tags"))
	FGameplayTagContainer Tags;

	UPROPERTY(EditDefaultsOnly, Category="RangedWeaponSkillCategory", meta=(AllowPrivateAccess="true", DisplayName="Category Skill Set"))
	FRangedWeaponSkill WeaponSkill;

	UPROPERTY(EditDefaultsOnly, Category="RangedWeaponSkillCategory", meta=(AllowPrivateAccess="true", DisplayName="Category Specializations"))
	TArray<FRangedWeaponSkillCategorySpecialization> Specializations;

};

UCLASS(MinimalAPI)
class UFortAthenaAIBotRangeAttackDigestedSkillSet : public UFortAthenaAIBotDigestedSkillSet
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	TWeakObjectPtr<AFortWeapon> CachedWeaponUsedToCalculateSkillSet;

	UPROPERTY(Transient)
	TArray<FDigestedRangedWeaponSkillCategory> RangedWeaponCategorySkills;

	UPROPERTY(Transient)
	float ChangeWeaponDelay;

	UPROPERTY(Transient)
	float ChangeWeaponDelayDeviation;

	UPROPERTY(Transient)
	float SwapInsteadOfReloadOdds;

	UPROPERTY(Transient)
	float SwapInsteadOfReloadRangeMax;

	UPROPERTY(Transient)
	FGameplayTagContainer SwapInsteadOfReloadIgnoredWeaponTags;

	UPROPERTY(Transient)
	float InterruptReloadToShootOdds;

	UPROPERTY(Transient)
	float ReloadPartiallyEmptyWeaponsOdds;

	UPROPERTY(Transient)
	float UseCoverOdds;

	UPROPERTY(Transient)
	float CoverDistanceMin;

	UPROPERTY(Transient)
	FScalableFloat CoverDistanceMaxCurve;

	UPROPERTY(Transient)
	float CoverDistanceToTargetMin;

	UPROPERTY(Transient)
	float MinimumDistanceToTargetWhileMovingToCover;

	UPROPERTY(Transient)
	float CoverSearchCooldown;

	UPROPERTY(Transient)
	float MaximumPathDetourFactor;

	UPROPERTY(Transient)
	float PostCoverCooldownMin;

	UPROPERTY(Transient)
	float PostCoverCooldownMax;

	UPROPERTY(Transient)
	bool bCanFindShootingPositionAround;

	UPROPERTY(Transient)
	float PositioningMaxSearchRadius;

	UPROPERTY(Transient)
	float PositioningQueryCooldown;

	UPROPERTY(Transient)
	float PositioningQueryCooldownDeviation;

	UPROPERTY(Transient)
	int32 CoverPeekCountMin;

	UPROPERTY(Transient)
	int32 CoverPeekCountMax;

	UPROPERTY(Transient)
	float ShotDelayAfterTargetRevived;

	UPROPERTY(Transient)
	TArray<FDigestedFiringPattern> DefaultTargetInAirFiringPatterns;

	UPROPERTY(Transient)
	bool bStepBackEnabled;

	UPROPERTY(Transient)
	float StepBackCooldown;

	UPROPERTY(Transient)
	float StepBackPercentageChance;

	UPROPERTY(Transient)
	float StepBackDistanceBetweenAIPawnAndTargetMin;

	UPROPERTY(Transient)
	float StepBackDistanceBetweenAIPawnAndTargetMax;

	UPROPERTY(Transient)
	float StepBackDistanceBetweenCoverAndTargetMin;

	UPROPERTY(Transient)
	float StepBackDistanceBetweenCoverAndTargetMax;

	UPROPERTY(Transient)
	float StepBackDistanceBetweenAIPawnAndCoverMin;

	UPROPERTY(Transient)
	float StepBackDistanceBetweenAIPawnAndCoverMax;

	UPROPERTY(Transient)
	bool bFlankingEnabled;

	UPROPERTY(Transient)
	float FlankingCooldown;

	UPROPERTY(Transient)
	float FlankingPercentageChance;

	UPROPERTY(Transient)
	float FlankingInnerRadius;

	UPROPERTY(Transient)
	float FlankingOuterRadius;

	UPROPERTY(Transient)
	int32 FlankingLayersCount;

	UPROPERTY(Transient)
	int32 FlankingPointsPerLayerCount;

	UPROPERTY(Transient)
	float FlankingMaxAngleRad;

	UPROPERTY(Transient)
	float FlankingScorePawnDetectionRadius;

	UPROPERTY(Transient)
	float LoFMaxDistanceToTest;

	UPROPERTY(Transient)
	float LoFForceCrouchVehicleSeatZOffset;

};

UCLASS(MinimalAPI)
class UFortAthenaAIBotRangeAttackSkillSet : public UFortAthenaAIBotSkillSet
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Ranged Weapon", meta=(AllowPrivateAccess="true"))
	TArray<FRangedWeaponSkillCategory> RangedWeaponSkills;

	UPROPERTY(EditDefaultsOnly, Category="Weapon Swap", meta=(AllowPrivateAccess="true"))
	FScalableFloat ChangeWeaponDelay;

	UPROPERTY(EditDefaultsOnly, Category="Weapon Swap", meta=(AllowPrivateAccess="true"))
	FScalableFloat ChangeWeaponDelayDeviation;

	UPROPERTY(EditDefaultsOnly, Category="Weapon Swap", meta=(AllowPrivateAccess="true"))
	FScalableFloat SwapInsteadOfReloadOdds;

	UPROPERTY(EditDefaultsOnly, Category="Weapon Swap", meta=(AllowPrivateAccess="true"))
	FScalableFloat SwapInsteadOfReloadRangeMax;

	UPROPERTY(EditDefaultsOnly, Category="Weapon Swap", meta=(AllowPrivateAccess="true"))
	FGameplayTagContainer SwapInsteadOfReloadIgnoredWeaponTags;

	UPROPERTY(EditDefaultsOnly, Category="Reload", meta=(AllowPrivateAccess="true"))
	FScalableFloat InterruptReloadToShootOdds;

	UPROPERTY(EditDefaultsOnly, Category="Reload", meta=(AllowPrivateAccess="true"))
	FScalableFloat ReloadPartiallyEmptyWeaponsOdds;

	UPROPERTY(EditDefaultsOnly, Category="Cover Positioning", meta=(AllowPrivateAccess="true"))
	FScalableFloat UseCoverOdds;

	UPROPERTY(EditDefaultsOnly, Category="Cover Positioning", meta=(AllowPrivateAccess="true"))
	FScalableFloat CoverDistanceMin;

	UPROPERTY(EditDefaultsOnly, Category="Cover Positioning", meta=(AllowPrivateAccess="true"))
	FScalableFloat CoverDistanceMaxCurve;

	UPROPERTY(EditDefaultsOnly, Category="Cover Positioning", meta=(AllowPrivateAccess="true"))
	FScalableFloat CoverDistanceToTargetMin;

	UPROPERTY(EditDefaultsOnly, Category="Cover Positioning", meta=(AllowPrivateAccess="true"))
	FScalableFloat MinimumDistanceToTargetWhileMovingToCover;

	UPROPERTY(EditDefaultsOnly, Category="Cover Positioning", meta=(AllowPrivateAccess="true"))
	FScalableFloat CoverSearchCooldown;

	UPROPERTY(EditDefaultsOnly, Category="Cover Positioning", meta=(AllowPrivateAccess="true"))
	FScalableFloat MaximumPathDetourFactor;

	UPROPERTY(EditDefaultsOnly, Category="Cover Positioning", meta=(AllowPrivateAccess="true"))
	FScalableFloat PostCoverCooldownMin;

	UPROPERTY(EditDefaultsOnly, Category="Cover Positioning", meta=(AllowPrivateAccess="true"))
	FScalableFloat PostCoverCooldownMax;

	UPROPERTY(EditDefaultsOnly, Category="Shoot Positioning", meta=(AllowPrivateAccess="true"))
	FScalableFloat CanFindShootingPositionAround;

	UPROPERTY(EditDefaultsOnly, Category="Shoot Positioning", meta=(AllowPrivateAccess="true"))
	FScalableFloat PositioningMaxSearchRadius;

	UPROPERTY(EditDefaultsOnly, Category="Shoot Positioning", meta=(AllowPrivateAccess="true"))
	FScalableFloat PositioningQueryCooldown;

	UPROPERTY(EditDefaultsOnly, Category="Shoot Positioning", meta=(AllowPrivateAccess="true"))
	FScalableFloat PositioningQueryCooldownDeviation;

	UPROPERTY(EditDefaultsOnly, Category="Cover Peek", meta=(AllowPrivateAccess="true"))
	FScalableFloat CoverPeekCountMin;

	UPROPERTY(EditDefaultsOnly, Category="Cover Peek", meta=(AllowPrivateAccess="true"))
	FScalableFloat CoverPeekCountMax;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaAIBotRangeAttackSkillSet", meta=(AllowPrivateAccess="true"))
	FScalableFloat ShotDelayAfterTargetRevived;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaAIBotRangeAttackSkillSet", meta=(AllowPrivateAccess="true"))
	TArray<FFiringPattern> DefaultTargetInAirFiringPatterns;

	UPROPERTY(EditDefaultsOnly, Category="Step Back Behavior", meta=(AllowPrivateAccess="true"))
	FScalableFloat StepBackEnabled;

	UPROPERTY(EditDefaultsOnly, Category="Step Back Behavior", meta=(AllowPrivateAccess="true"))
	FScalableFloat StepBackCooldown;

	UPROPERTY(EditDefaultsOnly, Category="Step Back Behavior", meta=(AllowPrivateAccess="true"))
	FScalableFloat StepBackPercentageChance;

	UPROPERTY(EditDefaultsOnly, Category="Step Back Behavior", meta=(AllowPrivateAccess="true"))
	FScalableFloat StepBackDistanceBetweenAIPawnAndTargetMin;

	UPROPERTY(EditDefaultsOnly, Category="Step Back Behavior", meta=(AllowPrivateAccess="true"))
	FScalableFloat StepBackDistanceBetweenAIPawnAndTargetMax;

	UPROPERTY(EditDefaultsOnly, Category="Step Back Behavior", meta=(AllowPrivateAccess="true"))
	FScalableFloat StepBackDistanceBetweenCoverAndTargetMin;

	UPROPERTY(EditDefaultsOnly, Category="Step Back Behavior", meta=(AllowPrivateAccess="true"))
	FScalableFloat StepBackDistanceBetweenCoverAndTargetMax;

	UPROPERTY(EditDefaultsOnly, Category="Step Back Behavior", meta=(AllowPrivateAccess="true"))
	FScalableFloat StepBackDistanceBetweenAIPawnAndCoverMin;

	UPROPERTY(EditDefaultsOnly, Category="Step Back Behavior", meta=(AllowPrivateAccess="true"))
	FScalableFloat StepBackDistanceBetweenAIPawnAndCoverMax;

	UPROPERTY(EditDefaultsOnly, Category="Flanking Behavior", meta=(AllowPrivateAccess="true"))
	FScalableFloat FlankingEnabled;

	UPROPERTY(EditDefaultsOnly, Category="Flanking Behavior", meta=(AllowPrivateAccess="true"))
	FScalableFloat FlankingCooldown;

	UPROPERTY(EditDefaultsOnly, Category="Flanking Behavior", meta=(AllowPrivateAccess="true"))
	FScalableFloat FlankingPercentageChance;

	UPROPERTY(EditDefaultsOnly, Category="Flanking Behavior", meta=(AllowPrivateAccess="true"))
	FScalableFloat FlankingInnerRadius;

	UPROPERTY(EditDefaultsOnly, Category="Flanking Behavior", meta=(AllowPrivateAccess="true"))
	FScalableFloat FlankingOuterRadius;

	UPROPERTY(EditDefaultsOnly, Category="Flanking Behavior", meta=(AllowPrivateAccess="true"))
	FScalableFloat FlankingLayersCount;

	UPROPERTY(EditDefaultsOnly, Category="Flanking Behavior", meta=(AllowPrivateAccess="true"))
	FScalableFloat FlankingPointsPerLayerCount;

	UPROPERTY(EditDefaultsOnly, Category="Flanking Behavior", meta=(AllowPrivateAccess="true"))
	FScalableFloat FlankingMaxAngle;

	UPROPERTY(EditDefaultsOnly, Category="Flanking Behavior", meta=(AllowPrivateAccess="true"))
	FScalableFloat FlankingScorePawnDetectionRadius;

	UPROPERTY(EditDefaultsOnly, Category="Line of Fire", meta=(AllowPrivateAccess="true", DisplayName="LoF Max Distance To Test"))
	FScalableFloat LoFMaxDistanceToTest;

	UPROPERTY(EditDefaultsOnly, Category="Line of Fire", meta=(AllowPrivateAccess="true", DisplayName="LoF Force Crouch Vehicle Seat ZOffset"))
	FScalableFloat LoFForceCrouchVehicleSeatZOffset;

};

