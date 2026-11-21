// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Modifiers/FortAthenaMutator_MaxItemSlots.h"
#include "Net/UnrealNetwork.h"

void AFortAthenaMutator_MaxItemSlots::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaMutator_MaxItemSlots, MaxItemSlots);
}
