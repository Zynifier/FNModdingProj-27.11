// Copyright Epic Games, Inc. All Rights Reserved.

#include "HarmonixDsp/FusionSampler/FusionPatch.h"

void UFusionPatch::CancelAudioLoadRequest()
{
}

bool UFusionPatch::IsAudioLoadedForPlayback() const
{
	return false;
}

void UFusionPatch::LoadAudioForPlayback(const FOnFusionPatchLoadComplete OnLoadComplete)
{
}

void UFusionPatch::ReleaseLoadedAudio()
{
}
