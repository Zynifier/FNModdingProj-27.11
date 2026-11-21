// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortMovieWidget.h"

void UFortMovieWidget::CleanupMediaPlayer()
{
}

UMediaPlayer* UFortMovieWidget::GetMediaPlayer() const
{
	return nullptr;
}

UMediaSoundComponent* UFortMovieWidget::GetMediaSoundComponent() const
{
	return nullptr;
}

UMediaTexture* UFortMovieWidget::GetMediaTexture() const
{
	return nullptr;
}

bool UFortMovieWidget::HasPlayerForSource(UMediaSource* InMediaSource) const
{
	return false;
}

void UFortMovieWidget::RequestPlayMovie(bool bShouldRewind)
{
}

void UFortMovieWidget::RequestStopMovie()
{
}

bool UFortMovieWidget::SetMediaSource(UMediaPlayer* InMediaPlayer, UMediaSource* InMediaSource, const FMediaPlayerOptions& PlayerOptions, bool bPlayOnOpen, bool bLooping)
{
	return false;
}
