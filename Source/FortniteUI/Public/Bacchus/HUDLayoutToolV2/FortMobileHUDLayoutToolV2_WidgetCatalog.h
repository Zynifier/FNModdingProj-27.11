// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortMobileHUDLayoutToolV2_WidgetCatalog.generated.h"

class UCommonActivatableWidgetSwitcher;
class UCommonTextBlock;
class UFortDynamicEntryBox;
class UFortMobileHUDWidgetRegistry;
class UHUDLayoutToolV2_Button;
class UImage;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortMobileHUDLayoutToolV2_WidgetCatalog : public UCommonUserWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TObjectPtr<UFortMobileHUDWidgetRegistry> HUDWidgetRegistry;

	UPROPERTY(EditAnywhere, Category="FortMobileHUDLayoutToolV2_WidgetCatalog")
	float PanelOpacityWhenDragedOver;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_LayoutIcon;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ContextName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_Button> Button_DisplayButtonPreviews;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_Button> Button_DisplayWidgetPreviews;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonActivatableWidgetSwitcher> Switcher_Previews;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortDynamicEntryBox> EntryBox_ButtonPreviews;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortDynamicEntryBox> EntryBox_WidgetPreviews;

};

