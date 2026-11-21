// Copyright Epic Games, Inc. All Rights Reserved.

#include "Online/FortMtxWallets.h"

TArray<EAppStore> UFortMtxWallets::GetAvailableAppStores()
{
	return TArray<EAppStore>();
}

bool UFortMtxWallets::GetSelectedAppStore(EAppStore& OutAppStore)
{
	return false;
}

void UFortMtxWallets::SetSelectedAppStore(const EAppStore InAppStore)
{
}
