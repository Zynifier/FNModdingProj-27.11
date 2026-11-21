// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Core/FortInitializeFromObjectInterface.h"
#include "FortCreativeContentBrowserTabPanelBase.h"
#include "Items/FortItemEntry.h"
#include "FortEmporiumItemListTabPanel.generated.h"

class UAthenaCreativeItemTileView;
class UCommonButtonBase;
class UFortEmporiumItemListMenu;
class UFortItemDefinition;
enum class EFortItemCardSize : uint8;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEmporiumItemActivatedDelegate, FFortItemEntry, ItemToSpawn);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEmporiumItemClickedDelegate, const FFortItemEntry&, ItemClicked);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEmporiumItemCountChangedDelegate, int32, count);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEmporiumItemDoubleClickedDelegate, const FFortItemEntry&, ItemClicked);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEmporiumItemEquippedDelegate, const FFortItemEntry&, ItemEquipped);

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortEmporiumItemListTabPanel : public UFortCreativeContentBrowserTabPanelBase, public IFortInitializeFromObjectInterface
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

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
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

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void SetActiveItemDetailTags(const TArray<FName>& TagIDs);

	UFUNCTION(BlueprintPure)
	bool ShowLegacyItemDetailsPanel() const;

	UFUNCTION(BlueprintImplementableEvent)
	void ShowTopButtonBar(bool bShow);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateSortButton(const FText& SortType);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void UpdateTabHeader();

	UPROPERTY(BlueprintAssignable)
	FOnEmporiumItemCountChangedDelegate OnSourceItemCountChanged;

	UPROPERTY(BlueprintAssignable)
	FOnEmporiumItemClickedDelegate OnItemClickedDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnEmporiumItemDoubleClickedDelegate OnItemDoubleClickedDelegate;

protected:
	UFUNCTION(BlueprintPure)
	UFortItemDefinition* GetSubTabSelectedItemDefinition() const;

	UFUNCTION(BlueprintCallable)
	void HandleItemDetailTagSelected(const FName& TagID);

	UFUNCTION(BlueprintPure)
	bool IsSubTabOpened() const;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEmporiumItemListTabPanel", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaCreativeItemTileView> CreativeTileView_ItemOptions;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEmporiumItemListTabPanel", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Sort;

private:
	UPROPERTY(BlueprintReadWrite, Category="FortEmporiumItemListTabPanel", meta=(AllowPrivateAccess="true"))
	FFortItemEntry CurrentItemEntry;

	UPROPERTY(BlueprintAssignable, meta=(AllowPrivateAccess="true"))
	FOnEmporiumItemCountChangedDelegate OnItemCountChanged;

	UPROPERTY(BlueprintReadOnly, Category="FortEmporiumItemListTabPanel", meta=(AllowPrivateAccess="true"))
	TArray<FFortItemEntry> Items;

	UPROPERTY(BlueprintReadOnly, Category="FortEmporiumItemListTabPanel", meta=(AllowPrivateAccess="true"))
	TArray<FFortItemEntry> SourceItems;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortEmporiumItemListMenu> EmporiumItemListMenuParent;

};

