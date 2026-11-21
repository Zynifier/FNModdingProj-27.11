// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Modifiers/FortAthenaMutator_AllowItemDrop.h"
#include "Net/UnrealNetwork.h"

void AFortAthenaMutator_AllowItemDrop::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaMutator_AllowItemDrop, bAllowItemDrop);
}
