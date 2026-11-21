// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "SpectatorBeaconClient.h"
#include "SpectatorBeaconState.h"
#include "FortSpectatorBeaconClient.generated.h"

UCLASS()
class AFortSpectatorBeaconClient : public ASpectatorBeaconClient
{
	GENERATED_BODY()

public:
	UFUNCTION(Client, Reliable)
	void ClientAbandonResponse(ESpectatorReservationResult::Type ReservationResponse);

	UFUNCTION(Client, Reliable)
	void ClientAllowedToProceedFromReservation();

	UFUNCTION(Client, Reliable)
	void ClientAllowedToProceedFromReservationTimeout();

	UFUNCTION(Client, Reliable)
	void ClientReconnectResponse(ESpectatorReservationResult::Type ReservationResponse);

protected:
	UFUNCTION(Server, Reliable, WithValidation)
	void ServerAbandonExistingReservation(const FString& InSessionId, FUniqueNetIdRepl RequestingPlayer);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerReconnectExistingReservation(const FString& InSessionId, FUniqueNetIdRepl RequestingPlayer);

	UPROPERTY(Config)
	float ReconnectionInitialTimeout;

	UPROPERTY(Config)
	float ReconnectionTimeout;

	UPROPERTY()
	bool bHasReconnected;

};

