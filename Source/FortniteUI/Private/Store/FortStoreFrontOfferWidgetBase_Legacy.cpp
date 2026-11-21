// Copyright Epic Games, Inc. All Rights Reserved.

#include "Store/FortStoreFrontOfferWidgetBase_Legacy.h"

void UFortStoreFrontOfferWidgetBase_Legacy::AddOffer(UFortStoreFrontOfferInfo* InOfferData)
{
}

TSoftObjectPtr<UMaterialInterface> UFortStoreFrontOfferWidgetBase_Legacy::GetFirstOfferSeriesBackgroundMaterial() const
{
	return TSoftObjectPtr<UMaterialInterface>();
}

TSoftObjectPtr<UTexture2D> UFortStoreFrontOfferWidgetBase_Legacy::GetFirstOfferSeriesBackgroundTexture() const
{
	return TSoftObjectPtr<UTexture2D>();
}

UFortStoreFrontOfferInfo* UFortStoreFrontOfferWidgetBase_Legacy::GetOfferInfo() const
{
	return nullptr;
}

UFortMtxStoreRootBase_Legacy* UFortStoreFrontOfferWidgetBase_Legacy::GetStoreRoot() const
{
	return nullptr;
}

void UFortStoreFrontOfferWidgetBase_Legacy::HandleCarouselOfferChanged()
{
}

void UFortStoreFrontOfferWidgetBase_Legacy::HandleCurrentlyViewedAccountInfoChanged(FFortPublicAccountInfo NewInfo)
{
}

void UFortStoreFrontOfferWidgetBase_Legacy::OnDetailsOpened(UFortStoreFrontOfferDetailsWidgetBase* DetailsWidget)
{
}

void UFortStoreFrontOfferWidgetBase_Legacy::RemoveAllOffers()
{
}

void UFortStoreFrontOfferWidgetBase_Legacy::SendRealMoneyStoreInteractionAnalytic(const FString& Interaction) const
{
}

void UFortStoreFrontOfferWidgetBase_Legacy::SendSeasonPassInteractionAnalytic(const FString& Interaction) const
{
}

void UFortStoreFrontOfferWidgetBase_Legacy::SendShopInteractionAnalytic(const FString& Interaction) const
{
}

void UFortStoreFrontOfferWidgetBase_Legacy::SetIndexInSection(int32 InIndexInSection)
{
}

void UFortStoreFrontOfferWidgetBase_Legacy::SetStoreRoot(UFortMtxStoreRootBase_Legacy* InStoreRoot)
{
}

void UFortStoreFrontOfferWidgetBase_Legacy::SetupOffer(UFortStoreFrontOfferInfo* InOfferData)
{
}
