// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Athena/HUD/Items/AthenaItemElementWidgetBase.h"
#include "AthenaInventoryItemInfo.generated.h"

class UAthenaInventoryItemStatsWidget;
class UAthenaItemIcon;
class UAthenaItemTierWidget;
class UCommonTextBlock;
class UFortItem;
class UImage;
class UUserWidget;
enum class EUIExtensionSlot : uint8;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaInventoryItemInfo : public UAthenaItemElementWidgetBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnExtensionWidgetAdded(const EUIExtensionSlot ExtensionSlot, UUserWidget* ExtensionWidget);

	UFUNCTION(BlueprintImplementableEvent)
	void OnInspectItemInput(const bool bPressed);

	UFUNCTION(BlueprintImplementableEvent)
	void OnItemCategoryIconUpdated(const bool bHasCategoryIcon);

	UFUNCTION(BlueprintImplementableEvent)
	void OnItemCategoryTextUpdated();

	UFUNCTION(BlueprintImplementableEvent)
	void OnItemDescriptionTextUpdated();

	UFUNCTION(BlueprintImplementableEvent)
	void OnItemNameTextUpdated();

	UFUNCTION(BlueprintImplementableEvent)
	void OnItemRarityTextUpdated();

	UFUNCTION(BlueprintImplementableEvent)
	void OnOwnerDeactivated();

private:
	UFUNCTION()
	void HandleInventoryItemSelected(UFortItem* SelectedItem);

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaInventoryItemInfo", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ItemName;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaInventoryItemInfo", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ItemDescription;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaInventoryItemInfo", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ItemRarity;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaInventoryItemInfo", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ItemCategory;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaInventoryItemInfo", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_ItemCategory;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaInventoryItemInfo", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UAthenaItemIcon> ItemIcon;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaInventoryItemInfo", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UAthenaItemTierWidget> ItemTierWidget;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaInventoryItemInfo", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UAthenaInventoryItemStatsWidget> ItemStatsWidget;

	UPROPERTY(EditDefaultsOnly, Category="AthenaInventoryItemInfo", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle InspectItemInputRowHandle;

	UPROPERTY(EditAnywhere, Category="AthenaInventoryItemInfo")
	FText ItemRarityTextFormat;

	UPROPERTY(EditAnywhere, Category="AthenaInventoryItemInfo")
	FName CategoryIconTextureParamName;

};

