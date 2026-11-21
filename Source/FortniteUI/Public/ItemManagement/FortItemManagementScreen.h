// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortInventoryFilterEnum.h"
#include "FortItemTier.h"
#include "ItemManagement/FortItemManagementMulchPanel.h"
#include "ItemManagement/FortItemManagementScreenDefinitions.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortItemManagementScreen.generated.h"

class UFortAccountItem;
class UFortConsumableAccountItem;
class UFortInventoryContext;
class UFortItem;
class UFortItemManagementCustomFilterModalWidget;
class UFortItemManagementInventoryPanel;
class UFortItemManagementModeDetailsPanel;
class UFortMulchConfirmationModalWidget;
class UFortSchematicItem;
enum class EFortFrontendInventoryFilter : uint8;
enum class EFortItemTier : uint8;

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortItemManagementScreen : public UFortActivatablePanel, public IFortItemManagementMulchPanel
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Item Management")
	bool CanEquipItem(UFortItem* Item) const;

	UFUNCTION(BlueprintCallable, Category="Item Management")
	bool CanRequestPopupMenuForSelectedItem();

	UFUNCTION(BlueprintCallable, Category="Item Management", meta=(DisplayName="Consume Item"))
	void ConsumeItem(UFortConsumableAccountItem* ConsumableItem);

	UFUNCTION(BlueprintCallable, Category="Item Management", meta=(DisplayName="Craft And Slot Item"))
	void CraftAndSlotItem(UFortSchematicItem* SchematicItem, EFortItemTier RequestedTier = EFortItemTier::No_Tier, int32 CraftCount = 1);

	UFUNCTION(BlueprintCallable, Category="Item Management", meta=(DisplayName="Craft Item"))
	void CraftItem(UFortSchematicItem* SchematicItem, EFortItemTier RequestedTier = EFortItemTier::No_Tier, int32 CraftCount = 1);

	UFUNCTION(BlueprintCallable, Category="Item Management|Inventory")
	void CycleSortType();

	UFUNCTION(BlueprintCallable, Category="Item Management", meta=(DisplayName="Drop Item"))
	void DropItem(UFortItem* Item);

	UFUNCTION(BlueprintCallable, Category="Item Management|Mode")
	void EnterComparisonMode(UFortItem* ItemToCompareDetailsWith);

	UFUNCTION(BlueprintCallable, Category="Item Management|Mode")
	void EnterDetailsMode(UFortItem* ItemToDetail);

	UFUNCTION(BlueprintCallable, Category="Item Management|Mode")
	void EnterMulchMode(UFortItem* ItemToMulch);

	UFUNCTION(BlueprintCallable, Category="Item Management|Mode")
	void EnterMulchModeForAutoMulch();

	UFUNCTION(BlueprintCallable, Category="Item Management", meta=(DisplayName="Equip Item"))
	void EquipItem(UFortItem* Item);

	UFUNCTION(BlueprintPure, Category="Item Management|Comparison Mode")
	UFortItem* GetItemToCompareDetailsWith() const;

	UFUNCTION(BlueprintPure, Category="Item Management")
	UFortItem* GetItemToDetail() const;

	UFUNCTION(BlueprintPure, Category="Item Management")
	bool GetShouldShowCollectionBookIndicator() const;

	UFUNCTION(BlueprintPure, Category="Item Management")
	bool GetShouldShowRefundIndicator() const;

	UFUNCTION(BlueprintCallable, Category="Item Management")
	bool GuardActionForReadOnlyWIFE();

	UFUNCTION(BlueprintImplementableEvent, Category="Item Management", meta=(DisplayName="Handle Consume Item"))
	void HandleConsumeItemBP(UFortConsumableAccountItem* ConsumableItem);

	UFUNCTION(BlueprintImplementableEvent, Category="Item Management", meta=(DisplayName="Handle Craft And Slot Item"))
	void HandleCraftAndSlotItemBP(UFortSchematicItem* SchematicItem, EFortItemTier RequestedTier, int32 CraftCount);

	UFUNCTION(BlueprintImplementableEvent, Category="Item Management", meta=(DisplayName="Handle Craft Item"))
	void HandleCraftItemBP(UFortSchematicItem* SchematicItem, EFortItemTier RequestedTier, int32 CraftCount);

	UFUNCTION(BlueprintImplementableEvent, Category="Item Management|Mode", meta=(DisplayName="Handle Different Item Management Mode Set"))
	void HandleDifferentItemManagementModeSetBP();

	UFUNCTION(BlueprintImplementableEvent, Category="Item Management", meta=(DisplayName="Handle Drop Item"))
	void HandleDropItemBP(UFortItem* Item);

	UFUNCTION(BlueprintImplementableEvent, Category="Item Management", meta=(DisplayName="Handle Equip Item"))
	void HandleEquipItemBP(UFortItem* Item);

	UFUNCTION(BlueprintImplementableEvent, Category="Item Management", meta=(DisplayName="Handle Inspect Item"))
	void HandleInspectItemBP(UFortItem* Item);

	UFUNCTION(BlueprintImplementableEvent, Category="Item Management|Mulch Mode")
	void HandleMulchQuantitySelection(UFortItem* Item);

	UFUNCTION(BlueprintImplementableEvent, Category="Item Management", meta=(DisplayName="Handle Open Auto Mulch Options"))
	void HandleOpenAutoMulchOptionsBP();

	UFUNCTION(BlueprintImplementableEvent, Category="Item Management", meta=(DisplayName="Handle Open Crafting Options"))
	void HandleOpenCraftingOptionsBP(UFortSchematicItem* SchematicItem);

	UFUNCTION(BlueprintImplementableEvent, Category="Item Management", meta=(DisplayName="Handle Transfer Item"))
	void HandleTransferItemBP(UFortItem* Item);

	UFUNCTION(BlueprintPure, Category="Item Management")
	bool HasDefaultItemsToMulch() const;

	UFUNCTION(BlueprintPure, Category="Item Management", meta=(DisplayName="Has Item Been Seen"))
	bool HasItemBeenSeen(UFortAccountItem* AccountItem) const;

	UFUNCTION(BlueprintCallable, Category="Item Management|Custom Filter")
	void HideCustomFilterModal();

	UFUNCTION(BlueprintCallable, Category="Item Management|Mulch")
	virtual void HideMulchConfirmationModal();

	UFUNCTION()
	void HideRecycleProgressModal();

	UFUNCTION(BlueprintCallable, Category="Item Management", meta=(DisplayName="Inspect Item"))
	void InspectItem(UFortItem* Item);

	UFUNCTION(BlueprintPure, Category="Item Management")
	bool IsScreenWIFE() const;

	UFUNCTION(BlueprintCallable, Category="Item Management")
	void MarkAllItemsAsSeen();

	UFUNCTION(BlueprintCallable, Category="Item Management", meta=(DisplayName="Open Auto Mulch Options"))
	void OpenAutoMulchOptions();

	UFUNCTION(BlueprintCallable, Category="Item Management", meta=(DisplayName="Open Crafting Options"))
	void OpenCraftingOptions(UFortSchematicItem* SchematicItem);

	UFUNCTION(BlueprintCallable, Category="Item Management")
	void RequestPopupMenuForSelectedItem();

	UFUNCTION(BlueprintCallable, Category="Item Management", meta=(DisplayName="Set Consume Item Request In Progress"))
	void SetConsumeItemRequestInProgress(bool InProgress);

	UFUNCTION(BlueprintCallable, Category="Item Management|Inventory")
	void SetFrontendInventoryFilter(EFortFrontendInventoryFilter FrontendInventoryFilter);

	UFUNCTION(BlueprintCallable, Category="Item Management|Custom Filter")
	void ShowCustomFilterModal();

	UFUNCTION(BlueprintCallable, Category="Item Management|Mulch")
	virtual void ShowMulchConfirmationModal();

	UFUNCTION()
	void ShowRecycleProgressModal();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Item Management")
	void ShowWarningReadOnlyWIFE(bool Force);

	UFUNCTION(BlueprintCallable, Category="Item Management")
	void ToggleShowCollectionBookIndicator();

	UFUNCTION(BlueprintCallable, Category="Item Management")
	void ToggleShowRefundIndicator();

	UFUNCTION(BlueprintCallable, Category="Item Management", meta=(DisplayName="Transfer Item"))
	void TransferItem(UFortItem* Item);

	UPROPERTY(BlueprintAssignable, Category="Item Management")
	FOnItemViewRefreshed OnItemViewRefreshed;

	UPROPERTY(BlueprintReadOnly, Category="Item Management|Mode")
	EFortItemManagementMode Mode;

	UPROPERTY(BlueprintReadOnly, Category="Item Management|Mode")
	EFortFrontendInventoryFilter FrontendInventoryFilter;

	UPROPERTY(BlueprintReadWrite, Category="Item Management|Mode")
	bool bReadOnlyModeWIFE;

	UPROPERTY(BlueprintReadOnly, Category="Item Management")
	bool ConsumeItemRequestInProgress;

	UPROPERTY(EditAnywhere, Category="FortItemManagementScreen")
	FText RecycleText;

protected:
	UFUNCTION(BlueprintCallable, Category="Item Management")
	void CancelInventoryPanelTileViewRefresh();

	UFUNCTION(BlueprintCallable, Category="Item Management")
	virtual void NotifyPanelActivated();

	UFUNCTION(BlueprintCallable, Category="Item Management")
	virtual void NotifyPanelDeactivated();

	UPROPERTY(BlueprintReadOnly, Export, Category="Item Management", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortItemManagementInventoryPanel> InventoryPanel;

	UPROPERTY(BlueprintReadOnly, Export, Category="Item Management", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortItemManagementModeDetailsPanel> ModeDetailsPanel;

	UPROPERTY(BlueprintReadOnly, Category="FortItemManagementScreen")
	TWeakObjectPtr<UFortItem> ItemToDetail;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Item Management|Mulch")
	TSubclassOf<UFortMulchConfirmationModalWidget> MulchConfirmationModalClass;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Item Management|Custom Filter")
	TSubclassOf<UFortItemManagementCustomFilterModalWidget> CustomFilterModalClass;

private:
	UFUNCTION()
	void HandleItemToCompareWithChanged(bool bItemChanged, bool bAmmoChanged, bool bIngredientsChanged);

	UFUNCTION()
	void HandleItemToDetailChanged(bool bItemChanged, bool bAmmoChanged, bool bIngredientsChanged);

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortMulchConfirmationModalWidget> MulchConfirmationModal;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortItemManagementCustomFilterModalWidget> CustomFilterModal;

	UPROPERTY(Transient)
	TObjectPtr<UFortInventoryContext> InventoryContext;

};

