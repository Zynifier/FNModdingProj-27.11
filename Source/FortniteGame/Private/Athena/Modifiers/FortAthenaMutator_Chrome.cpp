// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Modifiers/FortAthenaMutator_Chrome.h"
#include "Net/UnrealNetwork.h"

void AFortAthenaMutator_Chrome::HandleTeleportComplete()
{
}

void AFortAthenaMutator_Chrome::OnRep_FinishTraversePoint()
{
}

void AFortAthenaMutator_Chrome::OnRep_RaceStarted()
{
}

void AFortAthenaMutator_Chrome::OnTraversePointTouched(AAthenaTraversePoint* PointActor, AFortPlayerStateAthena* TouchingPlayer)
{
}

void AFortAthenaMutator_Chrome::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaMutator_Chrome, FinishTraversePoint);
	DOREPLIFETIME(AFortAthenaMutator_Chrome, bRaceStarted);
}
