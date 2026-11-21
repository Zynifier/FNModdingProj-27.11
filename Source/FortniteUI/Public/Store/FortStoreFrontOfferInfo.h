// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CatalogTypes.h"
#include "FortItemQuantityPair.h"
#include "McpCatalogEnums.h"
#include "FortStoreFrontOfferInfo.generated.h"

class UFortAccountItem;
class UFortAccountItemDefinition;
class UFortItem;
class UFortItemDefinition;
class UFortMontageItemDefinitionBase;
class UFortMtxOfferData;
enum class EAppStore : uint8;
enum class ECatalogOfferType : uint8;
enum class ECatalogRequirementType : uint8;
enum class EFortMtxOfferDisplaySize : uint8;
enum class EFortMtxStoreOfferType : uint8;

USTRUCT(BlueprintType)
struct FBundledItemInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="Dynamic Bundles")
	FString TemplateId;

	UPROPERTY(BlueprintReadOnly, Category="Dynamic Bundles")
	int32 Quantity;

	UPROPERTY(BlueprintReadOnly, Category="Dynamic Bundles")
	bool bOwned;

};

UCLASS(BlueprintType, meta=(Category="Fortnite UI"))
class FORTNITEUI_API UFortStoreFrontOfferInfo : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	bool AreGrantedItemsOwned() const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	bool CanShowRegularPrice(const int32 PriceIndex) const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	UFortAccountItem* CreatePreviewItem() const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	EAppStore GetAppStoreByPrice(const int32 PriceIndex, const int32 ItemQuantity = 1) const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	FString GetBannerOverrideTag() const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	int32 GetBaseQuantity() const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	int32 GetBonusQuantity() const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	FText GetCategoryText() const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	UFortAccountItemDefinition* GetCurrencyItemDefinition() const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	FText GetDescription() const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	FString GetDisplayAssetPath() const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	void GetDynamicBundleItems(TArray<FBundledItemInfo>& Items) const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	FText GetFinalPrice(const int32 PriceIndex, const int32 ItemQuantity = 1) const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	UFortAccountItemDefinition* GetFirstGrantItemDefinition() const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	int32 GetFirstGrantQuantity() const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	FString GetForcedGiftBoxTemplateId() const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	FString GetFortStoreOfferCategory() const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	int32 GetFortStoreOfferFinalPrice() const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	EFortMtxStoreOfferType GetFortStoreOfferType() const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	UFortAccountItemDefinition* GetGrantedItemDefinition(int32 GrantedItemIndex) const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	void GetGrantedItemDefinitions(TArray<UFortAccountItemDefinition*>& GrantedItems) const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	int32 GetGrantedItemQuantity(int32 GrantedItemIndex) const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	bool GetGrantedItemQuantityPair(int32 GrantedItemIndex, FFortItemQuantityPair& ItemQuantity) const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	void GetGrantedItemQuantityPairs(bool bPrioritizeUnowned, bool bCombineCurrencyItems, TArray<FFortItemQuantityPair>& ItemQuantityPairs) const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	void GetGrantedItems(TArray<UFortItem*>& Items, const bool bSortItems = true) const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	int32 GetItemOfferCount(const FString& TemplateId) const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	int32 GetItemQuantity(const FString& TemplateId) const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	FText GetItemTypeText() const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	int32 GetMaxConcurrentPurchases() const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	bool GetMetaAsBool(const FString& MetaTag) const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	FString GetMetaValue(const FString& MetaTag) const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	virtual FText GetName() const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	int32 GetNumericPrice(const int32 PriceIndex) const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	int32 GetNumGrantedItems() const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	int32 GetNumRequirements() const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	const FCatalogOffer& GetOffer() const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	UFortMtxOfferData* GetOfferDisplayAsset() const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	EFortMtxOfferDisplaySize GetOfferDisplaySize() const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	FString GetOfferId() const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	ECatalogOfferType GetOfferType() const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	bool GetPrerollOfferItem(FFortItemQuantityPair& ItemQuantityPair) const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	int32 GetPrerollRarity() const;

	UFUNCTION(BlueprintPure)
	EStoreCurrencyType::Type GetPriceCurrencyType(const int32 PriceIndex) const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	UFortAccountItemDefinition* GetPriceItem(const int32 PriceIndex, int32& RequiredItemCount) const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	int32 GetQuantityRemaining() const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	FText GetRegularPrice(const int32 PriceIndex, const int32 ItemQuantity = 1) const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	FString GetRequirementIdAtIndex(int32 RequirementIndex) const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	int32 GetRequirementMinQuantityAtIndex(int32 RequirementIndex) const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	ECatalogRequirementType GetRequirementTypeAtIndex(int32 RequirementIndex) const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	bool GetSalePrice(const int32 PriceIndex, FText& SalePrice, const int32 ItemQuantity = 1) const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	FText GetSaleText(const int32 PriceIndex, const int32 ItemQuantity = 1) const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	ECatalogSaleType::Type GetSaleType(const int32 PriceIndex) const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	virtual FText GetShortDescription() const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	virtual FText GetShortName() const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	int32 GetSortPriority() const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	FName GetStorefrontName() const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	int32 GetTotalQuantity() const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	virtual bool HasCatalogOfferName(FText& CatalogOfferName) const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	virtual bool HasDisplayAsset() const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	bool HasMaxLevel(int32& MaxLevel) const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	bool HasRequirement(FText& RequirementText) const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	bool IsBattlePassLevelBundle() const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	virtual bool IsCardpack() const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	bool IsCrewBlingOffer() const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	bool IsCurrencyVoucher() const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	bool IsEmoteBuiltInToOwnedGrantedItem(const UFortMontageItemDefinitionBase* BuiltInEmote) const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	bool IsExclusive() const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	bool IsFriendTimeRequirementIgnored() const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	bool IsGiftable() const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	bool IsGiftingStorefrontOffer() const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	bool IsGiftLimitIgnored() const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	bool IsGiftOnly() const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	bool IsGridLayout() const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	bool IsItemDefOwned(const UFortItemDefinition* ItemDef) const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	bool isItemGrantUnique(const FString& TemplateId) const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	bool IsItemMissingFromCollectionBook(const UFortItem* ItemToCheck) const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	bool IsItemMissingFromInventory(const UFortItem* ItemToCheck) const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	bool IsLockedByRequirement() const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	bool IsNoPreviewOffer() const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	bool IsOfferOwned() const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	bool IsPrerollOffer() const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	bool IsPriceInGameItems(const int32 PriceIndex) const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	bool IsPriceInMTX(const int32 PriceIndex) const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	bool IsPriceInRealMoney(const int32 PriceIndex) const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	bool IsPurchasingAvailable() const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	bool IsRefundable() const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	bool IsSubscriptionOffer() const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	bool IsUnique() const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	bool IsValidOffer() const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	bool IsVotingOffer() const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="FortStoreFrontOfferInfo")
	void MarkPrerollAsSeen() const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	bool OfferHasDenyRequirements() const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	bool WasPrerollItemSeen() const;

private:
	UPROPERTY()
	TObjectPtr<UFortMtxOfferData> OfferDisplayAsset;

};

