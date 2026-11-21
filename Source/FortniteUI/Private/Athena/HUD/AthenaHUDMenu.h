// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "GameplayTagContainer.h"
#include "FortCombatTypes.h"
#include "AthenaHUDMenu.generated.h"

class AFortMinigame;
class UAthenaGameOverDisplay;
class UAthenaInventoryScreenContainer;
class UCommonActivatableWidgetStack;
class UCommonUserWidget;
class UFortDualBladeMenu;
class UFortPostGameScreenRoot;
class UOverlay;
class UScaleBox;
class UUserWidget;
class UWidget;
enum class EEndOfMatchReason : uint8;
enum class EFortMinigameState : uint8;

UCLASS(Abstract, Config=Game, meta=(DisableNativeTick))
class UAthenaHUDMenu : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnWidgetStackCleared();

	UFUNCTION(BlueprintCallable)
	void RecoverFromPostGame();

	UFUNCTION(BlueprintCallable)
	void SetInventoryPanelOverride(UUserWidget* InInventoryPanelOverride);

	UFUNCTION(BlueprintCallable)
	void StartPostGame();

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Post Game Ended"))
	void BP_OnPostGameEnded();

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Post Game Started"))
	void BP_OnPostGameStarted();

private:
	UFUNCTION(BlueprintCallable)
	void ClearGameOverScreen();

	UFUNCTION(BlueprintCallable)
	UAthenaGameOverDisplay* CreateOrShowGameOverScreen();

	UFUNCTION(BlueprintCallable)
	void HandleLocalPlayerDied(const FFortPlayerDeathReport& DeathReport);

	UFUNCTION()
	void HandleLocalPlayerLost(EEndOfMatchReason LostReason);

	UFUNCTION(BlueprintCallable)
	void HandleLocalPlayerOrTeamWon();

	UFUNCTION(BlueprintCallable)
	void HandleLocalPlayerRevived();

	UFUNCTION()
	void HandleMinigameStateChanged(AFortMinigame* Minigame, EFortMinigameState MinigameState);

	UFUNCTION()
	void HandleOverrideInventoryPanel(UUserWidget* Widget);

	UFUNCTION()
	void HandlePreviewScreenshotCameraActivated(bool bActivated);

	UFUNCTION()
	void HandleRecoverFromPostGame();

	UFUNCTION()
	void HandleStartPostGame();

	UFUNCTION()
	void NativeHandleCursorModeChanged(bool bCursorModeEnabled, FName ActionName, UUserWidget* CursorModeContentWidget);

	UFUNCTION()
	void PostBindCheckConditions();

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_AllContent;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortDualBladeMenu> DualBladeMenu;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaInventoryScreenContainer> InventoryScreenContainer;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaHUDMenu", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonUserWidget> BottomBar;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonActivatableWidgetStack> WidgetStack_PrimaryContent;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Container_ServerShutdownTimer;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UScaleBox> ScaleBox_LetoSplitscreen;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Container_ContentOnDemand;

	UPROPERTY(EditDefaultsOnly, Category="AthenaHUDMenu")
	FGameplayTagContainer HideOnMenuTags;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AthenaHUDMenu", meta=(AllowPrivateAccess))
	FGameplayTagContainer TagsToShow;

	UPROPERTY(EditDefaultsOnly, Category="AthenaHUDMenu")
	TSubclassOf<UAthenaGameOverDisplay> GameOverScreenClass;

	UPROPERTY(EditDefaultsOnly, Category="AthenaHUDMenu")
	TSubclassOf<UFortPostGameScreenRoot> PostGameScreenRootClass;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaHUDMenu", meta=(AllowPrivateAccess, EditInline="true"))
	TObjectPtr<UFortPostGameScreenRoot> PostGameScreenRoot;

	UPROPERTY(BlueprintReadWrite, Category="AthenaHUDMenu", meta=(AllowPrivateAccess))
	bool bShowingGameOverScreen;

	UPROPERTY(BlueprintReadWrite, Category="AthenaHUDMenu", meta=(AllowPrivateAccess))
	bool bShowingWinnerScreen;

	UPROPERTY(BlueprintReadWrite, Category="AthenaHUDMenu", meta=(AllowPrivateAccess))
	bool bStartedPostGame;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaHUDMenu", meta=(AllowPrivateAccess, EditInline="true"))
	TObjectPtr<UAthenaGameOverDisplay> GameOverScreen;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UUserWidget> InventoryPanelOverride;

};

