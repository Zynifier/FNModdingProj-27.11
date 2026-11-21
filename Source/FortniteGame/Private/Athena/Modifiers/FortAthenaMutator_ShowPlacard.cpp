// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Modifiers/FortAthenaMutator_ShowPlacard.h"
#include "Net/UnrealNetwork.h"

void AFortAthenaMutator_ShowPlacard::OnRep_ShowPlacardPhase()
{
}

void AFortAthenaMutator_ShowPlacard::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaMutator_ShowPlacard, ShowPlacardPhase);
}
