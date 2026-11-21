// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Camera/PlayerCameraManager.h"
#include "GameplayAbilitySpec.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "UObject/NoExportTypes.h"
#include "Components/FortControllerComponent.h"
#include "Components/FortControllerComponent_IndicatedActorManagement.h"
#include "ScoutDroneTypes.h"
#include "FortScoutDroneControllingComponent.generated.h"

class AActor;
class AFortScoutDrone;
class AFortWeapon;
class UFortCameraMode;
class UFortInputMappingContext;
class UGameplayEffect;
class UInputAction;
class UInputComponent;
class UScoutDroneDeferredDestructionPayload;

USTRUCT(BlueprintType)
struct FScoutDroneInputTriggerableEvent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="ScoutDroneInputTriggerableEvent")
	FName InputActionName;

	UPROPERTY(EditDefaultsOnly, Category="ScoutDroneInputTriggerableEvent")
	TObjectPtr<UInputAction> InputAction;

	UPROPERTY(EditDefaultsOnly, Category="ScoutDroneInputTriggerableEvent")
	FGameplayTag GameplayEventToTrigger;

};

UCLASS(MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"))
class UFortScoutDroneControllingComponent : public UFortControllerComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Drone")
	AFortScoutDrone* GetControlledDrone() const;

protected:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, meta=(DisplayName="OnDestructionStarted"))
	void BP_OnDestructionStarted(bool bInstantDestruction, const FGameplayTag DismissalReason);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, meta=(DisplayName="OnDismissalStarted"))
	void BP_OnDismissalStarted(bool bInstantDismissal, const FGameplayTag DismissalReason);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, meta=(DisplayName="OnDroneDestroyed"))
	void BP_OnDroneDestroyed(const FGameplayTag& DismissalReason);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, meta=(DisplayName="OnPlayerInteractLongUseChanged"))
	void BP_OnPlayerInteractLongUseChanged(bool bInteracting, bool bLongUseInteractionCompleted);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, meta=(DisplayName="OnPlayerShortInteract"))
	void BP_OnPlayerShortInteract();

private:
	UFUNCTION()
	void OnControlledDroneDestroyed(AActor* InControlledDrone);

	UFUNCTION()
	void OnOwningPlayerStartedDBNO();

	UFUNCTION()
	void OnPlayerInterruptionTagsChanged(const FGameplayTag Tag, int32 NewCount);

	UFUNCTION()
	void OnRep_ControlledDrone();

	UFUNCTION()
	void OnRep_CurrentDestructionData();

	UFUNCTION()
	void OnWeaponEquipped(AFortWeapon* NewWeapon, AFortWeapon* PrevWeapon);

	UFUNCTION(Server, Reliable)
	void ServerRequestDroneDismissal();

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UInputComponent> DroneInputComponent;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ControlledDrone)
	TObjectPtr<AFortScoutDrone> ControlledDrone;

	UPROPERTY(Transient)
	TObjectPtr<AActor> OriginalDroneOwner;

	UPROPERTY(EditDefaultsOnly, Category="Input")
	TObjectPtr<UFortInputMappingContext> DroneInputContext;

	UPROPERTY(EditDefaultsOnly, Category="Input")
	TArray<FScoutDroneInputTriggerableEvent> InputTriggerableEvents;

	UPROPERTY(EditDefaultsOnly, Category="Input")
	TObjectPtr<UInputAction> MoveUpAction;

	UPROPERTY(EditDefaultsOnly, Category="Input")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditDefaultsOnly, Category="Input")
	TObjectPtr<UInputAction> DismissAction;

	UPROPERTY(EditDefaultsOnly, Category="Drone Cooldown")
	TSubclassOf<UGameplayEffect> DroneCooldownEffectClass;

	UPROPERTY(EditDefaultsOnly, Category="Drone Indicators")
	FStenciledActorData OwningActorStencilData;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_CurrentDestructionData)
	FScoutDroneDeferredDestructionData CurrentDestructionData;

	UPROPERTY(EditAnywhere, Category="Remote Control | Camera")
	TSubclassOf<UFortCameraMode> FirstPersonCameraModeOverride;

	UPROPERTY(EditAnywhere, Category="Remote Control | Camera")
	TSubclassOf<UFortCameraMode> ThirdPersonCameraModeOverride;

	UPROPERTY(Transient)
	FGameplayAbilitySpec FakeCameraAbilitySpec;

	UPROPERTY(EditAnywhere, Category="Input")
	TArray<FName> LegacyInputActionsToBlock;

	UPROPERTY(Transient)
	TObjectPtr<UScoutDroneDeferredDestructionPayload> DismissPayloadCache;

	UPROPERTY(EditDefaultsOnly, Category="Input")
	FScalableFloat DismissButtonPressCooldown;

	UPROPERTY(EditDefaultsOnly, Category="Camera")
	FViewTargetTransitionParams PlayerToDroneTransitionParams;

	UPROPERTY(EditDefaultsOnly, Category="Remote Control | Interruptions")
	FGameplayTagContainer InterruptingPlayerTags;

};

UCLASS(BlueprintType)
class SCOUTDRONERUNTIME_API UScoutDroneDeferredDestructionPayload : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="ScoutDroneDeferredDestructionPayload")
	FScoutDroneDeferredDestructionData DeferredDestructionData;

};

