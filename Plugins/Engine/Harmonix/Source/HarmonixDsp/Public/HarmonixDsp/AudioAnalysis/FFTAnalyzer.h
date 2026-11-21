// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "HarmonixDsp/AudioAnalysis/OutputSettings.h"
#include "FFTAnalyzer.generated.h"

USTRUCT(BlueprintType)
struct HARMONIXDSP_API FHarmonixFFTAnalyzerResults
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="Results")
	TArray<float> Spectrum;

};

USTRUCT(BlueprintType)
struct HARMONIXDSP_API FHarmonixFFTAnalyzerSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Settings")
	int32 FFTSize;

	UPROPERTY(EditAnywhere, Category="Settings")
	float MinFrequencyHz;

	UPROPERTY(EditAnywhere, Category="Settings")
	float MaxFrequencyHz;

	UPROPERTY(EditAnywhere, Category="Settings")
	bool MelScaleBinning;

	UPROPERTY(EditAnywhere, Category="Settings")
	int32 NumResultBins;

	UPROPERTY(EditAnywhere, Category="Settings")
	FHarmonixAudioAnalyzerOutputSettings OutputSettings;

};

