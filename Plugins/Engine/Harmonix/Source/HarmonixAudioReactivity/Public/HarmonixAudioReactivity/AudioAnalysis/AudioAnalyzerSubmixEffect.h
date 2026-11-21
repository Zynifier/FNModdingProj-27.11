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

UCLASS(HideCategories=("Object"), ClassGroup=("AudioSubmixEffect"), meta=(BlueprintSpawnableComponent))
class UHarmonixAudioAnalyzerSubmixEffectPreset : public USoundEffectSubmixPreset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Audio|Analysis")
	FHarmonixAudioAnalyzerSubmixEffectSettings Settings;

};

