// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortEncounterDirectionEnum.h"
#include "FortEncounterEnvironmentQueryInfo.h"
#include "FortEncounterSettings.generated.h"

class AActor;
class ABuildingRift;
class UEnvQuery;
class UFortDifficultyOptionCategoryEncounter;

USTRUCT(BlueprintType)
struct FFortEncounterSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortEncounterSettings")
	TArray<TEnumAsByte<EFortEncounterDirection::Type>> ForbiddenSpawnDirections;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortEncounterSettings")
	bool bDestroyAllBuildings;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortEncounterSettings")
	bool bDestroyPlayerBuildings;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortEncounterSettings")
	bool bValidateIfPlayerIsAtSpawnLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category="FortEncounterSettings")
	bool bMustFindSpawnPoints;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category="FortEncounterSettings")
	bool bStopIfCantFindSpawnPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortEncounterSettings")
	bool bIgnoreCollisionWhenSpawningAI;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category="FortEncounterSettings")
	bool bTrackCombatParticipation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category="FortEncounterSettings")
	bool bDisplayThreatVisuals;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category="FortEncounterSettings")
	bool bCanDespawnExpiredPawns;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category="FortEncounterSettings")
	float BurstSpawnThreatVisualsEndDelayOverride;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category="FortEncounterSettings")
	int32 NumRiftsToUseOverride;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category="FortEncounterSettings")
	uint8 bUseEQSQueryToFindAISpawnLocations : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category="FortEncounterSettings")
	uint8 bRelevantForTotalAICap : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EnvironmentQuery")
	uint8 bEnableRecreateRift : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EnvironmentQuery")
	uint8 bRespawnRiftWhenRiftDead : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EnvironmentQuery")
	uint8 bRandomiseQueryRiftLocations : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EnvironmentQuery")
	uint8 bAvoidRepeatingRiftLocations : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortEncounterSettings")
	uint8 bOverrideEqsFallback : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortEncounterSettings")
	FEncounterEnvironmentQueryInfo EqsFallbackOverride;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EnvironmentQuery")
	float PreSpawnRequeryTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawning")
	float SpawnAIIntervalTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawning")
	float SpawnRiftIntervalTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawning")
	bool bSpawnFirstRiftNoDelay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EnvironmentQuery")
	TObjectPtr<UEnvQuery> RiftSelectionQuery;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EnvironmentQuery")
	TObjectPtr<UEnvQuery> RiftSlotsEQSQueryOverride;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawning")
	TArray<TObjectPtr<AActor>> ScriptedSpawnPoints;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RiftType")
	TSubclassOf<ABuildingRift> RiftClassOverride;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AActor>> WorkingScriptedSpawnPoints;

	UPROPERTY(Transient)
	int32 EncounterGroupID;

	UPROPERTY(Transient)
	int32 ZoneIndex;

	UPROPERTY(Transient)
	int32 DifficultyIndex;

	UPROPERTY(Transient)
	float AIDespawnDistanceOverride;

	UPROPERTY(Transient)
	bool bAIDespawnWhenTooFar;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Difficulty")
	TArray<TObjectPtr<UFortDifficultyOptionCategoryEncounter>> InjectedOverrideCategories;

};

USTRUCT(BlueprintType)
struct FFortEncounterSettingsFixedPace
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	float RiftSpawnInterval;

	UPROPERTY(Transient)
	int32 RiftSpawnCount;

	UPROPERTY(Transient)
	int32 AIMaxCount;

	UPROPERTY(Transient)
	float SpawnAIIntervalTime;

	UPROPERTY(Transient)
	int32 SpawnAIIntervalCount;

};

