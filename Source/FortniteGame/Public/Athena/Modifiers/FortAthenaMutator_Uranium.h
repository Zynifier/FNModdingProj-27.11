// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Athena/AthenaGameMessage.h"
#include "Athena/Modifiers/FortAthenaMutator_GameModeBase.h"
#include "Athena/Modifiers/FortAthenaMutator_OperationsCustomCharacterParts.h"
#include "Athena/Modifiers/Interfaces/InfiltrationRoundInfoMutatorInterface.h"
#include "Athena/Modifiers/RegisterWithMutatorComponent.h"
#include "Player/FortCheatManager_Coupled.h"
#include "FortAthenaMutator_Uranium.generated.h"

class AActor;
class ACameraActor;
class AFortAthenaMutator_InventoryOverride;
class AFortAthenaMutator_RespawnWave;
class AFortAthenaMutator_SynchronizedTeleport;
class AFortCheckPointCosmeticActor;
class AFortCheckPointSplineActor;
class AFortMissionStormShield;
class AFortPlayerPushableCart;
class AFortPlayerStateAthena;
class UMaterialParameterCollection;
class USoundBase;
enum class EUraniumRoundPhase : uint8;

UENUM()
enum class EUraniumCartMovementRuleOnNewRound : uint8
{
	/** cart stays where it is */
	NoChange = 0,
	/** cart moves to the next checkpoint */
	MoveToNextCheckpoint = 1,
	/** cart is moved to the start of a new spline chosen at random */
	MoveToStartOfNewSpline = 2,
	/** cart is moved to a random checkpoint of a new spline chosen at random */
	MoveToRandomCheckPointOfNewSpline = 3,
	/** cart is moved to the next check point index of a new spline chosen at random */
	MoveToNextCheckPointOfNewSpline = 4,
};

UENUM()
enum class EUraniumEventId : uint8
{
	Intro = 0,
	CartBecomesPushable = 1,
	CheckPointReached = 2,
	NearCheckPoint = 3,
	NearFinalCheckPoint = 4,
	TimeIsLow = 5,
	TimeIsExtraLow = 6,
	OvertimeStarted = 7,
	RoundEnd_PushersWin = 8,
	RoundEnd_DefendersWin = 9,
	RoundStart = 10,
	GameEnded_AllRoundsPlayed = 11,
	GameEndedEarly_BlowOut = 12,
	GameEndedEarly_OutNumbered = 13,
};

UENUM()
enum class EUraniumGameEndedReason : uint8
{
	/** The game has NOT ended and is still in progress */
	GameIsStillInProgress = 0,
	/** Normal end condition, every round that was expected has played */
	AllRoundsPlayed = 1,
	/** Early Game End, the game was a blowout. One of the teams scored much higher than the other team */
	EarlyGameEnd_BlowOut = 2,
	/** Early Game End, a team was out numbered. One team has significantly fewer players than the other team (and also lost the previous round) */
	EarlyGameEnd_OutNumbered = 3,
};

UENUM()
enum class EUraniumRoundEndCondition : uint8
{
	/** round ends when any check-point has been reached */
	RanOutOfTime_Or_CheckpointReached = 0,
	/** round ends when the last check-point on the spline has been reached */
	RanOutOfTime_Or_LastCheckpointReached = 1,
};

UENUM()
enum class EUraniumRoundPhase : uint8
{
	/** not currently processing round phases */
	None = 0,
	/** The round has just ended, do some messaging, turn off some gameplay, wait */
	EndOfRoundStart = 1,
	/** Show the Round End screen that displays who won */
	ShowRoundEnd = 2,
	/** Hide the Round End screen that displays who won */
	HideRoundEnd = 3,
	/** control is removed and the screen is told to fade out */
	FadeOut = 4,
	/** screen should be fully faded, teleport the cart and set the new view target, modify the world as needed for the new round */
	SetupForNextRound = 5,
	/** show the round intro screen which tells players their objective */
	ShowRoundIntro = 6,
	/** Hide the round intro screen if shown and start showing the POI camera view */
	ShowPOICamera = 7,
	/** Show the perk select screen and wait for all player to choose a perk or for the timer to run out */
	PerkSelect = 8,
	/** Round is currently active */
	RoundActive = 9,
	/** start fading the screen in */
	FadeIn = 10,
	/** we are done with the round end sequence, normal gameplay is resumed */
	EndOfRoundFinish = 11,
	/** A phase that does a quick fade before releasing the player into gameplay to hide the awkward transition from POI Camera to Player Camera */
	FadeBeforeReleasePlayerIntoGameplay = 12,
	/** Releases players back into gameplay */
	ReleasePlayersIntoGameplay = 13,
	/** we are done with the entire game */
	EndGame = 14,
	/** number of total values, not to be used */
	MAX = 15 UMETA(Hidden),
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FUraniumChangeRoundEndVisibility, bool, bNewVisibility);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FUraniumChangeRoundProgressVisibility, bool, bNewVisibility);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FUraniumOnOvertimeChanged);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FUraniumOnRoundCompleted);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FUraniumOnRoundDataUpdated);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FUraniumOnShowRoundIntro);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FUraniumOnTeamsRolesChanged, uint8, PusherTeam, uint8, DefenderTeam);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FUraniumTeleportOutComplete);

USTRUCT()
struct FUraniumPOIData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FGameplayTag POITag;

	UPROPERTY()
	TWeakObjectPtr<AFortCheckPointSplineActor> SplineActor;

	UPROPERTY()
	TWeakObjectPtr<ACameraActor> CameraActor;

};

USTRUCT()
struct FUraniumSingleRoundInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	uint8 RoundTeamWinner;

	UPROPERTY(EditDefaultsOnly, NotReplicated, Category="UraniumSingleRoundInfo")
	FText RoundName;

	UPROPERTY(EditDefaultsOnly, NotReplicated, Category="UraniumSingleRoundInfo")
	TObjectPtr<USoundBase> RoundSound;

	UPROPERTY(EditDefaultsOnly, NotReplicated, Category="UraniumSingleRoundInfo", meta=(ClampMin="0"))
	int32 PointsForWinning;

};

USTRUCT()
struct FUraniumRoundData
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	int8 CurrentRoundNumber;

	UPROPERTY(Transient)
	int8 CurrentRoundCheckPoint;

	UPROPERTY(EditDefaultsOnly, Category="UraniumRoundData")
	TArray<FUraniumSingleRoundInfo> SingleRoundInfos;

};

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Tick", "Replication", "Actor", "LOD", "Cooking", "Mutator", "FortAthenaMutator", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_Uranium : public AFortAthenaMutator_GameModeBase, public IFortOperationsCharacterPartsFactionAuthority, public IInfiltrationRoundInfoMutatorInterface, public IRegisterWithMutatorComponentManager
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInitialized);

public:
	UFUNCTION(BlueprintPure)
	int32 GetCurrentRoundCheckPoint() const;

	UFUNCTION(BlueprintPure)
	int32 GetCurrentRoundNumber() const;

	UFUNCTION(BlueprintPure)
	AFortPlayerPushableCart* GetPushCart() const;

	UFUNCTION(BlueprintCallable)
	void GetRoundTeamWinners(TArray<uint8>& TeamWinnersEachRound);

	UFUNCTION(BlueprintPure)
	const uint8 GetWinningTeamForRound(int32 RoundNumber) const;

	UPROPERTY(BlueprintAssignable)
	FOnInitialized OnInitialized;

	UPROPERTY(VisibleDefaultsOnly, BlueprintAssignable, Category="FortAthenaMutator_Uranium")
	FUraniumTeleportOutComplete OnTeleportOutComplete;

	UPROPERTY(BlueprintAssignable)
	FUraniumChangeRoundEndVisibility OnUraniumChangeRoundEndVisibility;

	UPROPERTY()
	FUraniumOnShowRoundIntro OnShowRoundIntro;

	UPROPERTY(BlueprintAssignable)
	FUraniumChangeRoundProgressVisibility OnUraniumChangeRoundProgressVisibility;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="UI")
	FScalableFloat bPerkSelectBeforePOICamera;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	FText RoundResultsText_AttackersWin;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	FText RoundResultsText_AttackersLost;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	FText RoundResultsText_DefendersWin;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	FText RoundResultsText_DefendersLost;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	FText RoundIntroText_Attacking;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	FText RoundIntroText_Defending;

	UPROPERTY(EditDefaultsOnly, Category="Sound")
	TObjectPtr<USoundBase> RoundIntroFactionSound_Attacking;

	UPROPERTY(EditDefaultsOnly, Category="Sound")
	TObjectPtr<USoundBase> RoundIntroFactionSound_Defending;

	UPROPERTY(EditDefaultsOnly, Category="Sound")
	TObjectPtr<USoundBase> MatchEndSound_Win_Attackers;

	UPROPERTY(EditDefaultsOnly, Category="Sound")
	TObjectPtr<USoundBase> MatchEndSound_Win_Defenders;

	UPROPERTY(EditDefaultsOnly, Category="Sound")
	TObjectPtr<USoundBase> MatchEndSound_Lose_Attackers;

	UPROPERTY(EditDefaultsOnly, Category="Sound")
	TObjectPtr<USoundBase> MatchEndSound_Lose_Defenders;

protected:
	UFUNCTION()
	void HandleRoundPhase(EUraniumRoundPhase NewRoundPhase);

	UFUNCTION(NetMulticast, Reliable)
	void MulticastSetWinningTeams(const TArray<uint8>& InWinningTeams);

	UFUNCTION()
	void OnPushCartPushersOrDefendersChanged();

	UFUNCTION()
	void OnPushCartReachedCheckPoint(int32 CheckPointIndex);

	UFUNCTION()
	void OnPushCartTeamsRolesChanged(uint8 NewPusherTeam, uint8 NewDefenerTeam);

	UFUNCTION()
	void OnRep_bInOvertime();

	UFUNCTION()
	void OnRep_CurrentPOI();

	UFUNCTION()
	void OnRep_PushCart();

	UFUNCTION()
	void OnRep_RoundData();

	UFUNCTION()
	void TickUraniumEvents();

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_Uranium")
	TSubclassOf<AFortPlayerPushableCart> PushCartClass;

	UPROPERTY(ReplicatedUsing=OnRep_PushCart)
	TWeakObjectPtr<AFortPlayerPushableCart> PushCart;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_Uranium")
	TSubclassOf<AFortMissionStormShield> StormShieldClass;

	UPROPERTY(Replicated)
	TObjectPtr<AFortMissionStormShield> StormShield;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_Uranium")
	float RespawnRadius;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_Uranium")
	FScalableFloat RespawnLocationOffset_PusherTeam;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_Uranium")
	FScalableFloat RespawnLocationOffset_DefenderTeam;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_Uranium")
	FScalableFloat StartMovingRespawnCheckPointPct_PusherTeam;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_Uranium")
	FScalableFloat StartMovingRespawnCheckPointPct_DefenderTeam;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_Uranium")
	FScalableFloat StopMovingRespawnCheckPointPct_PusherTeam;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_Uranium")
	FScalableFloat StopMovingRespawnCheckPointPct_DefenderTeam;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_Uranium")
	FScalableFloat MovingRespawnOffsetMultiplier_PusherTeam;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_Uranium")
	FScalableFloat MovingRespawnOffsetMultiplier_DefenderTeam;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_Uranium")
	FScalableFloat PercentToMoveRespawnTowardCartViaTeamSize_PusherTeam;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_Uranium")
	FScalableFloat PercentToMoveRespawnTowardCartViaTeamSize_DefenderTeam;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_Uranium")
	FScalableFloat bAlignMovingRespawnToCart;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_Uranium")
	FScalableFloat MinRespawnHeightAboveGround;

	UPROPERTY(Transient)
	float CurrentMovingRespawnOffset_PusherTeam;

	UPROPERTY(Transient)
	float CurrentMovingRespawnOffset_DefenderTeam;

	UPROPERTY(Transient, Replicated)
	FVector RespawnLocation_PusherTeam;

	UPROPERTY(Transient, Replicated)
	FVector RespawnLocation_DefenderTeam;

	UPROPERTY(ReplicatedUsing=OnRep_CurrentPOI)
	FUraniumPOIData CurrentPOI;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortAthenaMutator_Uranium")
	FScalableFloat SafeZoneRadius;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortAthenaMutator_Uranium")
	FScalableFloat AircraftOffsetFromRadius;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortAthenaMutator_Uranium")
	FScalableFloat SupplyDropRadius;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Rounds", meta=(ClampMin="1"))
	int32 NumberOfRounds;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Rounds", meta=(EditCondition="NumberOfRounds>1"))
	EUraniumRoundEndCondition RoundEndCondition;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Rounds", meta=(EditCondition="NumberOfRounds>1"))
	EUraniumCartMovementRuleOnNewRound CartMovementRuleOnNewRound;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Rounds", meta=(EditCondition="NumberOfRounds>1"))
	FScalableFloat bOnRoundEndSwitchTeamRoles;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Rounds", meta=(EditCondition="NumberOfRounds>1"))
	FScalableFloat bOnRoundSetUpResetPlayerAbilities;

	UPROPERTY(EditDefaultsOnly, Category="Rounds", meta=(ArraySizeEnum="/Script/FortniteGame.EUraniumRoundPhase"))
	float RoundPhaseDurations[15];

	UPROPERTY(EditDefaultsOnly, Category="Rounds")
	float EndOfRoundCameraFadeOutTime;

	UPROPERTY(EditDefaultsOnly, Category="Rounds")
	float EndOfRoundCameraFadeInTime;

	UPROPERTY(EditDefaultsOnly, Category="Rounds", meta=(ClampMin="0"))
	float EndOfRoundStasisDelay;

	UPROPERTY(EditDefaultsOnly, ReplicatedUsing=OnRep_RoundData, Category="Rounds")
	FUraniumRoundData RoundData;

	UPROPERTY(EditDefaultsOnly, Category="End Game Early Rules", meta=(ClampMin="0"))
	FScalableFloat EarlyEndGame_BlowOutRoundNumberMin;

	UPROPERTY(EditDefaultsOnly, Category="End Game Early Rules", meta=(ClampMin="1"))
	FScalableFloat EarlyEndGame_BlowOutPointSpread;

	UPROPERTY(EditDefaultsOnly, Category="End Game Early Rules", meta=(ClampMax="1", ClampMin="0"))
	FScalableFloat EarlyEndGame_OutNumberedPercent;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_CurrentRoundPhase, Category="FortAthenaMutator_Uranium")
	EUraniumRoundPhase CurrentRoundPhase;

	UPROPERTY(Replicated)
	bool bRoundTimerStarted;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortAthenaMutator_Uranium")
	FScalableFloat MatchTimeAtStart;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortAthenaMutator_Uranium")
	FScalableFloat MatchTimeAddedPerCheckpoint;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortAthenaMutator_Uranium")
	FScalableFloat PushersAbandonedCartOvertime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortAthenaMutator_Uranium")
	int32 PushersAbandonedCartOvertimeInterval;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortAthenaMutator_Uranium")
	FScalableFloat PushersAbandonedCartOvertimeDuration;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAthenaMutator_Uranium")
	bool bPushCartIsPushableAtStart;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="FortAthenaMutator_Uranium")
	float PushersAbandonedCartStartTime;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="FortAthenaMutator_Uranium")
	float PushersAbandonedCartDuration;

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_bInOvertime, Category="FortAthenaMutator_Uranium")
	uint8 bInOvertime : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAthenaMutator_Uranium")
	uint8 bPerkModeOn : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAthenaMutator_Uranium")
	uint8 bShouldPlayFactionIntro : 1;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_Uranium")
	FScalableFloat DestroyActorsOnNewRound;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_Uranium")
	TArray<TSubclassOf<AActor>> ActorClassesToDestroy;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAthenaMutator_Uranium")
	FScalableFloat PlayersImmediatelyReenterGameplayAfterSelectingAPerk;

	UPROPERTY(EditDefaultsOnly, Category="MiniMap")
	TObjectPtr<UMaterialParameterCollection> MinimapMaterialParameterCollection;

	UPROPERTY(BlueprintAssignable)
	FUraniumOnOvertimeChanged OnOvertimeChanged;

	UPROPERTY(BlueprintAssignable)
	FUraniumOnRoundDataUpdated OnRoundDataUpdated;

	UPROPERTY(BlueprintAssignable)
	FUraniumOnRoundCompleted OnRoundCompleted;

	UPROPERTY(BlueprintAssignable)
	FUraniumOnTeamsRolesChanged OnTeamsRolesChanged;

	UPROPERTY(EditDefaultsOnly, Category="Gameplay")
	FGameplayTag RoundCompleteAccoladeTag;

	UPROPERTY(EditDefaultsOnly, Category="Gameplay")
	FGameplayTag RoundWinAccoladeTag;

	UPROPERTY(EditDefaultsOnly, Category="Gameplay")
	FGameplayTag MatchWinAccoladeTag;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_Uranium")
	bool bShowFullSplineOnMapUI;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_Uranium")
	TSubclassOf<AFortCheckPointCosmeticActor> CheckPointMarkerClass;

	UPROPERTY(EditDefaultsOnly, Category="Registering Actors")
	FGameplayTag SplineGameplayTag;

	UPROPERTY(EditDefaultsOnly, Category="Registering Actors")
	FGameplayTag CameraGameplayTag;

	UPROPERTY(EditDefaultsOnly, Category="Registering Actors")
	FGameplayTagContainer POIParentGameplayTags;

	UPROPERTY(Transient, Replicated)
	bool bIsSafeToTurnOnCameraAfterRespawn;

	UPROPERTY(EditDefaultsOnly, Category="Uranium Messages")
	TMap<EUraniumEventId, FAthenaGameMessageData> GameMessages_Pushers;

	UPROPERTY(EditDefaultsOnly, Category="Uranium Messages")
	TMap<EUraniumEventId, FAthenaGameMessageData> GameMessages_Defenders;

	UPROPERTY(EditDefaultsOnly, Category="Uranium Messages")
	FScalableFloat EventTracking_TimeBetweenTicks;

	UPROPERTY(EditDefaultsOnly, Category="Uranium Messages")
	FScalableFloat EventTracking_TimeIsLowTime;

	UPROPERTY(EditDefaultsOnly, Category="Uranium Messages")
	FScalableFloat EventTracking_TimeIsExtraLowTime;

	UPROPERTY(EditDefaultsOnly, Category="Uranium Messages")
	FScalableFloat EventTracking_CheckPointIsNearDistance;

	UPROPERTY(EditDefaultsOnly, Category="Uranium Messages")
	FText TeleportingPlayersOutText;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAthenaMutator_Uranium", meta=(EditCondition="bPerkModeOn"))
	bool bForcePerkPickerOnCheckpoint;

private:
	UFUNCTION()
	void HandleTeleportComplete();

	UFUNCTION()
	void OnPlaylistDataLoaded(FName PlaylistName, const FGameplayTagContainer& PlaylistContainerTags);

	UFUNCTION()
	void OnRep_CurrentRoundPhase();

	UFUNCTION()
	void OnRep_TeleportComplete();

	UFUNCTION()
	void StartEndOfRoundStasis();

	UFUNCTION()
	void TeleportPlayerLoadComplete(AFortPlayerStateAthena* PlayerState);

	UPROPERTY()
	TObjectPtr<AFortAthenaMutator_SynchronizedTeleport> TeleportMutator;

	UPROPERTY()
	TObjectPtr<AFortAthenaMutator_InventoryOverride> InventoryOverrideMutator;

	UPROPERTY()
	TObjectPtr<AFortAthenaMutator_RespawnWave> RespawnWaveMutator;

	UPROPERTY(Replicated)
	uint8 CheckpointTeleportPlayersReleased;

	UPROPERTY(ReplicatedUsing=OnRep_TeleportComplete)
	uint8 CheckpointTeleportComplete;

	UPROPERTY(EditDefaultsOnly, Category="Gameplay")
	FScalableFloat TeleportHeight;

	UPROPERTY(Transient)
	bool bCheatDrawRespawnLocations;

};

UCLASS()
class UFortCheatManager_Uranium : public UFortCheatManager_Coupled
{
	GENERATED_BODY()

public:
	UFUNCTION(Exec)
	void DrawUraniumRespawnLocations(bool bDraw);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void SetCartBaseSpeed(float NewBaseSpeed);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void SetCartPushAreaSizeScalar(float PushAreaSizeScalar);

};

