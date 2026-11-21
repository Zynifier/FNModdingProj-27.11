// Copyright Epic Games, Inc. All Rights Reserved.

#include "HarmonixAudioReactivity/AudioAnalysis/AudioAnalyzerSubmixEffect.h"

void FHarmonixAudioAnalyzerSubmixEffect::Init(const FSoundEffectSubmixInitData& InInitData)
{
}

void FHarmonixAudioAnalyzerSubmixEffect::OnPresetChanged()
{
}

void FHarmonixAudioAnalyzerSubmixEffect::OnProcessAudio(const FSoundEffectSubmixInputData& InData, FSoundEffectSubmixOutputData& OutData)
{
	const float* InBuffer = InData.AudioBuffer->GetData();
	float* OutBuffer = OutData.AudioBuffer->GetData();

	if (InData.NumChannels == OutData.NumChannels)
	{
		FMemory::Memcpy(OutBuffer, InBuffer, sizeof(float) * InData.NumFrames * InData.NumChannels);
	}
	else
	{
		for (int32 FrameIndex = 0; FrameIndex < InData.NumFrames; ++FrameIndex)
		{
			for (int32 ChannelIndex = 0; ChannelIndex < OutData.NumChannels; ++ChannelIndex)
			{
				OutBuffer[FrameIndex * OutData.NumChannels + ChannelIndex] = ChannelIndex < InData.NumChannels ? InBuffer[FrameIndex * InData.NumChannels + ChannelIndex] : 0.0f;
			}
		}
	}
}
