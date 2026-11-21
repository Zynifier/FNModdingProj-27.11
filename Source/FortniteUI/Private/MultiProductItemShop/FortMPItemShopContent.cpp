// Copyright Epic Games, Inc. All Rights Reserved.

#include "MultiProductItemShop/FortMPItemShopContent.h"

void UFortMPItemShopContent::ClearRows()
{
}

UWidget* UFortMPItemShopContent::GetScrollTarget_Implementation(UWidget* TargetWidget) const
{
	return nullptr;
}

bool UFortMPItemShopContent::HasLoadedRowsForAnimatedScroll(const int32 DestinationIndex, const int32 NumRows) const
{
	return false;
}

void UFortMPItemShopContent::ScrollToRowIndex(const int32 DestinationIndex, const int32 NumRows, const bool bRefreshAll)
{
}
