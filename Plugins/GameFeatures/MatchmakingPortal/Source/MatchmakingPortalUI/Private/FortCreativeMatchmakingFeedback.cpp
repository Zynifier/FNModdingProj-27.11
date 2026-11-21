// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortCreativeMatchmakingFeedback.h"

bool UFortCreativeMatchmakingFeedback::CanCancelMatchmaking() const
{
	return false;
}

float UFortCreativeMatchmakingFeedback::GetTimeToDisplayMessageBeforeFadeOut() const
{
	return float();
}

void UFortCreativeMatchmakingFeedback::HandleCancelMatchmaking()
{
}

void UFortCreativeMatchmakingFeedback::HoldAction()
{
}

void UFortCreativeMatchmakingFeedback::HoldPressed()
{
}

void UFortCreativeMatchmakingFeedback::HoldReleased()
{
}

bool UFortCreativeMatchmakingFeedback::IsLocalPlayerReady() const
{
	return false;
}

bool UFortCreativeMatchmakingFeedback::IsPartyLeader() const
{
	return false;
}

void UFortCreativeMatchmakingFeedback::OnCreativeReadyCheckStatusChanged(EInGameReadyCheckStatus InGameReadyCheckStatus)
{
}

void UFortCreativeMatchmakingFeedback::OnOutroFinished()
{
}

void UFortCreativeMatchmakingFeedback::PopInputComponent()
{
}

void UFortCreativeMatchmakingFeedback::PushInputComponent()
{
}
