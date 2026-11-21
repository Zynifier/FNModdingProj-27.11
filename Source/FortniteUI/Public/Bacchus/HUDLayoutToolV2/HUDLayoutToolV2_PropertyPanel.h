// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "HUDLayoutToolV2_PropertyPanel.generated.h"

class UCommonActivatableWidgetSwitcher;
class UCommonTextBlock;
class UFortMobileHUDElementProxy;
class UFortMobileHUDWidgetCustomPropertySettingRegistry;
class UFortMobileHUDWidgetRegistry;
class UFortSetting;
class UFortSettingsListView;
class UHUDLayoutToolV2_Button;
class UVerticalBox;

UCLASS(Abstract, meta=(DisableNativeTick))
class UHUDLayoutToolV2_PropertyPanel : public UCommonUserWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortMobileHUDElementProxy> WidgetProxyToEdit;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortSetting>> VisibleSettings;

	UPROPERTY(Transient)
	TObjectPtr<UFortMobileHUDWidgetCustomPropertySettingRegistry> HUDWidgetCustomPropertySettingRegistry;

	UPROPERTY(Transient)
	TObjectPtr<UFortMobileHUDWidgetRegistry> HUDWidgetRegistry;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonActivatableWidgetSwitcher> Switcher_PropertiesAndMessage;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_SelectWidgetMessage;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UVerticalBox> VerticalBox_PropertiesContainer;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_WidgetName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_Button> Button_EditLinks;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_Button> Button_RevertHUDWidget;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_Button> Button_DeleteHUDWidget;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSettingsListView> ListView_Settings;

};

