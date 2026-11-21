// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortMobileHUDLayoutToolV2_ControlPanel.generated.h"

class UCommonActivatableWidgetSwitcher;
class UHUDLayoutToolV2_Button;
class UHUDLayoutToolV2_ContextSelector;
class UHUDLayoutToolV2_GridSnap;
class UHUDLayoutToolV2_PropertyPanel;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortMobileHUDLayoutToolV2_ControlPanel : public UCommonUserWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortMobileHUDLayoutToolV2_ControlPanel")
	float PanelOpacityWhenDragedOver;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_Button> Button_Save;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_Button> Button_RevertAll;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_Button> Button_Exit;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_Button> Button_OpenProfileSelectionPanel;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_Button> Button_SwitchContexts;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_Button> Button_SwitchProperties;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_GridSnap> GridSnapOption_Controls;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonActivatableWidgetSwitcher> Switcher_Controls;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_ContextSelector> ContextSelector_ContextLayouts;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_PropertyPanel> PropertyPanel_WidgetProperties;

};

