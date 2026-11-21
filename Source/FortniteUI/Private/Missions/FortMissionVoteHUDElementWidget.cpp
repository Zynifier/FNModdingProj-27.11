// Copyright Epic Games, Inc. All Rights Reserved.

#include "Missions/FortMissionVoteHUDElementWidget.h"

int32 UFortMissionVoteHUDElementWidget::GetVoteTimeRemaining(EFortVoteType VoteType)
{
	return int32();
}

void UFortMissionVoteHUDElementWidget::HandleDifficultyIncreaseVoteUpdate(EFortVoteType VoteType, EFortVoteStatus VoteStatus, int32 VoteResult, const TArray<FVoter>& Voters)
{
}

void UFortMissionVoteHUDElementWidget::HandleMissionActivationVoteUpdate(EFortVoteType VoteType, EFortVoteStatus VoteStatus, int32 VoteResult, const TArray<FVoter>& Voters)
{
}

bool UFortMissionVoteHUDElementWidget::HasLocalPlayerVoted(EFortVoteType VoteType)
{
	return false;
}

bool UFortMissionVoteHUDElementWidget::IsMultiplayerVote(EFortVoteType VoteType)
{
	return false;
}

void UFortMissionVoteHUDElementWidget::RegisterFailsafeForVoteType(EFortVoteType VoteType)
{
}
