// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortEventPurchasePremiumTrackModal.h"

const UFortEventScreenData* UFortEventPurchasePremiumTrackModal::GetEventScreenData() const
{
	return nullptr;
}

void UFortEventPurchasePremiumTrackModal::HandlePurchaseComplete(bool bSuccess, const TArray<FPurchasedItemInfo>& PurchasedItems, const FString& InOfferId)
{
}

UFortPurchasePremiumTrackBody::UFortPurchasePremiumTrackBody(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}
