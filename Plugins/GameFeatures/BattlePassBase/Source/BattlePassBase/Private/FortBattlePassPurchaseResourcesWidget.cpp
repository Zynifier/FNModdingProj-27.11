// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortBattlePassPurchaseResourcesWidget.h"

void UFortBattlePassPurchaseResourcesWidget::HandlePurchaseComplete(bool bSuccess, const TArray<FPurchasedItemInfo>& PurchasedItems, const FString& OfferId)
{
}

void UFortBattlePassPurchaseResourcesWidget::HandlePurchaseMultiComplete(bool bSuccess, const TArray<FPurchasedItemInfo>& PurchasedItems, const TArray<FString>& OfferIdList)
{
}

bool UFortBattlePassPurchaseResourcesWidget::IsReloadMtxEnabled()
{
	return false;
}
