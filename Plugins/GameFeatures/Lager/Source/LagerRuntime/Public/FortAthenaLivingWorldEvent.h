// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "WorldConditionQuery.h"
#include "Athena/FortGameStateAthenaEnums.h"
#include "Conditions/FortAthenaLivingWorldDespawnCondition.h"
#include "FortAthenaLivingWorldEventData.h"
#include "FortAthenaLivingWorldEvent.generated.h"

class UFortAthenaLivingWorldEventData;

USTRUCT()
struct FFortAthenaLivingWorldEventDataEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="LivingWorld", meta=(AssetBundles="Server"))
	TSoftObjectPtr<UFortAthenaLivingWorldEventData> EventData;

	UPROPERTY(EditDefaultsOnly, Category="LivingWorld")
	FScalableFloat Weight;

};

USTRUCT()
struct FFortAthenaLivingWorldEventDespawnCondition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortAthenaLivingWorldEventDespawnCondition")
	bool bCanBeDespawned;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaLivingWorldEventDespawnCondition", meta=(EditCondition="bCanBeDespawned"))
	float MinDistanceToPlayer;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaLivingWorldEventDespawnCondition", meta=(EditCondition="bCanBeDespawned"))
	float TimeAsCandidateBeforeDespawn;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaLivingWorldEventDespawnCondition", meta=(EditCondition="bCanBeDespawned"))
	EAthenaGamePhaseStep CanStartDespawningPhaseStep;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaLivingWorldEventDespawnCondition", meta=(EditCondition="bCanBeDespawned"))
	int32 CanStartDespawningSafeZonePhase;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaLivingWorldEventDespawnCondition", meta=(EditCondition="bCanBeDespawned"))
	bool bCanDespawnWhenInCombatWithPlayer;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaLivingWorldEventDespawnCondition", meta=(EditCondition="bCanBeDespawned && !bCanDespawnWhenInCombatWithPlayer"))
	float MaxStimulusAgeToBeConsideredInCombat;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaLivingWorldEventDespawnCondition", meta=(EditCondition="bCanBeDespawned"))
	bool bCanDespawnInTheStorm;

};

USTRUCT()
struct FFortAthenaLivingWorldEventTagDensityCondition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortAthenaLivingWorldEventTagDensityCondition", meta=(Categories="Athena.AI.Lager.TagDensity"))
	FGameplayTag Tag;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaLivingWorldEventTagDensityCondition")
	float Distance;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaLivingWorldEventTagDensityCondition")
	float MaxDensity;

};

USTRUCT()
struct FFortAthenaLivingWorldEvent : public FTableRowBase
{
	GENERATED_BODY()

private:
	UPROPERTY(meta=(AssetBundles="Server"))
	TSoftObjectPtr<UFortAthenaLivingWorldEventData> EventData_DEPRECATED;

	UPROPERTY(EditDefaultsOnly, Category="LivingWorld")
	TArray<FFortAthenaLivingWorldEventDataEntry> EventDatas;

	UPROPERTY(EditDefaultsOnly, Category="LivingWorld")
	FScalableFloat IsEnabled;

	UPROPERTY(EditDefaultsOnly, Category="LivingWorld")
	TArray<float> MaxCount;

	UPROPERTY(EditDefaultsOnly, Category="LivingWorld")
	TArray<float> MaxSpawnedCount;

	UPROPERTY(EditDefaultsOnly, Category="LivingWorld")
	TArray<float> EventInstanceMaxCount;

	UPROPERTY(EditDefaultsOnly, Category="LivingWorld")
	TArray<float> EventInstanceMaxSpawnedCount;

	UPROPERTY(EditDefaultsOnly, Category="LivingWorld")
	float Weight;

	UPROPERTY(EditAnywhere, Category="Respawn Time")
	TArray<float> MinRespawnTime;

	UPROPERTY(EditAnywhere, Category="Respawn Time")
	TArray<float> MaxRespawnTime;

	UPROPERTY(EditAnywhere, Category="Respawn Time")
	TArray<float> InstantDeathMinRespawnTime;

	UPROPERTY(EditAnywhere, Category="Respawn Time")
	TArray<float> InstantDeathMaxRespawnTime;

	UPROPERTY(EditAnywhere, Category="Spawn Location")
	bool bOnlyInSafeZone;

	UPROPERTY(EditAnywhere, Category="Spawn Location")
	bool bOnlyInNextSafeZone;

	UPROPERTY(EditAnywhere, Category="Spawn Location")
	bool bOnlyInNextSafeZoneIfStormShrinking;

	UPROPERTY(EditAnywhere, Category="Activation")
	FWorldConditionQueryDefinition CanSpawnCondition;

	UPROPERTY(EditDefaultsOnly, Category="Activation")
	EAthenaGamePhaseStep ActivationGamePhaseStep;

	UPROPERTY(EditDefaultsOnly, Category="Activation")
	int32 ActivationSafeZoneIndex;

	UPROPERTY(EditDefaultsOnly, Category="Activation")
	float ActivationMinDelay;

	UPROPERTY(EditDefaultsOnly, Category="Activation")
	float ActivationMaxDelay;

	UPROPERTY(EditDefaultsOnly, Category="Activation")
	float DeactivationMinDelay;

	UPROPERTY(EditDefaultsOnly, Category="Activation")
	float DeactivationMaxDelay;

	UPROPERTY(EditDefaultsOnly, Category="Spawn Location")
	TArray<FFortAthenaLivingWorldEventTagDensityCondition> TagDensityConditions;

	UPROPERTY(EditDefaultsOnly, Category="Spawn Location")
	bool bCheckForActorDensity;

	UPROPERTY(EditDefaultsOnly, Category="Spawn Location")
	float MaxActorDensityOverride;

	UPROPERTY(EditDefaultsOnly, Category="Spawn Location")
	float MinDistanceToPlayer;

	UPROPERTY(EditDefaultsOnly, Category="Spawn Location")
	float MaxDistanceToPlayer;

	UPROPERTY(EditDefaultsOnly, Category="Spawn Location")
	bool bCanSpawnWithoutMatchingPlayerDistance;

	UPROPERTY(EditDefaultsOnly, Category="Activation", meta=(ClampMax="100.0", ClampMin="0.0"))
	float RandomActivationChance;

	UPROPERTY(EditDefaultsOnly, Category="Deactivation")
	FFortAthenaLivingWorldEventDespawnCondition DespawnCondition;

	UPROPERTY(EditDefaultsOnly, Category="Deactivation")
	TArray<FFortAthenaLivingWorldDespawnCondition> DespawnConditions;

	UPROPERTY(EditDefaultsOnly, Category="LivingWorld")
	FGameplayTagContainer RequirePlaylistTags;

	UPROPERTY(EditDefaultsOnly, Category="LivingWorld")
	FLivingWorldCalendarEventConditions CalendarEventConditions;

};

