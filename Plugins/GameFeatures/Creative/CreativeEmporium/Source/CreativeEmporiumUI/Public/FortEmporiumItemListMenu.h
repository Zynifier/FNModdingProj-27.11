// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "UObject/NoExportTypes.h"
#include "Athena/AthenaMapScreenContainerTabInterface.h"
#include "FortTabInterface.h"
#include "FortTabListWidgetBase.h"
#include "Items/FortItemEntry.h"
#include "FortEmporiumItemListMenu.generated.h"

class AActor;
class UAthenaCustomizationPickerSortAndFilterBlade;
class UCommonAnimatedSwitcher;
class UCommonButtonBase;
class UCommonVisibilitySwitcher;
class UDataTable;
class UEmporiumBrowserFiltersPanel;
class UFortCreativeContentBrowserTabPanelBase;
class UFortCreativeItemListPanelData;
class UFortCreativeLevelManagementTabPanel;
class UFortCreativeMenuQuickbar;
class UFortEmporiumHomeTabPanel;
class UFortEmporiumItemDefinition;
class UFortEmporiumItemDetailsPanel;
class UFortEmporiumItemListTabPanel;
class UFortItemDefinition;
class UOverlay;
class UUserWidget;
class UWidgetSwitcher;
enum class EFortContentBrowserQuickbarState : uint8;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEmporiumItemSelectedDelegate, FFortItemEntry, ItemSelected);

UCLASS(BlueprintType)
class UFortEmporiumCategoryEntry : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortEmporiumCategoryEntry")
	FString Path;

	UPROPERTY(BlueprintReadOnly, Category="FortEmporiumCategoryEntry")
	FString Hash;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortEmporiumItemListMenu : public UCommonActivatableWidget, public IFortTabInterface, public IAthenaMapScreenContainerTabInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	bool AddSelectionToQuickBar();

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

	UFUNCTION(BlueprintPure)
	FName GetLastSelectedTabName() const;

	UFUNCTION(BlueprintPure)
	UFortItemDefinition* GetSubTabSelectedItemDefinition() const;

	UFUNCTION(BlueprintCallable)
	void InitializeFabTab();

	UFUNCTION(BlueprintCallable)
	void InitializeTabs();

	UFUNCTION(BlueprintPure)
	bool IsSubTabOpened() const;

	UFUNCTION(BlueprintCallable)
	void LoadFabItems();

	UFUNCTION()
	void NativeOnBuiltInItemsLoaded();

	UFUNCTION()
	void NativeOnItemsLoaded();

	UFUNCTION()
	void NativeOnItemsRefreshed();

	UFUNCTION(BlueprintImplementableEvent)
	void OnBuiltInItemsLoaded();

	UFUNCTION()
	void OnCreativeQuickbarComponentLoaded();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnExitSubTab();

	UFUNCTION(BlueprintImplementableEvent)
	void OnItemsLoaded();

	UFUNCTION(BlueprintImplementableEvent)
	void OnSearchFiltersVisibilityChanged(bool bIsVisible);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnSelectionOpened(const UFortItemDefinition* SelectedItemDefinition);

	UFUNCTION(BlueprintCallable)
	bool OpenSelection();

	UFUNCTION(BlueprintCallable)
	bool PlaceSelectionInMoveTool();

	UFUNCTION(BlueprintCallable)
	void RefreshTabWarningState();

	UFUNCTION(BlueprintCallable)
	void SetIsItemCommandsEnabled(bool bInIsItemCommandEnabled);

	UFUNCTION(BlueprintCallable)
	void SetSubTabOpened(UFortItemDefinition* ItemDefinition);

	UFUNCTION(BlueprintCallable)
	void SpawnContainer(TSubclassOf<AActor> SupplyDropClass);

	UFUNCTION(BlueprintCallable)
	void SwitchItemDetailsPanel(bool bUseLegacy = false);

	UFUNCTION(BlueprintCallable)
	void UpdateDetailsPanel();

	UPROPERTY(EditAnywhere, Category="FortEmporiumItemListMenu")
	TSubclassOf<UFortCreativeItemListPanelData> PanelDataClass;

	UPROPERTY(EditAnywhere, Category="FortEmporiumItemListMenu")
	TObjectPtr<UDataTable> ItemListCategorySource;

	UPROPERTY(BlueprintReadWrite, Category="FortEmporiumItemListMenu", meta=(ExposeOnSpawn="TRUE"))
	TObjectPtr<UFortCreativeItemListPanelData> ItemListPanelData;

	UPROPERTY(EditAnywhere, Category="FortEmporiumItemListMenu")
	TSubclassOf<UFortEmporiumItemListTabPanel> InventoryTabClass;

	UPROPERTY(EditAnywhere, Category="FortEmporiumItemListMenu")
	TSubclassOf<UFortCreativeLevelManagementTabPanel> LevelManagementTabClass;

	UPROPERTY(EditAnywhere, Category="FortEmporiumItemListMenu")
	TSubclassOf<UFortEmporiumHomeTabPanel> HomeTabClass;

	UPROPERTY(EditAnywhere, Category="FortEmporiumItemListMenu")
	TSubclassOf<UCommonButtonBase> InventoryTabButton;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnItemEquipped(const FFortItemEntry& EquippedItemEntry);

	UFUNCTION(BlueprintImplementableEvent)
	void OnQuickbarStateChanged(const EFortContentBrowserQuickbarState State);

	UFUNCTION(BlueprintImplementableEvent)
	void OnShowCategoryModal(bool bShowModal);

private:
	UFUNCTION()
	void HandleAddSelectionToMoveToolComplete();

	UFUNCTION()
	void HandleCategoryActivated(FName CategoryID);

	UFUNCTION()
	void HandleCategoryFocused(FName CategoryID);

	UFUNCTION()
	void HandleChestItemCountChanged(int32 Count);

	UFUNCTION()
	void HandleEquipItem(const FFortItemEntry& ItemEntry);

	UFUNCTION()
	void HandleFilterButtonClicked(FName FilterNameId, UCommonButtonBase* NewButton);

	UFUNCTION()
	void HandleFilterChanged();

	UFUNCTION()
	void HandleFilterPanelIsFocused(bool bIsFocused);

	UFUNCTION()
	void HandleGlobalSortPanelToggle();

	UFUNCTION()
	void HandleItemClicked(const FFortItemEntry& ItemEntry);

	UFUNCTION()
	void HandleItemDoubleClicked(const FFortItemEntry& ItemEntry);

	UFUNCTION()
	void HandleItemTagSelected(const FName& TagID, bool bSelected);

	UFUNCTION()
	void HandleItemThumbnailDownloaded(UFortEmporiumItemDefinition* ItemDefinition);

	UFUNCTION(BlueprintCallable)
	void HandleModalHitBlockerClicked();

	UFUNCTION()
	void HandleQuickbarPanelIsFocused(bool bIsFocused);

	UFUNCTION()
	void HandleQuickbarStateChanged(const EFortContentBrowserQuickbarState State);

	UFUNCTION()
	void HandleSelectionChanged(UFortCreativeContentBrowserTabPanelBase* Tab);

	UFUNCTION()
	void HandleSortButtonClicked(FName SortNameId, UCommonButtonBase* NewButton);

	UFUNCTION()
	void HandleSortChanged();

	UFUNCTION()
	void HandleTabItemDetailClicked(const FName& TagID);

	UFUNCTION(BlueprintCallable)
	void HandleTabSelected(FName TabId, bool bCaptureFocus);

	UFUNCTION()
	void HandleTabSortButtonClicked();

	UFUNCTION()
	void OnContentRatingFilterChanged();

	UFUNCTION()
	void OnCursorModeChanged(bool bCursorModeEnabled, FName ActionName, UUserWidget* CursorModeContentWidget);

	UFUNCTION()
	void OnFabCategoryListLoaded(bool bSuccess, const FString& JSONString);

	UFUNCTION()
	void OnFabItemQueryComplete(bool bSuccess, const FString& JSONString);

	UFUNCTION()
	void UpdatePermissionsDisplay();

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEmporiumItemListMenu", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<UFortEmporiumItemListTabPanel> ChestTabPanel;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEmporiumItemListMenu", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<UFortCreativeLevelManagementTabPanel> LevelManagementTabPanel;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEmporiumItemListMenu", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<UFortEmporiumHomeTabPanel> HomeTabPanel;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEmporiumItemListMenu", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<UFortEmporiumItemListTabPanel> FabTabPanel;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEmporiumItemListMenu", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<UFortEmporiumItemListTabPanel> SubItemsTabPanel;

	UPROPERTY(EditDefaultsOnly, Category="Fort Tab Interface")
	FName FabTabNameId;

	UPROPERTY(EditDefaultsOnly, Category="Fort Tab Interface")
	FFortTabButtonLabelInfo TabButtonLabelInfo;

	UPROPERTY(EditDefaultsOnly, Category="Athena Map Screen Container Tab Interface")
	FAthenaMapScreenContainerTabInfo MapScreenContainerTabInfo;

	UPROPERTY(EditDefaultsOnly, Category="Fort Tab Interface")
	bool bIsDefaultActiveTab;

	UPROPERTY(EditDefaultsOnly, Category="FortEmporiumItemListMenu")
	bool bAddItemToInventoryOnEquip;

	UPROPERTY(EditDefaultsOnly, Category="FortEmporiumItemListMenu")
	bool bLoadItemsOnInitialized;

	UPROPERTY(Transient)
	int32 LastUsedSlot;

	UPROPERTY(Export, meta=(EditInline="true"))
	TMap<FName, TObjectPtr<UFortCreativeContentBrowserTabPanelBase>> TabMap;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortEmporiumItemDefinition>> EmporiumItemDefinitionList;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonAnimatedSwitcher> Switcher_Categories;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidgetSwitcher> Switcher_ItemTabWarnings;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_ChestEmpty;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_TabEmpty;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_DownloadingFabCategories;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_FabCategoriesNotLoaded;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidgetSwitcher> Switcher_CommandBar;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_ChestCommands;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_VendCommands;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEmporiumItemListMenu", meta=(AllowPrivateAccess, BindWidget, EditInline="true", OptionalWidget="TRUE"))
	TObjectPtr<UFortCreativeMenuQuickbar> MenuQuickbar_QuickBars;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_ResetChest;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_CreateChest;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_AddToQuickBar;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_OpenItem;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_PlaceNow;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Equip;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_AddToChest;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Drop;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_CreateLlama;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_RemoveFromChest;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_SearchFilters;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonAnimatedSwitcher> Switcher_LeftPanel;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEmporiumItemListMenu", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UEmporiumBrowserFiltersPanel> FiltersPanel;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEmporiumItemListMenu", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortEmporiumItemDetailsPanel> SubTabItemDetailsPanel;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEmporiumItemListMenu", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UAthenaCustomizationPickerSortAndFilterBlade> Blade_SortAndFilter;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonVisibilitySwitcher> Switcher_SidePanels;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortEmporiumItemDetailsPanel> ItemDetailsSidePanel_DefaultSidePanel;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonVisibilitySwitcher> Switcher_ProductPage;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_ItemBrowser;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortEmporiumItemDetailsPanel> ItemProductPagePanel;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidgetSwitcher> Switcher_InventoryPermission;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_EmporiumPanel;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_InventoryNotAllowed;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_EditorDisconnected;

};

