// Copyright Epic Games, Inc. All Rights Reserved.

#include "Online/FortLobbyBeaconState.h"
#include "Net/UnrealNetwork.h"

void AFortLobbyBeaconState::OnRep_MissionGeneratorClassPath()
{
}

void AFortLobbyBeaconState::OnRep_MissionGeneratorDetailsRequirement()
{
}

void AFortLobbyBeaconState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortLobbyBeaconState, MatchmakingLevel);
	DOREPLIFETIME(AFortLobbyBeaconState, MissionGeneratorClassPath);
	DOREPLIFETIME(AFortLobbyBeaconState, MissionGeneratorDetailsRequirement);
}
