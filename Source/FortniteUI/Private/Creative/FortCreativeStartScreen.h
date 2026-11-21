// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "FortCreativeStartScreen.generated.h"

class AActor;
class AFortMinigame;
class AFortPlayerControllerAthena;
class UCommonButtonBase;
class UFortCreativeMiniGameInfo;
class UFortHoldableButton;
class UInputComponent;
class UWidgetAnimation;
enum class EFortMinigameState : uint8;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCreativeStartScreen : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	static bool IsNewCreativeStartScreenEnabled();

private:
	UFUNCTION()
	void HandleFullScreenMapToggled(bool bMapVisible);

	UFUNCTION()
	void HandleInGameLoadScreenChanged(AFortPlayerControllerAthena* PlayerController, bool bEnableLoadScreen, FText HUDReasonText);

	UFUNCTION()
	void HandleMinigameStateChanged(AFortMinigame* Minigame, EFortMinigameState MinigameState);

	UFUNCTION()
	void HandleVolumeMinigameChanged(AFortMinigame* Minigame);

	UPROPERTY()
	AFortMinigame* CurrentMinigame;

	UPROPERTY()
	AActor* CurrentContainer;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UInputComponent> IgnoreToggleInventoryInputComponent;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeStartScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortCreativeMiniGameInfo> MinigameInfo;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeStartScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortHoldableButton> HoldableButton_Start;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeStartScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_MoreInfo;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortCreativeStartScreen", meta=(AllowPrivateAccess="TRUE", BindWidgetAnimOptional))
	TObjectPtr<UWidgetAnimation> BoundAnim_StartGame;

	UPROPERTY(EditDefaultsOnly, Category="Start Screen")
	float AutoStartTimerPeriod;

};

