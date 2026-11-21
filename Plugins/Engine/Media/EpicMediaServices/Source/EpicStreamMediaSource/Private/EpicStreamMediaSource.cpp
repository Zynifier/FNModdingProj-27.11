// Copyright Epic Games, Inc. All Rights Reserved.

#include "EpicStreamMediaSource.h"

void UEpicStreamMediaSource::CancelVideoUrlRequest(bool bInCancelled)
{
}

void UEpicStreamMediaSource::ClearSyncTimes()
{
}

void UEpicStreamMediaSource::DisableSharing()
{
}

void UEpicStreamMediaSource::ForceSegmentCaching(bool bForce)
{
}

bool UEpicStreamMediaSource::HasLocalFilePlayback() const
{
	return false;
}

bool UEpicStreamMediaSource::IsScreenRecordingInProgress()
{
	return false;
}

void UEpicStreamMediaSource::MetadataResultHandler(const FEpicMediaMetadataExt& Metadata, bool bSuccess)
{
}

void UEpicStreamMediaSource::ReinstateSharing()
{
}

void UEpicStreamMediaSource::RequestVideoUrl(const APlayerController* FortPC)
{
}

void UEpicStreamMediaSource::SetLocalizedOverlaysV2(UEpicMediaDownloadLocalizedOverlays* InOverlays)
{
}

void UEpicStreamMediaSource::SetPlaybackStartTime(float StartTime)
{
}

void UEpicStreamMediaSource::SetSyncTimes(FDateTime InNowTime, FDateTime InStartTime, bool DynamicStart, float InOffset_s, float InDelay_s)
{
}

void UEpicStreamMediaSource::SetUrl(FString& InUrl)
{
}

UCPTypes UEpicStreamMediaSource::ShouldProtectPlayerFromContent()
{
	return UCPTypes();
}

bool UEpicStreamMediaSource::ShouldStreamBePlaying(const UObject* WorldContextObject, const UPrimitiveComponent* PrimitiveComponent, float CullRadius) const
{
	return false;
}

FMediaPlayerOptions UEpicStreamMediaSource::UpdatePlayerOptions(FMediaPlayerOptions PlayerOptions) const
{
	return FMediaPlayerOptions();
}

void UEpicStreamMediaSource::UpdateStreamUrlArguments()
{
}
