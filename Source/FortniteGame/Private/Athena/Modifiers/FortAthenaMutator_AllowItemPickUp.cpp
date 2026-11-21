// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Modifiers/FortAthenaMutator_AllowItemPickUp.h"
#include "Net/UnrealNetwork.h"

void AFortAthenaMutator_AllowItemPickUp::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaMutator_AllowItemPickUp, bAllowItemPickUp);
}
