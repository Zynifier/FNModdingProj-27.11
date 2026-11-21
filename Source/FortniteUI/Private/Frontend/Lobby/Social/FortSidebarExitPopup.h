// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Frontend/Lobby/Social/FortSocialSidebarPanelInterface.h"
#include "FortSidebarExitPopup.generated.h"

class UCommonActivatableWidgetSwitcher;
class UCommonButtonBase;
class UCommonButtonLegacy;
class UCommonRichTextBlock;
class UCommonTextBlock;
class UFortExpressYourSupportFavoriteButton;
class UFortExpressYourSupportThumbsUpButton;
class UFortMainMenuLeaveButtonWrapper;
class UPanelWidget;
class UWidget;
class UWidgetAnimation;
enum class ESidebarExitActions : uint8;

UENUM(BlueprintType)
enum class ESidebarExitActions : uint8
{
	None = 0,
	LeaveExperience = 1,
	AthenaLeaveAction = 2,
	LogOut = 3,
	QuitGame = 4,
};

UENUM(BlueprintType)
enum class ESidebarExitConfirmationNavBehavior : uint8
{
	None = 0,
	ButtonYesFocus = 1,
	ButtonYesSelection = 2,
	ButtonYesFocusSelection = 3,
	ButtonNoFocus = 4,
	ButtonNoSelection = 5,
	ButtonNoFocusSelection = 6,
};

UCLASS(Abstract, Config=Game, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortSidebarExitPopup : public UCommonActivatableWidget, public IFortSocialSidebarPanelInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="FortSidebarExitPopup")
	void CancelConfirmationView();

	UFUNCTION(BlueprintCallable, Category="FortSidebarExitPopup")
	void ConfirmSelectedAction();

	UFUNCTION(BlueprintCallable, Category="FortSidebarExitPopup")
	void Hide(const bool bDoImmediately = false);

	UFUNCTION(BlueprintCallable, Category="FortSidebarExitPopup")
	void Show(const bool bTakeFocus = true);

	UFUNCTION(BlueprintCallable, Category="FortSidebarExitPopup")
	void ShowConfirmationView(const ESidebarExitActions ActionToConfirm);

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortSidebarExitPopup")
	bool bIsHidden;

protected:
	UFUNCTION()
	void HandleActiveWidgetIndexChanged(UWidget* ActiveWidget, int32 ActiveWidgetIndex);

	UFUNCTION()
	void HandleHidePopupAnimFinished();

	UFUNCTION()
	void HandleShowPopupAnimFinished();

	UFUNCTION()
	void HandleTransitioningChanged(const bool bTransitioning);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateNoEnabledButtonsText(const bool bAllowLogout, const bool bAllowQuit);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSidebarExitPopup", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UPanelWidget> PanelWidget_MainMenuButtons;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSidebarExitPopup", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UPanelWidget> PanelWidget_ExpressYourSupportButtons;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSidebarExitPopup", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortExpressYourSupportThumbsUpButton> Button_SupportCreator;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSidebarExitPopup", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortExpressYourSupportFavoriteButton> Button_Favorite;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSidebarExitPopup", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UPanelWidget> ConfirmationButtons;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSidebarExitPopup", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_LeaveExperience;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSidebarExitPopup", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortMainMenuLeaveButtonWrapper> Button_AthenaMainMenuLeave;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSidebarExitPopup", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Logout;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSidebarExitPopup", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_ExitGame;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSidebarExitPopup", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Yes;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSidebarExitPopup", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_No;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSidebarExitPopup", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ActivityName;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSidebarExitPopup", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> Text_NoEnabledButtons;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSidebarExitPopup", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonActivatableWidgetSwitcher> WidgetSwitcher;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSidebarExitPopup", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_BackBoard;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortSidebarExitPopup", meta=(BindWidgetAnimOptional))
	TObjectPtr<UWidgetAnimation> ShowPopupAnim;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortSidebarExitPopup", meta=(BindWidgetAnimOptional))
	TObjectPtr<UWidgetAnimation> HidePopupAnim;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortSidebarExitPopup")
	ESidebarExitActions SelectedAction;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortSidebarExitPopup")
	FText AthenaConfirmationMessageText;

private:
	UPROPERTY(Config)
	ESidebarExitConfirmationNavBehavior ConfirmationBtnsSelection;

};

