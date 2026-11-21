// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "OnlineLinkId.h"
#include "PhaseCommitEnums.h"
#include "FortMatchmakingGroupMemberData.generated.h"

UENUM(BlueprintType)
enum class EGameReadiness : uint8
{
	NotReady = 0,
	Ready = 1,
	Reevaluating = 2,
	// Player was ready, but now needs to figure out if they should set to ready or not ready

	SittingOut = 3,
};

UENUM()
enum class EInGameLinkType : uint8
{
	BattleRoyale = 0,
	CreativeIsland = 1,
	Competitive = 2,
	UEFN = 3,
	UNDEFINED = 4,
};

USTRUCT()
struct FFortMatchmakingMemberData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FUniqueNetIdRepl Player;

	UPROPERTY()
	EGameReadiness Readiness;

	UPROPERTY()
	FOnlineLinkId CurrentGameId;

	UPROPERTY()
	EInGameLinkType CurrentGameType;

	UPROPERTY()
	FString CurrentGameSessionId;

	UPROPERTY()
	uint32 Version;

};

USTRUCT()
struct FFortMatchmakingMemberData_State
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FFortMatchmakingMemberData> Members;

	UPROPERTY()
	FUniqueNetIdRepl Requester;

	UPROPERTY()
	uint32 Version;

};

USTRUCT()
struct FFortMatchmakingMemberData_DataForParticipant
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FFortMatchmakingMemberData_State Requested;

	UPROPERTY()
	ECoordinatorBroadcasts Broadcast;

	UPROPERTY()
	uint32 Version;

};

USTRUCT()
struct FFortMatchmakingMemberData_Coordinator
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FFortMatchmakingMemberData_State Current;

	UPROPERTY()
	EPhaseCommit PhaseUsedForCommit;

	UPROPERTY()
	FFortMatchmakingMemberData_DataForParticipant ParticipantData;

};

USTRUCT()
struct FFortMatchmakingMemberData_Participant
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FFortMatchmakingMemberData_State Request;

	UPROPERTY()
	EParticipantResponses Response;

	UPROPERTY()
	uint32 Version;

};

