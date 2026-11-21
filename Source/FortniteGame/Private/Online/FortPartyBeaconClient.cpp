// Copyright Epic Games, Inc. All Rights Reserved.

#include "Online/FortPartyBeaconClient.h"

void AFortPartyBeaconClient::ClientAbandonResponse_Implementation(EPartyReservationResult::Type ReservationResponse)
{
}

void AFortPartyBeaconClient::ClientAllowedToProceedFromReservation_Implementation()
{
}

void AFortPartyBeaconClient::ClientAllowedToProceedFromReservationTimeout_Implementation()
{
}

void AFortPartyBeaconClient::ClientNotifyServerReadinessChanged_Implementation(EServerInitializationState NewServerState)
{
}

void AFortPartyBeaconClient::ClientReconnectResponse_Implementation(EPartyReservationResult::Type ReservationResponse)
{
}

void AFortPartyBeaconClient::ServerAbandonExistingReservation_Implementation(const FString& InSessionId, FUniqueNetIdRepl RequestingPlayer)
{
}
bool AFortPartyBeaconClient::ServerAbandonExistingReservation_Validate(const FString& InSessionId, FUniqueNetIdRepl RequestingPlayer)
{
	return true;
}

void AFortPartyBeaconClient::ServerEmptyServerReservationRequest_Implementation(const FString& InSessionId, const FEmptyServerReservation ReservationData, FPartyReservation Reservation)
{
}
bool AFortPartyBeaconClient::ServerEmptyServerReservationRequest_Validate(const FString& InSessionId, const FEmptyServerReservation ReservationData, FPartyReservation Reservation)
{
	return true;
}

void AFortPartyBeaconClient::ServerReconnectExistingReservation_Implementation(const FString& InSessionId, FUniqueNetIdRepl RequestingPlayer)
{
}
bool AFortPartyBeaconClient::ServerReconnectExistingReservation_Validate(const FString& InSessionId, FUniqueNetIdRepl RequestingPlayer)
{
	return true;
}

void AFortPartyBeaconClient::ServerRequestInitializationState_Implementation()
{
}
bool AFortPartyBeaconClient::ServerRequestInitializationState_Validate()
{
	return true;
}
