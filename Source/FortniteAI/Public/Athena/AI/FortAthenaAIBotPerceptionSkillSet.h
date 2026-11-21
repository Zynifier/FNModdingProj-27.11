// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "Athena/AI/FortAthenaAIBotSkillSet.h"
#include "Athena/AI/Perception/AthenaTrapAIPerceptionStimuliSourceComponent.h"
#include "FortAthenaAIBotPerceptionSkillSet.generated.h"

class UAISenseConfig;
class UFortAthenaAIBotAlertLevelConfig;

USTRUCT()
struct FAlertLevelInfo
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TArray<TObjectPtr<UAISenseConfig>> SensesConfig;

};

USTRUCT()
struct FDigestedPerceptionStateSettings
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	float ForgetTime;

	UPROPERTY(Transient)
	float ForgetTimeDeviation;

	UPROPERTY(Transient)
	float ForgetDistance;

	UPROPERTY(Transient)
	float ForgetDistanceDeviation;

};

USTRUCT()
struct FDigestedSightReactionSpecialization
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	FGameplayTagContainer Tags;

	UPROPERTY(Transient)
	FScalableFloat SightMinAdditionTime;

	UPROPERTY(Transient)
	FScalableFloat SightMaxAdditionTime;

};

USTRUCT()
struct FFortAthenaAIBotDigestedTargetHeuristicSettings
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	FDigestedPerceptionStateSettings PerceptionStateSettings[6];

	UPROPERTY(Transient)
	float ThreatDamageWeight;

	UPROPERTY(Transient)
	float ThreatDamageWeightMultiplier;

	UPROPERTY(Transient)
	FScalableFloat ThreatTimeSinceLastDamageMultiplier;

	UPROPERTY(Transient)
	float ThreatLoFWeight;

	UPROPERTY(Transient)
	float DBNOWeightModifier;

	UPROPERTY(Transient)
	float GameParticipantWeightModifier;

};

USTRUCT()
struct FFortAthenaAIBotDigestedTargetHeuristicSettingsSpecialization
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	FGameplayTagQuery TargetTagQuery;

	UPROPERTY(Transient)
	FFortAthenaAIBotDigestedTargetHeuristicSettings Settings;

};

USTRUCT()
struct FPerceptionStateSettings
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="PerceptionSettings", meta=(AllowPrivateAccess="true", ClampMin="0.0", UIMin="0.0"))
	FScalableFloat ForgetTime;

	UPROPERTY(EditDefaultsOnly, Category="PerceptionSettings", meta=(AllowPrivateAccess="true", ClampMin="0.0", UIMin="0.0"))
	FScalableFloat ForgetTimeDeviation;

	UPROPERTY(EditDefaultsOnly, Category="PerceptionSettings", meta=(AllowPrivateAccess="true", ClampMin="0.0", UIMin="0.0"))
	FScalableFloat ForgetDistance;

	UPROPERTY(EditDefaultsOnly, Category="PerceptionSettings", meta=(AllowPrivateAccess="true", ClampMin="0.0", UIMin="0.0"))
	FScalableFloat ForgetDistanceDeviation;

	UPROPERTY(EditDefaultsOnly, Category="PerceptionSettings", meta=(AllowPrivateAccess="true", ClampMin="0.0", UIMin="0.0"))
	FScalableFloat ThreatDistanceWeight;

};

USTRUCT()
struct FFortAthenaAIBotTargetHeuristicSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="PerceptionWeights", meta=(AllowPrivateAccess="true"))
	FPerceptionStateSettings ThreatSeeingPerceptionSettings;

	UPROPERTY(EditDefaultsOnly, Category="PerceptionWeights", meta=(AllowPrivateAccess="true"))
	FPerceptionStateSettings ThreatLKPPerceptionSettings;

	UPROPERTY(EditDefaultsOnly, Category="PerceptionWeights", meta=(AllowPrivateAccess="true"))
	FPerceptionStateSettings ThreatAlertedPerceptionSettings;

	UPROPERTY(EditDefaultsOnly, Category="PerceptionWeights", meta=(AllowPrivateAccess="true", ClampMin="0.0", UIMin="0.0"))
	FScalableFloat ThreatDamageWeight;

	UPROPERTY(EditDefaultsOnly, Category="PerceptionWeights", meta=(AllowPrivateAccess="true", ClampMin="0.0", UIMin="0.0"))
	FScalableFloat ThreatDamageWeightMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="PerceptionWeights", meta=(AllowPrivateAccess="true", ClampMin="0.0", UIMin="0.0"))
	FScalableFloat ThreatTimeSinceLastDamageMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="PerceptionWeights", meta=(AllowPrivateAccess="true", ClampMin="0.0", DisplayName="Has LoF Weight", UIMin="0.0"))
	FScalableFloat ThreatLoFWeight;

	UPROPERTY(EditDefaultsOnly, Category="PerceptionWeights", meta=(AllowPrivateAccess="true", ClampMin="0.0", UIMin="0.0"))
	FScalableFloat DBNOWeightModifier;

	UPROPERTY(EditDefaultsOnly, Category="PerceptionWeights", meta=(AllowPrivateAccess="true", ClampMin="0.0", UIMin="0.0"))
	FScalableFloat GameParticipantWeightModifier;

};

USTRUCT()
struct FFortAthenaAIBotTargetHeuristicSettingsSpecialization
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="PerceptionWeights", meta=(AllowPrivateAccess="true"))
	FGameplayTagQuery TargetTagQuery;

	UPROPERTY(EditDefaultsOnly, Category="PerceptionWeights", meta=(AllowPrivateAccess="true"))
	FFortAthenaAIBotTargetHeuristicSettings Settings;

};

USTRUCT()
struct FSightReactionSpecialization
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="SightReactionSpecialization", meta=(AllowPrivateAccess="true"))
	FGameplayTagContainer Tags;

	UPROPERTY(EditDefaultsOnly, Category="SightReactionSpecialization", meta=(AllowPrivateAccess="true"))
	FScalableFloat SightMinAdditionTime;

	UPROPERTY(EditDefaultsOnly, Category="SightReactionSpecialization", meta=(AllowPrivateAccess="true"))
	FScalableFloat SightMaxAdditionTime;

};

USTRUCT()
struct FSoundPerceptionDigestedSetting
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	float Loudness;

	UPROPERTY(Transient)
	float IgnoreTime;

	UPROPERTY(Transient)
	float OverrideReactionDistanceSq;

};

USTRUCT()
struct FSoundPerceptionSetting
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="SoundSettings", meta=(AllowPrivateAccess="true", ClampMin="0.0", UIMin="0.0"))
	FScalableFloat Loudness;

	UPROPERTY(EditDefaultsOnly, Category="SoundSettings", meta=(AllowPrivateAccess="true", ClampMin="0.0", UIMin="0.0"))
	FScalableFloat IgnoreTime;

	UPROPERTY(EditDefaultsOnly, Category="SoundSettings", meta=(AllowPrivateAccess="true", ClampMin="0.0", UIMin="0.0"))
	FScalableFloat OverrideReactionDistance;

};

UCLASS()
class FORTNITEAI_API UFortAthenaAIBotPerceptionDigestedSkillSet : public UFortAthenaAIBotDigestedSkillSet
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	float SightReactionTime;

	UPROPERTY(Transient)
	float SightRandomDeviation;

	UPROPERTY(Transient)
	TArray<FDigestedSightReactionSpecialization> SightReactionSpecializations;

	UPROPERTY(Transient)
	float LoseSightTime;

	UPROPERTY(Transient)
	float LoseSightRandomDeviation;

	UPROPERTY(Transient)
	float SightSuspicionTime;

	UPROPERTY(Transient)
	float SightSuspicionRandomDeviation;

	UPROPERTY(Transient)
	float EnemyMarkedReactionTime;

	UPROPERTY(Transient)
	float EnemyMarkedReactionRandomDeviation;

	UPROPERTY(Transient)
	float ChancesToHelpOnMarkedEnemy;

	UPROPERTY(Transient)
	float DamageReactionTime;

	UPROPERTY(Transient)
	float DamageRandomDeviation;

	UPROPERTY(Transient)
	float HearingReactionTime;

	UPROPERTY(Transient)
	float HearingRandomDeviation;

	UPROPERTY(Transient)
	float MaxHearingLocationError;

	UPROPERTY(Transient)
	float ObstacleDistanceOverrideTargetingSq;

	UPROPERTY(Transient)
	float ObstacleForgetDistanceSq;

	UPROPERTY(Transient)
	float ObstacleMinimumBlockingTime;

	UPROPERTY(Transient)
	FFortAthenaAIBotDigestedTargetHeuristicSettings DefaultTargetHeuristicSettings;

	UPROPERTY(Transient)
	TArray<FFortAthenaAIBotDigestedTargetHeuristicSettingsSpecialization> TargetHeuristicsSettingsSpecializations;

	UPROPERTY(Transient, meta=(ArraySizeEnum="/Script/FortniteAI.EPerceptionSoundType"))
	FSoundPerceptionDigestedSetting SoundSettings[7];

	UPROPERTY(Transient)
	float AlertedAccumulatedLoudnessLimit;

	UPROPERTY(Transient)
	float AlertedAccumulatedDamageLimit;

	UPROPERTY(Transient)
	float LKPAccumulatedLoudnessLimit;

	UPROPERTY(Transient)
	float EnemyMarkingDelay;

	UPROPERTY(Transient)
	float EnemyMarkingDelayRandomDeviation;

	UPROPERTY(Transient)
	float AdditionalMarkedEnemyLKPForgetTime;

	UPROPERTY(Transient)
	float AdditionalMarkedEnemyLKPForgetDistance;

	UPROPERTY(Transient, meta=(ArraySizeEnum="/Script/FortniteAI.EAlertLevel"))
	FAlertLevelInfo AlertLevelInfos[4];

	UPROPERTY(Transient)
	float ProjectileThreatForgetTime;

	UPROPERTY(Transient)
	FTrapPerceptionSettings TrapPerceptionSettings;

	UPROPERTY(Transient)
	bool bStealthMeterEnable;

	UPROPERTY(Transient)
	float StealthMeterThreshold;

	UPROPERTY(Transient)
	FScalableFloat StealthMeterIncreaseSpeed;

	UPROPERTY(Transient)
	float StealthMeterDecreaseSpeed;

	UPROPERTY(Transient)
	bool bStealthMeterAllowSharedTarget;

	UPROPERTY(Transient)
	bool bStealthMeterForceLKPWhenDamagedAndThreatened;

};

UCLASS()
class FORTNITEAI_API UFortAthenaAIBotPerceptionSkillSet : public UFortAthenaAIBotSkillSet
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Reaction time", meta=(AllowPrivateAccess="true", ClampMin="0.0", UIMin="0.0"))
	FScalableFloat SightReactionTime;

	UPROPERTY(EditDefaultsOnly, Category="Reaction time", meta=(AllowPrivateAccess="true", ClampMin="0.0", UIMin="0.0"))
	FScalableFloat SightRandomDeviation;

	UPROPERTY(EditDefaultsOnly, Category="Reaction time", meta=(AllowPrivateAccess="true", ClampMin="0.0", UIMin="0.0"))
	FScalableFloat SightRandomAddition;

	UPROPERTY(EditDefaultsOnly, Category="Reaction time", meta=(AllowPrivateAccess="true"))
	TArray<FSightReactionSpecialization> SightReactionSpecializations;

	UPROPERTY(EditDefaultsOnly, Category="Reaction time", meta=(AllowPrivateAccess="true", ClampMin="0.0", UIMin="0.0"))
	FScalableFloat LoseSightTime;

	UPROPERTY(EditDefaultsOnly, Category="Reaction time", meta=(AllowPrivateAccess="true", ClampMin="0.0", UIMin="0.0"))
	FScalableFloat LoseSightRandomDeviation;

	UPROPERTY(EditDefaultsOnly, Category="Reaction time", meta=(AllowPrivateAccess="true", ClampMin="0.0", UIMin="0.0"))
	FScalableFloat SightSuspicionTime;

	UPROPERTY(EditDefaultsOnly, Category="Reaction time", meta=(AllowPrivateAccess="true", ClampMin="0.0", UIMin="0.0"))
	FScalableFloat SightSuspicionRandomDeviation;

	UPROPERTY(EditDefaultsOnly, Category="Reaction time", meta=(AllowPrivateAccess="true", ClampMin="0.0", UIMin="0.0"))
	FScalableFloat EnemyMarkedReactionTime;

	UPROPERTY(EditDefaultsOnly, Category="Reaction time", meta=(AllowPrivateAccess="true", ClampMin="0.0", UIMin="0.0"))
	FScalableFloat EnemyMarkedReactionRandomDeviation;

	UPROPERTY(EditDefaultsOnly, Category="Reaction time", meta=(AllowPrivateAccess="true", ClampMin="0.0", UIMin="0.0"))
	FScalableFloat ChancesToHelpOnMarkedEnemy;

	UPROPERTY(EditDefaultsOnly, Category="Reaction time", meta=(AllowPrivateAccess="true", ClampMin="0.0", UIMin="0.0"))
	FScalableFloat DamageReactionTime;

	UPROPERTY(EditDefaultsOnly, Category="Reaction time", meta=(AllowPrivateAccess="true", ClampMin="0.0", UIMin="0.0"))
	FScalableFloat DamageRandomDeviation;

	UPROPERTY(EditDefaultsOnly, Category="Reaction time", meta=(AllowPrivateAccess="true", ClampMin="0.0", UIMin="0.0"))
	FScalableFloat HearingReactionTime;

	UPROPERTY(EditDefaultsOnly, Category="Reaction time", meta=(AllowPrivateAccess="true", ClampMin="0.0", UIMin="0.0"))
	FScalableFloat HearingRandomDeviation;

	UPROPERTY(EditDefaultsOnly, Category="Reaction time", meta=(AllowPrivateAccess="true", ClampMin="0.0", UIMin="0.0"))
	FScalableFloat MaxHearingLocationError;

	UPROPERTY(EditDefaultsOnly, Category="PerceptionWeights", meta=(AllowPrivateAccess="true"))
	FFortAthenaAIBotTargetHeuristicSettings DefaultTargetHeuristicSettings;

	UPROPERTY(EditDefaultsOnly, Category="PerceptionWeights", meta=(AllowPrivateAccess="true"))
	TArray<FFortAthenaAIBotTargetHeuristicSettingsSpecialization> TargetHeuristicSettingsSpecializations;

	UPROPERTY(EditDefaultsOnly, Category="PerceptionWeights", meta=(AllowPrivateAccess="true", ClampMin="0.0", UIMin="0.0"))
	FScalableFloat ObstacleDistanceOverrideTargeting;

	UPROPERTY(EditDefaultsOnly, Category="PerceptionWeights", meta=(AllowPrivateAccess="true", ClampMin="0.0", UIMin="0.0"))
	FScalableFloat ObstacleForgetDistance;

	UPROPERTY(EditDefaultsOnly, Category="PerceptionWeights", meta=(AllowPrivateAccess="true", ClampMin="0.0", UIMin="0.0"))
	FScalableFloat ObstacleMinimumBlockingTime;

	UPROPERTY(EditDefaultsOnly, Category="PerceptionWeights", meta=(AllowPrivateAccess="true", ArraySizeEnum="/Script/FortniteAI.EPerceptionSoundType", ClampMin="0.0", UIMin="0.0"))
	FSoundPerceptionSetting SoundSettings[7];

	UPROPERTY(EditDefaultsOnly, Category="PerceptionWeights", meta=(AllowPrivateAccess="true", ClampMin="0.0", UIMin="0.0"))
	FScalableFloat AlertedAccumulatedLoudnessLimit;

	UPROPERTY(EditDefaultsOnly, Category="PerceptionWeights", meta=(AllowPrivateAccess="true", ClampMin="0.0", UIMin="0.0"))
	FScalableFloat AlertedAccumulatedDamageLimit;

	UPROPERTY(EditDefaultsOnly, Category="PerceptionWeights", meta=(AllowPrivateAccess="true", ClampMin="0.0", UIMin="0.0"))
	FScalableFloat LKPAccumulatedLoudnessLimit;

	UPROPERTY(EditDefaultsOnly, Category="Marking", meta=(AllowPrivateAccess="true", ClampMin="0.0", UIMin="0.0"))
	FScalableFloat EnemyMarkingDelay;

	UPROPERTY(EditDefaultsOnly, Category="Marking", meta=(AllowPrivateAccess="true", ClampMin="0.0", UIMin="0.0"))
	FScalableFloat EnemyMarkingDelayRandomDeviation;

	UPROPERTY(EditDefaultsOnly, Category="Marking", meta=(AllowPrivateAccess="true", ClampMin="0.0", UIMin="0.0"))
	FScalableFloat AdditionalMarkedEnemyLKPForgetTime;

	UPROPERTY(EditDefaultsOnly, Category="Marking", meta=(AllowPrivateAccess="true", ClampMin="0.0", UIMin="0.0"))
	FScalableFloat AdditionalMarkedEnemyLKPForgetDistance;

	UPROPERTY(EditDefaultsOnly, Instanced, Category="AlertLevel", meta=(AllowPrivateAccess="true"))
	TArray<TObjectPtr<UFortAthenaAIBotAlertLevelConfig>> AlertLevelConfigs;

	UPROPERTY(EditDefaultsOnly, Category="Projectiles Threat", meta=(AllowPrivateAccess="true", ClampMin="0.0", UIMin="0.0"))
	FScalableFloat ProjectileThreatForgetTime;

	UPROPERTY(EditDefaultsOnly, Category="Trap Detection", meta=(AllowPrivateAccess="true", ClampMin="0.0", UIMin="0.0"))
	FScalableFloat TrapDetectionDistanceMax;

	UPROPERTY(EditDefaultsOnly, Category="Trap Detection", meta=(AllowPrivateAccess="true", ClampMin="0.0", UIMin="0.0"))
	FScalableFloat TrapDetectionDistanceMaxDeviation;

	UPROPERTY(EditDefaultsOnly, Category="Trap Detection", meta=(AllowPrivateAccess="true", ClampMax="1.0", ClampMin="0.0", UIMax="1.0", UIMin="0.0"))
	FScalableFloat TrapDetectionChanceWhenPerpendicular;

	UPROPERTY(EditDefaultsOnly, Category="Trap Detection", meta=(AllowPrivateAccess="true", ClampMax="1.0", ClampMin="0.0", UIMax="1.0", UIMin="0.0"))
	FScalableFloat TrapDetectionChanceWhenParallel;

	UPROPERTY(EditDefaultsOnly, Category="Trap Detection", meta=(AllowPrivateAccess="true", ClampMin="0.0", UIMin="0.0"))
	FScalableFloat TrapDetectionEvaluationAngleThreshold;

	UPROPERTY(EditDefaultsOnly, Category="Trap Detection", meta=(AllowPrivateAccess="true"))
	FScalableFloat TrapDetectionAutomaticIfWithinCreationTime;

	UPROPERTY(EditDefaultsOnly, Category="Stealth mechanics", meta=(AllowPrivateAccess="true"))
	FScalableFloat StealthMeterEnable;

	UPROPERTY(EditDefaultsOnly, Category="Stealth mechanics", meta=(AllowPrivateAccess="true"))
	FScalableFloat StealthMeterThreshold;

	UPROPERTY(EditDefaultsOnly, Category="Stealth mechanics", meta=(AllowPrivateAccess="true"))
	FScalableFloat StealthMeterIncreaseSpeed;

	UPROPERTY(EditDefaultsOnly, Category="Stealth mechanics", meta=(AllowPrivateAccess="true"))
	FScalableFloat StealthMeterDecreaseSpeed;

	UPROPERTY(EditDefaultsOnly, Category="Stealth mechanics", meta=(AllowPrivateAccess="true"))
	FScalableFloat StealthMeterAllowSharedTarget;

	UPROPERTY(EditDefaultsOnly, Category="Stealth mechanics", meta=(AllowPrivateAccess="true"))
	FScalableFloat bStealthMeterForceLKPWhenDamagedAndThreatened;

};

