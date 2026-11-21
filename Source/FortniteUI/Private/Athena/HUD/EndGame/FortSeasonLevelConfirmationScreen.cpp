// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/HUD/EndGame/FortSeasonLevelConfirmationScreen.h"

bool UFortSeasonLevelConfirmationScreen::CanAffordTierBundlePurchase() const
{
	return false;
}

bool UFortSeasonLevelConfirmationScreen::CanAffordTierPurchase() const
{
	return false;
}

void UFortSeasonLevelConfirmationScreen::HandleCloseScreen(bool& bPassThrough)
{
}

void UFortSeasonLevelConfirmationScreen::HandlePurchaseComplete(bool bSuccess, const TArray<FPurchasedItemInfo>& PurchasedItems, const FString& OfferId)
{
}
