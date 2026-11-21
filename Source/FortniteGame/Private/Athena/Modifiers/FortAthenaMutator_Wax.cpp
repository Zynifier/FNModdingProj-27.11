// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Modifiers/FortAthenaMutator_Wax.h"
#include "Net/UnrealNetwork.h"

void AFortAthenaMutator_Wax::CommonDeadPawn(AFortPlayerPawnAthena* DeadPawn)
{
}

EWaxState AFortAthenaMutator_Wax::GetCurrentWaxState(const AFortPlayerStateAthena* Player) const
{
	return EWaxState();
}

int32 AFortAthenaMutator_Wax::GetPlayerLives(const AFortPlayerStateAthena* Player) const
{
	return int32();
}

int32 AFortAthenaMutator_Wax::GetPlayerPlacement(const AFortPlayerStateAthena* Player) const
{
	return int32();
}

int32 AFortAthenaMutator_Wax::GetPlayerTeamPlacement(const AFortPlayerStateAthena* Player) const
{
	return int32();
}

int32 AFortAthenaMutator_Wax::GetPlayerTeamScore(const AFortPlayerStateAthena* Player) const
{
	return int32();
}

int32 AFortAthenaMutator_Wax::GetTokensForPlayer(const AFortPlayerStateAthena* Player) const
{
	return int32();
}

int32 AFortAthenaMutator_Wax::GetTokensToWinBP() const
{
	return int32();
}

void AFortAthenaMutator_Wax::GetWaxUI_Info(float& MyPercent, float& Enemy1Pct, float& Enemy2Pct, float& Enemy3Pct, int32& MyRank) const
{
}

bool AFortAthenaMutator_Wax::IsPlayerInPodium(const AFortPlayerStateAthena* Player) const
{
	return false;
}

bool AFortAthenaMutator_Wax::IsPlayerMovingOrShooting(const AFortPlayerStateAthena* Player) const
{
	return false;
}

bool AFortAthenaMutator_Wax::IsPlayerTeamLeader(const AFortPlayerStateAthena* Player) const
{
	return false;
}

void AFortAthenaMutator_Wax::OnRep_Leaders()
{
}

void AFortAthenaMutator_Wax::SendTokenStats()
{
}

bool AFortAthenaMutator_Wax::ShouldBeUI_Visible(const AFortPlayerStateAthena* Player) const
{
	return false;
}

void AFortAthenaMutator_Wax::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaMutator_Wax, TeamLeadersInOrder);
	DOREPLIFETIME(AFortAthenaMutator_Wax, PlayerData);
}

void UFortCheatManager_Wax::DisableWaxRespawningLogic()
{
}

void UFortCheatManager_Wax::EnableWaxRespawningLogic()
{
}

void UFortCheatManager_Wax::SetGameScore(int32 CurrentScoreAt)
{
}

void UFortCheatManager_Wax::SetRespawnsRemaining(int32 NumberOfRespawnsRemaining)
{
}

void UFortCheatManager_Wax::SetTargetGoalScore(int32 TargetGoalScore)
{
}
