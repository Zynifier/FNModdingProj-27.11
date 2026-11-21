// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "OnlineLinkId.h"
#include "PhaseCommitEnums.h"
#include "FortMatchmakingGroupData.generated.h"

UENUM()
enum class EMatchmakingReadyCheck : uint8
{
	NotReady = 0,
	Default = 1,
	SaveTheWorld = 2,
	LinkCode = 3,
	JoinEditingSession = 4,
	MAX_NUM = 5,
};

UENUM()
enum class EMatchmakingUtilityFlows : uint8
{
	Automatic = 0,
	JoinMatchInProgress = 1,
	SpectateMatch = 2,
	Legacy = 3,
	LinkCode = 4,
	JoinEditingSession = 5,
	SaveTheWorld = 6,
	Internal_Unselected = 7,
};

USTRUCT()
struct FFortCommonMatchmakingData_State
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FOnlineLinkId LinkId;

	UPROPERTY()
	EMatchmakingReadyCheck MatchmakingTransaction;

	UPROPERTY()
	FUniqueNetIdRepl Requester;

	UPROPERTY()
	uint32 Version;

};

USTRUCT()
struct FFortCommonMatchmakingData_DataForParticipant
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FFortCommonMatchmakingData_State Requested;

	UPROPERTY()
	ECoordinatorBroadcasts Broadcast;

	UPROPERTY()
	uint32 Version;

};

USTRUCT()
struct FFortCommonMatchmakingData_Coordinator
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FFortCommonMatchmakingData_State Current;

	UPROPERTY()
	EPhaseCommit PhaseUsedForCommit;

	UPROPERTY()
	FFortCommonMatchmakingData_DataForParticipant ParticipantData;

};

USTRUCT()
struct FFortCommonMatchmakingData_Participant
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FFortCommonMatchmakingData_State Request;

	UPROPERTY()
	EParticipantResponses Response;

	UPROPERTY()
	uint32 Version;

};

