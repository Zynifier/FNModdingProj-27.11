// Copyright Epic Games, Inc. All Rights Reserved.

#include "PictureInPictureMediaController.h"

void UPictureInPictureMediaController::Exit(bool bStop)
{
}

const TArray<UPictureInPictureActionData*>& UPictureInPictureMediaController::GetActions()
{
	static TArray<UPictureInPictureActionData*> Dummy;
	return Dummy;
}

FPiPPartnerSource UPictureInPictureMediaController::GetCurrentSource()
{
	return FPiPPartnerSource();
}

const FPIPVideoPlayerAssetConfig& UPictureInPictureMediaController::GetDefaultPlayerAssetConfig() const
{
	static FPIPVideoPlayerAssetConfig Dummy;
	return Dummy;
}

UPictureInPicturePlayer* UPictureInPictureMediaController::GetMediaPlayerWidget() const
{
	return nullptr;
}

const FPIPVideoPlayerAssetConfig& UPictureInPictureMediaController::GetPlayerAssetConfig() const
{
	static FPIPVideoPlayerAssetConfig Dummy;
	return Dummy;
}

TArray<FPiPPartnerSource> UPictureInPictureMediaController::GetSources()
{
	return TArray<FPiPPartnerSource>();
}

TArray<FPiPPartnerSource> UPictureInPictureMediaController::GetValidSources()
{
	return TArray<FPiPPartnerSource>();
}

void UPictureInPictureMediaController::HandleSourceSelectedEvent(const FString& SelectedSource)
{
}

bool UPictureInPictureMediaController::IsEnabled() const
{
	return false;
}

bool UPictureInPictureMediaController::IsMultiSourceSupported()
{
	return false;
}

bool UPictureInPictureMediaController::IsPaused()
{
	return false;
}

bool UPictureInPictureMediaController::IsPlaying()
{
	return false;
}

void UPictureInPictureMediaController::OnMediaClosedAnalytics()
{
}

void UPictureInPictureMediaController::OnMediaPausedAnalytics()
{
}

void UPictureInPictureMediaController::OnMediaResumedAnalytics()
{
}

void UPictureInPictureMediaController::OnMediaStartedAnalytics()
{
}

void UPictureInPictureMediaController::OnNextThumbnailReceived(UTexture2DDynamic* InTexture)
{
}

void UPictureInPictureMediaController::OnPrevThumbnailReceived(UTexture2DDynamic* InTexture)
{
}

void UPictureInPictureMediaController::Pause()
{
}

void UPictureInPictureMediaController::Play(bool bForcePlay)
{
}

void UPictureInPictureMediaController::SetCurrentSource(const FPiPPartnerSource& SelectedSource)
{
}

void UPictureInPictureMediaController::SetEnabled(bool bIsEnabled, bool bIsFromUser)
{
}

void UPictureInPictureMediaController::Stop()
{
}

void UPictureInPictureMediaController::ToggleFullScreen()
{
}
