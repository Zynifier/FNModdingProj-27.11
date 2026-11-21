// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Core/FortInitializeFromObjectInterface.h"
#include "FortCreativeContentBrowserTabPanelBase.h"
#include "Items/FortItemEntry.h"
#include "FortCreativeItemListTabPanel.generated.h"

class UAthenaCreativeItemTileView;
class UFortCreativeItemListMenu;
enum class EFortItemCardSize : uint8;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnItemActivatedDelegate, FFortItemEntry, ItemToSpawn);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnItemCountChangedDelegate, int32, count);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnItemDetailsInputAction);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnItemEquippedDelegate, const FFortItemEntry&, ItemEquipped);

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCreativeItemListTabPanel : public UFortCreativeContentBrowserTabPanelBase, public IFortInitializeFromObjectInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void AddItem(UPARAM(ref) FFortItemEntry& ItemToAdd);

	UFUNCTION(BlueprintCallable)
	void AddItemToSource(UPARAM(ref) FFortItemEntry& ItemToAdd);

	UFUNCTION(BlueprintPure)
	bool CanPlayerCreateInVolume() const;

	UFUNCTION(BlueprintCallable)
	void ClearAllItems();

	UFUNCTION(BlueprintCallable)
	void ClearFilteredItems();

	UFUNCTION(BlueprintImplementableEvent)
	void FocusCurrentSelection();

	UFUNCTION(BlueprintPure)
	EFortItemCardSize GetCardSizeForCategory() const;

	UFUNCTION(BlueprintPure)
	bool GetCollapseBorderPadFlagForCategory() const;

	UFUNCTION(BlueprintPure)
	bool IsEmpty();

	UFUNCTION(BlueprintImplementableEvent)
	void ItemEquipped(const FFortItemEntry& Item);

	UFUNCTION(BlueprintCallable)
	void RemoveSelectedItem();

	UFUNCTION(BlueprintCallable)
	void RestoreLastSelection();

	UPROPERTY(BlueprintAssignable)
	FOnItemCountChangedDelegate OnSourceItemCountChanged;

	UPROPERTY(EditAnywhere, Category="FortCreativeItemListTabPanel", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle ItemDetailsInputRowHandle;

	UPROPERTY()
	FOnItemDetailsInputAction OnItemDetailsInputAction;

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeItemListTabPanel", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaCreativeItemTileView> CreativeTileView_ItemOptions;

private:
	UPROPERTY(BlueprintReadWrite, Category="FortCreativeItemListTabPanel", meta=(AllowPrivateAccess="true"))
	FFortItemEntry CurrentItemEntry;

	UPROPERTY(BlueprintAssignable, meta=(AllowPrivateAccess="true"))
	FOnItemCountChangedDelegate OnItemCountChanged;

	UPROPERTY(BlueprintReadOnly, Category="FortCreativeItemListTabPanel", meta=(AllowPrivateAccess="true"))
	TArray<FFortItemEntry> Items;

	UPROPERTY(BlueprintReadOnly, Category="FortCreativeItemListTabPanel", meta=(AllowPrivateAccess="true"))
	TArray<FFortItemEntry> SourceItems;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortCreativeItemListMenu> CreativeItemListMenuParent;

};

