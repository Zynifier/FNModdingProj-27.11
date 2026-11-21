// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Athena/AI/FortAthenaAIBotSkillSet.h"
#include "FortAthenaAIBotLootingSkillSet.generated.h"

UCLASS(MinimalAPI)
class UFortAthenaAIBotLootingDigestedSkillSet : public UFortAthenaAIBotDigestedSkillSet
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	float ThresholdDistanceToSwitchLootItem;

	UPROPERTY(Transient)
	float ThresholdDistanceSquaredToRescanForBetterLoot;

	UPROPERTY(Transient)
	float ThresholdTimeToRescanForBetterLoot;

	UPROPERTY(Transient)
	FVector OctreeBoxHalfExtent;

	UPROPERTY(Transient)
	float LootStateEvaluationRadiusSq;

	UPROPERTY(Transient)
	float MinLootDurationPerPOI;

	UPROPERTY(Transient)
	float MaxLootDurationPerPOI;

	UPROPERTY(Transient)
	float LootPickupInteractionTime;

	UPROPERTY(Transient)
	float LootPickupInteractionDeviationTime;

	UPROPERTY(Transient)
	float Distance2DScore;

	UPROPERTY(Transient)
	float HeightScore;

	UPROPERTY(Transient)
	float ThreatMaxScore;

	UPROPERTY(Transient)
	FScalableFloat ThreatProximityScoreTable;

	UPROPERTY(Transient)
	float PrioritizeWeaponScore;

	UPROPERTY(Transient)
	float PoiSelectionDistanceScore;

	UPROPERTY(Transient)
	float PoiSelectionBotPresenceScore;

};

UCLASS(MinimalAPI)
class UFortAthenaAIBotLootingSkillSet : public UFortAthenaAIBotSkillSet
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Loot Selection", meta=(AllowPrivateAccess="true", ClampMin="0.0", UIMin="0.0"))
	FScalableFloat ThresholdDistanceToSwitchLootItem;

	UPROPERTY(EditDefaultsOnly, Category="Loot Selection", meta=(AllowPrivateAccess="true", ClampMin="0.0", UIMin="0.0"))
	FScalableFloat ThresholdDistanceToRescanForBetterLoot;

	UPROPERTY(EditDefaultsOnly, Category="Loot Selection", meta=(AllowPrivateAccess="true", ClampMin="0.0", UIMin="0.0"))
	FScalableFloat ThresholdTimeToRescanForBetterLoot;

	UPROPERTY(EditDefaultsOnly, Category="Loot Selection", meta=(AllowPrivateAccess="true"))
	FVector OctreeBoxExtent;

	UPROPERTY(EditDefaultsOnly, Category="Loot Selection", meta=(AllowPrivateAccess="true", ClampMin="0.0", UIMin="0.0"))
	FScalableFloat LootStateEvaluationRadius;

	UPROPERTY(EditDefaultsOnly, Category="Loot Duration", meta=(AllowPrivateAccess="true"))
	FScalableFloat MinLootDurationPerPOI;

	UPROPERTY(EditDefaultsOnly, Category="Loot Duration", meta=(AllowPrivateAccess="true"))
	FScalableFloat MaxLootDurationPerPOI;

	UPROPERTY(EditDefaultsOnly, Category="Loot Interaction", meta=(AllowPrivateAccess="true"))
	FScalableFloat LootPickupInteractionTime;

	UPROPERTY(EditDefaultsOnly, Category="Loot Interaction", meta=(AllowPrivateAccess="true"))
	FScalableFloat LootPickupInteractionDeviationTime;

	UPROPERTY(EditDefaultsOnly, Category="Loot Scores", meta=(AllowPrivateAccess="true"))
	FScalableFloat Distance2DScore;

	UPROPERTY(EditDefaultsOnly, Category="Loot Scores", meta=(AllowPrivateAccess="true"))
	FScalableFloat HeightScore;

	UPROPERTY(EditDefaultsOnly, Category="Loot Scores", meta=(AllowPrivateAccess="true"))
	FScalableFloat ThreatMaxScore;

	UPROPERTY(EditDefaultsOnly, Category="Loot Scores", meta=(AllowPrivateAccess="true"))
	FScalableFloat ThreatProximityScoreTable;

	UPROPERTY(EditDefaultsOnly, Category="Loot Scores", meta=(AllowPrivateAccess="true"))
	FScalableFloat PrioritizeWeaponScore;

	UPROPERTY(EditDefaultsOnly, Category="POI Scores", meta=(AllowPrivateAccess="true"))
	FScalableFloat PoiSelectionDistanceScore;

	UPROPERTY(EditDefaultsOnly, Category="POI Scores", meta=(AllowPrivateAccess="true"))
	FScalableFloat PoiSelectionBotPresenceScore;

};

