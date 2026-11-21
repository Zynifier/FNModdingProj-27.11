// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CineCameraSettings.h"
#include "GameFramework/OnlineReplStructs.h"
#include "Math/MathFwd.h"
#include "Items/FortQuickBars.h"
#include "Player/FortPlayerControllerGameplay.h"
#include "Replay/FortReplayContext.h"
#include "Replay/FortReplayTypes.h"
#include "Spectator/FortSpectateGameplayBlend.h"
#include "FortPlayerControllerSpectating.generated.h"

class AActor;
class ABattleMapPawnReplay;
class AFortBroadcastRemoteClientInfo;
class AFortPlayerControllerSpectating;
class AFortPlayerState;
class AFortPlayerStateAthena;
class AFortRelevancyZoneIndicator;
class AFortReplaySpectatorPawnBase;
class AFortSpectatorPlayerHighlighter;
class AFortSpectatorThirdPersonPawn;
class AHoverDronePawn;
class APlayerState;
class AVolume;
class UAthenaMarkerComponent;
class UAthenaPlayerMatchReport;
class UFortMiniMapTeamIndicators;
class UFortReplayContext;
class UFortSpectatorCameraComponent;
class UMaterialInterface;
class UWorld;
enum class EFortSpectatorBlendType : uint8;
enum class EPlayEventType : int32;
enum class ESpectateBlendEasing : uint8;
enum class ESpectatorCameraType : uint8;
enum class ESpectatorSquadIdMode : uint8;

UENUM()
enum class ECameraShotNotificationTypes : uint8
{
	Notification = 0,
	HighlightAnnotation = 1,
	TitleScreen = 2,
};

UENUM()
enum class ECameraStateRestoreReason : uint8
{
	Unknown = 0,
	ChangedFollowTarget = 1,
	ChangedCameraType = 2,
	InvokedHotKey = 3,
	Scrubbed = 4,
	Restored = 5,
	SpecialAction = 6,
	MAX = 7,
};

UENUM(BlueprintType)
enum class EHighlightReelTypes : uint8
{
	Generic = 0,
	GameSummary = 1,
	ExtendedGameSummary = 2,
	Builder = 3,
	FastMover = 4,
	LongDistance = 5,
	Multikill = 6,
	StormCloud = 7,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCameraTypeChanged, AFortPlayerControllerSpectating*, SpectatorPC, ESpectatorCameraType, NewCameraType);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnFollowedPlayerChanged, AFortPlayerControllerSpectating*, SpectatorPC, AFortPlayerState*, NewFollowedPlayer);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayerBecameIrrelevant, AFortPlayerState*, NewlyIrrelevantPlayer);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayerBecameRelevant, AFortPlayerState*, NewlyRelevantPlayer);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayerDied, AFortPlayerState*, NewlyDeadPlayer);

USTRUCT(BlueprintType)
struct FNotificationUISettings
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="NotificationUISettings")
	float DisplayTime;

	UPROPERTY(BlueprintReadOnly, Category="NotificationUISettings")
	bool bShouldOverrideVisibilitySettings;

};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnShowNotification, const FText&, NotificationText, const FNotificationUISettings&, NotificationSettings);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnShowNotificationsEnabledChanged, bool, bShouldShowNotifications);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPlayerStateAthenaDelegate, AFortPlayerStateAthena*, FPSA);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSpectatorDelegate);

USTRUCT(BlueprintType)
struct FHighlightReel
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 TotalDurationSeconds;

	UPROPERTY()
	FText Description;

	UPROPERTY()
	EHighlightReelTypes HighlightType;

};

USTRUCT()
struct FNamePlateFilter
{
	GENERATED_BODY()

private:
	UPROPERTY()
	bool bIsSet;

	UPROPERTY()
	TSet<FUniqueNetIdRepl> NamePlatesToShow;

};

USTRUCT()
struct FRemoteViewRotSnapshot
{
	GENERATED_BODY()

};

USTRUCT()
struct FRemoteViewRotSnapshotManager
{
	GENERATED_BODY()

public:
	UPROPERTY(Config)
	int32 BufferSize;

	UPROPERTY(Config)
	float TimeDelay;

	UPROPERTY(Config)
	bool bUseVariableTimeDelay;

	UPROPERTY(Config)
	float VariableTimeDelayMultiplier;

	UPROPERTY(Config)
	float TimeBeforeDormant;

	UPROPERTY(Config)
	float InterpSpeedWhenNoSample;

};

USTRUCT()
struct FSavedSpectatorCameraState
{
	GENERATED_BODY()

public:
	UPROPERTY()
	bool bDataIsValid;

	UPROPERTY()
	ESpectatorCameraType CameraType;

	UPROPERTY()
	FUniqueNetIdRepl FollowedPlayerUniqueId;

	UPROPERTY()
	FCameraFilmbackSettings FilmbackSettings;

	UPROPERTY()
	FCameraLensSettings LensSettings;

	UPROPERTY()
	FCameraFocusSettings FocusSettings;

	UPROPERTY()
	float CurrentFocalLength;

	UPROPERTY()
	float CurrentAperture;

	UPROPERTY()
	bool bAutoFocus;

	UPROPERTY()
	float CurrentFocusDistance;

	UPROPERTY()
	bool bAutoExposure;

	UPROPERTY()
	float ManualExposureBias;

	UPROPERTY()
	FTransform Transform;

	UPROPERTY()
	FRotator ControlRotation;

	UPROPERTY()
	float ThirdPersonNormalizedDistance;

	UPROPERTY()
	EThirdPersonAutoFollowMode ThirdPersonAutoFollowMode;

	UPROPERTY()
	float DroneSpeedIndex;

	UPROPERTY()
	float ReplayPlaybackSpeed;

	UPROPERTY()
	bool bNamePlatesEnabled;

	UPROPERTY()
	bool bDisplaySessionRank;

	UPROPERTY()
	bool bPlayerOutlinesEnabled;

	UPROPERTY()
	bool bThirdPersonCamCollide;

	UPROPERTY()
	bool bFollowDroneDoTest;

	UPROPERTY()
	bool bBattleMapIsOnTimelineMode;

	UPROPERTY()
	FNamePlateFilter NamePlatesFilter;

};

USTRUCT()
struct FSavedPlayerSpectatorCameraData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TMap<FUniqueNetIdRepl, FSavedSpectatorCameraState> PlayerToCameraStateMap;

};

USTRUCT()
struct FSavedSpectatorCameraShot
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FSavedSpectatorCameraState CameraState;

	UPROPERTY()
	bool bIsShotStart;

	UPROPERTY()
	float TimeStamp;

	UPROPERTY()
	float ShotLength;

	UPROPERTY()
	FString Message;

	UPROPERTY()
	FText LocalisedMessage;

	UPROPERTY()
	ECameraShotNotificationTypes NotificationType;

	UPROPERTY()
	FNotificationUISettings MessageUISettings;

};

USTRUCT()
struct FSavedSpectatorCameras
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FSavedSpectatorCameraShot> Shots;

};

UCLASS(MinimalAPI, HideCategories=("Collision", "Rendering", "Transformation"))
class AFortPlayerControllerSpectating : public AFortPlayerControllerGameplay
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void AdjustNormalizedDistanceToPlayer(const float Val);

	UFUNCTION(BlueprintPure)
	bool AreNotificationsEnabled() const;

	UFUNCTION(BlueprintCallable, Exec)
	void BlendCameraPlacement(const FTransform InTransform, const FTransform InTargetTransform, const float BlendDuration = 1.000000f, const ESpectateBlendEasing InEasing = ESpectateBlendEasing::Linear);

	UFUNCTION(BlueprintPure)
	bool CanRespawnAfterDeath() const;

	UFUNCTION(BlueprintPure)
	AFortPlayerState* FindPlayerStateByUID(const FUniqueNetIdRepl& UID) const;

	UFUNCTION(BlueprintCallable)
	bool FollowHoveredPlayer();

	UFUNCTION(BlueprintCallable, Exec)
	void FollowLastDamagerOfViewTarget();

	UFUNCTION(Exec)
	virtual void FollowNextPlayer();

	UFUNCTION(BlueprintCallable, Exec)
	void FollowNextSquadMember();

	UFUNCTION(BlueprintCallable, Exec)
	void FollowNextTeamMember();

	UFUNCTION(Exec)
	void FollowPlayerByName(const FString& PlayerName);

	UFUNCTION(Exec)
	virtual void FollowPrevPlayer();

	UFUNCTION(BlueprintCallable, Exec)
	void FollowPrevSquadMember();

	UFUNCTION(BlueprintCallable, Exec)
	void FollowPrevTeamMember();

	UFUNCTION(BlueprintPure)
	EFortSpectatorBlendType GetBlendType() const;

	UFUNCTION(BlueprintPure)
	UFortSpectatorCameraComponent* GetCurrentSpectatorCameraComponent() const;

	UFUNCTION(BlueprintPure)
	virtual AFortPlayerState* GetFollowedPlayer() const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	void HandleNewNotificationRequest(const FText& NotificationText, const FNotificationUISettings& NotificationSettings) const;

	UFUNCTION()
	void HandleTimelineScrubbed(UWorld* InWorld);

	UFUNCTION(BlueprintPure)
	bool HasBroadcasterToken() const;

	UFUNCTION(BlueprintPure, Exec)
	bool IsCameraBlending() const;

	UFUNCTION(BlueprintPure)
	bool IsFollowedPlayerInBus() const;

	UFUNCTION(BlueprintPure)
	virtual bool IsPlayerInRelevancy(const AFortPlayerState* FPS) const;

	UFUNCTION(BlueprintPure)
	virtual bool IsValidToFollow(AFortPlayerState* FPS) const;

	UFUNCTION(BlueprintCallable)
	bool JumpToHoveredActor();

	UFUNCTION(BlueprintCallable)
	void ResetAllCameras();

	UFUNCTION(BlueprintCallable)
	virtual void ResetCamera();

	UFUNCTION(BlueprintCallable)
	void ResetCameraBoundsVolume();

	UFUNCTION(BlueprintCallable)
	void SetBlendType(EFortSpectatorBlendType NewBlendType);

	UFUNCTION(BlueprintCallable)
	virtual void SetFollowedPlayer(AFortPlayerState* NewPlayerToFollow);

	UFUNCTION(BlueprintCallable)
	virtual void SetNewCameraType(ESpectatorCameraType NewCameraType, bool bReset = false);

	UFUNCTION(BlueprintCallable)
	void SetNotificationsEnabled(bool bNewState);

	UFUNCTION(BlueprintCallable)
	void ToggleSpectatorHUD();

	UFUNCTION()
	virtual void UpdateReplayEvents(EPlayEventType Type);

	UFUNCTION()
	void ZoomIn(const float Val);

	UPROPERTY(BlueprintReadOnly, Category="FortPlayerControllerSpectating")
	ESpectatorCameraType CurrentCameraType;

	UPROPERTY(BlueprintReadOnly, Category="Camera")
	TArray<ESpectatorCameraType> CameraModeCycle;

	UPROPERTY(EditAnywhere, Category="QuickBar", meta=(ArraySizeEnum="/Script/FortniteGame.EFortQuickBars"))
	FQuickBarData QuickBarDefinitions[3];

	UPROPERTY(BlueprintAssignable)
	FOnFollowedPlayerChanged OnFollowedPlayerChanged;

	UPROPERTY(BlueprintAssignable)
	FOnCameraTypeChanged OnCameraTypeChanged;

	UPROPERTY(BlueprintAssignable)
	FOnPlayerBecameRelevant OnPlayerBecameRelevant;

	UPROPERTY(BlueprintAssignable)
	FOnPlayerBecameIrrelevant OnPlayerBecameIrrelevant;

	UPROPERTY(BlueprintAssignable)
	FPlayerStateAthenaDelegate OnPlayerStateAdded;

	UPROPERTY(BlueprintAssignable)
	FPlayerStateAthenaDelegate OnPlayerStateChanged;

	UPROPERTY(BlueprintAssignable)
	FOnPlayerDied OnPlayerDied;

	UPROPERTY(BlueprintAssignable)
	FSpectatorDelegate OnTimelineScrubbed;

	UPROPERTY(BlueprintAssignable)
	FSpectatorDelegate OnZoomChanged;

	UPROPERTY(BlueprintAssignable)
	FOnShowNotification OnShowNotification;

	UPROPERTY(BlueprintAssignable)
	FOnShowNotificationsEnabledChanged OnShowNotificationsEnabledChanged;

	UPROPERTY(BlueprintAssignable)
	FNoParamDelegate OnFollowedPlayerChangedTeam;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PostProcess")
	TObjectPtr<UMaterialInterface> SpectatorPostProcessMaterial;

	UPROPERTY(BlueprintReadWrite, Category="FortPlayerControllerSpectating")
	TObjectPtr<AVolume> CameraBoundsVolume;

	UPROPERTY(BlueprintReadWrite, Category="FortPlayerControllerSpectating")
	bool ClampDroneToCameraBoundsVolume;

protected:
	UFUNCTION(BlueprintCallable)
	virtual bool IsAllowedChangeCamera();

	UFUNCTION(BlueprintCallable)
	void OnNextCameraMode();

	UFUNCTION()
	virtual void OnRep_FollowedPlayerRemoteClientInfo(AFortBroadcastRemoteClientInfo* PreviousFollowedPlayerRemoteClientInfo);

	UFUNCTION()
	virtual void PlayerBecameRelevant(AFortPlayerState* FPS);

	UFUNCTION(Exec)
	void SpectatorClearSavedCameraShots();

	UFUNCTION()
	void SpectatorSpecialAction();

	UPROPERTY(EditDefaultsOnly, Category="SpectatorPawns")
	TSubclassOf<AFortReplaySpectatorPawnBase> SpectatorPawnBaseClass;

	UPROPERTY(EditDefaultsOnly, Category="SpectatorPawns")
	TSubclassOf<AFortSpectatorThirdPersonPawn> ThirdPersonPawnBaseClass;

	UPROPERTY(EditDefaultsOnly, Category="SpectatorPawns")
	TSubclassOf<AHoverDronePawn> HoverDronePawnClass;

	UPROPERTY(EditDefaultsOnly, Category="SpectatorPawns")
	TSubclassOf<ABattleMapPawnReplay> BattleMapPawnClass;

	UPROPERTY(EditDefaultsOnly, Category="SpectatorPawns")
	TSubclassOf<AHoverDronePawn> ARDronePawnClass;

	UPROPERTY(EditDefaultsOnly, Category="FortPlayerControllerSpectating")
	TSubclassOf<UFortMiniMapTeamIndicators> MinimapIndicatorClass;

	UPROPERTY(Transient)
	TArray<FSavedPlayerSpectatorCameraData> SavedCameraStates;

	UPROPERTY()
	TMap<TObjectPtr<APlayerState>, bool> PlayerRelevancyTrackingMap;

	UPROPERTY()
	TMap<FUniqueNetIdRepl, TObjectPtr<AFortPlayerStateAthena>> AddedPlayersMap;

	UPROPERTY()
	TMap<FUniqueNetIdRepl, TObjectPtr<UAthenaPlayerMatchReport>> PlayerMatchReports;

	UPROPERTY()
	FVector ChaseCamOffset;

	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerState> LastDamagerOfViewTarget;

	UPROPERTY()
	FSavedSpectatorCameras HotkeyCameras;

	UPROPERTY()
	TObjectPtr<AActor> LastKnownViewTarget;

	UPROPERTY(EditDefaultsOnly, Category="RelevancyZone")
	TSubclassOf<AFortRelevancyZoneIndicator> RelevancyZoneIndicatorClass;

	UPROPERTY(EditDefaultsOnly, Category="SpectatorPlayerHighlighter")
	TSubclassOf<AFortSpectatorPlayerHighlighter> SpectatorPlayerHighlighterClass;

	UPROPERTY(Transient)
	TObjectPtr<AFortRelevancyZoneIndicator> RelevancyZoneIndicator;

	UPROPERTY(Transient)
	TMap<FUniqueNetIdRepl, TObjectPtr<AFortSpectatorPlayerHighlighter>> SpectatorPlayerHighlightersMap;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerControllerSpectating")
	TObjectPtr<UFortReplayContext> ReplayContext;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UAthenaMarkerComponent> MarkerComponent;

	UPROPERTY()
	TArray<TObjectPtr<AFortPlayerStateAthena>> SquadMembers;

	UPROPERTY(ReplicatedUsing=OnRep_FollowedPlayerRemoteClientInfo)
	TObjectPtr<AFortBroadcastRemoteClientInfo> FollowedPlayerRemoteClientInfo;

private:
	UFUNCTION()
	void HandleSquadIdModeChanged(ESpectatorSquadIdMode SquadIdMode);

	UPROPERTY(Config)
	FRemoteViewRotSnapshotManager RemoteViewRotSnapshotManager;

};

