// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Modifiers/FortAthenaMutator_TeamPlacement.h"
#include "Net/UnrealNetwork.h"

void AFortAthenaMutator_TeamPlacement::OnRep_TeamsInfo()
{
}

void AFortAthenaMutator_TeamPlacement::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaMutator_TeamPlacement, TeamsInfo);
}
