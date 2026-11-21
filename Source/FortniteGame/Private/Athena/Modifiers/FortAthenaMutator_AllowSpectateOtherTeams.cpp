// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Modifiers/FortAthenaMutator_AllowSpectateOtherTeams.h"
#include "Net/UnrealNetwork.h"

void AFortAthenaMutator_AllowSpectateOtherTeams::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaMutator_AllowSpectateOtherTeams, bAllowSpectateOtherTeams);
}
