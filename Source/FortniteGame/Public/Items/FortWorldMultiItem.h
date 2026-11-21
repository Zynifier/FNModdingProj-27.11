// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbilityTypes.h"
#include "Engine/TimerHandle.h"
#include "GameplayTagContainer.h"
#include "Items/FortWorldItem.h"
#include "FortWorldMultiItem.generated.h"

class UFortGameplayAbility;
class UFortItemDefinition;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FMultiItemOnSwitchPending, const int32, CurrentItemIndex, const int32, PendingItemIndex);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMultiItemOnSwitched, const int32, CurrentItemIndex);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FMultiItemOnXPChanged, const float, XPChangeAmount, const float, CurrentXP);

UCLASS(MinimalAPI, BlueprintType)
class UFortWorldMultiItem : public UFortWorldItem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Multi Item")
	UFortItemDefinition* GetCurrentActiveItemDefinition() const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Power Up")
	void IncrementItemXP(float IncrementAmount);

	UPROPERTY(BlueprintAssignable, Category="Item Switch")
	FMultiItemOnSwitched OnItemSwitched;

	UPROPERTY(BlueprintAssignable, Category="Power Up")
	FMultiItemOnXPChanged OnItemXPChanged;

	UPROPERTY(BlueprintAssignable, Category="Power Up")
	FMultiItemOnSwitchPending OnPowerUpPending;

private:
	UFUNCTION()
	void OnOwnerPlayerPawnAbilityActivated(UFortGameplayAbility* GameplayAbility, FGameplayTagContainer AbilityTags);

	UFUNCTION()
	void OnOwnerPlayerPawnAbilityEndedWithData(const FAbilityEndedData& AbilityEndedData);

	UFUNCTION()
	void StopDisablingEquipAnimation();

	UPROPERTY(Transient)
	FTimerHandle TimeToSwitchHandle;

	UPROPERTY(Transient)
	FTimerHandle TimeToEndSwitchHandle;

	UPROPERTY(Transient)
	FTimerHandle TimeToRetrySwitchHandle;

	UPROPERTY(Transient)
	FTimerHandle TimeToReenableEquipAnim;

	UPROPERTY(Transient)
	float TimeOfLastSwitch;

	UPROPERTY(Transient)
	uint8 bWantsToSwitch : 1;

	UPROPERTY(Transient)
	uint8 bTellHasBegun : 1;

	UPROPERTY(Transient)
	uint8 bDisableEquipAnimationThisFrame : 1;

	UPROPERTY(Transient)
	int32 CurrentSelectedItemIndex;

	UPROPERTY(Transient)
	float CurrentItemXP;

	UPROPERTY(Transient)
	int32 PendingPowerUpLevel;

};

