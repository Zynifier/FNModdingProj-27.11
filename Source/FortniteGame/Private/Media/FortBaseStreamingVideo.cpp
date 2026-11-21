// Copyright Epic Games, Inc. All Rights Reserved.

#include "Media/FortBaseStreamingVideo.h"

UFortMediaPlayerCtrl* UFortBaseStreamingVideo::GetMediaController()
{
	return nullptr;
}

FFortMediaInBandMetadata UFortBaseStreamingVideo::GetMediaMetadata()
{
	return FFortMediaInBandMetadata();
}

UFortMediaSubtitlesPlayer* UFortBaseStreamingVideo::GetSubtitlePlayer()
{
	return nullptr;
}

void UFortBaseStreamingVideo::HandleMetadataEvent()
{
}

void UFortBaseStreamingVideo::SetMediaControllerStartTime(const float InStartTime)
{
}

void UFortBaseStreamingVideo::SetSubtitles(ULocalizedOverlays* InOverlays, UFortMediaSubtitlesPlayer* InSubtitlePlayer)
{
}
