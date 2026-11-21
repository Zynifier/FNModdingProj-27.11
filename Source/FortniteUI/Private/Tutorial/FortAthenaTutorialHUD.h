// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "GameplayTagContainer.h"
#include "FortAthenaTutorialHUD.generated.h"

class AActor;
class AFortAthenaTutorialManager;
class UCommonButtonLegacy;
class UFortAthenaTutorialProgressBar;
class UFortAthenaTutorialScreen;
class UFortAthenaTutorialTargetCounter;
class UFortAthenaTutorialTextPrompt;
class UOverlay;
class UUserWidget;

UCLASS(meta=(DisableNativeTick))
class UFortAthenaTutorialHUD : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void BroadcastSkipMenuOpened();

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void CompletedEnabled();

	UFUNCTION(BlueprintImplementableEvent)
	void DragToTurnEnabled();

	UFUNCTION(BlueprintImplementableEvent)
	void PlayFingerPointingAnimation();

private:
	UPROPERTY()
	TArray<FGameplayTag> HighlightTagArray;

	UPROPERTY()
	TObjectPtr<AFortAthenaTutorialManager> TutorialManager;

	UPROPERTY(Transient)
	TObjectPtr<AActor> CurrentTrackedActor;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortAthenaTutorialHUD", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_TutorialScreen;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortAthenaTutorialHUD", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Athena_Tutorial_Skip_Mobile;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortAthenaTutorialHUD", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UFortAthenaTutorialTargetCounter> Athena_Tutorial_TargetCounter;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortAthenaTutorialHUD", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UFortAthenaTutorialProgressBar> Athena_Tutorial_ProgressBar;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortAthenaTutorialHUD", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UFortAthenaTutorialScreen> Athena_Tutorial_ModalPopup;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortAthenaTutorialHUD", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UFortAthenaTutorialTextPrompt> TextPrompt_Tutorial;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortAthenaTutorialHUD", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_Finger;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortAthenaTutorialHUD", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_Gradient;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortAthenaTutorialHUD", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UUserWidget> Widget_EasyInteractFinger;

};

