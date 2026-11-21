// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "UIManager/FortPrimaryContentInterface.h"
#include "FortActivityBrowser.generated.h"

class UCommonActivatableWidget;
class UCommonActivatableWidgetSwitcher;
class UCommonButtonBase;
class UFortActivityBrowserAttributionsModal;
class UFortActivityBrowserColorSchemeAsset;
class UFortActivityBrowserPlayWithFriendsTile;
class UFortActivityCategoryPageView;
class UFortActivityCreatorPageView;
class UFortActivityDetailsModal;
class UFortActivityModeSetSelectionModalBase;
class UFortCampaignPurchaseScreen;
class UFortCreativeDiscoverySurfaceManager;
class UFortGameActivity;
class UFortTabButton;
class UFortTabListWidgetBase_Legacy;
enum class EPlayerQueueType : uint8;

UCLASS(Abstract, Config=Game, meta=(DisableNativeTick))
class UFortActivityBrowser : public UCommonActivatableWidget, public IFortPrimaryContentInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnActivitySelected();

	UFUNCTION(BlueprintImplementableEvent)
	void OnEnableColorScheme(const bool bIsColorSchemeActive);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPlayerQueueTypeChanged(const EPlayerQueueType PlayerQueueType);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSwapColorScheme(const bool bInIsUsingAlternateColorScheme);

private:
	UFUNCTION()
	void HandleTabChanged(FName TabId);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortActivityBrowser", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonActivatableWidgetSwitcher> Switcher_TabActivityBrowserViews;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Back;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_ShowCustomMatchmakingModal;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortActivityBrowser", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_BackToTop;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_MobileShowGameDetails;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_MobileAccept;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_CloseTouch;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortActivityBrowser", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_JoinAsSpectator;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_ShowSpectateMatchModal;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortActivityBrowser", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortTabListWidgetBase_Legacy> TabList_BrowserTabs;

	UPROPERTY(EditDefaultsOnly, Category="FortActivityBrowser")
	FPrimaryContentSetup PrimaryContentSetup;

	UPROPERTY(EditDefaultsOnly, Category="FortActivityBrowser")
	TSubclassOf<UFortTabButton> TabButtonClass;

	UPROPERTY(EditDefaultsOnly, Category="FortActivityBrowser")
	TSubclassOf<UFortActivityDetailsModal> ActivityDetailsModalClass;

	UPROPERTY(EditDefaultsOnly, Category="FortActivityBrowser")
	TSubclassOf<UFortActivityModeSetSelectionModalBase> ActivityModeSetSelectionModalClass;

	UPROPERTY(EditDefaultsOnly, Category="FortActivityBrowser")
	TSubclassOf<UCommonActivatableWidget> ActivityModeSetFirstTimeNotificationModalClass;

	UPROPERTY(EditDefaultsOnly, Category="FortActivityBrowser")
	TSubclassOf<UFortActivityBrowserAttributionsModal> AttributionsModalClass;

	UPROPERTY(EditDefaultsOnly, Category="FortActivityBrowser")
	TSubclassOf<UFortActivityCreatorPageView> CreatorPageViewClass;

	UPROPERTY(EditDefaultsOnly, Category="FortActivityBrowser")
	TSubclassOf<UFortActivityCategoryPageView> CategoryPageViewClass;

	UPROPERTY(EditDefaultsOnly, Category="FortActivityBrowser")
	TSoftClassPtr<UCommonActivatableWidget> SoftCustomMatchmakingModalClass;

	UPROPERTY(EditDefaultsOnly, Category="FortActivityBrowser")
	TSoftClassPtr<UCommonActivatableWidget> SoftSpectateMatchModalClass;

	UPROPERTY(EditDefaultsOnly, Category="FortActivityBrowser")
	TSubclassOf<UFortCampaignPurchaseScreen> CampaignPurchaseScreenClass;

	UPROPERTY(EditDefaultsOnly, Category="FortActivityBrowser")
	TSubclassOf<UCommonActivatableWidget> CCUModalClass;

	UPROPERTY(EditDefaultsOnly, Category="FortActivityBrowser")
	TMap<FName, TObjectPtr<UFortActivityBrowserColorSchemeAsset>> ColorSchemes;

	UPROPERTY(EditDefaultsOnly, Category="FortActivityBrowser")
	FText MobileAcceptButtonBaseText;

	UPROPERTY(Transient)
	TObjectPtr<UFortCreativeDiscoverySurfaceManager> Manager;

	UPROPERTY(Transient, Export)
	TWeakObjectPtr<UFortActivityBrowserPlayWithFriendsTile> LastSelectedPlayWithFriendsTile;

	UPROPERTY(Transient)
	TObjectPtr<UFortGameActivity> SelectedGameActivity;

	UPROPERTY(Transient)
	TObjectPtr<UFortActivityBrowserColorSchemeAsset> CurrentColorScheme;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortActivityCategoryPageView> CachedCategoryPageView;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortActivityCreatorPageView> CachedCreatorPageView;

	UPROPERTY(Config)
	bool bCCUModalEnabled;

};

