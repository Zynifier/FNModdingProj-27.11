// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Online/FortMatchmakingV2Types.h"
#include "FortMatchmakingV2.generated.h"

UCLASS(Config=Game, MinimalAPI)
class UFortMatchmakingV2 : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	static float GetMatchmakingAttemptThrottleTime();

private:
	UPROPERTY(Config)
	FString MMSVersionCompatability;

	UPROPERTY(Config)
	FString MMSTicketURLClient;

	UPROPERTY(Config)
	float MMSPingInterval;

	UPROPERTY(Config)
	bool bCustomKeyEnabled;

	UPROPERTY(Config)
	float UpdateCheckInterval;

	UPROPERTY(Config)
	bool bEnablePrivateMatchUpdateCheck;

	UPROPERTY(Config)
	bool bUpdateLinkCodeHistory;

	UPROPERTY(Config)
	float MatchmakingRetryInterval;

	UPROPERTY(Config)
	uint32 MaxMatchmakingRetries;

	UPROPERTY(Config)
	TArray<FMMSAltDomainRecord> AltDomainRecords;

	UPROPERTY(Config)
	float LogSubmitChance;

	UPROPERTY(Config)
	bool bSubmitSecondaryLogs;

	UPROPERTY(Config)
	int32 LogTailKb;

	UPROPERTY(Config)
	TArray<FString> DisabledMatchmakingRegions;

	UPROPERTY(Config)
	TArray<FName> WhitelistedPlaylistsForActiveCheck;

	UPROPERTY(Config)
	bool bUseHotfixVersionForPlaylistRevision;

	UPROPERTY(Config)
	bool bGenerateSessionTokensFailOpen;

	UPROPERTY(Config)
	bool bServerTravelAnalytics;

};

