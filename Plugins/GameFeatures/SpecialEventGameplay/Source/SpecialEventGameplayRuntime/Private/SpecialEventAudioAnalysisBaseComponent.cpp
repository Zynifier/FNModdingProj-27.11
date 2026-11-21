// Copyright Epic Games, Inc. All Rights Reserved.

#include "SpecialEventAudioAnalysisBaseComponent.h"

UConstantQNRT* USpecialEventAudioAnalysisBaseComponent::GetConstantQNRT() const
{
	return nullptr;
}

float USpecialEventAudioAnalysisBaseComponent::GetCurrentNormalizedLoudness() const
{
	return float();
}

ULoudnessNRT* USpecialEventAudioAnalysisBaseComponent::GetLoudnessNRT() const
{
	return nullptr;
}

UOnsetNRT* USpecialEventAudioAnalysisBaseComponent::GetOnsetNRT() const
{
	return nullptr;
}

void USpecialEventAudioAnalysisBaseComponent::UpdateConstantQ_Implementation(float Time)
{
}

void USpecialEventAudioAnalysisBaseComponent::UpdateLoudness_Implementation(float Time)
{
}

void USpecialEventAudioAnalysisBaseComponent::UpdateOnset_Implementation(float Time)
{
}

void USpecialEventAudioAnalysisBaseComponent::UpdateTime_Implementation(const float NewTime)
{
}
