// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "Frontend/FortItemPreviewScreen.h"
#include "FortVariantSprayCustomizer.generated.h"

class UAthenaCosmeticItemDefinition;
class UCommonActionWidget;
class UCommonActivatableWidgetSwitcher;
class UCommonButtonBase;
class UCommonButtonGroupLegacy;
class UFortCustomizableObjectSprayVariant;
class UFortVariantItemTexturePicker;
class UFortVariantSprayCustomizerSetting;
class UObject;
class UWidget;

UCLASS(Abstract, meta=(Category="MeshCosmetics UI", DisableNativeTick))
class UFortVariantSprayCustomizer : public UFortItemPreviewScreen
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Set Channel Slot Icon"))
	void BP_SetChannelSlotIcon(const TSoftObjectPtr<UObject>& ChannelSlotIcon);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Set Variant Editor Mode"))
	void BP_SetVariantEditorMode(const bool bIsLockerMode);

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Back;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Confirm;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_HideArchivedItems;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_ShowArchivedItems;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Widget_ArchivedItemsButtons;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortVariantSprayCustomizer", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_SpraysTab;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortVariantSprayCustomizer", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_SettingsTab;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_TouchClose;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonActionWidget> ActionWidget_TabLeft;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonActionWidget> ActionWidget_TabRight;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonActivatableWidgetSwitcher> Switcher_Tabs;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Widget_Sprays;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Widget_Settings;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortVariantItemTexturePicker> TexturePicker_Sprays;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortVariantSprayCustomizerSetting> Setting_Saturation;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortVariantSprayCustomizerSetting> Setting_Wear;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortVariantSprayCustomizerSetting> Setting_Scale;

	UPROPERTY(EditDefaultsOnly, Category="FortVariantSprayCustomizer", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle TabLeftAction;

	UPROPERTY(EditDefaultsOnly, Category="FortVariantSprayCustomizer", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle TabRightAction;

	UPROPERTY(EditDefaultsOnly, Category="Camera Behavior", meta=(Categories="UI.ItemPreview.SceneChanger"))
	FGameplayTag ItemShopPreviewSceneChangerTag;

	UPROPERTY(Transient)
	TObjectPtr<UCommonButtonGroupLegacy> TabButtonGroup;

	UPROPERTY(Transient)
	TWeakObjectPtr<UAthenaCosmeticItemDefinition> ItemDefinition;

	UPROPERTY(Transient)
	TObjectPtr<UFortCustomizableObjectSprayVariant> SprayVariant;

};

