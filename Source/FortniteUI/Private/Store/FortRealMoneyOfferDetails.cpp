// Copyright Epic Games, Inc. All Rights Reserved.

#include "Store/FortRealMoneyOfferDetails.h"

void UFortRealMoneyOfferDetails::ClearActionOnPurchaseButton()
{
}

void UFortRealMoneyOfferDetails::DeclineMtxPurchase()
{
}

UFortCTAButton* UFortRealMoneyOfferDetails::GetPurchaseButtonCurrent() const
{
	return nullptr;
}

bool UFortRealMoneyOfferDetails::GetSalePriceFromLastAppStore(const int32 PriceIndex, FText& SalePrice, const int32 ItemQuantity) const
{
	return false;
}

void UFortRealMoneyOfferDetails::HandleBackAction(bool& bPassthrough)
{
}

void UFortRealMoneyOfferDetails::HandleItemPurchaseComplete(bool bSuccess, const TArray<FPurchasedItemInfo>& PurchasedItems, const FString& OfferId)
{
}

void UFortRealMoneyOfferDetails::HandleMtxPurchaseComplete(bool bSuccess, const TArray<FPurchasedItemInfo>& PurchasedItems, const FString& OfferId)
{
}

void UFortRealMoneyOfferDetails::HandleOnInputMethodChanged(ECommonInputType CommonInput)
{
}

bool UFortRealMoneyOfferDetails::IsGiftable() const
{
	return false;
}

void UFortRealMoneyOfferDetails::RequestMtxPurchase()
{
}

void UFortRealMoneyOfferDetails::SendGift()
{
}

void UFortRealMoneyOfferDetails::SetCanPurchase(bool bInCanPurchase)
{
}

void UFortRealMoneyOfferDetails::SetPurchaseActionOnPurchaseButton()
{
}

void UFortRealMoneyOfferDetails::SetVBuckActionOnPurchaseButton()
{
}

void UFortRealMoneyOfferDetails::ShowLegalTextInPopup(const FText& ItemName, const FText& LegalText)
{
}
