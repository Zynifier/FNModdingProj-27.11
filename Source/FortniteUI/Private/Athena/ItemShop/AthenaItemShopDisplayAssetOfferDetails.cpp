// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/ItemShop/AthenaItemShopDisplayAssetOfferDetails.h"

void UAthenaItemShopDisplayAssetOfferDetails::AttemptPurchase()
{
}

void UAthenaItemShopDisplayAssetOfferDetails::ClearActionOnPurchaseButton()
{
}

void UAthenaItemShopDisplayAssetOfferDetails::DeclineMtxPurchase()
{
}

UWidget* UAthenaItemShopDisplayAssetOfferDetails::GetFirstFocusableButton() const
{
	return nullptr;
}

bool UAthenaItemShopDisplayAssetOfferDetails::GetSalePriceFromLastAppStore(const int32 PriceIndex, FText& SalePrice, const int32 ItemQuantity) const
{
	return false;
}

void UAthenaItemShopDisplayAssetOfferDetails::HandleBackAction()
{
}

void UAthenaItemShopDisplayAssetOfferDetails::HandleInputMethodChanged(ECommonInputType CommonInput)
{
}

void UAthenaItemShopDisplayAssetOfferDetails::HandleItemPurchaseComplete(bool bSuccess, const TArray<FPurchasedItemInfo>& PurchasedItems, const FString& OfferId)
{
}

void UAthenaItemShopDisplayAssetOfferDetails::HandleLegalTextAction()
{
}

void UAthenaItemShopDisplayAssetOfferDetails::HandleMtxPurchaseComplete(bool bSuccess, const TArray<FPurchasedItemInfo>& PurchasedItems, const FString& OfferId)
{
}

bool UAthenaItemShopDisplayAssetOfferDetails::IsGiftable() const
{
	return false;
}

void UAthenaItemShopDisplayAssetOfferDetails::RequestMtxPurchase()
{
}

void UAthenaItemShopDisplayAssetOfferDetails::SendGift()
{
}

void UAthenaItemShopDisplayAssetOfferDetails::SetCanPurchase(bool bInCanPurchase)
{
}

void UAthenaItemShopDisplayAssetOfferDetails::SetPurchaseActionOnPurchaseButton()
{
}

void UAthenaItemShopDisplayAssetOfferDetails::SetVBuckActionOnPurchaseButton()
{
}

void UAthenaItemShopDisplayAssetOfferDetails::ShowLegalTextInPopup(const FText& ItemName, const FText& LegalText)
{
}
