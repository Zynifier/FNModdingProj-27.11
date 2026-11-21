// Copyright Epic Games, Inc. All Rights Reserved.

#include "MtxStore/FortMtxStoreRootBase_Legacy.h"

bool UFortMtxStoreRootBase_Legacy::AreOffersLoaded() const
{
	return false;
}

void UFortMtxStoreRootBase_Legacy::ClearOfferWidgets_Implementation()
{
}

void UFortMtxStoreRootBase_Legacy::GenerateOfferWidget_Implementation(UFortStoreFrontOfferInfo* OfferData)
{
}

FMtxBreakdown UFortMtxStoreRootBase_Legacy::GetMtxBreakdown() const
{
	return FMtxBreakdown();
}

TArray<FString> UFortMtxStoreRootBase_Legacy::GetStorefrontNames() const
{
	return TArray<FString>();
}

void UFortMtxStoreRootBase_Legacy::OnStartReadingOffers_Implementation()
{
}

void UFortMtxStoreRootBase_Legacy::PushStoreSelection()
{
}

void UFortMtxStoreRootBase_Legacy::SetStorefrontNames(const TArray<FString>& InStorefrontNames)
{
}
