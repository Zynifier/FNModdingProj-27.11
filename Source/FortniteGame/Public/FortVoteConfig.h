// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortVoteConfig.generated.h"

UENUM(BlueprintType)
enum class EFortVoteArbitratorType : uint8
{
	Invalid = 0,
	// Majority of voters need to be in agreement

	Majority = 1,
	// All voters need to be in agreement

	Unanimous = 2,
};

UENUM(BlueprintType)
enum class EFortVoteStatus : uint8
{
	Begin = 0,
	Update = 1,
	End = 2,
	BeginLockout = 3,
	EndLockout = 4,
};

UENUM(BlueprintType)
enum class EFortVoteType : uint8
{
	SurvivalVote = 0,
	DifficultyIncrease = 1,
	MissionActivation = 2,
	ContinueOrExtract = 3,
};

USTRUCT(BlueprintType)
struct FFortVoteConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="VoteConfig")
	int32 NumVoteOptions;

	UPROPERTY(BlueprintReadWrite, Category="VoteConfig")
	float VoteDuration;

	UPROPERTY(BlueprintReadWrite, Category="VoteConfig")
	float FailedVoteLockOutDuration;

	UPROPERTY(BlueprintReadWrite, Category="VoteConfig")
	int32 MaxVotesAllowedPerPlayer;

	UPROPERTY(BlueprintReadWrite, Category="VoteConfig")
	EFortVoteArbitratorType VoteArbitratorType;

};

