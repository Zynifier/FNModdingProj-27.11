// Copyright Epic Games, Inc. All Rights Reserved.

#include "DiscoveryShared/FortDiscoverSurfaceViewModel.h"

int32 UFortDiscoverProviderViewModel::GetIslandCount() const
{
	return int32();
}

void UFortDiscoverProviderViewModel::ResetImpressions()
{
}

void UFortDiscoverProviderViewModel::StartVisibleImpressions()
{
}

void UFortDiscoverProviderViewModel::StopVisibleImpression()
{
}

void UFortDiscoverSurfaceViewModel::FetchNextPageFromIndex(int32 SelectionIndex, int32 ProviderIndex)
{
}

void UFortDiscoverSurfaceViewModel::FetchNextPageFromPanelName(int32 SelectionIndex, FName PanelName)
{
}

void UFortDiscoverSurfaceViewModel::FireExitedImpressionsFromSurface()
{
}

const int32 UFortDiscoverSurfaceViewModel::GetProviderIndexFromPanelName(FName PanelName) const
{
	return int32();
}

void UFortDiscoverSurfaceViewModel::StartAnalyticsImpressions()
{
}

void UFortDiscoverSurfaceViewModel::StartVisibleImpressions()
{
}

void UFortDiscoverSurfaceViewModel::StopVisibleImpressions()
{
}

void UFortDiscoverSurfaceViewModel::UpdateCachedSurfaceData(const bool bShouldForceUpdate)
{
}
