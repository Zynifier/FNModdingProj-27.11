// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "Athena/ItemShop/AthenaItemShopEnums.h"
#include "CatalogTypes.h"
#include "Online/FortMcpContext.h"
#include "Online/FortMcpTypes.h"
#include "FortItemShopOfferVM.generated.h"

class UAthenaItemShopOfferInfo;
class UFortAccountItemDefinition;
class UObject;
enum class EMcpSubscriptionState : uint8;
enum class EOfferPurchaseError : uint8;

UCLASS()
class UFortItemShopOfferVM : public UMVVMViewModelBase
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnPresentationsLoaded, const TArray<UObject*>&, LoadedPresentations);
UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_FourParams(FOnUndoPurchaseComplete, const bool, bSuccess, const TArray<FPurchasedItemInfo>&, RefundedItems, FString, PurchaseId, const int32, MtxReturned);

public:
	UFUNCTION(BlueprintCallable)
	void CancelLoadingPresentations();

	UFUNCTION(BlueprintPure)
	EOfferPurchaseError CanPurchaseOffer(const int32 PriceIndex) const;

	UFUNCTION(BlueprintPure)
	FString GetDisplayAssetName() const;

	UFUNCTION(BlueprintPure)
	UFortAccountItemDefinition* GetItemDefFromTemplateId(const FString& TemplateId) const;

	UFUNCTION(BlueprintPure)
	FString GetOfferTrackingId() const;

	UFUNCTION(BlueprintPure)
	bool HasMultiplePrices() const;

	UFUNCTION(BlueprintCallable)
	bool LoadPresentationsFromDisplayAssetPath(const FString& InDisplayAssetPath, const FOnPresentationsLoaded& OnLoadedCallback);

	UFUNCTION(BlueprintCallable)
	bool LoadPresentationsFromSubscriptionCMS(const EMcpSubscriptionState SubscriptionState, const FOnPresentationsLoaded& OnLoadedCallback);

	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	bool NeedsPurchaseConfirmationMessage(FText& OutCustomConfirmationMessage) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	EOfferPurchaseError PurchaseOffer(const int32 PriceIndex, const FOnPurchaseOfferComplete& OnPurchaseCompleteCallback) const;

	UFUNCTION(BlueprintPure)
	bool ShouldLoadSubscriptionImagesFromCMS() const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	void UndoPurchase(const FOnUndoPurchaseComplete& OnUndoPurchaseCompleteCallback) const;

private:
	UFUNCTION()
	void HandleRealMoneyPurchaseComplete(bool bSuccess, const TArray<FPurchasedItemInfo>& PurchasedItems);

	UPROPERTY(BlueprintReadOnly, Category="FortItemShopOfferVM", meta=(AllowPrivateAccess))
	FString OfferId;

	UPROPERTY(BlueprintReadOnly, Category="FortItemShopOfferVM", meta=(AllowPrivateAccess))
	FText ShortName;

	UPROPERTY(BlueprintReadOnly, Category="FortItemShopOfferVM", meta=(AllowPrivateAccess))
	FText ShortDescription;

	UPROPERTY(BlueprintReadOnly, Category="FortItemShopOfferVM", meta=(AllowPrivateAccess))
	int32 Price;

	UPROPERTY(BlueprintReadOnly, Category="FortItemShopOfferVM", meta=(AllowPrivateAccess))
	int32 RegularPrice;

	UPROPERTY(BlueprintReadOnly, Category="FortItemShopOfferVM", meta=(AllowPrivateAccess))
	EItemShopCurrency CurrencyType;

	UPROPERTY(BlueprintReadOnly, Category="FortItemShopOfferVM", meta=(AllowPrivateAccess))
	FString CurrencySubType;

	UPROPERTY(BlueprintReadOnly, Category="FortItemShopOfferVM", meta=(AllowPrivateAccess))
	EItemShopTileSize TileSize;

	UPROPERTY(BlueprintReadOnly, Category="FortItemShopOfferVM", meta=(AllowPrivateAccess))
	EViolatorIntensity ViolatorIntensity;

	UPROPERTY(BlueprintReadOnly, Category="FortItemShopOfferVM", meta=(AllowPrivateAccess))
	FText ViolatorText;

	UPROPERTY(BlueprintReadOnly, Category="FortItemShopOfferVM", meta=(AllowPrivateAccess))
	FString DisplayAssetPath;

	UPROPERTY(BlueprintReadOnly, Category="FortItemShopOfferVM", meta=(AllowPrivateAccess))
	TArray<FItemQuantity> GrantedItems;

	UPROPERTY(BlueprintReadOnly, Category="FortItemShopOfferVM", meta=(AllowPrivateAccess))
	int32 MtxQuantity;

	UPROPERTY(BlueprintReadOnly, Category="FortItemShopOfferVM", meta=(AllowPrivateAccess))
	TArray<FText> TagTexts;

	UPROPERTY(BlueprintReadOnly, Category="FortItemShopOfferVM", meta=(AllowPrivateAccess))
	bool bOwned;

	UPROPERTY(BlueprintReadOnly, Category="FortItemShopOfferVM", meta=(AllowPrivateAccess))
	bool bCanUndoPurchase;

	UPROPERTY(BlueprintReadOnly, Category="FortItemShopOfferVM", meta=(AllowPrivateAccess))
	bool bSuppressRegularPrice;

	UPROPERTY(BlueprintReadOnly, Category="FortItemShopOfferVM", meta=(AllowPrivateAccess))
	FString OverrideParentOfferTrackingId;

	UPROPERTY(BlueprintReadOnly, Category="FortItemShopOfferVM", meta=(AllowPrivateAccess))
	TArray<FString> Categories;

	UPROPERTY(BlueprintReadOnly, Category="FortItemShopOfferVM", meta=(AllowPrivateAccess))
	int32 QuantityRemaining;

	UPROPERTY(BlueprintReadOnly, Category="FortItemShopOfferVM", meta=(AllowPrivateAccess))
	int32 SortPriority;

	UPROPERTY(BlueprintReadOnly, Category="FortItemShopOfferVM", meta=(AllowPrivateAccess))
	int32 MaxLevel;

	UPROPERTY(BlueprintReadOnly, Category="FortItemShopOfferVM", meta=(AllowPrivateAccess))
	bool bIsSubscriptionOffer;

	UPROPERTY(BlueprintReadOnly, Category="FortItemShopOfferVM", meta=(AllowPrivateAccess))
	bool bIsProgressiveCosmeticOffer;

	UPROPERTY(BlueprintReadOnly, Category="FortItemShopOfferVM", meta=(AllowPrivateAccess))
	bool bShouldShowBattlePassPurchase;

	UPROPERTY(BlueprintReadOnly, Category="FortItemShopOfferVM", meta=(AllowPrivateAccess))
	FString LayoutId;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortItemShopOfferVM", meta=(AllowPrivateAccess))
	TObjectPtr<UAthenaItemShopOfferInfo> OfferInfo;

	UPROPERTY(Transient)
	TArray<FPurchasedItemInfo> CachedRefundedItems;

};

