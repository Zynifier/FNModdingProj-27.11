// Copyright Epic Games, Inc. All Rights Reserved.

#include "ViewModels/ItemShop/FortItemShopOfferVM.h"

void UFortItemShopOfferVM::CancelLoadingPresentations()
{
}

EOfferPurchaseError UFortItemShopOfferVM::CanPurchaseOffer(const int32 PriceIndex) const
{
	return EOfferPurchaseError();
}

FString UFortItemShopOfferVM::GetDisplayAssetName() const
{
	return FString();
}

UFortAccountItemDefinition* UFortItemShopOfferVM::GetItemDefFromTemplateId(const FString& TemplateId) const
{
	return nullptr;
}

FString UFortItemShopOfferVM::GetOfferTrackingId() const
{
	return FString();
}

void UFortItemShopOfferVM::HandleRealMoneyPurchaseComplete(bool bSuccess, const TArray<FPurchasedItemInfo>& PurchasedItems)
{
}

bool UFortItemShopOfferVM::HasMultiplePrices() const
{
	return false;
}

bool UFortItemShopOfferVM::LoadPresentationsFromDisplayAssetPath(const FString& InDisplayAssetPath, const FOnPresentationsLoaded& OnLoadedCallback)
{
	return false;
}

bool UFortItemShopOfferVM::LoadPresentationsFromSubscriptionCMS(const EMcpSubscriptionState SubscriptionState, const FOnPresentationsLoaded& OnLoadedCallback)
{
	return false;
}

bool UFortItemShopOfferVM::NeedsPurchaseConfirmationMessage(FText& OutCustomConfirmationMessage) const
{
	return false;
}

EOfferPurchaseError UFortItemShopOfferVM::PurchaseOffer(const int32 PriceIndex, const FOnPurchaseOfferComplete& OnPurchaseCompleteCallback) const
{
	return EOfferPurchaseError();
}

bool UFortItemShopOfferVM::ShouldLoadSubscriptionImagesFromCMS() const
{
	return false;
}

void UFortItemShopOfferVM::UndoPurchase(const FOnUndoPurchaseComplete& OnUndoPurchaseCompleteCallback) const
{
}
