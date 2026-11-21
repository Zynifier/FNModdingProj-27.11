// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/HitResult.h"
#include "Engine/NetSerialization.h"
#include "Fonts/SlateFontInfo.h"
#include "GameFramework/OnlineReplStructs.h"
#include "GameplayTagContainer.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "Misc/DateTime.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "ScalableFloat.h"
#include "Styling/SlateBrush.h"
#include "Types/SlateEnums.h"
#include "Athena/AircraftFlightInfo.h"
#include "Athena/AthenaGameMessage.h"
#include "Athena/AthenaStreamIdOverride.h"
#include "Athena/FortCustomizationsPreloader.h"
#include "Athena/FortMutatorContext.h"
#include "Athena/Modifiers/DBNOCustomSettings.h"
#include "Building/BuildingTypes.h"
#include "Evaluator/FortEvaluator.h"
#include "FortGameStateZone.h"
#include "FortMapLocationStateType.h"
#include "FortPlaylist.h"
#include "FortPlaylistData.h"
#include "FortTypes.h"
#include "MeshNetworkTypes.h"
#include "Modifiers/GameplayMutatorRegistryInterface.h"
#include "FortGameStateAthena.generated.h"

class AActor;
class ABuildingActor;
class ABuildingContainer;
class AFortAthenaMapInfo;
class AFortAthenaMutator_AI;
class AFortBroadcastSpectatorInfo;
class AFortGameModePickup;
class AFortGameStateAthena;
class AFortGameplayMutator;
class AFortLocalizationService;
class AFortMissionStormShield;
class AFortPartyRiftPortalManager;
class AFortPawn;
class AFortPlayerController;
class AFortPlayerControllerAthena;
class AFortPlayerState;
class AFortPlayerStateAthena;
class AFortProjectileBase;
class AFortPropertyOverrideReplShared;
class AFortSpecialActorReplicationInfo;
class AFortVolumeManager;
class AFortWeapon;
class APawn;
class APlayerState;
class AUnicornDriver;
class IFortSafeZoneInterface;
class UAthenaBattleBusItemDefinition;
class UCurveFloat;
class UCurveTable;
class UCurveVector;
class UCustomCharacterPart;
class UFortContextualTutorialController;
class UFortCustomizationsPreloader;
class UFortGameStateComponent_BattleRoyaleGamePhaseLogic;
class UFortHermesLoadContext;
class UFortItemDefinition;
class UFortMutatorListComponent;
class UFortPlaylistAthena;
class UFortSanitizationService;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class UMaterialParameterCollection;
class UObject;
class USoundCue;
class USoundMix;
class USplatterGridSystem;
enum class EAthenaGameMsgType : uint8;
enum class EAthenaGamePhase : uint8;
enum class EAthenaGamePhaseStep : uint8;
enum class EAthenaStormCapState : uint8;
enum class EFortPlaylistType : uint8;
enum class EMapLocationStateType : uint8;

UENUM()
enum class EPlayerIndicatorFlags : uint8
{
	None = 0,
	Minimap = 1,
	// Show the player on the minimap

	WorldArrow = 2,
	// Show an arrow over their head

	WorldName = 4,
	// Show the name above the players head

	DBNOCountDown = 8,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FHideGameModeMessage);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnActiveTeamArrayBuilt);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAllWinnersAnnounced);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnClientVolumeManagerReplicated);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnContextTutorialGameModeMessageRequest, FAthenaGameMessageData, MsgData, UFortContextualTutorialController*, OwnedController);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCountdownFinished);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCountdownStarted, int32, SecondsRemaining);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCountdownStopped);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCountdownTick, int32, SecondsRemaining);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCurrentHighScoreUpdated);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEndGameTimeDilationComplete);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFinalCountdownFinished);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFinalCountdownStarted, int32, SecondsRemaining);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFinalCountdownTick, int32, SecondsRemaining);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGameModeMessageRequest, FAthenaGameMessageData, MsgData);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGameModeMessageSuccess, AFortPlayerController*, OwnerController);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGameModeRemoveMarker, int32, PlayerID, int32, InstanceID);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGameModeShowMarker, int32, PlayerID, int32, InstanceID);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGamePhaseChanged, EAthenaGamePhase, GamePhase);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGamePhaseStepChanged, const TScriptInterface<IFortSafeZoneInterface>&, SafeZoneInterface, const EAthenaGamePhaseStep, GamePhaseStep);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnGameStateGoalScoreChanged);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnHideGameModeMessageRequest, EAthenaGameMsgType, MsgType, bool, bInstantHide, bool, bClearQueue, int32, MessageChannel);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnKillFeedUpdated);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMapInfoSet);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMutatorCharacterMovementBlocked, FHitResult&, InOutHit, AFortPawn*, FortPawn);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnMutatorGameplayEvent, int32, EventId, int32, EventParam1, int32, EventParam2, int32, EventParam3);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMutatorGenericIntegerUpdated, int32, GenericIntegerIndex, int32, NewIntegerValue);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnNewContentUpdateMessageRecieved, FString, NewMessage);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnNewScreenLogMessageRecieved, FString, NewMessage, FLinearColor, Color, float, Duration);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlayerBotsLeftChanged);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlayerJoinedLeftCreativeIsland);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayersLeftChanged, int32, NumPlayersLeft);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlayersLoadedChanged);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSafeZoneIndicatorChanged);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStormCapStateChanged, EAthenaStormCapState, StormCapState);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStormProgressStopped, bool, StormStopped);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTeamsLeftChanged, int32, NumTeamsLeft);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnWarmupCountdownEndTimeUpdated, float, NewEndTime);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnWinConditionMetCN);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnWinnerAnnounced, FString, WinnerPlayerName);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnWinnerInfoDisplayReadyCN);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnWinningScoreAnnounced, int32, WinningScore);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnWinningTeamAnnounced, int32, WinningTeam);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FPickupOnDestroy, AFortGameModePickup*, SelfActor, const UFortItemDefinition*, ItemDefinition);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FPickupOnSpawnReady, AFortGameModePickup*, SelfActor, const UFortItemDefinition*, ItemDefinition);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FRepositionGameModeMessage, FVector2D, Position, TEnumAsByte<EHorizontalAlignment>, HorizontalAlignment, TEnumAsByte<EVerticalAlignment>, VerticalAlignment);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSetDefaultGameModeMessage);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FShowGameModeMessage);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FUpdateNamedPoiColorDelegate);

USTRUCT()
struct FAthenaPlayerRankingAwards
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float PlacementRankAward;

	UPROPERTY()
	float KillRankAward;

	UPROPERTY()
	float DamageAssistRankAward;

};

USTRUCT()
struct FAthenaPlayerRankingStats
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FAthenaPlayerRankingAwards TotalPlayerRankingAwards;

	UPROPERTY()
	TMap<FString, FAthenaPlayerRankingAwards> PerPlayerAwards;

};

USTRUCT(BlueprintType)
struct FDynamicLandData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Location")
	FName Name;

	UPROPERTY(EditAnywhere, Category="Location")
	FVector WorldPosition;

	UPROPERTY(EditAnywhere, Category="Location")
	float Rotation;

	UPROPERTY(EditAnywhere, Category="Location")
	FSlateBrush LandBrush;

};

USTRUCT()
struct FFortPlayersLeftChangedEvent
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FFortWinnerPlayerData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 PlayerId;

};

USTRUCT()
struct FGameMemberInfo : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY()
	uint8 SquadId;

	UPROPERTY()
	uint8 TeamIndex;

	UPROPERTY()
	FUniqueNetIdRepl MemberUniqueId;

};

USTRUCT()
struct FGameMemberInfoArray : public FFastArraySerializer
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TArray<FGameMemberInfo> Members;

	UPROPERTY(Transient, NotReplicated)
	TObjectPtr<AFortGameStateAthena> OwningGameState;

};

USTRUCT()
struct FGameplayMutatorEventData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 EventId;

	UPROPERTY()
	int32 EventParam1;

	UPROPERTY()
	int32 EventParam2;

	UPROPERTY()
	int32 EventParam3;

};

USTRUCT()
struct FGameplayMutatorObjectData : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UObject> TheObject;

	UPROPERTY()
	int32 ObjectId;

	UPROPERTY()
	int32 ObjectValue1;

	UPROPERTY()
	int32 ObjectValue2;

};

USTRUCT()
struct FGameplayMutatorObjectDataArray : public FFastArraySerializer
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FGameplayMutatorObjectData> ObjectDataList;

};

USTRUCT()
struct FMeshNetworkStatus
{
	GENERATED_BODY()

public:
	UPROPERTY()
	bool bEnabled;

	UPROPERTY()
	bool bConnectedToRoot;

	UPROPERTY()
	EMeshNetworkNodeType GameServerNodeType;

};

USTRUCT()
struct FPlayerDamageData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float Damage;

	UPROPERTY()
	uint8 TeamIndex;

	UPROPERTY()
	float TeamMMR;

};

USTRUCT(BlueprintType)
struct FPlayersLeft
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="PlayersLeft")
	int32 Humans;

	UPROPERTY(BlueprintReadOnly, Transient, Category="PlayersLeft")
	int32 Bots;

	UPROPERTY(BlueprintReadOnly, Transient, Category="PlayersLeft")
	int32 Total;

};

USTRUCT(BlueprintType)
struct FTotalPlayers
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="TotalPlayers")
	int32 Humans;

	UPROPERTY(BlueprintReadOnly, Transient, Category="TotalPlayers")
	int32 Bots;

	UPROPERTY(BlueprintReadOnly, Transient, Category="TotalPlayers")
	int32 Total;

};

USTRUCT()
struct FVariantUsageReportInner
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FGameplayTag ChannelTag;

	UPROPERTY()
	FGameplayTag VariantTag;

	UPROPERTY()
	int32 UseCount;

};

USTRUCT()
struct FVariantUsageReport
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FVariantUsageReportInner> VariantUsage;

	UPROPERTY()
	int32 TotalUses;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortGameStateAthena : public AFortGameStateZone, public IGameplayMutatorObserverInterface, public IFortMutatorOwner
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCurrentPlaylistLoaded, FName, PlaylistName, const FGameplayTagContainer&, PlaylistContextTags);

public:
	UFUNCTION(BlueprintPure, Category="SkyTubes")
	bool AreSkyTubesEnabled() const;

	UFUNCTION(BlueprintCallable)
	bool CanChangeGameplayOptions();

	UFUNCTION(BlueprintPure)
	bool CanRespawnOnStarterIsland() const;

	UFUNCTION(BlueprintPure)
	FEvaluationResult CanSpawnActor(const AActor* InstigatorActor, AActor* ActorToSpawn, const FVector& Location, const FRotator& Rotation) const;

	UFUNCTION(BlueprintPure)
	FEvaluationResult CanSpawnActorOfClass(const AActor* InstigatorActor, UClass* ActorClassToSpawn, const FVector& Location, const FRotator& Rotation) const;

	UFUNCTION(BlueprintCallable)
	bool CanUseSlowMotionOnVictory();

	UFUNCTION(BlueprintPure)
	void DoesPlayerHaveLimitedLives(AFortPlayerState* PlayerState, bool& bPlayerLivesAreLimited, int32& RespawnsRemaining) const;

	UFUNCTION(BlueprintPure)
	bool EvaluateDBNOMutator(const AFortPlayerState* PS, FDBNOCustomSettings& OutDBNOSetting) const;

	UFUNCTION(BlueprintCallable)
	virtual void GatherCustomCharacterPartOverridesFromMutator(AFortPlayerController* FortPC, TArray<UCustomCharacterPart*>& OutOverrides);

	UFUNCTION(BlueprintPure)
	FGameplayTagContainer GetAthenaPlaylistContextTags() const;

	UFUNCTION(BlueprintPure)
	int32 GetAvgPlayerMMR() const;

	UFUNCTION(BlueprintPure, Category="Aircraft")
	UAthenaBattleBusItemDefinition* GetBattleBusForPlayer(AFortPlayerControllerAthena* PC) const;

	UFUNCTION(BlueprintPure, Category="Playlist")
	FName GetCurrentPlaylistName() const;

	UFUNCTION(BlueprintPure, Category="Damage Combo")
	int32 GetDamageComboHUDMinHits() const;

	UFUNCTION(BlueprintPure)
	float GetEndGameReturnToMatchmakingOriginDelay() const;

	UFUNCTION(BlueprintPure)
	int32 GetMaxPlaylistPlayers() const;

	UFUNCTION(BlueprintNativeEvent)
	AFortGameplayMutator* GetMutatorByClass(const AActor* ContextActor, TSubclassOf<AFortGameplayMutator> MutatorClass);

	UFUNCTION(BlueprintNativeEvent)
	AFortGameplayMutator* GetMutatorByInterface(const AActor* ContextActor, UClass* MutatorInterface);

	UFUNCTION(BlueprintCallable)
	float GetOverriddenVehicleTrickScore(const AFortPlayerController* Controller, float InTrickScore);

	UFUNCTION(BlueprintPure)
	float GetOverridenDamageSelfDamageToDeal(const APawn* Pawn) const;

	UFUNCTION(BlueprintPure)
	bool GetOverridenDamageSelfRequiresNonZeroDamage(const APawn* Pawn) const;

	UFUNCTION(BlueprintPure)
	FGameplayTagQuery GetOverridenDamageSelfTargetQuery(const APawn* Pawn) const;

	UFUNCTION(BlueprintPure)
	FGameplayTagQuery GetOverridenDamageSelfWeaponQuery(const APawn* Pawn) const;

	UFUNCTION(BlueprintPure)
	float GetOverridenSiphonGoldValue(const APawn* Pawn) const;

	UFUNCTION(BlueprintPure)
	float GetOverridenSiphonHealthValue(const APawn* Pawn) const;

	UFUNCTION(BlueprintPure)
	float GetOverridenSiphonMetalValue(const APawn* Pawn) const;

	UFUNCTION(BlueprintPure)
	float GetOverridenSiphonStoneValue(const APawn* Pawn) const;

	UFUNCTION(BlueprintPure)
	float GetOverridenSiphonWoodValue(const APawn* Pawn) const;

	UFUNCTION(BlueprintPure)
	AFortPartyRiftPortalManager* GetPartyRiftPortalManager() const;

	UFUNCTION(BlueprintPure)
	FPlayersLeft GetPlayersLeft() const;

	UFUNCTION(BlueprintPure)
	FPlayersLeft GetPlayersLeftForUI() const;

	UFUNCTION(BlueprintPure, Category="Creative")
	bool GetPlaylistTeams(TArray<uint8>& OutTeams) const;

	UFUNCTION(BlueprintPure)
	EFortPlaylistType GetPlaylistType() const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="POI")
	FGameplayTagContainer GetPoiGridTagsForLocation(const FVector& Location) const;

	UFUNCTION(BlueprintCallable)
	float GetScoringModeWinningGoal();

	UFUNCTION(BlueprintPure)
	bool GetShouldDisplayCountdownTimerText() const;

	UFUNCTION(BlueprintPure)
	bool GetShouldPlayRespawnTimerSFX() const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	TArray<AFortPlayerStateAthena*> GetSquadMemberPlayerStates(AFortPlayerStateAthena* InstigatingPlayerState, const bool bIncludeSelf = false) const;

	UFUNCTION(BlueprintPure)
	FText GetTeamPOIName(uint8 Team) const;

	UFUNCTION(BlueprintPure)
	float GetTimedWinConditionTime() const;

	UFUNCTION(BlueprintPure)
	FTotalPlayers GetTotalPlayers() const;

	UFUNCTION(BlueprintCallable, Category="UI | Messaging")
	void HandleContextTutorialGameModeMessageRequest(FAthenaGameMessageData MessageData, UFortContextualTutorialController* OwnedController);

	UFUNCTION(BlueprintCallable, Category="UI | Messaging")
	void HandleGameModeHideMarker(int32 PlayerID, int32 InstanceID);

	UFUNCTION(BlueprintCallable, Category="UI | Messaging")
	void HandleGameModeMessageDefaultPosition();

	UFUNCTION(BlueprintCallable, Category="UI | Messaging")
	void HandleGameModeMessageReposition(FVector2D Position, EHorizontalAlignment HorizontalAlignment, EVerticalAlignment VerticalAlignment);

	UFUNCTION(BlueprintCallable, Category="UI | Messaging")
	void HandleGameModeMessageRequest(FAthenaGameMessageData MessageData);

	UFUNCTION(BlueprintCallable, Category="UI | Messaging")
	void HandleGameModeMessageSuccess(AFortPlayerController* OwnerController);

	UFUNCTION(BlueprintCallable, Category="UI | Messaging")
	void HandleGameModeShowMarker(int32 PlayerID, int32 InstanceID);

	UFUNCTION(BlueprintCallable, Category="UI | Messaging")
	void HandleHideGameModeMessageRequest(const EAthenaGameMsgType MsgType = EAthenaGameMsgType::None, const bool bInstantHide = false, const bool bClearQueue = false, int32 MessageChannel = -1);

	UFUNCTION(BlueprintPure)
	bool HasValidFocalPointActor() const;

	UFUNCTION(BlueprintPure)
	bool IsAnyCreativePlaylist() const;

	UFUNCTION(BlueprintPure)
	bool IsAsyncPhysicsPlaylist() const;

	UFUNCTION(BlueprintPure)
	bool IsBattleRoyalePlaylist(bool bExplicitCheck = false) const;

	UFUNCTION(BlueprintPure)
	bool IsCompetitivePlaylist() const;

	UFUNCTION(BlueprintPure)
	bool IsCreativeLTMPlaylist() const;

	UFUNCTION(BlueprintPure)
	bool IsCreativeMMPlaylist() const;

	UFUNCTION(BlueprintPure)
	bool IsCreativeModePlaylist() const;

	UFUNCTION(BlueprintPure)
	bool IsCreativeOrPlaygroundModePlaylist() const;

	UFUNCTION(BlueprintPure)
	bool IsCreativeRoyalePlaylist() const;

	UFUNCTION(BlueprintPure)
	bool IsCreativeUtilitySpawningAllowedPlaylist() const;

	UFUNCTION(BlueprintPure)
	bool IsExperiencePlayOnly() const;

	UFUNCTION(BlueprintPure)
	bool IsGamePhaseNotificationSkipped(EAthenaGamePhaseStep GamePhaseToSkip) const;

	UFUNCTION(BlueprintPure)
	bool IsGuidedTutorialPlaylist() const;

	UFUNCTION(BlueprintPure)
	bool IsLargePreviewDisabledOnMobile() const;

	UFUNCTION(BlueprintPure)
	bool IsLastManStandingCN() const;

	UFUNCTION(BlueprintPure)
	bool IsNoBuildBRPlaylist() const;

	UFUNCTION(BlueprintPure)
	bool IsPapayaPlaylist() const;

	UFUNCTION(BlueprintPure, Category="Creative")
	bool IsPlayerClearPersistanceIslandDataAllowed(const APawn* SwitchingPawn) const;

	UFUNCTION(BlueprintPure)
	bool IsPlayerTriggeredRespawnAllowed(const AFortPlayerState* PlayerState) const;

	UFUNCTION(BlueprintPure)
	bool IsPlayerTriggeredRespawnAllowedByPlaylist() const;

	UFUNCTION(BlueprintPure)
	bool IsPlaygroundModePlaylist() const;

	UFUNCTION(BlueprintPure)
	bool IsSpatialGameplayExperience() const;

	UFUNCTION(BlueprintPure, Category="Creative")
	bool IsTeamSwitchAllowed(const APawn* SwitchingPawn) const;

	UFUNCTION(BlueprintPure)
	bool IsTeleportToCreativeHubAllowed(const AFortPlayerState* PlayerState) const;

	UFUNCTION(BlueprintPure, Category="Creative")
	bool IsTherePersistenceDevices(const APawn* SwitchingPawn) const;

	UFUNCTION(BlueprintPure)
	bool IsVKEditPlaylist() const;

	UFUNCTION(BlueprintPure)
	bool IsVKPlayPlaylist() const;

	UFUNCTION(BlueprintPure)
	bool IsWeaponReticleWidgetVisible(const AFortPlayerController* Controller, const AFortWeapon* Weapon) const;

	UFUNCTION(BlueprintPure)
	bool IsWorldResourceWidgetVisible(const AFortPlayerController* Controller, const EFortResourceType::Type ResourceType) const;

	UFUNCTION()
	void OnRep_ClientItemDefsToLoad();

	UFUNCTION()
	void OnRep_CurrentHighScore();

	UFUNCTION()
	void OnRep_EndGameKickPlayerTime();

	UFUNCTION()
	void OnRep_FocalPointActor();

	UFUNCTION()
	void OnRep_MeshNetworkStatus();

	UFUNCTION()
	void OnRep_MutatorEventData();

	UFUNCTION()
	void OnRep_MutatorGenericInt_0();

	UFUNCTION()
	void OnRep_MutatorGenericInt_1();

	UFUNCTION()
	void OnRep_MutatorGenericInt_2();

	UFUNCTION()
	void OnRep_PlayersLeft();

	UFUNCTION()
	void OnRep_PlayersLoaded();

	UFUNCTION()
	void OnRep_ReticulatedSplineDefinitions();

	UFUNCTION()
	void OnRep_ServerChangelistNumber();

	UFUNCTION()
	void OnRep_SkyTubesDisabled();

	UFUNCTION()
	void OnRep_SkyTubesShuttingDown();

	UFUNCTION()
	void OnRep_SpecialActorData();

	UFUNCTION()
	void OnRep_SupplyDropWaveStartedSoundCue();

	UFUNCTION()
	void OnRep_TeamsLeft();

	UFUNCTION()
	void OnRep_WinningPlayerList();

	UFUNCTION()
	void OnRep_WinningPlayerState();

	UFUNCTION()
	void OnRep_WinningScore();

	UFUNCTION()
	void OnRep_WinningTeam();

	UFUNCTION()
	void OnRep_WinningTeamsCN();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Game")
	void OnWinnerAnnounced();

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="UI|Minimap")
	void OverrideAllLocations_StateFontMaterial(UMaterialInterface* Mat, EMapLocationStateType State);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="UI|Minimap")
	void OverrideLocation_StateFontMaterial(const FGameplayTag& LocationTag, UMaterialInterface* Mat, EMapLocationStateType State);

	UFUNCTION()
	void PauseFPSChartTimer();

	UFUNCTION(Client, Reliable)
	void RunPerfMemCheatScript_Client_Replicated(bool bStartStatFiles);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="UI|Minimap", meta=(AutoCreateRefTerm="Color"))
	void SetAllLocations_StateColor(const FLinearColor& Color, EMapLocationStateType State);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetCanSpawnLoot(const bool bInCanSpawnLoot);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetDefaultParachuteDeployTraceForGroundDistance(const float InDefaultParachuteDeployTraceForGroundDistance);

	UFUNCTION(BlueprintCallable, Category="Playlist")
	void SetFloatingIslandInformation(FVector WorldPosition, bool bActivated);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetFocalPointActor(AActor* InFocalPointActor, FVector InFocalPointOffset, float InFocalPointFOV, float InDuration, float InInterpSpeed = 5.000000f);

	UFUNCTION(BlueprintCallable)
	void SetKillFeedFilter(const FGameplayTagContainer& NewFilter);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="UI|Minimap", meta=(AutoCreateRefTerm="Color"))
	void SetLocation_StateColor(const FGameplayTag& LocationTag, const FLinearColor& Color, EMapLocationStateType State);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="UI|Minimap", meta=(DeprecatedFunction, DeprecationMessage="Prefer SetLocationColorInState so you aren't stomping location states (eg: undiscovered, golden)."))
	void SetLocationColor(const FGameplayTag& LocationTag, FLinearColor Color);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="UI|Minimap")
	void SetLocationColorInState(const FGameplayTag& LocationTag, FLinearColor Color, EMapLocationStateType State = EMapLocationStateType::Normal);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="UI|Minimap", meta=(DeprecatedFunction, DeprecationMessage="Prefer SetLocationFontInState so you aren't stomping location states (eg: undiscovered, golden)."))
	void SetLocationFont(const FGameplayTag& LocationTag, const FSlateFontInfo& Font);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="UI|Minimap")
	void SetLocationFontInAllStates(const FGameplayTag& LocationTag, const FSlateFontInfo& Font);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="UI|Minimap")
	void SetLocationFontInState(const FGameplayTag& LocationTag, const FSlateFontInfo& Font, EMapLocationStateType State = EMapLocationStateType::Normal);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="UI|Minimap")
	void SetLocationText(const FGameplayTag& LocationTag, const FText& Text, EMapLocationStateType State = EMapLocationStateType::Normal);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="UI|Minimap")
	void SetLocationTextWorldPosition(const FGameplayTag& LocationTag, FVector Location);

	UFUNCTION(BlueprintCallable)
	bool ShouldAllowKeepPlayingTogether();

	UFUNCTION(BlueprintCallable)
	bool ShouldAllowPartyRift();

	UFUNCTION(BlueprintCallable)
	bool ShouldAllowSquadSizeTracking();

	UFUNCTION(BlueprintPure)
	bool ShouldBlockQuestProgressReport() const;

	UFUNCTION(BlueprintPure)
	virtual bool ShouldBlockTrapPlacement(const APawn* Pawn) const;

	UFUNCTION(BlueprintPure)
	bool ShouldDBNOTeamInfoFlash() const;

	UFUNCTION(BlueprintPure)
	bool ShouldEnterSpawningStartup() const;

	UFUNCTION(BlueprintPure)
	bool ShouldHaveInfiniteResources(const APawn* Pawn) const;

	UFUNCTION(BlueprintPure, Category="Mutators")
	bool ShouldPlayDeathSoundEffects(const AActor* Victim) const;

	UFUNCTION(BlueprintPure)
	bool ShouldReturnToMatchmakingOriginOnMatchEnd() const;

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="UI|Minimap")
	void UpdateAllGoldenPoiColor(FLinearColor Color, const FSlateFontInfo& Font);

	UPROPERTY(Config)
	bool bCanBuildOnWaterGlobal;

	UPROPERTY(Config)
	bool bBlockBuildOnWaterGlobal;

	UPROPERTY(BlueprintAssignable)
	FOnNewContentUpdateMessageRecieved OnNewContentUpdateMessageRecieved;

	UPROPERTY(BlueprintAssignable)
	FOnNewScreenLogMessageRecieved OnNewScreenLogMessageReceived;

	UPROPERTY(BlueprintAssignable, Category="Playlist")
	FOnCurrentPlaylistLoaded OnCurrentPlaylistLoaded;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortGameStateAthena")
	bool bPlaylistDataIsLoaded;

	UPROPERTY(Transient)
	bool bPlaylistDataIsActivelyLoading;

	UPROPERTY(BlueprintAssignable)
	FOnAllWinnersAnnounced AllWinnersAnnounced;

	UPROPERTY(BlueprintAssignable)
	FOnWinnerInfoDisplayReadyCN WinnerInfoDisplayReadyCN;

	UPROPERTY(BlueprintAssignable)
	FOnCountdownTick CountdownTick;

	UPROPERTY(BlueprintAssignable)
	FOnCountdownStarted CountdownStarted;

	UPROPERTY(BlueprintAssignable)
	FOnCountdownFinished CountdownFinished;

	UPROPERTY(BlueprintAssignable)
	FOnCountdownStopped CountdownStopped;

	UPROPERTY(BlueprintAssignable)
	FOnFinalCountdownTick FinalCountdownTick;

	UPROPERTY(BlueprintAssignable)
	FOnFinalCountdownStarted FinalCountdownStarted;

	UPROPERTY(BlueprintAssignable)
	FOnFinalCountdownFinished FinalCountdownFinished;

	UPROPERTY(BlueprintAssignable)
	FOnCurrentHighScoreUpdated CurrentHighScoreUpdated;

	UPROPERTY(BlueprintAssignable)
	FOnGameStateGoalScoreChanged OnGoalScoreChanged;

	UPROPERTY(BlueprintAssignable, Category="Pickup")
	FPickupOnSpawnReady OnPickupSpawnedAndReady;

	UPROPERTY(BlueprintAssignable, Category="Pickup")
	FPickupOnDestroy OnPickupDestroy;

	UPROPERTY(BlueprintAssignable)
	FOnGameModeMessageRequest GameModeMessageRequest;

	UPROPERTY(BlueprintAssignable)
	FOnContextTutorialGameModeMessageRequest ContextTutorialGameModeMessageRequest;

	UPROPERTY(BlueprintAssignable)
	FOnHideGameModeMessageRequest HideGameModeMessageRequest;

	UPROPERTY(BlueprintAssignable)
	FOnGameModeMessageSuccess GameModeMessageSuccess;

	UPROPERTY(BlueprintAssignable)
	FShowGameModeMessage ShowGameModeMessage;

	UPROPERTY(BlueprintAssignable)
	FHideGameModeMessage HideGameModeMessage;

	UPROPERTY(BlueprintAssignable)
	FOnGameModeShowMarker ShowMarkerGameMode;

	UPROPERTY(BlueprintAssignable)
	FOnGameModeRemoveMarker HideMarkerGameMode;

	UPROPERTY(BlueprintAssignable)
	FRepositionGameModeMessage RepositionGameModeMessage;

	UPROPERTY(BlueprintAssignable)
	FSetDefaultGameModeMessage SetDefaultPositionGameModeMessage;

	UPROPERTY(BlueprintAssignable)
	FOnPlayerJoinedLeftCreativeIsland OnPlayerLeftCreativeIsland;

	UPROPERTY(BlueprintAssignable)
	FOnPlayerJoinedLeftCreativeIsland OnPlayerJoinedCreativeIsland;

	UPROPERTY(BlueprintAssignable)
	FOnMutatorGenericIntegerUpdated MutatorGenericIntegerUpdated;

	UPROPERTY(BlueprintAssignable)
	FOnMutatorGameplayEvent MutatorGameplayEvent;

	UPROPERTY()
	bool bForceTeamScorePlacementOnDeath;

	UPROPERTY(ReplicatedUsing=OnRep_SkyTubesShuttingDown)
	bool bSkyTubesShuttingDown;

	UPROPERTY(ReplicatedUsing=OnRep_SkyTubesDisabled)
	bool bSkyTubesDisabled;

	UPROPERTY(ReplicatedUsing=OnRep_ServerChangelistNumber)
	int32 ServerChangelistNumber;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_SpecialActorData)
	TObjectPtr<AFortSpecialActorReplicationInfo> SpecialActorData;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Building")
	TArray<TSubclassOf<ABuildingActor>> BuildingActorClasses;

	UPROPERTY(BlueprintAssignable)
	FOnWinnerAnnounced WinnerAnnounced;

	UPROPERTY(BlueprintAssignable)
	FOnWinningTeamAnnounced WinningTeamAnnounced;

	UPROPERTY(BlueprintAssignable)
	FOnWinningScoreAnnounced WinningScoreDetermined;

	UPROPERTY(BlueprintAssignable)
	FOnActiveTeamArrayBuilt ActiveTeamArrayBuiltEvent;

	UPROPERTY(BlueprintAssignable, Category="Game")
	FOnPlayersLeftChanged OnPlayersLeftChanged;

	UPROPERTY(BlueprintAssignable, Category="Game")
	FOnTeamsLeftChanged OnTeamsLeftChanged;

	UPROPERTY(BlueprintAssignable, Category="Game")
	FOnWinConditionMetCN OnWinConditionMetCN;

	UPROPERTY(BlueprintAssignable, Category="Game")
	FUpdateNamedPoiColorDelegate UpdateNamedPoiColorDelegate;

	UPROPERTY(Config)
	bool bSkipWinnerAnnounced;

	UPROPERTY(Config)
	bool bStopBuildingHealingOnDamage;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="EndGame")
	float EndGameStartTime;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_EndGameKickPlayerTime, Category="EndGame")
	float EndGameKickPlayerTime;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Game")
	int32 TotalPlayers;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_PlayersLeft, Category="Game")
	int32 PlayersLeft;

	UPROPERTY(ReplicatedUsing=OnRep_PlayersLoaded)
	int32 PlayersLoaded;

	UPROPERTY(Replicated)
	TArray<TSubclassOf<UObject>> ClientVehicleClassesToLoad;

	UPROPERTY(ReplicatedUsing=OnRep_ClientItemDefsToLoad)
	TArray<TObjectPtr<UFortItemDefinition>> ClientItemDefsToLoad;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortProjectileBase>> PredictedProjectiles;

	UPROPERTY(Transient)
	float RemainingFocalPointActorDuration;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_FocalPointActor)
	TObjectPtr<AActor> FocalPointActor;

	UPROPERTY(Transient, Replicated)
	float FocalPointRotationInterpSpeed;

	UPROPERTY(Transient, Replicated)
	FVector_NetQuantize FocalPointOffset;

	UPROPERTY(Transient, Replicated)
	float FocalPointFOV;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Game")
	TArray<int32> TeamXPlayersLeft;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_WinningPlayerList, Category="Game")
	TArray<FFortWinnerPlayerData> WinningPlayerList;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_TeamsLeft, Category="Game")
	int32 TeamsLeft;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_WinningTeamsCN, Category="Game")
	TArray<uint8> WinningTeamsCN;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Game")
	TArray<TObjectPtr<UObject>> ServerToClientPreloadList;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Game")
	TObjectPtr<UAthenaBattleBusItemDefinition> DefaultBattleBus;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Game")
	bool bAllowUserPickedCosmeticBattleBus;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Game")
	TArray<FAircraftFlightInfo> TeamFlightPaths;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Game")
	FAircraftFlightInfo FlightPathMidLine;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Game")
	FVector2D DropZoneCenter;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Game")
	FVector2D FlightPathSelectionCenter;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_UtcTimeStartedMatch, Category="Game")
	FDateTime UtcTimeStartedMatch;

	UPROPERTY(Replicated)
	bool bIsLargeTeamGame;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_WinningPlayerState, Category="Game")
	TObjectPtr<APlayerState> WinningPlayerState;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_WinningTeam, Category="Game")
	int32 WinningTeam;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_WinningScore, Category="Game")
	int32 WinningScore;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_CurrentHighScore, Category="Game")
	int32 CurrentHighScore;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Game")
	int32 CurrentHighScoreTeam;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_SupplyDropWaveStartedSoundCue, Category="Game")
	TObjectPtr<USoundCue> SupplyDropWaveStartedSoundCue;

	UPROPERTY(BlueprintReadOnly, Category="Game")
	TArray<FText> KillFeedEntry;

	UPROPERTY(BlueprintAssignable)
	FOnKillFeedUpdated KillFeedUpdated;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortPlayerState>> SpectatorArray;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortPlayerState>> PartyMemberSpectatorArray;

	UPROPERTY(Replicated)
	bool bStormReachedFinalPosition;

	UPROPERTY(Replicated)
	EFriendlyFireType FriendlyFireType;

	UPROPERTY(EditDefaultsOnly, Category="Audio")
	TObjectPtr<USoundMix> LobbySoundMix;

	UPROPERTY(ReplicatedUsing=OnRep_MutatorEventData)
	FGameplayMutatorEventData MutatorEventData;

	UPROPERTY(Replicated)
	FGameplayMutatorObjectDataArray MutatorObjectDataArray;

	UPROPERTY(ReplicatedUsing=OnRep_MutatorGenericInt_0)
	int32 MutatorGenericInt_0;

	UPROPERTY(ReplicatedUsing=OnRep_MutatorGenericInt_1)
	int32 MutatorGenericInt_1;

	UPROPERTY(ReplicatedUsing=OnRep_MutatorGenericInt_2)
	int32 MutatorGenericInt_2;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="HotfixWorkAround")
	float DefaultGliderRedeployCanRedeploy;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="HotfixWorkAround")
	float DefaultRedeployGliderLateralVelocityMult;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="HotfixWorkAround")
	float DefaultRedeployGliderHeightLimit;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="HotfixWorkAround")
	float DefaultParachuteDeployTraceForGroundDistance;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="HotfixWorkAround")
	float DefaultAllowNeutralWallEditing;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="HotfixWorkAround")
	float SignalInStormRegenSpeed;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="HotfixWorkAround")
	float SignalInStormLostSpeed;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="HotfixWorkAround")
	float StormCNDamageVulnerabilityLevel0;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="HotfixWorkAround")
	float StormCNDamageVulnerabilityLevel1;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="HotfixWorkAround")
	float StormCNDamageVulnerabilityLevel2;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="HotfixWorkAround")
	float StormCNDamageVulnerabilityLevel3;

	UPROPERTY(ReplicatedUsing=OnRep_MeshNetworkStatus)
	FMeshNetworkStatus MeshNetworkStatus;

	UPROPERTY()
	FOnClientVolumeManagerReplicated OnClientVolumeManagerReplicated;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Creative")
	TSubclassOf<AFortVolumeManager> VolumeManagerToUse;

	UPROPERTY(EditDefaultsOnly, Category="FortGameStateAthena")
	TSubclassOf<AFortPartyRiftPortalManager> PartyRiftPortalManagerToUse;

	UPROPERTY(EditDefaultsOnly, Category="BattleRoyale")
	TSubclassOf<UFortGameStateComponent_BattleRoyaleGamePhaseLogic> BattleRoyaleGamePhaseLogicClass;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ReticulatedSplineDefinitions)
	TArray<FString> ReticulatedSplineDefinitions;

	UPROPERTY(Transient, Replicated)
	TArray<FAthenaStreamIdOverride> ReticulatedSplineIds;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortMissionStormShield>> StormShields;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortGameStateAthena")
	FScalableFloat DelayMovementInput;

protected:
	UFUNCTION(BlueprintCallable)
	void InitializeAnimationSharing(const UFortPlaylistAthena* FortAthenaPlaylist);

	UFUNCTION()
	void OnDownloadedAnyAdditionalContent(bool bSuccess);

	UFUNCTION()
	void OnLoadedAllAdditionalContent(bool bSuccess);

	UFUNCTION()
	void OnRep_AICharacterPartsPreloadData();

	UFUNCTION()
	void OnRep_AIPawnCustomizationPreloadData();

	UFUNCTION()
	void OnRep_BroadcastSpectatorInfo();

	UFUNCTION()
	void OnRep_CurrentPlaylistId();

	UFUNCTION()
	void OnRep_CurrentPlaylistInfo();

	UFUNCTION()
	void OnRep_EventTournamentRound();

	UFUNCTION()
	void OnRep_MapInfo();

	UFUNCTION()
	void OnRep_PlayerBotsLeft();

	UFUNCTION()
	void OnRep_SpectateAPartyMemberAvailable();

	UFUNCTION()
	void OnRep_UtcTimeStartedMatch(const FDateTime& OldUtcTimeStartedMatch);

	UFUNCTION()
	void OnRep_VolumeManager();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	bool OverrideSpawnPercentage(const TSubclassOf<ABuildingContainer> BuildingContainerClass, const float SpawnPercentage);

	UPROPERTY(Replicated)
	bool bIsGrassFireBoundsUpdateEnabled;

	UPROPERTY(Transient)
	bool bCanSpawnLoot;

	UPROPERTY(Transient)
	TObjectPtr<UCurveTable> AthenaGameDataTable;

	UPROPERTY(VisibleAnywhere, Config, Category="FortGameStateAthena")
	TArray<FName> AthenaGameDataResetRows;

	UPROPERTY(Transient)
	TObjectPtr<UCurveTable> ResetAthenaGameDataTable;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_IsUsingDownloadOnDemand)
	bool bIsUsingDownloadOnDemand;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_WantsHoldoverPluginOnClient)
	bool bWantsHoldoverPluginOnClient;

	UPROPERTY(Config)
	bool bDisconnectOnContentBeaconError;

	UPROPERTY(Transient, Replicated)
	TObjectPtr<AFortPropertyOverrideReplShared> ReplOverrideData;

	UPROPERTY(Replicated)
	bool bCheatRespawnEnabled;

	UPROPERTY(ReplicatedUsing=OnRep_SpectateAPartyMemberAvailable)
	bool SpectateAPartyMemberAvailable;

	UPROPERTY(Replicated)
	FGameMemberInfoArray GameMemberInfoArray;

	UPROPERTY(Replicated)
	TArray<uint8> ActiveTeamNums;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_CurrentPlaylistId, Category="Game")
	int32 CurrentPlaylistId;

	UPROPERTY(Transient)
	TObjectPtr<UMaterialInstanceDynamic> MinimapBackgroundMID;

	UPROPERTY(Transient)
	TObjectPtr<UMaterialInstanceDynamic> MinimapCircleMID;

	UPROPERTY(Transient)
	TObjectPtr<UMaterialInstanceDynamic> MinimapNextCircleMID;

	UPROPERTY(Transient)
	TObjectPtr<UMaterialInstanceDynamic> FullMapCircleMID;

	UPROPERTY(Transient)
	TObjectPtr<UMaterialInstanceDynamic> FullMapNextCircleMID;

	UPROPERTY(Transient)
	FSlateBrush MinimapSafeZoneBrush;

	UPROPERTY(Transient)
	FSlateBrush MinimapCircleBrush;

	UPROPERTY(Transient)
	FSlateBrush MinimapNextCircleBrush;

	UPROPERTY(Transient)
	FSlateBrush FullMapCircleBrush;

	UPROPERTY(Transient)
	FSlateBrush FullMapNextCircleBrush;

	UPROPERTY(Transient)
	FSlateBrush MinimapSafeZoneFinalPosBrush;

	UPROPERTY(Transient)
	FSlateBrush AircraftPathBrush;

	UPROPERTY(Transient)
	FSlateBrush AircraftMidlinePathBrush;

	UPROPERTY(Transient)
	FSlateBrush AircraftPathTeamIndicatorBrush;

	UPROPERTY(EditDefaultsOnly, Category="MiniMap")
	TObjectPtr<UMaterialInterface> MiniMapBackgroundDrawingMaterial;

	UPROPERTY(EditDefaultsOnly, Category="MiniMap")
	TObjectPtr<UMaterialInterface> MiniMapCircleDrawingMaterial;

	UPROPERTY(EditDefaultsOnly, Category="MiniMap")
	TObjectPtr<UMaterialInterface> MiniMapNextCircleDrawingMaterial;

	UPROPERTY(EditDefaultsOnly, Category="MiniMap")
	TObjectPtr<UMaterialInterface> MiniMapRadiusTrackerCircleDrawingMaterial;

	UPROPERTY(EditDefaultsOnly, Category="MiniMap")
	FName RadiusTrackerCircleCenterAndRadiusParameterName;

	UPROPERTY(EditDefaultsOnly, Category="MiniMap")
	FName RadiusTrackerCircleColorParameterName;

	UPROPERTY(Transient)
	TArray<FDynamicLandData> DynamicShadows;

	UPROPERTY(Transient)
	TArray<FDynamicLandData> DynamicLands;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_MapInfo, Category="Game")
	TObjectPtr<AFortAthenaMapInfo> MapInfo;

	UPROPERTY(EditDefaultsOnly, Category="MiniMap")
	TObjectPtr<UMaterialParameterCollection> MinimapMPC;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_BroadcastSpectatorInfo)
	TObjectPtr<AFortBroadcastSpectatorInfo> BroadcastSpectatorInfo;

	UPROPERTY(Transient)
	TObjectPtr<USplatterGridSystem> SplatterGridSystem;

	UPROPERTY(Transient)
	TObjectPtr<UFortCustomizationsPreloader> CustomizationsPreloader;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_AICharacterPartsPreloadData)
	TArray<FAICharacterPartsPreloadData> AICharacterPartsPreloadData;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_AIPawnCustomizationPreloadData)
	TArray<FAIPawnCustomizationPreloadData> AIPawnCustomizationPreloadData;

	UPROPERTY(Replicated)
	FString ReasonWereInSetupPhase;

	UPROPERTY(ReplicatedUsing=OnRep_EventTournamentRound)
	EEventTournamentRound EventTournamentRound;

	UPROPERTY(Replicated)
	bool bIsCustomMatch;

	UPROPERTY(ReplicatedUsing=OnRep_CurrentPlaylistInfo)
	FPlaylistPropertyArray CurrentPlaylistInfo;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Game")
	int32 TotalPlayersBots;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_PlayerBotsLeft, Category="Game")
	int32 PlayerBotsLeft;

	UPROPERTY(Replicated)
	int32 LobbyAction;

	UPROPERTY(Transient)
	TObjectPtr<AFortAthenaMutator_AI> GameplayMutator_AI;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Export, Category="FortGameStateAthena", meta=(EditInline="true"))
	TObjectPtr<UFortMutatorListComponent> MutatorListComponent;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_VolumeManager)
	TObjectPtr<AFortVolumeManager> VolumeManager;

	UPROPERTY(Transient, Replicated)
	TObjectPtr<AFortPartyRiftPortalManager> PartyRiftPortalManager;

	UPROPERTY(Transient, Replicated)
	TObjectPtr<AFortLocalizationService> LocalizationService;

	UPROPERTY(Transient)
	TObjectPtr<UFortSanitizationService> SanitizationService;

	UPROPERTY(Transient)
	TObjectPtr<UFortHermesLoadContext> HermesLoadContext;

	UPROPERTY(EditDefaultsOnly, Category="Resurrection")
	FScalableFloat ResurrectionEnabledRow;

	UPROPERTY(EditDefaultsOnly, Category="Resurrection|UI")
	FSlateBrush SpawnMachineIconBrush;

	UPROPERTY(EditDefaultsOnly, Category="Resurrection|UI")
	FSlateBrush SpawnCardIconBrush;

	UPROPERTY(EditDefaultsOnly, Category="Teammate|UI")
	FSlateBrush TeammateIconBrush;

	UPROPERTY(EditDefaultsOnly, Category="Elimination|Self")
	FSlateBrush EliminationSelfIconBrush;

	UPROPERTY(EditDefaultsOnly, Category="Elimination|Self")
	FSlateBrush EliminationSelfClampedIconBrush;

	UPROPERTY(EditDefaultsOnly, Category="Elimination|Squadmate")
	FSlateBrush EliminationSquadmateIconBrush;

	UPROPERTY(EditDefaultsOnly, Category="Elimination|Squadmate")
	FSlateBrush EliminationSquadmateClampedIconBrush;

	UPROPERTY(EditDefaultsOnly, Category="Elimination|Teammate")
	FSlateBrush EliminationTeammateIconBrush;

	UPROPERTY(EditDefaultsOnly, Category="Elimination|Teammate")
	FSlateBrush EliminationTeammateClampedIconBrush;

	UPROPERTY(EditDefaultsOnly, Category="Elimination|Enemies")
	FSlateBrush EliminationEnemyIconBrush;

	UPROPERTY(EditDefaultsOnly, Category="Elimination|Enemies")
	FSlateBrush EliminationEnemyClampedIconBrush;

	UPROPERTY(EditDefaultsOnly, Category="Elimination|Curves")
	TSoftObjectPtr<UCurveFloat> EliminationFadeInCurve;

	UPROPERTY(EditDefaultsOnly, Category="Elimination|Curves")
	TSoftObjectPtr<UCurveFloat> EliminationFadeOutCurve;

	UPROPERTY(EditDefaultsOnly, Category="Elimination|Curves")
	TSoftObjectPtr<UCurveVector> EliminationScaleInCurve;

	UPROPERTY(EditDefaultsOnly, Category="Elimination|Curves")
	TSoftObjectPtr<UCurveVector> EliminationScaleOutCurve;

	UPROPERTY(EditDefaultsOnly, Category="Elimination")
	float EliminationMarkerHUDMaxDistance;

	UPROPERTY(EditDefaultsOnly, Category="Elimination")
	float EliminationMarkerHUDZOffset;

	UPROPERTY(Transient)
	TArray<FString> ActiveEventNamesAtPlaylistLoad;

	UPROPERTY(EditDefaultsOnly, Category="NamedWeights")
	FScalableFloat NewItemDuringWarmupWeightAddMod;

	UPROPERTY(Transient)
	float SmoothedWorldTimeSeconds;

	UPROPERTY(Transient)
	float SmoothedWorldTimeSecondsDrift;

	UPROPERTY(BlueprintAssignable)
	FOnEndGameTimeDilationComplete EndGameTimeDilationCompleteDelegate;

private:
	UFUNCTION()
	void OnRep_GoldenPoiLocationTags();

	UFUNCTION()
	void OnRep_IsUsingDownloadOnDemand();

	UFUNCTION()
	void OnRep_WantsHoldoverPluginOnClient();

	UPROPERTY(ReplicatedUsing=OnRep_GoldenPoiLocationTags)
	FGameplayTagContainer GoldenPoiLocationTags;

	UPROPERTY()
	TObjectPtr<AUnicornDriver> UnicornDriver;

	UPROPERTY(Transient, Replicated)
	FGameplayTagContainer RolledLootGroupTags;

	UPROPERTY(Transient, Replicated)
	bool bEnvironmentDamageBlocked;

	UPROPERTY(Replicated)
	bool bDamageComboHUDEnabled;

	UPROPERTY(Replicated)
	int32 DamageComboHUDMinHits;

	UPROPERTY(Config)
	bool bEnableMatchesProxy;

	UPROPERTY(Transient, Replicated)
	FString MatchesProxyMatchId;

	UPROPERTY(Replicated)
	float DelayMovementInputReplicated;

	UPROPERTY(Replicated)
	bool bCraftingEnabled;

	UPROPERTY(EditDefaultsOnly, Category="Bus Driver")
	TMap<FString, FText> BusDriverMessages;

};

