// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "FortRarityData.h"
#include "FortCraftingItemInfoWidget.generated.h"

class UAthenaInventoryItemStatsWidget;
class UCommonButtonLegacy;
class UCommonTextBlock;
class UFortCraftingFormulaIngredientsWidget;
class UFortItemCategoryIndicator;
enum class EFortRarity : uint8;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortCraftingItemInfoWidget : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnItemRaritySet(const EFortRarity Rarity, const FFortRarityItemData RarityItemData);

private:
	UPROPERTY(EditDefaultsOnly, Category="FortCraftingItemInfoWidget")
	FText RarityTextFormat;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCraftingItemInfoWidget", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ItemName;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCraftingItemInfoWidget", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ItemRarity;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCraftingItemInfoWidget", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ItemCategory;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCraftingItemInfoWidget", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortItemCategoryIndicator> ItemCategoryIndicator;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCraftingItemInfoWidget", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ItemDescription;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCraftingItemInfoWidget", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UAthenaInventoryItemStatsWidget> ItemStatsWidget;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCraftingItemInfoWidget", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortCraftingFormulaIngredientsWidget> IngredientsWidget;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCraftingItemInfoWidget", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_StartCrafting;

};

