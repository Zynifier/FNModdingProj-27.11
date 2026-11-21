// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "PartyBeaconClient.h"
#include "PartyBeaconState.h"
#include "Online/FortPartyBeaconState.h"
#include "FortPartyBeaconClient.generated.h"

enum class EServerInitializationState : uint8;

UCLASS()
class AFortPartyBeaconClient : public APartyBeaconClient
{
	GENERATED_BODY()

public:
	UFUNCTION(Client, Reliable)
	void ClientAbandonResponse(EPartyReservationResult::Type ReservationResponse);

	UFUNCTION(Client, Reliable)
	void ClientAllowedToProceedFromReservation();

	UFUNCTION(Client, Reliable)
	void ClientAllowedToProceedFromReservationTimeout();

	UFUNCTION(Client, Reliable)
	void ClientNotifyServerReadinessChanged(EServerInitializationState NewServerState);

	UFUNCTION(Client, Reliable)
	void ClientReconnectResponse(EPartyReservationResult::Type ReservationResponse);

protected:
	UFUNCTION(Server, Reliable, WithValidation)
	void ServerAbandonExistingReservation(const FString& InSessionId, FUniqueNetIdRepl RequestingPlayer);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerEmptyServerReservationRequest(const FString& InSessionId, const FEmptyServerReservation ReservationData, FPartyReservation Reservation);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerReconnectExistingReservation(const FString& InSessionId, FUniqueNetIdRepl RequestingPlayer);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerRequestInitializationState();

	UPROPERTY()
	FEmptyServerReservation PendingEmptyReservation;

	UPROPERTY(Config)
	float ReconnectionInitialTimeout;

	UPROPERTY(Config)
	float ReconnectionTimeout;

	UPROPERTY()
	bool bHasReconnected;

};

