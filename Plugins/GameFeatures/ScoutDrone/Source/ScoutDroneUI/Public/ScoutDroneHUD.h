// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Engine/TimerHandle.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "Abilities/FortGameplayAbility_ScoutDrone_PassiveMark.h"
#include "ScoutDroneHUD.generated.h"

class AFortScoutDrone;
class UOverlay;
class UWidget;

USTRUCT(BlueprintType)
struct FScoutDroneWidgetIdentifier
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="ScoutDroneWidgetIdentifier")
	FGameplayTagContainer Tags;

	UPROPERTY(BlueprintReadWrite, Export, Category="ScoutDroneWidgetIdentifier")
	TWeakObjectPtr<UWidget> WeakWdiget;

};

UCLASS()
class UScoutDroneHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UScoutDroneHUD(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UFUNCTION(BlueprintPure, Category="Drone")
	AFortScoutDrone* GetControlledDrone() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnDroneDismissAbilityUsed();

	UFUNCTION(BlueprintImplementableEvent)
	void OnDroneEnergyChanged(float EnergyPercentage);

	UFUNCTION(BlueprintImplementableEvent)
	void OnDroneHealthUpdated(float HealthPercentage, float CurrentHealth);

	UFUNCTION(BlueprintImplementableEvent)
	void OnDroneInteractAbilityEnd();

	UFUNCTION(BlueprintImplementableEvent)
	void OnDroneInteractAbilityUsed();

	UFUNCTION(BlueprintImplementableEvent)
	void OnDroneMarkAbilityEnd();

	UFUNCTION(BlueprintImplementableEvent)
	void OnDroneMarkAbilityUsed();

	UFUNCTION(BlueprintImplementableEvent)
	void OnDronePickUpAbilityEnd();

	UFUNCTION(BlueprintImplementableEvent)
	void OnDronePickUpAbilityUsed();

	UFUNCTION(BlueprintImplementableEvent)
	void OnDronePickUpTargetsAvailable();

	UFUNCTION(BlueprintImplementableEvent)
	void OnDronePickUpTargetsEmpty();

	UFUNCTION(BlueprintImplementableEvent)
	void OnDroneSignalDataUpdated(float DistanceFromPlayer, float SignalPercentage);

	UFUNCTION(BlueprintImplementableEvent)
	void OnDroneSpeedBoostAbilityEnd();

	UFUNCTION(BlueprintImplementableEvent)
	void OnDroneSpeedBoostAbilityUsed();

	UFUNCTION(BlueprintImplementableEvent)
	void OnOwningPlayerDamaged();

	UFUNCTION(BlueprintImplementableEvent)
	void OnReticleChangeAbilityActivated(const FGameplayTag UpdatedTag);

	UFUNCTION(BlueprintImplementableEvent)
	void OnTargetingStatusChanged(const FScoutDroneStatusData& StatusData);

	UPROPERTY(BlueprintReadOnly, Transient, Category="ScoutDroneHUD")
	float TimeToConfirmTargetCache;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ScoutDroneHUD")
	float InitialHealth;

	UPROPERTY(EditDefaultsOnly, Category="ScoutDroneHUD")
	FScalableFloat WarningRange;

	UPROPERTY(EditDefaultsOnly, Category="ScoutDroneHUD")
	FScalableFloat SignalLossRange;

	UPROPERTY(EditDefaultsOnly, Category="ScoutDroneHUD")
	FScalableFloat UpdateSignalInterval;

	UPROPERTY(EditDefaultsOnly, Category="ScoutDroneHUD")
	FGameplayTag MarkAbilityTag;

	UPROPERTY(EditDefaultsOnly, Category="ScoutDroneHUD")
	FGameplayTag DismissAbilityTag;

	UPROPERTY(EditDefaultsOnly, Category="ScoutDroneHUD")
	FGameplayTag InteractAbilityTag;

	UPROPERTY(EditDefaultsOnly, Category="ScoutDroneHUD")
	FGameplayTag PickUpAbilityTag;

	UPROPERTY(EditDefaultsOnly, Category="ScoutDroneHUD")
	FGameplayTag PickUpTargetsChangedTag;

	UPROPERTY(EditDefaultsOnly, Category="ScoutDroneHUD")
	FGameplayTag SpeedBoostAbilityTag;

	UPROPERTY(BlueprintReadOnly, Export, Category="ScoutDroneHUD", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_Health;

	UPROPERTY(BlueprintReadOnly, Export, Category="ScoutDroneHUD", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_EnergyLevel;

	UPROPERTY(BlueprintReadOnly, Export, Category="ScoutDroneHUD", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_Reticle;

	UPROPERTY(BlueprintReadOnly, Export, Category="ScoutDroneHUD", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_TetheringIndicator;

private:
	UFUNCTION(BlueprintCallable)
	float GetTargetConfirmationTime();

	UPROPERTY(Transient)
	float MaxHealthCache;

	UPROPERTY(Transient)
	float MaxEnergyCache;

	UPROPERTY(Transient)
	FTimerHandle SignalDataTimerHandle;

	UPROPERTY(EditDefaultsOnly, Category="Cheats")
	TArray<FScoutDroneWidgetIdentifier> HUDIdentifiers;

};

