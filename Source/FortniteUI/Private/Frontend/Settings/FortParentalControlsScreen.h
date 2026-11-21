// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortParentalControlsScreen.generated.h"

class UCommonActivatableWidgetSwitcher;
class UCommonButtonLegacy;
class UFortParentalControlsUpdatedBase;
class UFortParentalControls_AskToEnableControls;
class UFortParentalControls_AskToReEnable;
class UFortParentalControls_CabinModeEmailSubScreen;
class UFortParentalControls_DisableParentalControls;
class UFortParentalControls_DisplaySettings;
class UFortParentalControls_EnterPin;
class UFortParentalControls_Renabling;
class UFortParentalControls_SetupEmail;
class UFortParentalControls_SetupPin;
class UFortParentalControls_VerifyEmail;
class UFortSettingDetailView;
class UFortSidebarOnboardTooltipWidget;
class UOverlay;
enum class EParentalControlsViewState : uint8;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortParentalControls : public UFortActivatablePanel
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnExitActionChange(bool bIsExitAction);

	UFUNCTION(BlueprintImplementableEvent)
	void OnNewSubScreenSet(EParentalControlsViewState ScreenState);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortParentalControls", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_CloseScreen;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortParentalControls", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_CloseTouch;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortParentalControls", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonActivatableWidgetSwitcher> Switcher_SubViews;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortParentalControls", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortParentalControls_EnterPin> SubView_EnterPin;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortParentalControls", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortParentalControls_SetupPin> SubView_SetupPin;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortParentalControls", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortParentalControls_AskToEnableControls> SubView_AskToEnableControls;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortParentalControls", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortParentalControls_VerifyEmail> SubView_VerifyEmail;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortParentalControls", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortParentalControls_SetupEmail> SubView_SetupEmail;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortParentalControls", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortParentalControls_DisplaySettings> SubView_DisplaySettings;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortParentalControls", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortParentalControls_DisableParentalControls> SubView_DisableParentalControls;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortParentalControls", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortParentalControls_AskToReEnable> SubView_AskToReEnable;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortParentalControls", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortParentalControls_Renabling> SubView_Renabling;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortParentalControls", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortParentalControls_CabinModeEmailSubScreen> SubView_CabinModeEmailChange;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortParentalControls", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSettingDetailView> Details_Settings;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortParentalControls", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_SavingSettings;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortParentalControls", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortParentalControlsUpdatedBase> UpdateNotice;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortParentalControls", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortSidebarOnboardTooltipWidget> ContentRatingTooltip;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortParentalControls", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortSidebarOnboardTooltipWidget> UnlockedContentTooltip;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortParentalControls", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortSidebarOnboardTooltipWidget> CreativeUnlockTooltip;

};

