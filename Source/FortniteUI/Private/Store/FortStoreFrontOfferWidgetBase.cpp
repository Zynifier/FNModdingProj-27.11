// Copyright Epic Games, Inc. All Rights Reserved.

#include "Store/FortStoreFrontOfferWidgetBase.h"

void UFortStoreFrontOfferWidgetBase::AddOffer(UFortStoreFrontOfferInfo* InOfferData)
{
}

TSoftObjectPtr<UMaterialInterface> UFortStoreFrontOfferWidgetBase::GetFirstOfferSeriesBackgroundMaterial() const
{
	return TSoftObjectPtr<UMaterialInterface>();
}

TSoftObjectPtr<UTexture2D> UFortStoreFrontOfferWidgetBase::GetFirstOfferSeriesBackgroundTexture() const
{
	return TSoftObjectPtr<UTexture2D>();
}

UFortStoreFrontOfferInfo* UFortStoreFrontOfferWidgetBase::GetOfferInfo() const
{
	return nullptr;
}

UFortMtxStoreRootBase* UFortStoreFrontOfferWidgetBase::GetStoreRoot() const
{
	return nullptr;
}

void UFortStoreFrontOfferWidgetBase::HandleCarouselOfferChanged()
{
}

void UFortStoreFrontOfferWidgetBase::HandleCurrentlyViewedAccountInfoChanged(FFortPublicAccountInfo NewInfo)
{
}

void UFortStoreFrontOfferWidgetBase::OnDetailsOpened(UFortStoreFrontOfferDetailsWidgetBase* DetailsWidget)
{
}

void UFortStoreFrontOfferWidgetBase::RemoveAllOffers()
{
}

void UFortStoreFrontOfferWidgetBase::SendRealMoneyStoreInteractionAnalytic(const FString& Interaction) const
{
}

void UFortStoreFrontOfferWidgetBase::SendSeasonPassInteractionAnalytic(const FString& Interaction) const
{
}

void UFortStoreFrontOfferWidgetBase::SendShopInteractionAnalytic(const FString& Interaction) const
{
}

void UFortStoreFrontOfferWidgetBase::SetIndexInSection(int32 InIndexInSection)
{
}

void UFortStoreFrontOfferWidgetBase::SetStoreRoot(UFortMtxStoreRootBase* InStoreRoot)
{
}

void UFortStoreFrontOfferWidgetBase::SetStoreRoot_Legacy(UFortMtxStoreRootBase_Legacy* InStoreRoot)
{
}

void UFortStoreFrontOfferWidgetBase::SetupOffer(UFortStoreFrontOfferInfo* InOfferData)
{
}
