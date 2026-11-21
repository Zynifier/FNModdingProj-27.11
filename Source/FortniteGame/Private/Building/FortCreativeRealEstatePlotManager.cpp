// Copyright Epic Games, Inc. All Rights Reserved.

#include "Building/FortCreativeRealEstatePlotManager.h"
#include "Net/UnrealNetwork.h"

void AFortCreativeRealEstatePlotManager::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortCreativeRealEstatePlotManager, ActiveCreativeRealEstatePlots);
}
