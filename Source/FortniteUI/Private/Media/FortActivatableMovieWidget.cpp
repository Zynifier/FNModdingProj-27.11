// Copyright Epic Games, Inc. All Rights Reserved.

#include "Media/FortActivatableMovieWidget.h"

void UFortActivatableMovieWidget::Close()
{
}

void UFortActivatableMovieWidget::EnableFadeInFromColor(bool bInEnable)
{
}

void UFortActivatableMovieWidget::FadeInFromColorComplete(UFortActivatablePrePostRollStates Reason)
{
}

UFortBaseStreamingVideo* UFortActivatableMovieWidget::GetBaseStreamingVideo()
{
	return nullptr;
}

UMediaPlayer* UFortActivatableMovieWidget::GetMediaPlayer() const
{
	return nullptr;
}

const UImage* UFortActivatableMovieWidget::GetVideoTexture()
{
	return nullptr;
}

void UFortActivatableMovieWidget::HandleVideoStreamingSuccess()
{
}

void UFortActivatableMovieWidget::HandleVideoStreamingTerminalError(EBaseMediaTerminalErrorReason Reason)
{
}

void UFortActivatableMovieWidget::LoadStreamingVideo(const FVideoWidgetConfig& Config)
{
}

void UFortActivatableMovieWidget::Play()
{
}

void UFortActivatableMovieWidget::SetFadeTime(double InFadeTime)
{
}

void UFortActivatableMovieWidget::SetMediaPreEndTimeSeconds(float InSeconds)
{
}

bool UFortActivatableMovieWidget::ShouldAutoPlayVideo(FName AssetName, bool bAllowRecord) const
{
	return false;
}

void UFortActivatableMovieWidget::Stop(bool InForceClose)
{
}

void UFortActivatableMovieWidget::StreamedVideoOnMediaPlayerClosed()
{
}

void UFortActivatableMovieWidget::StreamedVideoOnMediaPlayerEndReached()
{
}

void UFortActivatableMovieWidget::StreamedVideoOpeningTimeout()
{
}

void UFortActivatableMovieWidget::WholeFadeComplete()
{
}
