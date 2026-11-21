// Copyright Epic Games, Inc. All Rights Reserved.

#include "STW/Online/FortLobbyBeaconStateRM.h"
#include "Net/UnrealNetwork.h"

void AFortLobbyBeaconStateRM::OnRep_LobbyTimeRemaining()
{
}

void AFortLobbyBeaconStateRM::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortLobbyBeaconStateRM, LobbyTimeRemaining);
}
