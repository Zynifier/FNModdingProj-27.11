// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "GameplayTagContainer.h"
#include "Athena/Inventory/AthenaInventoryTabInterface.h"
#include "FortTabListWidgetBase.h"
#include "FortCraftingTab.generated.h"

class UAthenaInventoryItemInfo;
class UAthenaQuickbarEditorBase;
class UCommonListView;
class UFortCraftingItemInfoWidget;
class UFortItem;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortCraftingTab : public UCommonActivatableWidget, public IAthenaInventoryTabInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnFormulaListUpdated(const int32 NumFormulas);

private:
	UFUNCTION()
	void HandleInventoryItemSelected(UFortItem* Item);

	UPROPERTY(EditAnywhere, Category="Fort Tab Interface")
	FName TabNameId;

	UPROPERTY(EditAnywhere, Category="Fort Tab Interface")
	FFortTabButtonLabelInfo TabButtonLabelInfo;

	UPROPERTY(EditAnywhere, Category="FortCraftingTab")
	FGameplayTagContainer PrimaryIngredientTags;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCraftingTab", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortCraftingItemInfoWidget> CraftingItemInfo;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCraftingTab", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonListView> ListView_Recipes;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCraftingTab", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UAthenaQuickbarEditorBase> QuickbarEditor;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCraftingTab", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UAthenaInventoryItemInfo> ItemInfoWidget;

};

