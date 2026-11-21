// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Athena/HUD/EndGame/FortPostGameScreen.h"
#include "FortPostGameScreenRoot.generated.h"

class UFortPlaylistUIInfo;
class UFortPostGameNewQuestsWidget;
class UFortPostGameScreen;
class UFortPostGameScreenContainer;
class UOverlay;
class UPostGamePlacementOverlay;
class UScaleBox;
class USoundCue;
class USpacer;
class UUserWidget;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortPostGameScreenRoot : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void AnimateCinematicBars();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPostGameScreenConfigUpdated(const FFortPostGameScreenConfig& NewPostGameConfig);

	UFUNCTION(BlueprintImplementableEvent)
	void SetPlacementZOrder(const bool bIsPlacementAboveContent);

	UFUNCTION(BlueprintImplementableEvent)
	void ToggleBlur();

private:
	UFUNCTION()
	void HandleRecoverFromPostGame();

	UFUNCTION()
	void HandleXPScreenFinished();

	UPROPERTY(EditAnywhere, Category="Preview")
	TObjectPtr<UFortPlaylistUIInfo> PreviewPlaylistUIInfo;

	UPROPERTY(EditAnywhere, Category="Defaults")
	TObjectPtr<UFortPlaylistUIInfo> DefaultScreenOrder;

	UPROPERTY(Transient)
	TArray<TSubclassOf<UUserWidget>> PostGameScreenClassesToCreate;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFortPostGameScreen>> PostGameScreens;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<USpacer> Spacer_ClickCatcher;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortPostGameScreenRoot", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_Placement;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortPostGameScreenContainer> PostGameScreenContainer_Main;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortPostGameScreenRoot", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UUserWidget> HUD_CinematicBars;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UScaleBox> ScaleBox_CinematicBars_UserSpecified;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UScaleBox> ScaleBox_PlacementOverlay_UserSpecified;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortPostGameNewQuestsWidget> HUD_NewQuestsWidget;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UPostGamePlacementOverlay> DefaultPlacementOverlay;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UPostGamePlacementOverlay> OverridePlacementOverlay;

	UPROPERTY(Transient)
	TObjectPtr<USoundCue> DefaultVictoryStingerCue;

	UPROPERTY(Transient)
	TObjectPtr<USoundCue> OverrideVictoryStingerCue;

};

