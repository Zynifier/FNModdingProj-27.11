// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortItemCraftingOptionsActivatablePanel.generated.h"

class UFortItemManagementScreen;
class UFortSchematicItem;
class UImage;
class UWidget;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortItemCraftingOptionsActivatablePanel : public UFortActivatablePanel
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="CraftingOptions")
	void SetBaseSchematicItem(UFortSchematicItem* InBaseItem);

	UFUNCTION(BlueprintCallable, Category="CraftingOptions")
	void SetItemManagementScreen(UFortItemManagementScreen* InItemManagementScreen);

protected:
	UFUNCTION(BlueprintCallable, Category="CraftingOptions")
	void CraftAndSlotTargetItem();

	UFUNCTION(BlueprintCallable, Category="CraftingOptions")
	void CraftTargetItem();

	UFUNCTION(BlueprintCallable, Category="CraftingOptions")
	void DecreaseSelectedQuantity();

	UFUNCTION(BlueprintCallable, Category="CraftingOptions")
	void IncreaseSelectedQuantity();

	UFUNCTION(BlueprintImplementableEvent)
	void OnBaseItemChanged(UFortSchematicItem* NewBaseItem);

	UFUNCTION(BlueprintImplementableEvent)
	void OnMaxQuantityChanged(int32 NewMaxQuantity);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSelectedQuantityChanged(int32 NewSelectedQuantity);

	UFUNCTION(BlueprintImplementableEvent)
	void OnTargetItemChanged(UFortSchematicItem* NewTargetItem);

	UFUNCTION(BlueprintCallable, Category="CraftingOptions")
	void SelectNextTier();

	UFUNCTION(BlueprintCallable, Category="CraftingOptions")
	void SelectPreviousTier();

	UFUNCTION(BlueprintCallable, Category="CraftingOptions")
	void SetSelectedQuantity_BP(int32 NewQuantity);

	UFUNCTION(BlueprintCallable, Category="CraftingOptions")
	void SetTargetCraftingTierIndex(int32 NewTierIndex);

	UFUNCTION(BlueprintCallable, Category="CraftingOptions")
	void UpdateTierImages();

	UPROPERTY(BlueprintReadOnly, Category="FortItemCraftingOptionsActivatablePanel")
	TObjectPtr<UFortSchematicItem> BaseItem;

	UPROPERTY(BlueprintReadOnly, Category="FortItemCraftingOptionsActivatablePanel")
	TObjectPtr<UFortSchematicItem> TargetItem;

	UPROPERTY(BlueprintReadOnly, Category="FortItemCraftingOptionsActivatablePanel")
	int32 MaxCraftingTierIndex;

	UPROPERTY(BlueprintReadOnly, Category="FortItemCraftingOptionsActivatablePanel")
	int32 TargetCraftingTierIndex;

	UPROPERTY(BlueprintReadOnly, Category="FortItemCraftingOptionsActivatablePanel")
	int32 TargetPromotionTierIndex;

	UPROPERTY(BlueprintReadOnly, Category="FortItemCraftingOptionsActivatablePanel")
	int32 MaxQuantity;

	UPROPERTY(BlueprintReadOnly, Category="FortItemCraftingOptionsActivatablePanel")
	int32 SelectedQuantity;

	UPROPERTY(BlueprintReadOnly, Category="FortItemCraftingOptionsActivatablePanel")
	bool CanCraftTargetItem;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemCraftingOptionsActivatablePanel", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UWidget> TierImageParent_1;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemCraftingOptionsActivatablePanel", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UWidget> TierImageParent_2;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemCraftingOptionsActivatablePanel", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UWidget> TierImageParent_3;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemCraftingOptionsActivatablePanel", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UWidget> TierImageParent_4;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemCraftingOptionsActivatablePanel", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UWidget> TierImageParent_5;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemCraftingOptionsActivatablePanel", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UImage> TierImage_1;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemCraftingOptionsActivatablePanel", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UImage> TierImage_2;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemCraftingOptionsActivatablePanel", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UImage> TierImage_3;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemCraftingOptionsActivatablePanel", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UImage> TierImage_4;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemCraftingOptionsActivatablePanel", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UImage> TierImage_5;

};

