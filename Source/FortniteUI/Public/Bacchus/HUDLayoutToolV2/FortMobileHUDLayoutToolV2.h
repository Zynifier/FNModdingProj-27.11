// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Bacchus/HUDLayoutToolV2/HUDLayoutToolV2_Popup.h"
#include "Bacchus/HUDLayoutToolV2/HUDLayoutToolV2_Toaster.h"
#include "Bacchus/LayoutProfile/FortMobileHUDLayoutProfile.h"
#include "CommonActivatablePanelLegacy.h"
#include "UIManager/FortPrimaryContentInterface.h"
#include "FortMobileHUDLayoutToolV2.generated.h"

class UCanvasPanel;
class UCommonTextBlock;
class UFortMobileHUDElementProxy;
class UFortMobileHUDLayer;
class UFortMobileHUDLayoutToolV2_ControlPanel;
class UFortMobileHUDLayoutToolV2_PresetEditorTool;
class UFortMobileHUDLayoutToolV2_WidgetCatalog;
class UFortMobileHUDWidgetRegistry;
class UHUDLayoutToolV2_Button;
class UHUDLayoutToolV2_Grid;
class UHUDLayoutToolV2_LinkAcrossPanel;
class UHUDLayoutToolV2_Popup;
class UHUDLayoutToolV2_ProfileSelectionPanel;
class UHUDLayoutToolV2_Toaster;
class UHUDLayoutToolV2_TooltipLayer;
class UHUDLayoutToolV2_TutorialPopup;
class UHUDLayoutToolV2_VirtualCanvas;
class UOverlay;
class UVerticalBox;
class UWidgetAnimation;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortMobileHUDLayoutToolV2 : public UCommonActivatablePanelLegacy, public IFortPrimaryContentInterface
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortMobileHUDLayoutToolV2")
	float OverlapPercentageToColapsePanels;

	UPROPERTY(EditAnywhere, Category="FortMobileHUDLayoutToolV2")
	float NonEditableHUDWidgetOpacity;

	UPROPERTY(EditAnywhere, Category="FortMobileHUDLayoutToolV2")
	float PanelOpacityWhenDragedOver;

	UPROPERTY(EditAnywhere, Category="FortMobileHUDLayoutToolV2")
	float OnOpenSubPanelAnimPlaybackSpeed;

	UPROPERTY(EditAnywhere, Category="PrimaryContent")
	FPrimaryContentSetup PrimaryContentSetup;

	UPROPERTY(Transient)
	TObjectPtr<UFortMobileHUDWidgetRegistry> HUDWidgetRegistry;

	UPROPERTY(EditAnywhere, Category="FortMobileHUDLayoutToolV2")
	TSubclassOf<UHUDLayoutToolV2_Popup> HudLayoutToolPopupClass;

	UPROPERTY(EditAnywhere, Category="FortMobileHUDLayoutToolV2")
	TSubclassOf<UHUDLayoutToolV2_TutorialPopup> HudLayoutToolTutorialPopupClass;

	UPROPERTY(EditAnywhere, Category="PopupContent", meta=(DisplayName="Exit HUD Layout Tool Popup Content"))
	FHUDLayoutToolV2_PopupContent ExitHudLayoutToolPopupContent;

	UPROPERTY(EditAnywhere, Category="PopupContent", meta=(DisplayName="Delete Out Of Bounds HUD Proxies Popup Content"))
	FHUDLayoutToolV2_PopupContent DeleteOutOfBoundsHUDProxiesPopupContent;

	UPROPERTY(EditAnywhere, Category="PopupContent", meta=(DisplayName="Revert All Proxies Popup Content"))
	FHUDLayoutToolV2_PopupContent RevertAllProxiesPopupContent;

	UPROPERTY(EditAnywhere, Category="PopupContent", meta=(DisplayName="Switch HUD Save Profile Content"))
	FHUDLayoutToolV2_PopupContent SwitchHUDProfileSavePopupContent;

	UPROPERTY(EditAnywhere, Category="PopupContent", meta=(DisplayName="Switch HUD Delete Profile Content"))
	FHUDLayoutToolV2_PopupContent SwitchHUDProfileDeletePopupContent;

	UPROPERTY(EditAnywhere, Category="PopupContent", meta=(DisplayName="Create New Custom Layout Popup Content"))
	FHUDLayoutToolV2_PopupContent CreateNewCustomLayoutPopupContent;

	UPROPERTY(EditAnywhere, Category="PopupContent", meta=(DisplayName="Custom Layout Slots Full Popup Content"))
	FHUDLayoutToolV2_PopupContent CustomLayoutSlotsFullPopupContent;

	UPROPERTY(EditAnywhere, Category="ToasterContent", meta=(DisplayName="Save successful Toaster Content"))
	FHUDLayoutToolV2_ToastNotificationContent SuccessToasterContent;

	UPROPERTY(EditAnywhere, Category="ToasterContent", meta=(DisplayName="Save failed Toaster Content"))
	FHUDLayoutToolV2_ToastNotificationContent FailureToasterContent;

	UPROPERTY(EditAnywhere, Category="ToasterContent", meta=(DisplayName="Local Save failed Toaster Content"))
	FHUDLayoutToolV2_ToastNotificationContent LocalFailureToasterContent;

	UPROPERTY(EditAnywhere, Category="ToasterContent", meta=(DisplayName="Cloud Save failed Toaster Content"))
	FHUDLayoutToolV2_ToastNotificationContent CloudFailureToasterContent;

	UPROPERTY(EditAnywhere, Category="Custom Properties", meta=(Categories="HUDLayout.Property"))
	FGameplayTag AnchorsCustomPropertyTag;

	UPROPERTY(EditAnywhere, Category="FortMobileHUDLayoutToolV2")
	float DoubleClickDelay;

	UPROPERTY(Transient)
	FFortMobileHUDLayoutProfile LayoutProfile;

	UPROPERTY(Transient)
	FFortMobileHUDLayoutProfile CachedSavedLayoutProfile;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortMobileHUDElementProxy> SelectedWidgetProxy;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UHUDLayoutToolV2_Popup>> QueuedPopups;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_VirtualCanvas> VirtualCanvas_WidgetLayer;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortMobileHUDLayer> HUDLayer_HUDWidgetProxies;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_VirtualCanvasWorkspace;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_Grid> Grid_Visual;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ProfileName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_WidgetName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ContextName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_Button> Button_Exit;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_Button> Button_ResetVirtualCanvas;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_Button> Button_ToggleControlPanel;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_Button> Button_ToggleWidgetCatalog;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCanvasPanel> CanvasPanel_ControlsContainer;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UVerticalBox> VerticalBox_ControlPanelContainer;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortMobileHUDLayoutToolV2_ControlPanel> ControlPanel_Controls;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_ProfileSelectionPanel> ProfileSelectionPanel_Profiles;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortMobileHUDLayoutToolV2_WidgetCatalog> WidgetCatalog_Catalog;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_LinkAcrossPanel> LinkAcrossPanel_LinkManagementWindow;

	UPROPERTY(Transient, meta=(BindWidgetAnim))
	TObjectPtr<UWidgetAnimation> Anim_ControlPanelToggle;

	UPROPERTY(Transient, meta=(BindWidgetAnim))
	TObjectPtr<UWidgetAnimation> Anim_ToggleWidgetCatalog;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_Toaster> Toaster_Notifications;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_TooltipLayer> TooltipLayer_Messages;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Editor")
	TSubclassOf<UFortMobileHUDLayoutToolV2_PresetEditorTool> PresetEditorToolClass;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortMobileHUDLayoutToolV2_PresetEditorTool> PresetEditorTool;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_ToolMainOverlay;
#endif

};

