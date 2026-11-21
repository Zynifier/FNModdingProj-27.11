// Copyright Epic Games, Inc. All Rights Reserved.

#include "AudioShapePrimitiveComponent.h"

UAudioComponent* UAudioShapePrimitiveComponent::GetEdgeAudioComponent()
{
	return nullptr;
}

UAudioComponent* UAudioShapePrimitiveComponent::GetInsideAudioComponent()
{
	return nullptr;
}

bool UAudioShapePrimitiveComponent::GetIsPlayerInside() const
{
	return false;
}
