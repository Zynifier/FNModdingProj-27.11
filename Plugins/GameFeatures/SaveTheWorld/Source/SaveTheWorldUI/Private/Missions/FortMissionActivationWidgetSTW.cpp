// Copyright Epic Games, Inc. All Rights Reserved.

#include "Missions/FortMissionActivationWidgetSTW.h"

bool UFortMissionActivationInfoSTW::CanRequestVote(EFortVoteType VoteType) const
{
	return false;
}

bool UFortMissionActivationInfoSTW::DoesPrimaryMissionContainTags(const FGameplayTagContainer& Tags) const
{
	return false;
}

EFortVoteArbitratorType UFortMissionActivationInfoSTW::GetArbitratorType(EFortVoteType VoteType)
{
	return EFortVoteArbitratorType();
}

int32 UFortMissionActivationInfoSTW::GetAvailableBluGloCount() const
{
	return int32();
}

void UFortMissionActivationInfoSTW::GetDeltaRewards(int32 BaseDifficultyIncreaseTier, int32 ComparedDifficultyIncreaseTier, TArray<FFortItemDelta>& DeltaRewards) const
{
}

int32 UFortMissionActivationInfoSTW::GetIncreaseDifficultyBluGloRequirement() const
{
	return int32();
}

FUniqueNetIdRepl UFortMissionActivationInfoSTW::GetInstigatorId(EFortVoteType VoteType) const
{
	return FUniqueNetIdRepl();
}

FText UFortMissionActivationInfoSTW::GetLockoutTimeRemaining(EFortVoteType VoteType) const
{
	return FText();
}

float UFortMissionActivationInfoSTW::GetMissionObjectiveTimeRemaining() const
{
	return float();
}

EFortVoteType UFortMissionActivationInfoSTW::GetMissionVoteType() const
{
	return EFortVoteType();
}

AFortMission* UFortMissionActivationInfoSTW::GetPrimaryMission() const
{
	return nullptr;
}

UFortMissionInfo* UFortMissionActivationInfoSTW::GetPrimaryMissionInfo() const
{
	return nullptr;
}

int32 UFortMissionActivationInfoSTW::GetStartObjectiveBluGloRequirement() const
{
	return int32();
}

void UFortMissionActivationInfoSTW::GetVoteCounts(EFortVoteType VoteType, int32& OutYesVoteCount, int32& OutNoVoteCount)
{
}

TArray<FVoter> UFortMissionActivationInfoSTW::GetVoters(EFortVoteType VoteType)
{
	return TArray<FVoter>();
}

float UFortMissionActivationInfoSTW::GetVoteTimeRemaining(EFortVoteType VoteType) const
{
	return float();
}

void UFortMissionActivationInfoSTW::HandleGameplayVoteUpdated(EFortVoteType VoteType, EFortVoteStatus VoteStatus, int32 VoteResult, const TArray<FVoter>& Voters)
{
}

void UFortMissionActivationInfoSTW::HandleTeamMemberAdded(FFortTeamMemberInfo NewInfo)
{
}

void UFortMissionActivationInfoSTW::HandleTeamMemberRemoved(int32 RemovedIndex)
{
}

bool UFortMissionActivationInfoSTW::HasPlayerVoted(EFortVoteType VoteType)
{
	return false;
}

bool UFortMissionActivationInfoSTW::IsAnyVoteActive() const
{
	return false;
}

bool UFortMissionActivationInfoSTW::IsPlayerVoteInstigator(EFortVoteType VoteType) const
{
	return false;
}

bool UFortMissionActivationInfoSTW::IsVoteActive(EFortVoteType VoteType) const
{
	return false;
}

bool UFortMissionActivationInfoSTW::IsVoteLocked(EFortVoteType VoteType) const
{
	return false;
}

void UFortMissionActivationInfoSTW::RequestVote(EFortVoteType VoteType, float VoteDuration, float FailedVoteLockoutDuration, EFortVoteArbitratorType ArbitratorType)
{
}

void UFortMissionActivationInfoSTW::SubmitVote(EFortVoteType VoteType, bool bApprove)
{
}

FText UFortMissionActivationInfoSTW::TimeSecondsToText(float InSeconds) const
{
	return FText();
}

EFortMissionActivationWidgetSTWState UFortMissionActivationWidgetSTW::GetCurrentState() const
{
	return EFortMissionActivationWidgetSTWState();
}

void UFortMissionActivationWidgetSTW::RequestDefaultState()
{
}

void UFortMissionActivationWidgetSTW::RequestDifficultyIncreaseState()
{
}

void UFortMissionActivationWidgetSTW::RequestStartObjectiveState()
{
}

void UFortMissionActivationWidgetSTWPanel::SetInfoObject(UFortMissionActivationInfoSTW* NewInfoObject)
{
}
