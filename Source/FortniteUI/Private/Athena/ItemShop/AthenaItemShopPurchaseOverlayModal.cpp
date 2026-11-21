// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/ItemShop/AthenaItemShopPurchaseOverlayModal.h"

void UAthenaItemShopPurchaseOverlayModal::Dismiss()
{
}

const TArray<FPurchasedItemInfo>& UAthenaItemShopPurchaseOverlayModal::GetPurchasedItems() const
{
	static TArray<FPurchasedItemInfo> Dummy;
	return Dummy;
}

int32 UAthenaItemShopPurchaseOverlayModal::GetQuantityPurchased() const
{
	return int32();
}

bool UAthenaItemShopPurchaseOverlayModal::HasMultipleItems() const
{
	return false;
}

bool UAthenaItemShopPurchaseOverlayModal::IsLastItem(int32 ItemIndex) const
{
	return false;
}

bool UAthenaItemShopPurchaseOverlayModal::ShouldShowAsRefund() const
{
	return false;
}
