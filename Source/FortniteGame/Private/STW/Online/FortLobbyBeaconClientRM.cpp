// Copyright Epic Games, Inc. All Rights Reserved.

#include "STW/Online/FortLobbyBeaconClientRM.h"

void AFortLobbyBeaconClientRM::ClientBroadcastLobbyPlayerPadTop_Implementation(const FUniqueNetIdRepl& ReadiedPlayer, bool bIsReadiedUp) const
{
}

void AFortLobbyBeaconClientRM::ServerUpdateNewlyJoinedPlayerInternal_Implementation()
{
}
bool AFortLobbyBeaconClientRM::ServerUpdateNewlyJoinedPlayerInternal_Validate()
{
	return true;
}

void AFortLobbyBeaconClientRM::ServerUpdateReadyStatus_Implementation(bool bIsReady)
{
}
bool AFortLobbyBeaconClientRM::ServerUpdateReadyStatus_Validate(bool bIsReady)
{
	return true;
}

void AFortLobbyBeaconClientRM::SetLocalReadyStatus(bool bIsReady)
{
}

void AFortLobbyBeaconClientRM::UpdateNewlyJoinedPlayer()
{
}
