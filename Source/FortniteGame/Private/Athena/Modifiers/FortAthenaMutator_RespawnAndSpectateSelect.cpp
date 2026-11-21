// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Modifiers/FortAthenaMutator_RespawnAndSpectateSelect.h"
#include "Net/UnrealNetwork.h"

const bool AFortAthenaMutator_RespawnAndSpectateSelect::GetCanPlayerSelectRespawnTargetBeforeTheyCanRespawn() const
{
	return bool();
}

void AFortAthenaMutator_RespawnAndSpectateSelect::OnRep_ManagerObject()
{
}

void AFortAthenaMutator_RespawnAndSpectateSelect::OnRep_RespawnTargetDataArray()
{
}

void AFortAthenaMutator_RespawnAndSpectateSelect::OnSafeZoneStateChanged(EFortSafeZoneState InSafeZoneState)
{
}

void AFortAthenaMutator_RespawnAndSpectateSelect::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaMutator_RespawnAndSpectateSelect, RespawnTargetDataArray);
	DOREPLIFETIME(AFortAthenaMutator_RespawnAndSpectateSelect, bAreAllRespawnTargetsAvailableToAllPlayersCheat);
	DOREPLIFETIME(AFortAthenaMutator_RespawnAndSpectateSelect, ManagerObject);
}

void UFortCheatManager_RespawnAndSpectateSelect::RespawnScreenToggleMakeAllRespawnTargetsAvailableToAllPlayers()
{
}
