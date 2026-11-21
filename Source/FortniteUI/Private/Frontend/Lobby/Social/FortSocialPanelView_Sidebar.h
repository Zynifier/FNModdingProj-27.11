// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Types/SlateEnums.h"
#include "FortSocialPanelView_Sidebar.generated.h"

class UCommonActivatableWidget;
class UCommonVisibilitySwitcher;
class UFortSidebarButtons;
class UFortSidebarCollectionScreenContainerEditTags;
class UFortSidebarExitPopup;
class UFortSidebarOnboardTooltipWidget;
class UFortSidebarPanelFindFriends;
class URebootRallyQRModalWidget;
class USocialActionMenu;
class UWidget;

UENUM(BlueprintType)
enum class ESidebarState : uint8
{
	TabButtons = 0,
	UserListPanels = 1,
	ExitPopup = 2,
};

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortSocialPanelView_Sidebar : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	UWidget* TryNavigateToNewPanel();

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSocialPanelView_Sidebar", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSidebarButtons> Panel_SidebarButtons;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSocialPanelView_Sidebar", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonVisibilitySwitcher> Switcher_UserLists;

private:
	UFUNCTION()
	UWidget* HandleSidebarTabButtonNavigateRight(const EUINavigation InNavigation);

	UFUNCTION()
	UWidget* HandleSidebarUserListPanelNavigateLeft(const EUINavigation InNavigation);

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonActivatableWidget> Panel_PartyUp;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSidebarPanelFindFriends> Panel_FindFriends;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonActivatableWidget> Panel_VoiceChat;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonActivatableWidget> Panel_Settings;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonActivatableWidget> Panel_YourProfile;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonActivatableWidget> Panel_Tags;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonActivatableWidget> Panel_RebootRally;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonActivatableWidget> Panel_Exit;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSidebarExitPopup> Popup_Exit;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonActivatableWidget> Panel_EditProfile;

	UPROPERTY(Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UCommonActivatableWidget>> ExtensionPanels;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortSidebarOnboardTooltipWidget> SidebarOnboardingTagsEditTooltip;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortSidebarOnboardTooltipWidget> SidebarOnboardingLookingForParty;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortSidebarOnboardTooltipWidget> SidebarOnboardingLikeIsland;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	UFortSidebarOnboardTooltipWidget* SiderbarSupervisedSettingsTooltip;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	UWidget* OnboardingTooltip_InputBlocker;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<USocialActionMenu> ActiveActionMenu;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TMap<TSubclassOf<USocialActionMenu>, TObjectPtr<USocialActionMenu>> MapCachedActionMenuPool;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Utilities", meta=(AllowPrivateAccess))
	TSubclassOf<UFortSidebarCollectionScreenContainerEditTags> CollectionScreenEditTagsClass;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Utilities", meta=(AllowPrivateAccess))
	TSubclassOf<URebootRallyQRModalWidget> RebootRallyQRModalClass;

};

