// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortEventPurchaseLevelsModal.h"

const UFortEventScreenData* UFortEventPurchaseLevelsModal::GetEventScreenData() const
{
	return nullptr;
}

void UFortEventPurchaseLevelsModal::HandlePurchaseComplete(bool bSuccess, const TArray<FPurchasedItemInfo>& PurchasedItems, const FString& InOfferId)
{
}
