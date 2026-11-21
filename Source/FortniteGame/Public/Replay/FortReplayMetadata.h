// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "Math/MathFwd.h"
#include "Athena/FortGameStateAthena.h"
#include "AthenaPlayerMatchReport.h"
#include "FortDeathCauseEnum.h"
#include "FortReplayMetadata.generated.h"

USTRUCT()
struct FGameStateInformation
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FGameMemberInfoArray PlayerInfos;

	UPROPERTY()
	bool bIsTeamBasedGame;

};

USTRUCT()
struct FReplayKillSummary
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FUniqueNetIdRepl Victim;

	UPROPERTY()
	FTransform VictimLocation;

	UPROPERTY()
	FUniqueNetIdRepl Instigator;

	UPROPERTY()
	FTransform InstigatorLocation;

	UPROPERTY()
	float TimeStamp;

	UPROPERTY()
	bool bIsDownButNotOut;

	UPROPERTY()
	EDeathCause DeathCause;

};

USTRUCT()
struct FFortReplayMetadata
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString ReplayName;

	UPROPERTY()
	FString PlaylistName;

	UPROPERTY()
	float ReplayLength;

	UPROPERTY()
	FUniqueNetIdRepl RecordingPlayer;

	UPROPERTY()
	TMap<float, FUniqueNetIdRepl> RelevancyList;

	UPROPERTY()
	TMap<FUniqueNetIdRepl, FString> PlayerIds;

	UPROPERTY()
	TMap<FString, FString> PlayerMatchReportToName;

	UPROPERTY()
	TMap<FUniqueNetIdRepl, FString> PlayerIdToMatchReport;

	UPROPERTY()
	TMap<FUniqueNetIdRepl, int32> PlayerIdToWorldIdentifier;

	UPROPERTY()
	TArray<FReplayKillSummary> KillSummaries;

	UPROPERTY()
	TMap<FUniqueNetIdRepl, int32> PlayerFinalRankings;

	UPROPERTY()
	FGameStateInformation GameInformation;

	UPROPERTY()
	TArray<FAthenaTravelLogEntry> WorldLogEntries;

};

