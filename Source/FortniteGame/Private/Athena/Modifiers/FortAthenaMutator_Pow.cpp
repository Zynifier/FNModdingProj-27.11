// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Modifiers/FortAthenaMutator_Pow.h"
#include "Net/UnrealNetwork.h"

float AFortAthenaMutator_Pow::GetPlayerCurrentShield(AFortPlayerStateAthena* Player) const
{
	return float();
}

void AFortAthenaMutator_Pow::OnRep_RespawningCurrentlyAllowed()
{
}

void AFortAthenaMutator_Pow::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaMutator_Pow, PlayerData);
	DOREPLIFETIME(AFortAthenaMutator_Pow, bRespawningCurrentlyAllowed);
}
