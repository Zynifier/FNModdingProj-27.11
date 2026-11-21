// Copyright Epic Games, Inc. All Rights Reserved.

#include "Store/FortLlamaStoreOfferInfo.h"

UTexture* UFortLlamaStoreOfferInfo::GetDisplayAssetIcon() const
{
	return nullptr;
}

TSoftObjectPtr<UTexture2D> UFortLlamaStoreOfferInfo::GetDisplayAssetImage() const
{
	return TSoftObjectPtr<UTexture2D>();
}

UFortPackPersonality* UFortLlamaStoreOfferInfo::GetDisplayAssetPersonality() const
{
	return nullptr;
}

TSoftObjectPtr<UTexture2D> UFortLlamaStoreOfferInfo::GetDisplayAssetXrayImage() const
{
	return TSoftObjectPtr<UTexture2D>();
}

UFortCardPackItemDefinition* UFortLlamaStoreOfferInfo::GetLlamaOfferDisplayAsset() const
{
	return nullptr;
}

int32 UFortLlamaStoreOfferWidgetBase::GetCurrentRarity()
{
	return int32();
}

int32 UFortLlamaStoreOfferWidgetBase::GetPriceIndexToShow()
{
	return int32();
}

bool UFortLlamaStoreOfferWidgetBase::IsParentActivatablePanelActive()
{
	return false;
}

void UFortLlamaStoreOfferWidgetBase::LoadInFinished()
{
}

void UFortLlamaStoreOfferWidgetBase::RequestPurchase(int32 PriceIndex, int32 Quantity)
{
}

void UFortLlamaStoreOfferWidgetBase::RequestToInspect()
{
}

void UFortLlamaStoreOfferWidgetBase::ShowInitialRarityState()
{
}

void UFortLlamaStoreOfferWidgetBase::SilverUpgradeFinished()
{
}

void UFortLlamaStoreOfferWidgetBase::UpgradingFinished()
{
}
