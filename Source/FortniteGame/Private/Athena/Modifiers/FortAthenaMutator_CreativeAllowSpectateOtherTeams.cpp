// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Modifiers/FortAthenaMutator_CreativeAllowSpectateOtherTeams.h"
#include "Net/UnrealNetwork.h"

void AFortAthenaMutator_CreativeAllowSpectateOtherTeams::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaMutator_CreativeAllowSpectateOtherTeams, AllowSpectateOtherTeams);
}
