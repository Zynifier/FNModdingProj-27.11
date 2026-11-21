// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameFramework/Info.h"
#include "GameFramework/OnlineReplStructs.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Environment/FortWindManager.h"
#include "Missions/MissionSaving/FortMissionManagerRecord.h"
#include "Missions/MissionSaving/MissionSavingTypes.h"
#include "WorldTiles/WorldTileManager.h"
#include "FortWorldManager.generated.h"

class AActor;
class ABuildingActor;
class ABuildingFoundation;
class AWorldTileFoundation;
class UFortItemCacheItemDefinition;
class UFortMissionGenerator;
class UFortMissionInfo;
class UFortUserCloudHelperComponent;
class UFortWorldRecord;
class UFortZoneRecord;
class UFortZoneTheme;
class UWorldTheme;
class UWorldTileManager;

UENUM()
enum EFortLevelStreamingState
{
	// Still streaming in

	LSS_Unloaded = 0,
	// Streamed but not yet processed

	LSS_Loaded = 1,
	// All always-stream foundations have been streamed in and have been updated.

	LSS_UnconditionalFoundationsUpdated = 2,
	// All foundations have been updated, and sublevels have been streamed. Loot quotas haven't been applied yet

	LSS_AllFoundationsUpdated = 3,
	// All new actors have been created, but data has not been serialized on top of them yet

	LSS_NewActorsCreatedButNotUpdated = 4,
	// Loot quotas have been applied and all actors have been updated by the persistence system

	LSS_AllUpdated = 5,
	// Playing

	LSS_Ready = 6,
};

UENUM()
enum class EFortQueuedActionUserStatus : uint8
{
	Succeeded = 0,
	// Processing successful

	Failed = 1,
	// Processing failed

	WaitingForCloudRequest = 2,
	// Awaiting a cloud request to return

	WaitingForProfileSave = 3,
};

UENUM()
enum EFortWorldManagerState
{
	// Actor exists, but nothing else

	WMS_Created = 0,
	// Currently querying the state of the world

	WMS_QueryingWorld = 1,
	// We've finished querying the world state, are ready to load or create

	WMS_WorldQueryComplete = 2,
	// Creating a new world due to a load failure

	WMS_CreatingNewWorld = 3,
	// Loading an existing world

	WMS_LoadingExistingWorld = 4,
	// Done with initialization, running normal ticks

	WMS_Running = 5,
	// In a failed state, world manager will be recreated later, prevent further state changes

	WMS_Failed = 6,
};

UENUM()
enum class EFortWorldRecordAction : uint8
{
	LoadWorldOnly = 0,
	SaveWorldOnly = 1,
	SaveZoneAndWorld = 2,
	LoadZoneAndWorld = 3,
	SaveDeployableBasesAndWorld = 4,
	Max_None = 5,
};

UENUM()
enum class EFortWorldRecordState : uint8
{
	StartProcessing = 0,
	// We haven't started yet

	WaitingForResponse = 1,
	// We're waiting for a callback of some sort

	RetrievingTheaterInformation = 2,
	// Querying the mcp about the global theater data

	RetrievingZoneInformation = 3,
	// Querying the mcp about the zone

	LoadingWorldRecord = 4,
	// We load world records first

	LoadingZoneRecord = 5,
	// We then load a zone record if applicable

	SavingZoneRecord = 6,
	// Sometimes we save a zone record, if we do it's before we save the world record

	SavingPlayerProfiles = 7,
	// Save the profiles of any players, this also saves world metadata

	SavingPlayerDeployableBases = 8,
	// Save dirty deployable bases

	Succeeded = 9,
	// All steps complete, we're done

	Failed = 10,
	// Failed somewhere

	Max_None = 11,
};

USTRUCT()
struct FFortDeferredNewActorData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<ABuildingActor> BuildingActor;

	UPROPERTY()
	int32 SavedLevelIndex;

};

USTRUCT()
struct FFortLevelStreamingInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FName PackageName;

	UPROPERTY()
	TEnumAsByte<EFortLevelStreamingState> LevelState;

	UPROPERTY()
	bool bFailedToLoad;

};

USTRUCT()
struct FFortPIEMissionOverrideData
{
	GENERATED_BODY()

public:
#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="PIEOverride")
	TSoftClassPtr<UFortMissionGenerator> MissionGenerator;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="PIEOverride")
	float GameDifficulty;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="PIEOverride")
	int32 ZoneRecommendedRating;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="PIEOverride")
	bool bIsTestTheater;
#endif

};

USTRUCT()
struct FFortPlacementLocationTagHandler
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<ABuildingActor> SpawnLocationBuildingActor;

	UPROPERTY()
	TObjectPtr<AActor> SpawnedActor;

	UPROPERTY()
	FGameplayTagContainer TagsToRemove;

};

USTRUCT()
struct FFortPlayerEarnedItemCaches
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FUniqueNetIdRepl PlayerID;

	UPROPERTY()
	TArray<TObjectPtr<UFortItemCacheItemDefinition>> EarnedItemCaches;

};

USTRUCT(BlueprintType)
struct FFortStartingMissionInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Objectives")
	TArray<TObjectPtr<UFortMissionInfo>> StartingMissions;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Objectives")
	bool bDisableSharedMissionLoading;

};

USTRUCT()
struct FWorldTileSubArray
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<TObjectPtr<AWorldTileFoundation>> X;

};

UCLASS(Config=Game, MinimalAPI, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortWorldManager : public AInfo
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnRep_InitialGlobalWind();

	UPROPERTY(Transient, Replicated)
	int32 FinalNumChosenBuildingFoundations;

	UPROPERTY(Transient, Replicated)
	TArray<TObjectPtr<ABuildingFoundation>> ChosenBuildingFoundations;

private:
	UPROPERTY()
	TArray<FFortLevelStreamingInfo> StreamedLevels;

	UPROPERTY(Transient)
	TArray<FFortPlacementLocationTagHandler> PlacementLocationTagHandlers;

	UPROPERTY(EditAnywhere, Category="Game")
	uint8 bSavingEnabled : 1;

	UPROPERTY(Config, Transient)
	uint32 SaveFrequency_Seconds;

	UPROPERTY(EditAnywhere, Category="Streaming")
	uint8 bStreamInBuildings : 1;

	UPROPERTY(EditAnywhere, Category="TileManager")
	uint8 bConstructTileWorld : 1;

	UPROPERTY(EditAnywhere, Category="TileManager")
	uint8 bUseSimMaps : 1;

	UPROPERTY(EditAnywhere, Category="Streaming")
	int32 NumNonAutoconstructedTiles;

	UPROPERTY(EditAnywhere, Category="PIE")
	FDataTableRowHandle GameDifficultyRowPIEOverride;

	UPROPERTY(EditAnywhere, Category="PIE")
	TSubclassOf<UFortZoneTheme> ZoneThemeForPIE;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_InitialGlobalWind)
	FFortWindIntensityAndDirection InitialGlobalWind;

	UPROPERTY(Transient)
	TEnumAsByte<EFortWorldManagerState> WorldManagerState;

	UPROPERTY(VisibleAnywhere, Instanced, Category="AFortWorldManager")
	TObjectPtr<UWorldTileManager> TileManager;

	UPROPERTY(EditAnywhere, Category="TileManager")
	int32 X_Size;

	UPROPERTY(EditAnywhere, Category="TileManager")
	int32 Y_Size;

	UPROPERTY(EditAnywhere, Category="TileManager", meta=(ClampMax="80", ClampMin="20", UIMax="80", UIMin="20"))
	int32 Z_StructuralGrid_Size;

	UPROPERTY(EditAnywhere, Category="TileManager")
	int32 VerticalCellNumOffsetFromOrigin;

	UPROPERTY(EditAnywhere, Category="TileManager")
	int32 TileEdgeSize;

	UPROPERTY(EditAnywhere, Category="TileManager")
	TObjectPtr<UWorldTheme> Theme;

	UPROPERTY(EditAnywhere, Category="TileManager")
	FName DefaultLootQuotaCategory;

	UPROPERTY()
	FFortTileLootData LootData;

	UPROPERTY(EditAnywhere, Category="TileManager")
	int32 MaxTiles;

	UPROPERTY(EditAnywhere, Config, Category="TileManager")
	bool bUseFixedSeed;

	UPROPERTY(EditAnywhere, Config, Category="TileManager")
	int32 FixedSeed;

	UPROPERTY()
	TArray<FWorldTileSubArray> Y;

	UPROPERTY(EditAnywhere, Category="Player")
	FVector FriendlyPlayerSpawnExtent;

	UPROPERTY(EditAnywhere, Category="Player")
	FVector PadPlayerSpawnExtent;

	UPROPERTY(EditAnywhere, Category="Player")
	float DangerPlayerSpawnExclusionRadius;

	UPROPERTY(EditAnywhere, Category="Player")
	float ObjectivePlayerSpawnExclusionRadius;

	UPROPERTY(EditAnywhere, Category="Player")
	FGameplayTagContainer OverrideInitialPlayerSpawnTags;

	UPROPERTY(EditAnywhere, Category="Player")
	FGameplayTagContainer OverrideBackupPlayerSpawnTags;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Game")
	FString MissionGenerationDebugString;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Game")
	FFortPIEMissionOverrideData MissionGenerationPIEOverride;
#endif

	UPROPERTY(EditAnywhere, Category="Game")
	FFortStartingMissionInfo StartingMissionInfo;

	UPROPERTY()
	TObjectPtr<UFortWorldRecord> CurrentWorldRecord;

	UPROPERTY()
	TObjectPtr<UFortZoneRecord> CurrentZoneRecord;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortUserCloudHelperComponent> CloudHelper;

	UPROPERTY(Transient)
	int32 CurrentZoneIndex;

	UPROPERTY(Transient)
	bool bHasCreatedMissions;

	UPROPERTY(Transient)
	bool bHasCreatedPrimaryAdditionalFoundations;

	UPROPERTY(Transient)
	bool bHasSpawnedActorsForMissions;

	UPROPERTY(Transient)
	bool bZoneCompleted;

	UPROPERTY(Transient)
	bool bZoneFinished;

	UPROPERTY(Transient)
	bool bCreatedMissionRecord;

	UPROPERTY(Transient)
	FFortMissionManagerRecord MissionManagerRecord;

	UPROPERTY(Transient)
	TArray<FFortMissionEntry> ReactiveMissionsToAdd;

	UPROPERTY()
	TArray<FFortDeferredNewActorData> DeferredActors;

	UPROPERTY(Config)
	int32 MaxConsecutiveFails;

	UPROPERTY(Config)
	bool bClearOutpostMapStats;

	UPROPERTY(Transient)
	TArray<FFortPlayerEarnedItemCaches> UnsavedPlayerEarnedItemCaches;

};

