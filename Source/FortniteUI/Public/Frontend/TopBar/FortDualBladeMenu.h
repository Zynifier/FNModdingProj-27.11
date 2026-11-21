// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Engine/DataTable.h"
#include "UITag.h"
#include "FortDualBladeMenu.generated.h"

class UCommonButtonBase;
class UFortBladeMenu;
class UFortSeasonDataWidget;
class UFortSocialPanelView_Sidebar;
class UNamedSlot;
class UWidget;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortDualBladeMenu : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnFullScreenWidgetCreated(UWidget* NewWidget);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortDualBladeMenu")
	TSoftClassPtr<UFortSocialPanelView_Sidebar> SidebarLeft;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortDualBladeMenu")
	TSoftClassPtr<UFortSocialPanelView_Sidebar> SidebarRight;

private:
	UFUNCTION()
	void HandleBladeMenuRequestedClose();

	UPROPERTY(EditAnywhere, Category="FortDualBladeMenu")
	FUIActionTag OpenSocialPanelActionTag;

	UPROPERTY(EditAnywhere, Category="FortDualBladeMenu")
	FUIActionTag OpenMainMenuActionTag;

	UPROPERTY(EditAnywhere, Category="FortDualBladeMenu")
	FUIActionTag SwitchProfileActionTag;

	UPROPERTY(EditAnywhere, Category="FortDualBladeMenu", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle TriggeringSocialPanelInputAction;

	UPROPERTY(EditAnywhere, Category="FortDualBladeMenu", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle TriggeringMainMenuInputAction;

	UPROPERTY(EditAnywhere, Category="FortDualBladeMenu", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle SwitchProfileInputAction;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortSocialPanelView_Sidebar> Sidebar;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortBladeMenu> TopRightWindowControlsWidget;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_BackBoard;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSeasonDataWidget> BladesMenu_XpBar;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UNamedSlot> Slot_SidebarLeft;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UNamedSlot> Slot_SidebarRight;

};

