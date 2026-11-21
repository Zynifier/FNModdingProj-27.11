// Copyright Epic Games, Inc. All Rights Reserved.

#include "Store/FortPurchaseOverlayModal.h"

void UFortPurchaseOverlayModal::Dismiss()
{
}

const TArray<FPurchasedItemInfo>& UFortPurchaseOverlayModal::GetPurchasedItems() const
{
	static TArray<FPurchasedItemInfo> Dummy;
	return Dummy;
}

int32 UFortPurchaseOverlayModal::GetQuantityPurchased() const
{
	return int32();
}

bool UFortPurchaseOverlayModal::HasMultipleItems() const
{
	return false;
}

bool UFortPurchaseOverlayModal::IsLastItem(int32 ItemIndex) const
{
	return false;
}

bool UFortPurchaseOverlayModal::ShouldShowAsRefund() const
{
	return false;
}
