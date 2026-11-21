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

class FHarmonixAudioAnalyzerSubmixEffect : public FSoundEffectSubmix
{
public:
	virtual void Init(const FSoundEffectSubmixInitData& InInitData) override;

	virtual void OnPresetChanged() override;

	virtual void OnProcessAudio(const FSoundEffectSubmixInputData& InData, FSoundEffectSubmixOutputData& OutData) override;
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

