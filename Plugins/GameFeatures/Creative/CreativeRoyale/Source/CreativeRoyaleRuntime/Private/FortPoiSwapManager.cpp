// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortPoiSwapManager.h"

AFortPoiSwapPlayspace* UFortPoiSwapManager::GetPlayspaceForPoi(const AFortPoiVolume* PoiVolume) const
{
	return nullptr;
}

FString UFortPoiSwapManager::GetPoiSubPlotLinkCode(const AFortPoiVolume* PoiVolume) const
{
	return FString();
}

void UFortPoiSwapManager::OnPlayspaceContentLoadingStateChanged(AFortPoiSwapPlayspace* PoiSwapPlayspace, const EFortPoiSwapUserContentState& ContentLoadingState)
{
}

void UFortPoiSwapManager::OnPrePlayspaceContentUnload(AFortPoiSwapPlayspace* PoiSwapPlayspace)
{
}

void UFortPoiSwapManager::SetPoiSubPlot(const AFortPoiVolume* PoiVolume, const FString& SubPlotName, const FString& SubPlotLinkCode)
{
}

void UFortPoiSwapManager::SwapPoi(const AFortPoiVolume* PoiToSwap)
{
}
