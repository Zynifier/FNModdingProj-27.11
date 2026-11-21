// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortInventoryFilterEnum.h"
#include "FortUITypes.h"
#include "ItemManagement/FortItemManagementScreenDefinitions.h"
#include "FortItemManagementInventoryPanel.generated.h"

class UCommonButtonBase;
class UCommonButtonStyle;
class UCommonLoadGuard;
class UCommonTextBlock;
class UFortInventoryContext;
class UFortItem;
class UFortItemDefinition;
class UFortItemManagementScreen;
class UFortItemTileView;
class UFortTabListWidgetBase_Legacy;
class UObject;
class UPanelWidget;
class UUserWidget;
class UWidget;
enum class EFortQuickBars : uint8;
enum class EInventoryContentSortType : uint8;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortItemManagementInventoryPanel : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Item Management|Inventory")
	void AdvanceSelection();

	UFUNCTION(BlueprintPure, Category="Item Management|Inventory")
	bool CanDragItems() const;

	UFUNCTION(BlueprintCallable, Category="Item Management|Inventory")
	void CycleSortType();

	UFUNCTION(BlueprintCallable, Category="Item Management|Inventory")
	bool GetShouldPrioritizeFavorites();

	UFUNCTION(BlueprintCallable, Category="Item Management|Inventory")
	void HandleItemBeginDrag(UObject* Item);

	UFUNCTION(BlueprintPure, Category="Item Management|Inventory")
	bool HasUnlockedStorageSlots() const;

	UFUNCTION(BlueprintPure, Category="Item Management|Inventory")
	bool IsSelectedItem(const UFortItem* Item) const;

	UFUNCTION(BlueprintPure, Category="Item Management|Inventory")
	bool IsSwitchPanelAvailable() const;

	UFUNCTION(BlueprintCallable, Category="Item Management|Inventory")
	void MarkAllItemsAsSeen();

	UFUNCTION(BlueprintCallable, Category="Item Management|Inventory")
	void RefreshCraftingSort();

	UFUNCTION(BlueprintCallable, Category="Item Management|Inventory")
	void RequestFocusEquipSlots();

	UFUNCTION(BlueprintCallable, Category="Item Management|Inventory")
	void SwitchPanelFocus();

	UFUNCTION(BlueprintCallable, Category="Item Management|Inventory")
	void TogglePrioritizeFavorites();

	UFUNCTION(BlueprintCallable, Category="Item Management|Inventory")
	void ToggleTileSize();

	UFUNCTION(BlueprintCallable, Category="Item Management|Inventory")
	void UpdateSchematicTiles();

protected:
	UFUNCTION(BlueprintCallable, Category="Item Management|Mulch Details")
	void AddItemStackToMulch(UFortItem* Item, int32 Count);

	UFUNCTION(BlueprintPure, Category="Item Management|Inventory")
	FText GetQualifiedFilterDisplayName() const;

	UFUNCTION(BlueprintPure, Category="Item Management|Inventory")
	TArray<EInventoryContentSortType> GetSupportedSortTypesForCurrentInventory() const;

	UFUNCTION(BlueprintPure, Category="Item Management|Inventory")
	TArray<UFortItemDefinition*> GetUpgradeItemDefinitionsForCurrentInventory() const;

	UFUNCTION(BlueprintImplementableEvent, Category="Item Management|Inventory", meta=(DisplayName="Handle Cursor Mode Changed"))
	void HandleCursorModeChangedBP(bool bCursorModeEnabled, FName ActionName, UUserWidget* CursorModeContentWidget);

	UFUNCTION()
	void HandleCustomInventoryFilterChanged();

	UFUNCTION(BlueprintImplementableEvent, Category="Item Management|Inventory", meta=(DisplayName="Handle Different Filter Set"))
	void HandleDifferentFilterSetBP();

	UFUNCTION(BlueprintImplementableEvent, Category="Item Management|Mode", meta=(DisplayName="Handle Different Frontend Inventory Filter Set"))
	void HandleDifferentFrontendInventoryFilterSetBP();

	UFUNCTION(BlueprintImplementableEvent, Category="Item Management|Mode", meta=(DisplayName="Handle Different Item Management Mode Set"))
	void HandleDifferentItemManagementModeSetBP();

	UFUNCTION(BlueprintImplementableEvent, Category="Item Management|Inventory", meta=(DisplayName="Handle Different Sort Type Set"))
	void HandleDifferentSortTypeSetBP();

	UFUNCTION(BlueprintImplementableEvent, Category="Item Management|Inventory", meta=(DisplayName="Handle Focus Equip Slots"))
	void HandleFocusEquipSlotsBP();

	UFUNCTION(BlueprintImplementableEvent, Category="Item Management|Inventory", meta=(DisplayName="Handle QuickBar Changed"))
	void HandleQuickBarChangedBP(EFortQuickBars QuickBarType);

	UFUNCTION(BlueprintImplementableEvent, Category="Item Management|Mulch Details", meta=(DisplayName="Handle Set Of Items To Mulch Changed"))
	void HandleSetOfItemsToMulchChangedBP();

	UFUNCTION(BlueprintImplementableEvent, Category="Item Management|Inventory", meta=(DisplayName="On Mulch Restriction Text Shown"))
	void OnMulchRestrictionTextShown(bool bShown);

	UFUNCTION(BlueprintCallable, Category="Item Management|Inventory")
	void SetFilter(const FName FilterName);

	UFUNCTION(BlueprintCallable, Category="Item Management|Inventory")
	void SetSortType(EInventoryContentSortType SortType);

	UPROPERTY(BlueprintReadOnly, Category="Item Management|Inventory")
	FName CurrentFilterName;

	UPROPERTY(BlueprintReadOnly, Category="Item Management|Inventory")
	EInventoryContentSortType CurrentSortType;

	UPROPERTY(EditAnywhere, Category="Item Management|Inventory")
	TSubclassOf<UCommonButtonBase> FilterTabButtonType;

	UPROPERTY(EditAnywhere, Category="Item Management|Inventory")
	TSubclassOf<UCommonButtonStyle> FilterTabButtonStyle;

	UPROPERTY(EditAnywhere, EditFixedSize, Category="Item Management|Inventory", meta=(TitleProperty="FilterTabNameId"))
	TArray<FFortItemManagementInventoryFilterTabLabelInfo> FilterTabLabelInfoArray;

	UPROPERTY(BlueprintReadOnly, Export, Category="Item Management|Inventory", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortTabListWidgetBase_Legacy> FilterTabList;

	UPROPERTY(BlueprintReadOnly, Export, Category="Item Management|Inventory", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonLoadGuard> TileViewLoadGuard;

	UPROPERTY(BlueprintReadOnly, Export, Category="Item Management|Inventory", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortItemTileView> TileView;

	UPROPERTY(BlueprintReadOnly, Export, Category="Item Management|Inventory", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UPanelWidget> CraftingPanel;

	UPROPERTY(BlueprintReadOnly, Export, Category="Item Management|Inventory", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonLoadGuard> CraftingTileViewLoadGuard;

	UPROPERTY(BlueprintReadOnly, Export, Category="Item Management|Inventory", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortItemTileView> CraftingTileView;

	UPROPERTY(BlueprintReadOnly, Export, Category="Item Management|Inventory", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UPanelWidget> StoragePanel;

	UPROPERTY(BlueprintReadOnly, Export, Category="Item Management|Inventory", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonLoadGuard> StorageTileViewLoadGuard;

	UPROPERTY(BlueprintReadOnly, Export, Category="Item Management|Inventory", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortItemTileView> StorageTileView;

	UPROPERTY(BlueprintReadOnly, Export, Category="Item Management|Inventory", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> MulchRestrictionReasonText;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Item Management|Inventory")
	EFortItemCardSize SmallTileSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Item Management|Inventory")
	EFortItemCardSize LargeTileSize;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemManagementInventoryPanel")
	TWeakObjectPtr<UFortItemManagementScreen> HostItemManagementScreen;

	UPROPERTY(BlueprintReadWrite, Category="FortItemManagementInventoryPanel", meta=(ScriptName="b_can_drag_items"))
	bool bCanDragItems;

	UPROPERTY(EditInstanceOnly, Category="Item Management|Equip Slot")
	TArray<FQuickbarEquipSlotIndicesConfig> DefaultQuickbarEquipSlotIndicesConfigs;

	UPROPERTY(EditInstanceOnly, Category="Item Management|Equip Slot")
	TMap<FName, int32> QuickbarEquipSlotIndices;

private:
	UFUNCTION()
	void HandleCraftItemStarted();

	UFUNCTION()
	void HandleCursorModeChanged(bool bCursorModeEnabled, FName ActionName, UUserWidget* CursorModeContentWidget);

	UFUNCTION()
	void HandleFilterTabButtonCreated(FName TabNameId, UCommonButtonBase* TabButton);

	UFUNCTION()
	void HandleFilterTabSelected(FName TabNameId);

	UFUNCTION()
	void HandleInventoryUpdatedEvent();

	UPROPERTY(Transient)
	TObjectPtr<UFortInventoryContext> InventoryContext;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UWidget> WidgetToCenter;

};

