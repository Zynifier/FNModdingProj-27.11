// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Modifiers/FortAthenaMutator_Uranium.h"
#include "Net/UnrealNetwork.h"

int32 AFortAthenaMutator_Uranium::GetCurrentRoundCheckPoint() const
{
	return int32();
}

int32 AFortAthenaMutator_Uranium::GetCurrentRoundNumber() const
{
	return int32();
}

AFortPlayerPushableCart* AFortAthenaMutator_Uranium::GetPushCart() const
{
	return nullptr;
}

void AFortAthenaMutator_Uranium::GetRoundTeamWinners(TArray<uint8>& TeamWinnersEachRound)
{
}

const uint8 AFortAthenaMutator_Uranium::GetWinningTeamForRound(int32 RoundNumber) const
{
	return uint8();
}

void AFortAthenaMutator_Uranium::HandleRoundPhase(EUraniumRoundPhase NewRoundPhase)
{
}

void AFortAthenaMutator_Uranium::HandleTeleportComplete()
{
}

void AFortAthenaMutator_Uranium::MulticastSetWinningTeams_Implementation(const TArray<uint8>& InWinningTeams)
{
}

void AFortAthenaMutator_Uranium::OnPlaylistDataLoaded(FName PlaylistName, const FGameplayTagContainer& PlaylistContainerTags)
{
}

void AFortAthenaMutator_Uranium::OnPushCartPushersOrDefendersChanged()
{
}

void AFortAthenaMutator_Uranium::OnPushCartReachedCheckPoint(int32 CheckPointIndex)
{
}

void AFortAthenaMutator_Uranium::OnPushCartTeamsRolesChanged(uint8 NewPusherTeam, uint8 NewDefenerTeam)
{
}

void AFortAthenaMutator_Uranium::OnRep_bInOvertime()
{
}

void AFortAthenaMutator_Uranium::OnRep_CurrentPOI()
{
}

void AFortAthenaMutator_Uranium::OnRep_CurrentRoundPhase()
{
}

void AFortAthenaMutator_Uranium::OnRep_PushCart()
{
}

void AFortAthenaMutator_Uranium::OnRep_RoundData()
{
}

void AFortAthenaMutator_Uranium::OnRep_TeleportComplete()
{
}

void AFortAthenaMutator_Uranium::StartEndOfRoundStasis()
{
}

void AFortAthenaMutator_Uranium::TeleportPlayerLoadComplete(AFortPlayerStateAthena* PlayerState)
{
}

void AFortAthenaMutator_Uranium::TickUraniumEvents()
{
}

void AFortAthenaMutator_Uranium::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaMutator_Uranium, PushCart);
	DOREPLIFETIME(AFortAthenaMutator_Uranium, StormShield);
	DOREPLIFETIME(AFortAthenaMutator_Uranium, RespawnLocation_PusherTeam);
	DOREPLIFETIME(AFortAthenaMutator_Uranium, RespawnLocation_DefenderTeam);
	DOREPLIFETIME(AFortAthenaMutator_Uranium, CurrentPOI);
	DOREPLIFETIME(AFortAthenaMutator_Uranium, RoundData);
	DOREPLIFETIME(AFortAthenaMutator_Uranium, CurrentRoundPhase);
	DOREPLIFETIME(AFortAthenaMutator_Uranium, bRoundTimerStarted);
	DOREPLIFETIME(AFortAthenaMutator_Uranium, PushersAbandonedCartStartTime);
	DOREPLIFETIME(AFortAthenaMutator_Uranium, PushersAbandonedCartDuration);
	DOREPLIFETIME(AFortAthenaMutator_Uranium, bInOvertime);
	DOREPLIFETIME(AFortAthenaMutator_Uranium, bIsSafeToTurnOnCameraAfterRespawn);
	DOREPLIFETIME(AFortAthenaMutator_Uranium, CheckpointTeleportPlayersReleased);
	DOREPLIFETIME(AFortAthenaMutator_Uranium, CheckpointTeleportComplete);
}

void UFortCheatManager_Uranium::DrawUraniumRespawnLocations(bool bDraw)
{
}

void UFortCheatManager_Uranium::SetCartBaseSpeed(float NewBaseSpeed)
{
}

void UFortCheatManager_Uranium::SetCartPushAreaSizeScalar(float PushAreaSizeScalar)
{
}
