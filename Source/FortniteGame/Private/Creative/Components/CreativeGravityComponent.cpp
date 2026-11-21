// Copyright Epic Games, Inc. All Rights Reserved.

#include "Creative/Components/CreativeGravityComponent.h"

bool UCreativeGravityComponent::SetCustomGravityOverride(AActor* PhysicsObject, float CustomMultiplier, bool bUseCustomGravity, float CustomGravity) const
{
	return false;
}

bool UCreativeGravityComponent::SetPresetGravityOverride(AActor* PhysicsObject, int32 PresetIndex, bool bUseCustomGravity, float CustomGravity) const
{
	return false;
}
