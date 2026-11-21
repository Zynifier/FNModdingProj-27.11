// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "HarmonixAudioAnalysisType.generated.h"

UENUM()
enum class EHarmonixAudioAnalysisType : uint8
{
	/** Read texture data from the audio analyzer VU meter (the texture will be 1 pixel wide) */
	VUMeter = 0 UMETA(DisplayName="VU Meter"),
	/** Read texture data from the audio analyzer FFT (the texture will be as wide as the number of FFT bins) */
	FFT = 1 UMETA(DisplayName="FFT"),
	/** Read texture data from the audio analyzer waveform (the texture will be as wide as the number of samples held by the analyzer) */
	Waveform = 2 UMETA(DisplayName="Waveform"),
	/** Read texture data from an array of arbitrary data (the texture's width will be defined by the provider and context) */
	Arbitrary = 3 UMETA(DisplayName="Arbitrary Texture Data"),
	Count = 4 UMETA(Hidden),
};

