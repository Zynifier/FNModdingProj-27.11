// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/AI/FortAthenaAIBotSkillSet.h"
#include "FortAthenaAIBotUnstuckSkillSet.generated.h"

UCLASS(MinimalAPI)
class UFortAthenaAIBotUnstuckDigestedSkillSet : public UFortAthenaAIBotDigestedSkillSet
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	bool bCanUndermineWhenStuck;

	UPROPERTY(Transient)
	bool bCanTeleportWhenStuck;

	UPROPERTY(Transient)
	bool bAvoidsTeleportLocationsUnderTheLandscape;

	UPROPERTY(Transient)
	bool bCanTeleportWhenStuckWithPlayerAround;

	UPROPERTY(Transient)
	float MaxDistanceSqToPlayerToTeleport;

	UPROPERTY(Transient)
	float PlayerToPhoebeAngleVisibilityConeToTeleport;

	UPROPERTY(Transient)
	float TimeBetweenPartialPathToConsiderPathStuck;

	UPROPERTY(Transient)
	int32 ConsecutivePartialPathCountToConsiderPathStuck;

	UPROPERTY(Transient)
	float DistanceSqBetweenBlockedPathToConsiderPathStuck;

	UPROPERTY(Transient)
	float DistanceBetweenSampleToConsiderPathStuckInWater;

	UPROPERTY(Transient)
	float TimeBetweenSampleToConsiderPathStuckInWater;

	UPROPERTY(Transient)
	float DistanceBetweenSampleToConsiderPathStuckOnGround;

	UPROPERTY(Transient)
	float TimeBetweenSampleToConsiderPathStuckOnGround;

	UPROPERTY(Transient)
	int32 ConsecutiveBlockedPathCountToConsiderPathStuck;

	UPROPERTY(Transient)
	int32 MaxSafeZoneIndexToAllowTeleport;

	UPROPERTY(Transient)
	float TimeToBreakBlockingDoor;

	UPROPERTY(Transient)
	float TimeToCloseBlockingDoor;

	UPROPERTY(Transient)
	float RiverbedObstacleCollisionNormalThreshold;

	UPROPERTY(Transient)
	bool bCanUseSteeringWhenStuckOnIsolatedIsland;

	UPROPERTY(Transient)
	int32 MaxSteeringDirectionAttempts;

	UPROPERTY(Transient)
	float SteeringAttemptDuration;

	UPROPERTY(Transient)
	float EvaluateIsolatedIslandSteeringTime;

	UPROPERTY(Transient)
	bool bCanSlideWhenBlocked;

	UPROPERTY(Transient)
	float SlidingDurationSeconds;

	UPROPERTY(Transient)
	float SlidingStartIntensity;

	UPROPERTY(Transient)
	float SlidingIntensityPerSeconds;

	UPROPERTY(Transient)
	float SlidingMaxIntensity;

};

UCLASS(MinimalAPI)
class UFortAthenaAIBotUnstuckSkillSet : public UFortAthenaAIBotSkillSet
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Teleport", meta=(AllowPrivateAccess="true"))
	FScalableFloat CanUndermineWhenStuck;

	UPROPERTY(EditDefaultsOnly, Category="Teleport", meta=(AllowPrivateAccess="true"))
	FScalableFloat CanTeleportWhenStuck;

	UPROPERTY(EditDefaultsOnly, Category="Teleport", meta=(AllowPrivateAccess="true"))
	FScalableFloat AvoidsTeleportLocationsUnderTheLandscape;

	UPROPERTY(EditDefaultsOnly, Category="Teleport", meta=(AllowPrivateAccess="true"))
	FScalableFloat CanTeleportWhenStuckWithPlayerAround;

	UPROPERTY(EditDefaultsOnly, Category="Teleport", meta=(AllowPrivateAccess="true"))
	FScalableFloat MaxDistanceToPlayerToTeleport;

	UPROPERTY(EditDefaultsOnly, Category="Teleport", meta=(AllowPrivateAccess="true"))
	FScalableFloat PlayerToPhoebeAngleVisibilityConeToTeleport;

	UPROPERTY(EditAnywhere, Category="Teleport", meta=(AllowPrivateAccess="true"))
	FScalableFloat MaxSafeZoneIndexToAllowTeleport;

	UPROPERTY(EditAnywhere, Category="Door", meta=(AllowPrivateAccess="true"))
	FScalableFloat TimeToCloseBlockingDoor;

	UPROPERTY(EditAnywhere, Category="Door", meta=(AllowPrivateAccess="true"))
	FScalableFloat TimeToBreakBlockingDoor;

	UPROPERTY(EditAnywhere, Category="Water", meta=(AllowPrivateAccess="true"))
	FScalableFloat RiverbedObstacleCollisionNormalThreshold;

	UPROPERTY(EditDefaultsOnly, Category="Steer", meta=(AllowPrivateAccess="true"))
	FScalableFloat CanUseSteeringWhenStuckOnIsolatedIsland;

	UPROPERTY(EditAnywhere, Category="Steer", meta=(AllowPrivateAccess="true"))
	FScalableFloat MaxSteeringDirectionAttempts;

	UPROPERTY(EditAnywhere, Category="Steer", meta=(AllowPrivateAccess="true"))
	FScalableFloat SteeringAttemptDuration;

	UPROPERTY(EditAnywhere, Category="Steer", meta=(AllowPrivateAccess="true"))
	FScalableFloat EvaluateIsolatedIslandSteeringTime;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FScalableFloat TimeBetweenPartialPathToConsiderPathStuck;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FScalableFloat ConsecutivePartialPathCountToConsiderPathStuck;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FScalableFloat DistanceBetweenSampleToConsiderPathStuckInWater;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FScalableFloat TimeBetweenSampleToConsiderPathStuckInWater;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FScalableFloat DistanceBetweenSampleToConsiderPathStuckOnGround;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FScalableFloat TimeBetweenSampleToConsiderPathStuckOnGround;

	UPROPERTY(Transient)
	FScalableFloat DistanceBetweenBlockedPathToConsiderPathStuck;

	UPROPERTY(Transient)
	FScalableFloat ConsecutiveBlockedPathCountToConsiderPathStuck;

	UPROPERTY(EditAnywhere, Category="Slide", meta=(AllowPrivateAccess="true"))
	FScalableFloat bCanSlideWhenBlocked;

	UPROPERTY(EditAnywhere, Category="Slide", meta=(AllowPrivateAccess="true"))
	FScalableFloat SlidingDurationSeconds;

	UPROPERTY(EditAnywhere, Category="Slide", meta=(AllowPrivateAccess="true"))
	FScalableFloat SlidingStartIntensity;

	UPROPERTY(EditAnywhere, Category="Slide", meta=(AllowPrivateAccess="true"))
	FScalableFloat SlidingIntensityPerSeconds;

	UPROPERTY(EditAnywhere, Category="Slide", meta=(AllowPrivateAccess="true"))
	FScalableFloat SlidingMaxIntensity;

};

