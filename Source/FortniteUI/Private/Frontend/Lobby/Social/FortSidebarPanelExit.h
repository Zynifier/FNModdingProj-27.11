// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Frontend/Lobby/Social/FortSocialSidebarPanelInterface.h"
#include "FortSidebarPanelExit.generated.h"

class UCommonRichTextBlock;
class UFortMainMenuButton;
class UFortMainMenuLeaveButtonWrapper;
class UPanelWidget;

UCLASS(meta=(DisableNativeTick))
class UFortSidebarPanelExit : public UCommonActivatableWidget, public IFortSocialSidebarPanelInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void HandleLeaveExperienceClicked();

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateNoEnabledButtonsText(const bool bAllowLogout, const bool bAllowQuit);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSidebarPanelExit", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UPanelWidget> PanelWidget_MainMenuButtons;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSidebarPanelExit", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortMainMenuButton> Button_LeaveExperience;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSidebarPanelExit", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortMainMenuLeaveButtonWrapper> Button_AthenaMainMenuLeave;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSidebarPanelExit", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortMainMenuButton> Button_Logout;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSidebarPanelExit", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortMainMenuButton> Button_ExitGame;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSidebarPanelExit", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> Text_NoEnabledButtons;

};

