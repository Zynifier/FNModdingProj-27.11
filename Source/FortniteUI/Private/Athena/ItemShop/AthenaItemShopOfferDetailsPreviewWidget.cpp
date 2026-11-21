// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/ItemShop/AthenaItemShopOfferDetailsPreviewWidget.h"

void UAthenaItemShopOfferDetailsPreviewWidget::FocusOnWidget(UWidget* WidgetToFocus)
{
}

bool UAthenaItemShopOfferDetailsPreviewWidget::GetSalePriceFromLastAppStore(const int32 PriceIndex, FText& SalePrice, const int32 ItemQuantity) const
{
	return false;
}

FUnlockableVariantPreviewInfo UAthenaItemShopOfferDetailsPreviewWidget::GetVariantPreviewInfo()
{
	return FUnlockableVariantPreviewInfo();
}

void UAthenaItemShopOfferDetailsPreviewWidget::HandleGetVBucksClicked()
{
}

void UAthenaItemShopOfferDetailsPreviewWidget::HandleInputMethodChanged(ECommonInputType InputType)
{
}

void UAthenaItemShopOfferDetailsPreviewWidget::HandleItemShown(const UFortAccountItemDefinition* AccountItemDef)
{
}

bool UAthenaItemShopOfferDetailsPreviewWidget::IsMultiplePriceRealMoneyOffer() const
{
	return false;
}

bool UAthenaItemShopOfferDetailsPreviewWidget::IsSingleItemEquipped() const
{
	return false;
}

void UAthenaItemShopOfferDetailsPreviewWidget::RefreshFocus()
{
}

void UAthenaItemShopOfferDetailsPreviewWidget::RegisterItemRewardInteraction(UFortAthenaReward* InItemReward)
{
}

void UAthenaItemShopOfferDetailsPreviewWidget::SetIsPurchasing(bool bInIsPurchasing)
{
}

void UAthenaItemShopOfferDetailsPreviewWidget::SetItemToRepresent(const UFortItem* InItemToRepresent)
{
}

void UAthenaItemShopOfferDetailsPreviewWidget::SetupNavigationForSection(UAthenaItemShopSection* SectionToNavigate)
{
}

bool UAthenaItemShopOfferDetailsPreviewWidget::ShouldDisplayOfferPurchasedOverlay() const
{
	return false;
}

void UAthenaItemShopOfferDetailsPreviewWidget::ShowItemFromItemReward(UFortAthenaReward* InItemReward)
{
}

void UAthenaItemShopOfferDetailsPreviewWidget::TriggerPurchaseChoiceRequest()
{
}

void UAthenaItemShopOfferDetailsPreviewWidget::TryDismiss()
{
}

void UAthenaItemShopOfferDetailsPreviewWidget::UpdatePreviewFromOffer()
{
}

void UAthenaItemShopOfferDetailsPreviewWidget::UpdateSwipeButtonsVisibility()
{
}
