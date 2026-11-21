// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "OnlineLinkId.h"
#include "MatchmakingTypes.generated.h"

UENUM()
enum class EIslandJoinability : int32
{
	CanNotBeJoinedOrWatched = 0,
	Joinable = 1,
	Watchable = 2,
};

USTRUCT()
struct FIslandJoinInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	EIslandJoinability IslandJoinability;

	UPROPERTY()
	FString SessionKey;

};

USTRUCT()
struct FIslandRepData
{
	GENERATED_BODY()

private:
	UPROPERTY()
	FOnlineLinkId LinkId;

	UPROPERTY()
	FString SessionId;

	UPROPERTY()
	FIslandJoinInfo JoinInfo;

};

