// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "HarmonixDsp/AudioAnalysis/FFTAnalyzer.h"
#include "HarmonixDsp/AudioAnalysis/VuMeterAnalyzer.h"
#include "HarmonixDsp/AudioAnalysis/WaveformAnalyzer.h"
#include "AudioAnalyzerResults.generated.h"

USTRUCT(BlueprintType)
struct FHarmonixAudioAnalyzerResults
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="VUMeter")
	FHarmonixVuMeterAnalyzerResults VuMeterResults;

	UPROPERTY(BlueprintReadOnly, Category="FFT")
	FHarmonixFFTAnalyzerResults FFTResults;

	UPROPERTY(BlueprintReadOnly, Category="Waveform")
	FHarmonixWaveformAnalyzerResults WaveformAnalyzerResults;

	UPROPERTY(BlueprintReadOnly, Category="Array")
	TArray<float> ArbitraryTextureData;

};

