// Copyright Epic Games, Inc. All Rights Reserved.

#include "Items/FortItem.h"

bool UFortItem::AllowedToBeLockedInInventory() const
{
	return false;
}

void UFortItem::BroadcastOnItemChanged(bool bItemChanged, bool bAmmoChanged, bool bIngredientsChanged, bool bLogBroadcasts) const
{
}

bool UFortItem::CanAffordPromotion() const
{
	return false;
}

bool UFortItem::CanBeDropped() const
{
	return false;
}

bool UFortItem::CanBeUnslotted() const
{
	return false;
}

bool UFortItem::CanBeUpgraded(TArray<EItemUpgradeRestrictionReason>& OutRestrictionReasons) const
{
	return false;
}

bool UFortItem::CanEvolve(TArray<EItemEvolutionRestrictionReason>& OutRestrictionReasons) const
{
	return false;
}

bool UFortItem::CanUpgradeItemRarity(TArray<EItemEvolutionRestrictionReason>& OutRestrictionReasons) const
{
	return false;
}

bool UFortItem::DoesMatchSearchString(const FString& SearchString) const
{
	return false;
}

TArray<UFortAlterationItemDefinition*> UFortItem::GetActiveAlterations(int32 PretendLevel) const
{
	return TArray<UFortAlterationItemDefinition*>();
}

TArray<FFortAlterationSlotStatus> UFortItem::GetAlterationSlots() const
{
	return TArray<FFortAlterationSlotStatus>();
}

float UFortItem::GetCoolDownTimeRemaining(const AFortPlayerController* FortPC, float& CooldownDuration) const
{
	return float();
}

FText UFortItem::GetCraftedDisplayName() const
{
	return FText();
}

FText UFortItem::GetDescription() const
{
	return FText();
}

FText UFortItem::GetDisplayName() const
{
	return FText();
}

FText UFortItem::GetDisplayNameWithoutPrefix() const
{
	return FText();
}

float UFortItem::GetDurability() const
{
	return float();
}

FText UFortItem::GetEvolveRestrictionReasonText(const EItemEvolutionRestrictionReason Reason)
{
	return FText();
}

EFortInventoryFilter UFortItem::GetFilterCategory() const
{
	return EFortInventoryFilter();
}

TSoftObjectPtr<UTexture2D> UFortItem::GetInactivePreviewImage() const
{
	return TSoftObjectPtr<UTexture2D>();
}

UFortItemDefinition* UFortItem::GetItemDefinitionBP() const
{
	return nullptr;
}

FGuid UFortItem::GetItemGuid() const
{
	return FGuid();
}

FText UFortItem::GetItemTypeName(bool bUsePlural) const
{
	return FText();
}

FGuid UFortItem::GetItemVariantGuid() const
{
	return FGuid();
}

FItemVariantHandle UFortItem::GetItemVariantHandle() const
{
	return FItemVariantHandle();
}

TSoftObjectPtr<UTexture2D> UFortItem::GetLargePreviewImage() const
{
	return TSoftObjectPtr<UTexture2D>();
}

int32 UFortItem::GetLevel() const
{
	return int32();
}

int32 UFortItem::GetLevelRelativeCostForRarityUpgrade() const
{
	return int32();
}

int32 UFortItem::GetLoadedAmmo() const
{
	return int32();
}

int32 UFortItem::GetMaxLevel() const
{
	return int32();
}

int32 UFortItem::GetMaxStackSize(UAbilitySystemComponent* AbilityComp) const
{
	return int32();
}

EFortItemTier UFortItem::GetMaxTier() const
{
	return EFortItemTier();
}

float UFortItem::GetNormalizedDurability() const
{
	return float();
}

uint8 UFortItem::GetNumberOfSlotsTaken() const
{
	return uint8();
}

int32 UFortItem::GetNumInStack() const
{
	return int32();
}

int32 UFortItem::GetNumInStackWithInfinityCheck() const
{
	return int32();
}

AFortPlayerController* UFortItem::GetOwningController() const
{
	return nullptr;
}

int32 UFortItem::GetPhantomReserveAmmo() const
{
	return int32();
}

TArray<TSoftObjectPtr<UObject>> UFortItem::GetPreviewAssets() const
{
	return TArray<TSoftObjectPtr<UObject>>();
}

bool UFortItem::GetPrimaryCategory(FText& ItemCategoryText) const
{
	return false;
}

int32 UFortItem::GetPromotionTier() const
{
	return int32();
}

EFortRarity UFortItem::GetRarity() const
{
	return EFortRarity();
}

FLinearColor UFortItem::GetRarityColor() const
{
	return FLinearColor();
}

FLinearColor UFortItem::GetRaritySecondaryColor() const
{
	return FLinearColor();
}

int32 UFortItem::GetRating() const
{
	return int32();
}

int32 UFortItem::GetRecycleValue() const
{
	return int32();
}

int32 UFortItem::GetRemainingAmmo() const
{
	return int32();
}

UFortItemDefinition* UFortItem::GetSchematicCraftingResultBP() const
{
	return nullptr;
}

UFortWeaponItemDefinition* UFortItem::GetSchematicCraftingResultOrCraftedWeaponBP() const
{
	return nullptr;
}

EFortItemType UFortItem::GetSchematicResultType() const
{
	return EFortItemType();
}

FText UFortItem::GetSearchTags() const
{
	return FText();
}

bool UFortItem::GetSecondaryCategory(FText& ItemCategoryText, FSlateBrush& ItemCategoryBrush, EFortBrushSize::Type BrushSize) const
{
	return false;
}

TSoftObjectPtr<UTexture2D> UFortItem::GetSmallPreviewImage() const
{
	return TSoftObjectPtr<UTexture2D>();
}

bool UFortItem::GetTertiaryCategory(FText& ItemCategoryText, FSlateBrush& ItemCategoryBrush, EFortBrushSize::Type BrushSize) const
{
	return false;
}

EFortItemTier UFortItem::GetTier() const
{
	return EFortItemTier();
}

int32 UFortItem::GetTotalAmmo() const
{
	return int32();
}

FGuid UFortItem::GetTrackerGuid() const
{
	return FGuid();
}

EFortItemType UFortItem::GetType() const
{
	return EFortItemType();
}

int32 UFortItem::GetUpgradeCost() const
{
	return int32();
}

int32 UFortItem::GetUpgradeCostToLevel(int32 TargetLevel) const
{
	return int32();
}

UFortPersistentResourceItemDefinition* UFortItem::GetUpgradeResourceItemDefinition() const
{
	return nullptr;
}

FText UFortItem::GetUpgradeRestrictionReasonText(const EItemUpgradeRestrictionReason Reason)
{
	return FText();
}

TSoftObjectPtr<UTexture2D> UFortItem::GetWidePreviewImage() const
{
	return TSoftObjectPtr<UTexture2D>();
}

bool UFortItem::HasDurability() const
{
	return false;
}

bool UFortItem::HasEvolutions() const
{
	return false;
}

bool UFortItem::HasOverriddenWeaponAmmo() const
{
	return false;
}

bool UFortItem::HasRarityUpgrade() const
{
	return false;
}

bool UFortItem::IsActivatable(const AFortPlayerController* FortPC, FGameplayTagContainer& FailureReason) const
{
	return false;
}

bool UFortItem::IsDroppedItem() const
{
	return false;
}

bool UFortItem::IsEquipable(const AFortPlayerController* EquippingPC, bool bGamepadSwitchingForHeroAbilities) const
{
	return false;
}

bool UFortItem::IsEquipped() const
{
	return false;
}

bool UFortItem::IsInStorageVault() const
{
	return false;
}

bool UFortItem::IsInventoryOverflowItem() const
{
	return false;
}

bool UFortItem::IsSchematic() const
{
	return false;
}

bool UFortItem::IsSchematicOrCraftedWeapon() const
{
	return false;
}

bool UFortItem::IsSlotted() const
{
	return false;
}

bool UFortItem::IsTemporaryItem() const
{
	return false;
}

bool UFortItem::IsVisible() const
{
	return false;
}

void UFortItem::SetOwningControllerForTemporaryItem(AFortPlayerController* InController)
{
}

bool UFortItem::TryGetCategory(EFortItemCategoryOrdinal Ordinal, FText& OutCategoryDisplayName, bool& OutHasIcon, FFortMultiSizeBrush& OutCategoryIconBrush) const
{
	return false;
}

bool UFortItem::UsesPhantomReserveAmmo() const
{
	return false;
}
