// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AthenaBroadcastKillFeedEntryInfo.generated.h"

UENUM(BlueprintType)
enum class EAthenaBroadcastKillFeedEntryType : uint8
{
	Elimination = 0,
	Storm = 1,
	FallDamage = 2,
	Explosion = 3,
	DBNO = 4,
};

USTRUCT(BlueprintType)
struct FAthenaBroadcastKillFeedEntryInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaBroadcastKillFeedEntryInfo")
	FString InstigatorPlayerName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaBroadcastKillFeedEntryInfo")
	FString VictimPlayerName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaBroadcastKillFeedEntryInfo")
	EAthenaBroadcastKillFeedEntryType EntryType;

};

