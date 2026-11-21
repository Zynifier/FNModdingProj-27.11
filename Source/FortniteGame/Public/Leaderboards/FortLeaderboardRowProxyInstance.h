// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "UObject/NoExportTypes.h"
#include "FortLeaderboardRowProxyInstance.generated.h"

USTRUCT(BlueprintType)
struct FLeaderboardRowData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="LeaderboardRowData")
	int32 Rank;

	UPROPERTY(BlueprintReadOnly, Category="LeaderboardRowData")
	FString User;

	UPROPERTY(BlueprintReadOnly, Category="LeaderboardRowData")
	int32 Value;

	UPROPERTY(BlueprintReadOnly, Category="LeaderboardRowData")
	FUniqueNetIdRepl PlatformAccountId;

};

UCLASS(MinimalAPI, BlueprintType)
class UFortLeaderboardRowProxyInstance : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="FortLeaderboardRowProxyInstance")
	FLeaderboardRowData RowData;

};

