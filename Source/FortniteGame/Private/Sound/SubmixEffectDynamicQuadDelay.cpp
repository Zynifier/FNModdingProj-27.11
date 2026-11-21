// Copyright Epic Games, Inc. All Rights Reserved.

#include "Sound/SubmixEffectDynamicQuadDelay.h"

void FSubmixEffectDynamicQuadDelay::Init(const FSoundEffectSubmixInitData& InInitData)
{
}

void FSubmixEffectDynamicQuadDelay::OnPresetChanged()
{
}

void FSubmixEffectDynamicQuadDelay::OnProcessAudio(const FSoundEffectSubmixInputData& InData, FSoundEffectSubmixOutputData& OutData)
{
	FMemory::Memcpy(OutData.AudioBuffer->GetData(), InData.AudioBuffer->GetData(), sizeof(float) * InData.NumFrames * InData.NumChannels);
}

void USubmixEffectDynamicQuadDelayPreset::SetModulationSettings(const FSubmixEffectDynamicQuadDelaySettings& InSettings)
{
}

void USubmixEffectDynamicQuadDelayPreset::SetSettings(const FSubmixEffectDynamicQuadDelaySettings& InSettings)
{
}
