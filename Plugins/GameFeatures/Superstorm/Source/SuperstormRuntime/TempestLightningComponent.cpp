// Copyright Epic Games, Inc. All Rights Reserved.

#include "TempestLightningComponent.h"

UTempestLightningComponent::UTempestLightningComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

float UTempestLightningComponent::GetCloudHeight() const
{
	return float();
}

float UTempestLightningComponent::GetLightningRadius() const
{
	return float();
}
