// Copyright Epic Games, Inc. All Rights Reserved.

#include "Sound/SubmixEffectDynamicReverb.h"

void FSubmixEffectDynamicReverb::Init(const FSoundEffectSubmixInitData& InInitData)
{
}

void FSubmixEffectDynamicReverb::OnPresetChanged()
{
}

void FSubmixEffectDynamicReverb::OnProcessAudio(const FSoundEffectSubmixInputData& InData, FSoundEffectSubmixOutputData& OutData)
{
	FMemory::Memcpy(OutData.AudioBuffer->GetData(), InData.AudioBuffer->GetData(), sizeof(float) * InData.NumFrames * InData.NumChannels);
}

void USubmixEffectDynamicReverbPreset::SetModulationSettings(const FSubmixEffectDynamicReverbSettings& InSettings)
{
}

void USubmixEffectDynamicReverbPreset::SetSettings(const FSubmixEffectDynamicReverbSettings& InSettings)
{
}
