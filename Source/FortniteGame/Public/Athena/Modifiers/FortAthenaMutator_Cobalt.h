// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TimerHandle.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "ScalableFloat.h"
#include "Athena/AthenaGameMessage.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "Athena/Modifiers/FortAthenaMutator_GameModeBase.h"
#include "Athena/Modifiers/Interfaces/InfiltrationRoundInfoMutatorInterface.h"
#include "Items/FortItemTypeEnum.h"
#include "Player/FortCheatManager_Coupled.h"
#include "FortAthenaMutator_Cobalt.generated.h"

class AActor;
class AAthenaCobaltStormShield;
class ACobaltPOICameraActor;
class AFortAthenaMutator_InventoryOverride;
class AFortAthenaMutator_SynchronizedTeleport;
class AFortPlayerController;
class AFortPlayerPawn;
class AFortPlayerStateAthena;
class UAudioComponent;
class UDeathEffectsPawnComponent;
class UMaterialParameterCollection;
class USoundBase;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCobaltHideVsDisplay);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCobaltPawnLoaded, AFortPlayerController*, PlayerController);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCobaltPostKill, AFortPlayerStateAthena*, Victim);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCobaltPreRoundDisplayVisibility, bool, bNewVisibility);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCobaltRoundAdvanced);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCobaltRoundCompleteUIFinished);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCobaltRoundComplete, const TArray<uint8>&, WinningTeams);

USTRUCT(BlueprintType)
struct FCobaltWidgetMatchData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<uint8> Teams;

	UPROPERTY()
	FGameplayTag POITag;

};

USTRUCT(BlueprintType)
struct FCobaltWidgetRoundData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int8 RoundNumber;

	UPROPERTY()
	int8 FirstRound;

	UPROPERTY()
	TArray<FCobaltWidgetMatchData> CurrentRoundMatches;

	UPROPERTY()
	TArray<uint8> PreviousRoundWinners;

};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCobaltShowVsDisplay, const FCobaltWidgetRoundData&, RoundData);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCobaltTeleportComplete);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPlaylistTimerValueUpdated);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FStormShieldArrayUpdated);

USTRUCT()
struct FCobaltCombatStormShieldDataEntry : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY()
	bool bStormShieldActive;

	UPROPERTY()
	TArray<uint8> Teams;

	UPROPERTY()
	TArray<int32> ParentStormShields;

	UPROPERTY()
	TObjectPtr<AAthenaCobaltStormShield> StormShieldActor;

	UPROPERTY()
	FVector StormShieldPOILocation;

	UPROPERTY()
	FGameplayTag POITag;

	UPROPERTY()
	int8 RoundIndex;

	UPROPERTY()
	TArray<int32> TeamScores;

	UPROPERTY()
	uint8 LeadingTeam;

	UPROPERTY()
	uint8 TieBreakerTeam;

	UPROPERTY(NotReplicated)
	bool bAwardedFirstEliminationOfRound;

	UPROPERTY(NotReplicated)
	uint8 FirstLandTeam;

	UPROPERTY(NotReplicated)
	TArray<float> TotalDamageDealt;

	UPROPERTY(NotReplicated)
	TArray<float> TotalDamageTaken;

	UPROPERTY(NotReplicated)
	TObjectPtr<ACobaltPOICameraActor> POICamera;

	UPROPERTY(NotReplicated)
	FVector2D Team0RespawnPoint;

	UPROPERTY(NotReplicated)
	FVector2D Team1RespawnPoint;

	UPROPERTY(NotReplicated)
	float NextSupplyDropSpawnTime;

};

USTRUCT()
struct FCobaltCombatStormShieldArray : public FFastArraySerializer
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FCobaltCombatStormShieldDataEntry> Entries;

};

USTRUCT()
struct FTaggedPOI
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="TaggedPOI")
	FGameplayTag POITag;

	UPROPERTY(EditDefaultsOnly, Category="TaggedPOI")
	FScalableFloat Enabled;

	UPROPERTY(EditDefaultsOnly, Category="TaggedPOI")
	FVector SpawnOffset;

	UPROPERTY(EditDefaultsOnly, Category="TaggedPOI")
	FScalableFloat SelectFromAvailableShrinkLocation;

	UPROPERTY(EditDefaultsOnly, Category="TaggedPOI")
	TArray<FVector2D> AvailableShrinkLocations;

	UPROPERTY(EditDefaultsOnly, Category="TaggedPOI")
	FText POIOverrideName;

};

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Tick", "Replication", "Actor", "LOD", "Cooking", "Mutator", "Tick", "Replication", "Actor", "LOD", "Cooking", "Mutator", "FortAthenaMutator", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_Cobalt : public AFortAthenaMutator_GameModeBase, public IInfiltrationRoundInfoMutatorInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	const int32 GetFinalRoundIndex() const;

	UPROPERTY(VisibleDefaultsOnly, BlueprintAssignable, Category="FortAthenaMutator_Cobalt")
	FCobaltTeleportComplete OnTeleportComplete;

	UPROPERTY(VisibleDefaultsOnly, BlueprintAssignable, Category="FortAthenaMutator_Cobalt")
	FCobaltRoundComplete OnRoundComplete;

	UPROPERTY(VisibleDefaultsOnly, BlueprintAssignable, Category="FortAthenaMutator_Cobalt")
	FCobaltRoundCompleteUIFinished OnRoundCompleteUIFinished;

	UPROPERTY(VisibleDefaultsOnly, BlueprintAssignable, Category="FortAthenaMutator_Cobalt")
	FCobaltRoundAdvanced OnRoundAdvanced;

	UPROPERTY(VisibleDefaultsOnly, BlueprintAssignable, Category="FortAthenaMutator_Cobalt")
	FCobaltShowVsDisplay OnShowVsDisplay;

	UPROPERTY(VisibleDefaultsOnly, BlueprintAssignable, Category="FortAthenaMutator_Cobalt")
	FCobaltHideVsDisplay OnHideVsDisplay;

	UPROPERTY(VisibleDefaultsOnly, BlueprintAssignable, Category="FortAthenaMutator_Cobalt")
	FStormShieldArrayUpdated OnStormShieldArrayUpdated;

	UPROPERTY(VisibleDefaultsOnly, BlueprintAssignable, Category="FortAthenaMutator_Cobalt")
	FPlaylistTimerValueUpdated OnPlaylistTimerValueUpdated;

	UPROPERTY(VisibleDefaultsOnly, BlueprintAssignable, Category="FortAthenaMutator_Cobalt")
	FCobaltPreRoundDisplayVisibility OnUpdatePreRoundDisplayVisibility;

protected:
	UPROPERTY(EditDefaultsOnly, Category="StormShield")
	TSubclassOf<AAthenaCobaltStormShield> StormShieldClass;

	UPROPERTY(EditDefaultsOnly, Category="StormShield")
	TArray<FTaggedPOI> POIList;

	UPROPERTY(EditDefaultsOnly, Category="StormShield")
	FScalableFloat MinimumDistanceBetweenPOIs;

	UPROPERTY(EditDefaultsOnly, Category="StormShield")
	FScalableFloat StormShieldRadiusMultiplierPerPlayer;

	UPROPERTY(EditDefaultsOnly, Category="StormShield")
	FScalableFloat StormShieldMinRadiusMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="StormShield")
	FScalableFloat DelayBeforeStormShrink;

	UPROPERTY(EditDefaultsOnly, Category="StormShield")
	FScalableFloat StormShieldShrinkLocationMinOffset;

	UPROPERTY(EditDefaultsOnly, Category="StormShield")
	FScalableFloat StormShieldShrinkLocationMaxOffset;

	UPROPERTY(EditDefaultsOnly, Category="StormShield")
	FScalableFloat StormShieldShrinkRate;

	UPROPERTY(EditDefaultsOnly, Category="StormShield")
	FScalableFloat StormShieldGrowthRate;

	UPROPERTY(EditDefaultsOnly, Category="Round")
	FScalableFloat DelayBeforeNextRound;

	UPROPERTY(EditDefaultsOnly, Category="Round")
	FScalableFloat DelayBeforePushToSpectateMode;

	UPROPERTY(EditDefaultsOnly, Category="Round")
	float DelayBeforeRoundEndDeathAndStinger;

	UPROPERTY(EditDefaultsOnly, Category="Round")
	float DelayBeforeShowingRoundEndUI;

	UPROPERTY(EditDefaultsOnly, Category="Round")
	FScalableFloat RadiusRatioForRespawn;

	UPROPERTY(EditDefaultsOnly, Category="Round")
	FScalableFloat HeightOfSpawnIntoNewStormShield;

	UPROPERTY(EditDefaultsOnly, Category="Round")
	FScalableFloat DistanceBetweenPlayersOfSameTeamDuringRespawn;

	UPROPERTY(EditDefaultsOnly, Category="Round")
	FText TeleportingPlayersText;

	UPROPERTY(EditDefaultsOnly, Category="Round")
	FText TeleportingSpectatorsText;

	UPROPERTY(EditDefaultsOnly, Category="Round")
	FScalableFloat bResetPlayerAbilitiesOnRoundEnd;

	UPROPERTY(EditDefaultsOnly, Category="Round")
	FGameplayTag RiftTeleportEventTag;

	UPROPERTY(EditDefaultsOnly, Category="Gameplay")
	FScalableFloat AvailablePerkRerolls;

	UPROPERTY(EditDefaultsOnly, Category="Gameplay")
	FScalableFloat ResetPlayerInventoryBetweenRounds;

	UPROPERTY(EditDefaultsOnly, Category="Gameplay")
	FScalableFloat bKeepWarmupLoadoutsInFirstRound;

	UPROPERTY(EditDefaultsOnly, Category="Gameplay")
	TArray<EFortItemType> ItemTypesToRemove;

	UPROPERTY(EditDefaultsOnly, Category="Gameplay|Respawn")
	bool bRespawnEnabled;

	UPROPERTY(EditDefaultsOnly, Category="Gameplay|Respawn")
	FScalableFloat RoundDuration;

	UPROPERTY(EditDefaultsOnly, Category="Gameplay|Respawn")
	FScalableFloat RespawnDelay;

	UPROPERTY(EditDefaultsOnly, Category="Gameplay|Respawn")
	FFortRespawnLogicData RespawnLogicData;

	UPROPERTY(EditDefaultsOnly, Category="Gameplay|Respawn")
	float RespawnFallbackHeight;

	UPROPERTY(EditDefaultsOnly, Category="Gameplay|Respawn")
	float RespawnTraceEnd;

	UPROPERTY(EditDefaultsOnly, Category="MiniMap")
	TObjectPtr<UMaterialParameterCollection> MinimapMPC;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	FScalableFloat MinimumVersusScreenDuration;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	float POICameraViewPhaseDuration;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	FScalableFloat HideStormShieldDuringPOICameraViewPhase;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	float PreRoundDisplayDelay;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	float PreRoundDisplayDuration;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	float RoundStartWidgetSequenceAdditionalDelay;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	float UILastManStandingDisplayTime;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	TArray<FAthenaGameMessageData> RoundGameMessageData;

	UPROPERTY(EditDefaultsOnly, Category="Sound")
	TObjectPtr<USoundBase> StormShieldShrinkBeginSound;

	UPROPERTY(EditDefaultsOnly, Category="Sound")
	TObjectPtr<USoundBase> VictoryStingerSound;

	UPROPERTY(EditDefaultsOnly, Category="Sound")
	TObjectPtr<USoundBase> LoserStingerSound;

	UPROPERTY(EditDefaultsOnly, Category="Sound")
	float RoundEndStingerFadeDuration;

	UPROPERTY(EditDefaultsOnly, Category="WinnerDeathEffects")
	TSubclassOf<UDeathEffectsPawnComponent> DeathEffectsComponentClass;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	FText RoundResultsText_Win;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	FText RoundResultsText_Lost;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	bool bShouldSkipWinLossScreen;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	FScalableFloat ShowTeammatesInMap;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	FScalableFloat ShowEnemiesInMap;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	FScalableFloat TeammateMapIconScale;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	FScalableFloat EnemyMapIconScale;

	UPROPERTY()
	TObjectPtr<AFortAthenaMutator_InventoryOverride> InventoryOverrideMutator;

	UPROPERTY(EditDefaultsOnly, Category="Gameplay")
	FGameplayTag RoundCompleteAccoladeTag;

	UPROPERTY(EditDefaultsOnly, Category="Gameplay")
	FGameplayTag RoundWinAccoladeTag;

	UPROPERTY(EditDefaultsOnly, Category="Gameplay")
	FGameplayTag FirstEliminationAccoladeTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Storm Eye")
	TObjectPtr<UMaterialParameterCollection> SafeZoneMaterialCollection;

	UPROPERTY(EditDefaultsOnly, Category="Storm Eye")
	FName SafeZoneLocMaterialParamName;

	UPROPERTY(EditDefaultsOnly, Category="Storm Eye")
	FName SafeZoneScaleMaterialParamName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Storm Eye")
	float SafeZoneRadiusAtMaxSafeZoneScale;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Storm Eye")
	TSubclassOf<AActor> StormEyeActorClass;

	UPROPERTY(EditDefaultsOnly, Category="Supply Drops")
	FScalableFloat MaxSupplyDropSpawnTime;

	UPROPERTY(EditDefaultsOnly, Category="Supply Drops")
	FScalableFloat MinSupplyDropSpawnTime;

private:
	UFUNCTION()
	void AudioFadeChangeEvent(bool bFadeOut, float FadeTime);

	UFUNCTION()
	void ClientCobaltRoundTimerComplete();

	UFUNCTION()
	void HandlePlayerStateTeleportComplete(AFortPlayerStateAthena* FortPlayerState);

	UFUNCTION()
	void HandleTeleportComplete();

	UFUNCTION()
	void OnRep_ActiveRound();

	UFUNCTION()
	void OnRep_bClientPlaylistTimerStarted();

	UFUNCTION()
	void OnRep_bIsFinishedDisplayingRoundEndUI();

	UFUNCTION()
	void OnRep_CombatStormShieldArray();

	UFUNCTION()
	void OnRep_RoundStartWidgetSequenceRunning();

	UFUNCTION()
	void OnRep_TeamWinners();

	UFUNCTION()
	void OnRep_TeleportComplete();

	UFUNCTION()
	void OnRep_WidgetRoundData();

	UFUNCTION()
	void TeleportPlayerLoadComplete(AFortPlayerPawn* FortPlayerPawn);

	UFUNCTION()
	void UpdateStormEyeVisuals();

	UPROPERTY(ReplicatedUsing=OnRep_TeleportComplete)
	bool bTeleportComplete;

	UPROPERTY(ReplicatedUsing=OnRep_RoundStartWidgetSequenceRunning)
	bool bRoundStartWidgetSequenceRunning;

	UPROPERTY()
	TObjectPtr<AFortAthenaMutator_SynchronizedTeleport> TeleportMutator;

	UPROPERTY(ReplicatedUsing=OnRep_CombatStormShieldArray)
	FCobaltCombatStormShieldArray CombatStormShieldArray;

	UPROPERTY(ReplicatedUsing=OnRep_ActiveRound)
	int8 ActiveRound;

	UPROPERTY(Replicated)
	bool bIsCobaltFinished;

	UPROPERTY(Replicated)
	int8 FirstRound;

	UPROPERTY(ReplicatedUsing=OnRep_TeamWinners)
	TArray<uint8> TeamWinners;

	UPROPERTY(Replicated)
	TArray<uint8> TeamLosers;

	UPROPERTY()
	TArray<TObjectPtr<AFortPlayerStateAthena>> PendingTeleportingPlayers;

	UPROPERTY()
	TArray<FTimerHandle> MoveToSpectateTimerHandles;

	UPROPERTY(ReplicatedUsing=OnRep_bClientPlaylistTimerStarted)
	bool bClientPlaylistTimerStarted;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UAudioComponent> RoundEndStingerInstance;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_Cobalt")
	FScalableFloat bUseStrictBracketStructure;

	UPROPERTY(ReplicatedUsing=OnRep_WidgetRoundData)
	FCobaltWidgetRoundData WidgetRoundData;

	UPROPERTY(ReplicatedUsing=OnRep_bIsFinishedDisplayingRoundEndUI)
	bool bIsFinishedDisplayingRoundEndUI;

	UPROPERTY()
	TObjectPtr<AActor> StormEyeActor;

};

UCLASS()
class UFortCheatManager_Cobalt : public UFortCheatManager_Coupled
{
	GENERATED_BODY()

public:
	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void AwardCobaltTeamPoints(uint8 TeamToAward, int32 PointsToAward);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void EndCobaltRound();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void SimulateFullCobaltMatch(bool bSimulate);

};

