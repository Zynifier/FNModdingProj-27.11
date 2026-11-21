// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortTutorialLobbyPopup.generated.h"

class UFortPlaylistAthena;
class UWidgetSwitcher;

UCLASS(meta=(DisableNativeTick))
class UFortTutorialLobbyPopup : public UFortActivatablePanel
{
	GENERATED_BODY()

private:
	UFUNCTION(BlueprintCallable)
	void SkipTutorial();

	UFUNCTION(BlueprintCallable)
	void StartTutorial();

	UPROPERTY(EditAnywhere, Category="FortTutorialLobbyPopup")
	TObjectPtr<UFortPlaylistAthena> TutorialPlaylistData;

	UPROPERTY(EditAnywhere, Category="FortTutorialLobbyPopup")
	TObjectPtr<UFortPlaylistAthena> Tutorial_DefensiveBuildingPlaylistData;

	UPROPERTY(EditAnywhere, Category="FortTutorialLobbyPopup")
	TObjectPtr<UFortPlaylistAthena> SoloPlaylistData;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortTutorialLobbyPopup", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UWidgetSwitcher> WidgetSwitcher_PopupTutorial;

};

