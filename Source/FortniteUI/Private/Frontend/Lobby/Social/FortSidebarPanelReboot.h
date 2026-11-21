// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Frontend/Lobby/Social/FortSidebarPanelWithTree.h"
#include "FortSidebarPanelReboot.generated.h"

class UCommonActivatableWidget;
class UCommonButtonBase;
class UFortSidebarOnboardTooltipWidget;
class UFortSidebarPanelRebootHeader;
class UFortSocialUserTreeView;
class URebootRallyTimerBase;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortSidebarPanelReboot : public UFortSidebarPanelWithTree
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnRebootRallyEligibilityUpdated(bool bEligible);

protected:
	UFUNCTION(BlueprintCallable)
	void ShowMissingFriendsModal();

private:
	UPROPERTY(EditAnywhere, Category="FortSidebarPanelReboot")
	TSoftClassPtr<UCommonActivatableWidget> SoftMissingFriendsModalClass;

	UPROPERTY(Export, meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> SidebarBackButton;

	UPROPERTY(Export, meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortSidebarPanelRebootHeader> Header;

	UPROPERTY(Export, meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	URebootRallyTimerBase* WBP_RebootRallyTimer;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSocialUserTreeView> UserTree_RebootRally;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortSidebarOnboardTooltipWidget> RebootRallyTooltip;

};

