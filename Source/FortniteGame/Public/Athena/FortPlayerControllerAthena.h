// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/NetSerialization.h"
#include "GameFramework/OnlineReplStructs.h"
#include "GameplayTagContainer.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "Misc/Guid.h"
#include "Misc/Timespan.h"
#include "ScalableFloat.h"
#include "UpdateManager.h"
#include "AsyncTaskQueue.h"
#include "Athena/AthenaQuickChatActiveEntry.h"
#include "Athena/Markers/FortWorldMarker.h"
#include "Athena/Physics/TimeStampedPhysicsPawnState.h"
#include "Athena/PlayerStateEncryptionKey.h"
#include "AthenaPlayerMatchReport.h"
#include "Building/BuildingTypes.h"
#include "Conversation/FortGiftUINotifications.h"
#include "Cosmetics/FortCosmeticLoadout.h"
#include "Creative/FortCreativeTypes.h"
#include "FortCombatTypes.h"
#include "FortHUDMessageData.h"
#include "FortItemAndCount.h"
#include "FortTypes.h"
#include "Input/FortActionKeyMapping.h"
#include "Items/FortItemEntry.h"
#include "Items/FortPersistentTypes.h"
#include "Items/FortPlaysetStreamingData.h"
#include "Items/FortQuickBars.h"
#include "OnlineLinkId.h"
#include "Player/FortPlayerControllerZone.h"
#include "Tests/FortProfileUtils.h"
#include "FortPlayerControllerAthena.generated.h"

class AActor;
class ACameraActor;
class AFortAthenaCreativePortal;
class AFortAthenaPartyRiftPortal;
class AFortBroadcastRemoteClientInfo;
class AFortCreativeTimerDevice;
class AFortGameStateAthena;
class AFortGameplayMutator;
class AFortMinigame;
class AFortPhysicsPawnObject;
class AFortPickup;
class AFortPlayerController;
class AFortPlayerControllerAthena;
class AFortPlayerMarkerBase;
class AFortPlayerPawn;
class AFortPlayerPawnAthena;
class AFortPlayerStartWarmup;
class AFortPlayerState;
class AFortPlayerStateAthena;
class AFortVolume;
class APawn;
class APlayerState;
class UAthenaMarkerComponent;
class UAthenaPlayerMatchReport;
class UAthenaResurrectionComponent;
class UCreativeAnalyticsComponent;
class UCreativeUserContentManager;
class UFortControllerComponent_AthenaQuestsPinner;
class UFortControllerComponent_Habanero;
class UFortControllerComponent_IndicatedActorManagement;
class UFortControllerComponent_InventoryService;
class UFortControllerComponent_LocalizationService;
class UFortControllerComponent_MapDiscoverability;
class UFortControllerComponent_MinigameActivity;
class UFortControllerComponent_RadiusTracker;
class UFortControllerComponent_RechargeWeapons;
class UFortControllerComponent_SeasonItem;
class UFortControllerComponent_SkydiveFeedback;
class UFortControllerComponent_ToxicityService;
class UFortControllerComponent_TransientQuests;
class UFortCreativeDeviceButtonComponent;
class UFortCreativeEntitlementComponent;
class UFortCreativeObjectTrackingComponent;
class UFortCreativeRealEstatePlotItemDefinition;
class UFortGamepadSettings;
class UFortHero;
class UFortItemDefinition;
class UFortMiniMapTeamIndicators;
class UFortPlayerControllerAthenaXPComponent;
class UFortPlaysetItemDefinition;
class UFortWeaponItemDefinition;
class UFortWorldItem;
class UFortWorldItemDefinition;
class UInputComponent;
class UObject;
class USoundBase;
class USoundCue;
enum class EDeathCause : uint8;
enum class EDuelState : uint8;
enum class EEndOfMatchReason : uint8;
enum class EFortItemType : uint8;
enum class EFortVolumeType : uint8;
enum class EMatchmakingCancelReasonV2 : uint8;
enum class EMatchmakingUtilityState : uint8;
enum class ERoundVictoryAnimation : uint8;

UENUM()
enum class EMapZoomingMode : uint8
{
	None = 0,
	ZoomingIn = 1,
	ZoomingOut = 2,
};

UENUM(BlueprintType)
enum class ERoundVictoryAnimation : uint8
{
	Default = 0,
	// Uses BR Victory confetti 

	None = 1,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FFortPlayerControllerAthenaOnPickupProjectileCreated, const AFortPlayerControllerAthena*, PlayerController, const UFortItemDefinition*, ItemDefinition);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAircraftStateChange);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCameraInStormWallChange, bool, bInStormWall);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCinematicCameraSkipped, AFortPlayerControllerAthena*, CinematicCameraUser);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnClientDonationSuccessDelegate);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCreativeContentFilterChanged);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCreativePermissionsChanged);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCreativePlotLinkedVolumeChanged, AFortVolume*, Volume);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFocalPointActorChanged, AActor*, NewFocalActor);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHUDMessageToggled, const FHUDMessageData&, HUDMessageData, bool, bShowMessage);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInGameContentDownloadStarted);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnInGameLoadScreenChanged, AFortPlayerControllerAthena*, PlayerController, bool, bEnableLoadScreen, FText, HUDReasonText);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInGameMatchmakingCanceled, EMatchmakingCancelReasonV2, CancelReason);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInGameMatchmakingComplete, bool, bSuccess);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInGameMatchmakingError, FString, ErrorMessage);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnInGameMatchmakingQueuedStatusUpdated, const FTimespan&, EstimatedWaitTime, int32, NumQueuedPlayers, FString, LinkCode);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInGameMatchmakingReadyCheckComplete);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInGameMatchmakingStarted);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnInGameMatchmakingStateChanged, FString, NewState, const FText&, NewStateText);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnInGameMatchmakingUtilityStateChanged, EMatchmakingUtilityState, OldState, EMatchmakingUtilityState, NewState, bool, bIsRunningMatchmakingFlow);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInGamematchmakingUpdateCheckFailed, EUpdateCompletionStatus, UpdateStatus);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnIslandEntriesChanged);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnItemDropSpawned, const AFortPickup*, Pickup, const UFortItemDefinition*, ItemDef, FGameplayTagContainer, ItemTags);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnItemDroppedDueToOverflow, const UFortWorldItem*, ItemDropped);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnLocalPlayerChangedTeams);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMCPIslandRequestFinished, bool, bSuccess, const FText&, Reason);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlayerForcedOffIslandEvent);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayerPawnEvent, AFortPlayerPawn*, PlayerPawn);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPreviewScreenshotCameraActivated, bool, bActivated);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnSkydiveLeaderChanged, bool, bEnabled, bool, bLocal, AFortPlayerState*, LeaderPlayerState);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSpectatorStreaming, bool, bSpectatorStreaming);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTalkingPlayersChanged);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnUsingFocalPointChanged, AFortPlayerControllerAthena*, FocalPointUser, AActor*, FocalPointActor, bool, bUsingFocalPoint);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnViewTargetKillsChanged, int32, NewKills);

USTRUCT()
struct FContentDownloadReplayModuleInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString ModuleId;

	UPROPERTY()
	FString ArtifactId;

};

USTRUCT()
struct FContentDownloadReplayURIInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString ContentURI;

};

USTRUCT()
struct FAthenaContentDownloadReplayData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FContentDownloadReplayModuleInfo> ModuleInfo;

	UPROPERTY()
	TArray<FContentDownloadReplayURIInfo> URIInfo;

};

USTRUCT()
struct FBuildingEditAnalyticEvent
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TEnumAsByte<EFortBuildingType::Type> BuildingType;

	UPROPERTY()
	TEnumAsByte<EFortResourceType::Type> ResourceType;

	UPROPERTY()
	FVector Location;

};

USTRUCT()
struct FBuildingStats
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 BuildingsPlaced;

	UPROPERTY()
	int32 WallsPlaced;

	UPROPERTY()
	int32 StairsPlaced;

	UPROPERTY()
	int32 FloorsPlaced;

	UPROPERTY()
	int32 RoofsPlaced;

	UPROPERTY()
	int32 WoodBuildingsPlaced;

	UPROPERTY()
	int32 StoneBuildingsPlaced;

	UPROPERTY()
	int32 MetalBuildingsPlaced;

	UPROPERTY()
	int32 BuildingsEdited;

};

USTRUCT()
struct FCreativePlotSessionData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 TimesInventoryOpened;

	UPROPERTY()
	int32 TimesIslandMenuOpened;

	UPROPERTY()
	int32 TimesGameStarted;

};

USTRUCT()
struct FLevelStreamRequestHandshakeState
{
	GENERATED_BODY()

public:
	UPROPERTY()
	bool bLevelStreamingCompleted;

};

USTRUCT()
struct FMinigameSpawnData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	uint8 Team;

	UPROPERTY()
	uint8 ClassSlot;

	UPROPERTY()
	bool bIsSet;

};

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Collision", "Rendering", "Transformation"))
class AFortPlayerControllerAthena : public AFortPlayerControllerZone
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnIslandMetatdataUpdateComplete, FString, Error);

public:
	UFUNCTION(BlueprintCallable)
	void BroadcastDeviceButtonComponentClickedDelegate(const UFortCreativeDeviceButtonComponent* DeviceButtonComponent);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic)
	void BroadcastOnHUDMessageToggled(const FHUDMessageData& HUDMessageData, bool bShowMessage);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void BroadcastOnPickupProjectileCreated(UFortItemDefinition* ItemDefinition);

	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	void CancelCreativeMatchmakingReadyCheck() const;

	UFUNCTION(BlueprintCallable)
	void CancelMatchmaking(EMatchmakingCancelReasonV2 CancelReason);

	UFUNCTION(BlueprintPure, Category="Team")
	bool CanFollowSpecialActor() const;

	UFUNCTION(BlueprintPure, Category="Creative")
	bool CanPlayerCreateInCurrentVolume(AFortVolume*& OutCurrentVolume) const;

	UFUNCTION()
	void CheckIfClientLoadedLTM();

	UFUNCTION()
	void CheckIfSafeToTurnOnCamera();

	UFUNCTION(BlueprintCallable)
	void ClearDroppableItems(bool bAllowShouldDropItemOverride = false);

	UFUNCTION(BlueprintCallable)
	void ClearInventorySpaces(int32 NumSpaces);

	UFUNCTION(BlueprintCallable, Category="Creative")
	void ClearPendingMinigameSpawnData();

	UFUNCTION(BlueprintCallable)
	void ClearRespawnAfterDeathTimer();

	UFUNCTION(Client, Reliable)
	void Client_DisplayQuestUpdate(const TArray<FFortDisplayQuestUpdateData>& UpdateData);

	UFUNCTION(Client, Unreliable)
	void Client_DisplayReceivedMultipleInstanceLoot(const TArray<FGiftUINotificationInfo>& ItemsReceived);

	UFUNCTION(Client, Reliable)
	void ClientAddProfileGoCollection(const FString& CollectionName, const TArray<FProfileGoScenario>& NewScenarios);

	UFUNCTION(Client, Reliable)
	void ClientAlertForcedOffIsland();

	UFUNCTION(Client, Reliable)
	void ClientAlertLeaveIsland();

	UFUNCTION(Client, Reliable)
	void ClientAlertPortalDoneTeleporting();

	UFUNCTION(Client, Reliable)
	void ClientBotStartDogpile(FVector DogpilePosition);

	UFUNCTION(Client, Reliable)
	void ClientBotStopDogpile();

	UFUNCTION(Client, Reliable)
	void ClientBroadcastOnDestroyCreativePlotFinished(bool bSuccess, const FText& Reason);

	UFUNCTION(Client, Reliable)
	void ClientBroadcastOnDuplicateCreativePlotFinished(bool bSuccess, const FText& Reason);

	UFUNCTION(Client, Reliable)
	void ClientBroadcastOnMakeNewCreativePlotFinished(bool bSuccess, const FText& Reason);

	UFUNCTION(Client, Reliable)
	void ClientBroadcastOnRestoreCreativePlotFinished(bool bSuccess, const FText& Reason);

	UFUNCTION(Client, Reliable)
	void ClientBroadcastOnUpdateCreativeDescriptionTags(bool bSuccess, const FText& Reason);

	UFUNCTION(Client, Reliable)
	void ClientBroadcastOnUpdateCreativePlotName(bool bSuccess, const FText& Reason);

	UFUNCTION(Client, Reliable)
	void ClientBroadcastPlotItemID(const FString& PlotID);

	UFUNCTION(Client, Reliable, WithValidation)
	void ClientChangeCustomGamepadActionBindings(const TArray<FFortActionKeyMapping>& Mappings);

	UFUNCTION(Client, Reliable)
	void ClientCheckIfSafeToTurnOnCamera();

	UFUNCTION(Client, Reliable)
	void ClientCreativeTimerDeviceClearRequested(AFortCreativeTimerDevice* TimerDevice);

	UFUNCTION(Client, Reliable)
	void ClientCreativeTimerDeviceUpdateRequested(AFortCreativeTimerDevice* TimerDevice, uint8 CurrentState, float ServerTimeFinished);

	UFUNCTION(Client, Reliable)
	void ClientCycleQuickBarToCreativeItem(const FGuid& CreativeItemGuid, const UFortWorldItemDefinition* CreativeItemDef);

	UFUNCTION(Client, Reliable, WithValidation)
	void ClientDownloadedContentForLinkCodeResult(const FOnlineLinkId& LinkId, bool bSuccess, const FString& ErrorMessage);

	UFUNCTION(Client, Reliable)
	void ClientEnterCameraMode();

	UFUNCTION(Client, Reliable)
	void ClientFadeCameraForScoreScreen();

	UFUNCTION(Client, Reliable)
	void ClientFadeCameraPreMinigameTeleport();

	UFUNCTION(Client, Reliable)
	void ClientFinishTeleportingForMinigame(FRotator Rotation);

	UFUNCTION(Client, Reliable)
	void ClientHideScreenWhileRespawning(const FText& HUDReasonText);

	UFUNCTION(Client, Reliable)
	void ClientMarkSkydivePathsComplete();

	UFUNCTION(Client, Reliable)
	void ClientMutatorEvent(AFortGameplayMutator* Mutator, int32 EventId, int32 PayloadData);

	UFUNCTION(Client, Reliable)
	void ClientNotifyAbortRespawn();

	UFUNCTION(Client, Reliable)
	void ClientNotifyLost(APawn* WinningPawn, EEndOfMatchReason LostReason);

	UFUNCTION(Client, Reliable)
	void ClientNotifyTeamLost();

	UFUNCTION(Client, Reliable)
	void ClientNotifyTeamWon(APawn* FinisherPawn, const UFortWeaponItemDefinition* FinishingWeapon, EDeathCause DeathCause);

	UFUNCTION(Client, Reliable)
	void ClientNotifyWon(APawn* FinisherPawn, const UFortWeaponItemDefinition* FinishingWeapon, EDeathCause DeathCause);

	UFUNCTION(Client, Reliable)
	void ClientOnCreativePlotReported(bool bWasSuccessful, const FOnlineLinkId& LinkId);

	UFUNCTION(Client, Reliable)
	void ClientPreviewScreenshotModeActivated(bool bSuccess, bool bForceQuit);

	UFUNCTION(Client, Reliable)
	void ClientPublishCreativePlotComplete(const FString& ResultErrorCode, const FString& LinkJson);

	UFUNCTION(Client, Unreliable)
	void ClientReceiveSquadQuickChatMessage(FAthenaQuickChatActiveEntry ChatEntry, AFortPlayerController* SenderPC);

	UFUNCTION(Client, Reliable)
	void ClientReportPhaseFound(const FString& Phase);

	UFUNCTION(Client, Reliable)
	void ClientReportTournamentPlacementPointsScored(int32 Placement, int32 PointsEarned);

	UFUNCTION(Client, Reliable)
	void ClientSendDebugPoiLocationTags(const FGameplayTagContainer& InPoiTags);

	UFUNCTION(Client, Reliable)
	void ClientSendDebugPoiVolumeData(const FString& PoiVolumes);

	UFUNCTION(Client, Reliable)
	void ClientSendStateEncryptionKey(const FPlayerStateEncryptionKey& Key);

	UFUNCTION(Client, Reliable)
	void ClientSetDeathReport(FFortPlayerDeathReport InDeathReport);

	UFUNCTION(Client, Reliable)
	void ClientSetStreamingTestStreamingLevels(bool streaming);

	UFUNCTION(Client, Reliable)
	void ClientSignalPortalLoadCompleteViaDelegate(const FAsyncTaskResult& Result);

	UFUNCTION(Client, Reliable)
	void ClientStartRespawnPreparation(FVector RespawnLoc, FRotator RespawnRot, float RespawnCameraDist, FName InRespawnCameraBehavior, const FText& HUDReasonText);

	UFUNCTION(Client, Reliable)
	void ClientStartWaitLTMLoading();

	UFUNCTION(Client, Reliable)
	void ClientStopWaitLTMLoading();

	UFUNCTION(Client, Reliable, WithValidation)
	void ClientSwitchToCreatorCustomController(const FString& ConfigName, const TArray<FFortActionKeyMapping>& Mappings);

	UFUNCTION(Client, Reliable)
	void ClientTeleportToPlaygroundLobbyIsland();

	UFUNCTION(Client, Reliable)
	void ClientTryEndRebootInteraction();

	UFUNCTION(Client, Reliable, WithValidation)
	void ClientUnloadedContentForLinkCodeResult(const FOnlineLinkId& LinkId, bool bSuccess, const FString& ErrorMessage);

	UFUNCTION(Client, Reliable)
	void ClientUpdateDuel(const EDuelState DuelState, const FDuelOverlayData& DuelOverlayData);

	UFUNCTION(Client, Reliable)
	void ClientUpdateGeneratedSkydivePath(const FString& LocationStr, const FVector& DropLocationStr, const FVector& GlideLocationStr, const FVector& LandingLocationStr);

	UFUNCTION(Client, Reliable)
	void ClientVkSessionModeratorLinkCodeReceived(bool bSuccess, const FOnlineLinkId& OnlineLink);

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable)
	void DestroyCreativePlot(const FString& IslandId);

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable)
	void DuplicateCreativePlot(const FString& IslandId, const FString& Locale, const FString& Title);

	UFUNCTION(BlueprintCallable, Category="Team")
	void FollowSpecialActor();

	UFUNCTION(BlueprintPure, Category="Highlights")
	int32 GetCachedHighlightCount();

	UFUNCTION(BlueprintPure)
	AFortVolume* GetCreativePlotLinkedVolume() const;

	UFUNCTION(BlueprintPure)
	UCreativeUserContentManager* GetCreativeUserContentManager() const;

	UFUNCTION(BlueprintImplementableEvent)
	float GetCurrentBuildingCostModifier();

	UFUNCTION(BlueprintImplementableEvent)
	float GetCurrentBuildingSpeedModifier();

	UFUNCTION(BlueprintPure, Category="Creative")
	EFortVolumeType GetCurrentExperienceType() const;

	UFUNCTION(BlueprintPure)
	AFortVolume* GetCurrentVolumeOrCreativePlotLinkedVolume() const;

	UFUNCTION(BlueprintPure)
	AFortGameStateAthena* GetGameStateAthena() const;

	UFUNCTION(BlueprintPure)
	bool GetIgnoreSpectatorViewRotation() const;

	UFUNCTION(BlueprintPure)
	int32 GetInventorySpace() const;

	UFUNCTION(BlueprintPure)
	bool GetIsSpectating() const;

	UFUNCTION(BlueprintCallable, Category="Report")
	UAthenaPlayerMatchReport* GetMatchReport();

	UFUNCTION(BlueprintPure)
	int32 GetMaxNumberOfPlots();

	UFUNCTION(BlueprintPure)
	int32 GetOverflowCountIfItemWasAddedToInventory(const FFortItemEntry& ItemEntry) const;

	UFUNCTION(BlueprintPure)
	AFortAthenaPartyRiftPortal* GetPartyRiftPortal() const;

	UFUNCTION(BlueprintPure)
	const FText& GetPlaylistGameTypeText() const;

	UFUNCTION(BlueprintPure, Category="Creative")
	UFortPlaysetItemDefinition* GetPlayset() const;

	UFUNCTION(BlueprintPure, Category="Creative")
	void GetPlaysetSize(int32& SizeX, int32& SizeY, int32& SizeZ) const;

	UFUNCTION(BlueprintPure)
	int32 GetProfilePlotEntries(bool bIncludeDeleted);

	UFUNCTION(BlueprintPure, Category="Team")
	void GetSquadKills(TArray<int32>& Kills) const;

	UFUNCTION(BlueprintPure, Category="Team")
	int32 GetSquadKillsCount() const;

	UFUNCTION(BlueprintPure, Category="Team")
	TArray<AFortPlayerStateAthena*> GetSquadMemberPlayerStates(const bool bIncludeSelf = true) const;

	UFUNCTION(BlueprintPure)
	void GetTrackedVictims(AFortPlayerStateAthena*& EliminatedVictim, AFortPlayerStateAthena*& DownedVictim) const;

	UFUNCTION(BlueprintPure)
	UFortControllerComponent_TransientQuests* GetTransientQuestsComponent() const;

	UFUNCTION(BlueprintPure, Category="Inventory")
	bool HasItems(const TArray<EFortItemType>& ExcludedItemTypes) const;

	UFUNCTION(BlueprintPure)
	bool HasPartyRiftPortal() const;

	UFUNCTION(BlueprintPure, Category="Creative")
	bool HasPendingMinigameSpawnData() const;

	UFUNCTION()
	void HighlightNumberReturned(int32 NumHighlights);

	UFUNCTION(BlueprintPure, Category="Victory")
	bool IsClientNotifiedOfLoss() const;

	UFUNCTION(BlueprintPure, Category="Victory")
	bool IsClientNotifiedOfTeamWin() const;

	UFUNCTION(BlueprintPure, Category="Victory")
	bool IsClientNotifiedOfWin() const;

	UFUNCTION(BlueprintPure, Category="Creative")
	bool IsInPublicMatchmadeCreativeMinigame() const;

	UFUNCTION(BlueprintCallable)
	bool IsLoadingScreenActive();

	UFUNCTION(BlueprintPure)
	bool IsMatchmaking() const;

	UFUNCTION(BlueprintPure)
	bool IsOnPublishedIsland() const;

	UFUNCTION(BlueprintPure)
	bool IsPartyMemberReadyCheckStatusInProgress() const;

	UFUNCTION(BlueprintPure)
	bool IsPiPFullScreen() const;

	UFUNCTION(BlueprintPure, Category="Creative")
	bool IsPlayerInAMinigame() const;

	UFUNCTION(BlueprintPure, Category="Creative")
	bool IsPlayerInAVolumeTheyCanCreateIn() const;

	UFUNCTION(BlueprintPure, Category="Creative")
	bool IsPlayerInFeaturedExperience() const;

	UFUNCTION(BlueprintPure, Category="Creative")
	bool IsPlayerInPublishedExperience() const;

	UFUNCTION(BlueprintPure, Category="Creative")
	bool IsPlayerInReadOnlyExperience() const;

	UFUNCTION(BlueprintPure, Category="Resurrection")
	bool IsPlayerRebootingNow() const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly)
	bool IsTeleportingToLobby() const;

	UFUNCTION(BlueprintPure, Category="WeaponCooldownMeta")
	bool IsTryToFireRestrictedByTypeCooldowns() const;

	UFUNCTION(BlueprintPure)
	bool IsUnderPlotLimit(int32& MaxIslands, int32& NumIslands, bool bIncludeDeleted);

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable)
	void MakeNewCreativePlot(const UFortCreativeRealEstatePlotItemDefinition* PlotType, const FString& Locale, const FString& Title);

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable)
	void MakeNewCreativePlotFromLinkCode(const FString& LinkCode, const FString& Locale, const FString& Title);

	UFUNCTION()
	void MultiKillExpired();

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable)
	void NotifyCinematicCameraSkipped();

	UFUNCTION()
	void OnFortPlayerPawnAthenaDied(AFortPlayerPawnAthena* FortPlayerPawnAthena);

	UFUNCTION()
	void OnMatchmakingPartyReady() const;

	UFUNCTION()
	void OnMinigameEnded();

	UFUNCTION()
	void OnMinigameStarted();

	UFUNCTION(Server, Reliable, WithValidation)
	void OnPostGameForced();

	UFUNCTION()
	void OnRep_FocalPoint();

	UFUNCTION()
	void OnRep_SkydiveLeader();

	UFUNCTION()
	void OnRep_TrackedVictimsShared();

	UFUNCTION()
	void OnServerMarkerAdded(const FFortWorldMarkerData& MarkerData);

	UFUNCTION(BlueprintCallable)
	void PartyLeaderReadyUpOrStartMatchmaking(const FOnlineLinkId& LinkId, bool& bOutDidStartMatchmakingImmediately, const bool bIsPrivateMatch = false);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void PlayVictoryStinger(USoundCue* VictoryStingerCue);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void PlayWinEffects(APawn* FinisherPawn, const UFortWeaponItemDefinition* FinishingWeapon, EDeathCause DeathCause, bool bAudioOnly, const ERoundVictoryAnimation VictoryAnimation = ERoundVictoryAnimation::Default);

	UFUNCTION()
	void PostLobbyIslandTeleport(AFortPlayerPawn* PlayerPawn);

	UFUNCTION()
	void PreLobbyIslandTeleport();

	UFUNCTION()
	void PrepareClientForRespawning();

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable)
	void PublishCreativePlot(AFortVolume* VolumeToPublish, FCreativePublishOptions MyPublishOptions);

	UFUNCTION(BlueprintCallable)
	void ReduceDroppableResources(const float ReductionPercentage);

	UFUNCTION(BlueprintCallable)
	void RemoveAllInventoryItems();

	UFUNCTION(BlueprintCallable)
	void RemoveDroppableItems();

	UFUNCTION(BlueprintCallable)
	void RemoveDroppableTaggedItems(const FGameplayTagContainer GameplayTagContainer);

	UFUNCTION(Server, Reliable, WithValidation)
	void ReportCreativePlot(const FString& PrivateIslandOwnerID, const FString& PlotInstanceId);

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable)
	void RequestFocalPoint(AActor* InFocalPoint, FVector InFocalPointOffset, float InFocalPointFOV);

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable)
	void ResetMyCurrentCreativePlot();

	UFUNCTION(BlueprintCallable)
	void RespawnPlayerAfterDeath(bool bEnterSkydiving = true);

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable)
	void RestoreCreativePlot(const FString& IslandId);

	UFUNCTION(BlueprintImplementableEvent)
	void RevokeCreativeTool();

	UFUNCTION(Server, Reliable, WithValidation)
	void SendClientPhysicsBallStateToServer(AFortPhysicsPawnObject* PhysicsObject, const float ClientPing, const FTimeStampedPhysicsPawnState ClientBallState);

	UFUNCTION(Server, Reliable, WithValidation)
	void SendPhysicsBallHitToServer(AFortPhysicsPawnObject* PhysicsObject, const float ClientPing, APawn* HittingPawn, const FVector VelocityOfHitter, const FVector HitNormal, const FTimeStampedPhysicsPawnState ClientBallState);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerAddDownloadOnDemandContent(const FOnlineLinkId& LinkId);

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable, Category="Creative")
	void ServerAddToCachedPurchased(UFortItemDefinition* ItemDefinition, int32 Count);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerAlertForceOthersOffIsland();

	UFUNCTION(Server, Reliable, WithValidation, Category="UserPreviewCamera")
	void ServerBeginEndPreview(bool bInBegin);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerBroadcastDeviceButtonComponentClickedDelegate(const UFortCreativeDeviceButtonComponent* DeviceButtonComponent);

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable, Category="Creative")
	void ServerClaimPortal();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerClearSkydiveLeader();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerClientIsReadyToRespawn();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerCreateProfileGoCollectionForSublevels(const FString& SublevelSearchString, int32 GridStepsX, int32 GridStepsY, int32 RotationSteps, int32 Quad);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerCreativeCreateNewLevelInstance();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerCreativeDeleteLevelInstance(const FGuid LevelInstanceGuid);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerCreativeRenameLevelInstance(const FGuid LevelInstanceGuid, const FString& NewLevelName);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerCreativeUnlockItemCategory(const FString& ItemCategory, const FString& ItemSubcategory);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerDBNOReviveInterrupted(AFortPlayerPawnAthena* DBNOPawn);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerDownloadContentByLinkId(const FOnlineLinkId& LinkId, const bool bStripProjectId);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerEndLoadingVolume(AActor* VolumeToLoad);

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable, Category="Creative")
	void ServerEndMinigame(bool bAbandon);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerEndUnloadingVolume(AActor* VolumeToUnload);

	UFUNCTION(Server, Reliable)
	void ServerEnteredCameraMode();

	UFUNCTION(Server, Reliable)
	void ServerEnteredCursorMode();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerGenerateMockMatchReport();

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable, Category="Creative")
	void ServerGiveCreativeItem(const FFortItemEntry& CreativeItem, const FGuid& ItemToRemoveGuid);

	UFUNCTION(Server, Reliable)
	void ServerInsertExtraStreamingTestSkydiveStates();

	UFUNCTION(Server, Reliable)
	void ServerInvalidateRespawnOnWaitingForLevelStreamingFailed();

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable, Category="Creative")
	void ServerLoadIslandCheckpoint(AFortAthenaCreativePortal* Portal);

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable, Category="Creative")
	void ServerLoadPlotForPortal(AFortAthenaCreativePortal* Portal, const FString& PlotItemId);

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable, Category="Creative")
	void ServerLoadPlotForPortalFromMnemonic(AFortAthenaCreativePortal* Portal, const FOnlineLinkId& LinkId);

	UFUNCTION(Server, Reliable)
	void ServerLookedAtFocalPoint();

	UFUNCTION(Server, Reliable)
	void ServerMarkSkydiveLocationsComplete();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerNotifyOstrichSelfDestruct();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerNotifyOstrichShieldOvercharge();

	UFUNCTION(Server, Unreliable, WithValidation)
	void ServerPlaySquadQuickChatMessage(FAthenaQuickChatActiveEntry ChatEntry, FUniqueNetIdRepl SenderID);

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable, Category="Creative")
	void ServerReleasePortal();

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable)
	void ServerReloadCreativePlot();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerRemoveDownloadOnDemandContent(const FOnlineLinkId& LinkId);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerRequestNewSkydiveLeader();

	UFUNCTION(Server, Reliable, BlueprintCallable)
	void ServerRequestObjectTrackingDetails(const AFortVolume* Volume);

	UFUNCTION(Server, Reliable)
	void ServerRequestVkSessionModeratorLinkCode();

	UFUNCTION(Server, Reliable, WithValidation, Category="UserPreviewCamera")
	void ServerResetCameraPreviewToDefaultLocation();

	UFUNCTION(Server, Reliable)
	void ServerResetCurrentVolumeWithoutTeleport();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerRespondToAbandonMatch(bool bAbandon);

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable, Category="Creative")
	void ServerRestartMinigame();

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable, Category="Creative")
	void ServerSaveIslandCheckpoint(AFortAthenaCreativePortal* Portal);

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable, Category="UI")
	void ServerSelectMutatorItem(AFortGameplayMutator* Mutator, int32 ItemIndex, int32 PayloadData = -1);

	UFUNCTION(Server, Reliable)
	void ServerSetCosmeticAndRefresh(const FFortAthenaLoadout& Loadout);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category="Creative")
	void ServerSetMinigameClassSlot(uint8 InClassSlotIndex);

	UFUNCTION(Server, Reliable, WithValidation, Category="Creative")
	void ServerSetMinigameTeamAndClassSlot(const uint8 InTeam, const uint8 InClassSlotIndex, const bool bDeferred);

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable, Category="Creative")
	void ServerSetModeratorTeam(uint8 InTeam);

	UFUNCTION(Server, Reliable)
	void ServerSetOnCreativePortalLoadedDelegate(int32 PortalIndex);

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable, Category="Creative")
	void ServerSetPlayset(UFortPlaysetItemDefinition* NewPlayset);

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable)
	void ServerSetReceiveEmailSignups(bool bSignUp);

	UFUNCTION()
	void ServerSetRespawnData(FVector RespawnLoc, FRotator RespawnRot, float RespawnCameraDist);

	UFUNCTION(Server, Reliable)
	void ServerSetStreamingTestStreamingLevels(bool streaming);

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable, Category="Creative")
	void ServerSetTeam(uint8 InTeam);

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable, Category="Creative")
	void ServerSpawnCreativeSupplyDrop(TSubclassOf<AActor> InSupplyDropClass);

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable, Category="Creative")
	void ServerSpawnPickup(const FFortItemEntry& CreativeItem);

	UFUNCTION(Server, Reliable, BlueprintCallable)
	void ServerStartInteractWithIslandPortal(AFortAthenaCreativePortal* Portal);

	UFUNCTION(Server, Reliable, BlueprintCallable)
	void ServerStartInteractWithPartyRiftPortal(AFortAthenaPartyRiftPortal* Portal, const FString& Reason);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerStartLoadingVolume(AActor* VolumeToLoad);

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable, Category="Creative")
	void ServerStartMinigame();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerStartUnloadingVolume(AActor* VolumeToUnload);

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable)
	void ServerStopSavingCreativePlot();

	UFUNCTION(Server, Reliable)
	void ServerStopWaitLTMLoading();

	UFUNCTION(Server, Reliable)
	void ServerTeleportToMapMarker();

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable)
	void ServerTeleportToPlaygroundIslandDock();

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable)
	void ServerTeleportToPlaygroundLobbyIsland();

	UFUNCTION(Server, Reliable)
	void ServerTeleportViaCreativePortal(int32 PortalIndex);

	UFUNCTION(Server, Unreliable, WithValidation)
	void ServerThankBusDriver();

	UFUNCTION(Server, Unreliable, WithValidation)
	void ServerThankBusDriverCheck();

	UFUNCTION(Server, Reliable)
	void ServerTickForDoneTeleporting(AFortAthenaCreativePortal* Portal);

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable, Category="Creative")
	void ServerToggleAutoRestartMinigame();

	UFUNCTION(Server, Reliable)
	void ServerTryFindPlotItemForDefinition(UFortCreativeRealEstatePlotItemDefinition* PlotDefinition);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerUnloadDownloadedContentByLinkId(const FOnlineLinkId& LinkId);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerUpdateCreativePlotData(AFortVolume* VolumeToPublish, FCreativeIslandInfo MyInfo);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerUpdateCreativePlotName(const FString& IslandId, const FString& Locale, const FString& Title);

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable)
	void ServerUpdateHeatmapBoundsForCurrentVolume();

	UFUNCTION(Server, Unreliable)
	void ServerUpdatePrimaryQuickBarSlots(const FQuickBarEquippedItemGuids& SlotItemGuids);

	UFUNCTION(Server, Reliable)
	void ServerUpdateSkydiveLocation(const FString& LocationStr, const FVector& Location);

	UFUNCTION(Server, Reliable, WithValidation, Category="UserPreviewCamera")
	void ServerUpdateUserCameraPreview();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetFocalPoint(AActor* InFocalPoint, FVector InFocalPointOffset, float InFocalPointFOV, float InInterpSpeed = 5.000000f);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetFocalPointWithDuration(AActor* InFocalPoint, FVector InFocalPointOffset, float InFocalPointFOV, float InDuration, float InInterpSpeed = 5.000000f);

	UFUNCTION(BlueprintCallable)
	void SetIgnoreSpectatorViewRotation(const bool bNewValue);

	UFUNCTION(BlueprintCallable)
	void SetOverrideDesiredRotation(const FRotator& NewDesiredRotation);

	UFUNCTION()
	void SetupClientRespawnTimerAndLocation(FVector RespawnLoc, FRotator RespawnRot, FVector OldPlayerLocation, bool bCalculateRespawnData, bool bAllowCreativeOverride);

	UFUNCTION(BlueprintCallable)
	void SetUseOverrideDesiredRotation(const bool bNewUseDesiredRotation, const float NewDuration = 1.000000f);

	UFUNCTION(BlueprintCallable, Category="Highlights")
	void ShowHighlightSummary();

	UFUNCTION(BlueprintCallable)
	void StartMatchmakingByLinkCode(const FOnlineLinkId& LinkCode, bool bIsPrivateMatch = false);

	UFUNCTION()
	void StartRespawnLoading();

	UFUNCTION()
	void StopRecordingHighlights();

	UFUNCTION(BlueprintCallable)
	void TeleportToPlaygroundLobbyIsland();

	UFUNCTION(Server, Reliable, WithValidation)
	void TellServer_ClientReceivedPlaysetDataForVolume(FFortPlaysetStreamingData PlaysetData, AActor* Volume);

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable)
	void UpdateCreativeIslandDescriptionTags(const FString& IslandId, const FString& Locale, const TArray<FString>& DescriptionTags);

	UFUNCTION(BlueprintCallable)
	void UpdateCreativePlotData(AFortVolume* VolumeToPublish, FCreativeIslandInfo MyInfo);

	UFUNCTION(BlueprintCallable)
	void UpdateCreativePlotName(const FString& IslandId, const FString& Locale, const FString& Title);

	UFUNCTION(BlueprintCallable)
	void UpdateDuel(const EDuelState DuelState, const FDuelOverlayData& DuelOverlayData);

	UFUNCTION(Server, Reliable, WithValidation)
	void UpdateUGCRestrictedForVolume(AFortVolume* Volume, bool bRestricted);

	UPROPERTY(Config)
	float FireAbilityToWeaponSwitchTime;

	UPROPERTY(BlueprintAssignable)
	FOnAircraftStateChange OnAircraftStateChange;

	UPROPERTY(Transient)
	TObjectPtr<UFortWorldItemDefinition> SwappingItemDefinition;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortPlayerControllerAthena")
	float WinScreenDelayTime;

	UPROPERTY(Config)
	bool bSkipPlayWinEffects;

	UPROPERTY(Config)
	bool bAllowPlayersCreditOnLeave;

	UPROPERTY(BlueprintReadOnly, Category="FortPlayerControllerAthena")
	bool bLockingOnFocalPoint;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_FocalPoint)
	TObjectPtr<AActor> FocalPoint;

	UPROPERTY(Transient, Replicated)
	FVector_NetQuantize FocalPointOffset;

	UPROPERTY(Transient, Replicated)
	float FocalPointFOV;

	UPROPERTY(Transient)
	float FocalPointDuration;

	UPROPERTY(BlueprintAssignable, Category="Athena")
	FOnUsingFocalPointChanged OnUsingFocalPointChanged;

	UPROPERTY(BlueprintAssignable, Category="Athena")
	FOnFocalPointActorChanged OnFocalPointActorChanged;

	UPROPERTY(BlueprintAssignable, Category="Athena")
	FOnCinematicCameraSkipped OnCinematicCameraSkipped;

	UPROPERTY(BlueprintAssignable, Category="Athena")
	FOnSkydiveLeaderChanged OnSkydiveLeaderChanged;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnClientDonationSuccessDelegate OnClientDonationSuccessDelegate;

	UPROPERTY(Transient)
	float SkydiveLeaderManualCameraTime;

	UPROPERTY(Transient)
	FRotator InterpolatedSkydiveFollowerViewRotation;

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_SkydiveLeader, Category="FortPlayerControllerAthena")
	TObjectPtr<AFortPlayerState> SkydiveLeader;

	UPROPERTY(BlueprintAssignable)
	FFortPlayerControllerAthenaOnPickupProjectileCreated OnPickupProjectileCreatedDelegate;

	UPROPERTY(ReplicatedUsing=OnRep_TrackedVictimsShared)
	TObjectPtr<AFortPlayerStateAthena> LastDownedVictim;

	UPROPERTY(ReplicatedUsing=OnRep_TrackedVictimsShared)
	TObjectPtr<AFortPlayerStateAthena> LastElimVictim;

	UPROPERTY(BlueprintAssignable)
	FOnCameraInStormWallChange OnCameraInStormWallChangeDelegate;

	UPROPERTY(Config)
	bool bLeaveDisconnectedPawnsInGame;

	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerPawn> DisconnectedPawn;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Voice")
	TArray<FString> PlayersTalking;

	UPROPERTY(BlueprintAssignable)
	FOnTalkingPlayersChanged TalkingPlayersChanged;

	UPROPERTY(Transient)
	bool bHighlightRecordingEnabled;

	UPROPERTY(Transient)
	bool bPlaceDangerMarkerWhenTargeting;

	UPROPERTY(Transient)
	bool bDeferringStartRecordingHighlights;

	UPROPERTY(Transient)
	FString HighlightGroupId;

	UPROPERTY(Transient)
	int32 CachedHighlightCount;

	UPROPERTY(Transient)
	float HighlightFirstKillTime;

	UPROPERTY(Transient)
	int32 HighlightKillMultiple;

	UPROPERTY(Transient)
	int32 HighlightDownMultiple;

	UPROPERTY(Config)
	float HighlightKillCooldown;

	UPROPERTY(Config)
	float HighlightKillRewindTime;

	UPROPERTY(Config)
	float CabinModeCheckTimeInterval;

	UPROPERTY(Config)
	float CabinModeRestartTimeInterval;

	UPROPERTY(EditDefaultsOnly, Category="Respawning|Timing")
	float RespawnCamera_Time;

	UPROPERTY(EditDefaultsOnly, Category="Respawning|Timing")
	float RespawnCamera_HoldPositionTime;

	UPROPERTY(EditDefaultsOnly, Category="Respawning|Offsets")
	FVector RespawnCamera_InitialLocOffset_InAir;

	UPROPERTY(EditDefaultsOnly, Category="Respawning|Offsets")
	FVector RespawnCamera_InitialLocOffset_OnGround;

	UPROPERTY(EditDefaultsOnly, Category="Respawning|Offsets")
	FRotator RespawnCamera_InitialRotOffset_InAir;

	UPROPERTY(EditDefaultsOnly, Category="Respawning|Offsets")
	FRotator RespawnCamera_InitialRotOffset_OnGround;

	UPROPERTY(EditDefaultsOnly, Category="Respawning|Offsets")
	float RespawnCamera_OffsetFromHit;

	UPROPERTY(Replicated)
	bool bNextRespawnInAir;

	UPROPERTY(Transient)
	FName RespawnCameraBehavior;

	UPROPERTY(Config)
	int32 MaximumNumberOfPawnsToSearchForEmoteMusic;

	UPROPERTY(Config)
	float PickupSwapHoldTime;

	UPROPERTY(Config)
	bool bUseNewPickupSwapLogic;

	UPROPERTY(Config)
	float SpectatorLevelStreamDistance;

	UPROPERTY(Config)
	float RespawnLevelStreamDistance;

	UPROPERTY(BlueprintAssignable)
	FOnSpectatorStreaming SpectatorStreamingChanged;

	UPROPERTY(BlueprintAssignable)
	FOnInGameLoadScreenChanged InGameLoadScreenChanged;

	UPROPERTY(BlueprintReadWrite, BlueprintAssignable, Category="FortPlayerControllerAthena")
	FOnLocalPlayerChangedTeams OnLocalPlayerChangedTeams;

	UPROPERTY(BlueprintAssignable)
	FOnCreativePlotLinkedVolumeChanged OnCreativePlotLinkedVolumeChanged;

	UPROPERTY(BlueprintAssignable)
	FOnCreativePermissionsChanged OnCreativePermissionsChanged;

	UPROPERTY(BlueprintAssignable)
	FOnCreativeContentFilterChanged OnCreativeContentFilterChanged;

	UPROPERTY(BlueprintAssignable)
	FOnPlayerPawnEvent OnClientLeaveIsland;

	UPROPERTY(BlueprintAssignable)
	FOnPlayerForcedOffIslandEvent OnClientForcedOffIsland;

	UPROPERTY(BlueprintAssignable)
	FOnMCPIslandRequestFinished OnMakeNewCreativePlotFinished;

	UPROPERTY(BlueprintAssignable)
	FOnMCPIslandRequestFinished OnDestroyCreativePlotFinished;

	UPROPERTY(BlueprintAssignable)
	FOnMCPIslandRequestFinished OnRestoreCreativePlotFinished;

	UPROPERTY(BlueprintAssignable)
	FOnMCPIslandRequestFinished OnDuplicateCreativePlotFinished;

	UPROPERTY(BlueprintAssignable)
	FOnIslandEntriesChanged OnIslandEntriesChanged;

	UPROPERTY(BlueprintAssignable)
	FOnMCPIslandRequestFinished OnUpdateCreativePlotName;

	UPROPERTY(BlueprintAssignable)
	FOnMCPIslandRequestFinished OnUpdateCreativeDescriptionTags;

	UPROPERTY()
	TObjectPtr<ACameraActor> RespawnCameraActor;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerControllerAthena")
	bool bDelayedTeleporting;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortPlayerControllerAthena")
	bool bBlockTeleporting;

	UPROPERTY(BlueprintAssignable)
	FOnInGameMatchmakingStarted InGameMatchmakingReadyCheckStarted;

	UPROPERTY(BlueprintAssignable)
	FOnInGameMatchmakingReadyCheckComplete InGameMatchmakingReadyCheckComplete;

	UPROPERTY(BlueprintAssignable)
	FOnInGameMatchmakingReadyCheckComplete InGameMatchmakingReadyCheckCanceled;

	UPROPERTY(BlueprintAssignable)
	FOnInGameMatchmakingStarted InGameMatchmakingStarted;

	UPROPERTY(BlueprintAssignable)
	FOnInGameMatchmakingComplete InGameMatchmakingComplete;

	UPROPERTY(BlueprintAssignable)
	FOnInGameMatchmakingStateChanged InGameMatchmakingStateChanged;

	UPROPERTY(BlueprintAssignable)
	FOnInGameMatchmakingQueuedStatusUpdated InGameMatchmakingQueuedStatusUpdated;

	UPROPERTY(BlueprintAssignable)
	FOnInGameMatchmakingError InGameMatchmakingError;

	UPROPERTY(BlueprintAssignable)
	FOnInGameMatchmakingCanceled OnInGameMatchmakingCanceled;

	UPROPERTY(BlueprintAssignable)
	FOnInGamematchmakingUpdateCheckFailed OnInGameMatchmakingUpdateCheckFailed;

	UPROPERTY(BlueprintAssignable)
	FOnInGameContentDownloadStarted OnInGameContentDownloadStarted;

	UPROPERTY(BlueprintAssignable)
	FOnInGameMatchmakingUtilityStateChanged OnInGameMatchmakingUtilityStateChanged;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortPlayerControllerAthena")
	bool bNoInGameMatchmaking;

	UPROPERTY(EditDefaultsOnly, Category="Sounds")
	TObjectPtr<USoundBase> AudioOnExitAircraft;

	UPROPERTY(EditDefaultsOnly, Category="Sounds")
	TObjectPtr<USoundBase> AudioOnExitAircraftHornDoppler;

	UPROPERTY()
	float MinQuickChatCooldown;

	UPROPERTY()
	float QuickChatOffCooldownTime;

	UPROPERTY(Replicated)
	bool bMarkedAlive;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_CreativeIslands, Category="FortPlayerControllerAthena")
	TArray<FCreativeIslandData> CreativeIslands;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="FortPlayerControllerAthena")
	bool bIsAllowedToPublish;

	UPROPERTY(EditDefaultsOnly, Category="Input")
	TSoftObjectPtr<UFortGamepadSettings> GamepadSettingsAssetPtr;

	UPROPERTY(BlueprintReadWrite, Category="Team")
	FLinearColor TeamMemberIndicatorColor;

	UPROPERTY(Transient)
	bool bHasSentMatchEndedQuestProgress;

	UPROPERTY(EditAnywhere, Category="QuickBar", meta=(ArraySizeEnum="/Script/FortniteGame.EFortQuickBars"))
	FQuickBarData QuickBarDefinitions[3];

	UPROPERTY(Transient)
	int32 BuildingsCreated;

	UPROPERTY(Transient)
	int32 BuildingsEdited;

	UPROPERTY(Transient)
	int32 BuildingsRepaired;

	UPROPERTY(Transient)
	int32 BuildingsUpgraded;

	UPROPERTY(Transient)
	float BuildingActionDoneLastAtTime;

	UPROPERTY()
	FBuildingStats BuildingMatchStats;

	UPROPERTY(BlueprintAssignable)
	FOnHUDMessageToggled OnHUDMessageToggled;

	UPROPERTY(BlueprintReadWrite, Replicated, Category="Creative")
	TArray<FItemAndCount> CachedPurchasedItems;

	UPROPERTY(Replicated)
	FMinigameSpawnData PendingMinigameSpawnData;

	UPROPERTY(BlueprintAssignable)
	FOnPreviewScreenshotCameraActivated OnPreviewScreenshotCameraActivated;

	UPROPERTY(Config)
	bool bIgnorePlayerInfoAbandonStateForSpecialEventRtmm;

protected:
	UFUNCTION()
	void CheckIfLevelStreamingCompleteForHandshake();

	UFUNCTION()
	void CheckIfSafeToRespawn();

	UFUNCTION(Client, Reliable)
	void ClientAutoEquipFirstItem(FGuid ItemGuid, bool bForceExecution);

	UFUNCTION(Client, Reliable)
	void ClientRequestLevelStreamingHandshake();

	UFUNCTION(Client, Reliable)
	void ClientSendEndBattleRoyaleMatchForPlayer(bool bSuccess, const FAthenaRewardResult& Result);

	UFUNCTION(Client, Reliable)
	void ClientSendEndMatchReportHeartbeat();

	UFUNCTION(Client, Reliable)
	void ClientSendMatchStatsForPlayer(const FAthenaMatchStats& Stats);

	UFUNCTION(Client, Reliable)
	void ClientSendTeamStatsForPlayer(const FAthenaMatchTeamStats& TeamStats);

	UFUNCTION()
	void HandlePlayersLeftChanged(int32 NumPlayersLeft);

	UFUNCTION()
	void QuickWeapon1();

	UFUNCTION()
	void QuickWeapon2();

	UFUNCTION()
	void QuickWeapon3();

	UFUNCTION()
	void QuickWeapon4();

	UFUNCTION()
	void RespawnTurnCameraBackOn();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerEnableAnonymousCharacterMode();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerEnableAnonymousMode();

	UFUNCTION(Server, Reliable)
	void ServerEnableHideOtherPlayersNames();

	UFUNCTION(Server, Reliable)
	void ServerFriendGameMemberAdded(AFortPlayerStateAthena* FriendPSA, bool bIsEpicFriend);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerShowSeasonLevel();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerUpdateLevelStreamingHandshakeData(const bool bClientLevelStreamingState);

	UFUNCTION()
	void UpdateRichPresenceTimer();

	UFUNCTION()
	void WriteCreateBuildingAnalytics();

	UPROPERTY(BlueprintAssignable)
	FOnItemDropSpawned OnItemDropSpawnedDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnItemDroppedDueToOverflow OnItemDroppedDueToOverflow;

	UPROPERTY()
	TObjectPtr<AFortPlayerPawn> PreviousPawn;

	UPROPERTY(Config)
	bool bReplicateViewTargetInventory;

	UPROPERTY(Transient)
	uint8 bHasHadValidPawn : 1;

	UPROPERTY(Transient)
	uint8 bClientNotifiedOfWin : 1;

	UPROPERTY(Transient)
	uint8 bClientNotifiedOfTeamWin : 1;

	UPROPERTY(Transient)
	uint8 bClientNotifiedOfLoss : 1;

	UPROPERTY(Transient)
	uint8 bHideWarmUpLoadingScreen : 1;

	UPROPERTY(Replicated)
	int32 MaxPlotCount;

	UPROPERTY(Transient)
	bool bMatchStatsForPlayerSent;

	UPROPERTY(Transient)
	bool bAddedBookProgressStatsToGamemode;

	UPROPERTY(Config)
	bool bEnableBroadcastRemoteClientInfo;

	UPROPERTY(Replicated)
	TObjectPtr<AFortBroadcastRemoteClientInfo> BroadcastRemoteClientInfo;

	UPROPERTY()
	TObjectPtr<UFortHero> StrongMyHero;

	UPROPERTY(Config)
	float EndMatchHeartbeatTimerDelay;

	UPROPERTY()
	double EndMatchHeartbeatTimestamp;

	UPROPERTY()
	TObjectPtr<AFortPlayerStartWarmup> WarmupPlayerStart;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UInputComponent> FullScreenScoreboardInputComponent;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UInputComponent> CurrentFullscreenInputComponent;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UInputComponent> GameChannelRecommendationInputComponent;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UInputComponent> QuickWeaponInputComponent;

	UPROPERTY(Config, Transient)
	bool bUseTrapPicker;

	UPROPERTY(Config)
	float DoubleTapEditTime;

	UPROPERTY(Transient)
	TObjectPtr<UAthenaPlayerMatchReport> MatchReport;

	UPROPERTY(EditDefaultsOnly, Category="AutoRun")
	bool bBlockMoveInputInMenus;

	UPROPERTY(EditDefaultsOnly, Category="FortPlayerControllerAthena")
	TSubclassOf<UFortMiniMapTeamIndicators> MinimapIndicatorClass;

	UPROPERTY(Config)
	bool bEnableInGameChallengeLocationIndicators;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortPlayerControllerAthena")
	TSubclassOf<AFortPlayerMarkerBase> SquadMarkerActorClass;

	UPROPERTY(Transient)
	TArray<FBuildingEditAnalyticEvent> BuildingAnalyticsArray;

	UPROPERTY(Transient)
	float TimeStartedTrackingBuildingAnalytics;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Creative")
	TObjectPtr<UFortPlaysetItemDefinition> CurrentPlayset;

	UPROPERTY(Config)
	float DestructedBuildingInGridTimeoutOverride;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortPlayerControllerAthena")
	FText ClientRespawnText;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortPlayerControllerAthena")
	FText ClientRebootingText;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortPlayerControllerAthena")
	FText ClientIslandTravelText;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortPlayerControllerAthena")
	FText ClientTravelToCreativeHubText;

	UPROPERTY(VisibleDefaultsOnly, Export, Category="FortPlayerControllerAthena", meta=(EditInline="true"))
	TObjectPtr<UAthenaMarkerComponent> MarkerComponent;

	UPROPERTY(VisibleAnywhere, Export, Category="FortPlayerControllerAthena", meta=(EditInline="true"))
	TObjectPtr<UAthenaResurrectionComponent> ResurrectionComponent;

	UPROPERTY(VisibleAnywhere, Export, Category="FortPlayerControllerAthena", meta=(EditInline="true"))
	TObjectPtr<UFortControllerComponent_SeasonItem> SeasonItemComponent;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortPlayerControllerAthenaXPComponent> XPComponent;

	UPROPERTY(VisibleDefaultsOnly, Export, Category="FortPlayerControllerAthena", meta=(EditInline="true"))
	TObjectPtr<UFortControllerComponent_MapDiscoverability> DiscoverabilityComponent;

	UPROPERTY(VisibleDefaultsOnly, Export, Category="FortPlayerControllerAthena", meta=(EditInline="true"))
	TObjectPtr<UFortControllerComponent_TransientQuests> TransientQuestsComponent;

	UPROPERTY(VisibleDefaultsOnly, Export, Category="FortPlayerControllerAthena", meta=(EditInline="true"))
	TObjectPtr<UFortControllerComponent_SkydiveFeedback> SkydiveFeedback;

	UPROPERTY(VisibleDefaultsOnly, Export, Category="FortPlayerControllerAthena", meta=(EditInline="true"))
	TObjectPtr<UFortControllerComponent_Habanero> HabaneroComponent;

	UPROPERTY(VisibleDefaultsOnly, Export, Category="FortPlayerControllerAthena", meta=(EditInline="true"))
	TObjectPtr<UFortControllerComponent_IndicatedActorManagement> IndicatedActorManagementComponent;

	UPROPERTY(VisibleDefaultsOnly, Export, Category="FortPlayerControllerAthena", meta=(EditInline="true"))
	TObjectPtr<UFortControllerComponent_LocalizationService> LocalizationServiceComponent;

	UPROPERTY(VisibleDefaultsOnly, Export, Category="FortPlayerControllerAthena", meta=(EditInline="true"))
	TObjectPtr<UFortControllerComponent_ToxicityService> ToxicityServiceComponent;

	UPROPERTY(VisibleDefaultsOnly, Export, Category="FortPlayerControllerAthena", meta=(EditInline="true"))
	TObjectPtr<UFortControllerComponent_RechargeWeapons> RechargingWeaponsComponent;

	UPROPERTY(VisibleDefaultsOnly, Export, Category="FortPlayerControllerAthena", meta=(EditInline="true"))
	TObjectPtr<UFortControllerComponent_InventoryService> InventoryServiceComponent;

	UPROPERTY(VisibleDefaultsOnly, Export, Category="FortPlayerControllerAthena", meta=(EditInline="true"))
	TObjectPtr<UFortControllerComponent_RadiusTracker> RadiusTrackerComponent;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortControllerComponent_MinigameActivity> MinigameActivityComponent;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UCreativeAnalyticsComponent> CreativeAnalyticsComponent;

	UPROPERTY(VisibleDefaultsOnly, Export, Category="FortPlayerControllerAthena", meta=(EditInline="true"))
	TObjectPtr<UFortControllerComponent_AthenaQuestsPinner> QuestPinnerComponent;

	UPROPERTY(Replicated, Export, meta=(EditInline="true"))
	TObjectPtr<UCreativeUserContentManager> CreativeUserContentManager;

	UPROPERTY(EditDefaultsOnly, Category="Creative")
	TSoftClassPtr<UCreativeUserContentManager> CreativeUserContentManagerClassSoftClassPtr;

	UPROPERTY(Replicated, Export, meta=(EditInline="true"))
	TObjectPtr<UFortCreativeObjectTrackingComponent> CreativeObjectTrackingComponent;

	UPROPERTY(Replicated, Export, meta=(EditInline="true"))
	TObjectPtr<UFortCreativeEntitlementComponent> CreativeEntitlementComponent;

	UPROPERTY(Transient)
	FQuickBarEquippedItemGuids PrimaryQuickBarSlotItemGuids;

	UPROPERTY(Transient)
	bool bIgnoreSpectatorViewRotation;

private:
	UFUNCTION()
	void EnableCreativeContentManagerBasedOnPlaylist();

	UFUNCTION()
	void OnClientEnterVolume(APlayerState* InPlayerState, AFortVolume* InVolume);

	UFUNCTION()
	void OnClientVolumeManagerReplicated();

	UFUNCTION()
	void OnCreativePlotLinkedVolumeMinigameChanged(AFortMinigame* Minigame);

	UFUNCTION()
	void OnRep_CreativeIslands();

	UFUNCTION()
	void OnRep_CreativePlotLinkedVolume();

	UFUNCTION()
	void RecordContentDownloadModules();

	UFUNCTION()
	void RecordMatchStats();

	UFUNCTION()
	void RecordTeamStats();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerNotifyClientReachedMaxWaitingTimeForDeviceReplication();

	UFUNCTION(Server, Reliable)
	void ServerSetCosmeticLoadout(const FFortAthenaLoadout& Loadoutbool, bool bRefreshPawn);

	UPROPERTY(Transient)
	FLevelStreamRequestHandshakeState LevelStreamRequestHandshakeState;

	UPROPERTY(Transient)
	TArray<TWeakObjectPtr<UObject>> ClientGameWorldHolds;

	UPROPERTY(Transient)
	int32 UnprocessedXp;

	UPROPERTY(Transient)
	float XpReceivedLastAtTime;

	UPROPERTY(ReplicatedUsing=OnRep_CreativePlotLinkedVolume)
	TObjectPtr<AFortVolume> CreativePlotLinkedVolume;

	UPROPERTY(Transient)
	FCreativePlotSessionData CreativePlotSessionData;

	UPROPERTY(Replicated)
	TObjectPtr<AFortAthenaCreativePortal> OwnedPortal;

	UPROPERTY(Replicated)
	TObjectPtr<AFortAthenaPartyRiftPortal> OwnedPartyRiftPortal;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AActor>> VolumesLoading;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AActor>> VolumesUnloading;

	UPROPERTY(EditDefaultsOnly, Category="Perception", meta=(ClampMin="0.0", UIMin="0.0"))
	FScalableFloat SightWeatherCapRadius;

	UPROPERTY()
	double TimeSinceLastCreativeSpawn;

};

