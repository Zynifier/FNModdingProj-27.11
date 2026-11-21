// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ItemTiles/FortItemTileButton.h"
#include "STW/FortHomebase/FortHomebaseManager.h"
#include "FortItemManagementItemTileButton_STW.generated.h"

class UFortAccountItem;
class UFortDynamicEntryBox;
class UFortInventoryContext;
class UFortItemManagementScreen_STW;
class UMenuAnchor;
class UOverlay;
class UUserWidget;
enum class EFortItemManagementMode : uint8;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortItemManagementItemTileButton_STW : public UFortItemTileButton
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Item Management|Equip Slot")
	bool IsValidEquipSlotOverlayIndex(const int32 SlotIndex) const;

	UFUNCTION(BlueprintCallable, Category="Item Management|Equip Slot")
	void PopulateEquipSlotOverlay();

	UFUNCTION(BlueprintCallable, Category="Item Management|Equip Slot")
	void UpdateEquipSlotOverlay(const int32 CurrentSlotIndex);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemManagementItemTileButton_STW")
	TWeakObjectPtr<UFortItemManagementScreen_STW> HostItemManagementScreen;

protected:
	UFUNCTION(BlueprintPure, Category="Item Management|Item Tile")
	FHomebaseSquadSlotId GetHomebaseSquadSlotForItem() const;

	UFUNCTION(BlueprintPure, Category="Item Management|Item Tile")
	EFortItemManagementMode GetItemManagementMode() const;

	UFUNCTION(BlueprintImplementableEvent, Category="Item Management|Item Tile", meta=(DisplayName="Handle Different Item Management Mode Set"))
	void HandleDifferentItemManagementModeSetBP();

	UFUNCTION(BlueprintImplementableEvent, Category="Item Management|Item Tile")
	void HandleEquipSlotChanged(int32 EquipSlot);

	UFUNCTION(BlueprintImplementableEvent, Category="Item Management|Item Tile")
	void HandleHasItemToCompareDetailsWithChanged();

	UFUNCTION(BlueprintImplementableEvent, Category="Item Management|Item Tile")
	void HandleHasItemToDetailChanged();

	UFUNCTION(BlueprintImplementableEvent, Category="Item Management|Item Tile")
	void HandleItemChangedBP();

	UFUNCTION(BlueprintImplementableEvent, Category="Item Management|Item Tile")
	void HandleItemMulchStateChanged();

	UFUNCTION(BlueprintImplementableEvent, Category="Item Management|Item Tile")
	void HandleShowCollectionBookIndicatorChanged();

	UFUNCTION(BlueprintImplementableEvent, Category="Item Management|Item Tile")
	void HandleShowRefundIndicatorChanged();

	UPROPERTY(BlueprintReadOnly, Category="Item Management|Item Tile")
	bool HasTheItemToDetail;

	UPROPERTY(BlueprintReadOnly, Category="Item Management|Item Tile")
	bool HasTheItemToCompareDetailsWith;

	UPROPERTY(BlueprintReadOnly, Category="Item Management|Item Tile")
	bool HasAnItemMarkedForMulching;

	UPROPERTY(BlueprintReadOnly, Category="Item Management|Item Tile")
	int32 MulchCount;

	UPROPERTY(BlueprintReadOnly, Export, Category="Item Management|Item Tile", meta=(BindWidget, EditInline="true"))
	UOverlay* NotCraftableOverlay;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortItemManagementItemTileButton_STW", meta=(BindWidget, EditInline="true"))
	UFortDynamicEntryBox* EquipSlotOverlay;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemManagementItemTileButton_STW", meta=(BindWidget, EditInline="true"))
	UMenuAnchor* PopupMenuAnchor;

	UPROPERTY(BlueprintReadOnly, Category="Item Management|Item Tile")
	bool ShowCollectionBookIndicator;

	UPROPERTY(BlueprintReadOnly, Category="Item Management|Item Tile")
	bool ShowRefundIndicator;

private:
	UFUNCTION()
	UUserWidget* GetPopupMenu();

	UFUNCTION()
	void OnSlotItemComplete(const UFortAccountItem* SlottedItem, FName SlotId);

	UPROPERTY(Transient)
	UFortInventoryContext* InventoryContext;

};

