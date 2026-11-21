// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Bacchus/HUDLayoutToolV2/HUDLayoutToolV2_Popup.h"
#include "Bacchus/HUDLayoutToolV2/HUDLayoutToolV2_TextInputPopup.h"
#include "HUDLayoutToolV2_ProfileSelectionPanel.generated.h"

class UBacchusCloseButton;
class UFortDynamicEntryBox;
class UFortMobileHUDWidgetRegistry;
class UHUDLayoutToolV2_Button;
class UHUDLayoutToolV2_LayoutButton;
class UHUDLayoutToolV2_Popup;
class UHUDLayoutToolV2_TextInputPopup;

UCLASS(Abstract, meta=(DisableNativeTick))
class UHUDLayoutToolV2_ProfileSelectionPanel : public UCommonUserWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="HUDLayoutToolV2_ProfileSelectionPanel")
	TSubclassOf<UHUDLayoutToolV2_Popup> HUDLayoutToolPopupClass;

	UPROPERTY(EditAnywhere, Category="HUDLayoutToolV2_ProfileSelectionPanel")
	TSubclassOf<UHUDLayoutToolV2_TextInputPopup> HUDLayoutToolTextInputPopupClass;

	UPROPERTY(EditAnywhere, Category="PopupContent")
	FHUDLayoutToolV2_PopupContent NoCustomLayoutSlotsLeftPopupContent;

	UPROPERTY(EditAnywhere, Category="PopupContent")
	FHUDLayoutToolV2_PopupContent DeleteCustomLayoutPopupContent;

	UPROPERTY(EditAnywhere, Category="PopupContent")
	FHUDLayoutToolV2_TextInputPopupContent RenamePopupContent;

	UPROPERTY(Transient)
	TObjectPtr<UFortMobileHUDWidgetRegistry> HUDWidgetRegistry;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_LayoutButton> InEditLayoutButton;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_LayoutButton> SelectedLayoutButton;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortDynamicEntryBox> EntryBox_Presets;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortDynamicEntryBox> EntryBox_CustomLayouts;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortDynamicEntryBox> EntryBox_EmptyCustomLayoutSlots;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UBacchusCloseButton> Button_Exit;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_Button> Button_EditLayout;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_Button> Button_Convert;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_Button> Button_Copy;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_Button> Button_Delete;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_Button> Button_Rename;

};

