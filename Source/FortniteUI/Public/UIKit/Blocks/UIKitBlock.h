// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UIKitBlock.generated.h"

class UWidgetAnimation;
enum class EUIKitBlockInstantTransitionState : uint8;
enum class EUIKitBlockVisualState : uint8;

UENUM(BlueprintType)
enum class EUIKitBlockInstantTransitionState : uint8
{
	Invalid = 0,
	InstantEnabled = 1,
	InstantDisabled = 2,
	InstantSelected = 3,
	InstantDeselected = 4,
	InstantLocked = 5,
	InstantUnlocked = 6,
};

UENUM(BlueprintType)
enum class EUIKitBlockVisualState : uint8
{
	Invalid = 0,
	Hovered = 1,
	Unhovered = 2,
	Focused = 3,
	Unfocused = 4,
	Pressed = 5,
	Released = 6,
	Disabled = 7,
	Enabled = 8,
	Selected = 9,
	DeselectedIdle = 10,
	DeselectedFocused = 11,
};

USTRUCT(BlueprintType)
struct FUIKitBlockTiming
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UIKitBlockTiming")
	float Hovering;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UIKitBlockTiming")
	float Unhovering;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UIKitBlockTiming")
	float Focusing;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UIKitBlockTiming")
	float Unfocusing;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UIKitBlockTiming")
	float Pressing;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UIKitBlockTiming")
	float Releasing;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UIKitBlockTiming")
	float Disabling;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UIKitBlockTiming")
	float Enabling;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UIKitBlockTiming")
	float Selecting;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UIKitBlockTiming")
	float DeselectingIdle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UIKitBlockTiming")
	float DeselectingFocused;

};

UCLASS(Abstract, meta=(DisableNativeTick))
class UUIKitBlock : public UUserWidget
{
	GENERATED_BODY()

public:
	UUIKitBlock(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintPure, Category="UI Kit Block|Animation")
	float GetTransitionTime(EUIKitBlockVisualState State);

	UFUNCTION(BlueprintCallable, Category="UI Kit Block|Animation")
	void PlayTransition(UWidgetAnimation* Animation, const bool bPlayForward = true);

	UFUNCTION(BlueprintCallable, Category="UI Kit Block|Animation")
	void RequestInstantTransition(EUIKitBlockInstantTransitionState State);

	UFUNCTION(BlueprintCallable, Category="UI Kit Block|Animation")
	void RequestTransition(EUIKitBlockVisualState State);

	UFUNCTION(BlueprintCallable, Category="UI Kit Block|Animation")
	void SetBlockTiming(const FUIKitBlockTiming& Timing);

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="UI Kit Block|Animation")
	void OnInstantTransitionToDeselected();

	UFUNCTION(BlueprintImplementableEvent, Category="UI Kit Block|Animation")
	void OnInstantTransitionToDisabled();

	UFUNCTION(BlueprintImplementableEvent, Category="UI Kit Block|Animation")
	void OnInstantTransitionToEnabled();

	UFUNCTION(BlueprintImplementableEvent, Category="UI Kit Block|Animation")
	void OnInstantTransitionToLocked();

	UFUNCTION(BlueprintImplementableEvent, Category="UI Kit Block|Animation")
	void OnInstantTransitionToSelected();

	UFUNCTION(BlueprintImplementableEvent, Category="UI Kit Block|Animation")
	void OnInstantTransitionToUnlocked();

	UFUNCTION(BlueprintImplementableEvent, Category="UI Kit Block|Animation")
	void OnTransitionDeselectedFocusedRequested();

	UFUNCTION(BlueprintImplementableEvent, Category="UI Kit Block|Animation")
	void OnTransitionDeselectedIdleRequested();

	UFUNCTION(BlueprintImplementableEvent, Category="UI Kit Block|Animation")
	void OnTransitionDisabledRequested();

	UFUNCTION(BlueprintImplementableEvent, Category="UI Kit Block|Animation")
	void OnTransitionEnabledRequested();

	UFUNCTION(BlueprintImplementableEvent, Category="UI Kit Block|Animation")
	void OnTransitionFocusedRequested();

	UFUNCTION(BlueprintImplementableEvent, Category="UI Kit Block|Animation")
	void OnTransitionHoveredRequested();

	UFUNCTION(BlueprintImplementableEvent, Category="UI Kit Block|Animation")
	void OnTransitionPressedRequested();

	UFUNCTION(BlueprintImplementableEvent, Category="UI Kit Block|Animation")
	void OnTransitionReleasedRequested();

	UFUNCTION(BlueprintImplementableEvent, Category="UI Kit Block|Animation")
	void OnTransitionSelectedRequested();

	UFUNCTION(BlueprintImplementableEvent, Category="UI Kit Block|Animation")
	void OnTransitionUnfocusedRequested();

	UFUNCTION(BlueprintImplementableEvent, Category="UI Kit Block|Animation")
	void OnTransitionUnhoveredRequested();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI Kit Block|Animation")
	FUIKitBlockTiming TransitionTiming;

};

