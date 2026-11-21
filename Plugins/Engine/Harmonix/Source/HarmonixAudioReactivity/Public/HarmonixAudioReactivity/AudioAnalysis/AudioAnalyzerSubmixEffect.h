// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Sound/SoundEffectSubmix.h"
#include "HarmonixAudioReactivity/AudioAnalysis/AudioAnalyzerSettings.h"
#include "AudioAnalyzerSubmixEffect.generated.h"

USTRUCT(BlueprintType)
struct FHarmonixAudioAnalyzerSubmixEffectSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Audio|Analysis")
	FHarmonixAudioAnalyzerSettings AnalyzerSettings;

};

/** Stub effect: passes audio through unchanged. Exists so the preset can create a valid effect instance. */
class FHarmonixAudioAnalyzerSubmixEffect : public FSoundEffectSubmix
{
public:
	virtual void Init(const FSoundEffectSubmixInitData& InInitData) override {}

	virtual void OnProcessAudio(const FSoundEffectSubmixInputData& InData, FSoundEffectSubmixOutputData& OutData) override
	{
		FMemory::Memcpy(OutData.AudioBuffer->GetData(), InData.AudioBuffer->GetData(), sizeof(float) * InData.NumFrames * InData.NumChannels);
	}
};

UCLASS(HideCategories=("Object"), ClassGroup=("AudioSubmixEffect"), meta=(BlueprintSpawnableComponent))
class UHarmonixAudioAnalyzerSubmixEffectPreset : public USoundEffectSubmixPreset
{
	GENERATED_BODY()

public:
	EFFECT_PRESET_METHODS(HarmonixAudioAnalyzerSubmixEffect)

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Audio|Analysis")
	FHarmonixAudioAnalyzerSubmixEffectSettings Settings;

};

