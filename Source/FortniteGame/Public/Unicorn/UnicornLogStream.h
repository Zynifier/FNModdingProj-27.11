// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "Unicorn/UnicornTypes.h"
#include "UnicornLogStream.generated.h"

USTRUCT()
struct FGameLogPlayerSampleBase
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FUniqueNetIdRepl PlayerId;

};

USTRUCT()
struct FGameLogBuildSample : public FGameLogPlayerSampleBase
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FBuildEvent TheSample;

};

USTRUCT()
struct FGameLogDancePartySample : public FGameLogPlayerSampleBase
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FPlayerDancePartySample TheSample;

};

USTRUCT()
struct FGameLogPawnSample : public FGameLogPlayerSampleBase
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FPawnSample TheSample;

};

USTRUCT()
struct FGameLogPlayerMetaSample : public FGameLogPlayerSampleBase
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FPlayerMetaInfo TheSample;

};

USTRUCT()
struct FGameLogStream
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FDeathEvent> DeathEvents;

	UPROPERTY()
	TArray<FGameLogPawnSample> PawnSamples;

	UPROPERTY()
	TArray<FGameLogBuildSample> BuildEvents;

	UPROPERTY()
	TArray<FStormSample> StormSamples;

	UPROPERTY()
	TArray<FGameLogPlayerMetaSample> PlayerMetaInfoSamples;

	UPROPERTY()
	TArray<FGameLogDancePartySample> PlayerDancePartySamples;

};

