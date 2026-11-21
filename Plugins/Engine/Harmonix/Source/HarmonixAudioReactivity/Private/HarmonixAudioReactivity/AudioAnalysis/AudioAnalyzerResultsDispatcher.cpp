// Copyright Epic Games, Inc. All Rights Reserved.

#include "HarmonixAudioReactivity/AudioAnalysis/AudioAnalyzerResultsDispatcher.h"

bool UHarmonixAudioAnalyzerResultsDispatcher::HasProvider(const FName& Name) const
{
	return false;
}

bool UHarmonixAudioAnalyzerResultsDispatcher::TryGetResults(const FName& Name, FHarmonixAudioAnalyzerResults& Results) const
{
	return false;
}

UHarmonixAudioAnalyzerResultsProvider* UHarmonixAudioAnalyzerResultsProvider::CreateHarmonixAudioAnalyzerResultsProvider(FName Name)
{
	return nullptr;
}

void UHarmonixAudioAnalyzerResultsProvider::SetArbitraryTextureData(const TArray<float>& ArbitraryTextureData)
{
}
