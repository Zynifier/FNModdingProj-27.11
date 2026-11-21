// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Online/FortMatchmakingPolicy.h"
#include "FortMatchmaking.generated.h"

class AFortLobbyBeaconClient;
class AFortPartyBeaconClient;
class APartyBeaconClient;
class UFortMatchmakingPolicy;

UENUM()
enum class EFortMatchmakingType : uint8
{
	// Normal matchmaking

	Gathering = 0,
	// Search for anyone, sorted by player rating

	CriticalMission = 1,
	// Search for anyone, sorted by zone difficulty

	QuickPlay = 2,
	// Currently unused

	Session = 3,
};

USTRUCT()
struct FFortCachedMatchmakingSearchParams
{
	GENERATED_BODY()

private:
	UPROPERTY()
	EFortMatchmakingType MatchmakingType;

	UPROPERTY()
	FMatchmakingParams MatchmakingParams;

	UPROPERTY()
	bool bValid;

};

UCLASS(Config=Game)
class UFortMatchmaking : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TSubclassOf<APartyBeaconClient> ReservationBeaconClientClass;

	UPROPERTY(Transient)
	TObjectPtr<AFortPartyBeaconClient> ReservationBeaconClient;

	UPROPERTY(Transient)
	TObjectPtr<AFortLobbyBeaconClient> LobbyBeaconClient;

	UPROPERTY()
	int32 ControllerId;

	UPROPERTY()
	FString TempZoneInstanceId;

	UPROPERTY()
	FFortCachedMatchmakingSearchParams CachedMatchmakingSearchParams;

	UPROPERTY()
	TObjectPtr<UFortMatchmakingPolicy> Matchmaking;

	UPROPERTY()
	FString LastCriticalMissionSessionId;

	UPROPERTY()
	EFortMatchmakingPrivacyConfiguration LastMatchmakingPrivacyConfiguration;

	UPROPERTY(Config)
	bool bUpdateLinkCodeHistory;

};

