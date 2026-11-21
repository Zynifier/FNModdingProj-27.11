// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "Math/MathFwd.h"
#include "Misc/Guid.h"
#include "ScalableFloat.h"
#include "Abilities/FortAbilitySystemInterface.h"
#include "Analytics/FortAutorunAnalytics.h"
#include "CatalogTypes.h"
#include "FortCombatTypes.h"
#include "FortVoteConfig.h"
#include "Items/FortPersistentTypes.h"
#include "McpCatalogEnums.h"
#include "McpCatalogItemPrice.h"
#include "Player/FortPlayerControllerGameplay.h"
#include "FortPlayerControllerZone.generated.h"

class AActor;
class AController;
class AFortPlayerControllerZone;
class AFortPlayerStateZone;
class APawn;
class IFortHUDTargetUnderReticleInterface;
class UFortControllerComponent_MovementCancellableAction;
class UFortControllerComponent_TriggerHaptics;
class UInputComponent;
class UObject;
enum class EFortVoteType : uint8;

UENUM()
enum class ELeecherStatus : uint8
{
	NotReady = 0,
	NonLeecher = 1,
	Leecher = 2,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayerStartedRespawn, AFortPlayerControllerZone*, PlayerController);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPossessedPawnDied);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSkyDivingStateChange);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSkydivingFromBusStateChange, AFortPlayerControllerZone*, PlayerController);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnVehicleSeatTransitionTargetIndexChange, int32, SeatIndex);

USTRUCT()
struct FPurchaseCatalogEntryData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString OfferId;

	UPROPERTY()
	TEnumAsByte<EStoreCurrencyType::Type> CurrencyType;

	UPROPERTY()
	FString CurrencySubType;

	UPROPERTY()
	int32 ExpectedTotalPrice;

	UPROPERTY()
	int32 PurchaseQuantity;

	UPROPERTY()
	FString GameContext;

	UPROPERTY()
	FString ClientRequestId;

	UPROPERTY()
	bool bIsValid;

	UPROPERTY()
	FStoreOfferInfo StoreOfferInfo;

};

UCLASS(MinimalAPI, HideCategories=("Collision", "Rendering", "Transformation"))
class AFortPlayerControllerZone : public AFortPlayerControllerGameplay, public IFortAbilitySystemInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Cosmetics")
	void AllowLoadoutRefresh();

	UFUNCTION(BlueprintPure, Category="Death")
	bool AreResurrectionAndRespawnTimeRemainingValid() const;

	UFUNCTION(Client, Reliable)
	void ClientAckLoadoutConfig(int32 LoadoutSeed);

	UFUNCTION(Client, Reliable)
	void ClientClearDeathNotification();

	UFUNCTION(Client, Reliable)
	void ClientOnPawnDied(FFortPlayerDeathReport DeathReport);

	UFUNCTION(Client, Reliable)
	void ClientOnPawnRevived(AController* EventInstigator);

	UFUNCTION(Client, Reliable)
	void ClientOnPawnSpawned();

	UFUNCTION(Client, Reliable)
	void ClientOnZoneEndScoreReports(const TArray<FFortPlayerScoreReport>& ScoreReports);

	UFUNCTION(Client, Reliable)
	void ClientSendPartyJoinInfoToPlayer(const FString& JoinInfoStr);

	UFUNCTION(Client, Reliable)
	void ClientSubmitLogs(const FGuid& ParentReportId) const;

	UFUNCTION(Client, Reliable)
	void ClientUpdatePlaylistFlags(const TArray<uint8>& Buffer);

	UFUNCTION(Client, Reliable)
	void ClientVoiceChatSendJoinToken(int32 RequestId, bool bSuccess, const FString& Error, const FString& Token, const FString& ChannelName);

	UFUNCTION(Exec)
	void DumpPhysicsVehicleBuffer(const FString& Command);

	UFUNCTION(BlueprintPure)
	int32 GetVehicleSeatTransitionTargetIndex() const;

	UFUNCTION(BlueprintPure, Category="Defeat")
	bool IsClientNotifiedOfPawnDied() const;

	UFUNCTION(BlueprintPure)
	bool IsShowingSeasonLevel() const;

	UFUNCTION(BlueprintPure)
	bool IsUsingAnonymousCharacterMode() const;

	UFUNCTION(BlueprintPure)
	bool IsUsingAnonymousMode() const;

	UFUNCTION(Exec)
	void KillAllVehicles(const FString& Command);

	UFUNCTION()
	void OnRep_VoiceChatChannel();

	UFUNCTION(BlueprintCallable, Category="Input")
	void PopDeathInputComponent();

	UFUNCTION()
	void PostMCPUpdateRequestLoadoutRefresh();

	UFUNCTION(BlueprintCallable, Category="Input")
	virtual void PushDeathInputComponent();

	UFUNCTION(BlueprintCallable, Category="Input")
	void ResetExecuteJetpackToggle();

	UFUNCTION(BlueprintCallable, Category="Death")
	virtual void RespawnPlayer();

	UFUNCTION(BlueprintCallable, Category="Death")
	void ResurrectPlayer();

	UFUNCTION(Exec)
	void RewindVehicle(const FString& Command);

	UFUNCTION(Server, Reliable, BlueprintCallable)
	void ServerAttemptExitVehicle();

	UFUNCTION(Server, Reliable, BlueprintCallable)
	void ServerBeginGameplayVote(EFortVoteType VoteType, FFortVoteConfig VoteConfig);

	UFUNCTION(Server, Reliable, BlueprintCallable)
	void ServerEndGameplayVote(EFortVoteType VoteType);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category="Cosmetics")
	void ServerRequestLoadoutRefresh(bool bForceResfresh = false);

	UFUNCTION(Server, Reliable)
	void ServerRequestSeatChange(int32 TargetSeatIndex);

	UFUNCTION(Server, Reliable)
	void ServerSendLoadoutConfig(int32 LoadoutSeed, const TArray<uint8>& Loadout);

	UFUNCTION(Server, Reliable)
	void ServerSendPartyJoinInfoToPlayer(const FUniqueNetIdRepl& RecipientId, const FString& JoinInfoStr);

	UFUNCTION(Server, Reliable)
	void ServerSetShouldDisablePlayerTeleportingDuringMissionResults();

	UFUNCTION(Server, Reliable)
	void ServerSetVehicleHealth(float NewHealth);

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable, Category="Team")
	void ServerSpectateActor(AActor* NewViewTarget, const bool bAllowStateChange);

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable, Category="Team")
	void ServerSpectatePlayerState(AFortPlayerStateZone* PlayerToSpectate, const bool bAllowStateChange);

	UFUNCTION(Server, Reliable, BlueprintCallable)
	void ServerSubmitGameplayVote(EFortVoteType VoteType, int32 VoteDecision);

	UFUNCTION(BlueprintCallable)
	void SetDontChangeReticleColorForEnemy(bool bDontChangeForEnemy);

	UFUNCTION(Exec)
	void SetVehicleHealth(float NewHealth);

	UFUNCTION()
	virtual void SpectateOnDeath();

	UFUNCTION(Exec)
	void TestVehicleVelocity(const FString& Command);

	UPROPERTY(BlueprintAssignable)
	FOnSkyDivingStateChange OnBeginSkydiving;

	UPROPERTY(BlueprintAssignable)
	FOnSkyDivingStateChange OnEndSkydiving;

	UPROPERTY(BlueprintAssignable)
	FOnSkydivingFromBusStateChange OnBeginSkydivingFromBus;

	UPROPERTY(BlueprintAssignable)
	FOnSkydivingFromBusStateChange OnEndSkydivingFromBus;

	UPROPERTY(BlueprintAssignable)
	FOnVehicleSeatTransitionTargetIndexChange OnVehicleSeatTransitionTargetIndexChange;

	UPROPERTY(BlueprintAssignable)
	FOnPlayerStartedRespawn OnStartedRespawn;

	UPROPERTY()
	bool bDontChangeReticleColorForEnemy;

	UPROPERTY(Transient)
	float LastVehicleSeatSwitchTime;

	UPROPERTY()
	TObjectPtr<APawn> PlayerToSpectateOnDeath;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_VoiceChatChannel)
	FString VoiceChatChannel;

	UPROPERTY(Replicated)
	TArray<TObjectPtr<AActor>> DesyncNotifyList;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	UFUNCTION(Client, Reliable)
	void ClientHandleCatalogOutOfDate();

	UFUNCTION(Client, Reliable)
	void ClientHandlePurchaseCatalogEntryFailure();

	UFUNCTION(BlueprintCallable, Category="Utilities")
	void DisableRangedWeaponScopeFX();

	UFUNCTION(Server, Reliable, BlueprintCallable)
	void ServerActivateMission();

	UFUNCTION(Server, Reliable)
	void ServerDestroyFromRemoteControlledPawn();

	UFUNCTION(Server, Reliable)
	void ServerDetachFromRemoteControlledPawn();

	UFUNCTION(Server, Reliable)
	void ServerPurchaseCatalogEntry(const FString& GameNamespace, const FString& OfferId, const FString& DevName, const FCatalogItemPrice& Price, const FString& AppStoreOfferId, const FString& EpicOfferId, int32 Quantity, int32 ExpectedPrice, const FString& NotificationId, const int32 CommonCoreClientRevision, const int32 AthenaClientRevision, const FStoreOfferInfo& StoreOfferInfo);

	UPROPERTY(Transient)
	int32 NumForceQueryProfileRequestsInFlight;

	UPROPERTY(Transient)
	FPurchaseCatalogEntryData PurchaseCatalogEntryData;

	UPROPERTY(Transient)
	TSet<FGuid> GadgetTrackedAttributeItemInstanceIds;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortControllerComponent_TriggerHaptics> TriggerHapticsComponent;

	UPROPERTY()
	TArray<TObjectPtr<UObject>> InstantSlideInputSources;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UInputComponent> DeathInputComponent;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UInputComponent> RemoteControlledPawnInputComponent;

	UPROPERTY(Config)
	bool bUseDeferredFireInputs;

	UPROPERTY(BlueprintReadOnly, Transient, Category="DeathReport")
	FFortPlayerDeathReport PlayerDeathReport;

	UPROPERTY(Transient)
	bool bClientNotifiedOfPawnDied;

	UPROPERTY(Transient)
	bool bEnterCameraModeOnDeath;

	UPROPERTY(Transient, Replicated)
	ELeecherStatus PlayerLeecherStatus;

	UPROPERTY(BlueprintAssignable)
	FOnPossessedPawnDied OnPossessedPawnDied;

	UPROPERTY(Transient)
	TScriptInterface<IFortHUDTargetUnderReticleInterface> HUDTargetUnderReticle;

	UPROPERTY()
	TArray<FUniqueNetIdRepl> RejoinablePartyMembers;

	UPROPERTY(Transient)
	float LastScoreEarnedTime;

	UPROPERTY(Transient)
	bool bJetpackExecuteToggle;

	UPROPERTY(Config)
	bool bAllowMovementCancellableActionsWithIceFeet;

	UPROPERTY(Config)
	bool bAllowMovementCancellableActionsDuringInputWithIceFeet;

	UPROPERTY(Config)
	float MoveForwardOnlyEmoteCancelBackwardsThreshold;

	UPROPERTY(Config)
	float MoveForwardOnlyEmoteCancelStrafeThreshold;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortPlayerControllerZone")
	FScalableFloat MovementCancellableActionLeashLength;

	UPROPERTY()
	FVector MovementCancellableActionLeashLocation;

	UPROPERTY()
	FVector MovementCancellableActionStartingLeashLocation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortPlayerControllerZone")
	FScalableFloat UpdateSurfaceTypeMinimumLength;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortPlayerControllerZone")
	FScalableFloat UpdateSurfaceTypeMinimumDelay;

	UPROPERTY(EditDefaultsOnly, Category="FortPlayerControllerZone")
	TSubclassOf<UFortControllerComponent_MovementCancellableAction> MovementCancellableActionComponentClass;

private:
	UFUNCTION(Client, Reliable, WithValidation)
	void ClientDebugReceiveTagDiscrepancyResponse(const TArray<uint8>& CompressedTags, bool bAllDataSent);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerDebugSendDiscrepancyRequestData();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerDebugSendTagDiscrepancyRequest();

	UFUNCTION(Server, Reliable)
	void ServerVoiceChatRequestJoinToken(int32 RequestId, const FString& ChannelName);

	UPROPERTY(Transient)
	int32 VehicleSeatTransitionTargetIndex;

	UPROPERTY(Transient)
	FString PurchaseNotificationId;

	UPROPERTY(Config)
	float VoiceChatCachedTokenLifetimeSeconds;

	UPROPERTY(Transient)
	TArray<FAutorunUsageData> AutorunAnalyticsDataArray;

	UPROPERTY(Config)
	double ClientSubmitLogsLockoutIntervalSeconds;

};

