// Copyright Epic Games, Inc. All Rights Reserved.

#include "HarmonixAudioReactivity/AudioAnalysis/AudioAnalyzerSourceEffect.h"

void FHarmonixAudioAnalyzerSourceEffect::Init(const FSoundEffectSourceInitData& InInitData)
{
}

void FHarmonixAudioAnalyzerSourceEffect::OnPresetChanged()
{
}

void FHarmonixAudioAnalyzerSourceEffect::ProcessAudio(const FSoundEffectSourceInputData& InData, float* OutAudioBufferData)
{
	FMemory::Memcpy(OutAudioBufferData, InData.InputSourceEffectBufferPtr, sizeof(float) * InData.NumSamples);
}
