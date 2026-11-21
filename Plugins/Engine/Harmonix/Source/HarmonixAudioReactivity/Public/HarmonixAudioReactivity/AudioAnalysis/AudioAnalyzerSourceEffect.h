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

UCLASS(ClassGroup=("AudioSourceEffect"), meta=(BlueprintSpawnableComponent))
class UHarmonixAudioAnalyzerSourceEffectPreset : public USoundEffectSourcePreset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Audio|Analysis")
	FHarmonixAudioAnalyzerSourceEffectSettings Settings;

};

