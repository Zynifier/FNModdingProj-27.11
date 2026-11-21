// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Modifiers/FortAthenaMutator_Payback.h"
#include "Net/UnrealNetwork.h"

void AFortAthenaMutator_Payback::GetAllPlayersMarkedForPayback(TArray<AFortPlayerStateAthena*>& OutPlayerStates) const
{
}

float AFortAthenaMutator_Payback::GetHighestPaybackTimeRemaining(const APlayerState* KillerPlayerState) const
{
	return float();
}

void AFortAthenaMutator_Payback::GetPaybackTeams(TArray<uint8>& OutTeams, const APlayerState* PlayerState) const
{
}

float AFortAthenaMutator_Payback::GetPaybackTimeRemaining(const APlayerState* KillerPlayerState, const uint8 VictimTeam) const
{
	return float();
}

void AFortAthenaMutator_Payback::GetPlayersToPayBack(TArray<AFortPlayerStateAthena*>& OutPlayerStatesToPayBack, const APlayerState* AttackerPlayerState) const
{
}

void AFortAthenaMutator_Payback::GetTeamPlayersMarkedForPayback(TArray<AFortPlayerStateAthena*>& OutPlayerStates, const uint8 Team) const
{
}

bool AFortAthenaMutator_Payback::IsMarkedForPayback(const APlayerState* PlayerState) const
{
	return false;
}

bool AFortAthenaMutator_Payback::IsMarkedForPaybackByTeam(const APlayerState* PlayerState, const uint8 Team) const
{
	return false;
}

void AFortAthenaMutator_Payback::NetMulticast_OnPaybackKill_Implementation(AFortPlayerStateAthena* KillerPlayerState, AFortPlayerStateAthena* VictimPlayerState)
{
}

void AFortAthenaMutator_Payback::OnDeadStateChanged(AFortPlayerStateAthena* VictimPlayerState, bool bDead)
{
}

void AFortAthenaMutator_Payback::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaMutator_Payback, PaybackEffectDataArray);
}

void UFortCheatManager_Payback::PaybackDebug(float TextScale)
{
}
