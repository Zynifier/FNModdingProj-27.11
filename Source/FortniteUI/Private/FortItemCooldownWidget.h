// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortCombatTypes.h"
#include "GameFramework/GameplayMessageTypes.h"
#include "FortItemCooldownWidget.generated.h"

class AFortPlayerPawn;
class UCommonTextBlock;
class UFortItemDefinition;
class UFortWorldItem;
class UImage;
class UMaterialInstanceDynamic;
enum class EFortItemCooldownType : uint8;

UENUM(BlueprintType)
enum class EFortItemCooldownType : uint8
{
	// There is no cooldown associated with this value

	None = 0,
	// The cooldown is based on regeneration of ammo

	AmmoRegeneration = 1,
	// The cooldown is not activateable due to cooldown

	ItemActivation = 2,
	// The cooldown is based on reloading, note that reloading has no duration associated with it

	WeaponReloading = 3,
	// The cooldown is based on death, as in real-life, death has no duration

	Death = 4,
	// The cooldown used by BR when a weapon is fired (if the systems are turned on of course)

	AthenaWeaponFireCooldown = 5,
	// The cooldown used by abilities that come from an ability set with activate by input abilities.

	AbilitySetActivateByInputAbility = 6,
	// This widget's cooldown is set directly via the gameplay message router system

	DirectProgressUpdate = 7,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAmmoRegenerationUpdated, bool, bOutAmmoRegenAvailableState);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCooldownStarted, EFortItemCooldownType, CooldownType, float, CooldownDuration);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCooldownStopped, EFortItemCooldownType, CooldownType);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnCooldownUpdated, EFortItemCooldownType, CooldownType, float, CooldownDuration, float, CooldownRemaining, float, CooldownPercentage);

USTRUCT(BlueprintType)
struct FDirectProgressUpdateData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="DirectProgressUpdateData")
	float ProgressPercent;

	UPROPERTY(BlueprintReadWrite, Category="DirectProgressUpdateData")
	TObjectPtr<UFortItemDefinition> ItemDef;

	UPROPERTY(BlueprintReadWrite, Category="DirectProgressUpdateData")
	TObjectPtr<AFortPlayerPawn> OwningPawn;

};

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortItemCooldownWidget : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category="Item Cooldown Widget")
	void OnAmmoRegenerationUpdated(bool bOutAmmoRegenAvailableState);

	UFUNCTION(BlueprintImplementableEvent, Category="Item Cooldown Widget")
	void OnCooldownStarted(EFortItemCooldownType CooldownType, float CooldownDuration);

	UFUNCTION(BlueprintImplementableEvent, Category="Item Cooldown Widget")
	void OnCooldownStopped(EFortItemCooldownType CooldownType);

	UFUNCTION(BlueprintImplementableEvent, Category="Item Cooldown Widget")
	void OnCooldownUpdated(EFortItemCooldownType CooldownType, float CooldownDuration, float CooldownRemaining, float CooldownPercentage);

	UFUNCTION(BlueprintCallable, Category="Item Cooldown Widget")
	void SetItem(const UFortWorldItem* InWorldItem);

	UFUNCTION(BlueprintCallable, Category="Item Cooldown Widget")
	void TryStartUpdateCooldown_BP();

	UPROPERTY(BlueprintAssignable, Category="HUD", meta=(DisplayName="OnCooldownStarted"))
	FOnCooldownStarted OnCooldownStartedEvent;

	UPROPERTY(BlueprintAssignable, Category="HUD", meta=(DisplayName="OnCooldownStopped"))
	FOnCooldownStopped OnCooldownStoppedEvent;

	UPROPERTY(BlueprintAssignable, Category="HUD", meta=(DisplayName="OnCooldownUpdated"))
	FOnCooldownUpdated OnCooldownUpdatedEvent;

	UPROPERTY(BlueprintAssignable, Category="HUD", meta=(DisplayName="OnAmmoRegenerationUpdated"))
	FOnAmmoRegenerationUpdated OnAmmoRegenerationUpdated_Delegate;

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="Item Cooldown Widget", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> CooldownText;

	UPROPERTY(BlueprintReadOnly, Export, Category="Item Cooldown Widget", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UImage> CooldownImage;

	UPROPERTY(BlueprintReadOnly, Export, Category="Item Cooldown Widget", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UImage> CooldownChargingImage;

	UPROPERTY(EditAnywhere, Category="Item Cooldown Widget")
	FName CooldownMaterialParameterName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Item Cooldown Widget")
	TArray<EFortItemCooldownType> CooldownTypesSupported;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	FEventMessageTag DirectProgressUpdateTag;

	UPROPERTY(Transient)
	TObjectPtr<UMaterialInstanceDynamic> CooldownPercentageMID;

	UPROPERTY(Transient)
	bool bAmmoRegenAvailableState;

	UPROPERTY(Transient)
	bool bDirectUpdateState;

private:
	UFUNCTION()
	void HandleLocalPlayerDied(const FFortPlayerDeathReport& DeathReport);

	UFUNCTION()
	void HandleLocalPlayerRevived();

	UFUNCTION()
	void HandleLocalPlayerSpawned();

	UFUNCTION()
	void OnWorldItemDestroyed();

};

