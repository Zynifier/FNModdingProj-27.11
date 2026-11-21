// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Frontend/Lobby/Social/FortSocialSidebarPanelInterface.h"
#include "SocialInteractionMenu.h"
#include "FortSocialProfilePanel.generated.h"

class UCommonButtonBase;
class UFortSocialProfileSubPanel;
class UFortSocialProfileSubPanel_Loading;
class UScrollBox;
class UWidget;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortSocialProfilePanel : public USocialActionMenu, public IFortSocialSidebarPanelInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnFinishedProfileLoading();

	UFUNCTION(BlueprintImplementableEvent)
	void OnStartProfileLoading();

private:
	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortSocialProfileSubPanel> SubPanelIdentity;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortSocialProfileSubPanel> SubPanelRegion;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortSocialProfileSubPanel> SubPanelTags;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortSocialProfileSubPanel> SubPanelPresence;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortSocialProfileSubPanel> SubPanelActions;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortSocialProfileSubPanel> SubPanelMutualFriends;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortSocialProfileSubPanel> SubPanelMutualFriendsCount;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortSocialProfileSubPanel> SubPanelRebootRallyText;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> SidebarBackButton;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UScrollBox> ScrollBox_ScrollablePanels;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortSocialProfileSubPanel : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	UWidget* GetDesiredFocusTarget() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnFinishedProfileLoading();

	UFUNCTION(BlueprintImplementableEvent)
	void OnStartProfileLoading();

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortSocialProfileSubPanel_Loading> SubPanel_Loading;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortSocialProfileSubPanel_Loading : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnLoadingFinished();

	UFUNCTION(BlueprintImplementableEvent)
	void OnLoadingStarted();

};

