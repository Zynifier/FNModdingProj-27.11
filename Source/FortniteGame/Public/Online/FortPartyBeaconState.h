// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "PartyBeaconState.h"
#include "Online/FortMatchmakingPolicy.h"
#include "FortPartyBeaconState.generated.h"

USTRUCT()
struct FEmptyServerReservation
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 PlaylistId;

	UPROPERTY()
	FString ZoneInstanceId;

	UPROPERTY()
	FString WUID;

	UPROPERTY()
	FUniqueNetIdRepl WorldDataOwner;

	UPROPERTY()
	bool bMakePrivate;

	UPROPERTY()
	EFortMatchmakingPool MatchmakingPool;

	UPROPERTY()
	bool bUsesMatchmakingV2;

};

UCLASS()
class UFortPartyBeaconState : public UPartyBeaconState
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	FUniqueNetIdRepl GameSessionOwner;

	UPROPERTY()
	FEmptyServerReservation ReservationData;

};

