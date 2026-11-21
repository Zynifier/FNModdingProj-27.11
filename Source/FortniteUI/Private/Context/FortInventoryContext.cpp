// Copyright Epic Games, Inc. All Rights Reserved.

#include "Context/FortInventoryContext.h"

bool UFortInventoryContext::AreAnyItemsAnimate(const TArray<UFortItem*>& Items)
{
	return false;
}

bool UFortInventoryContext::AreAnyItemsInanimate(const TArray<UFortItem*>& Items)
{
	return false;
}

bool UFortInventoryContext::AreAnyItemsUnseenForInventoryFilter(const EFortFrontendInventoryFilter InventoryFilter) const
{
	return false;
}

bool UFortInventoryContext::CanCraftSchematic(UFortSchematicItem* SchematicItem, EFortCraftFailCause& FailCause, EFortItemTier RequestedTier, int32 CraftCount) const
{
	return false;
}

bool UFortInventoryContext::CanEvolve(const UFortItem* Item, TArray<EItemEvolutionRestrictionReason>& OutRestrictionReasons) const
{
	return false;
}

bool UFortInventoryContext::CanItemBeMulched(const UFortItem* Item, FText& OutRestrictionReasons) const
{
	return false;
}

bool UFortInventoryContext::CanItemBePromoted(const UFortItem* Item, TArray<FFortItemQuantityPair>& Costs) const
{
	return false;
}

bool UFortInventoryContext::CanRecycle(const UFortItem* Item, TArray<EItemRecyclingRestrictionReason>& OutRestrictionReasons) const
{
	return false;
}

bool UFortInventoryContext::CanSwapItem(UFortItem* Item, EFortQuickBars TargetQuickbar, int32 TargetSlot)
{
	return false;
}

bool UFortInventoryContext::CanUpgradeItemRarity(const UFortItem* Item, TArray<EItemEvolutionRestrictionReason>& OutRestrictionReasons)
{
	return false;
}

bool UFortInventoryContext::CraftAndSlotSchematic(UFortSchematicItem* SchematicItem, int32 PostCraftSlot, EFortCraftFailCause& FailCause, EFortItemTier RequestedTier, int32 CraftCount)
{
	return false;
}

bool UFortInventoryContext::CraftSchematic(UFortSchematicItem* SchematicItem, EFortCraftFailCause& FailCause, EFortItemTier RequestedTier, int32 CraftCount)
{
	return false;
}

void UFortInventoryContext::DestroyWorldItem(UFortItem* Item)
{
}

bool UFortInventoryContext::DropCreativeItemOnQuickBar(UFortItem* Item, EFortQuickBars TargetQuickbar, int32 TargetSlot)
{
	return false;
}

bool UFortInventoryContext::DropItem(const UFortWorldItem* ItemBeingDropped, const int32 Quantity)
{
	return false;
}

bool UFortInventoryContext::DropItemOnQuickBar(UFortItem* Item, EFortQuickBars TargetQuickbar, int32 TargetSlot)
{
	return false;
}

void UFortInventoryContext::EnumerateRecyclingWarningsForItems(const TArray<UFortItem*>& Items, TArray<EItemRecyclingWarning>& OutWarnings)
{
}

void UFortInventoryContext::EquipItem(UFortItem* Item)
{
}

void UFortInventoryContext::ForceItemsChanged(const TArray<EFortInventoryFilter>& InventoryFilters)
{
}

void UFortInventoryContext::GetAccountItemsByFilterType(const FString SearchText, const EInventoryContentSortType SortType, const EFortInventoryFilter SubType, TArray<UFortAccountItem*>& OutItemList) const
{
}

void UFortInventoryContext::GetAccountItemsByType(EFortItemType ItemType, TArray<UFortAccountItem*>& Items) const
{
}

void UFortInventoryContext::GetBackpackItemCounts(int32& ItemsCount, int32& MaxItemsCount, int32& OverflowItemsCount) const
{
}

int32 UFortInventoryContext::GetBackpackOverflowFromAddingItem(UFortWorldItem* Item, int32 Count) const
{
	return int32();
}

TArray<FRecipe> UFortInventoryContext::GetConversionRecipesFromItemDefintion(UFortItemDefinition* ItemDefinition)
{
	return TArray<FRecipe>();
}

int32 UFortInventoryContext::GetCountOfVaultLimitedItems() const
{
	return int32();
}

UFortWorldItemDefinition* UFortInventoryContext::GetCurrentAmmoItemDefinition() const
{
	return nullptr;
}

int32 UFortInventoryContext::GetCurrentResourceCount() const
{
	return int32();
}

UFortResourceItemDefinition* UFortInventoryContext::GetCurrentResourceItemDefinition() const
{
	return nullptr;
}

void UFortInventoryContext::GetDeployableBaseItemCounts(int32& ItemsCount, int32& MaxItemsCount, int32& OverflowItemsCount) const
{
}

int32 UFortInventoryContext::GetDeployableBaseOverflowFromAddingItem(UFortWorldItem* Item, int32 Count) const
{
	return int32();
}

AFortWeapon* UFortInventoryContext::GetEquippedWeapon() const
{
	return nullptr;
}

void UFortInventoryContext::GetItemInstancesByDefinition(UFortItemDefinition* ItemDefinition, TArray<UFortItem*>& Items) const
{
}

FText UFortInventoryContext::GetItemStackCount_Creative(const int32 Quantity)
{
	return FText();
}

TArray<UFortItem*> UFortInventoryContext::GetItemsToMulchBP() const
{
	return TArray<UFortItem*>();
}

int32 UFortInventoryContext::GetLevelsPerItemPromotion() const
{
	return int32();
}

int32 UFortInventoryContext::GetNumInInventory(UFortItemDefinition* ItemDefinition, bool bIncludeReserved) const
{
	return int32();
}

int32 UFortInventoryContext::GetNumItemsToMulch() const
{
	return int32();
}

int32 UFortInventoryContext::GetNumOfItemToMulch(const UFortItem* Item) const
{
	return int32();
}

void UFortInventoryContext::GetQuickbarFocus(EFortQuickBars& OutQuickBar, int32& OutSlot, int32& OutSecondarySlot, int32& OutPreviousFocusedSlot) const
{
}

UFortItem* UFortInventoryContext::GetQuickBarSlottedItem(EFortQuickBars InQuickBar, int32 Slot) const
{
	return nullptr;
}

FText UFortInventoryContext::GetRecyclingWarningText(EItemRecyclingWarning Warning, const bool WereAnyItemsAnimate)
{
	return FText();
}

int32 UFortInventoryContext::GetResourceCount(EFortResourceType::Type ResourceType) const
{
	return int32();
}

UFortResourceItemDefinition* UFortInventoryContext::GetResourceItemDefinition(EFortResourceType::Type ResourceType) const
{
	return nullptr;
}

int32 UFortInventoryContext::GetStorageCapacity() const
{
	return int32();
}

int32 UFortInventoryContext::GetStorageNumItems() const
{
	return int32();
}

int32 UFortInventoryContext::GetStorageOverflowFromAddingItem(UFortWorldItem* Item, int32 Count) const
{
	return int32();
}

FText UFortInventoryContext::GetTierText(EFortItemTier Tier)
{
	return FText();
}

int32 UFortInventoryContext::GetTotalItemQuantityByDefinition(UFortItemDefinition* ItemDefinition) const
{
	return int32();
}

void UFortInventoryContext::GetTransformKeys(EConversionControlKeyRequest RequestType, const EInventoryContentSortType SortType, TArray<UFortAccountItem*>& TransformKeys)
{
}

bool UFortInventoryContext::GetTransmogSacrificeDataFromItemDefintion(const UFortItemDefinition* ItemDefinition, FTransmogSacrifice& OutTransmogData) const
{
	return false;
}

FText UFortInventoryContext::GetTrapAttachTypeName(ABuildingSMActor* Actor) const
{
	return FText();
}

void UFortInventoryContext::GetUnseenTransformKeys(EConversionControlKeyRequest RequestType, const EInventoryContentSortType SortType, TArray<UFortAccountItem*>& TransformKeys)
{
}

FRecipe UFortInventoryContext::GetUpgradeItemRarityRecipeFromItemDefintion(UFortItemDefinition* ItemDefinition)
{
	return FRecipe();
}

TArray<FText> UFortInventoryContext::GetUserFriendlyTags(const UFortItem* Item, bool bAddWeaponTier)
{
	return TArray<FText>();
}

int32 UFortInventoryContext::GetVaultItemLimit() const
{
	return int32();
}

EVaultItemLimitStatus UFortInventoryContext::GetVaultItemLimitStatus() const
{
	return EVaultItemLimitStatus();
}

void UFortInventoryContext::HandleMcpProfilesInitialized()
{
}

bool UFortInventoryContext::HasGameplayTagContainer(FGameplayTagContainer GameplayTagContainer) const
{
	return false;
}

bool UFortInventoryContext::HasGameplayTagContainerExact(FGameplayTagContainer GameplayTagContainer) const
{
	return false;
}

bool UFortInventoryContext::HasTrapReadyForBuilding(const ABuildingSMActor* BuildingToAttachTo) const
{
	return false;
}

bool UFortInventoryContext::HasUnavailableItemsInStorage() const
{
	return false;
}

bool UFortInventoryContext::HasUnseenHomebasePoints() const
{
	return false;
}

bool UFortInventoryContext::HasUnseenResearchPointCollectionNodes() const
{
	return false;
}

bool UFortInventoryContext::IsTrapAvailableForBuilding(ABuildingSMActor* Actor) const
{
	return false;
}

FFortItemInstanceQuantityPair UFortInventoryContext::MakeItemInstanceQuantityPair(const UFortItem* Item, const EFortInventoryType::Type InventoryType, int32 ItemQuantity)
{
	return FFortItemInstanceQuantityPair();
}

FFortItemQuantityPair UFortInventoryContext::MakeItemQuantityPair(const UFortItemDefinition* ItemDefinition, int32 ItemQuantity)
{
	return FFortItemQuantityPair();
}

bool UFortInventoryContext::RemoveItemFromQuickBar(UFortItem* Item)
{
	return false;
}

void UFortInventoryContext::UpdateLastSeenHomebasePoints()
{
}

void UFortInventoryContext::UpdateLastSeenResearchPointCollectionNodes()
{
}

bool UFortInventoryContext::WillAllItemsSlotInCollectionBook(const TArray<UFortItem*>& Items)
{
	return false;
}

bool UFortInventoryContext::WouldExceedMaxStackSize(UFortItemDefinition* ItemDefinition, int32 QuantityToTest) const
{
	return false;
}
