// Copyright Epic Games, Inc. All Rights Reserved.

#include "STW/Items/FortInventoryOutpost.h"
#include "Net/UnrealNetwork.h"

void AFortInventoryOutpost::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortInventoryOutpost, bHasUnavailableItems);
}
