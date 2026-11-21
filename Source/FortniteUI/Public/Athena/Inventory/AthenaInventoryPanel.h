// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "Athena/Inventory/AthenaInventoryTabInterface.h"
#include "FortTabListWidgetBase.h"
#include "AthenaInventoryPanel.generated.h"

class UAthenaInventoryGroupBase;
class UAthenaInventoryGroupPanel;
class UAthenaInventoryItemInfo;
class UAthenaQuickbarEditorBase;
class UDataTable;
class UFortItem;
class UFortItemTileView;
class UFortQuantitySelector;
class UPanelWidget;
class UVerticalBox;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaInventoryPanel : public UCommonActivatableWidget, public IAthenaInventoryTabInterface
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleInventoryItemSelected(UFortItem* SelectedInventoryItem);

	UPROPERTY(EditDefaultsOnly, Category="Fort Tab Interface")
	FName TabNameId;

	UPROPERTY(EditDefaultsOnly, Category="Fort Tab Interface")
	FFortTabButtonLabelInfo TabButtonLabelInfo;

	UPROPERTY(EditDefaultsOnly, Category="Fort Tab Interface")
	FFortTabButtonLabelInfo CreativeTabButtonLabelInfo;

	UPROPERTY(EditDefaultsOnly, Category="AthenaInventoryPanel")
	TSubclassOf<UFortQuantitySelector> QuantitySelectorClass;

	UPROPERTY(EditDefaultsOnly, Category="AthenaInventoryPanel")
	TObjectPtr<UDataTable> StackSizeDataTable;

	UPROPERTY(EditDefaultsOnly, Category="AthenaInventoryPanel", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle DropItemInputRowHandle;

	UPROPERTY(EditDefaultsOnly, Category="AthenaInventoryPanel", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle DropAllInputRowHandle;

	UPROPERTY(EditDefaultsOnly, Category="AthenaInventoryPanel", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle DropStackInputRowHandle;

	UPROPERTY(EditDefaultsOnly, Category="AthenaInventoryPanel", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle DropHalfInputRowHandle;

	UPROPERTY(EditDefaultsOnly, Category="AthenaInventoryPanel")
	FText DropItemsText;

	UPROPERTY(EditDefaultsOnly, Category="AthenaInventoryPanel")
	FText ConfirmDropText;

	UPROPERTY(EditDefaultsOnly, Category="AthenaInventoryPanel")
	FText DropStackTextFormat;

	UPROPERTY(EditDefaultsOnly, Category="AthenaInventoryPanel")
	FGameplayTagContainer IngredientItemTags;

	UPROPERTY(BlueprintReadOnly, Export, Category="Item Management|Inventory", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UAthenaInventoryGroupPanel> DefaultGroupPanel;

	UPROPERTY(BlueprintReadOnly, Export, Category="Item Management|Inventory", meta=(AllowPrivateAccess, EditInline="true"))
	TObjectPtr<UAthenaInventoryGroupPanel> CurrentGroupPanel;

	UPROPERTY(BlueprintReadOnly, Export, Category="Item Management|Inventory", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UPanelWidget> GroupPanelHolder;

	UPROPERTY(BlueprintReadOnly, Export, Category="Item Management|Inventory", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UVerticalBox> QuickbarEditorHolder;

	UPROPERTY(BlueprintReadOnly, Export, Category="Item Management|Inventory", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UAthenaQuickbarEditorBase> DefaultQuickbarEditor;

	UPROPERTY(BlueprintReadOnly, Export, Category="Item Management|Inventory", meta=(AllowPrivateAccess, EditInline="true"))
	TObjectPtr<UAthenaQuickbarEditorBase> CurrentQuickbarEditor;

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="AthenaInventoryPanel", meta=(AllowPrivateAccess, EditInline="true"))
	TArray<TObjectPtr<UFortItemTileView>> InventorySections;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaInventoryPanel", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UAthenaInventoryItemInfo> ItemInfoWidget;

	UPROPERTY(Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UAthenaInventoryGroupBase>> InventoryGroups;

};

