// Copyright Epic Games, Inc. All Rights Reserved.

#include "MtxStore/FortMtxStoreRootBase.h"

bool UFortMtxStoreRootBase::AreOffersLoaded() const
{
	return false;
}

void UFortMtxStoreRootBase::ClearOfferWidgets_Implementation()
{
}

void UFortMtxStoreRootBase::GenerateOfferWidget_Implementation(UFortStoreFrontOfferInfo* OfferData)
{
}

FMtxBreakdown UFortMtxStoreRootBase::GetMtxBreakdown() const
{
	return FMtxBreakdown();
}

TArray<FString> UFortMtxStoreRootBase::GetStorefrontNames() const
{
	return TArray<FString>();
}

void UFortMtxStoreRootBase::OnStartReadingOffers_Implementation()
{
}

void UFortMtxStoreRootBase::PushStoreSelection()
{
}

void UFortMtxStoreRootBase::SetStorefrontNames(const TArray<FString>& InStorefrontNames)
{
}
