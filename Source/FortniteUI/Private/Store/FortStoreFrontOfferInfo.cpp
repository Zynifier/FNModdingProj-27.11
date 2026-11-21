// Copyright Epic Games, Inc. All Rights Reserved.

#include "Store/FortStoreFrontOfferInfo.h"

bool UFortStoreFrontOfferInfo::AreGrantedItemsOwned() const
{
	return false;
}

bool UFortStoreFrontOfferInfo::CanShowRegularPrice(const int32 PriceIndex) const
{
	return false;
}

UFortAccountItem* UFortStoreFrontOfferInfo::CreatePreviewItem() const
{
	return nullptr;
}

EAppStore UFortStoreFrontOfferInfo::GetAppStoreByPrice(const int32 PriceIndex, const int32 ItemQuantity) const
{
	return EAppStore();
}

FString UFortStoreFrontOfferInfo::GetBannerOverrideTag() const
{
	return FString();
}

int32 UFortStoreFrontOfferInfo::GetBaseQuantity() const
{
	return int32();
}

int32 UFortStoreFrontOfferInfo::GetBonusQuantity() const
{
	return int32();
}

FText UFortStoreFrontOfferInfo::GetCategoryText() const
{
	return FText();
}

UFortAccountItemDefinition* UFortStoreFrontOfferInfo::GetCurrencyItemDefinition() const
{
	return nullptr;
}

FText UFortStoreFrontOfferInfo::GetDescription() const
{
	return FText();
}

FString UFortStoreFrontOfferInfo::GetDisplayAssetPath() const
{
	return FString();
}

void UFortStoreFrontOfferInfo::GetDynamicBundleItems(TArray<FBundledItemInfo>& Items) const
{
}

FText UFortStoreFrontOfferInfo::GetFinalPrice(const int32 PriceIndex, const int32 ItemQuantity) const
{
	return FText();
}

UFortAccountItemDefinition* UFortStoreFrontOfferInfo::GetFirstGrantItemDefinition() const
{
	return nullptr;
}

int32 UFortStoreFrontOfferInfo::GetFirstGrantQuantity() const
{
	return int32();
}

FString UFortStoreFrontOfferInfo::GetForcedGiftBoxTemplateId() const
{
	return FString();
}

FString UFortStoreFrontOfferInfo::GetFortStoreOfferCategory() const
{
	return FString();
}

int32 UFortStoreFrontOfferInfo::GetFortStoreOfferFinalPrice() const
{
	return int32();
}

EFortMtxStoreOfferType UFortStoreFrontOfferInfo::GetFortStoreOfferType() const
{
	return EFortMtxStoreOfferType();
}

UFortAccountItemDefinition* UFortStoreFrontOfferInfo::GetGrantedItemDefinition(int32 GrantedItemIndex) const
{
	return nullptr;
}

void UFortStoreFrontOfferInfo::GetGrantedItemDefinitions(TArray<UFortAccountItemDefinition*>& GrantedItems) const
{
}

int32 UFortStoreFrontOfferInfo::GetGrantedItemQuantity(int32 GrantedItemIndex) const
{
	return int32();
}

bool UFortStoreFrontOfferInfo::GetGrantedItemQuantityPair(int32 GrantedItemIndex, FFortItemQuantityPair& ItemQuantity) const
{
	return false;
}

void UFortStoreFrontOfferInfo::GetGrantedItemQuantityPairs(bool bPrioritizeUnowned, bool bCombineCurrencyItems, TArray<FFortItemQuantityPair>& ItemQuantityPairs) const
{
}

void UFortStoreFrontOfferInfo::GetGrantedItems(TArray<UFortItem*>& Items, const bool bSortItems) const
{
}

int32 UFortStoreFrontOfferInfo::GetItemOfferCount(const FString& TemplateId) const
{
	return int32();
}

int32 UFortStoreFrontOfferInfo::GetItemQuantity(const FString& TemplateId) const
{
	return int32();
}

FText UFortStoreFrontOfferInfo::GetItemTypeText() const
{
	return FText();
}

int32 UFortStoreFrontOfferInfo::GetMaxConcurrentPurchases() const
{
	return int32();
}

bool UFortStoreFrontOfferInfo::GetMetaAsBool(const FString& MetaTag) const
{
	return false;
}

FString UFortStoreFrontOfferInfo::GetMetaValue(const FString& MetaTag) const
{
	return FString();
}

FText UFortStoreFrontOfferInfo::GetName() const
{
	return FText();
}

int32 UFortStoreFrontOfferInfo::GetNumericPrice(const int32 PriceIndex) const
{
	return int32();
}

int32 UFortStoreFrontOfferInfo::GetNumGrantedItems() const
{
	return int32();
}

int32 UFortStoreFrontOfferInfo::GetNumRequirements() const
{
	return int32();
}

const FCatalogOffer& UFortStoreFrontOfferInfo::GetOffer() const
{
	static FCatalogOffer Dummy;
	return Dummy;
}

UFortMtxOfferData* UFortStoreFrontOfferInfo::GetOfferDisplayAsset() const
{
	return nullptr;
}

EFortMtxOfferDisplaySize UFortStoreFrontOfferInfo::GetOfferDisplaySize() const
{
	return EFortMtxOfferDisplaySize();
}

FString UFortStoreFrontOfferInfo::GetOfferId() const
{
	return FString();
}

ECatalogOfferType UFortStoreFrontOfferInfo::GetOfferType() const
{
	return ECatalogOfferType();
}

bool UFortStoreFrontOfferInfo::GetPrerollOfferItem(FFortItemQuantityPair& ItemQuantityPair) const
{
	return false;
}

int32 UFortStoreFrontOfferInfo::GetPrerollRarity() const
{
	return int32();
}

EStoreCurrencyType::Type UFortStoreFrontOfferInfo::GetPriceCurrencyType(const int32 PriceIndex) const
{
	return EStoreCurrencyType::Type();
}

UFortAccountItemDefinition* UFortStoreFrontOfferInfo::GetPriceItem(const int32 PriceIndex, int32& RequiredItemCount) const
{
	return nullptr;
}

int32 UFortStoreFrontOfferInfo::GetQuantityRemaining() const
{
	return int32();
}

FText UFortStoreFrontOfferInfo::GetRegularPrice(const int32 PriceIndex, const int32 ItemQuantity) const
{
	return FText();
}

FString UFortStoreFrontOfferInfo::GetRequirementIdAtIndex(int32 RequirementIndex) const
{
	return FString();
}

int32 UFortStoreFrontOfferInfo::GetRequirementMinQuantityAtIndex(int32 RequirementIndex) const
{
	return int32();
}

ECatalogRequirementType UFortStoreFrontOfferInfo::GetRequirementTypeAtIndex(int32 RequirementIndex) const
{
	return ECatalogRequirementType();
}

bool UFortStoreFrontOfferInfo::GetSalePrice(const int32 PriceIndex, FText& SalePrice, const int32 ItemQuantity) const
{
	return false;
}

FText UFortStoreFrontOfferInfo::GetSaleText(const int32 PriceIndex, const int32 ItemQuantity) const
{
	return FText();
}

ECatalogSaleType::Type UFortStoreFrontOfferInfo::GetSaleType(const int32 PriceIndex) const
{
	return ECatalogSaleType::Type();
}

FText UFortStoreFrontOfferInfo::GetShortDescription() const
{
	return FText();
}

FText UFortStoreFrontOfferInfo::GetShortName() const
{
	return FText();
}

int32 UFortStoreFrontOfferInfo::GetSortPriority() const
{
	return int32();
}

FName UFortStoreFrontOfferInfo::GetStorefrontName() const
{
	return FName();
}

int32 UFortStoreFrontOfferInfo::GetTotalQuantity() const
{
	return int32();
}

bool UFortStoreFrontOfferInfo::HasCatalogOfferName(FText& CatalogOfferName) const
{
	return false;
}

bool UFortStoreFrontOfferInfo::HasDisplayAsset() const
{
	return false;
}

bool UFortStoreFrontOfferInfo::HasMaxLevel(int32& MaxLevel) const
{
	return false;
}

bool UFortStoreFrontOfferInfo::HasRequirement(FText& RequirementText) const
{
	return false;
}

bool UFortStoreFrontOfferInfo::IsBattlePassLevelBundle() const
{
	return false;
}

bool UFortStoreFrontOfferInfo::IsCardpack() const
{
	return false;
}

bool UFortStoreFrontOfferInfo::IsCrewBlingOffer() const
{
	return false;
}

bool UFortStoreFrontOfferInfo::IsCurrencyVoucher() const
{
	return false;
}

bool UFortStoreFrontOfferInfo::IsEmoteBuiltInToOwnedGrantedItem(const UFortMontageItemDefinitionBase* BuiltInEmote) const
{
	return false;
}

bool UFortStoreFrontOfferInfo::IsExclusive() const
{
	return false;
}

bool UFortStoreFrontOfferInfo::IsFriendTimeRequirementIgnored() const
{
	return false;
}

bool UFortStoreFrontOfferInfo::IsGiftable() const
{
	return false;
}

bool UFortStoreFrontOfferInfo::IsGiftingStorefrontOffer() const
{
	return false;
}

bool UFortStoreFrontOfferInfo::IsGiftLimitIgnored() const
{
	return false;
}

bool UFortStoreFrontOfferInfo::IsGiftOnly() const
{
	return false;
}

bool UFortStoreFrontOfferInfo::IsGridLayout() const
{
	return false;
}

bool UFortStoreFrontOfferInfo::IsItemDefOwned(const UFortItemDefinition* ItemDef) const
{
	return false;
}

bool UFortStoreFrontOfferInfo::isItemGrantUnique(const FString& TemplateId) const
{
	return false;
}

bool UFortStoreFrontOfferInfo::IsItemMissingFromCollectionBook(const UFortItem* ItemToCheck) const
{
	return false;
}

bool UFortStoreFrontOfferInfo::IsItemMissingFromInventory(const UFortItem* ItemToCheck) const
{
	return false;
}

bool UFortStoreFrontOfferInfo::IsLockedByRequirement() const
{
	return false;
}

bool UFortStoreFrontOfferInfo::IsNoPreviewOffer() const
{
	return false;
}

bool UFortStoreFrontOfferInfo::IsOfferOwned() const
{
	return false;
}

bool UFortStoreFrontOfferInfo::IsPrerollOffer() const
{
	return false;
}

bool UFortStoreFrontOfferInfo::IsPriceInGameItems(const int32 PriceIndex) const
{
	return false;
}

bool UFortStoreFrontOfferInfo::IsPriceInMTX(const int32 PriceIndex) const
{
	return false;
}

bool UFortStoreFrontOfferInfo::IsPriceInRealMoney(const int32 PriceIndex) const
{
	return false;
}

bool UFortStoreFrontOfferInfo::IsPurchasingAvailable() const
{
	return false;
}

bool UFortStoreFrontOfferInfo::IsRefundable() const
{
	return false;
}

bool UFortStoreFrontOfferInfo::IsSubscriptionOffer() const
{
	return false;
}

bool UFortStoreFrontOfferInfo::IsUnique() const
{
	return false;
}

bool UFortStoreFrontOfferInfo::IsValidOffer() const
{
	return false;
}

bool UFortStoreFrontOfferInfo::IsVotingOffer() const
{
	return false;
}

void UFortStoreFrontOfferInfo::MarkPrerollAsSeen() const
{
}

bool UFortStoreFrontOfferInfo::OfferHasDenyRequirements() const
{
	return false;
}

bool UFortStoreFrontOfferInfo::WasPrerollItemSeen() const
{
	return false;
}
