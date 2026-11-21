// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Components/SlateWrapperTypes.h"
#include "Athena/AthenaMapScreenContainerTabInterface.h"
#include "FortTabInterface.h"
#include "FortTabListWidgetBase.h"
#include "Items/FortItemEntry.h"
#include "FortCreativeItemListMenu.generated.h"

class AActor;
class UCommonButtonLegacy;
class UCommonVisibilitySwitcher;
class UCommonWidgetSwitcherLegacy;
class UContentBrowserFiltersPanel;
class UDataTable;
class UFortCreativeContentBrowserTabPanelBase;
class UFortCreativeItemDetailsSidePanel;
class UFortCreativeItemListPanelData;
class UFortCreativeItemListTabPanel;
class UFortCreativeLevelManagementTabPanel;
class UFortCreativeMenuQuickbar;
class UFortTabListWidgetBase_Legacy;
class UOverlay;
class UUserWidget;
class UWidgetSwitcher;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSelectItemToSpawnDelegate, FFortItemEntry, ItemToSpawn);

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCreativeItemListMenu : public UCommonActivatableWidget, public IFortTabInterface, public IAthenaMapScreenContainerTabInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	bool AddSelectionToQuickBar();

	UFUNCTION(BlueprintCallable)
	void BroadcastOnCloseFromContentBrowser();

	UFUNCTION(BlueprintCallable)
	void BroadcastOnItemEquipped(FFortItemEntry ItemToSpawn);

	UFUNCTION(BlueprintPure)
	bool CanAddToChest(const FFortItemEntry& SelectedItem) const;

	UFUNCTION(BlueprintPure)
	bool CanDropItem(const FFortItemEntry& SelectedItem) const;

	UFUNCTION(BlueprintPure)
	bool CanEquip(const FFortItemEntry& SelectedItem) const;

	UFUNCTION(BlueprintCallable)
	bool DropItem(const FFortItemEntry& SelectedItem);

	UFUNCTION(BlueprintCallable)
	bool EquipItem(const FFortItemEntry& ItemEntry);

	UFUNCTION(BlueprintCallable)
	bool EquipSelection();

	UFUNCTION(BlueprintPure)
	FFortItemEntry GetCurrentSelection() const;

	UFUNCTION(BlueprintPure)
	UFortCreativeContentBrowserTabPanelBase* GetCurrentTab() const;

	UFUNCTION(BlueprintCallable)
	FName GetLastSelectedTabName();

	UFUNCTION(BlueprintCallable)
	void InitializeTabs();

	UFUNCTION(BlueprintPure)
	bool IsSubTabOpened() const;

	UFUNCTION(BlueprintCallable)
	void LoadItems();

	UFUNCTION()
	void NativeOnItemsLoaded();

	UFUNCTION()
	void NativeOnItemsRefreshed();

	UFUNCTION()
	void OnCreativeQuickbarComponentLoaded();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnExitSubTab();

	UFUNCTION(BlueprintImplementableEvent)
	void OnItemsLoaded();

	UFUNCTION(BlueprintImplementableEvent)
	void OnSearchFiltersVisibilityChanged(ESlateVisibility NewVisibility);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnSelectionOpened(const FFortItemEntry& PreviousSelectedItem, const FName PreviousTab);

	UFUNCTION(BlueprintCallable)
	bool OpenSelection();

	UFUNCTION(BlueprintCallable)
	bool PlaceSelectionInMoveTool();

	UFUNCTION(BlueprintCallable)
	void RefreshChestWidgetState();

	UFUNCTION(BlueprintCallable)
	void SetIsItemCommandsEnabled(bool bInIsItemCommandEnabled);

	UFUNCTION(BlueprintCallable)
	void SetSubTabOpened(bool bIsOpened);

	UFUNCTION(BlueprintCallable)
	void SpawnContainer(TSubclassOf<AActor> SupplyDropClass);

	UFUNCTION(BlueprintCallable)
	void SwitchItemDetailsPanel(bool bUseLegacy = false);

	UFUNCTION(BlueprintCallable)
	void UpdateDetailsPanel();

	UPROPERTY(EditAnywhere, Category="FortCreativeItemListMenu")
	TSubclassOf<UFortCreativeItemListPanelData> PanelDataClass;

	UPROPERTY(EditAnywhere, Category="FortCreativeItemListMenu")
	TObjectPtr<UDataTable> ItemListCategorySource;

	UPROPERTY(BlueprintReadWrite, Category="FortCreativeItemListMenu", meta=(ExposeOnSpawn="TRUE"))
	TObjectPtr<UFortCreativeItemListPanelData> ItemListPanelData;

	UPROPERTY(EditAnywhere, Category="FortCreativeItemListMenu")
	TSubclassOf<UFortCreativeItemListTabPanel> InventoryTabClass;

	UPROPERTY(EditAnywhere, Category="FortCreativeItemListMenu")
	TSubclassOf<UFortCreativeLevelManagementTabPanel> LevelManagementTabClass;

	UPROPERTY(EditAnywhere, Category="FortCreativeItemListMenu")
	TSubclassOf<UCommonButtonLegacy> InventoryTabButton;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnItemEquipped(const FFortItemEntry& EquippedItemEntry);

private:
	UFUNCTION()
	void HandleAddSelectionToMoveToolComplete();

	UFUNCTION()
	void HandleChestItemCountChanged(int32 Count);

	UFUNCTION()
	void HandleEquipItem(const FFortItemEntry& ItemEntry);

	UFUNCTION()
	void HandleFilterChanged();

	UFUNCTION()
	void HandleFilterPanelIsFocused(bool bIsFocused);

	UFUNCTION()
	void HandleItemDetailsInputAction();

	UFUNCTION()
	void HandleQuickbarPanelIsFocused(bool bIsFocused);

	UFUNCTION()
	void HandleSelectionChanged(UFortCreativeContentBrowserTabPanelBase* Tab);

	UFUNCTION(BlueprintCallable)
	void HandleTabSelected(FName TabId);

	UFUNCTION()
	void OnContentRatingFilterChanged();

	UFUNCTION()
	void OnCursorModeChanged(bool bCursorModeEnabled, FName ActionName, UUserWidget* CursorModeContentWidget);

	UFUNCTION()
	void VerifyPermissionsToCreativeInventory();

	UPROPERTY(BlueprintAssignable, meta=(AllowPrivateAccess, DisplayName="On Item Selected"))
	FSelectItemToSpawnDelegate BP_OnItemSelected;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeItemListMenu", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<UFortCreativeItemListTabPanel> ChestTabPanel;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeItemListMenu", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<UFortCreativeLevelManagementTabPanel> LevelManagementTabPanel;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeItemListMenu", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<UFortCreativeItemListTabPanel> SubItemsTabPanel;

	UPROPERTY(EditDefaultsOnly, Category="Fort Tab Interface")
	FName TabNameId;

	UPROPERTY(EditDefaultsOnly, Category="Fort Tab Interface")
	FFortTabButtonLabelInfo TabButtonLabelInfo;

	UPROPERTY(EditDefaultsOnly, Category="Athena Map Screen Container Tab Interface")
	FAthenaMapScreenContainerTabInfo MapScreenContainerTabInfo;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativeItemListMenu")
	bool bAddItemToInventoryOnEquip;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativeItemListMenu")
	bool bLoadItemsOnInitialized;

	UPROPERTY(Transient)
	int32 LastUsedSlot;

	UPROPERTY(BlueprintReadWrite, Category="FortCreativeItemListMenu", meta=(AllowPrivateAccess))
	FName LastSelectedTab;

	UPROPERTY(Export, meta=(EditInline="true"))
	TMap<FName, TObjectPtr<UFortCreativeItemListTabPanel>> TabMap;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeItemListMenu", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortTabListWidgetBase_Legacy> TabList_Categories;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonWidgetSwitcherLegacy> Switcher_Categories;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidgetSwitcher> Switcher_NoItemInChest;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidgetSwitcher> Switcher_CommandBar;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeItemListMenu", meta=(AllowPrivateAccess, BindWidget, EditInline="true", OptionalWidget="TRUE"))
	TObjectPtr<UFortCreativeMenuQuickbar> MenuQuickbar_QuickBars;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_ResetChest;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_CreateChest;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_AddToQuickBar;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_OpenItem;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_PlaceNow;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Equip;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_AddToChest;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Drop;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_CreateLlama;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_RemoveFromChest;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_SearchFilters;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeItemListMenu", meta=(AllowPrivateAccess, BindWidget, EditInline="true", OptionalWidget="TRUE"))
	TObjectPtr<UContentBrowserFiltersPanel> FiltersPanel;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonVisibilitySwitcher> Switcher_SidePanels;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortCreativeItemDetailsSidePanel> ItemDetailsSidePanel_DefaultSidePanel;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidgetSwitcher> Switcher_InventoryPermission;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeItemListMenu", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UWidgetSwitcher> Switcher_EditorConnected;

};

