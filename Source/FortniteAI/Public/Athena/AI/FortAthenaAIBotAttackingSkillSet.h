// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Athena/AI/FortAthenaAIBotSkillSet.h"
#include "FortAthenaAIBotAttackingSkillSet.generated.h"

USTRUCT()
struct FDigestedMeleeWeaponSkill
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	float IdealAttackDistance;

	UPROPERTY(Transient)
	float IdealAttackDistanceTolerance;

	UPROPERTY(Transient)
	float MinCooldownDelayBetweenMeleeAttackAttempts;

	UPROPERTY(Transient)
	float MaxCooldownDelayBetweenMeleeAttackAttempts;

};

USTRUCT()
struct FDigestedMeleeWeaponSkillCategory
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	FGameplayTagContainer Tags;

	UPROPERTY(Transient)
	FDigestedMeleeWeaponSkill WeaponSkill;

};

USTRUCT()
struct FMeleeWeaponSkill
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="MeleeWeaponSkill", meta=(AllowPrivateAccess="true"))
	FScalableFloat IdealAttackDistance;

	UPROPERTY(EditDefaultsOnly, Category="MeleeWeaponSkill", meta=(AllowPrivateAccess="true"))
	FScalableFloat IdealAttackDistanceTolerance;

	UPROPERTY(EditDefaultsOnly, Category="MeleeWeaponSkill", meta=(AllowPrivateAccess="true"))
	FScalableFloat MinCooldownDelayBetweenMeleeAttackAttempts;

	UPROPERTY(EditDefaultsOnly, Category="MeleeWeaponSkill", meta=(AllowPrivateAccess="true"))
	FScalableFloat MaxCooldownDelayBetweenMeleeAttackAttempts;

};

USTRUCT()
struct FMeleeWeaponSkillCategory
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="MeleeWeaponSkillCategory", meta=(AllowPrivateAccess="true", DisplayName="Category Tags"))
	FGameplayTagContainer Tags;

	UPROPERTY(EditDefaultsOnly, Category="MeleeWeaponSkillCategory", meta=(AllowPrivateAccess="true", DisplayName="Category Skill Set"))
	FMeleeWeaponSkill WeaponSkill;

};

UCLASS(MinimalAPI)
class UFortAthenaAIBotAttackingDigestedSkillSet : public UFortAthenaAIBotDigestedSkillSet
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	TArray<FDigestedMeleeWeaponSkillCategory> MeleeWeaponCategorySkills;

	UPROPERTY(Transient)
	float MaxDistanceToThrowMeleeAttackSq;

	UPROPERTY(Transient)
	float ExcludeReachingTargetInMeleeTime;

	UPROPERTY(Transient)
	float ExcludeReachingTargetMoveDistanceSquared;

	UPROPERTY(Transient)
	FGameplayTagQuery ContinousMeleeAttackTagQuery;

	UPROPERTY(Transient)
	bool bOnlyEngageMeleeAgainstThreatThatHasNoRangeWeapon;

	UPROPERTY(Transient)
	bool bOnlyUsePickaxeAgainstGameParticipants;

	UPROPERTY(Transient)
	float MaxDistanceToConsiderAsAnAlternateTargetSq;

	UPROPERTY(Transient)
	bool bEnableAlternateTargetRequiredTags;

	UPROPERTY(Transient)
	FGameplayTagContainer AlternateTargetRequiredTags;

	UPROPERTY(Transient)
	bool bEnableWTFBehavior;

	UPROPERTY(Transient)
	float MinCooldownDelayBetweenMeleeAttackAttempts;

	UPROPERTY(Transient)
	float MaxCooldownDelayBetweenMeleeAttackAttempts;

	UPROPERTY(Transient)
	FGameplayTagContainer ThrowableGameplayTags;

	UPROPERTY(Transient)
	FGameplayTagQuery CombatMeleeTagQuery;

	UPROPERTY(Transient)
	bool bPreventMeleeOutsideLeash;

	UPROPERTY(Transient)
	int32 MinThrowableCount;

	UPROPERTY(Transient)
	int32 MaxThrowableCount;

	UPROPERTY(Transient)
	float ThrowableCooldownMin;

	UPROPERTY(Transient)
	float ThrowableCooldownMax;

	UPROPERTY(Transient)
	bool bKeepThrowableEquippedDuringCooldown;

	UPROPERTY(Transient)
	float ThrowableMinimumRangeSquared;

	UPROPERTY(Transient)
	bool bThrowableEvaluatorActive;

	UPROPERTY(Transient)
	float RetreatMinHealthRange;

	UPROPERTY(Transient)
	float RetreatMaxHealthRange;

	UPROPERTY(Transient)
	float RetreatProbability;

	UPROPERTY(Transient)
	float RetreatRangeMinSquared;

	UPROPERTY(Transient)
	float RetreatRangeMaxSquared;

	UPROPERTY(Transient)
	float RetreatMaxDuration;

	UPROPERTY(Transient)
	FVector RetreatPositionBoxExtent;

	UPROPERTY(Transient)
	bool CautiousInvestigationEnabled;

	UPROPERTY(Transient)
	float TimeSinceLastStimToBeCautious;

	UPROPERTY(Transient)
	float CautiousInvestigationTimeMax;

};

UCLASS(MinimalAPI)
class UFortAthenaAIBotAttackingSkillSet : public UFortAthenaAIBotSkillSet
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Melee Weapon", meta=(AllowPrivateAccess="true", TitleProperty="Tags"))
	TArray<FMeleeWeaponSkillCategory> MeleeWeaponSkills;

	UPROPERTY(EditDefaultsOnly, Category="Melee", meta=(AllowPrivateAccess="true"))
	FScalableFloat MaxDistanceToThrowMeleeAttack;

	UPROPERTY(EditDefaultsOnly, Category="Melee", meta=(AllowPrivateAccess="true"))
	FGameplayTagQuery ContinousMeleeAttackTagQuery;

	UPROPERTY(EditDefaultsOnly, Category="Melee", meta=(AllowPrivateAccess="true"))
	FScalableFloat OnlyEngageMeleeAgainstThreatThatHasNoRangeWeapon;

	UPROPERTY(EditDefaultsOnly, Category="Melee", meta=(AllowPrivateAccess="true"))
	FScalableFloat OnlyUsePickaxeAgainstGameParticipants;

	UPROPERTY(EditDefaultsOnly, Category="Melee", meta=(AllowPrivateAccess="true"))
	FScalableFloat EnableWTFBehavior;

	UPROPERTY(EditDefaultsOnly, Category="Melee", meta=(AllowPrivateAccess="true"))
	FScalableFloat MinCooldownDelayBetweenMeleeAttackAttempts;

	UPROPERTY(EditDefaultsOnly, Category="Melee", meta=(AllowPrivateAccess="true"))
	FScalableFloat MaxCooldownDelayBetweenMeleeAttackAttempts;

	UPROPERTY(EditDefaultsOnly, Category="Melee", meta=(AllowPriveAccess="true"))
	FGameplayTagQuery CombatMeleeTagQuery;

	UPROPERTY(EditDefaultsOnly, Category="Melee", meta=(AllowPrivateAccess="true"))
	FScalableFloat ExcludeReachingTargetInMeleeTime;

	UPROPERTY(EditDefaultsOnly, Category="Melee", meta=(AllowPrivateAccess="true"))
	FScalableFloat ExcludeReachingTargetMoveDistance;

	UPROPERTY(EditDefaultsOnly, Category="Melee", meta=(AllowPrivateAccess="true"))
	FScalableFloat PreventMeleeOutsideLeash;

	UPROPERTY(EditDefaultsOnly, Category="Range", meta=(AllowPrivateAccess="true"))
	FScalableFloat MaxDistanceToConsiderAsAnAlternateTarget;

	UPROPERTY(EditDefaultsOnly, Category="Range", meta=(AllowPrivateAccess="true"))
	FScalableFloat EnableAlternateTargetRequiredTags;

	UPROPERTY(EditDefaultsOnly, Category="Range", meta=(AllowPriveAccess="true"))
	FGameplayTagContainer AlternateTargetRequiredTags;

	UPROPERTY(EditDefaultsOnly, Category="Throwable", meta=(AllowPrivateAccess="true"))
	FGameplayTagContainer ThrowableGameplayTags;

	UPROPERTY(EditDefaultsOnly, Category="Throwable", meta=(AllowPrivateAccess="true"))
	FScalableFloat MinThrowableCount;

	UPROPERTY(EditDefaultsOnly, Category="Throwable", meta=(AllowPrivateAccess="true"))
	FScalableFloat MaxThrowableCount;

	UPROPERTY(EditDefaultsOnly, Category="Throwable", meta=(AllowPrivateAccess="true"))
	FScalableFloat ThrowableCooldownMin;

	UPROPERTY(EditDefaultsOnly, Category="Throwable", meta=(AllowPrivateAccess="true"))
	FScalableFloat ThrowableCooldownMax;

	UPROPERTY(EditDefaultsOnly, Category="Throwable", meta=(AllowPrivateAccess="true"))
	FScalableFloat KeepThrowableEquippedDuringCooldown;

	UPROPERTY(EditDefaultsOnly, Category="Throwable", meta=(AllowPrivateAccess="true"))
	FScalableFloat ThrowableMinimumRange;

	UPROPERTY(EditDefaultsOnly, Category="Throwable", meta=(AllowPrivateAccess="true"))
	FScalableFloat ThrowableEvaluatorActive;

	UPROPERTY(EditDefaultsOnly, Category="Retreat", meta=(AllowPrivateAccess="true"))
	FScalableFloat RetreatMinHealthRange;

	UPROPERTY(EditDefaultsOnly, Category="Retreat", meta=(AllowPrivateAccess="true"))
	FScalableFloat RetreatMaxHealthRange;

	UPROPERTY(EditDefaultsOnly, Category="Retreat", meta=(AllowPrivateAccess="true"))
	FScalableFloat RetreatProbability;

	UPROPERTY(EditDefaultsOnly, Category="Retreat", meta=(AllowPrivateAccess="true"))
	FScalableFloat RetreatRangeMin;

	UPROPERTY(EditDefaultsOnly, Category="Retreat", meta=(AllowPrivateAccess="true"))
	FScalableFloat RetreatRangeMax;

	UPROPERTY(EditDefaultsOnly, Category="Retreat", meta=(AllowPrivateAccess="true"))
	FScalableFloat RetreatMaxDuration;

	UPROPERTY(EditDefaultsOnly, Category="Retreat", meta=(AllowPrivateAccess="true"))
	FVector RetreatPositionBoxExtent;

	UPROPERTY(EditDefaultsOnly, Category="Investigate", meta=(AllowPrivateAccess="true"))
	FScalableFloat CautiousInvestigationEnabled;

	UPROPERTY(EditDefaultsOnly, Category="Investigate", meta=(AllowPrivateAccess="true"))
	FScalableFloat TimeSinceLastStimToBeCautious;

	UPROPERTY(EditDefaultsOnly, Category="Investigate", meta=(AllowPrivateAccess="true"))
	FScalableFloat CautiousInvestigationTimeMax;

};

