// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "GameplayTagContainer.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "Athena/FortDeathTypes.h"
#include "Athena/FortMutatorContext.h"
#include "Components/CustomFeedMessageContext.h"
#include "FortDataRegistry/FortDataRegistryResolverScopeInterface.h"
#include "FortEventTournamentIds.h"
#include "FortTeamActorInterface.h"
#include "FortTypes.h"
#include "Items/FortItemEntryNameModifierInterface.h"
#include "ObjectTracking/FortMetricInformation.h"
#include "Online/FortTournamentStatInfo.h"
#include "Player/FortPlayerStateZone.h"
#include "FortPlayerStateAthena.generated.h"

class AActor;
class ABuildingGameplayActorSpawnMachine;
class AFortPlayerStateAthena;
class APlayerState;
class UAthenaGadgetItemDefinition;
class UFortControllerComponent_TransientQuests;
class UTexture2D;
enum class EAthenaScoringEvent : uint8;
enum class ECreativePersistenceErrorTypes : uint8;
enum class EDeathCause : uint8;
enum class EKeepPlayingTogetherVotingStatus : uint8;
enum class EMatchAbandonState : uint8;

UENUM(BlueprintType, meta=(IsBlueprintBase="true"))
enum class ECreativePersistenceErrorTypes : uint8
{
	None = 0,
	VersionError = 1,
	LocalOnly = 2,
	LSRError = 3,
};

UENUM()
enum class EFortPawnState : uint8
{
	Default = 0,
	// nothing going on (this will not set a bit in the integer)

	InCombat = 1,
	// player is in combat

	DBNO = 2,
	// player is DBNO

	IsReviving = 4,
	// player is reviving someone else

	BeingRevived = 8,
	// player is being revived by someone

	Dead = 16,
};

UENUM()
enum class EKeepPlayingTogetherAnalyticEventPhase : uint8
{
	/** Event was triggered before post game started. */
	PrePostGamePhase = 0,
	/** Event was triggered during the countdown phase. */
	Countdown = 1,
	/** Event was triggered because the countdown phase finished and they were automatically opted out. */
	TimedOut = 2,
	/** Event was triggered when all members voted. */
	AllSquadMembersVoted = 3,
};

UENUM(BlueprintType)
enum class EKeepPlayingTogetherVotingStatus : uint8
{
	/** Initial State, player has not made a decision yet. */
	Undecided = 0,
	/** Player has indicated they want to keep playing together with their squad from this match. */
	OptedIn = 1,
	/** Player manually selected that they do not want to keep playing together. */
	OptedOut_Manual = 2,
	/** Player was forced to opt out because a new party member joined. */
	OptedOut_PartySizeIncreased = 3,
	/** Player was forced to opt out because at least one member of their party is in the lobby. */
	OptedOut_PartyMemberInLobby = 4,
	/** Player was forced to opt out because at least one member of their party opted out of KPT. */
	OptedOut_PartyMemberOptedOut = 5,
	/** Player was forced to opt out because they or one of their party members left their social party. */
	OptedOut_PartyMemberLeft = 6,
	/** Player was forced to opt out for some reason. */
	OptedOut_Forced = 7,
	/** Player did not make a decision before the allotted time expired and was automatically opted-out. */
	OptedOut_TimedOut = 8,
	/** Player was opted out when they returned to the lobby. */
	OptedOut_PlayerReturnedToLobby = 9,
	/** Player was Opted Out because they were the only player in their squad */
	OptedOut_OnlyPlayerInSquad = 10,
	/** Player was Opted Out because they disconnected from the match */
	OptedOut_Disconnected = 11,
};

UENUM()
enum class EMatchAbandonState : uint8
{
	None = 0,
	/** Team members are still joining the match. */
	Joining = 1,
	/** One or more team members failed to connect and so you can abandon the match. */
	CanAbandon = 2,
	/** Player chose not to abandon the match and is now locked or the team is all present. */
	TeamLocked = 3,
};

UENUM(BlueprintType, meta=(IsBlueprintBase="true"))
enum class ETeamMemberState : uint8
{
	/**
 * 
 */
	None = 0,
	/**
 * 
 */
	FIRST_CHAT_MESSAGE = 1 UMETA(Hidden),
	/**
 * 
 */
	NeedAmmoHeavy = 1,
	/**
 * 
 */
	NeedAmmoLight = 2,
	/**
 * 
 */
	NeedAmmoMedium = 3,
	/**
 * 
 */
	NeedAmmoShells = 4,
	/**
 * 
 */
	NeedAmmoRocket = 5,
	/**
 * 
 */
	ChatBubble = 6,
	/**
 * 
 */
	EnemySpotted = 7,
	/**
 * 
 */
	NeedBandages = 8,
	/**
 * 
 */
	NeedMaterials = 9,
	/**
 * 
 */
	NeedShields = 10,
	/**
 * 
 */
	NeedWeapon = 11,
	/**
 * 
 */
	LAST_CHAT_MESSAGE = 11 UMETA(Hidden),
	/**
 * 
 */
	MAX = 12 UMETA(Hidden),
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMatchAbandonStateChanged, EMatchAbandonState, OldState, EMatchAbandonState, NewState);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPlaceChanged, AFortPlayerStateAthena*, Sender, int32, NewPlace);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPointsAddedToScore, int32, NewPoints, EAthenaScoringEvent, ScoreType);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSquadIdChangedDelegate, AFortPlayerStateAthena*, PlayerState, const uint8, OldSquadIndex);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTeamAverageDamageChanged, float, NewAverageDamage);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTeamPlacementChanged, int32, NewPlacement);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTeamScoreChanged, int32, NewScore);

USTRUCT(BlueprintType)
struct FChangeTeamInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="ChangeTeamInfo")
	TWeakObjectPtr<AActor> Instigator;

	UPROPERTY(BlueprintReadOnly, Category="ChangeTeamInfo")
	FGameplayTagContainer ChangeTeamTags;

};

USTRUCT()
struct FFortRespawnData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	bool bRespawnDataAvailable;

	UPROPERTY()
	bool bClientIsReady;

	UPROPERTY()
	bool bServerIsReady;

	UPROPERTY()
	FVector RespawnLocation;

	UPROPERTY()
	FRotator RespawnRotation;

	UPROPERTY()
	float RespawnCameraDistance;

};

USTRUCT()
struct FFortResurrectionData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	bool bResurrectionChipAvailable;

	UPROPERTY()
	float ResurrectionExpirationTime;

	UPROPERTY()
	float ResurrectionExpirationLength;

	UPROPERTY()
	FVector WorldLocation;

};

USTRUCT()
struct FFortVehicleUseTelemetryInfo
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortPlayerStateAthena : public AFortPlayerStateZone, public IFortMutatorContext, public IFortDataRegistryResolverScopeInterface, public IFortItemEntryNameModifierInterface
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDynamicPersistenceErrorChange, const AFortPlayerStateAthena*, FortPlayerState, ECreativePersistenceErrorTypes, NewValue);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPlayerMetricInformationUpdated, APlayerState*, Client, const FDetailedMetricInformation&, Information);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSimplePlayerMetricInformationUpdated, APlayerState*, Client, const FSimpleMetricInformation&, Information);

public:
	UFUNCTION(BlueprintPure, Category="Resurrection")
	bool CanBeResurrected() const;

	UFUNCTION(BlueprintPure, Category="Creative")
	bool CanEditCreativeIsland() const;

	UFUNCTION(NetMulticast, Unreliable)
	void Client_OnNewLevel(int32 NewLevel);

	UFUNCTION(Client, Unreliable)
	void ClientAddKillFeedErrorMessage(const TArray<FFortCreativeMessageDispatcherErrorMessage>& ErrorMessages);

	UFUNCTION(Client, Reliable)
	void ClientNotifyMatchEntered(const FEventTournamentIds& EventIds);

	UFUNCTION(Client, Reliable)
	void ClientReportDBNO(const AFortPlayerStateAthena* Player);

	UFUNCTION(Client, Reliable)
	void ClientReportKill(const AFortPlayerStateAthena* Player);

	UFUNCTION(Client, Reliable)
	void ClientReportTeamKill(int32 TeamKills);

	UFUNCTION(Client, Reliable)
	void ClientReportTournamentStatUpdate(const FFortTournamentStatInfo& TournamentStatInfo) const;

	UFUNCTION(BlueprintPure)
	ECreativePersistenceErrorTypes GetCurrentPersistenceErrorType() const;

	UFUNCTION(BlueprintPure)
	const FDeathInfo& GetDeathInfo() const;

	UFUNCTION(BlueprintPure)
	bool GetInventoriesInLocalOnlyMode() const;

	UFUNCTION(BlueprintPure)
	bool GetInventoriesInNonPersistenceMode() const;

	UFUNCTION(BlueprintPure)
	bool GetInventoriesRequiredWithNoPersistence() const;

	UFUNCTION(BlueprintPure)
	int32 GetKillScore() const;

	UFUNCTION(BlueprintPure)
	FLinearColor GetPinColor() const;

	UFUNCTION(BlueprintPure)
	static FLinearColor GetPinColorBySquadMemberIndex(int32 SquadIndex);

	UFUNCTION(BlueprintPure, Category="Resurrection")
	float GetRemainingResurrectionChipExpirationTime() const;

	UFUNCTION(BlueprintPure, Category="Resurrection")
	float GetResurrectionChipExpirationLength() const;

	UFUNCTION(BlueprintPure)
	TSoftObjectPtr<UTexture2D> GetSocialAvatarBrush(const bool bSmallImage = true) const;

	UFUNCTION(BlueprintPure)
	uint8 GetSquadId() const;

	UFUNCTION(BlueprintPure)
	int32 GetSquadMemberIndex() const;

	UFUNCTION(BlueprintPure)
	virtual uint8 GetTeam() const;

	UFUNCTION(BlueprintPure)
	UFortControllerComponent_TransientQuests* GetTransientQuestsComponent() const;

	UFUNCTION(BlueprintPure)
	bool IsAnAthenaGameParticipant() const;

	UFUNCTION(BlueprintPure, Category="State")
	bool IsDisconnected() const;

	UFUNCTION(BlueprintPure)
	bool IsInSquad() const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="Player")
	bool IsRespawningWithRespawnData() const;

	UFUNCTION(BlueprintPure, Category="Resurrection")
	bool IsResurrectingNow() const;

	UFUNCTION(BlueprintPure, Category="Resurrection")
	bool IsResurrectionChipAvailable() const;

	UFUNCTION(BlueprintPure)
	bool IsSquadDead() const;

	UFUNCTION(NetMulticast, Reliable)
	void NetMulticastTriggerCustomFeedMessage(const FGameplayTag CustomFeedMessageGeneratorID);

	UFUNCTION(NetMulticast, Reliable)
	void NetMulticastTriggerCustomFeedMessageWithContext(const FGameplayTag CustomFeedMessageGeneratorID, FCustomFeedMessageContext Context);

	UFUNCTION(BlueprintCallable)
	void OnInteractionEventOccurred(UPARAM(ref) FGameplayTagContainer& InteractionTargetTags);

	UFUNCTION()
	void OnRep_DidNotThankBusDriver();

	UFUNCTION()
	void OnRep_Downs();

	UFUNCTION()
	void OnRep_IsContributingToOverbudgetHeatmap();

	UFUNCTION()
	void OnRep_KeepPlayingTogetherMatchmakingRegion();

	UFUNCTION()
	void OnRep_KeepPlayingTogetherVotingStatus();

	UFUNCTION()
	void OnRep_Kills();

	UFUNCTION()
	void OnRep_NumAmmoCansOpened();

	UFUNCTION()
	void OnRep_NumBronzeCoinsCollected();

	UFUNCTION()
	void OnRep_NumChestsOpened();

	UFUNCTION()
	void OnRep_NumForagedItemsConsumed();

	UFUNCTION()
	void OnRep_NumGoldCoinsCollected();

	UFUNCTION()
	void OnRep_NumLlamasOpened();

	UFUNCTION()
	void OnRep_NumMinutesAlive();

	UFUNCTION()
	void OnRep_NumSilverCoinsCollected();

	UFUNCTION()
	void OnRep_NumSupplyDropsOpened();

	UFUNCTION()
	void OnRep_PersistenceErrorType();

	UFUNCTION()
	void OnRep_Place();

	UFUNCTION()
	void OnRep_PreserveSquad();

	UFUNCTION()
	void OnRep_SeasonLevelUIDisplay();

	UFUNCTION()
	void OnRep_SimpleMetricInformation();

	UFUNCTION()
	void OnRep_SquadId();

	UFUNCTION()
	void OnRep_StormSurgeEffectCount();

	UFUNCTION()
	void OnRep_TeamAverageDamageDealt();

	UFUNCTION()
	void OnRep_TeamIndex(uint8 OldVal);

	UFUNCTION()
	void OnRep_TeamKillScore();

	UFUNCTION()
	void OnRep_TeamScore();

	UFUNCTION()
	void OnRep_TeamScorePlacement();

	UFUNCTION()
	void OnRep_ThankedBusDriver();

	UFUNCTION()
	void OnRep_TotalPlayerScore();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	static void OnSquadSpecificActorDestroyed(const uint8 AlwaysRelevantForSquadId, AActor* DestroyedActor);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	static void OnSquadSpecificActorSpawned(const uint8 AlwaysRelevantForSquadId, AActor* SpawnedActor);

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_SetCanEditCreativeIsland(bool bCanEdit, const TArray<FString>& WhiteList);

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_SetKeepPlayingTogetherVotingStatus(EKeepPlayingTogetherVotingStatus NewStatus);

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_TogglePreserveSquad();

	UFUNCTION(Server, Reliable)
	void ServerSetKeepPlayingTogetherMatchmakingRegion(const FString& NewRegion);

	UFUNCTION()
	void SetIsContributingToOverbudgetHeatmap(bool bContributingToOverbudget);

	UFUNCTION(BlueprintCallable, Category="DeathCause")
	static EDeathCause ToDeathCause(const FGameplayTagContainer& InTags, bool bWasDBNO);

	UPROPERTY(BlueprintAssignable, Category="Player")
	FOnTeamIndexChangedDelegate OnTeamIndexChangedDelegate;

	UPROPERTY(BlueprintAssignable, Category="Player")
	FOnSquadIdChangedDelegate OnSquadIdChangedDelegate;

	UPROPERTY(BlueprintReadOnly, Category="Score")
	bool bHasWonAGame;

	UPROPERTY(Transient)
	TMap<TObjectPtr<UAthenaGadgetItemDefinition>, int32> KillsWhileAthenaGadgetEquippedMap;

	UPROPERTY(Transient)
	TMap<FString, float> DamageDealtToBigHealthProps;

	UPROPERTY()
	int32 HumanKillScore;

	UPROPERTY(BlueprintAssignable)
	FOnPointsAddedToScore PointsAddedToScore;

	UPROPERTY(BlueprintAssignable)
	FOnTeamScoreChanged TeamScoreChanged;

	UPROPERTY(BlueprintAssignable)
	FOnTeamPlacementChanged TeamPlacementChanged;

	UPROPERTY(BlueprintAssignable)
	FOnPlaceChanged PlaceChanged;

	UPROPERTY(BlueprintAssignable)
	FOnTeamAverageDamageChanged TeamAverageDamageChanged;

	UPROPERTY(BlueprintAssignable)
	FOnMatchAbandonStateChanged MatchAbandonStateChanged;

	UPROPERTY(BlueprintReadOnly, Category="Game")
	bool bIsTalking;

	UPROPERTY(BlueprintReadOnly, Category="Game")
	bool bIsMuted;

	UPROPERTY(BlueprintAssignable, Category="Player")
	FDynamicPersistenceErrorChange OnPersistenceErrorTypeChanged;

protected:
	UFUNCTION()
	void OnRep_AIKills();

	UFUNCTION()
	void OnRep_ReplicatedTeamMemberState();

	UPROPERTY()
	FFortRespawnData RespawnData;

	UPROPERTY()
	ETeamMemberState TeamMemberState;

	UPROPERTY()
	float TeamMemberStateRepTime;

	UPROPERTY(BlueprintReadOnly, Category="Score")
	int32 AIKillCount;

private:
	UFUNCTION()
	void OnRep_ChangeTeamInfo();

	UFUNCTION()
	void OnRep_DeathInfo();

	UFUNCTION()
	void OnRep_InteractingRebootVan();

	UFUNCTION()
	void OnRep_MatchAbandonState(const EMatchAbandonState PrevMatchAbandonState);

	UFUNCTION()
	void OnRep_MetricInformation();

	UFUNCTION()
	void OnRep_RebootCounter();

	UFUNCTION()
	void OnRep_ResurrectingNow(const bool bPreviousResurrectingNow);

	UFUNCTION()
	void OnRep_ResurrectionChipReplicated();

	UPROPERTY(Replicated)
	int32 PersonalLobbyAction;

	UPROPERTY(ReplicatedUsing=OnRep_ReplicatedTeamMemberState)
	ETeamMemberState ReplicatedTeamMemberState;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_TeamKillScore, Category="Score", meta=(AllowPrivateAccess="TRUE"))
	int32 TeamKillScore;

	UPROPERTY(ReplicatedUsing=OnRep_TeamIndex)
	uint8 TeamIndex;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_TeamScorePlacement, Category="Score", meta=(AllowPrivateAccess="TRUE"))
	int32 TeamScorePlacement;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_TeamScore, Category="Score", meta=(AllowPrivateAccess="TRUE"))
	int32 TeamScore;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Place, Category="Score", meta=(AllowPrivateAccess="TRUE"))
	int32 Place;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Downs, Category="Score", meta=(AllowPrivateAccess="TRUE"))
	int32 DownScore;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Kills, Category="Score", meta=(AllowPrivateAccess="TRUE"))
	int32 KillScore;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_SeasonLevelUIDisplay, Category="FortPlayerStateAthena", meta=(AllowPrivateAccess="TRUE"))
	int32 SeasonLevelUIDisplay;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_NumChestsOpened, Category="Score", meta=(AllowPrivateAccess="TRUE"))
	int32 NumChestsOpened;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_NumAmmoCansOpened, Category="Score", meta=(AllowPrivateAccess="TRUE"))
	int32 NumAmmoCansOpened;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_NumSupplyDropsOpened, Category="Score", meta=(AllowPrivateAccess="TRUE"))
	int32 NumSupplyDropsOpened;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_NumLlamasOpened, Category="Score", meta=(AllowPrivateAccess="TRUE"))
	int32 NumLlamasOpened;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_NumForagedItemsConsumed, Category="Score", meta=(AllowPrivateAccess="TRUE"))
	int32 NumForagedItemsConsumed;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_NumMinutesAlive, Category="Score", meta=(AllowPrivateAccess="TRUE"))
	int32 NumMinutesAlive;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_NumBronzeCoinsCollected, Category="Score", meta=(AllowPrivateAccess="TRUE"))
	int32 NumBronzeCoinsCollected;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_NumSilverCoinsCollected, Category="Score", meta=(AllowPrivateAccess="TRUE"))
	int32 NumSilverCoinsCollected;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_NumGoldCoinsCollected, Category="Score", meta=(AllowPrivateAccess="TRUE"))
	int32 NumGoldCoinsCollected;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_TotalPlayerScore, Category="Score", meta=(AllowPrivateAccess="TRUE"))
	int32 TotalPlayerScore;

	UPROPERTY(ReplicatedUsing=OnRep_StormSurgeEffectCount)
	uint8 StormSurgeEffectCount;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_TeamAverageDamageDealt)
	uint16 TeamAverageDamageDealt;

	UPROPERTY(ReplicatedUsing=OnRep_SquadId)
	uint8 SquadId;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ThankedBusDriver)
	uint8 bThankedBusDriver : 1;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_DidNotThankBusDriver)
	uint8 bDidNotThankBusDriver : 1;

	UPROPERTY(Transient, Replicated)
	uint8 bUsingAnonymousMode : 1;

	UPROPERTY(Transient, Replicated)
	uint8 bUsingAnonymousCharacterMode : 1;

	UPROPERTY(Transient, Replicated)
	uint8 bShowingSeasonLevel : 1;

	UPROPERTY(Transient, Replicated)
	FText PlayerNameCustomOverride;

	UPROPERTY(Transient, Replicated)
	uint8 bHidingOtherPlayersNames : 1;

	UPROPERTY(ReplicatedUsing=OnRep_MetricInformation)
	FDetailedMetricInformation MetricInformation;

	UPROPERTY(ReplicatedUsing=OnRep_SimpleMetricInformation)
	FSimpleMetricInformation SimpleMetricInformation;

	UPROPERTY(Transient)
	int32 SecondsAlive;

	UPROPERTY(Transient)
	int32 TimeOfPawnCreation;

	UPROPERTY(Transient, Replicated)
	bool bIsDisconnected;

	UPROPERTY()
	TObjectPtr<UTexture2D> GameModeIcon;

	UPROPERTY(ReplicatedUsing=OnRep_DeathInfo)
	FDeathInfo DeathInfo;

	UPROPERTY(ReplicatedUsing=OnRep_ChangeTeamInfo)
	FChangeTeamInfo ChangeTeamInfo;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ResurrectionChipReplicated)
	FFortResurrectionData ResurrectionChipAvailable;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ResurrectingNow)
	bool bResurrectingNow;

	UPROPERTY(Transient, Replicated)
	bool bRespawningFromRespawnData;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_RebootCounter)
	int32 RebootCounter;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_InteractingRebootVan)
	TWeakObjectPtr<ABuildingGameplayActorSpawnMachine> InteractingRebootVan;

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_MatchAbandonState, Category="FortPlayerStateAthena", meta=(AllowPrivateAccess="TRUE"))
	EMatchAbandonState MatchAbandonState;

	UPROPERTY(Transient, Replicated)
	uint8 bIsAnAthenaGameParticipant : 1;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_IsContributingToOverbudgetHeatmap)
	uint8 bIsContributingToOverbudgetHeatmap : 1;

	UPROPERTY(Replicated)
	FUniqueNetIdRepl BotUniqueId;

	UPROPERTY(ReplicatedUsing=OnRep_PreserveSquad)
	bool bPreserveSquad;

	UPROPERTY(ReplicatedUsing=OnRep_KeepPlayingTogetherVotingStatus)
	EKeepPlayingTogetherVotingStatus KeepPlayingTogetherVotingStatus;

	UPROPERTY(ReplicatedUsing=OnRep_KeepPlayingTogetherMatchmakingRegion)
	FString KeepPlayingTogetherMatchmakingRegion;

	UPROPERTY(Replicated)
	uint8 InitialSquadSize;

	UPROPERTY(Replicated)
	uint8 SquadSizeIncrements;

	UPROPERTY(Replicated)
	uint8 SquadSizeDecrements;

	UPROPERTY(ReplicatedUsing=OnRep_PersistenceErrorType)
	ECreativePersistenceErrorTypes PersistenceErrorType;

};

