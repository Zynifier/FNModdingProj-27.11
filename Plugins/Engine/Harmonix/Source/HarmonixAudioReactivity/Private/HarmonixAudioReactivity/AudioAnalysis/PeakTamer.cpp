// Copyright Epic Games, Inc. All Rights Reserved.

#include "HarmonixAudioReactivity/AudioAnalysis/PeakTamer.h"

void UHarmonixPeakTamer::Configure(const FHarmonixPeakTamerSettings& Settings)
{
}

UHarmonixPeakTamer* UHarmonixPeakTamer::CreateHarmonixPeakTamer()
{
	return nullptr;
}

float UHarmonixPeakTamer::GetPeak() const
{
	return float();
}

float UHarmonixPeakTamer::GetValue() const
{
	return float();
}

void UHarmonixPeakTamer::Update(float InputValue, float DeltaTimeSeconds)
{
}
