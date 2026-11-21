// Copyright Epic Games, Inc. All Rights Reserved.

#include "Sound/AudioAnalysis/FortAudioAnalysisSubsystem.h"

void UAudioAnalysisSubmixAnalyzer::OnSubmixEnvelope(const TArray<float>& Amplitudes)
{
}

void UAudioAnalysisSubmixAnalyzer::OnSubmixSpectralAnalysis(const TArray<float>& Amplitudes)
{
}

UFortAudioAnalysisSettings* UFortAudioAnalysisSubsystem::GetAnalysisSettings() const
{
	return nullptr;
}

UAudioAnalysisSubmixAnalyzer* UFortAudioAnalysisSubsystem::GetAnalyzerForSubmix(USoundSubmix* InSubmix)
{
	return nullptr;
}

bool UFortAudioAnalysisSubsystem::IsAnalysisActive() const
{
	return false;
}

void UFortAudioAnalysisSubsystem::RegisterDefaultSubmix()
{
}

void UFortAudioAnalysisSubsystem::RegisterSubmix(USoundSubmix* InSubmix, FFortSubmixAnalyzerData InAnalyzerData)
{
}

void UFortAudioAnalysisSubsystem::UnRegisterDefaultSubmix()
{
}

void UFortAudioAnalysisSubsystem::UnRegisterSubmix(USoundSubmix* InSubmix)
{
}
