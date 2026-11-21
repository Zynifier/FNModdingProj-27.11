// Copyright Epic Games, Inc. All Rights Reserved.

#include "EpicMediaBasePlayer.h"

void UEpicBaseStreamingVideo::ClearSyncTimes()
{
}

bool UEpicBaseStreamingVideo::GetLicensedAudio()
{
	return false;
}

UMediaPlayer* UEpicBaseStreamingVideo::GetMediaPlayer()
{
	return nullptr;
}

FMediaPlayerOptions UEpicBaseStreamingVideo::GetMediaPlayerOptions()
{
	return FMediaPlayerOptions();
}

UEpicStreamMediaSource* UEpicBaseStreamingVideo::GetMediaSource()
{
	return nullptr;
}

UMediaSoundComponent* UEpicBaseStreamingVideo::GetSoundComponent()
{
	return nullptr;
}

void UEpicBaseStreamingVideo::HandleLicensedAudioTreatmentChanged(UCPTypes UCPType)
{
}

void UEpicBaseStreamingVideo::HandleMediaClosed()
{
}

void UEpicBaseStreamingVideo::HandleMediaEndReached()
{
}

void UEpicBaseStreamingVideo::HandleMediaOpened(const FString& OpenedUrl)
{
}

void UEpicBaseStreamingVideo::HandleMediaOpenedFailed(const FString& FailedUrl)
{
}

void UEpicBaseStreamingVideo::HandleMediaResumed()
{
}

bool UEpicBaseStreamingVideo::Init(UMediaTexture* InVideoTexture, UMediaPlayer* InMediaPlayer, UEpicStreamMediaSource* InMediaSource, bool InCDNFailover)
{
	return false;
}

bool UEpicBaseStreamingVideo::IsSyncStartTimeSet() const
{
	return false;
}

void UEpicBaseStreamingVideo::OnFailedURL(const FString& URL)
{
}

void UEpicBaseStreamingVideo::OnSuccessfulURL(const FString& URL)
{
}

bool UEpicBaseStreamingVideo::Open(FMediaPlayerOptions InMediaOptions)
{
	return false;
}

void UEpicBaseStreamingVideo::Release()
{
}

bool UEpicBaseStreamingVideo::RetryOnError(bool bFromPlayer)
{
	return false;
}

void UEpicBaseStreamingVideo::SetCreateAudioComponent(bool bInCreateAudioComponent)
{
}

void UEpicBaseStreamingVideo::SetOpenTimeout(double InTimeoutTime)
{
}

void UEpicBaseStreamingVideo::SetSoundSubmixes(UMediaSoundComponent* InSoundComponent, USoundSubmixBase* InDefault, USoundSubmixBase* InLicensed)
{
}

void UEpicBaseStreamingVideo::SetSyncTimes(FDateTime InNowTime, FDateTime InStartTime, bool DynamicStart, float InOffset_s, float InDelay_s)
{
}

void UEpicBaseStreamingVideo::SetVideoSize(const int32 Width, const int32 Height)
{
}

void UEpicBaseStreamingVideo::Start(const FString& InVUID, UMediaTexture* InVideoTexture)
{
}

void UEpicBaseStreamingVideo::Stop(bool bRelease, bool bStopPlayer)
{
}
