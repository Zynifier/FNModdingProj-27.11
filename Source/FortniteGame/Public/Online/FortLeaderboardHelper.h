// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "FortLeaderboardHelper.generated.h"

USTRUCT(BlueprintType)
struct FMcpLeaderboardResultRow
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="McpLeaderboardResultRow")
	FUniqueNetIdRepl PlayerUniqueNetId;

	UPROPERTY(BlueprintReadOnly, Category="McpLeaderboardResultRow")
	int32 Rank;

	UPROPERTY(BlueprintReadOnly, Category="McpLeaderboardResultRow")
	int32 Value;

};

