// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CatalogTypes.h"
#include "ExcelImportUtil.h"
#include "TabularDataTransferUtil.h"
#include "CatalogDefinition.generated.h"

class UCatalogDefinition;
class UCatalogFulfillment;
class UCatalogMetaAsset;
class UMcpItemDefinitionBase;
class UObject;

UENUM()
enum class ECatalogOfferRequirementMode : int32
{
	Require = 0,
	Deny = 1,
};

USTRUCT()
struct GAMESUBCATALOGEDITOR_API FCatalogOfferRequirementEditor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Meta Info")
	ECatalogOfferRequirementMode Mode;

	UPROPERTY(EditAnywhere, Category="Meta Info")
	int32 MinQuantity;

	UPROPERTY(EditAnywhere, Category="Meta Info")
	TObjectPtr<UCatalogFulfillment> Fulfillment;

	UPROPERTY(EditAnywhere, Category="Meta Info")
	TObjectPtr<UMcpItemDefinitionBase> Item;

	UPROPERTY()
	FString ItemTemplateIdOnlyHack;

};

USTRUCT()
struct GAMESUBCATALOGEDITOR_API FCatalogGiftInfoEditor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="CatalogGiftInfoEditor")
	bool bGiftingEnabled;

	UPROPERTY(EditAnywhere, Category="CatalogGiftInfoEditor")
	FString ForcedGiftBoxTemplateId;

	UPROPERTY(EditAnywhere, Category="CatalogGiftInfoEditor")
	TArray<FCatalogOfferRequirementEditor> PurchaseRequirements;

	UPROPERTY(EditAnywhere, Category="CatalogGiftInfoEditor")
	TArray<FString> GiftRecordIds;

};

USTRUCT()
struct GAMESUBCATALOGEDITOR_API FCatalogOfferDefinition : public FCatalogOffer
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Meta Info")
	bool bEnabledForExport;

	UPROPERTY(EditAnywhere, Category="Meta Info")
	bool bRevealItemGrants;

	UPROPERTY(EditAnywhere, Category="Meta Info", meta=(TitleProperty="Key"))
	TArray<FCatalogKeyValue> ServerMetaInfo;

	UPROPERTY(EditAnywhere, Category="Display", meta=(AllowedClasses="/Script/Engine.Texture2D,/Script/Engine.MaterialInterface,/Script/Engine.DataAsset"))
	TSoftObjectPtr<UObject> DisplayAsset;

	UPROPERTY(EditAnywhere, Category="Display")
	TObjectPtr<UCatalogMetaAsset> MetaAsset;

	UPROPERTY(EditAnywhere, Category="Catalog")
	TArray<TObjectPtr<UCatalogFulfillment>> Fulfillments;

	UPROPERTY(EditAnywhere, Category="Fulfillment", meta=(TitleProperty="TemplateId"))
	TArray<FItemQuantity> InlineFulfillment;

	UPROPERTY(EditAnywhere, Category="Selection")
	FString MatchFilter;

	UPROPERTY(EditAnywhere, Category="Selection")
	float FilterWeight;

	UPROPERTY(EditAnywhere, Category="Catalog")
	TArray<FCatalogOfferRequirementEditor> OfferRequirements;

	UPROPERTY(EditAnywhere, Category="Catalog")
	FCatalogGiftInfoEditor GiftConfiguration;

	UPROPERTY(EditAnywhere, Category="Catalog")
	FString InlineFulfillmentClass;

private:
	UPROPERTY()
	TArray<TObjectPtr<UCatalogFulfillment>> RequiredFulfillments_DEPRECATED;

	UPROPERTY()
	TArray<TObjectPtr<UCatalogFulfillment>> DenyFulfillments_DEPRECATED;

	UPROPERTY()
	bool SinglePurchaseOnly_DEPRECATED;

	UPROPERTY()
	TObjectPtr<UCatalogFulfillment> Fulfillment_DEPRECATED;

};

USTRUCT()
struct GAMESUBCATALOGEDITOR_API FCatalogOfferSource
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="CatalogOfferSource")
	FString SourceName;

	UPROPERTY(EditAnywhere, Category="CatalogOfferSource")
	FExcelImportUtil ExcelImport;

	UPROPERTY(EditAnywhere, Category="CatalogOfferSource")
	FTabularDataTransferUtil TabDataTransfer;

	UPROPERTY(EditAnywhere, Category="Catalog", meta=(TitleProperty="DevName"))
	TArray<FCatalogOfferDefinition> Offers;

	UPROPERTY(Transient)
	TObjectPtr<UCatalogDefinition> Parent;

	UPROPERTY()
	bool bGenerated;

};

USTRUCT()
struct GAMESUBCATALOGEDITOR_API FCatalogStorefrontMatch
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Catalog")
	FString MatchFilter;

	UPROPERTY(EditAnywhere, Category="Catalog")
	float PullCount;

	UPROPERTY(EditAnywhere, Category="Catalog")
	TMap<FString, FString> MetaData;

};

USTRUCT()
struct GAMESUBCATALOGEDITOR_API FCatalogStorefrontDef
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Catalog")
	FString Name;

	UPROPERTY(EditAnywhere, Category="Catalog", meta=(TitleProperty="MatchFilter"))
	TArray<FCatalogStorefrontMatch> Matches;

};

USTRUCT()
struct GAMESUBCATALOGEDITOR_API FCatalogTableFilter
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString Name;

	UPROPERTY()
	FString Match;

	UPROPERTY()
	float PullCount;

};

USTRUCT()
struct GAMESUBCATALOGEDITOR_API FEpicOfferGrantInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Fulfillment")
	FString OfferNamespace;

	UPROPERTY(EditAnywhere, Category="Fulfillment")
	FString OfferId;

};

USTRUCT()
struct GAMESUBCATALOGEDITOR_API FGrantPackage
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Fulfillment")
	FString PackageName;

	UPROPERTY(EditAnywhere, Category="Fulfillment", meta=(TitleProperty="TemplateId"))
	TArray<FItemQuantity> ItemGrants;

};

UCLASS()
class GAMESUBCATALOGEDITOR_API UCatalogDefinition : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, DuplicateTransient, Category="Meta")
	FString ETag;

	UPROPERTY(EditAnywhere, Category="Catalog")
	int32 RefreshIntervalHrs;

	UPROPERTY(EditAnywhere, Category="Catalog")
	int32 DailyPurchaseHrs;

	UPROPERTY(EditAnywhere, Category="Catalog", meta=(TitleProperty="SourceName"))
	TArray<FCatalogOfferSource> Sources;

	UPROPERTY(EditAnywhere, Category="Catalog", meta=(TitleProperty="Name"))
	TArray<FCatalogStorefrontDef> Storefronts;

private:
	UPROPERTY()
	TArray<FCatalogOfferDefinition> CatalogOffers_DEPRECATED;

	UPROPERTY()
	TArray<FCatalogTableFilter> StorefrontFilters_DEPRECATED;

};

UCLASS()
class GAMESUBCATALOGEDITOR_API UCatalogFulfillment : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, DuplicateTransient, Category="Catalog Info")
	FString UniqueId;

	UPROPERTY(EditAnywhere, Category="Catalog Info")
	bool bCrossPromotionEnabled;

	UPROPERTY(EditAnywhere, Category="Fulfillment")
	FString FulfillmentClass;

	UPROPERTY(EditAnywhere, Category="Fulfillment", meta=(TitleProperty="Key"))
	TArray<FCatalogKeyValue> MetaInfo;

	UPROPERTY(EditAnywhere, Category="Fulfillment", meta=(TitleProperty="TemplateId"))
	TArray<FItemQuantity> ItemGrants;

	UPROPERTY(EditAnywhere, Category="Fulfillment", meta=(TitleProperty="PackageName"))
	TArray<FGrantPackage> AdditionalGrants;

	UPROPERTY(EditAnywhere, Category="Fulfillment")
	FString LootTableAward;

	UPROPERTY(EditAnywhere, Category="Fulfillment")
	FEpicOfferGrantInfo EpicOfferGrantInfo;

	UPROPERTY(EditAnywhere, Category="Fulfillment")
	int32 MaximumUseCount;

	UPROPERTY(EditAnywhere, Category="MTX", meta=(ArraySizeEnum="/Script/GameSubCatalog.EAppStore"))
	FString AppStoreId[12];

private:
	UPROPERTY()
	FString EpicOfferGrant_DEPRECATED;

};

UCLASS(Abstract)
class GAMESUBCATALOGEDITOR_API UCatalogMetaAsset : public UDataAsset
{
	GENERATED_BODY()

};

