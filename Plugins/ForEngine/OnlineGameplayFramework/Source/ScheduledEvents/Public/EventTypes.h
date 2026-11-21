// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "JsonObjectWrapper.h"
#include "Misc/DateTime.h"
#include "EventTypes.generated.h"

USTRUCT()
struct FEventRecord
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString EventType;

	UPROPERTY()
	FDateTime ActiveUntil;

	UPROPERTY()
	FDateTime ActiveSince;

};

USTRUCT()
struct FEventChannelState
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FDateTime ValidFrom;

	UPROPERTY()
	TArray<FEventRecord> ActiveEvents;

	UPROPERTY()
	FJsonObjectWrapper State;

};

USTRUCT()
struct FEventsTimeline
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FDateTime CacheExpire;

	UPROPERTY()
	TArray<FEventChannelState> States;

};

USTRUCT()
struct FCalendarDownload
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FDateTime CurrentTime;

	UPROPERTY()
	double CacheIntervalMins;

	UPROPERTY()
	TMap<FString, FEventsTimeline> Channels;

};

