// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "UIManager/FortPrimaryContentInterface.h"
#include "AthenaMapScreenContainer.generated.h"

class UAthenaSkewedTabButton;
class UCommonButtonBase;
class UCommonButtonGroupBase;
class UCommonVisibilitySwitcher;
class UFortAutoRunNotificationWidget;
class UFortSocialAvatarIcon;
class UInputComponent;
class UPanelWidget;
class UUserWidget;

UCLASS(Abstract, Config=Game, MinimalAPI, meta=(DisableNativeTick))
class UAthenaMapScreenContainer : public UCommonActivatableWidget, public IFortPrimaryContentInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Show Tabs Set"))
	void BP_OnShowTabsSet(bool bShowTabs);

	UFUNCTION(BlueprintPure)
	bool IsQuestsTabActive() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnDamageReceived();

private:
	UPROPERTY(EditDefaultsOnly, Category="AthenaMapScreenContainer")
	FGameplayTagContainer HideWithMapTags;

	UPROPERTY(EditAnywhere, Category="AthenaMapScreenContainer")
	TArray<TSoftClassPtr<UUserWidget>> DefaultTabs;

	UPROPERTY(Config)
	TArray<FString> DisabledTabs;

	UPROPERTY(EditAnywhere, Category="AthenaMapScreenContainer")
	bool bHideTabs;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaMapScreenContainer", meta=(AllowPrivateAccess, RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle BackInputAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaMapScreenContainer", meta=(AllowPrivateAccess, RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle NextTabInputAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaMapScreenContainer", meta=(AllowPrivateAccess, RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle PreviousTabInputAction;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonVisibilitySwitcher> VisibilitySwitcher_Content;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_TouchClose;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UPanelWidget> Panel_PlayerProfile;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSocialAvatarIcon> SocialAvatarIcon;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortAutoRunNotificationWidget> Widget_AutoRunNotification;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaMapScreenContainer", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UPanelWidget> Panel_TabButtonsContainer;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaMapScreenContainer", meta=(AllowPrivateAccess="TRUE"))
	TSubclassOf<UAthenaSkewedTabButton> TabButtonClass;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UInputComponent> MapPanelInputComp;

	UPROPERTY(Transient)
	TObjectPtr<UCommonButtonGroupBase> VisibleTabButtonGroup;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TMap<FName, TObjectPtr<UCommonButtonBase>> AllTabIDsToTabButtons;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TMap<FName, TObjectPtr<UCommonButtonBase>> VisibleTabIDsToTabButtons;

};

