// Copyright Epic Games, Inc. All Rights Reserved.

#include "Sound/FortQuartzSynchronizer.h"

FString UFortQuartzSynchronizer::CreateJsonFromTimestampEvents()
{
	return FString();
}

bool UFortQuartzSynchronizer::CreateTimestampEventsFromJson(const FString& JsonString)
{
	return false;
}

void UFortQuartzSynchronizer::HandleAudioComponentPlaybackPercent(const USoundWave* PlayingSoundWave, const float PlaybackPercent)
{
}

void UFortQuartzSynchronizer::HandleAudioComponentPlayStateChanged(EAudioComponentPlayState PlayState)
{
}

void UFortQuartzSynchronizer::HandleMediaPlayerClosed()
{
}

void UFortQuartzSynchronizer::HandleMediaPlayerOpened(const FString& OpenedURL)
{
}

void UFortQuartzSynchronizer::HandleMediaPlayerResumed()
{
}

void UFortQuartzSynchronizer::HandleMediaPlayerSuspended()
{
}

void UFortQuartzSynchronizer::SetAudioComponent(UAudioComponent* InAudioComponent)
{
}

void UFortQuartzSynchronizer::SetMediaSoundComponent(UMediaSoundComponent* InMediaSoundComponent)
{
}
