// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/FortControllerComponent.h"
#include "FortControllerComponent_AugmentUIEvents.generated.h"

enum class EAugmentHoldInputRerollState : uint8;

UENUM(BlueprintType)
enum class EAugmentHoldInputRerollState : uint8
{
	Pressed = 0,
	Released = 1,
};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent_AugmentUIEvents : public UFortControllerComponent
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FAugmentHoldInputRerollChangedDelegate, EAugmentHoldInputRerollState, HoldState, float, HoldDurationSeconds);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAugmentGrantingTimersFinishedForMatchDelegate);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAugmentGrantingTimersResetForMatchDelegate);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAugmentSelectorHighlightedChoiceDelegate, int32, ChoiceIndex);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAugmentSelectorOpenedStatusChangedDelegate, bool, bIsOpened, bool, bViewingInventory);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAugmentStartedSelectionOfChoiceDelegate, int32, ChoiceIndex);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAugmentToolViewSwapDelegate, bool, ViewingInventoryAugments);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGrantTimerProgressUpdatedDelegate, float, TimeRemaining, float, TimePercentage);

public:
	UFUNCTION(BlueprintCallable)
	void HandleAugmentSelectorOpenedStatusChanged(const bool bIsOpened, const bool bViewingInventory = false);

	UFUNCTION(BlueprintCallable)
	void NotifyGrantingTimersFinished();

	UFUNCTION(BlueprintCallable)
	void NotifyGrantingTimersReset();

	UFUNCTION(BlueprintCallable)
	void SetNumGrantableAugmentsForPlaylist(const int32 NewNumRounds);

	UFUNCTION(BlueprintCallable)
	void UpdatedTimerProgress(float TimeRemaining, float TimePercentage);

	UPROPERTY(BlueprintAssignable)
	FOnAugmentSelectorHighlightedChoiceDelegate OnAugmentSelectorHighlightedChoice;

	UPROPERTY(BlueprintAssignable)
	FOnAugmentStartedSelectionOfChoiceDelegate OnAugmentStartedSelectionOfChoice;

	UPROPERTY(BlueprintAssignable)
	FOnAugmentGrantingTimersFinishedForMatchDelegate OnAugmentGrantingTimersFinishedForMatch;

	UPROPERTY(BlueprintAssignable)
	FOnAugmentGrantingTimersResetForMatchDelegate OnAugmentGrantingTimersResetForMatch;

	UPROPERTY(BlueprintAssignable)
	FAugmentHoldInputRerollChangedDelegate AugmentHoldInputRerollChanged;

	UPROPERTY(BlueprintAssignable)
	FOnAugmentToolViewSwapDelegate OnAugmentToolViewSwap;

private:
	UPROPERTY(Transient)
	int32 NumAugmentGrantRoundsForPlaylist;

};

