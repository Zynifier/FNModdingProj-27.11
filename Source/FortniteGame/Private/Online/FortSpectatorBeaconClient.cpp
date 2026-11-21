// Copyright Epic Games, Inc. All Rights Reserved.

#include "Online/FortSpectatorBeaconClient.h"

void AFortSpectatorBeaconClient::ClientAbandonResponse_Implementation(ESpectatorReservationResult::Type ReservationResponse)
{
}

void AFortSpectatorBeaconClient::ClientAllowedToProceedFromReservation_Implementation()
{
}

void AFortSpectatorBeaconClient::ClientAllowedToProceedFromReservationTimeout_Implementation()
{
}

void AFortSpectatorBeaconClient::ClientReconnectResponse_Implementation(ESpectatorReservationResult::Type ReservationResponse)
{
}

void AFortSpectatorBeaconClient::ServerAbandonExistingReservation_Implementation(const FString& InSessionId, FUniqueNetIdRepl RequestingPlayer)
{
}
bool AFortSpectatorBeaconClient::ServerAbandonExistingReservation_Validate(const FString& InSessionId, FUniqueNetIdRepl RequestingPlayer)
{
	return true;
}

void AFortSpectatorBeaconClient::ServerReconnectExistingReservation_Implementation(const FString& InSessionId, FUniqueNetIdRepl RequestingPlayer)
{
}
bool AFortSpectatorBeaconClient::ServerReconnectExistingReservation_Validate(const FString& InSessionId, FUniqueNetIdRepl RequestingPlayer)
{
	return true;
}
