// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "HarmonixDsp/AudioAnalysis/FFTAnalyzer.h"
#include "HarmonixDsp/AudioAnalysis/VuMeterAnalyzer.h"
#include "HarmonixDsp/AudioAnalysis/WaveformAnalyzer.h"
#include "AudioAnalyzerSettings.generated.h"

USTRUCT(BlueprintType)
struct FHarmonixAudioAnalyzerSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="General")
	FName Name;

	UPROPERTY(EditAnywhere, Category="VUMeter")
	FHarmonixVuMeterAnalyzerSettings VuMeterSettings;

	UPROPERTY(EditAnywhere, Category="FFT")
	FHarmonixFFTAnalyzerSettings FFTAnalyzerSettings;

	UPROPERTY(EditAnywhere, Category="Waveform")
	FHarmonixWaveformAnalyzerSettings WaveformAnalyzerSettings;

};

