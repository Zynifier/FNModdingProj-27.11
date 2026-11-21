// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "ClamberingTypes.h"
#include "Components/FortPawnOverrideComponent.h"
#include "FortDataRegistry/FortDataRegistryResolverScopeInterface.h"
#include "Movement/FortCharacterMovementTypes.h"
#include "ClamberingComponent.generated.h"

class AActor;
class ACharacter;
class AFortPawn;
class AFortPlayerPawn;
class AHUD;
class APawn;
class APlayerState;
class UAnimMontage;
class UCanvas;
class UDataTable;
class UFortAbilitySystemComponent;
class UFortMovementMode_ExtClambering;
enum class EClamberingFailedReason : uint8;
enum class EClamberingState : uint8;

UCLASS(Config=Game, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UClamberingComponent : public UFortPawnOverrideComponent, public IFortDataRegistryResolverScopeInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	UAnimMontage* GetAnimMontage(float& OutPlayRate) const;

	UFUNCTION(BlueprintPure)
	bool IsAutoClamberingEnabled() const;

	UFUNCTION(BlueprintPure)
	bool IsTutorialModeEnabled() const;

	UFUNCTION(BlueprintCallable)
	void SetTutorialModeEnabled(bool bEnabled);

	UFUNCTION(BlueprintPure)
	bool ShouldShowClamberIndicator() const;

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="CanStartClambering"))
	void BP_CanStartClambering(bool& bCanStartClambering) const;

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="CanStartTargeting"))
	void BP_CanStartTargeting(bool& bCanStartTargeting) const;

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="HandleClamberingStateChanged"))
	void BP_HandleClamberingStateChanged(const EClamberingState OldClamberingState, const EClamberingState NewClamberingState);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="HandleSynchedActionStarted"))
	void BP_HandleSynchedActionStarted(const FSynchedActionInfo& SynchedActionInfo);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="IsValidTargetActor"))
	void BP_IsValidTargetActor(const AActor* TargetActor, bool& bIsValidTargetActor) const;

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="TutorialModeDisabled"))
	void BP_TutorialModeDisabled() const;

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="TutorialModeEnabled"))
	void BP_TutorialModeEnabled() const;

	UFUNCTION()
	void DrawDebugHUD(AHUD* HUD, UCanvas* Canvas);

	UFUNCTION(BlueprintImplementableEvent)
	void HandleClamberingTargetInActivationRange();

	UFUNCTION(BlueprintImplementableEvent)
	void HandleClamberingTargetOutOfActivationRange();

	UFUNCTION()
	void HandleOwnerASCInitialized(UFortAbilitySystemComponent* AbilitySystemComponent, AFortPlayerPawn* AffectedPawn);

	UFUNCTION()
	void HandleOwnerASCInvalidated();

	UFUNCTION()
	void HandleOwnerDBNO();

	UFUNCTION()
	void HandleOwnerDied(AFortPawn* DeadPawn);

	UFUNCTION()
	void HandleOwnerJumpInput(bool bPressed);

	UFUNCTION()
	void HandleOwnerMovementModeChanged(ACharacter* Character, EMovementMode PreviousMovementMode, uint8 PreviousCustomMode);

	UFUNCTION(BlueprintCallable)
	void HandleOwnerTeleported(AFortPawn* TeleportedOwner);

	UFUNCTION()
	void HandleTargetActorDestroyed(AActor* Actor);

	UFUNCTION()
	void HandleTargetActorHealthChanged();

	UFUNCTION(BlueprintImplementableEvent)
	void HandleTargetingDataInvalid();

	UFUNCTION(BlueprintImplementableEvent)
	void HandleTargetingDataValid(const FClamberingTargetingData& TargetingData);

	UFUNCTION(BlueprintPure)
	bool IsClamberingEnabled() const;

	UFUNCTION(NetMulticast, Reliable)
	void NetMulticast_ClamberingLedgeFailed(EClamberingFailedReason FailedReason, EClamberingState FailedState);

	UFUNCTION()
	void OnMutatorUpdated();

	UFUNCTION()
	void OnPlayerStatePawnSet(APlayerState* Player, APawn* NewPawn, APawn* OldPawn);

	UFUNCTION()
	void OnRep_ReplicatedClamberingState();

	UFUNCTION()
	void OnRep_ReplicatedLastTeleportTime();

	UFUNCTION()
	void OnRep_ReplicatedTargetingData();

	UFUNCTION()
	void RegisterMutatorUpdatedDelegate(APawn* AffectedPawn);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerStartClambering(const FReplicatedClamberingTargetingData InReplicatedTargetingData, const double ClientLastTeleportTime);

	UFUNCTION()
	void UnregisterMutatorUpdatedDelegate();

	UPROPERTY(Transient, meta=(DisplayName="ClamberingState"))
	EClamberingState LocalClamberingState;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ReplicatedClamberingState)
	EClamberingState ReplicatedClamberingState;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ClamberingComponent")
	FClamberingTargetingData LockedTargetingData;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ReplicatedTargetingData)
	FReplicatedClamberingTargetingData_SimClient ReplicatedTargetingData;

	UPROPERTY(EditDefaultsOnly, Config, Category="ClamberingComponent")
	FScalableFloat ClamberingEnabled;

	UPROPERTY(EditDefaultsOnly, Config, Category="ClamberingComponent")
	FScalableFloat ClamberIndicatorEnabled;

	UPROPERTY(EditDefaultsOnly, Config, Category="ClamberingComponent")
	FScalableFloat ClamberStartMaxFallingDamageFraction;

	UPROPERTY(EditDefaultsOnly, Config, Category="Clambering Config|Client")
	bool bPerformTargetingWhileWalking;

	UPROPERTY(EditDefaultsOnly, Config, Category="Clambering Config|Client")
	bool bPerformTargetingWhileSwimming;

	UPROPERTY(EditDefaultsOnly, Config, Category="Clambering Config|Server")
	FScalableFloat ServerFailDelay;

	UPROPERTY(EditDefaultsOnly, Config, Category="Clambering Config|Server")
	FScalableFloat ServerValidatePlayerMaxDistance;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Clambering Input Config", meta=(ShowOnlyInnerProperties))
	FClamberingInputConfig InputConfig;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Ledge Clambering Config|Targeting", meta=(ShowOnlyInnerProperties))
	FClamberingTargetingConfig_Ledge TargetingConfig_Ledge;

	UPROPERTY(Transient)
	FClamberingInputConfig_CachedValues InputConfigCachedValues;

	UPROPERTY(Transient)
	FClamberingTargetingConfig_Ledge_CachedContextualValues TargetingConfig_Ledge_CachedContextualValues;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Ledge Clambering Config|Movement", meta=(ShowOnlyInnerProperties))
	FClamberingMovementConfig_Ledge MoveConfig_Ledge;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Ledge Clambering Config|Sync Action")
	FScalableFloat ClamberSyncTargetLedgeOffset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ClamberingComponent")
	FScalableFloat ClamberingMaxAnalyticsEvents;

	UPROPERTY(EditDefaultsOnly, Config, Category="Clambering Config|Fail Safe")
	FScalableFloat SynchedActionFailDelay;

	UPROPERTY(EditDefaultsOnly, Category="Clambering")
	TObjectPtr<UDataTable> ClamberingAnimations;

	UPROPERTY(EditDefaultsOnly, Category="Clambering")
	TObjectPtr<UDataTable> PrototypeClamberingAnimations;

	UPROPERTY(EditDefaultsOnly, Category="ClamberingComponent")
	TSubclassOf<UFortMovementMode_ExtClambering> MovementModeExtension;

	UPROPERTY(ReplicatedUsing=OnRep_ReplicatedLastTeleportTime)
	double LastTeleportTime;

	UPROPERTY(Transient)
	bool bTutorialModeEnabled;

private:
	UPROPERTY(Transient)
	FClamberingTargetingData LocalTargetingData;

	UPROPERTY(Transient)
	FClamberingTargetingData ParallelTargetingData;

	UPROPERTY(Transient)
	float QueuedInputTimer;

	UPROPERTY(Transient)
	float InputEnabledTimer;

	UPROPERTY(Transient)
	bool bJumpInputPressed;

	UPROPERTY(Transient)
	float JumpHeldInAirTime;

	UPROPERTY(EditAnywhere, Category="ClamberingComponent")
	FGameplayTag Tag_DisableClambering;

};

