// Copyright Epic Games, Inc. All Rights Reserved.

#include "Pawns/Net/FortAIPawnIrisSharedRepMovement.h"
#include "Net/UnrealNetwork.h"

void UFortAIPawnIrisSharedRepMovement::OnRep_FastSharedReplication()
{
}

void UFortAIPawnIrisSharedRepMovement::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortAIPawnIrisSharedRepMovement, AISharedRepMovement);
}
