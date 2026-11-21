// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "ScalableFloat.h"
#include "Components/FortPawnComponent.h"
#include "FortDataRegistry/FortDataRegistryResolverScopeInterface.h"
#include "HurdleType.h"
#include "Movement/FortCharacterMovementTypes.h"
#include "HurdleComponent.generated.h"

class ACharacter;
class AFortPawn;
class APawn;
class APlayerState;
class UFortMovementMode_BaseExtLogic;

UCLASS(Config=Game, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UHurdleComponent : public UFortPawnComponent, public IFortDataRegistryResolverScopeInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool IsContextualActionPrototypeActive() const;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Hurdle Config|Movement", meta=(ShowOnlyInnerProperties))
	FHurdleInputConfig HurdleInputConfig;

	UPROPERTY(BlueprintReadOnly, Category="HurdleComponent")
	FHurdleInputConfigCache HurdleInputConfigCache;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HurdleComponent")
	TSubclassOf<UFortMovementMode_BaseExtLogic> MovementModeExtension;

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="CanStartHurdle"))
	void BP_CanStartHurdle(bool& OutCanStartHurdle) const;

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="HandleHurdleEnded"))
	void BP_HandleHurdleEnded();

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="HandleHurdleStarted"))
	void BP_HandleHurdleStarted(const FHurdleTargetingData& TargetingData, const FSynchedActionInfo& SynchedActionInfo);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="HandleSpringJump"))
	void BP_HandleSpringJump();

	UFUNCTION()
	void HandleOwnerJumpInput(bool bPressed);

	UFUNCTION()
	void HandleOwnerMovementModeChanged(ACharacter* Character, EMovementMode PreviousMovementMode, uint8 PreviousCustomMode);

	UFUNCTION()
	void HandleOwnerTeleported(AFortPawn* TeleportedOwner);

	UFUNCTION(BlueprintImplementableEvent)
	void HandleTargetingDataInvalid();

	UFUNCTION(BlueprintImplementableEvent)
	void HandleTargetingDataValid(const FHurdleTargetingData& TargetingData);

	UFUNCTION()
	void OnMutatorUpdated();

	UFUNCTION()
	void OnPlayerStatePawnSet(APlayerState* Player, APawn* NewPawn, APawn* OldPawn);

	UFUNCTION()
	void OnRep_ReplicatedHurdleState();

	UFUNCTION()
	void OnRep_ReplicatedLastTeleportTime();

	UFUNCTION()
	void RegisterMutatorUpdatedDelegate(APawn* AffectedPawn);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerStartHurdle(const FReplicatedHurdleTargetingData InReplicatedTargetingData, const double ClientLastTeleportTime);

	UFUNCTION(BlueprintPure)
	bool ShouldShowHurdleIndicator() const;

	UFUNCTION()
	void UnregisterMutatorUpdatedDelegate();

	UPROPERTY(EditDefaultsOnly, Config, Category="HurdleComponent")
	FScalableFloat HurdleEnabled;

	UPROPERTY(EditDefaultsOnly, Config, Category="HurdleComponent")
	FScalableFloat AutoHurdleEnabled;

private:
	UPROPERTY(Replicated)
	FReplicatedHurdleTargetingData ReplayHurdleTargetingData;

	UPROPERTY(ReplicatedUsing=OnRep_ReplicatedLastTeleportTime)
	double LastTeleportTime;

	UPROPERTY(Transient)
	FHurdleTargetingData ParallelTargetingData;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ReplicatedHurdleState)
	EHurdleState ReplicatedHurdleState;

};

