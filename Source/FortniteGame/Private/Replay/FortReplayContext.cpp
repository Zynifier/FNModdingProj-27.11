// Copyright Epic Games, Inc. All Rights Reserved.

#include "Replay/FortReplayContext.h"

void UFortReplayContext::DecreasePlaybackMultiplier()
{
}

FText UFortReplayContext::GetCameraNameFromType(const ESpectatorCameraType CamType) const
{
	return FText();
}

FString UFortReplayContext::GetEventTooltip(int32 EventIndex)
{
	return FString();
}

float UFortReplayContext::GetMaxMapZoomLevel() const
{
	return float();
}

void UFortReplayContext::IncreasePlaybackMultiplier()
{
}

bool UFortReplayContext::IsDepthOfFieldActive()
{
	return false;
}

void UFortReplayContext::JumpReplayToTimelinePosition(float TimeRatio)
{
}

void UFortReplayContext::JumpToEvent(int32 EventIndex)
{
}

void UFortReplayContext::JumpToNextEvent()
{
}

void UFortReplayContext::JumpToPreviousEvent()
{
}

void UFortReplayContext::OnHighQualityFxEnabledChanged(bool bEnabled)
{
}

void UFortReplayContext::ReplayHUDCleanup()
{
}

void UFortReplayContext::SetSessionIdWatermarkVisible(bool bIsVisible)
{
}

void UFortReplayContext::SkipBack(const float TimeInSeconds)
{
}

void UFortReplayContext::SkipForward(const float TimeInSeconds)
{
}

void UFortReplayContext::SkipTo(const float TimeInSeconds)
{
}

void UFortReplayContext::TakeScreenshot()
{
}

void UFortReplayContext::ToggleHighlightsListVisibility()
{
}

void UFortReplayContext::ToggleHUDVisibility()
{
}

bool UFortReplayContext::ToggleIconVisibility(UClass* ToToggle)
{
	return false;
}

void UFortReplayContext::TogglePlayerListVisibility()
{
}

void UFortReplayContext::TogglePlayPause()
{
}

void UFortReplayContext::ToggleViewSettingsVisibility()
{
}
