// Copyright Epic Games, Inc. All Rights Reserved.

#include "Replay/FortReplaySpectator.h"

bool AFortReplaySpectator::AreReplayGameHighlightsAvailable() const
{
	return false;
}

UFortReplaySequenceComponent* AFortReplaySpectator::GetSequencerComponent() const
{
	return nullptr;
}

bool AFortReplaySpectator::HasPermissionToViewHighlights() const
{
	return false;
}

void AFortReplaySpectator::OnDemoScrubComplete(bool bWasSuccessful)
{
}

void AFortReplaySpectator::OnPawnForReplayRelevancyChanged(AFortPawn* NewRelevancyPawn)
{
}

void AFortReplaySpectator::OnPlayerStatePlacementChanged(AFortPlayerStateAthena* Sender, int32 InPlace)
{
}

void AFortReplaySpectator::OnReplayExtractionPreScrubComplete(bool bWasSuccessful)
{
}

void AFortReplaySpectator::OnScrubComplete(bool bWasSuccessful)
{
}

void AFortReplaySpectator::OnShotStartGotoTimeComplete(bool bWasSuccessful)
{
}

void AFortReplaySpectator::PlayThroughHightlightReel(const FHighlightReel& Highlights)
{
}

void AFortReplaySpectator::SequencerLoadAndPlayFile(const FString& SequenceFileName)
{
}

void AFortReplaySpectator::SetAllowTimeDilation(bool bAllow)
{
}

void AFortReplaySpectator::SetCloudAltitudes(float NewCloudAltitude)
{
}

bool AFortReplaySpectator::SetOverrideTimeOfDay(bool bOverride, float Time, bool bImmediate, float Speed)
{
	return false;
}

bool AFortReplaySpectator::SetTimeOfDaySpeed(float Speed)
{
	return false;
}

bool AFortReplaySpectator::ShouldSetupUIForRecording() const
{
	return false;
}

void AFortReplaySpectator::SkipToNextSequencerShot() const
{
}

void AFortReplaySpectator::SkipToSequencerShot(int32 ShotIndex) const
{
}
