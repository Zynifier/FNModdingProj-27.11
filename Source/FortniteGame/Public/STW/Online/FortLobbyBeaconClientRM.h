// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "Online/FortLobbyBeaconClient.h"
#include "FortLobbyBeaconClientRM.generated.h"

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnReadiedUpStatusChanged, bool, bReadiedUp);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnUpdateLobbyPlayerPadTop, FUniqueNetIdRepl, PlayerNetId, bool, bIsReady);

UCLASS()
class AFortLobbyBeaconClientRM : public AFortLobbyBeaconClient
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="RestrictedMatchmaking")
	void SetLocalReadyStatus(bool bIsReady);

protected:
	UFUNCTION(Client, Reliable)
	void ClientBroadcastLobbyPlayerPadTop(const FUniqueNetIdRepl& ReadiedPlayer, bool bIsReadiedUp) const;

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerUpdateNewlyJoinedPlayerInternal();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerUpdateReadyStatus(bool bIsReady);

	UFUNCTION(BlueprintCallable)
	void UpdateNewlyJoinedPlayer();

private:
	UPROPERTY(BlueprintAssignable, Category="RestrictedMatchmaking", meta=(AllowPrivateAccess="true"))
	FOnReadiedUpStatusChanged LocalReadiedUpStatusChanged;

	UPROPERTY(BlueprintAssignable, Category="RestrictedMatchmaking", meta=(AllowPrivateAccess="true"))
	FOnUpdateLobbyPlayerPadTop OnUpdateLobbyPlayerPadTop;

};

