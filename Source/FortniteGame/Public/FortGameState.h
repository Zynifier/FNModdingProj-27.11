// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ActiveGameplayEffectHandle.h"
#include "GameFramework/OnlineReplStructs.h"
#include "GameplayTagContainer.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "Abilities/FortAbilitySetHandle.h"
#include "Athena/FortAmmoBoxSpawnInfo.h"
#include "Athena/FortTreasureChestSpawnInfo.h"
#include "FortGameStateBase.h"
#include "FortGameplayStateEnum.h"
#include "FortOnTimeHitInfo.h"
#include "Items/FortEndOfDayRecap.h"
#include "OnlineLinkId.h"
#include "FortGameState.generated.h"

class AFortAIPawn;
class AFortClientAnnouncementManager;
class AFortDestructionGraph;
class AFortFXManager;
class AFortFeedbackManager;
class AFortGlobalAbilityTargetingActor;
class AFortLobbyBeaconState;
class AFortMissionManager;
class AFortMusicManager;
class AFortPawn;
class AFortPlayerController;
class AFortPlayerState;
class AFortPoiManager;
class AFortScriptedActionManager;
class AFortTeamInfo;
class AFortWindManager;
class AFortWorldManager;
class APawn;
class IFortMiniMapInterface;
class UAbilitySystemComponent;
class UCreativeQuestManager;
class UFortAmbientAudioController;
class UFortMovementComp_Character;
class UFortMusicManagerBank;
enum class EProfileCaptureType : uint8;

UENUM()
enum class ETeamChatRoomState : uint8
{
	/** Lobby not created */
	NotCreated = 0,
	/** Some player told to create a room and report back */
	Creating = 1,
	/** Room successfully created */
	Created = 2,
	/** Room failed to create */
	Timeout = 3,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAllAdditionalPlaylistLevelsLoadedDynamic);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAllAdditionalPlaylistLevelsVisibleDynamic);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPoiManagerReplicated);

USTRUCT()
struct FAdditionalLevelStreamed
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FName LevelName;

	UPROPERTY()
	bool bIsServerOnly;

};

USTRUCT()
struct FAppliedHomebaseData
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, Export)
	TWeakObjectPtr<UAbilitySystemComponent> Source;

	UPROPERTY(Transient, Export)
	TWeakObjectPtr<UAbilitySystemComponent> Target;

	UPROPERTY(Transient)
	TArray<FActiveGameplayEffectHandle> AppliedEffects;

	UPROPERTY(Transient)
	TArray<FFortAbilitySetHandle> AppliedAbilitySets;

};

USTRUCT()
struct FBuildingContainerDebugInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FVector Location;

	UPROPERTY()
	FGameplayTagContainer LocationTags;

};

USTRUCT(BlueprintType)
struct FGameStateLootInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GameStateLootInfo")
	TArray<FFortTreasureChestSpawnInfo> TreasureChestSpawnInfos;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GameStateLootInfo")
	TArray<FFortAmmoBoxSpawnInfo> AmmoBoxSpawnInfos;

};

USTRUCT()
struct FPlaylistStreamedLevelData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	bool bIsFinishedStreaming;

	UPROPERTY()
	bool bIsServerOnly;

};

USTRUCT()
struct FTeamChangeRequest
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<AFortPlayerController> RequestingController;

	UPROPERTY()
	uint8 DesiredTeam;

};

UCLASS(MinimalAPI, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortGameState : public AFortGameStateBase
{
	GENERATED_BODY()

public:
	UFUNCTION(NetMulticast, Reliable)
	void Client_InitiateEndOfDayRecap(const FEndOfDayRecap& EndOfDayRecap);

	UFUNCTION(BlueprintPure, Category="GameState")
	bool DBNOEnabledForGameMode() const;

	UFUNCTION(Exec)
	void DemoEndOfDayRecap();

	UFUNCTION(BlueprintPure)
	AFortPlayerState* GetFortPlayerStateFromUniqueNetId(const FUniqueNetIdRepl& InPlayerId) const;

	UFUNCTION(BlueprintPure, Category="GameState")
	EFortGameplayState::Type GetGameplayState() const;

	UFUNCTION(BlueprintPure, Category="Session")
	FString GetGameSessionID() const;

	UFUNCTION(BlueprintPure, Category="GameState")
	virtual FGameplayTagContainer GetHUDElementsToHide(const APawn* Pawn) const;

	UFUNCTION(BlueprintPure, Category="GameState")
	virtual FGameplayTagContainer GetHUDElementsToShow(const APawn* Pawn) const;

	UFUNCTION(BlueprintPure, Category="GameState")
	virtual float GetMatchTime() const;

	UFUNCTION(BlueprintCallable)
	virtual TScriptInterface<IFortMiniMapInterface> GetMiniMapInterface();

	UFUNCTION(BlueprintPure, Category="GameState")
	bool GetPlayerRespawningBlocked_Temporarily() const;

	UFUNCTION(BlueprintPure, Category="GameState")
	AFortPoiManager* GetPoiManager() const;

	UFUNCTION(BlueprintPure, Category="GameState")
	virtual double GetRealMatchTime() const;

	UFUNCTION(BlueprintPure, Category="GameState")
	double GetServerWorldRealTimeSeconds() const;

	UFUNCTION(BlueprintPure, Category="Days")
	int32 GetWorldDaysElapsed() const;

	UFUNCTION(NetMulticast, Reliable)
	void HandleProfilingStatusChanged(bool bStarted, EProfileCaptureType CaptureType, const FString& StatusMessage);

	UFUNCTION()
	void OnFinishedShowingAdditionalPlaylistLevel();

	UFUNCTION()
	void OnFinishedStreamingAdditionalPlaylistLevel();

	UFUNCTION()
	void OnRep_AdditionalPlaylistLevelsStreamed();

	UFUNCTION()
	void OnRep_Teams();

	UFUNCTION(NetMulticast, Reliable)
	void RunPerfMemCheatScript(bool bStartStatFiles);

	UFUNCTION(BlueprintCallable, Category="GameState")
	void SetPlayerRespawningBlocked_Temporarily(bool bBlock);

	UPROPERTY(ReplicatedUsing=OnRep_CurrentWUID)
	FString CurrentWUID;

	UPROPERTY(Replicated)
	int32 ParTime;

	UPROPERTY(Replicated)
	int32 WorldLevel;

	UPROPERTY(Replicated)
	int32 CraftingBonus;

	UPROPERTY(Replicated)
	float CurrentReadyToContinueTimer;

	UPROPERTY(Replicated)
	int32 TeamCount;

	UPROPERTY(ReplicatedUsing=OnRep_MatchmakingLinkId)
	FOnlineLinkId MatchmakingLinkId;

	UPROPERTY(ReplicatedUsing=OnRep_MatchmakingLinkType)
	FString MatchmakingLinkType;

	UPROPERTY(ReplicatedUsing=OnRep_PoiManager)
	TObjectPtr<AFortPoiManager> PoiManager;

	UPROPERTY(Replicated)
	uint8 bDBNOEnabledForGameMode : 1;

	UPROPERTY()
	uint8 bSkipWorldSave : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortGameState")
	uint8 bShowLoadingScreenUntilAllLevelAreLoaded : 1;

	UPROPERTY(Replicated)
	bool bFishingCollectionEnabled;

	UPROPERTY(Replicated)
	bool bCharacterCollectionEnabled;

	UPROPERTY(Transient, Replicated)
	float MatchStartTime;

	UPROPERTY(Transient, Replicated)
	double RealMatchStartTime;

	UPROPERTY(ReplicatedUsing=OnRep_AdditionalPlaylistLevelsStreamed)
	TArray<FAdditionalLevelStreamed> AdditionalPlaylistLevelsStreamed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Loot")
	FGameStateLootInfo LootInfo;

	UPROPERTY()
	TObjectPtr<UCreativeQuestManager> CreativeQuestManager;

protected:
	UFUNCTION(NetMulticast, Reliable)
	void Client_RefreshEventCalendar();

	UFUNCTION(Exec)
	void CopyGameSessionIdToClipboard();

	UFUNCTION(NetMulticast, Unreliable)
	void DbgBoxSendToAllInternal_DoNotCall(const FVector& Center, const FVector& Extent, const FRotator& Rotation, const FColor& Color, bool bPersistentLines, float LifeTime, uint8 DepthPriority, float Thickness);

	UFUNCTION(NetMulticast, Unreliable)
	void DbgCapsuleSendToAllInternal_DoNotCall(const FVector& Center, float HalfHeight, float Radius, const FQuat& Rotation, const FColor& Color, bool bPersistentLines, float LifeTime, uint8 DepthPriority, float Thickness);

	UFUNCTION(NetMulticast, Unreliable)
	void DbgLineSendToAllInternal_DoNotCall(const FVector& LineStart, const FVector& LineEnd, const FColor& Color, bool bPersistentLines, float LifeTime, uint8 DepthPriority, float Thickness);

	UFUNCTION(NetMulticast, Unreliable)
	void DbgSphereSendToAllInternal_DoNotCall(const FVector& Center, float Radius, int32 Segments, const FColor& Color, bool bPersistentLines, float LifeTime, uint8 DepthPriority, float Thickness);

	UFUNCTION()
	void OnRep_AnnouncementManager();

	UFUNCTION()
	virtual void OnRep_CurrentWUID();

	UFUNCTION()
	void OnRep_FeedbackManager();

	UFUNCTION()
	virtual void OnRep_GameplayState();

	UFUNCTION()
	virtual void OnRep_GameSessionID();

	UFUNCTION()
	void OnRep_MatchmakingLinkId();

	UFUNCTION()
	void OnRep_MatchmakingLinkType();

	UFUNCTION()
	void OnRep_MissionManager();

	UFUNCTION()
	void OnRep_MusicManagerBank();

	UFUNCTION()
	void OnRep_MusicManagerSubclass();

	UFUNCTION()
	void OnRep_PawnForReplayRelevancy(AFortPawn* OldPawnForReplayRelevancy);

	UFUNCTION()
	virtual void OnRep_PoiManager();

	UFUNCTION()
	void OnRep_RecorderPlayerState();

	UFUNCTION()
	virtual void OnRep_ReplicatedWorldRealTimeSecondsDouble();

	UFUNCTION()
	void OnRep_WorldDaysElapsed();

	UFUNCTION()
	virtual void OnRep_WorldManager();

	UFUNCTION()
	virtual void UpdateServerRealTimeSeconds();

	UPROPERTY(Transient, Replicated)
	bool bPlayerRespawningBlocked_Temporarily;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ReplicatedWorldRealTimeSecondsDouble)
	double ReplicatedWorldRealTimeSecondsDouble;

	UPROPERTY(Transient)
	double ServerWorldRealTimeSecondsDelta;

	UPROPERTY(ReplicatedUsing=OnRep_WorldDaysElapsed)
	int32 WorldDaysElapsed;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_FeedbackManager)
	TObjectPtr<AFortFeedbackManager> FeedbackManager;

	UPROPERTY(ReplicatedUsing=OnRep_MissionManager)
	TObjectPtr<AFortMissionManager> MissionManager;

	UPROPERTY(ReplicatedUsing=OnRep_AnnouncementManager)
	TObjectPtr<AFortClientAnnouncementManager> AnnouncementManager;

	UPROPERTY()
	TObjectPtr<AFortScriptedActionManager> ScriptedActionManager;

	UPROPERTY()
	TObjectPtr<AFortLobbyBeaconState> LobbyGameState;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_WorldManager)
	TObjectPtr<AFortWorldManager> WorldManager;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_GameplayState)
	TEnumAsByte<EFortGameplayState::Type> GameplayState;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_MusicManagerSubclass)
	TSubclassOf<AFortMusicManager> MusicManagerSubclass;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_MusicManagerBank)
	TObjectPtr<UFortMusicManagerBank> MusicManagerBank;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Audio")
	TSubclassOf<UFortAmbientAudioController> FortAmbientAudioControllerClass;

	UPROPERTY(ReplicatedUsing=OnRep_GameSessionID)
	FString GameSessionId;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFortMovementComp_Character>> ManagedCharMovementComponents;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortAIPawn>> ManagedAnimPawns;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_PawnForReplayRelevancy)
	TObjectPtr<AFortPawn> PawnForReplayRelevancy;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_RecorderPlayerState)
	TObjectPtr<AFortPlayerState> RecorderPlayerState;

	UPROPERTY(Transient)
	TObjectPtr<AFortWindManager> WindManager;

	UPROPERTY(Transient)
	TObjectPtr<AFortDestructionGraph> DestructionGraph;

	UPROPERTY(ReplicatedUsing=OnRep_Teams)
	TArray<TObjectPtr<AFortTeamInfo>> Teams;

	UPROPERTY()
	bool bSkipTeamReplication;

	UPROPERTY(Replicated)
	TArray<FTeamChangeRequest> PendingTeamChangeRequests;

	UPROPERTY()
	bool bAllowPendingTeamChangeRequests;

	UPROPERTY(Transient)
	TArray<FAppliedHomebaseData> AppliedHomebaseDataArray;

	UPROPERTY(BlueprintAssignable, Category="GameState")
	FOnAllAdditionalPlaylistLevelsLoadedDynamic OnAllAdditionalPlaylistLevelsLoadedDynamicDelegate;

	UPROPERTY(BlueprintAssignable, Category="GameState")
	FOnAllAdditionalPlaylistLevelsVisibleDynamic OnAllAdditionalPlaylistLevelsVisibleDynamicDelegate;

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFortMovementComp_Character>> ManagedCharMovementComponentsCopy;

	UPROPERTY(Transient)
	TArray<FOnTimeHitInfo> TimeOfDayCallbacks;

	UPROPERTY(Transient)
	TObjectPtr<AFortFXManager> FXManager;

	UPROPERTY(BlueprintAssignable, meta=(AllowPrivateAccess="true"))
	FOnPoiManagerReplicated OnPoiManagerReplicatedEvent;

	UPROPERTY()
	TObjectPtr<AFortGlobalAbilityTargetingActor> GlobalAbilityTargetingActor;

	UPROPERTY(Replicated)
	TArray<FBuildingContainerDebugInfo> TreasureChestInfos;

	UPROPERTY(Replicated)
	TArray<FBuildingContainerDebugInfo> AmmoBoxInfos;

	UPROPERTY(Config)
	float UnplayableHitchThresholdInMs;

	UPROPERTY(Config)
	int32 MaxUnplayableHitchesToTolerate;

};

