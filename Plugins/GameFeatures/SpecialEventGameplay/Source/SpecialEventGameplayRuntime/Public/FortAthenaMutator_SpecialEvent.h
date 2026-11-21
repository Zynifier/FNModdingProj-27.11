// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Athena/AircraftFlightInfo.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortTypes.h"
#include "Items/FortItemTypeEnum.h"
#include "Player/FortCheatManager_Coupled.h"
#include "FortAthenaMutator_SpecialEvent.generated.h"

class AActor;
class AFortAthenaAircraft;
class AFortPlayerController;
class AFortPlayerControllerAthena;
class AFortPlayerPawn;
class AFortPlayerPawnAthena;
class APlayerState;
class ASpecialEventPlayerMannequin;
class ASpecialEventScript;
class UCustomCharacterPart;
class UFortControllerComponent_SpecialEvent;
class UGameplayEffect;
class UInputComponent;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FGenericSpecialEvent);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnClientInitialLoadingFinished);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHandleLogout, APlayerState*, PlayerState);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInitController, AFortPlayerControllerAthena*, NewPlayer);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPawnLoaded, AFortPlayerPawnAthena*, NewPawn);

USTRUCT(BlueprintType)
struct FSpecialClientEvent
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="SpecialClientEvent")
	TObjectPtr<AFortPlayerControllerAthena> PlayerController;

	UPROPERTY(BlueprintReadOnly, Category="SpecialClientEvent")
	float TimeSeconds;

	UPROPERTY(BlueprintReadOnly, Category="SpecialClientEvent")
	FGameplayTag EventTag;

	UPROPERTY(BlueprintReadOnly, Category="SpecialClientEvent")
	int32 Count;

};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSpecialClientEvent, FSpecialClientEvent, ClientEventData);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTeleportAllPlayersFinished);

USTRUCT(BlueprintType)
struct FFortDelayRTMMData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	bool bDelayRTTM;

	UPROPERTY()
	float MinRTTMDelay;

	UPROPERTY()
	float MaxRTTMDelay;

	UPROPERTY()
	float TimeStamp;

};

USTRUCT()
struct FFortSpecialEventGEData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortSpecialEventGEData")
	TSubclassOf<UGameplayEffect> GameplayEffect;

	UPROPERTY(EditAnywhere, Category="FortSpecialEventGEData")
	int32 Level;

};

USTRUCT()
struct FFortSpecialEventOverrideParts
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortSpecialEventOverrideParts")
	TArray<TObjectPtr<UCustomCharacterPart>> OverrideParts;

	UPROPERTY(EditAnywhere, Category="FortSpecialEventOverrideParts")
	FFortSpecialEventGEData GameplayEffectToApplyOnSwap;

};

USTRUCT()
struct FSpecialEventMapData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, NotReplicated, Category="SpecialEventMapData")
	FGameplayTag MapTag;

	UPROPERTY(EditDefaultsOnly, NotReplicated, Category="SpecialEventMapData")
	TArray<FName> MapNames;

	UPROPERTY()
	bool bReplicatedHasBeenUnloaded;

	UPROPERTY(NotReplicated)
	bool bHasBeenUnloaded;

};

UCLASS(Config=Game, MinimalAPI, BlueprintType, HideCategories=("Tick", "Replication", "Actor", "LOD", "Cooking", "Mutator", "FortAthenaMutator", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_SpecialEvent : public AFortAthenaMutator
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Event", meta=(DisplayName="Add Client CSV Event"))
	void AddClientCSVEvent(const FString& CSVEventName);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Event", meta=(DisplayName="Add CSV Event"))
	void AddCSVEvent(const FString& CSVEventName, bool bShouldRepToClient = true);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Event")
	void AddToBlockedNativeActions(const FGameplayTagContainer& Actions, const bool bCancelAbilities = false);

	UFUNCTION(BlueprintCallable, Category="Event|WinCondition")
	void AutobalanceTargetScore();

	UFUNCTION(BlueprintCallable, Category="Event|WinCondition")
	void ChangeWinCondition(float NewGoalScore);

	UFUNCTION(BlueprintCallable, Category="Event")
	void ClearAdditionalViewpoint();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Event")
	void ClearBlockedNativeActions();

	UFUNCTION(BlueprintCallable, Category="Misc")
	void CloseParachutes();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Event")
	void FlushUnhandledPlayerControllers();

	UFUNCTION(BlueprintCallable, Category="Storm")
	void ForceSafeZoneFinalLocation(FVector NewFinalLocation, float DefaultAircraftOffsetFromMidLine = 0.000000f, float MinDefaultMidlineAngle = 0.000000f, float MaxDefaultMidlineAngle = 360.000000f);

	UFUNCTION(BlueprintPure, Category="Misc")
	bool GetHasInfiniteSafeZonePhase() const;

	UFUNCTION(BlueprintPure, Category="Event")
	ASpecialEventScript* GetScript() const;

	UFUNCTION(BlueprintCallable, Category="Event")
	void JumpToSafeZonePhase(FVector PawnSpawnCenterLocation, float PawnSpawnMinDistance, float PawnSpawnMaxDistance);

	UFUNCTION(NetMulticast, Reliable)
	void NetMulticast_CheatClearSpecialEventGameUserSettings();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Event")
	void NotifyClientsGameResumed();

	UFUNCTION()
	void OnGameViewportActivationChanged(bool bHasFocus);

	UFUNCTION(BlueprintCallable, Category="Storm")
	void PauseStormDamage(bool bPause);

	UFUNCTION(BlueprintCallable, Category="Storm")
	void PauseStormProgression(bool bPause);

	UFUNCTION(BlueprintCallable, Category="Misc")
	void PauseSupplyDrops(bool bPause);

	UFUNCTION(BlueprintCallable, Category="Event|WinCondition")
	void PauseWinCondition(bool bLockScores = false);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Event")
	void PlacePlayersInAircraft();

	UFUNCTION(BlueprintCallable, Category="Event")
	void PopSpecialEventEmoteInputComponent();

	UFUNCTION(BlueprintCallable, Category="Event")
	void PushSpecialEventEmoteInputComponent();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Event")
	void RemoveFromBlockedNativeActions(const FGameplayTagContainer& Actions);

	UFUNCTION(BlueprintCallable, Category="Event|MatchDuration")
	void ResetMatchTimeToPrevious();

	UFUNCTION(BlueprintCallable, Category="Storm")
	void ResetSafeZoneOverrideAfterEvent(int32 MinResetSafeZoneIndex, float MinDelayReturnToMainMenu = 30.000000f, float MaxDelayReturnToMainMenu = 60.000000f);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Event")
	void ResetSpecialEventAircraft();

	UFUNCTION(BlueprintCallable, Category="Event|WinCondition")
	void ResetWinCondition();

	UFUNCTION(BlueprintCallable, Category="Event|WinCondition")
	void ResetWinConditionProgressToZero();

	UFUNCTION(BlueprintCallable, Category="Event|WinCondition")
	void ResumeWinCondition();

	UFUNCTION(BlueprintCallable, Category="Event|WinCondition")
	void SendToNightNight();

	UFUNCTION(BlueprintCallable, Category="Event")
	void SetAdditionalViewpoint(FVector WorldLocation);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Event")
	void SetCanStreamBuildingFoundationsIn(bool bEnable);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Event")
	void SetDestroyVehiclesInStorm(bool bDestroyVehiclesInStorm);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Event")
	void SetIsSimulatingDamage(bool bIsSimulating);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Event")
	void SetLockingOnFocalPoint(bool bInLockingOnFocalPoint);

	UFUNCTION(BlueprintCallable, Category="Event|MatchDuration")
	void SetMatchTime(int32 NewMatchTime);

	UFUNCTION(BlueprintCallable, Category="Event")
	void SetNamedWeightForContainerLootRoll(const FName WeightName);

	UFUNCTION(BlueprintCallable, Category="Misc")
	void SetReturnToMainMenuDelay(float MinDelayReturnToMainMenu = 30.000000f, float MaxDelayReturnToMainMenu = 60.000000f);

	UFUNCTION(BlueprintCallable, Category="Event")
	void SetWeightForContainerLootRoll(const float Weight);

	UFUNCTION(BlueprintNativeEvent)
	bool ShouldPreventLeavingWarmup() const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Event")
	void ShrinkSafeZone();

	UFUNCTION(BlueprintCallable, Category="Storm")
	void StartSafeZoneOverrideForEvent(int32 SafeZoneIndexForEvent);

	UFUNCTION(BlueprintCallable, Category="Event")
	void SwapBodyParts(const int32 ArrayIndex, AFortPlayerController* FortPC);

	UFUNCTION(BlueprintCallable, Category="Misc")
	void TeleportAllPlayers(FGameplayTagContainer EventTags, int32 TeleportsPerFrame = 10, int32 SafeZoneIndex = -1);

	UFUNCTION(BlueprintCallable, Category="Misc")
	void ToggleAllPlayersInvincibility(bool bInvincible);

	UFUNCTION(BlueprintCallable, Category="Misc")
	void ToggleDisableParachutes(bool bDisable);

	UFUNCTION(BlueprintCallable, Category="Misc")
	void ToggleDisableWeapons(bool bDisableWeapons);

	UFUNCTION(BlueprintCallable, Category="Misc")
	void ToggleHUDs(bool bHide);

	UFUNCTION(BlueprintCallable, Category="Map")
	void UnloadTerrainMaps(const FGameplayTag& MapTag);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Event")
	void WarmUpIslandUpdated();

	UPROPERTY(BlueprintAssignable)
	FOnTeleportAllPlayersFinished TeleportAllPlayersFinished;

	UPROPERTY(BlueprintAssignable)
	FOnPawnLoaded OnPawnLoaded;

	UPROPERTY(BlueprintAssignable)
	FOnInitController OnInitController;

	UPROPERTY(BlueprintAssignable)
	FGenericSpecialEvent OnResumeGame;

	UPROPERTY(BlueprintAssignable)
	FOnSpecialClientEvent OnSpecialClientEvent;

	UPROPERTY(BlueprintAssignable)
	FOnHandleLogout OnHandleLogout;

	UPROPERTY(BlueprintAssignable)
	FOnClientInitialLoadingFinished OnClientInitialLoadingFinished;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Event")
	bool bCanToggleCursorModeInStasis;

protected:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void ForceSetMatchmakingBackfill(bool bEnableBackfill);

	UFUNCTION()
	void HandleSpecialEventMannequinDestroyed(AActor* MannequinActor);

	UFUNCTION(BlueprintImplementableEvent)
	void OnActorPreSpawnInitialization(AActor* Actor);

	UFUNCTION(BlueprintImplementableEvent)
	void OnActorSpawned(AActor* Actor);

	UFUNCTION()
	void OnAircraftEnteredDropZone(AFortAthenaAircraft* FortAthenaAircraft);

	UFUNCTION()
	void OnAircraftExitedDropZone(AFortAthenaAircraft* FortAthenaAircraft);

	UFUNCTION()
	void OnAircraftFlightEnded(AFortAthenaAircraft* FortAthenaAircraft);

	UFUNCTION()
	void OnRep_AdditionalViewpoint();

	UFUNCTION()
	void OnRep_Aircraft();

	UFUNCTION()
	void OnRep_AllPlayerTeleportedCount();

	UFUNCTION()
	void OnRep_bCanStreamBuildingFoundationsIn();

	UFUNCTION()
	void OnRep_bDisableHUD();

	UFUNCTION()
	void OnRep_bLockingOnFocalPoint();

	UFUNCTION()
	void OnRep_bPlayersAreInvincible();

	UFUNCTION()
	void OnRep_DelayPlayersFromReturningToLobbyData();

	UFUNCTION()
	void OnRep_GameResumed();

	UFUNCTION()
	void OnRep_LastCSVEventName();

	UFUNCTION()
	void OnRep_TerrainMapsToUnload();

	UFUNCTION()
	void OnWarmUpTeleportComplete(AFortPlayerPawn* PlayerPawn);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void UpdateBackfillStatus();

	UPROPERTY(Transient, ReplicatedUsing=OnRep_bPlayersAreInvincible)
	bool bPlayersAreInvincible;

	UPROPERTY(EditAnywhere, Category="Win Condition")
	int32 MinimumScoreBumpForAutomadeGoal;

	UPROPERTY(EditAnywhere, Category="Win Condition")
	TArray<float> ScoreBrackets;

	UPROPERTY(EditAnywhere, Category="Phases")
	bool bEnforceInfiniteSafeZonePhase;

	UPROPERTY(EditAnywhere, Config, Category="Player Start")
	FName WarmupIslandPlayerStartTag;

	UPROPERTY(EditAnywhere, Category="UI")
	bool bAllowInventoryOpen;

	UPROPERTY(EditAnywhere, Category="UI")
	FScalableFloat bAllowFullScreenMap;

	UPROPERTY(EditAnywhere, Config, Category="UI")
	bool bShouldClearFrontEndMapMarkers;

	UPROPERTY(EditAnywhere, Category="UI")
	bool bBlockTeamIndicators;

	UPROPERTY(EditDefaultsOnly, Category="UI", meta=(Bitmask, BitmaskEnum="/Script/FortniteGame.EAthenaGamePhase"))
	int32 ForceDisplaySquadInfoDuringGamePhases;

	UPROPERTY(EditDefaultsOnly, Config, Category="UI")
	bool bAllowSquadListLocalPlayerInSplitscreen;

	UPROPERTY(EditAnywhere, Category="UI")
	FGameplayTagContainer UIToHideDuringSpecialEvent;

	UPROPERTY(EditAnywhere, Category="UI")
	FGameplayTagContainer UIToHideWhenInInfiniteWarmup;

	UPROPERTY(EditAnywhere, Category="UI")
	FGameplayTagContainer ClientEventsThatUnhideHiddenWhileLoadingHUDElements;

	UPROPERTY(EditDefaultsOnly, Config, Category="UI")
	bool bSkipPostGameScreens;

	UPROPERTY(EditDefaultsOnly, Config, Category="GC")
	bool bForceGarbageCollectionAfterUnloadOnServer;

	UPROPERTY(EditDefaultsOnly, Config, Category="GC")
	bool bForceGarbageCollectionAfterUnloadOnClient;

	UPROPERTY(EditDefaultsOnly, Config, Category="GC")
	bool bFullPurgeGC;

	UPROPERTY(ReplicatedUsing=OnRep_Aircraft)
	TObjectPtr<AFortAthenaAircraft> EventAircraft;

	UPROPERTY(EditAnywhere, Category="Aircraft Info")
	FAircraftFlightInfo EventAircraftInfo;

	UPROPERTY(EditAnywhere, Category="Aircraft Info")
	TSubclassOf<AFortAthenaAircraft> EventAircraftClass;

	UPROPERTY()
	TObjectPtr<ASpecialEventScript> ScriptActor;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_bDisableHUD)
	bool bDisableHUD;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_GameResumed)
	uint8 GameResumed;

	UPROPERTY(ReplicatedUsing=OnRep_AdditionalViewpoint)
	FVector AdditionalViewpoint;

	UPROPERTY(Replicated)
	bool bParachutesDisabled;

	UPROPERTY(ReplicatedUsing=OnRep_LastCSVEventName)
	FString LastCSVEventName;

	UPROPERTY(EditDefaultsOnly, ReplicatedUsing=OnRep_bCanStreamBuildingFoundationsIn, Category="Level Streaming")
	bool bCanStreamBuildingFoundationsIn;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_AllPlayerTeleportedCount)
	int32 AllPlayerTeleportedCount;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_DelayPlayersFromReturningToLobbyData)
	FFortDelayRTMMData DelayPlayersFromReturningToLobbyData;

	UPROPERTY(Transient)
	FName NamedWeightForContainerLootRoll;

	UPROPERTY(Transient)
	float WeightForContainerLootRoll;

	UPROPERTY(EditAnywhere, Category="Emotes")
	TArray<FFortSpecialEventEmoteData> SpecialEventEmoteData;

	UPROPERTY(EditDefaultsOnly, Replicated, Category="Emotes")
	FGameplayTagContainer BlockedNativeActions;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_SpecialEvent")
	EFortItemType DesiredQuickbarItemTypeAfterRemove;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UInputComponent> SpecialEventsInputComponent;

	UPROPERTY(ReplicatedUsing=OnRep_bLockingOnFocalPoint)
	bool bLockingOnFocalPoint;

	UPROPERTY(EditAnywhere, Category="Character Parts")
	TArray<FFortSpecialEventOverrideParts> SpecialEventOverrideParts;

	UPROPERTY(EditAnywhere, Category="Character Parts")
	FFortSpecialEventGEData GameplayEffectToApplyOnSwapToDefault;

	UPROPERTY(Transient)
	TMap<FUniqueNetIdRepl, int32> OverridePartsArrayIndexMap;

	UPROPERTY(EditAnywhere, Category="Gameplay")
	TArray<FFortSpecialEventGEData> GameplayEffectsToApplyOnLogin;

	UPROPERTY(EditAnywhere, Category="Gameplay")
	TSubclassOf<UFortControllerComponent_SpecialEvent> ControllerComponentClassOverride;

	UPROPERTY(EditDefaultsOnly, ReplicatedUsing=OnRep_TerrainMapsToUnload, Category="Maps")
	TArray<FSpecialEventMapData> TerrainMapsToUnload;

	UPROPERTY()
	TArray<TObjectPtr<AFortPlayerControllerAthena>> UnhandledPlayerControllers;

	UPROPERTY(EditDefaultsOnly, Category="HLOD")
	TArray<FName> HLODActorsToHideNames;

	UPROPERTY(EditDefaultsOnly, Config, Category="FortAthenaMutator_SpecialEvent")
	bool bForceAllowCloth;

	UPROPERTY(EditDefaultsOnly, Config, Category="Backfill", meta=(EditCondition="bPreventMultiplePlayerInitalizations", EditConditionHides))
	bool bManageBackfill;

	UPROPERTY(EditDefaultsOnly, Config, Category="Backfill", meta=(EditCondition="bPreventMultiplePlayerInitalizations && bManageBackfill", EditConditionHides))
	int32 PlayerCountToTriggerBackfill;

	UPROPERTY(EditDefaultsOnly, Config, Category="Backfill", meta=(EditCondition="bPreventMultiplePlayerInitalizations && bManageBackfill", EditConditionHides))
	bool bWaitForPlayerCountToTriggerBackfill;

	UPROPERTY(EditDefaultsOnly, Config, Category="Backfill", meta=(EditCondition="bPreventMultiplePlayerInitalizations && bManageBackfill", EditConditionHides))
	float UpdateBackfillStatusTime;

	UPROPERTY(BlueprintReadOnly, Transient, Replicated, Category="FortAthenaMutator_SpecialEvent", meta=(Hidden))
	bool bServerHasBackfillActive;

	UPROPERTY(EditDefaultsOnly, Category="Event")
	FScalableFloat MannequinRecentlyRenderedCheckToleranceValue;

	UPROPERTY(Transient)
	TArray<TObjectPtr<ASpecialEventPlayerMannequin>> SpecialEventMannequins;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_SpecialEvent")
	TArray<TSubclassOf<AActor>> ActorSpawnDelegateClasses;

};

UCLASS()
class UFortCheatManager_SpecialEvent : public UFortCheatManager_Coupled
{
	GENERATED_BODY()

protected:
	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void AddCSVEvent(const FString& CSVEventName);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void AutobalanceTargetScore();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void ChangeWinCondition(float NewGoalScore);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void CloseParachutes();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void PauseWinCondition(bool bLockScores = false);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void PlacePlayersInAircraft();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void ResetMatchTimeToPrevious();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void ResetSpecialEventAircraft();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void ResetWinCondition();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void ResetWinConditionProgressToZero();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void ResumeWinCondition();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void SendToNightNight();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void SetDestroyVehiclesInStorm(bool bDestroyVehiclesInStorm);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void SetIsSimulatingDamage(bool bIsSimulating);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void SetLockingOnFocalPoint(bool bInLockingOnFocalPoint);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void SetMatchTime(int32 NewMatchTime);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void SetReturnToMainMenuDelay(float MinDelayReturnToMainMenu, float MaxDelayReturnToMainMenu);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void ShrinkSafeZone();

	UFUNCTION(Exec)
	void SpecialEventClearAdditionalViewpoint();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void SpecialEventGameUserSettings_ClearDataForAllPlayers();

	UFUNCTION(Exec)
	void SpecialEventSetAdditionalViewpoint(float X, float Y, float Z);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void StartEventScript(const int32 InStartingIndex = 0, const float SequenceTimeOffset = 0.000000f);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void TeleportAllPlayers(int32 SafezoneIndex);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void ToggleDisableParachutes(bool bIsDisabled);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void UnloadTerrainMaps(FName MapTag);

};

