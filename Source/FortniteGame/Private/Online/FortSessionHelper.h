// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PartyBeaconState.h"
#include "UObject/NoExportTypes.h"
#include "Online/FortMatchmakingEnums.h"
#include "FortSessionHelper.generated.h"

class AFortPartyBeaconClient;
class UObject;

UENUM()
namespace EFortSessionHelperJoinState
{
	enum Type
	{
		/** Not in any attempt (not started) */
		NotJoining = 0,
		/** Testing the search result for joinability */
		RequestingReservation = 1,
		/** Failed the reservation request for some reason (end of state machine) */
		FailedReservation = 2,
		/** Notified the game of the reservation result, waiting for cleanup and continue */
		WaitingOnGame = 3,
		/** Attempting to join the session */
		AttemptingJoin = 4,
		/** In process of joining a session (end of state machine) */
		JoiningSession = 5,
		/** Failed to join a session for some reason (end of state machine) */
		FailedJoin = 6,
		/** Canceled while we are attempting to join the reserved session */
		CanceledJoin = 7,
	};
}

UCLASS()
class UFortSessionHelper : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TSubclassOf<UObject> BeaconClientClass;

	UPROPERTY(Transient)
	TObjectPtr<AFortPartyBeaconClient> PartyBeaconClient;

	UPROPERTY(Transient)
	FName CurrentSessionName;

	UPROPERTY(Transient)
	TEnumAsByte<EPartyReservationResult::Type> LastBeaconResponse;

	UPROPERTY(Transient)
	TEnumAsByte<EFortSessionHelperJoinState::Type> CurrentJoinState;

	UPROPERTY(Transient)
	EFortSessionHelperJoinResult CurrentJoinResult;

};

