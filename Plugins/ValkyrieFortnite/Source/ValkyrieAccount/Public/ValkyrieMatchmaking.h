// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Online/FortMatchmakingV2Types.h"
#include "ValkyrieMatchmaking.generated.h"

UCLASS(Config=Game)
class VALKYRIEACCOUNT_API UValkyrieMatchmaking : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY(Config)
	FString MMSVersionCompatability;

	UPROPERTY(Config)
	FString MMSTicketURLClient;

	UPROPERTY(Config)
	float MMSPingInterval;

	UPROPERTY(Config)
	uint32 MaxMatchmakingRetries;

	UPROPERTY(Config)
	TArray<FMMSAltDomainRecord> AltDomainRecords;

	UPROPERTY(Config)
	float MatchmakingRetryInterval;

};

