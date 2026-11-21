// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "FortMatchXPRecap.generated.h"

class UEndOfMatchQuestUpdateWidget;
class UFortMatchXPTotalEntry;
class UUserWidget;
class UWidget;
enum class EUIExtensionSlot : uint8;

UCLASS(Abstract, Config=Game, meta=(DisableNativeTick))
class UFortMatchXPRecap : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void AnimateXPTotals();

	UFUNCTION()
	void HandlePostMinigameReset();

	UFUNCTION()
	void HandleToggleFullscreenMap(bool bFullscreenMapVisible);

	UFUNCTION(BlueprintPure)
	bool IsSpectating() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnReturnToIslandInputAction();

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Handle Extension Widget Created"))
	void BP_HandleExtensionWidgetCreated(UUserWidget* Widget, EUIExtensionSlot SlotType);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Post Minigame Reset"))
	void BP_HandlePostMinigameReset();

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Toggle Spectating"))
	void BP_OnToggleSpectating();

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Update Widget Visibilities"))
	void BP_UpdateWidgetVisibilities(bool bNewVisibility);

	UFUNCTION(BlueprintCallable)
	void FadeOutOverlay();

	UFUNCTION(BlueprintCallable)
	void ReturnToIslandButtonShown(bool bShown);

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortMatchXPTotalEntry> MatchXP_MedalEntry;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortMatchXPTotalEntry> MatchXP_SurvivalBonus;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortMatchXPTotalEntry> MatchXP_CombatBonus;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortMatchXPTotalEntry> MatchXP_MatchXp;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortMatchXPTotalEntry> MatchXP_ChallengeXp;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortMatchXPTotalEntry> MatchXP_TotalEntry;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortMatchXPTotalEntry> MatchCash_TotalEntry;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UEndOfMatchQuestUpdateWidget> Widget_QuestRecap;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Overlay_ChallengeSection;

	UPROPERTY(Config)
	bool bFocusDesiredTargetAtEndOfMatch;

};

