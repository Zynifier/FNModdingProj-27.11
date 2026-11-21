// Copyright Epic Games, Inc. All Rights Reserved.

#include "PictureInPicturePlayer.h"

void UPictureInPicturePlayer::FlushPlayerAssetConfig()
{
}

void UPictureInPicturePlayer::HandleUCPAudioChanged(UFortClientSettingsRecord* Settings)
{
}

bool UPictureInPicturePlayer::IsAssetConfigSet()
{
	return false;
}

bool UPictureInPicturePlayer::SetPlayerAssetConfig(FPIPVideoPlayerAssetConfig& InAssetConfig)
{
	return false;
}

void UPictureInPicturePlayer::StreamedVideoOnUrlFailure(const FString URL)
{
}

void UPictureInPicturePlayer::StreamedVideoOnUrlSuccess(const FString URL)
{
}

void UPictureInPicturePlayer::UpdateStreamingPlayerSize(const FVector2D& InVector)
{
}
