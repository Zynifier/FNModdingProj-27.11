// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Engine/DataTable.h"
#include "FortItemDetailsActivatablePanel_STW.generated.h"

class UCommonLoadGuard;
class UCommonWidgetSwitcherLegacy;
class UFortItem;
class UFortItemManagementItemDetailsPanel_STW;
class UFortItemManagementMulchDetailsPanel_STW;
class UFortItemManagementScreen_STW;
class UFortTooltipLoadingWrapper;
class UFortWorldItem;
class UWidget;
enum class EFortQuickBars : uint8;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortItemDetailsActivatablePanel_STW : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Action Handling")
	void HandleBackNative();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Action Handling")
	void HandleCompare();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Action Handling")
	void HandleConsumeItem();

	UFUNCTION(BlueprintImplementableEvent, Category="Item Management|Details")
	void HandleConsumeItemProgressChangedBP();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Action Handling")
	void HandleCraft();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Action Handling")
	void HandleCraftingOptions();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Action Handling")
	void HandleDestroy();

	UFUNCTION(BlueprintImplementableEvent, Category="Item Management|Details")
	void HandleDifferentItemToCompareSetBP();

	UFUNCTION(BlueprintImplementableEvent, Category="Item Management|Details")
	void HandleDifferentItemToDetailSetBP();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Action Handling")
	void HandleDrop();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Action Handling")
	void HandleEquip();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Action Handling")
	void HandleInspect();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Action Handling")
	void HandleMore();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Action Handling")
	void HandleMulch();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Action Handling")
	void HandleMulchNative();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Action Handling")
	void HandleOpenCustomFilter();

	UFUNCTION(BlueprintCallable, Category="Action Refreshing")
	void HandleQuickbarContentsChanged(EFortQuickBars QuickBarIndex, const TArray<int32>& ChangedSlots);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Action Handling")
	void HandleSort();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Action Handling")
	void HandleSwitchPanel();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Action Handling")
	void HandleTransfer();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Action Handling")
	void HandleWithdrawAll();

	UFUNCTION(BlueprintCallable, Category="Action Handling")
	void HandleWorldItemListChanged(const TArray<UFortWorldItem*>& ItemsAdded, const TArray<UFortWorldItem*>& ItemsRemoved);

	UFUNCTION(BlueprintCallable, Category="Action Handling")
	void HandleWorldItemsChanged();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	bool MulchQuestComplete();

	UFUNCTION(BlueprintCallable, Category="Action Refreshing")
	void RefreshConsumeAction();

	UFUNCTION(BlueprintCallable, Category="Action Refreshing")
	void RefreshCraftActions();

	UFUNCTION(BlueprintCallable, Category="Action Refreshing")
	void RefreshDestroyAction();

	UFUNCTION(BlueprintCallable, Category="Action Refreshing")
	void RefreshDropAction();

	UFUNCTION(BlueprintCallable, Category="ActionRefreshing")
	void RefreshOnMenuChange();

	UFUNCTION(BlueprintCallable, Category="ActionRefreshing")
	void RefreshOnNewItemSelected();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void RefreshSwitchPanelAction();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void RefreshTransferActions();

	UFUNCTION(BlueprintCallable, Category="Action Registration")
	void RegisterBack();

	UFUNCTION(BlueprintCallable, Category="Action Registration")
	void RegisterCompare();

	UFUNCTION(BlueprintCallable, Category="Action Registration")
	void RegisterConsumeItem();

	UFUNCTION(BlueprintCallable, Category="Action Registration")
	void RegisterCraft();

	UFUNCTION(BlueprintCallable, Category="Action Registration")
	void RegisterDropOrDestroy();

	UFUNCTION(BlueprintCallable, Category="Action Registration")
	void RegisterEquip();

	UFUNCTION(BlueprintCallable, Category="Action Registration")
	void RegisterInspect();

	UFUNCTION(BlueprintCallable, Category="Action Registration")
	void RegisterInspectUpgrade();

	UFUNCTION(BlueprintCallable, Category="Action Registration")
	void RegisterInventoryInspect();

	UFUNCTION(BlueprintCallable, Category="Action Registration")
	void RegisterLeaveInventory();

	UFUNCTION(BlueprintCallable, Category="Action Registration")
	void RegisterMore();

	UFUNCTION(BlueprintCallable, Category="Action Registration")
	void RegisterMulch();

	UFUNCTION(BlueprintCallable, Category="Action Registration")
	void RegisterOpenCustomFilter();

	UFUNCTION(BlueprintCallable, Category="Action Registration")
	void RegisterRetire();

	UFUNCTION(BlueprintCallable, Category="Action Registration")
	void RegisterSort();

	UFUNCTION(BlueprintCallable, Category="Action Registration")
	void RegisterTransferActions();

	UFUNCTION(BlueprintCallable)
	void SetInputActionState(const FDataTableRowHandle& RowHandle, bool State);

	UFUNCTION(BlueprintCallable, Category="ActionRegistration")
	void SetupInputHandling();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input")
	FDataTableRowHandle DropInputActionHandle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input")
	FDataTableRowHandle DestroyInputActionHandle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input")
	FDataTableRowHandle BackInputActionHandle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input")
	FDataTableRowHandle LeaveInventoryInputActionHandle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input")
	FDataTableRowHandle CraftingOptionsInputActionHandle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input")
	FDataTableRowHandle CraftInputActionHandle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input")
	FDataTableRowHandle MulchInputActionHandle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input")
	FDataTableRowHandle InspectInputActionHandle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input")
	FDataTableRowHandle InventoryInspectInputActionHandle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input")
	FDataTableRowHandle UnequipInputActionHandle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input")
	FDataTableRowHandle EquipInputActionHandle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input")
	FDataTableRowHandle MoreInfoInputActionHandle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input")
	FDataTableRowHandle WithdrawAllInputActionHandle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input")
	FDataTableRowHandle SwitchPanelInputActionHandle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input")
	FDataTableRowHandle TransferInputActionHandle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input")
	FDataTableRowHandle ConsumeItemInputActionHandle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input")
	FDataTableRowHandle SortInputActionHandle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input")
	FDataTableRowHandle CompareInputActionHandle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input")
	FDataTableRowHandle OpenCustomFilterInputActionHandle;

	UPROPERTY(BlueprintReadOnly, Category="Item Management|Details")
	TWeakObjectPtr<UFortItem> ItemToDetail;

	UPROPERTY(BlueprintReadOnly, Category="Item Management|Details")
	TWeakObjectPtr<UFortItem> ItemToCompareWith;

	UPROPERTY(BlueprintReadOnly, Export, Category="Item Management|Details")
	TWeakObjectPtr<UFortItemManagementScreen_STW> HostItemManagementScreen;

private:
	UFUNCTION()
	void HandleItemToDetailTooltipAssetsLoaded();

	UPROPERTY()
	UFortTooltipLoadingWrapper* ItemToDetailLoadingWrapper;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	UCommonLoadGuard* ItemToDetailLoadGuard;

};

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortItemCompareModeActivatablePanel_STW : public UFortItemDetailsActivatablePanel_STW
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemCompareModeActivatablePanel_STW", meta=(BindWidget, EditInline="true"))
	UFortItemManagementItemDetailsPanel_STW* ComparisonModeLeftItemDetailsPanel;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemCompareModeActivatablePanel_STW", meta=(BindWidget, EditInline="true"))
	UFortItemManagementItemDetailsPanel_STW* ComparisonModeRightItemDetailsPanel;

};

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortItemDetailsModeActivatablePanel_STW : public UFortItemDetailsActivatablePanel_STW
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemDetailsModeActivatablePanel_STW", meta=(BindWidget, EditInline="true"))
	UCommonWidgetSwitcherLegacy* DetailPanelWidgetSwitcher;

private:
	UFUNCTION()
	void HandleOnActiveWidgetChanged(UWidget* ActiveWidget, int32 ActiveWidgetIndex);

};

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortItemMulchModeActivatablePanel_STW : public UFortItemDetailsActivatablePanel_STW
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemMulchModeActivatablePanel_STW", meta=(BindWidget, EditInline="true"))
	UFortItemManagementItemDetailsPanel_STW* MulchModeItemDetailsPanel;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemMulchModeActivatablePanel_STW", meta=(BindWidget, EditInline="true"))
	UFortItemManagementMulchDetailsPanel_STW* MulchDetailsPanel;

};

