// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Frontend/TopBar/FortBladeMenu.h"
#include "FortBladeMenu_MainMenu.generated.h"

class UCommonActivatableWidget;
class UCommonButtonBase;
class UCommonButtonLegacy;
class UCommonTextBlock;
class UFortMainMenuButton;
class UFortMinigameButtons;
class UFortOptionsMenu;
class URestrictedCountryRatingIcons;
class UUserWidget;
class UVerticalBox;
class UWidgetSwitcher;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortBladeMenu_MainMenu : public UFortBladeMenu
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void FakeSidebarBackButtonClick();

	UPROPERTY(BlueprintReadOnly, Export, Category="FortBladeMenu_MainMenu", meta=(BindWidgetOptional, EditInline="true"))
	UCommonButtonBase* SidebarBackButton;

protected:
	UFUNCTION(BlueprintCallable)
	bool IsInCreative();

	UFUNCTION(BlueprintCallable)
	void RefreshFocus();

	UFUNCTION(BlueprintCallable)
	void ReleaseSavedMenuPosition();

	UFUNCTION(BlueprintCallable)
	void ShowConsoleWindow();

	UFUNCTION(BlueprintCallable)
	void TryPushWidgetAsActivatablePanel(UUserWidget* InWidget, bool bHideHeader, bool bHideFooter, bool bHideChatWidget);

	UFUNCTION(BlueprintCallable)
	void TryPushWidgetAsModalPanel(UUserWidget* InWidget);

	UFUNCTION(BlueprintCallable)
	void ViewPurchaseHistory();

private:
	UFUNCTION()
	void HandleMatchmakingFlowChanged(bool bFlowActive);

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortMainMenuButton> Button_Squeegee;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortBladeMenu_MainMenu", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_BackToHub;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Settings;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortBladeMenu_MainMenu", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Subscription;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_MobileBack;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_SubgameSelection;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_LeaveExperience;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_BackToHubDisabledReason;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortBladeMenu_MainMenu", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Store;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortBladeMenu_MainMenu", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Locker;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortBladeMenu_MainMenu", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_CodeOfConduct;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortBladeMenu_MainMenu", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Support;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortBladeMenu_MainMenu", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortMinigameButtons> MinigameButtons;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<URestrictedCountryRatingIcons> RatingIcons_RatingIcons;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UVerticalBox> VerticalBox_ExtensionContainer;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortBladeMenu_MainMenu", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	UWidgetSwitcher* Switcher_Menus;

	UPROPERTY(EditDefaultsOnly, Category="FortBladeMenu_MainMenu")
	TSoftClassPtr<UCommonActivatableWidget> ExternalLinkPopupClass;

	UPROPERTY(EditDefaultsOnly, Category="FortBladeMenu_MainMenu")
	TSoftClassPtr<UFortOptionsMenu> OptionsMenuClass;

};

