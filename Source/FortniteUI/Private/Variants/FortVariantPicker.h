// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Engine/DataTable.h"
#include "CommonButtonLegacy.h"
#include "Variants/AthenaVariantPickerConfig.h"
#include "Variants/FortVariantEntryBox.h"
#include "FortVariantPicker.generated.h"

class UAthenaCosmeticAccountItem;
class UAthenaCosmeticItemDefinition;
class UAthenaVariantPickerConfig;
class UCommonActionWidget;
class UCommonButtonGroupLegacy;
class UCommonButtonLegacy;
class UCommonTextBlock;
class UDynamicEntryBox;
class UFortLazyImage;
class UFortVariantEntryBox;
class UHorizontalBox;
class UScrollBox;
class UWidget;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortVariantFilterTab : public UCommonButtonLegacy
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	FAthenaVariantFilterTabInfo TabInfo;

private:
	UPROPERTY(Export, meta=(BindWidgetOptional="TRUE", EditInline="true"))
	TObjectPtr<UFortLazyImage> LazyImage_Icon;

	UPROPERTY(Export, meta=(BindWidgetOptional="TRUE", EditInline="true"))
	TObjectPtr<UCommonTextBlock> TextBlock_Label;

};

UCLASS(meta=(Category="Fortnite UI", DisableNativeTick))
class UFortVariantPicker : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void InitFromCosmeticItem(UAthenaCosmeticAccountItem* InCosmeticItem);

	UFUNCTION(BlueprintCallable)
	void InitFromCosmeticItemDef(UAthenaCosmeticItemDefinition* InCosmeticItemDef);

protected:
	UPROPERTY(EditInstanceOnly, Category="FortVariantPicker")
	bool bShowCapeRestriction;

private:
	UFUNCTION()
	void Campaign_HandlePrimaryTabLeft(bool& bPassthrough);

	UFUNCTION()
	void Campaign_HandlePrimaryTabRight(bool& bPassthrough);

	UFUNCTION()
	void Campaign_HandleSecondaryTabLeft(bool& bPassthrough);

	UFUNCTION()
	void Campaign_HandleSecondaryTabRight(bool& bPassthrough);

	UFUNCTION()
	void HandlePrimaryTabSelectionChanged(UCommonButtonLegacy* TabButton, int32 TabIdx);

	UFUNCTION()
	void HandleSecondaryTabSelectionChanged(UCommonButtonLegacy* TabButton, int32 TabIdx);

	UPROPERTY(EditDefaultsOnly, Category="FortVariantPicker")
	TObjectPtr<UAthenaVariantPickerConfig> ConfigurationData;

	UPROPERTY(EditAnywhere, Category="FortVariantPicker", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle PrimaryTabLeftAction;

	UPROPERTY(EditAnywhere, Category="FortVariantPicker", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle PrimaryTabRightAction;

	UPROPERTY(EditAnywhere, Category="FortVariantPicker", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle SecondaryTabLeftAction;

	UPROPERTY(EditAnywhere, Category="FortVariantPicker", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle SecondaryTabRightAction;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UScrollBox> ScrollBox_Variants;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortVariantEntryBox> EntryBox_VariantOptions;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortVariantEntryBox> EntryBox_VariantOptions_NoScroll;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortVariantPicker", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_NoCapes;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortVariantPicker", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Container_Tabs;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortVariantPicker", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UHorizontalBox> HBox_PrimaryTabNav;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortVariantPicker", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_PrimaryFilter;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortVariantPicker", meta=(AllowPrivateAccess, BindWidget, EditInline="true", EntryClass="FortVariantFilterTab"))
	TObjectPtr<UDynamicEntryBox> EntryBox_PrimaryTabs;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortVariantPicker", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonActionWidget> ActionWidget_PrimaryTabLeft;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortVariantPicker", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonActionWidget> ActionWidget_PrimaryTabRight;

	UPROPERTY(Transient)
	TObjectPtr<UCommonButtonGroupLegacy> PrimaryTabButtonGroup;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortVariantPicker", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Container_SecondaryTabs;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortVariantPicker", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_SecondaryFilter;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortVariantPicker", meta=(AllowPrivateAccess, BindWidget, EditInline="true", EntryClass="FortVariantFilterTab"))
	TObjectPtr<UDynamicEntryBox> EntryBox_SecondaryTabs;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortVariantPicker", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonActionWidget> ActionWidget_SecondaryTabLeft;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortVariantPicker", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonActionWidget> ActionWidget_SecondaryTabRight;

	UPROPERTY(Transient)
	TObjectPtr<UCommonButtonGroupLegacy> SecondaryTabButtonGroup;

	UPROPERTY(Transient)
	FFortVariantFilterContext FilterContext;

	UPROPERTY(Transient)
	TObjectPtr<UAthenaCosmeticItemDefinition> CustomizingItemDef;

};

