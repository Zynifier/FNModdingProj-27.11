// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Modifiers/FortAthenaMutator_BallerRace.h"
#include "Net/UnrealNetwork.h"

void AFortAthenaMutator_BallerRace::OnMutatorGameplayEvent(int32 EventId, int32 EventParam1, int32 EventParam2, int32 EventParam3)
{
}

void AFortAthenaMutator_BallerRace::OnRep_ServerWorldTimeToStartRace()
{
}

void AFortAthenaMutator_BallerRace::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaMutator_BallerRace, ServerWorldTimeToStartRace);
}
