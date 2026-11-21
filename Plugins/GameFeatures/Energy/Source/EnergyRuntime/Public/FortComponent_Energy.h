// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/PawnComponent.h"
#include "Engine/TimerHandle.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "FortComponent_Energy.generated.h"

class AFortPlayerPawn;
class APawn;
class APlayerState;
class UFortAbilitySystemComponent;
class UFortComponent_Energy;
class UObject;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEnergyDrained, UFortComponent_Energy*, EnergyComponent);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEnergyReachedMax, UFortComponent_Energy*, EnergyComponent);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEnergyReachedMinForUsing, UFortComponent_Energy*, EnergyComponent);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEnergyRechargeBegun, UFortComponent_Energy*, EnergyComponent);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEnergyRechargeComplete, UFortComponent_Energy*, EnergyComponent);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEnergyRechargeDisabled, UFortComponent_Energy*, EnergyComponent);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEnergyRechargeEnabled, UFortComponent_Energy*, EnergyComponent);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEnergyRechargeInterrupted, UFortComponent_Energy*, EnergyComponent);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEnergyUseDisabled, UFortComponent_Energy*, EnergyComponent);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEnergyUseEnabled, UFortComponent_Energy*, EnergyComponent);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnEnergyValueChanged, UFortComponent_Energy*, EnergyComponent, float, PreviousValue);

USTRUCT()
struct FEnergyChannelingData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float EnergyPerSecond;

	UPROPERTY()
	FGameplayTag EnergyChannelingPurposeIdentifier;

	UPROPERTY()
	TObjectPtr<UObject> OptionalEnergyChannelingSource;

	UPROPERTY()
	bool bShouldStopApplyingNextTick;

};

USTRUCT()
struct FEnergyRegenOverrideData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FGameplayTag EnergyRegenIdentifier;

	UPROPERTY()
	float RechargeAmountPerSecond;

	UPROPERTY()
	float RechargeDelayInSeconds;

	UPROPERTY()
	float RechargePercentageLimit;

};

UCLASS(Config=Game, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class ENERGYRUNTIME_API UFortComponent_Energy : public UPawnComponent
{
	GENERATED_BODY()

public:
	UFortComponent_Energy(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintCallable, Category="Energy", meta=(HidePin="bBroadcastEnergyPercentChanged"))
	bool AddEnergy(float& OutAmountOfEnergyAdded, float AmountOfEnergyToAdd, UObject* OptionalEnergySource = nullptr, bool bBroadcastEnergyPercentChanged = true);

	UFUNCTION(BlueprintCallable, Category="Energy")
	void ApplyRegenDataOverride(const FGameplayTag& RegenOverrideIdentifier, const float NewRechargeAmountPerSecond = -1.000000f, const float NewRechargeDelayInSeconds = -1.000000f, const float NewRechargePercentageLimit = -1.000000f);

	UFUNCTION(BlueprintPure, Category="Energy")
	float GetCurrentEnergyPercentage() const;

	UFUNCTION(BlueprintPure, Category="Energy")
	bool HasSufficientEnergy(float EnergyAmountToTest) const;

	UFUNCTION(BlueprintCallable, Category="Energy")
	bool RemoveRegenDataOverride(const FGameplayTag& RegenOverrideIdentifier);

	UFUNCTION(BlueprintCallable, Category="Energy")
	bool SetAllEnergyUsageFree(bool bShouldEnergyUsageBeFree = true);

	UFUNCTION(BlueprintCallable, Category="Energy")
	bool StartAddingEnergy(float EnergyToAddPerSecond, const FGameplayTag& EnergySourceIdentifier, UObject* OptionalEnergySource = nullptr);

	UFUNCTION(BlueprintCallable, Category="Energy")
	bool StartUsingEnergy(float EnergyToUseToStart, float EnergyToUsePerSecond, const FGameplayTag& EnergyUseIdentifier, UObject* OptionalEnergyUser = nullptr);

	UFUNCTION(BlueprintCallable, Category="Energy")
	bool StopAddingEnergy(const FGameplayTag& EnergyUseIdentifier, UObject* OptionalEnergySource = nullptr);

	UFUNCTION(BlueprintCallable, Category="Energy")
	bool StopUsingEnergy(const FGameplayTag& EnergyUseIdentifier, UObject* OptionalEnergyUser = nullptr);

	UFUNCTION(BlueprintCallable, Category="Energy", meta=(HidePin="bBroadcastEnergyPercentChanged"))
	bool UseEnergy(float& OutAmountOfEnergyUsed, float AmountOfEnergyToUse, bool bUseEnergyEvenOnFailure = false, UObject* OptionalEnergyUser = nullptr, bool bBroadcastEnergyPercentChanged = true);

	UPROPERTY(BlueprintAssignable, Category="Events", meta=(AllowPrivateAccess="TRUE"))
	FOnEnergyDrained OnEnergyCompletelyDrained;

	UPROPERTY(BlueprintAssignable, Category="Events", meta=(AllowPrivateAccess="TRUE"))
	FOnEnergyRechargeComplete OnEnergyRechargeComplete;

protected:
	UPROPERTY(EditDefaultsOnly, Category="Energy")
	FScalableFloat MaxEnergy;

private:
	UFUNCTION()
	void HandleAbilitySystemComponentInitialized(UFortAbilitySystemComponent* AbilitySystemComponent, AFortPlayerPawn* PlayerPawn);

	UFUNCTION()
	void HandleAbilitySystemComponentInvalidated();

	UFUNCTION()
	void OnMutatorUpdated();

	UFUNCTION()
	void OnPlayerStatePawnSet(APlayerState* Player, APawn* NewPawn, APawn* OldPawn);

	UFUNCTION()
	void RegisterMutatorUpdatedDelegate(APawn* AffectedPawn);

	UPROPERTY(EditDefaultsOnly, Category="Energy")
	FGameplayTagQuery RechargeDisabledQuery;

	UPROPERTY()
	FGameplayTagQuery EnergyUseDisabledQuery;

	UPROPERTY()
	FTimerHandle BeginRechargeTimerHandle;

	UPROPERTY(EditDefaultsOnly, Category="FortComponent_Energy")
	FGameplayTagContainer EnergyTypeIdentifierTagContainer;

	UPROPERTY(Transient)
	float CurrentEnergy;

	UPROPERTY()
	float NetEnergyDeltaPerSecond;

	UPROPERTY(EditDefaultsOnly, Category="Energy")
	FScalableFloat MinEnergyForUsing;

	UPROPERTY(EditDefaultsOnly, Category="Energy")
	FScalableFloat RechargeAmountPerSecond;

	UPROPERTY(EditDefaultsOnly, Category="Energy")
	FScalableFloat RechargeDelayInSeconds;

	UPROPERTY(EditDefaultsOnly, Category="Energy")
	FScalableFloat RechargePercentageLimit;

	UPROPERTY()
	TArray<FEnergyChannelingData> ActiveEnergyChannels;

	UPROPERTY()
	TArray<FEnergyChannelingData> NewActiveEnergyChannels;

	UPROPERTY()
	TArray<FEnergyRegenOverrideData> EnergyRegenOverrides;

	UPROPERTY(BlueprintAssignable, Category="Events", meta=(AllowPrivateAccess="TRUE"))
	FOnEnergyValueChanged OnCurrentEnergyChanged;

	UPROPERTY(BlueprintAssignable, Category="Events", meta=(AllowPrivateAccess="TRUE"))
	FOnEnergyRechargeBegun OnEnergyRechargeBegun;

	UPROPERTY(BlueprintAssignable, Category="Events", meta=(AllowPrivateAccess="TRUE"))
	FOnEnergyRechargeInterrupted OnEnergyRechargeInterrupted;

	UPROPERTY(BlueprintAssignable, Category="Events", meta=(AllowPrivateAccess="TRUE"))
	FOnEnergyReachedMax OnEnergyReachedMax;

	UPROPERTY(BlueprintAssignable, Category="Events", meta=(AllowPrivateAccess="TRUE"))
	FOnEnergyReachedMinForUsing OnEnergyReachedMinForUsing;

	UPROPERTY(Transient)
	uint8 bRechargingEnabled : 1;

	UPROPERTY(Transient)
	uint8 bIsRecharging : 1;

	UPROPERTY(Transient)
	uint8 bIsUsingEnergy : 1;

};

