// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Athena/AI/FortAthenaAIBotSkillSet.h"
#include "FortAthenaAIBotMovementSkillSet.generated.h"

USTRUCT()
struct FBotKnockbackSettings
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="BotKnockbackSettings", meta=(AllowPrivateAccess="true"))
	FGameplayTagQuery TagQuery;

	UPROPERTY(EditAnywhere, Category="BotKnockbackSettings", meta=(AllowPrivateAccess="true"))
	FScalableFloat ShouldAllowCharacterToBeLaunched;

	UPROPERTY(EditAnywhere, Category="BotKnockbackSettings", meta=(AllowPrivateAccess="true"))
	FScalableFloat ShouldStopActiveMovement;

	UPROPERTY(EditAnywhere, Category="BotKnockbackSettings", meta=(AllowPrivateAccess="true"))
	FScalableFloat IgnoreMoveInputDuration;

};

USTRUCT()
struct FDigestedBotKnockbackSettings
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	FGameplayTagQuery TagQuery;

	UPROPERTY(Transient)
	bool bShouldAllowCharacterToBeLaunched;

	UPROPERTY(Transient)
	bool bShouldStopActiveMovement;

	UPROPERTY(Transient)
	float IgnoreMoveInputDuration;

};

UCLASS(MinimalAPI)
class UFortAthenaAIBotMovementDigestedSkillSet : public UFortAthenaAIBotDigestedSkillSet
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	float SlowDownDistanceSquared;

	UPROPERTY(Transient)
	float TraversalSpeedEstimation;

	UPROPERTY(Transient)
	float TraversalSpeedEstimationWithThreat;

	UPROPERTY(Transient)
	bool bOffPathDetectionEnabled;

	UPROPERTY(Transient)
	float OffPathDistanceThresholdSquared;

	UPROPERTY(Transient)
	float GliderDeployMinAngle;

	UPROPERTY(Transient)
	float GliderDeployMaxAngle;

	UPROPERTY(Transient)
	float GliderNoiseMinDistance;

	UPROPERTY(Transient)
	float GliderNoiseMaxDistance;

	UPROPERTY(Transient)
	float GliderNoiseMinDelay;

	UPROPERTY(Transient)
	float GliderNoiseMaxDelay;

	UPROPERTY(Transient)
	float GliderNoiseDistanceTreshold;

	UPROPERTY(Transient)
	float GliderStopRotationDistance;

	UPROPERTY(Transient)
	float GliderLandingDistance;

	UPROPERTY(Transient)
	float GliderRotationLerpDuration;

	UPROPERTY(Transient)
	bool GliderBehaviorEnableFlag;

	UPROPERTY(Transient)
	float GliderBehaviorMinInterval;

	UPROPERTY(Transient)
	float GliderBehaviorMaxInterval;

	UPROPERTY(Transient)
	float GliderBehaviorMinRadius;

	UPROPERTY(Transient)
	float GliderBehaviorMaxRadius;

	UPROPERTY(Transient)
	float GliderBehaviorSurveyProbability;

	UPROPERTY(Transient)
	bool GliderMovementTypeEnableFlag;

	UPROPERTY(Transient)
	float GliderLinearProbability;

	UPROPERTY(Transient)
	float GliderSpiralMinRadius;

	UPROPERTY(Transient)
	float GliderSpiralMaxRadius;

	UPROPERTY(Transient)
	float GliderSpiralMinAngle;

	UPROPERTY(Transient)
	float GliderSpiralMaxAngle;

	UPROPERTY(Transient)
	float GliderSpiralMinInterval;

	UPROPERTY(Transient)
	float GliderSpiralMaxInterval;

	UPROPERTY(Transient)
	float GliderSpiralProbability;

	UPROPERTY(Transient)
	float GliderSerpentineMinAngle;

	UPROPERTY(Transient)
	float GliderSerpentineMaxAngle;

	UPROPERTY(Transient)
	float GliderSerpentineMinRadius;

	UPROPERTY(Transient)
	float GliderSerpentineMaxRadius;

	UPROPERTY(Transient)
	float GliderSerpentineMinInterval;

	UPROPERTY(Transient)
	float GliderSerpentineMaxInterval;

	UPROPERTY(Transient)
	float GliderSerpentineMinPeriod;

	UPROPERTY(Transient)
	float GliderSerpentineMaxPeriod;

	UPROPERTY(Transient)
	float GliderSerpentineProbability;

	UPROPERTY(Transient)
	float JumpOffMinAngle;

	UPROPERTY(Transient)
	float JumpOffMaxAngle;

	UPROPERTY(Transient)
	float MinPatrolDistance;

	UPROPERTY(Transient)
	float MaxPatrolDistance;

	UPROPERTY(Transient)
	float MaxPatrolDistanceRandomDeviation;

	UPROPERTY(Transient)
	float WobbleProbability;

	UPROPERTY(Transient)
	float MaxDelayBetweenWobblingMovement;

	UPROPERTY(Transient)
	float MaxDelayBetweenWobblingMovementRandomDeviation;

	UPROPERTY(Transient)
	bool bAllowSwimWobble;

	UPROPERTY(Transient)
	float MaxWobblingDuration;

	UPROPERTY(Transient)
	float MaxWobblingDurationRandomDeviation;

	UPROPERTY(Transient)
	float MaxWobblingIntensity;

	UPROPERTY(Transient)
	float WobblingIntensityDeviation;

	UPROPERTY(Transient)
	float MaxWobblingFrequency;

	UPROPERTY(Transient)
	float WobblingFrequencyDeviation;

	UPROPERTY(Transient)
	float WobblingStickToPathCorridorStrength;

	UPROPERTY(Transient)
	float MaxAfterLaunchedPauseTime;

	UPROPERTY(Transient)
	float MaxAfterLaunchedFromVortexPauseTime;

	UPROPERTY(Transient)
	float AfterLaunchedPauseTimeDeviation;

	UPROPERTY(Transient)
	bool bSteerMovementWhenLaunched;

	UPROPERTY(Transient)
	float SteerMovementWhenLaunchedDirectionUpdateTime;

	UPROPERTY(Transient)
	float MaxReactionTimeToDangerZone;

	UPROPERTY(Transient)
	float MaxReactionTimeToDangerZoneDeviation;

	UPROPERTY(Transient)
	bool bLimitBlockingObstacleAngle;

	UPROPERTY(Transient)
	bool bShouldAutoJumpOverBlockingObstacles;

	UPROPERTY(Transient)
	bool bEnableSwimSprintJump;

	UPROPERTY(Transient)
	float SwimSprintJumpDelay;

	UPROPERTY(Transient)
	float SwimSprintJumpDelayDeviation;

	UPROPERTY(Transient)
	float SwimUnblockJumpHeightThreshold;

	UPROPERTY(Transient)
	bool bSwimSprintJumpNav2D;

	UPROPERTY(Transient)
	float TacticalSprintEvaluationMinTime;

	UPROPERTY(Transient)
	float TacticalSprintEvaluationMaxTime;

	UPROPERTY(Transient)
	float TacticalSprintMinTriggerChance;

	UPROPERTY(Transient)
	float TacticalSprintMaxTriggerChance;

	UPROPERTY(Transient)
	float TacticalSprintMinTriggerChanceInUrgentMovement;

	UPROPERTY(Transient)
	float TacticalSprintMaxTriggerChanceInUrgentMovement;

	UPROPERTY(Transient)
	float TacticalSprintMaxSlopeAngle;

	UPROPERTY(Transient)
	float TacticalSprintMinPathTargetDistance;

	UPROPERTY(Transient)
	float TacticalSprintMaxPathAlignmentAngle;

	UPROPERTY(Transient)
	float TacticalSprintMaxPathConeAngle;

	UPROPERTY(Transient)
	float TacticalSprintPathConeRearOffset;

	UPROPERTY(Transient)
	bool TacticalSprintUsageEnabled;

	UPROPERTY(Transient)
	float TacticalSprintJumpTriggerChance;

	UPROPERTY(Transient)
	float TacticalSprintJumpDelay;

	UPROPERTY(Transient)
	float TacticalSprintJumpDelayDeviation;

	UPROPERTY(Transient)
	float TacticalSprintJumpDelayInitialRatio;

	UPROPERTY(Transient)
	FVector SlidingBoxExtent;

	UPROPERTY(Transient, meta=(ArraySizeEnum="/Script/FortniteAI.EAlertLevel"))
	float SlidingEnabled[4];

	UPROPERTY(Transient)
	float SlidingEvaluationMinTime;

	UPROPERTY(Transient)
	float SlidingEvaluationMaxTime;

	UPROPERTY(Transient)
	float SlidingTriggerChanceStyleMalus;

	UPROPERTY(Transient)
	float SlidingTriggerChanceStyleMalusRandomDeviation;

	UPROPERTY(Transient)
	float SlidingTriggerChanceFlat;

	UPROPERTY(Transient)
	float SlidingTriggerChanceLittleSlope;

	UPROPERTY(Transient)
	float SlidingTriggerChanceSteepSlope;

	UPROPERTY(Transient)
	float SlidingDuringUrgentMovementTriggerChanceFlat;

	UPROPERTY(Transient)
	float SlidingDuringUrgentMovementTriggerChanceLittleSlope;

	UPROPERTY(Transient)
	float SlidingDuringUrgentMovementTriggerChanceSteepSlope;

	UPROPERTY(Transient)
	float MinSlidingDuration;

	UPROPERTY(Transient)
	float SlidingCooldownMinTime;

	UPROPERTY(Transient)
	float SlidingCooldownMaxTime;

	UPROPERTY(Transient)
	float SlidingStopMinDelay;

	UPROPERTY(Transient)
	float SlidingStopMaxDelay;

	UPROPERTY(Transient)
	float SlidingMaxPathConeAngle;

	UPROPERTY(Transient)
	float SlidingMinPathTargetDistance;

	UPROPERTY(Transient)
	float SlidingAllowResumeFocusOnTargetTriggerChance;

	UPROPERTY(Transient)
	float MoveToRangeAttackMinOffset;

	UPROPERTY(Transient)
	float MoveToRangeAttackMaxOffset;

	UPROPERTY(Transient)
	float LKPMinOffset;

	UPROPERTY(Transient)
	float LKPMaxOffset;

	UPROPERTY(Transient)
	bool bInvestigateAllowSearch;

	UPROPERTY(Transient)
	float InvestigateWaitMinTime;

	UPROPERTY(Transient)
	float InvestigateWaitMaxTime;

	UPROPERTY(Transient)
	float InvestigateSearchMinDistance;

	UPROPERTY(Transient)
	float InvestigateSearchMaxDistance;

	UPROPERTY(Transient)
	float SandTunnelJumpMinTime;

	UPROPERTY(Transient)
	float SandTunnelJumpMaxTime;

	UPROPERTY(Transient)
	float SandTunnelBurrowedAndHiddenChance;

	UPROPERTY(Transient)
	float SandTunnelBurrowedAndHiddenMinTime;

	UPROPERTY(Transient)
	float SandTunnelBurrowedAndHiddenMaxTime;

	UPROPERTY(Transient)
	FVector ZiplineOctreeBoxExtent;

	UPROPERTY(Transient)
	float ThresholdDistanceToRescanForZiplines;

	UPROPERTY(Transient)
	float CooldownBetweenZiplineUsages;

	UPROPERTY(Transient)
	float DistanceToAddToZiplineStartPosition;

	UPROPERTY(Transient)
	float RadiusFromZiplineEnterPointToLookAtExit;

	UPROPERTY(Transient)
	bool ZiplineUsageEnabled;

	UPROPERTY(Transient)
	bool bCanOpenDoors;

	UPROPERTY(Transient)
	FDigestedBotKnockbackSettings DefaultKnockbackSettings;

	UPROPERTY(Transient)
	TArray<FDigestedBotKnockbackSettings> KnockbackSettingsSpecializations;

};

UCLASS(MinimalAPI)
class UFortAthenaAIBotMovementSkillSet : public UFortAthenaAIBotSkillSet
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Navigation", meta=(AllowPrivateAccess="true"))
	FScalableFloat SlowDownDistance;

	UPROPERTY(EditDefaultsOnly, Category="Navigation", meta=(AllowPrivateAccess="true"))
	FScalableFloat TraversalSpeedEstimation;

	UPROPERTY(EditDefaultsOnly, Category="Navigation", meta=(AllowPrivateAccess="true"))
	FScalableFloat TraversalSpeedEstimationWithThreat;

	UPROPERTY(EditDefaultsOnly, Category="Navigation", meta=(AllowPrivateAccess="true"))
	FScalableFloat OffPathDetectionEnabled;

	UPROPERTY(EditDefaultsOnly, Category="Navigation", meta=(AllowPrivateAccess="true"))
	FScalableFloat OffPathDistanceThreshold;

	UPROPERTY(EditDefaultsOnly, Category="Navigation - Glider", meta=(AllowPrivateAccess="true"))
	FScalableFloat GliderDeployMinAngle;

	UPROPERTY(EditDefaultsOnly, Category="Navigation - Glider", meta=(AllowPrivateAccess="true"))
	FScalableFloat GliderDeployMaxAngle;

	UPROPERTY(EditDefaultsOnly, Category="Navigation - Glider", meta=(AllowPrivateAccess="true"))
	FScalableFloat GliderNoiseMinDistance;

	UPROPERTY(EditDefaultsOnly, Category="Navigation - Glider", meta=(AllowPrivateAccess="true"))
	FScalableFloat GliderNoiseMaxDistance;

	UPROPERTY(EditDefaultsOnly, Category="Navigation - Glider", meta=(AllowPrivateAccess="true"))
	FScalableFloat GliderNoiseMinDelay;

	UPROPERTY(EditDefaultsOnly, Category="Navigation - Glider", meta=(AllowPrivateAccess="true"))
	FScalableFloat GliderNoiseMaxDelay;

	UPROPERTY(EditDefaultsOnly, Category="Navigation - Glider", meta=(AllowPrivateAccess="true"))
	FScalableFloat GliderNoiseDistanceTreshold;

	UPROPERTY(EditDefaultsOnly, Category="Navigation - Glider", meta=(AllowPrivateAccess="true"))
	FScalableFloat GliderStopRotationDistance;

	UPROPERTY(EditDefaultsOnly, Category="Navigation - Glider", meta=(AllowPrivateAccess="true"))
	FScalableFloat GliderLandingDistance;

	UPROPERTY(EditDefaultsOnly, Category="Navigation - Glider", meta=(AllowPrivateAccess="true"))
	FScalableFloat GliderRotationLerpDuration;

	UPROPERTY(EditDefaultsOnly, Category="Navigation - Glider", meta=(AllowPrivateAccess="true"))
	FScalableFloat GliderBehaviorEnableFlag;

	UPROPERTY(EditDefaultsOnly, Category="Navigation - Glider", meta=(AllowPrivateAccess="true"))
	FScalableFloat GliderBehaviorMinInterval;

	UPROPERTY(EditDefaultsOnly, Category="Navigation - Glider", meta=(AllowPrivateAccess="true"))
	FScalableFloat GliderBehaviorMaxInterval;

	UPROPERTY(EditDefaultsOnly, Category="Navigation - Glider", meta=(AllowPrivateAccess="true"))
	FScalableFloat GliderBehaviorMinRadius;

	UPROPERTY(EditDefaultsOnly, Category="Navigation - Glider", meta=(AllowPrivateAccess="true"))
	FScalableFloat GliderBehaviorMaxRadius;

	UPROPERTY(EditDefaultsOnly, Category="Navigation - Glider", meta=(AllowPrivateAccess="true"))
	FScalableFloat GliderBehaviorSurveyProbability;

	UPROPERTY(EditDefaultsOnly, Category="Navigation - Glider", meta=(AllowPrivateAccess="true"))
	FScalableFloat GliderMovementTypeEnableFlag;

	UPROPERTY(EditDefaultsOnly, Category="Navigation - Glider", meta=(AllowPrivateAccess="true"))
	FScalableFloat GliderLinearProbability;

	UPROPERTY(EditDefaultsOnly, Category="Navigation - Glider", meta=(AllowPrivateAccess="true"))
	FScalableFloat GliderSpiralMinRadius;

	UPROPERTY(EditDefaultsOnly, Category="Navigation - Glider", meta=(AllowPrivateAccess="true"))
	FScalableFloat GliderSpiralMaxRadius;

	UPROPERTY(EditDefaultsOnly, Category="Navigation - Glider", meta=(AllowPrivateAccess="true"))
	FScalableFloat GliderSpiralMinAngle;

	UPROPERTY(EditDefaultsOnly, Category="Navigation - Glider", meta=(AllowPrivateAccess="true"))
	FScalableFloat GliderSpiralMaxAngle;

	UPROPERTY(EditDefaultsOnly, Category="Navigation - Glider", meta=(AllowPrivateAccess="true"))
	FScalableFloat GliderSpiralMinInterval;

	UPROPERTY(EditDefaultsOnly, Category="Navigation - Glider", meta=(AllowPrivateAccess="true"))
	FScalableFloat GliderSpiralMaxInterval;

	UPROPERTY(EditDefaultsOnly, Category="Navigation - Glider", meta=(AllowPrivateAccess="true"))
	FScalableFloat GliderSpiralProbability;

	UPROPERTY(EditDefaultsOnly, Category="Navigation - Glider", meta=(AllowPrivateAccess="true"))
	FScalableFloat GliderSerpentineMinAngle;

	UPROPERTY(EditDefaultsOnly, Category="Navigation - Glider", meta=(AllowPrivateAccess="true"))
	FScalableFloat GliderSerpentineMaxAngle;

	UPROPERTY(EditDefaultsOnly, Category="Navigation - Glider", meta=(AllowPrivateAccess="true"))
	FScalableFloat GliderSerpentineMinRadius;

	UPROPERTY(EditDefaultsOnly, Category="Navigation - Glider", meta=(AllowPrivateAccess="true"))
	FScalableFloat GliderSerpentineMaxRadius;

	UPROPERTY(EditDefaultsOnly, Category="Navigation - Glider", meta=(AllowPrivateAccess="true"))
	FScalableFloat GliderSerpentineMinInterval;

	UPROPERTY(EditDefaultsOnly, Category="Navigation - Glider", meta=(AllowPrivateAccess="true"))
	FScalableFloat GliderSerpentineMaxInterval;

	UPROPERTY(EditDefaultsOnly, Category="Navigation - Glider", meta=(AllowPrivateAccess="true"))
	FScalableFloat GliderSerpentineMinPeriod;

	UPROPERTY(EditDefaultsOnly, Category="Navigation - Glider", meta=(AllowPrivateAccess="true"))
	FScalableFloat GliderSerpentineMaxPeriod;

	UPROPERTY(EditDefaultsOnly, Category="Navigation - Glider", meta=(AllowPrivateAccess="true"))
	FScalableFloat GliderSerpentineProbability;

	UPROPERTY(EditDefaultsOnly, Category="Navigation", meta=(AllowPrivateAccess="true"))
	FScalableFloat JumpOffMinAngle;

	UPROPERTY(EditDefaultsOnly, Category="Navigation", meta=(AllowPrivateAccess="true"))
	FScalableFloat JumpOffMaxAngle;

	UPROPERTY(EditDefaultsOnly, Category="Navigation", meta=(AllowPrivateAccess="true"))
	FScalableFloat MinPatrolDistance;

	UPROPERTY(EditDefaultsOnly, Category="Navigation", meta=(AllowPrivateAccess="true"))
	FScalableFloat MaxPatrolDistance;

	UPROPERTY(EditDefaultsOnly, Category="Navigation", meta=(AllowPrivateAccess="true"))
	FScalableFloat MaxPatrolDistanceRandomDeviation;

	UPROPERTY(EditDefaultsOnly, Category="Navigation", meta=(AllowPrivateAccess="true"))
	FScalableFloat MoveToRangeAttackMinOffset;

	UPROPERTY(EditDefaultsOnly, Category="Navigation", meta=(AllowPrivateAccess="true"))
	FScalableFloat MoveToRangeAttackMaxOffset;

	UPROPERTY(EditDefaultsOnly, Category="Navigation", meta=(AllowPrivateAccess="true"))
	FScalableFloat LKPMinOffset;

	UPROPERTY(EditDefaultsOnly, Category="Navigation", meta=(AllowPrivateAccess="true"))
	FScalableFloat LKPMaxOffset;

	UPROPERTY(EditDefaultsOnly, Category="Navigation - Investigate", meta=(AllowPrivateAccess="true"))
	FScalableFloat bInvestigateAllowSearch;

	UPROPERTY(EditDefaultsOnly, Category="Navigation - Investigate", meta=(AllowPrivateAccess="true"))
	FScalableFloat InvestigateWaitMinTime;

	UPROPERTY(EditDefaultsOnly, Category="Navigation - Investigate", meta=(AllowPrivateAccess="true"))
	FScalableFloat InvestigateWaitMaxTime;

	UPROPERTY(EditDefaultsOnly, Category="Navigation - Investigate", meta=(AllowPrivateAccess="true"))
	FScalableFloat InvestigateSearchMinDistance;

	UPROPERTY(EditDefaultsOnly, Category="Navigation - Investigate", meta=(AllowPrivateAccess="true"))
	FScalableFloat InvestigateSearchMaxDistance;

	UPROPERTY(EditDefaultsOnly, Category="Navigation - Sand Tunnel", meta=(AllowPrivateAccess="true"))
	FScalableFloat SandTunnelJumpMinTime;

	UPROPERTY(EditDefaultsOnly, Category="Navigation - Sand Tunnel", meta=(AllowPrivateAccess="true"))
	FScalableFloat SandTunnelJumpMaxTime;

	UPROPERTY(EditDefaultsOnly, Category="Navigation - Sand Tunnel", meta=(AllowPrivateAccess="true"))
	FScalableFloat SandTunnelBurrowedAndHiddenChance;

	UPROPERTY(EditDefaultsOnly, Category="Navigation - Sand Tunnel", meta=(AllowPrivateAccess="true"))
	FScalableFloat SandTunnelBurrowedAndHiddenMinTime;

	UPROPERTY(EditDefaultsOnly, Category="Navigation - Sand Tunnel", meta=(AllowPrivateAccess="true"))
	FScalableFloat SandTunnelBurrowedAndHiddenMaxTime;

	UPROPERTY(EditDefaultsOnly, Category="Navigation - Wobbling Probability", meta=(AllowPrivateAccess="true"))
	FScalableFloat WobblingProbability;

	UPROPERTY(EditDefaultsOnly, Category="Navigation - Wobbling Timing", meta=(AllowPrivateAccess="true"))
	FScalableFloat MaxDelayBetweenWobblingMovement;

	UPROPERTY(EditDefaultsOnly, Category="Navigation - Wobbling Timing", meta=(AllowPrivateAccess="true"))
	FScalableFloat MaxDelayBetweenWobblingMovementRandomDeviation;

	UPROPERTY(EditDefaultsOnly, Category="Navigation - Wobbling Timing", meta=(AllowPrivateAccess="true"))
	FScalableFloat MaxWobblingDuration;

	UPROPERTY(EditDefaultsOnly, Category="Navigation - Wobbling Timing", meta=(AllowPrivateAccess="true"))
	FScalableFloat MaxWobblingDurationRandomDeviation;

	UPROPERTY(EditDefaultsOnly, Category="Navigation - Wobbling Behavior", meta=(AllowPrivateAccess="true"))
	FScalableFloat MaxWobblingIntensity;

	UPROPERTY(EditDefaultsOnly, Category="Navigation - Wobbling Behavior", meta=(AllowPrivateAccess="true"))
	FScalableFloat WobblingIntensityDeviation;

	UPROPERTY(EditDefaultsOnly, Category="Navigation - Wobbling Behavior", meta=(AllowPrivateAccess="true"))
	FScalableFloat MaxWobblingFrequency;

	UPROPERTY(EditDefaultsOnly, Category="Navigation - Wobbling Behavior", meta=(AllowPrivateAccess="true"))
	FScalableFloat WobblingFrequencyDeviation;

	UPROPERTY(EditDefaultsOnly, Category="Navigation - Wobbling Behavior", meta=(AllowPrivateAccess="true"))
	FScalableFloat WobblingStickToPathCorridorStrength;

	UPROPERTY(EditDefaultsOnly, Category="Navigation - Obstacle", meta=(AllowPrivateAccess="true"))
	FScalableFloat LimitBlockingObstacleAngle;

	UPROPERTY(EditDefaultsOnly, Category="Navigation - Obstacle", meta=(AllowPrivateAccess="true"))
	FScalableFloat AutoJumpOverBlockingObstacles;

	UPROPERTY(EditDefaultsOnly, Category="Launched", meta=(AllowPrivateAccess="true"))
	FScalableFloat MaxAfterLaunchedPauseTime;

	UPROPERTY(EditDefaultsOnly, Category="Launched", meta=(AllowPrivateAccess="true"))
	FScalableFloat MaxAfterLaunchedFromVortexPauseTime;

	UPROPERTY(EditDefaultsOnly, Category="Launched", meta=(AllowPrivateAccess="true"))
	FScalableFloat AfterLaunchedPauseTimeDeviation;

	UPROPERTY(EditDefaultsOnly, Category="Launched", meta=(AllowPrivateAccess="true"))
	FScalableFloat SteerMovementWhenLaunched;

	UPROPERTY(EditDefaultsOnly, Category="Launched", meta=(AllowPrivateAccess="true"))
	FScalableFloat SteerMovementWhenLaunchedDirectionUpdateTime;

	UPROPERTY(EditDefaultsOnly, Category="Danger Reaction", meta=(AllowPrivateAccess="true"))
	FScalableFloat MaxReactionTimeToDangerZone;

	UPROPERTY(EditDefaultsOnly, Category="Danger Reaction", meta=(AllowPrivateAccess="true"))
	FScalableFloat MaxReactionTimeToDangerZoneDeviation;

	UPROPERTY(EditDefaultsOnly, Category="Swimming", meta=(AllowPrivateAccess="true"))
	FScalableFloat AllowSwimWobble;

	UPROPERTY(EditDefaultsOnly, Category="Swimming", meta=(AllowPrivateAccess="true"))
	FScalableFloat EnableSwimSprintJump;

	UPROPERTY(EditDefaultsOnly, Category="Swimming", meta=(AllowPrivateAccess="true"))
	FScalableFloat SwimSprintJumpDelay;

	UPROPERTY(EditDefaultsOnly, Category="Swimming", meta=(AllowPrivateAccess="true"))
	FScalableFloat SwimSprintJumpDelayDeviation;

	UPROPERTY(EditDefaultsOnly, Category="Swimming", meta=(AllowPrivateAccess="true"))
	FScalableFloat SwimUnblockJumpHeightThreshold;

	UPROPERTY(EditDefaultsOnly, Category="Swimming", meta=(AllowPrivateAccess="true"))
	FScalableFloat SwimSprintJumpNav2D;

	UPROPERTY(EditDefaultsOnly, Category="Tactical Sprint", meta=(AllowPrivateAccess="true"))
	FScalableFloat TacticalSprintEvaluationMinTime;

	UPROPERTY(EditDefaultsOnly, Category="Tactical Sprint", meta=(AllowPrivateAccess="true"))
	FScalableFloat TacticalSprintEvaluationMaxTime;

	UPROPERTY(EditDefaultsOnly, Category="Tactical Sprint", meta=(AllowPrivateAccess="true"))
	FScalableFloat TacticalSprintMinTriggerChance;

	UPROPERTY(EditDefaultsOnly, Category="Tactical Sprint", meta=(AllowPrivateAccess="true"))
	FScalableFloat TacticalSprintMaxTriggerChance;

	UPROPERTY(EditDefaultsOnly, Category="Tactical Sprint", meta=(AllowPrivateAccess="true"))
	FScalableFloat TacticalSprintMinTriggerChanceInUrgentMovement;

	UPROPERTY(EditDefaultsOnly, Category="Tactical Sprint", meta=(AllowPrivateAccess="true"))
	FScalableFloat TacticalSprintMaxTriggerChanceInUrgentMovement;

	UPROPERTY(EditDefaultsOnly, Category="Tactical Sprint", meta=(AllowPrivateAccess="true"))
	FScalableFloat TacticalSprintMaxSlopeAngle;

	UPROPERTY(EditDefaultsOnly, Category="Tactical Sprint", meta=(AllowPrivateAccess="true"))
	FScalableFloat TacticalSprintMinPathTargetDistance;

	UPROPERTY(EditDefaultsOnly, Category="Tactical Sprint", meta=(AllowPrivateAccess="true"))
	FScalableFloat TacticalSprintMaxPathAlignmentAngle;

	UPROPERTY(EditDefaultsOnly, Category="Tactical Sprint", meta=(AllowPrivateAccess="true"))
	FScalableFloat TacticalSprintMaxPathConeAngle;

	UPROPERTY(EditDefaultsOnly, Category="Tactical Sprint", meta=(AllowPrivateAccess="true"))
	FScalableFloat TacticalSprintPathConeRearOffset;

	UPROPERTY(EditDefaultsOnly, Category="Tactical Sprint", meta=(AllowPrivateAccess="true"))
	FScalableFloat TacticalSprintUsageEnabled;

	UPROPERTY(EditDefaultsOnly, Category="Tactical Sprint", meta=(AllowPrivateAccess="true"))
	FScalableFloat TacticalSprintJumpTriggerChance;

	UPROPERTY(EditDefaultsOnly, Category="Tactical Sprint", meta=(AllowPrivateAccess="true"))
	FScalableFloat TacticalSprintJumpDelay;

	UPROPERTY(EditDefaultsOnly, Category="Tactical Sprint", meta=(AllowPrivateAccess="true"))
	FScalableFloat TacticalSprintJumpDelayDeviation;

	UPROPERTY(EditDefaultsOnly, Category="Tactical Sprint", meta=(AllowPrivateAccess="true"))
	FScalableFloat TacticalSprintJumpDelayInitialRatio;

	UPROPERTY(EditDefaultsOnly, Category="Sliding", meta=(AllowPrivateAccess="true"))
	FVector SlidingBoxExtent;

	UPROPERTY(EditDefaultsOnly, Category="Sliding", meta=(AllowPrivateAccess="true", ArraySizeEnum="/Script/FortniteAI.EAlertLevel"))
	FScalableFloat SlidingEnabled[4];

	UPROPERTY(EditDefaultsOnly, Category="Sliding", meta=(AllowPrivateAccess="true"))
	FScalableFloat SlidingEvaluationMinTime;

	UPROPERTY(EditDefaultsOnly, Category="Sliding", meta=(AllowPrivateAccess="true"))
	FScalableFloat SlidingEvaluationMaxTime;

	UPROPERTY(EditDefaultsOnly, Category="Sliding", meta=(AllowPrivateAccess="true"))
	FScalableFloat SlidingTriggerChanceStyleMalus;

	UPROPERTY(EditDefaultsOnly, Category="Sliding", meta=(AllowPrivateAccess="true"))
	FScalableFloat SlidingTriggerChanceStyleMalusRandomDeviation;

	UPROPERTY(EditDefaultsOnly, Category="Sliding", meta=(AllowPrivateAccess="true"))
	FScalableFloat SlidingTriggerChanceFlat;

	UPROPERTY(EditDefaultsOnly, Category="Sliding", meta=(AllowPrivateAccess="true"))
	FScalableFloat SlidingTriggerChanceLittleSlope;

	UPROPERTY(EditDefaultsOnly, Category="Sliding", meta=(AllowPrivateAccess="true"))
	FScalableFloat SlidingTriggerChanceSteepSlope;

	UPROPERTY(EditDefaultsOnly, Category="Sliding", meta=(AllowPrivateAccess="true"))
	FScalableFloat SlidingDuringUrgentMovementTriggerChanceFlat;

	UPROPERTY(EditDefaultsOnly, Category="Sliding", meta=(AllowPrivateAccess="true"))
	FScalableFloat SlidingDuringUrgentMovementTriggerChanceLittleSlope;

	UPROPERTY(EditDefaultsOnly, Category="Sliding", meta=(AllowPrivateAccess="true"))
	FScalableFloat SlidingDuringUrgentMovementTriggerChanceSteepSlope;

	UPROPERTY(EditDefaultsOnly, Category="Sliding", meta=(AllowPrivateAccess="true"))
	FScalableFloat MinSlidingDuration;

	UPROPERTY(EditDefaultsOnly, Category="Sliding", meta=(AllowPrivateAccess="true"))
	FScalableFloat SlidingCooldownMinTime;

	UPROPERTY(EditDefaultsOnly, Category="Sliding", meta=(AllowPrivateAccess="true"))
	FScalableFloat SlidingCooldownMaxTime;

	UPROPERTY(EditDefaultsOnly, Category="Sliding", meta=(AllowPrivateAccess="true"))
	FScalableFloat SlidingStopMinDelay;

	UPROPERTY(EditDefaultsOnly, Category="Sliding", meta=(AllowPrivateAccess="true"))
	FScalableFloat SlidingStopMaxDelay;

	UPROPERTY(EditDefaultsOnly, Category="Sliding", meta=(AllowPrivateAccess="true"))
	FScalableFloat SlidingMaxPathConeAngle;

	UPROPERTY(EditDefaultsOnly, Category="Sliding", meta=(AllowPrivateAccess="true"))
	FScalableFloat SlidingMinPathTargetDistance;

	UPROPERTY(EditDefaultsOnly, Category="Sliding", meta=(AllowPrivateAccess="true"))
	FScalableFloat SlidingAllowResumeFocusOnTargetTriggerChance;

	UPROPERTY(EditDefaultsOnly, Category="Zipline", meta=(AllowPrivateAccess="true"))
	FVector ZiplineOctreeBoxExtent;

	UPROPERTY(EditDefaultsOnly, Category="Zipline", meta=(AllowPrivateAccess="true"))
	FScalableFloat ThresholdDistanceToRescanForZiplines;

	UPROPERTY(EditDefaultsOnly, Category="Zipline", meta=(AllowPrivateAccess="true"))
	FScalableFloat CooldownBetweenZiplineUsages;

	UPROPERTY(EditDefaultsOnly, Category="Zipline", meta=(AllowPrivateAccess="true"))
	FScalableFloat DistanceToAddToZiplineStartPosition;

	UPROPERTY(EditDefaultsOnly, Category="Zipline", meta=(AllowPrivateAccess="true"))
	FScalableFloat RadiusFromZiplineEnterPointToLookAtExit;

	UPROPERTY(EditDefaultsOnly, Category="Zipline", meta=(AllowPrivateAccess="true"))
	FScalableFloat ZiplineUsageEnabled;

	UPROPERTY(EditDefaultsOnly, Category="Zipline", meta=(AllowPrivateAccess="true"))
	FScalableFloat CanOpenDoors;

	UPROPERTY(EditDefaultsOnly, Category="Knockback", meta=(AllowPrivateAccess="true"))
	TArray<FBotKnockbackSettings> KnockbackSettings;

};

