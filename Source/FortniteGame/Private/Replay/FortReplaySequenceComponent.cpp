// Copyright Epic Games, Inc. All Rights Reserved.

#include "Replay/FortReplaySequenceComponent.h"

int32 UFortReplaySequenceComponent::GetCurrentShotIndex() const
{
	return int32();
}

int32 UFortReplaySequenceComponent::GetNumberOfShotsInSequence() const
{
	return int32();
}

void UFortReplaySequenceComponent::NextShot()
{
}

void UFortReplaySequenceComponent::NoRecorderVideoFinishedCallback()
{
}

void UFortReplaySequenceComponent::OnPlaybackTimeChanged(float NowTime)
{
}

void UFortReplaySequenceComponent::OnReplayLevelStreamingChanged(bool bIsStreaming)
{
}

void UFortReplaySequenceComponent::OnVideoExportFinished(bool bSuccess, const FString& Video)
{
}

void UFortReplaySequenceComponent::PreviousShot()
{
}

void UFortReplaySequenceComponent::RestartSequence()
{
}
