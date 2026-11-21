// Copyright Epic Games, Inc. All Rights Reserved.

#include "Spectator/FortBroadcastSpectatorInfo.h"
#include "Net/UnrealNetwork.h"

void AFortBroadcastSpectatorInfo::HandleTeamInfosSet()
{
}

void AFortBroadcastSpectatorInfo::OnRep_PerPlayerInfo()
{
}

void AFortBroadcastSpectatorInfo::OnRep_TotalNumPlayers()
{
}

void AFortBroadcastSpectatorInfo::OnRep_TotalNumTeams()
{
}

void AFortBroadcastSpectatorInfo::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortBroadcastSpectatorInfo, TotalNumPlayers);
	DOREPLIFETIME(AFortBroadcastSpectatorInfo, TotalNumTeams);
	DOREPLIFETIME(AFortBroadcastSpectatorInfo, TeamPrivateInfos);
	DOREPLIFETIME(AFortBroadcastSpectatorInfo, PerPlayerInfo);
}
