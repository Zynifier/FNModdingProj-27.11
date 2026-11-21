// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Sound/SoundEffectSource.h"
#include "HarmonixAudioReactivity/AudioAnalysis/AudioAnalyzerSettings.h"
#include "AudioAnalyzerSourceEffect.generated.h"

USTRUCT(BlueprintType)
struct FHarmonixAudioAnalyzerSourceEffectSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Audio|Analysis")
	FHarmonixAudioAnalyzerSettings AnalyzerSettings;

};

class FHarmonixAudioAnalyzerSourceEffect : public FSoundEffectSource
{
public:
	virtual void Init(const FSoundEffectSourceInitData& InInitData) override;

	virtual void OnPresetChanged() override;

	virtual void ProcessAudio(const FSoundEffectSourceInputData& InData, float* OutAudioBufferData) override;
};

UCLASS(ClassGroup=("AudioSourceEffect"), meta=(BlueprintSpawnableComponent))
class UHarmonixAudioAnalyzerSourceEffectPreset : public USoundEffectSourcePreset
{
	GENERATED_BODY()

public:
	EFFECT_PRESET_METHODS(HarmonixAudioAnalyzerSourceEffect)

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Audio|Analysis")
	FHarmonixAudioAnalyzerSourceEffectSettings Settings;

};

