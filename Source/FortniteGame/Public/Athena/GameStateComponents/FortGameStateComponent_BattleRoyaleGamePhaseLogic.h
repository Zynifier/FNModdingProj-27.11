// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Styling/SlateBrush.h"
#include "Athena/AthenaGamePhaseEnum.h"
#include "Athena/FortAthenaMapInfo.h"
#include "Athena/FortGameModeAthena.h"
#include "Athena/FortGameStateAthena.h"
#include "Athena/FortGameStateAthenaEnums.h"
#include "Athena/FortPlaylistAthena.h"
#include "Components/FortGameStateComponent.h"
#include "Creative/FortSafeZoneInterface.h"
#include "Creative/FortTimeWidgetInterface.h"
#include "FortGameMode.h"
#include "Pawns/FortPawn.h"
#include "FortGameStateComponent_BattleRoyaleGamePhaseLogic.generated.h"

class AActor;
class AFortAthenaAircraft;
class AFortAthenaSupplyDrop;
class AFortSafeZoneIndicator;
class AFortTeamPrivateInfo;
class AHUD;
class AMegaStormManager;
class UCanvas;
class UFortAthenaExitCraftInfo;
class UFortGameStateComponent_BattleRoyaleGamePhaseLogic;
class UFortSpawnActorInfo;
class UFortSupplyDropInfo;
class UGameplayEffect;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class UObject;
enum class EAirCraftBehavior : uint8;
enum class EAthenaGamePhase : uint8;
enum class EAthenaGamePhaseStep : uint8;

USTRUCT()
struct FBuildingGameplayActorSpawnData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 BGAIndex;

	UPROPERTY()
	int32 NumSpawnedBGAs;

	UPROPERTY()
	int32 NumBGAsToSpawn;

	UPROPERTY()
	float NextSpawnTime;

	UPROPERTY()
	EBuildingGameplayActorAircraftSpawnSide LastSpawnSide;

};

USTRUCT()
struct FExitCraftSpawnData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UFortAthenaExitCraftInfo> ExitCraftInfo;

};

USTRUCT(BlueprintType)
struct FORTNITEGAME_API FFortBattleRoyaleGamePhaseLogicComponentReadyEvent
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortBattleRoyaleGamePhaseLogicComponentReadyEvent")
	TWeakObjectPtr<UFortGameStateComponent_BattleRoyaleGamePhaseLogic> GamePhaseLogic;

};

USTRUCT(BlueprintType)
struct FORTNITEGAME_API FFortGamePhaseStepUpdatedEvent
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortGamePhaseStepUpdatedEvent")
	EAthenaGamePhaseStep GamePhaseStep;

};

USTRUCT(BlueprintType)
struct FORTNITEGAME_API FFortGamePhaseUpdatedEvent
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortGamePhaseUpdatedEvent")
	EAthenaGamePhase GamePhase;

};

USTRUCT(BlueprintType)
struct FORTNITEGAME_API FFortSafeZoneIndicatorUpdatedEvent
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortSafeZoneIndicatorUpdatedEvent")
	TWeakObjectPtr<AFortSafeZoneIndicator> SafeZoneIndicator;

};

USTRUCT(BlueprintType)
struct FORTNITEGAME_API FFortSafeZoneLocationsInitializedEvent
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FORTNITEGAME_API FFortSafeZonePhaseUpdatedEvent
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortSafeZonePhaseUpdatedEvent")
	int32 SafeZonePhaseIndex;

	UPROPERTY(BlueprintReadOnly, Category="FortSafeZonePhaseUpdatedEvent")
	int32 SafeZonePhaseForUI;

};

USTRUCT()
struct FFortSpawnActorData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UFortSpawnActorInfo> SpawnActorInfo;

	UPROPERTY()
	int32 NumSpawnsRemaining;

	UPROPERTY()
	float TimeUntilNextSpawn;

	UPROPERTY()
	TArray<TObjectPtr<AActor>> SpawnedFortSpawnActors;

};

USTRUCT(BlueprintType)
struct FFortStormCapStateUpdatedEvent
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortStormCapStateUpdatedEvent")
	EAthenaStormCapState StormCapState;

};

USTRUCT(BlueprintType)
struct FFortStormProgressUpdatedEvent
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortStormProgressUpdatedEvent")
	bool bStormStopped;

};

USTRUCT(BlueprintType)
struct FFortWarmupCountdownEndTimeUpdatedEvent
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortWarmupCountdownEndTimeUpdatedEvent")
	float EndTime;

};

USTRUCT()
struct FStormCapDamageThresholdInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float ThresholdFloor;

	UPROPERTY()
	float ThresholdCeiling;

};

USTRUCT()
struct FSupplyDropItemDeliverySpawnData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 NumItemsToDeliver;

	UPROPERTY()
	TArray<float> QueuedSpawnTimes;

	UPROPERTY()
	float NextSpawnTime;

	UPROPERTY()
	int32 NumInitialSpawns;

};

USTRUCT()
struct FSupplyDropZoneBasedSpawnData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<TObjectPtr<AFortAthenaSupplyDrop>> SpawnedSupplyDrops;

	UPROPERTY()
	int32 NumDropsRemainingInWave;

	UPROPERTY()
	float NextWaveSpawnTime;

	UPROPERTY()
	float NextSpawnTime;

	UPROPERTY()
	EAthenaGamePhase CurrGamePhase;

	UPROPERTY()
	int32 CurrSubPhase;

	UPROPERTY()
	int32 TotalSupplyDropsSpawnedInSubPhase;

};

USTRUCT()
struct FSupplyDropSpawnData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UFortSupplyDropInfo> SupplyDropInfo;

	UPROPERTY()
	FSupplyDropZoneBasedSpawnData ZoneBasedData;

	UPROPERTY()
	FSupplyDropItemDeliverySpawnData ItemDeliveryData;

};

UCLASS(Abstract, Config=Game, MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"))
class UFortGameStateComponent_BattleRoyaleGamePhaseLogic : public UFortGameStateComponent, public IFortSafeZoneInterface, public IFortTimeWidgetInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void FinishCurrentStormCircle(float TimeToShrink);

	UFUNCTION(BlueprintPure, Category="BattleRoyaleGamePhaseLogic", meta=(DisplayName="GetBattleRoyaleGamePhaseLogicComponent", WorldContext="WorldContextObject"))
	static UFortGameStateComponent_BattleRoyaleGamePhaseLogic* Get(const UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category="BattleRoyaleGamePhaseLogic")
	EAirCraftBehavior GetAircraftBehavior() const;

	UFUNCTION(BlueprintPure, Category="BattleRoyaleGamePhaseLogic")
	float GetAircraftStartTime() const;

	UFUNCTION(BlueprintPure, Category="BattleRoyaleGamePhaseLogic")
	EAthenaGamePhase GetGamePhase() const;

	UFUNCTION(BlueprintPure, Category="BattleRoyaleGamePhaseLogic")
	EAthenaGamePhaseStep GetGamePhaseStep() const;

	UFUNCTION(BlueprintPure, Category="BattleRoyaleGamePhaseLogic")
	float GetGamePhaseStepTimeRemaining() const;

	UFUNCTION(BlueprintPure, Category="BattleRoyaleGamePhaseLogic")
	int32 GetSafeZonePhaseForUI() const;

	UFUNCTION(BlueprintPure, Category="BattleRoyaleGamePhaseLogic")
	int32 GetSafeZonePhaseIndex() const;

	UFUNCTION(BlueprintPure, Category="BattleRoyaleGamePhaseLogic")
	float GetSafeZonesStartTime() const;

	UFUNCTION(BlueprintPure, Category="BattleRoyaleGamePhaseLogic")
	float GetWarmupCountdownEndTime() const;

	UFUNCTION(BlueprintPure, Category="BattleRoyaleGamePhaseLogic")
	float GetWarmupCountdownStartTime() const;

	UFUNCTION(BlueprintCallable, Category="BattleRoyaleGamePhaseLogic")
	void InitializeSafeZoneLocations();

	UFUNCTION(BlueprintPure, Category="BattleRoyaleGamePhaseLogic")
	bool IsInCurrentSafeZone(const FVector& TestLocation, bool bClassicSafeZoneOnly = false) const;

	UFUNCTION(BlueprintCallable, Category="BattleRoyaleGamePhaseLogic")
	void JumpToSafeZonePhase();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void SetAircraftFlightPath(float StartDegrees = 0.000000f, float OffsetFactor = 0.000000f);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="BattleRoyaleGamePhaseLogic")
	void SetAircrafts(const TArray<AFortAthenaAircraft*>& InAircrafts);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void SetRandomAircraftFlightPath();

	UFUNCTION(BlueprintCallable, Category="BattleRoyaleGamePhaseLogic")
	void SetSafeZonesStartTime(const float InValue);

	UFUNCTION(BlueprintCallable, Category="BattleRoyaleGamePhaseLogic")
	void SetStormDamagePaused(bool bPause);

protected:
	UFUNCTION()
	void OnAircraftEnteredDropZone(AFortAthenaAircraft* FortAthenaAircraft);

	UFUNCTION()
	void OnAircraftExitedDropZone(AFortAthenaAircraft* FortAthenaAircraft);

	UFUNCTION()
	void OnAircraftFlightEnded(AFortAthenaAircraft* FortAthenaAircraft);

	UFUNCTION()
	void OnSafeZonePhaseChanged();

	UPROPERTY(EditDefaultsOnly, Category="SafeZone")
	TSubclassOf<UGameplayEffect> GE_OutsideSafeZone;

	UPROPERTY(EditDefaultsOnly, Category="SafeZone")
	TSubclassOf<UGameplayEffect> GE_OutsideSafeZoneCN;

	UPROPERTY(EditDefaultsOnly, Category="SafeZone")
	TSubclassOf<AFortSafeZoneIndicator> SafeZoneIndicatorClass;

	UPROPERTY(EditDefaultsOnly, Category="SafeZone")
	TSubclassOf<AMegaStormManager> MegaStormManagerClass;

	UPROPERTY(EditDefaultsOnly, Category="MiniMap")
	TSoftObjectPtr<UMaterialInterface> FullMapDebugCircleDrawingMaterial;

	UPROPERTY(EditDefaultsOnly, Category="MiniMap")
	int32 TotalMinimapDebugCirclesSupported;

	UPROPERTY(EditDefaultsOnly, Category="SafeZone")
	FScalableFloat SkyTubeDisablePhase;

	UPROPERTY(EditDefaultsOnly, Category="Storm Cap System")
	FScalableFloat TimeBetweenStormCapDamage;

	UPROPERTY(EditDefaultsOnly, Category="Storm Cap System")
	FScalableFloat StormCapDamagePerTick;

	UPROPERTY(EditDefaultsOnly, Category="SafeZone")
	FScalableFloat StormCampingInitialDelayTime;

	UPROPERTY(EditDefaultsOnly, Category="SafeZone")
	FScalableFloat StormCampingIncrementTimeAfterDelay;

	UPROPERTY(EditDefaultsOnly, Category="SafeZone")
	FScalableFloat StormCampingDamageMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="Storm Cap System")
	FScalableFloat PlaylistSupportsStormCapSystem;

	UPROPERTY(EditDefaultsOnly, Category="Safezone")
	FScalableFloat SafeZoneDamageAttribute;

	UPROPERTY(Config)
	bool bDisableStormCapSystem;

	UPROPERTY(Config)
	bool bAllowDamageInWarmup;

	UPROPERTY(Config)
	float DelayForStormCapWarning;

	UPROPERTY(Config)
	float DelayForStormCapDamage;

	UPROPERTY(Config)
	float DefaultWarmupEarlyRequiredPlayerPercent;

	UPROPERTY(EditDefaultsOnly, Config, Category="Warmup")
	float WarmupCountdownDuration;

	UPROPERTY(EditDefaultsOnly, Config, Category="Warmup")
	float WarmupEarlyCountdownDuration;

	UPROPERTY(Config)
	float StartAircraftPhaseRequiredAlivePlayersPercent;

	UPROPERTY(Config)
	float EndAircraftPhaseRequiredAlivePlayersPercent;

	UPROPERTY(Config)
	bool bEnableCompetitiveMissingPlayerMatchInvalidation;

	UPROPERTY(Config)
	TArray<FName> ExcludedDefaultSupplyDrops;

	UPROPERTY(Config)
	TArray<FName> ExcludedLTMSupplyDrops;

	UPROPERTY(Config)
	TArray<FName> ExcludedLTMSpawnActors;

private:
	UFUNCTION()
	void DrawDebugSafeZoneHUD(AHUD* HUD, UCanvas* Canvas);

	UFUNCTION()
	void FireServerPerformanceEvent();

	UFUNCTION()
	void HandleEndGamePhaseStarted(const FFortEndGamePhaseStartedEvent& Event);

	UFUNCTION()
	void HandleGamePhaseStepChanged(const EAthenaGamePhaseStep InGamePhaseStep);

	UFUNCTION()
	void HandleGracefulShutdownInitiated(const FFortGracefulShutdownInitiatedEvent& Event);

	UFUNCTION()
	void HandleMatchmakingAssigned(const FFortMatchmakingSessionAssignedEvent& Event);

	UFUNCTION()
	void HandleMeshServerPerfEvent(const FFortMeshServerPerfEvent& Event);

	UFUNCTION()
	void HandlePawnPossessed(const FFortPawnPossessed& Event);

	UFUNCTION()
	void HandlePawnUnpossessed(const FFortPawnUnpossessed& Event);

	UFUNCTION()
	void HandlePlayerRemovedFromAlivePlayers(const FFortPlayerRemovedFromAlivePlayersEvent& Event);

	UFUNCTION()
	void HandlePlayersLeftChanged(const FFortPlayersLeftChangedEvent& Event);

	UFUNCTION()
	void HandlePlaylistDataLoaded(FName PlaylistName, const FGameplayTagContainer& PlaylistContextTags);

	UFUNCTION()
	void HandleUpdateScoringLogic(const FFortUpdateScoringLogicEvent& Event);

	UFUNCTION()
	void OnRep_Aircrafts();

	UFUNCTION()
	void OnRep_bPlaylistStoppedSafeZonePhases();

	UFUNCTION()
	void OnRep_GamePhase(const EAthenaGamePhase OldGamePhase);

	UFUNCTION()
	void OnRep_PlaylistEndTime();

	UFUNCTION()
	void OnRep_SafeZoneIndicator();

	UFUNCTION()
	void OnRep_StormCapState();

	UFUNCTION()
	void OnRep_WarmupCountdownEndTime();

	UPROPERTY(ReplicatedUsing=OnRep_SafeZoneIndicator)
	TObjectPtr<AFortSafeZoneIndicator> SafeZoneIndicator;

	UPROPERTY(Transient)
	TObjectPtr<AMegaStormManager> MegaStormManager;

	UPROPERTY(Transient)
	TObjectPtr<UMaterialInstanceDynamic> FullMapDebugCircleMID;

	UPROPERTY(Transient)
	FSlateBrush FullMapDebugCircleBrush;

	UPROPERTY(Transient)
	TArray<FBuildingGameplayActorSpawnData> BuildingGameplayActorSpawnData;

	UPROPERTY(Transient)
	TArray<FSupplyDropSpawnData> SupplyDropSpawnDataList;

	UPROPERTY(Transient)
	TArray<FFortSpawnActorData> SpawnActorDataList;

	UPROPERTY(Transient)
	TArray<TWeakObjectPtr<AFortAthenaAircraft>> Aircrafts_GameMode;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_Aircrafts)
	TArray<TWeakObjectPtr<AFortAthenaAircraft>> Aircrafts_GameState;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortTeamPrivateInfo>> SortedStormCapPrivateTeams;

	UPROPERTY(Transient)
	FExitCraftSpawnData ExitCraftSpawnData;

	UPROPERTY(ReplicatedUsing=OnRep_GamePhase)
	EAthenaGamePhase GamePhase;

	UPROPERTY(Transient)
	EAthenaGamePhaseStep GamePhaseStep;

	UPROPERTY(Replicated)
	EAirCraftBehavior AirCraftBehavior;

	UPROPERTY(ReplicatedUsing=OnRep_StormCapState)
	EAthenaStormCapState StormCapState;

	UPROPERTY(Replicated)
	FStormCapDamageThresholdInfo DamageForStormCapMarking;

	UPROPERTY(ReplicatedUsing=OnRep_bPlaylistStoppedSafeZonePhases)
	bool bPlaylistStoppedSafeZonePhases;

	UPROPERTY(Replicated)
	bool bGameModeWillSkipAircraft;

	UPROPERTY(Replicated)
	bool bAircraftIsLocked;

	UPROPERTY(Replicated)
	bool bIsInCountdown;

	UPROPERTY(Replicated)
	bool bIsInFinalCountdown;

	UPROPERTY(Replicated)
	float WarmupCountdownStartTime;

	UPROPERTY(ReplicatedUsing=OnRep_WarmupCountdownEndTime)
	float WarmupCountdownEndTime;

	UPROPERTY(Replicated)
	float AircraftStartTime;

	UPROPERTY(Replicated)
	double AircraftRealStartTime;

	UPROPERTY(Replicated)
	float SafeZonesStartTime;

	UPROPERTY(Replicated)
	float SafeZonePauseTime;

	UPROPERTY(ReplicatedUsing=OnRep_PlaylistEndTime)
	float PlaylistEndTime;

	UPROPERTY(Replicated)
	int32 TotalFinalCountdownTime;

};

