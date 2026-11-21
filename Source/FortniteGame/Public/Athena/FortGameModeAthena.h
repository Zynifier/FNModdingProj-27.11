// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonInputTypeEnum.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Athena/AthenaStreamIdOverride.h"
#include "Athena/FortGamePvPBase.h"
#include "Athena/FortMutatorContext.h"
#include "Athena/FortPlaylistAthena.h"
#include "FortTypes.h"
#include "Modifiers/GameplayMutatorRegistryInterface.h"
#include "FortGameModeAthena.generated.h"

class AActor;
class ABuildingActor;
class AController;
class AFortAIPawn;
class AFortAthenaAIBotController;
class AFortAthenaSpawningPolicyManager;
class AFortGameplayMutator;
class AFortPawn;
class AFortPlayerControllerAthena;
class AFortPlayerControllerSpectating;
class AFortPlayerStateAthena;
class AFortSafeZoneIndicator;
class AInfo;
class UAthenaAISettings;
class UAthenaCosmeticItemDefinition;
class UDataTable;
class UFortGameFeatureData;
class UFortGameplayModifierItemDefinition;
class UFortMutatorListComponent;
class UObject;

UENUM(BlueprintType)
enum class EAircraftLaunchReason : uint8
{
	/** Aircraft was launched after standard countdown with all players */
	StdTimerAllPlayers = 0,
	/** Aircraft was launched after early countdown with all players */
	EarlyTimerAllPlayers = 1,
	/** Aircraft was launched after standard countdown with > threshold players */
	StdTimerMostPlayers = 2,
	/** Aircraft was launched after early countdown with > threshold players */
	EarlyTimerMostPlayers = 3,
	/** Aircraft was launched after standard countdown with < threshold players */
	StdTimerFewPlayers = 4,
};

UENUM()
enum class EGameModePauseWarmupMaskId : uint8
{
	/** Invalid Bit. */
	None = 0,
	/** A debug cheat or start-up setting is keeping the warmup phase paused. */
	Debug = 1,
	/** A mutator is pausing the warmup phase. */
	Mutator = 2,
	/** The Broadcast controller is pausing the warmup phase. */
	BroadcastController = 4,
	/** The AI Service Player Bots is pausing the warmup phase - bots are still spawning. */
	PlayerBotsSpawning = 8,
	/** Content is still being downloaded. */
	DownloadOnDemand = 16,
	/** The Minigame is expected to update the warmup time to match the pre-game countdown
	* This ensures the warmup phase does not end before that happens */
	Minigame = 32,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FNotifyAIPawnKilled, AController*, KillerController, AFortAIPawn*, KilledPawn, const FGameplayTagContainer&, Tags);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FNotifyGameplayModifiersRegistered);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FNotifySafeZoneChanges);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FNotifySafeZoneIndicatorSpawned, AFortSafeZoneIndicator*, SpawnedSafeZoneIndicator);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayerAddedToAlivePlayers, AController*, Controller);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayerRemovedFromAlivePlayers, AController*, Controller);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlaylistLootTablesApplied);

USTRUCT()
struct FAthenaServerStartAircraftStats
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float WarmupDurationSec;

	UPROPERTY()
	int32 NumPlayersMissing;

	UPROPERTY()
	int32 NumPlayersQuitting;

	UPROPERTY()
	bool bStartedEarly;

	UPROPERTY()
	EAircraftLaunchReason StartReason;

	UPROPERTY()
	int32 ExpectedPlayers;

	UPROPERTY()
	int32 PlayersReadied;

	UPROPERTY()
	int32 PlayersLoadingScreenDropped;

	UPROPERTY()
	FGameplayTagContainer GoldenPoisTags;

};

USTRUCT()
struct FAthenaVehicleOverride
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Event")
	FString RequiredCalendarEvent;

	UPROPERTY(EditAnywhere, Category="Event")
	TSoftClassPtr<AActor> DefaultVehicleClass;

	UPROPERTY(EditAnywhere, Category="Event")
	TSoftClassPtr<AActor> OverrideVehicleClass;

};

USTRUCT()
struct FClearAreaParams
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FVector Location;

	UPROPERTY()
	float CapsuleHalfHeight;

	UPROPERTY()
	float CapsuleRadius;

	UPROPERTY()
	FGameplayTagContainer IgnoreTags;

};

USTRUCT()
struct FFortEndGamePhaseStartedEvent
{
	GENERATED_BODY()

};

USTRUCT()
struct FFortGracefulShutdownInitiatedEvent
{
	GENERATED_BODY()

};

USTRUCT()
struct FFortMeshServerPerfEvent
{
	GENERATED_BODY()

};

USTRUCT()
struct FFortPlayerRemovedFromAlivePlayersEvent
{
	GENERATED_BODY()

};

USTRUCT()
struct FFortUpdateScoringLogicEvent
{
	GENERATED_BODY()

};

USTRUCT()
struct FGCSettingsOverride
{
	GENERATED_BODY()

public:
	UPROPERTY(Config)
	FName PlaylistName;

	UPROPERTY(Config)
	bool bEnableGCOnServerDuringMatch;

	UPROPERTY(Config)
	float GCFrequency;

};

USTRUCT()
struct FScorePlacementTable
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<float> Solo;

	UPROPERTY()
	TArray<float> Duos;

	UPROPERTY()
	TArray<float> Squads;

	UPROPERTY()
	TArray<float> FiftyFifty;

	UPROPERTY()
	TArray<float> LargeTeam;

	UPROPERTY()
	TArray<float> MediumTeam;

	UPROPERTY()
	TArray<float> QuickSolo;

	UPROPERTY()
	TArray<float> QuickDuo;

	UPROPERTY()
	TArray<float> QuickSquad;

	UPROPERTY()
	TArray<float> QuickLargeTeam;

	UPROPERTY()
	TArray<float> QuickTwoTeam;

	UPROPERTY()
	TArray<float> QuickMediumTeam;

	UPROPERTY()
	TArray<float> SinglePlacement;

	UPROPERTY()
	TArray<float> Default;

};

USTRUCT()
struct FTimeOfDayOverride
{
	GENERATED_BODY()

public:
	UPROPERTY(Config)
	FName PlaylistName;

	UPROPERTY(Config)
	float TimeOfDay;

	UPROPERTY(Config)
	float TimeOfDaySpeed;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Info", "Rendering", "MovementReplication", "Replication", "Actor", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortGameModeAthena : public AFortGamePvPBase, public IGameplayMutatorObserverInterface, public IFortMutatorOwner
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMapInfoInitialized);

public:
	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	void AddAIClassToReplicationGraph(TSubclassOf<AFortPawn> NewAIClass) const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void AddContentKeysToGameState();

	UFUNCTION(BlueprintCallable)
	virtual void AddMutatorToList(AFortGameplayMutator* Mutator);

	UFUNCTION(BlueprintCallable)
	void EnableGameplayMutator(FGameplayTag MutatorTag, bool bEnable);

	UFUNCTION(BlueprintImplementableEvent)
	void EndGamePhaseStarted();

	UFUNCTION(BlueprintCallable)
	AFortGameplayMutator* GetGameplayMutator(FGameplayTag MutatorTag);

	UFUNCTION(BlueprintNativeEvent)
	AFortGameplayMutator* GetMutatorByClass(const AActor* ContextActor, TSubclassOf<AFortGameplayMutator> MutatorClass);

	UFUNCTION(BlueprintPure)
	bool GetPlaylistEnableBots() const;

	UFUNCTION(BlueprintCallable)
	void GetSquadIds(TArray<uint8>& SquadIds);

	UFUNCTION(BlueprintCallable)
	void GetSquadIdsOfNonSolos(TArray<uint8>& SquadsWithNonSolos);

	UFUNCTION(BlueprintCallable)
	void GetSquadMembers(uint8 SquadId, TArray<AFortPlayerStateAthena*>& SquadMembers);

	UFUNCTION(BlueprintPure)
	TSubclassOf<AActor> GetVehicleClassOverride(TSubclassOf<AActor> DefaultVehicleClass) const;

	UFUNCTION(BlueprintPure)
	bool HavePlaylistLootTablesBeenApplied() const;

	UFUNCTION(BlueprintPure, Category="MapInfo")
	bool IsMapInfoInitialized() const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, meta=(WorldContext="WorldContext"))
	static void RemoveAllLootFromWorld(UObject* WorldContext, int32 ContainersPerIteration = -1, int32 PickupsPerIteration = -1, float TimeBetweenIterations = 0.000000f, bool bProcessContainersAndPickupsConcurrently = false);

	UFUNCTION(BlueprintCallable)
	virtual void RemoveMutatorFromList(AFortGameplayMutator* Mutator);

	UFUNCTION(BlueprintCallable)
	void SetTimeOfDayManagerGameplayOverride(TSubclassOf<AInfo> TimeOfDayManagerClass);

	UFUNCTION(BlueprintPure)
	bool ShouldForceSpawnInsideOfVolume() const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, meta=(WorldContext="WorldContext"))
	static void StopRemovingAllLoot(UObject* WorldContext, bool bImmediateCleanup = false);

	UPROPERTY(BlueprintReadWrite, BlueprintAssignable, Category="AI")
	FNotifyAIPawnKilled OnAIPawnKilled;

	UPROPERTY(BlueprintAssignable)
	FOnPlayerAddedToAlivePlayers OnPlayerAddedToAlivePlayers;

	UPROPERTY(BlueprintAssignable)
	FOnPlayerRemovedFromAlivePlayers OnPlayerRemovedFromAlivePlayers;

	UPROPERTY()
	bool bAlwaysDBNO;

	UPROPERTY(EditDefaultsOnly, Category="XP Data")
	FScalableFloat KillStreakTime;

	UPROPERTY(Config)
	bool bEnableSendingIndividualTournamentScoresOnLogout;

	UPROPERTY(EditDefaultsOnly, Category="FortGameModeAthena")
	bool bNeverSpawnPickupsOnPawnDeath;

	UPROPERTY(Config)
	bool bLoadTestCosmetics;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortGameModeAthena")
	TSubclassOf<AInfo> TimeOfDayManagerGameplayOverride;

	UPROPERTY(Config)
	bool bEnableCompetitiveDDoSDetectionMatchInvalidation;

	UPROPERTY(Config)
	FString DDoSDetectionMatchInvalidationSeverity;

	UPROPERTY(Config)
	int32 DDoSDetectionMatchInvalidationCount;

	UPROPERTY(Config)
	float DDoSDetectionMatchInvalidationEvalDurationSeconds;

	UPROPERTY(Config)
	TArray<FString> ReticulatedSplineDefinitions;

	UPROPERTY(Config)
	bool bReticulateSplineKeysOnStart;

	UPROPERTY(Config)
	TArray<FAthenaStreamIdOverride> ReticulatedSplineIds;

protected:
	UFUNCTION()
	void OnCheckForOrphanedServer(bool bFromPlayerLogout, bool bConsiderPendingPlayers);

	UFUNCTION()
	void OnEndGameKickPlayers();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void UpdateLootForBuildingContainers();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void UpdateToNewLootTables();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void UpdateToNewLootTablesAsync();

	UPROPERTY(BlueprintAssignable, Category="MapInfo")
	FOnMapInfoInitialized OnMapInfoInitialized;

	UPROPERTY(Transient)
	bool bMapInfoInitialized;

	UPROPERTY(Transient)
	bool bAllGameplayModifiersRegistered;

	UPROPERTY()
	TArray<TObjectPtr<ABuildingActor>> ActorsToClear;

	UPROPERTY()
	TArray<TObjectPtr<AActor>> ClearAreaIgnoreActors;

	UPROPERTY(Config)
	uint8 bDisable3DVoiceChat : 1;

	UPROPERTY(Config)
	TArray<FTimeOfDayOverride> TimeOfDayOverrideList;

	UPROPERTY(Config)
	bool bDisableGCOnServerDuringMatch;

	UPROPERTY(Config)
	TArray<FGCSettingsOverride> GCSettingsOverrideList;

	UPROPERTY(Transient)
	bool bPlaylistHotfixChangedGCDisabling;

	UPROPERTY(Transient)
	float PlaylistHotfixOriginalGCFrequency;

	UPROPERTY(Config)
	bool bUseSkydiveLeader;

	UPROPERTY(Config)
	bool bUseSkydiveLeaderInSplitScreen;

	UPROPERTY(Config)
	float OverloadedInitialConnectTimeout;

	UPROPERTY(Config)
	float FailedToStartMatchTimeout;

	UPROPERTY(Config)
	float OrphanedServerCheckTime;

	UPROPERTY(Config)
	bool bEnableRecentPlayersUpdates;

	UPROPERTY(EditDefaultsOnly, Category="Storm Cap System")
	FScalableFloat PlaylistSupportsStormCapSystem;

	UPROPERTY(EditDefaultsOnly, Category="Bots")
	FScalableFloat PlaylistEnableBots;

	UPROPERTY(EditDefaultsOnly, Category="Bots")
	FScalableFloat PlaylistEnableBotSpectate;

	UPROPERTY(EditDefaultsOnly, Category="Bots")
	FScalableFloat PlaylistEnableBotDynamicELO;

	UPROPERTY(Config)
	bool bAlwaysIncludeDisconnectedTeammates;

	UPROPERTY(Config)
	bool bIncludeDisconnectedTeammatesFromAircraftPhase;

	UPROPERTY(Config)
	EForceKickAfterDeathMode ForceKickAfterDeathMode;

	UPROPERTY(Config)
	float ForceKickAfterDeathTime;

	UPROPERTY(Config)
	bool bRemoveFromSquadOnLogout;

	UPROPERTY(Config)
	bool bIgnoreCanSpectateAfterDeathToken;

	UPROPERTY(Config)
	int32 CreativeModeGracefulShutdownTime;

	UPROPERTY(Config)
	TArray<FHotfixVolumePlacement> HotfixKillVolumes;

	UPROPERTY(Config)
	TArray<FHotfixVolumePlacement> HotfixBlockingVolumes;

	UPROPERTY(Config)
	TArray<FHotfixVolumePlacement> HotfixUndergroundVolumes;

	UPROPERTY(Config)
	TArray<FName> DisableMatchStatsReportingPlaylists;

	UPROPERTY(Config)
	TArray<FName> DisableProgressionReportingPlaylists;

	UPROPERTY(EditDefaultsOnly, Category="Athena")
	int32 MaxPlayerCount;

	UPROPERTY()
	TArray<TObjectPtr<AFortPlayerControllerAthena>> AlivePlayers;

	UPROPERTY()
	TArray<TObjectPtr<AFortAthenaAIBotController>> AliveBots;

	UPROPERTY()
	TArray<int32> TeamAlivePlayers;

	UPROPERTY(EditDefaultsOnly, Category="Warmup")
	int32 WarmupRequiredPlayerCount;

	UPROPERTY(BlueprintReadOnly, Config, Category="EndGame")
	float EndGameKickPlayersDelay_NoIGMM;

	UPROPERTY(BlueprintReadOnly, Config, Category="EndGame")
	float EndGameKickPlayersDelay_IGMM;

	UPROPERTY(Config)
	int32 EventStatSubmitAttempts;

	UPROPERTY()
	FString VoiceChatChannelPositional;

	UPROPERTY(EditDefaultsOnly, Config, Category="FortGameModeAthena")
	bool bUseRandomTimeOfDay;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Instanced, Category="AI")
	TObjectPtr<UAthenaAISettings> AISettings;

	UPROPERTY()
	TArray<TObjectPtr<AFortPlayerControllerSpectating>> LiveSpectators;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, NoClear, Category="Classes")
	TSubclassOf<AFortPlayerControllerSpectating> SpectateAFriendPlayerControllerClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, NoClear, Category="Classes")
	TSubclassOf<AFortPlayerControllerSpectating> LiveBroadcastPlayerControllerClass;

	UPROPERTY(Config)
	TArray<FName> PlatformOSSNamesToUploadStatsV2;

	UPROPERTY(Config)
	TMap<FName, ECommonInputType> LeaderboardStatsDefaultOssInputTypes;

	UPROPERTY(Config)
	TArray<FName> BlacklistedMatchmakingBackfillPlaylists;

	UPROPERTY(EditDefaultsOnly, Config, Category="FortGameModeAthena")
	bool bEnableMatchmakingRatingUpdateV2;

	UPROPERTY(EditDefaultsOnly, Config, Category="FortGameModeAthena")
	float ScorePerMinuteAlive;

	UPROPERTY(EditDefaultsOnly, Config, Category="FortGameModeAthena")
	float ScoreMaxMinutesAliveCounted;

	UPROPERTY(EditDefaultsOnly, Config, Category="FortGameModeAthena")
	float ScoreForGettingAtLeastOneKill;

	UPROPERTY(EditDefaultsOnly, Config, Category="FortGameModeAthena")
	float ScorePerScaledTeamKill;

	UPROPERTY(EditDefaultsOnly, Config, Category="FortGameModeAthena")
	float ScoreForFirstRevive;

	UPROPERTY(EditDefaultsOnly, Config, Category="FortGameModeAthena")
	float ScoreForSubsequentRevives;

	UPROPERTY(EditDefaultsOnly, Config, Category="FortGameModeAthena")
	int32 MaxAdditionalRevivesToScore;

	UPROPERTY(EditDefaultsOnly, Config, Category="FortGameModeAthena")
	FScorePlacementTable ScorePlacementTables;

	UPROPERTY(EditDefaultsOnly, Config, Category="FortGameModeAthena")
	float ScoreMultiplier;

	UPROPERTY(EditDefaultsOnly, Config, Category="AI")
	int32 MaxActiveAIActors;

	UPROPERTY(Config)
	bool bLockMobilePlayersToTouchInSwitchPool;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Export, Category="FortGameModeAthena", meta=(EditInline="true"))
	TObjectPtr<UFortMutatorListComponent> MutatorListComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortGameModeAthena")
	TArray<TObjectPtr<UFortGameplayModifierItemDefinition>> CoreGameModeModifiers;

	UPROPERTY(Config)
	TArray<FName> SupportedAthenaLootTierGroups;

	UPROPERTY(Config)
	TMap<FName, FName> RedirectAthenaLootTierGroups;

	UPROPERTY(Config)
	bool bIsSpawningNewLootSync;

	UPROPERTY(BlueprintAssignable)
	FOnPlaylistLootTablesApplied OnPlaylistLootTablesAppliedDelegate;

private:
	UPROPERTY(Config)
	uint8 MaxOpenInventoryLockFailRetries;

	UPROPERTY(Config)
	float OpenInventoryRetryTime;

	UPROPERTY(Transient)
	bool bAllCosmeticsLoaded;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UAthenaCosmeticItemDefinition>> SkyDiveContrailCosmetics;

	UPROPERTY(Transient)
	int32 SkyDiveContrailLoadTestIndex;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UAthenaCosmeticItemDefinition>> GliderCosmetics;

	UPROPERTY(Transient)
	int32 GliderLoadTestIndex;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UAthenaCosmeticItemDefinition>> PickaxeCosmetics;

	UPROPERTY(Transient)
	int32 PickaxeLoadTestIndex;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UAthenaCosmeticItemDefinition>> CharacterCosmetics;

	UPROPERTY(Transient)
	int32 CharacterLoadTestIndex;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UAthenaCosmeticItemDefinition>> HatCosmetics;

	UPROPERTY(Transient)
	int32 HatLoadTestIndex;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UAthenaCosmeticItemDefinition>> BackpackCosmetics;

	UPROPERTY(Transient)
	int32 BackpackLoadTestIndex;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UAthenaCosmeticItemDefinition>> DanceCosmetics;

	UPROPERTY(Transient)
	int32 DanceLoadTestIndex;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UAthenaCosmeticItemDefinition>> VictoryPoseCosmetics;

	UPROPERTY(Transient)
	int32 VictoryPoseLoadTestIndex;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UAthenaCosmeticItemDefinition>> MapMarkerCosmetics;

	UPROPERTY(Transient)
	int32 MapMarkerLoadTestIndex;

	UPROPERTY(Transient)
	int32 PetLoadTestIndex;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UAthenaCosmeticItemDefinition>> ConsumableEmoteCosmetics;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UAthenaCosmeticItemDefinition>> LoadingScreenCosmetics;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UAthenaCosmeticItemDefinition>> BattleBusCosmetics;

	UPROPERTY(Transient)
	TObjectPtr<AFortAthenaSpawningPolicyManager> SpawningPolicyManager;

	UPROPERTY(Transient)
	TArray<FAthenaVehicleOverride> AthenaVehicleOverrides;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UAthenaCosmeticItemDefinition>> ItemWrapCosmetics;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UAthenaCosmeticItemDefinition>> MusicPacks;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UAthenaCosmeticItemDefinition>> CharmCosmetics;

	UPROPERTY(Transient)
	TArray<TSoftObjectPtr<UDataTable>> GameFeatureLootTierData;

	UPROPERTY(Transient)
	TArray<TSoftObjectPtr<UDataTable>> GameFeatureLootPackageData;

	UPROPERTY(Transient)
	TArray<TWeakObjectPtr<UFortGameFeatureData>> GameFeaturesStreamingRangedWeaponData;

};

