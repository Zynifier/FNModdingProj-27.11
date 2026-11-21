// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortWorldManager.h"
#include "Net/UnrealNetwork.h"

void AFortWorldManager::OnRep_InitialGlobalWind()
{
}

void AFortWorldManager::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortWorldManager, InitialGlobalWind);
	DOREPLIFETIME(AFortWorldManager, FinalNumChosenBuildingFoundations);
	DOREPLIFETIME(AFortWorldManager, ChosenBuildingFoundations);
}
