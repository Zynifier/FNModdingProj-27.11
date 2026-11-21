// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "JsonObjectWrapper.h"
#include "Misc/DateTime.h"
#include "McpCatalogEnums.h"
#include "McpCatalogItemPrice.h"
#include "McpSharedTypes.h"
#include "CatalogTypes.generated.h"

UENUM()
enum class EAutoRenewState : uint8
{
	None = 0 UMETA(Hidden),
	AutoRenewEnabled = 1,
	AutoRenewDisabled = 2,
	NotAutoRenewable = 3,
	MAX = 4 UMETA(Hidden),
};

UENUM()
enum class ECatalogOfferType : uint8
{
	/** This offers price does not change based on owned items (but still may be affected by sales) */
	StaticPrice = 0,
	/** This offers price changes based on ownership of items contained in the bundle */
	DynamicBundle = 1,
};

UENUM()
enum class ECatalogRequirementType : uint8
{
	RequireFulfillment = 0,
	DenyOnFulfillment = 1,
	RequireItemOwnership = 2,
	DenyOnItemOwnership = 3,
};

UENUM()
enum class ECheckoutType : uint8
{
	/** No Validation*/
	None = 0 UMETA(Hidden),
	/** Checkout operation requests and / or returns the receipt information */
	ReceiptRequested = 1,
	/** 
	* Checkout operation is performed with no additional receipt request, doesn't return receipts. 
	*/
	Receiptless = 2,
	MAX = 3 UMETA(Hidden),
};

UENUM()
enum class ERedeemRealMoneyPurchaseRefreshType : uint8
{
	/** Query current platforms and active subscription platforms when auto-refresh conditions are met*/
	Default = 0 UMETA(Hidden),
	/** Force a query current platform, but active subscription platform only if auto-refresh conditions are met */
	ForceCurrent = 1,
	/** Force a query of current platform and all platforms with offline access regardless of cool down */
	ForceAll = 2,
	/** Tells the MCP to only update the offline token. */
	UpdateOfflineAuth = 3,
	MAX = 4 UMETA(Hidden),
};

UENUM()
enum class EVerifierModeOverride : uint8
{
	DefaultToConfig = 1,
	ReceiptOnly = 2,
	OccurrenceOnly = 3,
	ReceiptPrimary = 4,
	OccurrencePrimary = 5,
	OccurrenceOnlyRemoveReceipts = 6,
	MAX = 7 UMETA(Hidden),
};

USTRUCT()
struct FAppStoreCheckoutConfig
{
	GENERATED_BODY()

public:
	UPROPERTY()
	EAppStore AppStore;

	UPROPERTY()
	ECheckoutType CheckoutType;

};

USTRUCT(BlueprintType)
struct GAMESUBCATALOG_API FItemQuantity
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Item")
	FString TemplateId;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Item")
	int32 Quantity;

	UPROPERTY(EditAnywhere, Category="Attributes", meta=(TitleProperty="JsonString"))
	FJsonObjectWrapper Attributes;

};

USTRUCT()
struct GAMESUBCATALOG_API FCatalogDynamicBundleItem
{
	GENERATED_BODY()

public:
#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleDefaultsOnly, Category="Dynamic Bundles", meta=(IgnoreForMemberInitializationTest))
	FString BundleItemId;
#endif

	UPROPERTY(EditDefaultsOnly, Category="Dynamic Bundles")
	FItemQuantity Item;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic Bundles")
	bool bCanOwnMultiple;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic Bundles", meta=(ClampMin="0", UIMin="0"))
	int32 RegularPrice;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic Bundles", meta=(ClampMin="0", UIMin="0"))
	int32 DiscountedPrice;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic Bundles", meta=(ClampMin="0", UIMin="0"))
	int32 AlreadyOwnedPriceReduction;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic Bundles")
	FText Title;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic Bundles")
	FText Description;

};

USTRUCT()
struct GAMESUBCATALOG_API FCatalogDynamicBundle
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Dynamic Bundles")
	int32 DiscountedBasePrice;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic Bundles", meta=(ClampMin="0", UIMin="0"))
	int32 RegularBasePrice;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic Bundles", meta=(ClampMin="0", UIMin="0"))
	int32 FloorPrice;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic Bundles")
	TEnumAsByte<EStoreCurrencyType::Type> CurrencyType;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic Bundles")
	FString CurrencySubType;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic Bundles")
	TEnumAsByte<ECatalogSaleType::Type> DisplayType;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic Bundles", meta=(TitleProperty="BundleItemId"))
	TArray<FCatalogDynamicBundleItem> BundleItems;

};

USTRUCT()
struct GAMESUBCATALOG_API FCatalogOfferRequirement
{
	GENERATED_BODY()

public:
	UPROPERTY()
	ECatalogRequirementType RequirementType;

	UPROPERTY()
	int32 MinQuantity;

	UPROPERTY()
	FString RequiredId;

};

USTRUCT()
struct GAMESUBCATALOG_API FCatalogGiftInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	bool bIsEnabled;

	UPROPERTY()
	FString ForcedGiftBoxTemplateId;

	UPROPERTY()
	TArray<FCatalogOfferRequirement> PurchaseRequirements;

};

USTRUCT(BlueprintType)
struct GAMESUBCATALOG_API FCatalogKeyValue
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Catalog")
	FString Key;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Catalog")
	FString Value;

};

USTRUCT()
struct GAMESUBCATALOG_API FCatalogMetaAssetInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString StructName;

	UPROPERTY()
	FJsonObjectWrapper Payload;

};

USTRUCT(BlueprintType)
struct GAMESUBCATALOG_API FCatalogOffer
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category="Meta Info")
	FString OfferId;

	UPROPERTY(EditAnywhere, Category="Meta Info")
	FString DevName;

	UPROPERTY(EditAnywhere, Category="Meta Info", meta=(TitleProperty="Key"))
	TArray<FCatalogKeyValue> MetaInfo;

	UPROPERTY(EditAnywhere, Category="Catalog")
	ECatalogOfferType OfferType;

	UPROPERTY(EditAnywhere, Category="Catalog", meta=(TitleProperty="CurrencyType"))
	TArray<FCatalogItemPrice> Prices;

	UPROPERTY(EditAnywhere, Category="Catalog")
	FCatalogDynamicBundle DynamicBundleInfo;

	UPROPERTY(EditAnywhere, Category="Catalog")
	int32 DailyLimit;

	UPROPERTY(EditAnywhere, Category="Catalog")
	int32 WeeklyLimit;

	UPROPERTY(EditAnywhere, Category="Catalog")
	int32 MonthlyLimit;

	UPROPERTY(EditAnywhere, Category="Display")
	TArray<FString> Categories;

	UPROPERTY(EditAnywhere, Category="Display")
	FString CatalogGroup;

	UPROPERTY(EditAnywhere, Category="Display")
	int32 CatalogGroupPriority;

	UPROPERTY(EditAnywhere, Category="Display")
	int32 SortPriority;

	UPROPERTY(EditAnywhere, Category="Display")
	FText Title;

	UPROPERTY(EditAnywhere, Category="Display")
	FText ShortDescription;

	UPROPERTY(EditAnywhere, Category="Display", meta=(MultiLine="true"))
	FText Description;

	UPROPERTY(EditAnywhere, Category="Display", meta=(ArraySizeEnum="/Script/GameSubCatalog.EAppStore"))
	FString AppStoreId[12];

	UPROPERTY()
	FCatalogMetaAssetInfo MetaAssetInfo;

	UPROPERTY()
	FString DisplayAssetPath;

	UPROPERTY()
	TArray<FItemQuantity> ItemGrants;

	UPROPERTY()
	TArray<FCatalogOfferRequirement> Requirements;

	UPROPERTY()
	FCatalogGiftInfo GiftInfo;

	UPROPERTY(EditAnywhere, Category="Display")
	bool Refundable;

private:
	UPROPERTY()
	TArray<FString> DenyItemTemplateIds_DEPRECATED;

};

USTRUCT()
struct GAMESUBCATALOG_API FStorefront
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString Name;

	UPROPERTY()
	TArray<FCatalogOffer> CatalogEntries;

};

USTRUCT()
struct GAMESUBCATALOG_API FCatalogDownload
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 RefreshIntervalHrs;

	UPROPERTY()
	int32 DailyPurchaseHrs;

	UPROPERTY()
	FDateTime Expiration;

	UPROPERTY()
	TArray<FStorefront> Storefronts;

};

USTRUCT()
struct GAMESUBCATALOG_API FStoreOfferInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString StoreFront;

	UPROPERTY()
	FString StoreId;

	UPROPERTY()
	FString GroupId;

};

USTRUCT()
struct GAMESUBCATALOG_API FCatalogPurchaseAdditionalData : public FStoreOfferInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString Playlist;

	UPROPERTY()
	FString IslandId;

	UPROPERTY()
	FString IslandTitle;

	UPROPERTY()
	FString StoreContext;

};

USTRUCT()
struct GAMESUBCATALOG_API FCatalogPurchaseInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString OfferId;

	UPROPERTY()
	int32 PurchaseQuantity;

	UPROPERTY()
	TEnumAsByte<EStoreCurrencyType::Type> Currency;

	UPROPERTY()
	FString CurrencySubType;

	UPROPERTY()
	int32 ExpectedTotalPrice;

	UPROPERTY()
	FString GameContext;

	UPROPERTY()
	FCatalogPurchaseAdditionalData AdditionalData;

};

USTRUCT()
struct GAMESUBCATALOG_API FCatalogPurchaseInfoGift
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString OfferId;

	UPROPERTY()
	TEnumAsByte<EStoreCurrencyType::Type> Currency;

	UPROPERTY()
	FString CurrencySubType;

	UPROPERTY()
	int32 ExpectedTotalPrice;

	UPROPERTY()
	FString GameContext;

	UPROPERTY()
	TArray<FString> ReceiverAccountIds;

	UPROPERTY()
	FString GiftWrapTemplateId;

	UPROPERTY()
	FString PersonalMessage;

	UPROPERTY()
	FCatalogPurchaseAdditionalData AdditionalData;

};

USTRUCT()
struct GAMESUBCATALOG_API FCatalogPurchaseNotification
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FMcpLootResult LootResult;

};

USTRUCT()
struct GAMESUBCATALOG_API FCatalogReceiptInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	EAppStore AppStore;

	UPROPERTY()
	FString AppStoreId;

	UPROPERTY()
	FString ReceiptId;

	UPROPERTY()
	FString ReceiptInfo;

	UPROPERTY()
	FString PurchaseCorrelationId;

};

USTRUCT()
struct GAMESUBCATALOG_API FCatalogRedeemRealMoneyPurchasesInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	EAppStore AppStore;

	UPROPERTY()
	TArray<FString> AuthTokens;

	UPROPERTY()
	TArray<FString> ReceiptIds;

	UPROPERTY()
	ERedeemRealMoneyPurchaseRefreshType RefreshType;

	UPROPERTY()
	EVerifierModeOverride VerifierModeOverride;

	UPROPERTY()
	int32 ReceiptRefactorVersionOverride;

	UPROPERTY()
	TArray<FString> CatalogItems;

	UPROPERTY()
	FString PurchaseCorrelationId;

	UPROPERTY()
	FCatalogPurchaseAdditionalData AdditionalData;

};

