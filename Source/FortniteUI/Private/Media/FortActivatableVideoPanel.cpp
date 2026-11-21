// Copyright Epic Games, Inc. All Rights Reserved.

#include "Media/FortActivatableVideoPanel.h"

void UFortActivatableVideoPanel::EnableSkipButton(bool bAllowSkip)
{
}

UMediaPlayer* UFortActivatableVideoPanel::GetMediaPlayer() const
{
	return nullptr;
}

bool UFortActivatableVideoPanel::LoadVideo(FName VideoID, bool bIsAutoPlay, bool bForceDefaultAudioTrack, FName VideoString)
{
	return false;
}

bool UFortActivatableVideoPanel::ShouldAutoPlayVideo(FName AssetName, bool bAllowRecord) const
{
	return false;
}

void UFortActivatableVideoPanel::ShowThrobber()
{
}

void UFortActivatableVideoPanel::StartVideo()
{
}

bool UFortActivatableVideoPanel::StreamVideo(const FString& VideoURL)
{
	return false;
}

bool UFortActivatableVideoPanel::StreamVideoFromSource(UStreamMediaSource* StreamSource)
{
	return false;
}
