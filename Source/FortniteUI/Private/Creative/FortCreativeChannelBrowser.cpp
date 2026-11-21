// Copyright Epic Games, Inc. All Rights Reserved.

#include "Creative/FortCreativeChannelBrowser.h"

TMap<AActor*, FText> UFortCreativeChannelBrowser::GetSortedDeviceMap(const TMap<AActor*, FText>& InDeviceMap)
{
	return TMap<AActor*, FText>();
}

void UFortCreativeChannelBrowser::RequestCloseUI()
{
}

bool UFortCreativeChannelBrowser::ShouldShowChannelDetails()
{
	return false;
}
