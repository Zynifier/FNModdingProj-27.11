// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Modifiers/FortAthenaMutator_LoadoutSwap.h"
#include "Net/UnrealNetwork.h"

void AFortAthenaMutator_LoadoutSwap::OnRep_ServerWorldTimeOfNextSwap()
{
}

void AFortAthenaMutator_LoadoutSwap::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaMutator_LoadoutSwap, ServerWorldTimeOfNextSwap);
	DOREPLIFETIME(AFortAthenaMutator_LoadoutSwap, NextItemsToGrant);
	DOREPLIFETIME(AFortAthenaMutator_LoadoutSwap, ItemsWithInfiniteAmmo);
}
