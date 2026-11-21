// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortAudioToMPCComponent.h"

void UFortAudioToMPCComponent::AddTrackedAudioComponent(UAudioComponent* InAudioComponent)
{
}

float UFortAudioToMPCComponent::GetCachedAverageMagnitude() const
{
	return float();
}

float UFortAudioToMPCComponent::GetCachedMagnitudeForChannel(int32 ChannelIndex) const
{
	return float();
}

bool UFortAudioToMPCComponent::RemoveTrackedAudioComponent(UAudioComponent* InAudioComponent)
{
	return false;
}
