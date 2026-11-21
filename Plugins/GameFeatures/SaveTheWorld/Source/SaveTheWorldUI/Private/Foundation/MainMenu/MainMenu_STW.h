// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Engine/DataTable.h"
#include "MainMenu_STW.generated.h"

class UBackgroundBlur;
class UBorder;
class UCommonActivatableWidget;
class UCommonButtonBase;
class UCommonTextBlock;
class UCommonUserWidget;
class UFortCampaignTabsScreenBase;
class UFortOptionsMenu;

UCLASS(Abstract, MinimalAPI, meta=(DisableNativeTick))
class UMainMenu_STW : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	bool IsActiveTabMainShop() const;

	UFUNCTION(BlueprintPure)
	bool ShouldShowLeaveExperienceButton() const;

	UFUNCTION(BlueprintCallable)
	void TryShowModal(UPARAM(ref) TSoftClassPtr<UCommonActivatableWidget>& ModalWidgetClass);

	UFUNCTION(BlueprintCallable)
	void TryShowPrimaryContent(UPARAM(ref) TSoftClassPtr<UCommonActivatableWidget>& ContentWidgetClass);

	UPROPERTY(BlueprintReadOnly, Category="MainMenu_STW")
	FText DefaultHelpText;

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_CountDownTimer;

	UPROPERTY(BlueprintReadOnly, Export, Category="MainMenu_STW", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_LeaveExperience;

	UPROPERTY(BlueprintReadOnly, Export, Category="MainMenu_STW", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonUserWidget> Button_Leave;

	UPROPERTY(BlueprintReadOnly, Export, Category="MainMenu_STW", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> ContextualHelpText;

	UPROPERTY(BlueprintReadOnly, Export, Category="MainMenu_STW", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_BackBoard;

	UPROPERTY(BlueprintReadOnly, Export, Category="MainMenu_STW", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	UBackgroundBlur* BackgroundBlur;

	UPROPERTY(BlueprintReadOnly, Export, Category="MainMenu_STW", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	UBorder* BackgroundDarkener;

	UPROPERTY(BlueprintReadOnly, Export, Category="MainMenu_STW", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_ReportPlayer;

	UPROPERTY(BlueprintReadOnly, Export, Category="MainMenu_STW", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Logout;

	UPROPERTY(BlueprintReadOnly, Export, Category="MainMenu_STW", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Support;

	UPROPERTY(BlueprintReadOnly, Export, Category="MainMenu_STW", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Exit;

	UPROPERTY(BlueprintReadOnly, Export, Category="MainMenu_STW", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Settings;

	UPROPERTY(EditDefaultsOnly, Category="MainMenu_STW", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle CloseMenuAction;

	UPROPERTY(EditDefaultsOnly, Category="MainMenu_STW", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle SwitchProfileAction;

	UPROPERTY(EditDefaultsOnly, Category="MainMenu_STW")
	TSubclassOf<UFortOptionsMenu> SettingsScreenClass;

	UPROPERTY(EditDefaultsOnly, Category="MainMenu_STW")
	FText LogoutTitle;

	UPROPERTY(EditDefaultsOnly, Category="MainMenu_STW")
	FText LogoutDescription;

	UPROPERTY(EditDefaultsOnly, Category="MainMenu_STW")
	FText ExitTitle;

	UPROPERTY(EditDefaultsOnly, Category="MainMenu_STW")
	FText ExitDescription;

	UPROPERTY(BlueprintReadWrite, Category="MainMenu_STW", meta=(AllowPrivateAccess))
	bool bIsMainMenuOpen;

	UPROPERTY(Export, meta=(EditInline="true"))
	UFortCampaignTabsScreenBase* MainTabsScreen;

};

