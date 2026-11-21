// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Engine/HitResult.h"
#include "GameplayTagContainer.h"
#include "Athena/AthenaHUDBase.h"
#include "FortUIExtension.h"
#include "AthenaBroadcastHUDBase.generated.h"

class AActor;
class AFortGameState;
class AFortGameStateAthena;
class AFortMinigame;
class UAthenaBroadcastMapPanelBase;
class UAthenaReplayActionFeedScreenBase;
class UAthenaSpectatorHUDControlsBase;
class UAthenaSpectatorNameplateLayerBase;
class UCommonActivatableWidgetStack;
class UCommonWidgetSwitcherLegacy;
class UFortBroadcastViewSettings;
class UFortPlaylistAthena;
class UFortReplayGoToTimeDialogue;
class UFortReplayHighlightsWindow;
class UPrimitiveComponent;
class USpacer;
class UUserWidget;
enum class EHudVisibilityState : uint8;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaBroadcastHUDBase : public UAthenaHUDBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void HandleFollowedPlayerRespawnTimeChanged(float RespawnTime);

	UFUNCTION()
	void OnCursorModeChanging(bool bCursorModeEnabled, FName ActionName);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Game State Set"))
	void OnGameStateSet_BP(AFortGameStateAthena* GameStateAthena);

	UFUNCTION(BlueprintImplementableEvent)
	void OnHudVisibilityChanged(EHudVisibilityState NewVisibility);

	UFUNCTION(BlueprintImplementableEvent)
	void OnIndicatorModeChanged(bool bIndicatorsEnabled);

	UFUNCTION(BlueprintImplementableEvent)
	void OnMinigameChanged(AFortMinigame* NewMinigame);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPipModeChanged(bool bEnabled);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPlayerTargetingChanged(bool bIsTargeting);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPlaylistDataChanged(const UFortPlaylistAthena* PlaylistData);

	UFUNCTION(BlueprintImplementableEvent)
	void OnToggleFollowedPlayerInfoActionExecuted(bool& bPassthrough);

	UFUNCTION(BlueprintImplementableEvent)
	void OnToggleMatchStatusActionExecuted(bool& bPassthrough);

	UFUNCTION(BlueprintImplementableEvent)
	void OnToggleRemainingPlayersActionExecuted(bool& bPassthrough);

	UFUNCTION(BlueprintImplementableEvent)
	void OnToggleSquadStatusActionExecuted(bool& bPassthrough);

	UFUNCTION(BlueprintImplementableEvent)
	void OnUnableToPerformAction(FGameplayTagContainer FailedReason, const FText& FailureText);

	UFUNCTION(BlueprintImplementableEvent)
	void SetFullscreenMapVisibility(bool bIsVisible);

private:
	UFUNCTION()
	void HandleHudVisibilityChanged(EHudVisibilityState NewVisibility);

	UFUNCTION()
	void HandleNameplatesEnabledChanged(bool bInNameplatesEnabled);

	UFUNCTION()
	void HandleSpectatorViewTargetChanged();

	UFUNCTION()
	void HandleToggleActionFeedScreen();

	UFUNCTION()
	void HandleToggleGoToTime();

	UFUNCTION()
	void HandleToggleHighlightsList();

	UFUNCTION()
	void HandleToggleReplayViewSettings();

	UFUNCTION()
	void OnCurrentPlaylistChanged();

	UFUNCTION()
	void OnGameStateSet(AFortGameState* NewGameState);

	UFUNCTION()
	void OnToggleActiveGridScreenActionExecuted(bool& bPassthrough);

	UFUNCTION()
	void OnToggleEliminatedGridScreenActionExecuted(bool& bPassthrough);

	UFUNCTION()
	void OnToggleKillFeedActionExecuted(bool& bPassthrough);

	UFUNCTION()
	void OnToggleMatchStatusScreenActionExecuted(bool& bPassthrough);

	UFUNCTION()
	void OnTogglePipModeActionExecuted(bool& bPassthrough);

	UFUNCTION()
	void OnToggleScoreboardScreenActionExecuted(bool& bPassthrough);

	UFUNCTION()
	void OnVolumeBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnVolumeEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
	void OnVolumeMinigameChanged(AFortMinigame* Minigame);

	UFUNCTION()
	void TryHandleIfPlayerStateAlreadyInVolume();

	UPROPERTY(EditDefaultsOnly, Category="AthenaBroadcastHUDBase", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle ToggleMatchStatusActionRowHandle;

	UPROPERTY(EditDefaultsOnly, Category="AthenaBroadcastHUDBase", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle ToggleSquadStatusActionRowHandle;

	UPROPERTY(EditDefaultsOnly, Category="AthenaBroadcastHUDBase", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle ToggleRemainingPlayersActionRowHandle;

	UPROPERTY(EditDefaultsOnly, Category="AthenaBroadcastHUDBase", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle ToggleActiveGridScreenActionRowHandle;

	UPROPERTY(EditDefaultsOnly, Category="AthenaBroadcastHUDBase", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle ToggleEliminatedGridScreenActionRowHandle;

	UPROPERTY(EditDefaultsOnly, Category="AthenaBroadcastHUDBase", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle ToggleMatchStatusScreenActionRowHandle;

	UPROPERTY(EditDefaultsOnly, Category="AthenaBroadcastHUDBase", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle ToggleScoreboardScreenActionRowHandle;

	UPROPERTY(EditDefaultsOnly, Category="AthenaBroadcastHUDBase", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle ToggleKillFeedActionRowHandle;

	UPROPERTY(EditDefaultsOnly, Category="AthenaBroadcastHUDBase", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle ToggleActionFeedScreenActionRowHandle;

	UPROPERTY(EditDefaultsOnly, Category="AthenaBroadcastHUDBase", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle ToggleGotoTimeRowHandle;

	UPROPERTY(EditDefaultsOnly, Category="AthenaBroadcastHUDBase", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle TogglePipModeActionRowHandle;

	UPROPERTY(EditDefaultsOnly, Category="AthenaBroadcastHUDBase", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle ToggleFollowedPlayerInfoActionRowHandle;

	UPROPERTY(EditDefaultsOnly, Category="AthenaBroadcastHUDBase", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle ToggleFullscreenMapActionRowHandle;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	TMap<TSoftClassPtr<UUserWidget>, FUIExtension> ExtensionWidgetOverrides;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaBroadcastHUDBase", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UAthenaSpectatorHUDControlsBase> BroadcastHUDControls;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonActivatableWidgetStack> WidgetStack_SpectatorPrimaryContent;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaBroadcastHUDBase", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UAthenaSpectatorNameplateLayerBase> NameplateLayer;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaBroadcastMapPanelBase> AthenaBroadcastMapPanel;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonWidgetSwitcherLegacy> EventMatchInfoSwitcher;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonWidgetSwitcherLegacy> Switcher_TopLeft;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<USpacer> TopLeft_Empty;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortBroadcastViewSettings> TopLeft_ViewSettings;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaReplayActionFeedScreenBase> TopLeft_ActionFeed;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortReplayGoToTimeDialogue> TopLeft_GoToTime;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortReplayHighlightsWindow> TopLeft_Highlights;

};

