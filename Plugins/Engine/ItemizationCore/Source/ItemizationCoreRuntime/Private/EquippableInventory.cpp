// Copyright Epic Games, Inc. All Rights Reserved.

#include "EquippableInventory.h"
#include "Net/UnrealNetwork.h"

void UEquippableInventory::OnRep_EquippedItems()
{
}

void UEquippableInventory::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UEquippableInventory, EquippedItems);
}
