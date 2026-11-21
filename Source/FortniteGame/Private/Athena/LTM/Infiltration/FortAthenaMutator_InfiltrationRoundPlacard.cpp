// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/LTM/Infiltration/FortAthenaMutator_InfiltrationRoundPlacard.h"
#include "Net/UnrealNetwork.h"

void AFortAthenaMutator_InfiltrationRoundPlacard::OnRep_RoundInfoInterfaceRedirectReplicationObject()
{
}

void AFortAthenaMutator_InfiltrationRoundPlacard::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaMutator_InfiltrationRoundPlacard, RoundInfoInterfaceRedirectReplicationObject);
}
