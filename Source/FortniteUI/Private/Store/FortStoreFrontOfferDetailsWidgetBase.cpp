// Copyright Epic Games, Inc. All Rights Reserved.

#include "Store/FortStoreFrontOfferDetailsWidgetBase.h"

void UFortStoreFrontOfferDetailsWidgetBase::ConfirmUndo()
{
}

void UFortStoreFrontOfferDetailsWidgetBase::DeactivateUndoButton()
{
}

bool UFortStoreFrontOfferDetailsWidgetBase::FindItemQuantityPair(UFortItemDefinition* ItemDefinition, TArray<FFortItemQuantityPair>& InItemQuantityPairs, FFortItemQuantityPair& OutItemQuantity)
{
	return false;
}

UFortStoreFrontOfferInfo* UFortStoreFrontOfferDetailsWidgetBase::GetOfferInfo() const
{
	return nullptr;
}

UFortStoreFrontOfferInfo* UFortStoreFrontOfferDetailsWidgetBase::GetOfferInfoById(const FString& OfferId)
{
	return nullptr;
}

int32 UFortStoreFrontOfferDetailsWidgetBase::GetPriceIndexToShow()
{
	return int32();
}

void UFortStoreFrontOfferDetailsWidgetBase::HandleBattlePassPurchaseComplete(bool bSuccess)
{
}

void UFortStoreFrontOfferDetailsWidgetBase::HandleCurrentlyViewedAccountInfoChanged(FFortPublicAccountInfo NewInfo)
{
}

void UFortStoreFrontOfferDetailsWidgetBase::HandleGiftingItemPurchaseComplete(bool bSuccess, const TArray<FPurchasedItemInfo>& PurchasedItems, const FString& OfferId)
{
}

void UFortStoreFrontOfferDetailsWidgetBase::HandleRealMoneyPurchaseComplete(bool bSuccess, const TArray<FPurchasedItemInfo>& PurchasedItems)
{
}

void UFortStoreFrontOfferDetailsWidgetBase::HandleVaultItemsViewed(const TArray<UFortItem*>& ItemsShown)
{
}

bool UFortStoreFrontOfferDetailsWidgetBase::IsReloadMtxEnabled()
{
	return false;
}

void UFortStoreFrontOfferDetailsWidgetBase::OnEnterViewModeActionCommitted(bool& PassThrough)
{
}

void UFortStoreFrontOfferDetailsWidgetBase::PurchaseOffer(const FOnPurchaseOfferComplete& Callback, int32 Quantity, const float HoldTime)
{
}

void UFortStoreFrontOfferDetailsWidgetBase::RefreshOfferInfo()
{
}

void UFortStoreFrontOfferDetailsWidgetBase::RefreshUndoState(UFortStoreFrontOfferInfo* OfferPurchased)
{
}

void UFortStoreFrontOfferDetailsWidgetBase::RegisterItemRewardInteraction(UFortAthenaReward* InItemReward)
{
}

void UFortStoreFrontOfferDetailsWidgetBase::RequestExternalPurchase(int32 PriceIndex, int32 Quantity)
{
}

void UFortStoreFrontOfferDetailsWidgetBase::SendingToMainStore()
{
}

void UFortStoreFrontOfferDetailsWidgetBase::SendRealMoneyPurchase(int32 PriceIndex, int32 Quantity)
{
}

void UFortStoreFrontOfferDetailsWidgetBase::SendRealMoneyStoreInteractionAnalytic(const FString& Interaction) const
{
}

void UFortStoreFrontOfferDetailsWidgetBase::SendReloadMtxPurchaseSKUAnalytic() const
{
}

void UFortStoreFrontOfferDetailsWidgetBase::SendSeasonPassInteractionAnalytic(const FString& Interaction) const
{
}

void UFortStoreFrontOfferDetailsWidgetBase::SendShopInteractionAnalytic(const FString& Interaction, const float HoldTime) const
{
}

void UFortStoreFrontOfferDetailsWidgetBase::SendUndoMtxReturnedAnalytic(const FString& Interaction, const FString PurchaseID, const int32 MtxReturned) const
{
}

void UFortStoreFrontOfferDetailsWidgetBase::SetIsInItemViewMode(const bool Value)
{
}

void UFortStoreFrontOfferDetailsWidgetBase::SetItemRewardSecondaryItem(const UFortItemDefinition* ItemDef, TArray<FFortItemQuantityPair> AllItemQuantityPairs, UFortAthenaReward* RewardWidget)
{
}

void UFortStoreFrontOfferDetailsWidgetBase::SetPagedItems(const TArray<UFortStoreFrontOfferInfo*>& InPagedItems)
{
}

void UFortStoreFrontOfferDetailsWidgetBase::SetSecondaryItem(const UFortItemDefinition* ItemDefinition)
{
}

void UFortStoreFrontOfferDetailsWidgetBase::SetShouldAllowItemViewModeAction(const bool Value)
{
}

void UFortStoreFrontOfferDetailsWidgetBase::SetStoreRoot(UFortMtxStoreRootBase* InStoreRoot)
{
}

void UFortStoreFrontOfferDetailsWidgetBase::SetupOffer(UFortStoreFrontOfferInfo* InOfferData)
{
}

bool UFortStoreFrontOfferDetailsWidgetBase::ShouldDisplayOfferPurchasedOverlay() const
{
	return false;
}

bool UFortStoreFrontOfferDetailsWidgetBase::ShouldHavePurchaseConfirmation() const
{
	return false;
}

void UFortStoreFrontOfferDetailsWidgetBase::ShowItemPresentationScreen(const TArray<FPurchasedItemInfo>& PurchasedItems)
{
}

void UFortStoreFrontOfferDetailsWidgetBase::ShowPurchasedOverlayWidget(int32 QuantityPurchased, const TArray<FPurchasedItemInfo> PurchasedItems, bool bShowAsRefund, const FString OfferId)
{
}

void UFortStoreFrontOfferDetailsWidgetBase::ShowReloadMtx()
{
}

void UFortStoreFrontOfferDetailsWidgetBase::ShowVaultItem(const UFortItem* InItemToRepresent)
{
}

void UFortStoreFrontOfferDetailsWidgetBase::ShowVaultItemFromItemReward(UFortAthenaReward* InItemReward)
{
}
