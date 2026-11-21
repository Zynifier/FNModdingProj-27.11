// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/AI/FortAthenaAIRuntimeParametersComponent.h"
#include "Athena/AI/FortAthenaAISpawnerDataComponent_Behavior.h"
#include "FortAthenaAISpawnerDataComponent_AIBotBehavior.generated.h"

enum class EBehaviorTreeBranches : uint8;

UENUM(BlueprintType)
enum class EBehaviorTreeBranches : uint8
{
	/** If true this AI can use the Diving Behavior */
	CanUseDiving = 0,
	/** If true this AI can use the Gliding Behavior */
	CanUseGliding = 1,
	/** If true this AI can use the React To Projectile Behavior */
	CanReactToProjectile = 2,
	/** If true this AI can use the React To Traps Behavior */
	CanReactToTraps = 3,
	/** If true this AI can use the use the Avoid Danger Area Behavior */
	CanAvoidDangerArea = 4,
	/** If true this AI can use the use the Converted Behavior */
	CanBeConverted = 5,
	/** If true this AI can use the use the Propagate Awareness Behavior */
	CanPropagateAwareness = 6,
	/** If true this AI can use the use the Threatened Behavior (Range + Melee + MoveToAttack) */
	CanUseThreatenedBehaviors = 7,
	/** If true this AI can use the use the Last Known Position Behavior */
	CanUseLastKnownPositionBehavior = 8,
	/** If true this AI can use the use the Alerted Behavior (Wait + Observe + Focus) */
	CanUseAlertedBehavior = 9,
	/** If true this AI can use the use the Smart Objects */
	CanUseSmartObjects = 10,
	/** If true this AI can use the use the Revive DBNO Teammates */
	CanReviveDBNOTeammates = 11,
	/** If true this AI can use the use the Play Emote behavior */
	CanPlayEmote = 12,
	/** If true this AI can use the use the Conversation behavior */
	CanConverse = 13,
	/** If true this AI can use the use the Patrol on patrol path behavior */
	CanPatrolOnPath = 14,
	/** If true this AI can use the use the Patrol Around behavior */
	CanPatrolAround = 15,
	/** If true this AI will teleport when stuck */
	CanTeleportWhenStuck = 16,
	/** If true this AI will emote when stuck */
	CanEmoteWhenStuck = 17,
	/** If true this AI can use ziplines */
	CanUseZiplines = 18,
	/** Keep last */
	Count = 19 UMETA(Hidden),
};

UENUM()
enum class EBehaviorTreeBranchesBitmask : uint8
{
	/** If true this AI can use the Diving Behavior */
	CanUseDiving = 0,
	/** If true this AI can use the Gliding Behavior */
	CanUseGliding = 1,
	/** If true this AI can use the React To Projectile Behavior */
	CanReactToProjectile = 2,
	/** If true this AI can use the React To Traps Behavior */
	CanReactToTraps = 3,
	/** If true this AI can use the use the Avoid Danger Area Behavior */
	CanAvoidDangerArea = 4,
	/** If true this AI can use the use the Converted Behavior */
	CanBeConverted = 5,
	/** If true this AI can use the use the Propagate Awareness Behavior */
	CanPropagateAwareness = 6,
	/** If true this AI can use the use the Threatened Behavior (Range + Melee + MoveToAttack) */
	CanUseThreatenedBehaviors = 7,
	/** If true this AI can use the use the Last Known Position Behavior */
	CanUseLastKnownPositionBehavior = 8,
	/** If true this AI can use the use the Alerted Behavior (Wait + Observe + Focus) */
	CanUseAlertedBehavior = 9,
	/** If true this AI can use the use the Smart Objects */
	CanUseSmartObjects = 10,
	/** If true this AI can use the use the Revive DBNO Teammates */
	CanReviveDBNOTeammates = 11,
	/** If true this AI can use the use the Play Emote behavior */
	CanPlayEmote = 12,
	/** If true this AI can use the use the Conversation behavior */
	CanConverse = 13,
	/** If true this AI can use the use the Patrol on patrol path behavior */
	CanPatrolOnPath = 14,
	/** If true this AI can use the use the Patrol Around behavior */
	CanPatrolAround = 15,
	/** If true this AI will teleport when stuck */
	CanTeleportWhenStuck = 16,
	/** If true this AI will emote when stuck */
	CanEmoteWhenStuck = 17,
	/** If true this AI can use ziplines */
	CanUseZiplines = 18,
	/** Keep last */
	Count = 19 UMETA(Hidden),
};

UCLASS(MinimalAPI)
class UFortAthenaAIRuntimeParameters_Behavior : public UFortAthenaAIRuntimeParameters
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	uint8 bSurfaceTypeCheckEnabled : 1;

};

UCLASS(MinimalAPI)
class UFortAthenaAIRuntimeParameters_BehaviorTreeControl : public UFortAthenaAIRuntimeParameters
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void DisableBehaviorTreeBranch(const EBehaviorTreeBranches Behavior);

	UFUNCTION(BlueprintCallable)
	void EnableBehaviorTreeBranch(const EBehaviorTreeBranches Behavior);

	UFUNCTION(BlueprintPure)
	bool IsBehaviorTreeBranchActive(const EBehaviorTreeBranches Behavior) const;

private:
	UPROPERTY(Transient)
	uint32 BehaviorTreeControls;

};

UCLASS(MinimalAPI, BlueprintType)
class UFortAthenaAIRuntimeParameters_DBNOBehavior : public UFortAthenaAIRuntimeParameters
{
	GENERATED_BODY()

private:
	UPROPERTY(BlueprintReadWrite, Transient, Category="FortAthenaAIRuntimeParameters_DBNOBehavior", meta=(AllowPrivateAccess="true"))
	uint8 bDieWhenAllAlliesAreDBNO : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortAthenaAIRuntimeParameters_DBNOBehavior", meta=(AllowPrivateAccess="true"))
	uint8 bIsAllowedToMoveInDBNO : 1;

	UPROPERTY(Transient)
	float AliveAlliesMaxRangeSqr;

	UPROPERTY(Transient)
	float SecondsBeforeAutomaticReviveFromDBNOWhenOutOfCombat;

};

UCLASS(MinimalAPI)
class UFortAthenaAIRuntimeParameters_NPCBehavior : public UFortAthenaAIRuntimeParameters
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	uint8 bSupportsHolsteredWeapon : 1;

};

UCLASS(MinimalAPI)
class UFortAthenaAIRuntimeParameters_ReviveBehavior : public UFortAthenaAIRuntimeParameters
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	uint8 bAllowReviveSquadmates : 1;

	UPROPERTY(Transient)
	uint8 bAllowReviveSameFactionNPCs : 1;

	UPROPERTY(Transient)
	uint8 bAllowReviveConverter : 1;

	UPROPERTY(Transient)
	uint8 bAllowReviveConverterSquadmates : 1;

	UPROPERTY(Transient)
	uint8 bUseReviveToken : 1;

	UPROPERTY(Transient)
	float MaxDistanceToRevive;

	UPROPERTY(Transient)
	float MaxDistanceToReviveHumanPlayer;

};

UCLASS()
class UFortAthenaAISpawnerDataComponent_AIBotBehavior : public UFortAthenaAISpawnerDataComponent_Behavior
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void DisableBehaviorTreeBranch(const EBehaviorTreeBranches Behavior);

	UFUNCTION(BlueprintCallable)
	void EnableBehaviorTreeBranch(const EBehaviorTreeBranches Behavior);

	UFUNCTION(BlueprintPure)
	bool IsBehaviorTreeBranchActive(const EBehaviorTreeBranches Behavior) const;

private:
	UPROPERTY(EditAnywhere, Category="Behavior Controls", meta=(AllowPrivateAccess="true", BitMask, BitmaskEnum="/Script/FortniteAI.EBehaviorTreeBranchesBitmask"))
	uint32 BehaviorTreeControls;

	UPROPERTY(EditAnywhere, Category="Fallback Patrol Around", meta=(AllowPrivateAccess="true"))
	uint8 bCanUseFallbackPatrolAround : 1;

	UPROPERTY(EditAnywhere, Category="Revive", meta=(AllowPrivateAccess="true"))
	uint8 bAllowReviveSquadmates : 1;

	UPROPERTY(EditAnywhere, Category="Revive", meta=(AllowPrivateAccess="true"))
	uint8 bAllowReviveSameFactionNPCs : 1;

	UPROPERTY(EditAnywhere, Category="Revive", meta=(AllowPrivateAccess="true"))
	FScalableFloat AllowReviveConverter;

	UPROPERTY(EditAnywhere, Category="Revive", meta=(AllowPrivateAccess="true"))
	FScalableFloat AllowReviveConverterSquadmates;

	UPROPERTY(EditAnywhere, Category="Revive", meta=(AllowPrivateAccess="true"))
	uint8 bUseReviveToken : 1;

	UPROPERTY(EditAnywhere, Category="Revive", meta=(AllowPrivateAccess="true"))
	FScalableFloat MaxDistanceToRevive;

	UPROPERTY(EditAnywhere, Category="Revive", meta=(AllowPrivateAccess="true"))
	FScalableFloat MaxDistanceToReviveHumanPlayer;

	UPROPERTY(EditAnywhere, Category="DBNO", meta=(AllowPrivateAccess="true"))
	FScalableFloat DieWhenAllAlliesAreDBNO;

	UPROPERTY(EditAnywhere, Category="DBNO", meta=(AllowPrivateAccess="true"))
	uint8 bIsAllowedToMoveInDBNO : 1;

	UPROPERTY(EditAnywhere, Category="DBNO", meta=(AllowPrivateAccess="true"))
	FScalableFloat AliveAlliesMaxRange;

	UPROPERTY(EditAnywhere, Category="DBNO", meta=(AllowPrivateAccess="true"))
	FScalableFloat SecondsBeforeAutomaticReviveFromDBNOWhenOutOfCombat;

	UPROPERTY(EditAnywhere, Category="NPC", meta=(AllowPrivateAccess="true"))
	FScalableFloat SupportsHolsteredWeapon;

	UPROPERTY(EditAnywhere, Category="Misc", meta=(AllowPrivateAccess="true"))
	FScalableFloat SurfaceTypeCheckEnabled;

	UPROPERTY(EditAnywhere, Category="Misc", meta=(AllowPrivateAccess="true"))
	FScalableFloat bShouldResetAggressivePlayStyleOnUnaware;

	UPROPERTY(EditAnywhere, Category="Misc", meta=(AllowPrivateAccess="true"))
	FScalableFloat TimeToKeepTrackOfDamagingActorsForAggressivePlayStyle;

	UPROPERTY(EditAnywhere, Category="Misc", meta=(AllowPrivateAccess="true"))
	FScalableFloat TimeToIgnoreDamagingActorsWhenBeingControlled;

	UPROPERTY(EditAnywhere, Category="Startup", meta=(AllowPrivateAccess="true"))
	FScalableFloat PauseBehaviorOnSpawnDuration;

	UPROPERTY(EditAnywhere, Category="Startup", meta=(AllowPrivateAccess="true"))
	FScalableFloat bShouldBeInvulnerableDuringPause;

};

