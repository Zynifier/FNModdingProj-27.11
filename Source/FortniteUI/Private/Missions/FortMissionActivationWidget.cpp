// Copyright Epic Games, Inc. All Rights Reserved.

#include "Missions/FortMissionActivationWidget.h"

bool UFortMissionActivationInfo::CanRequestVote(EFortVoteType VoteType) const
{
	return false;
}

bool UFortMissionActivationInfo::DoesPrimaryMissionContainTags(const FGameplayTagContainer& Tags) const
{
	return false;
}

EFortVoteArbitratorType UFortMissionActivationInfo::GetArbitratorType(EFortVoteType VoteType)
{
	return EFortVoteArbitratorType();
}

int32 UFortMissionActivationInfo::GetAvailableBluGloCount() const
{
	return int32();
}

void UFortMissionActivationInfo::GetDeltaRewards(int32 BaseDifficultyIncreaseTier, int32 ComparedDifficultyIncreaseTier, TArray<FFortItemDelta>& DeltaRewards) const
{
}

int32 UFortMissionActivationInfo::GetIncreaseDifficultyBluGloRequirement() const
{
	return int32();
}

FUniqueNetIdRepl UFortMissionActivationInfo::GetInstigatorId(EFortVoteType VoteType) const
{
	return FUniqueNetIdRepl();
}

FText UFortMissionActivationInfo::GetLockoutTimeRemaining(EFortVoteType VoteType) const
{
	return FText();
}

float UFortMissionActivationInfo::GetMissionObjectiveTimeRemaining() const
{
	return float();
}

EFortVoteType UFortMissionActivationInfo::GetMissionVoteType() const
{
	return EFortVoteType();
}

AFortMission* UFortMissionActivationInfo::GetPrimaryMission() const
{
	return nullptr;
}

UFortMissionInfo* UFortMissionActivationInfo::GetPrimaryMissionInfo() const
{
	return nullptr;
}

int32 UFortMissionActivationInfo::GetStartObjectiveBluGloRequirement() const
{
	return int32();
}

void UFortMissionActivationInfo::GetVoteCounts(EFortVoteType VoteType, int32& OutYesVoteCount, int32& OutNoVoteCount)
{
}

TArray<FVoter> UFortMissionActivationInfo::GetVoters(EFortVoteType VoteType)
{
	return TArray<FVoter>();
}

float UFortMissionActivationInfo::GetVoteTimeRemaining(EFortVoteType VoteType) const
{
	return float();
}

void UFortMissionActivationInfo::HandleGameplayVoteUpdated(EFortVoteType VoteType, EFortVoteStatus VoteStatus, int32 VoteResult, const TArray<FVoter>& Voters)
{
}

void UFortMissionActivationInfo::HandleTeamMemberAdded(FFortTeamMemberInfo NewInfo)
{
}

void UFortMissionActivationInfo::HandleTeamMemberRemoved(int32 RemovedIndex)
{
}

bool UFortMissionActivationInfo::HasPlayerVoted(EFortVoteType VoteType)
{
	return false;
}

bool UFortMissionActivationInfo::IsAnyVoteActive() const
{
	return false;
}

bool UFortMissionActivationInfo::IsPlayerVoteInstigator(EFortVoteType VoteType) const
{
	return false;
}

bool UFortMissionActivationInfo::IsVoteActive(EFortVoteType VoteType) const
{
	return false;
}

bool UFortMissionActivationInfo::IsVoteLocked(EFortVoteType VoteType) const
{
	return false;
}

void UFortMissionActivationInfo::RequestVote(EFortVoteType VoteType, float VoteDuration, float FailedVoteLockoutDuration, EFortVoteArbitratorType ArbitratorType)
{
}

void UFortMissionActivationInfo::SubmitVote(EFortVoteType VoteType, bool bApprove)
{
}

FText UFortMissionActivationInfo::TimeSecondsToText(float InSeconds) const
{
	return FText();
}

EFortMissionActivationWidgetState UFortMissionActivationWidget::GetCurrentState() const
{
	return EFortMissionActivationWidgetState();
}

void UFortMissionActivationWidget::RequestDefaultState()
{
}

void UFortMissionActivationWidget::RequestDifficultyIncreaseState()
{
}

void UFortMissionActivationWidget::RequestStartObjectiveState()
{
}

void UFortMissionActivationWidgetPanel::SetInfoObject(UFortMissionActivationInfo* NewInfoObject)
{
}
