// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/ItemShop/AthenaItemShopOfferDetailsWidgetBase.h"

UWidget* UAthenaItemShopOfferDetailsWidgetBase::GetNextFocusableButton(TArray<UWidget*> Buttons, int32 InitialIndex, bool bForwardDirection) const
{
	return nullptr;
}

UFortStoreFrontOfferInfo* UAthenaItemShopOfferDetailsWidgetBase::GetOfferInfo() const
{
	return nullptr;
}

UFortStoreFrontOfferInfo* UAthenaItemShopOfferDetailsWidgetBase::GetOfferInfoById(const FString& OfferId) const
{
	return nullptr;
}

void UAthenaItemShopOfferDetailsWidgetBase::HandleCurrentlyViewedAccountInfoChanged(FFortPublicAccountInfo NewInfo)
{
}

void UAthenaItemShopOfferDetailsWidgetBase::HandleGiftingItemPurchaseComplete(bool bSuccess, const TArray<FPurchasedItemInfo>& PurchasedItems, const FString& OfferId)
{
}

void UAthenaItemShopOfferDetailsWidgetBase::HandleRealMoneyPurchaseComplete(bool bSuccess, const TArray<FPurchasedItemInfo>& PurchasedItems)
{
}

void UAthenaItemShopOfferDetailsWidgetBase::HandleUndoAction(const float HoldTime)
{
}

bool UAthenaItemShopOfferDetailsWidgetBase::IsFocusableButton(const UWidget* InButton) const
{
	return false;
}

bool UAthenaItemShopOfferDetailsWidgetBase::IsReloadMtxEnabled()
{
	return false;
}

void UAthenaItemShopOfferDetailsWidgetBase::PurchaseOffer(const FOnPurchaseOfferComplete& Callback, int32 Quantity, const float HoldTime)
{
}

void UAthenaItemShopOfferDetailsWidgetBase::RefreshOfferInfo()
{
}

void UAthenaItemShopOfferDetailsWidgetBase::RefreshUndoState(UFortStoreFrontOfferInfo* OfferPurchased)
{
}

void UAthenaItemShopOfferDetailsWidgetBase::SendRealMoneyPurchase(int32 PriceIndex, int32 Quantity)
{
}

void UAthenaItemShopOfferDetailsWidgetBase::SendShopInteractionAnalytic(const FString& Interaction, const float HoldTime) const
{
}

void UAthenaItemShopOfferDetailsWidgetBase::SetOffer(UFortStoreFrontOfferInfo* InOfferData)
{
}

bool UAthenaItemShopOfferDetailsWidgetBase::ShouldHavePurchaseConfirmation() const
{
	return false;
}

void UAthenaItemShopOfferDetailsWidgetBase::ShowItemPresentationScreen(const TArray<FPurchasedItemInfo>& PurchasedItems)
{
}

void UAthenaItemShopOfferDetailsWidgetBase::ShowPurchasedOverlayWidget(int32 QuantityPurchased, const TArray<FPurchasedItemInfo> PurchasedItems, bool bShowAsRefund, const FString OfferId)
{
}

void UAthenaItemShopOfferDetailsWidgetBase::ShowReloadMtx()
{
}
